/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <folly/IntrusiveList.h>
#include <folly/io/IOBuf.h>
#include <folly/io/async/Request.h>
#include <thrift/lib/cpp/protocol/TProtocolTypes.h>
#include <thrift/lib/cpp2/server/RequestId.h>
#include <chrono>

namespace apache {
namespace thrift {

class Cpp2RequestContext;
class ResponseChannelRequest;

/**
 * Stores a list of request stubs in memory.
 *
 * Each IO worker stores a single ActiveRequestsRegistry instance as its
 * member, so that it can intercept and insert request data into the registry.
 *
 * Note that read operations to the request list should be always executed in
 * the same thread as write operations to avoid race condition, which means
 * most of the time reads should be issued to the event base which the
 * corresponding registry belongs to, as a task.
 */
class ActiveRequestsRegistry {
  /**
   * A wrapper class for request payload we are tracking, to encapsulate the
   * details of processing and storing the real request buffer.
   */
  class DebugPayload {
   public:
    DebugPayload(std::unique_ptr<folly::IOBuf> data) : data_(std::move(data)) {}
    DebugPayload(const DebugPayload&) = delete;
    DebugPayload& operator=(const DebugPayload&) = delete;
    bool hasData() const {
      return data_ != nullptr;
    }
    std::unique_ptr<folly::IOBuf> cloneData() const {
      if (!data_) {
        return std::make_unique<folly::IOBuf>();
      }
      return data_->clone();
    }
    size_t dataSize() const {
      if (!data_) {
        return 0;
      }
      return data_->computeChainDataLength();
    }
    /**
     * User must call hasData() to ensure the underlying buffer is present
     * before releasing the buffer.
     */
    void releaseData() {
      DCHECK(data_);
      folly::IOBuf::destroy(std::move(data_));
    }

   private:
    std::unique_ptr<folly::IOBuf> data_;
  };

 public:
  /**
   * A piece of information which should be embedded into thrift request
   * objects.
   *
   * DebugStub tracks request payload to its corresponding thrift
   * request. Handles to the payloads can be optinally released by its
   * parent request registry, indicating the payload memory has been reclaimed
   * to control memory usage. DebugStub should be unlinked from lists
   * only during:
   *   1. Destruction of DebugStub.
   *   2. Memory collection from ActiveRequestsRegistry.
   *
   * NOTE: Place this as the last member of a request object to ensure we never
   *       try to examine half destructed objects.
   */
  class DebugStub {
    friend class ActiveRequestsRegistry;

   public:
    DebugStub(
        ActiveRequestsRegistry& reqRegistry,
        const ResponseChannelRequest& req,
        const Cpp2RequestContext& reqContext,
        protocol::PROTOCOL_TYPES protoId,
        std::unique_ptr<folly::IOBuf> payload,
        intptr_t rootRequestContextId)
        : req_(&req),
          reqContext_(&reqContext),
          protoId_(protoId),
          payload_(std::move(payload)),
          timestamp_(std::chrono::steady_clock::now()),
          registry_(&reqRegistry),
          reqId_(reqRegistry.genRequestId()),
          rootRequestContextId_(rootRequestContextId) {
      reqRegistry.registerStub(*this);
    }

    /**
     * DebugStub objects are oblivious to memory collection, but they should
     * notify their owner registry when unlinking themselves.
     */
    ~DebugStub() {
      if (payload_.hasData()) {
        DCHECK(activeRequestsPayloadHook_.is_linked());
        registry_->onStubPayloadUnlinked(*this);
      }
    }

    const ResponseChannelRequest& getRequest() const {
      return *req_;
    }

    const Cpp2RequestContext& getRequestContext() const {
      return *reqContext_;
    }

    std::chrono::steady_clock::time_point getTimestamp() const {
      return timestamp_;
    }

    const RequestId& getRequestId() const {
      return reqId_;
    }

    intptr_t getRootRequestContextId() const {
      return rootRequestContextId_;
    }

    /**
     * Clones the payload buffer to data accessors. If the buffer is already
     * released by memory collection, returns an empty unique_ptr.
     * Since ActiveRequestsRegistry doesn'y provide synchronization by default,
     * this should be called from the IO worker which also owns the same
     * ActiveRequestsRegistry.
     */
    std::unique_ptr<folly::IOBuf> clonePayload() const {
      return payload_.cloneData();
    }

    protocol::PROTOCOL_TYPES getProtoId() const {
      return protoId_;
    }

   private:
    uint64_t getPayloadSize() const {
      return payload_.dataSize();
    }
    void releasePayload() {
      payload_.releaseData();
    }
    const ResponseChannelRequest* req_;
    const Cpp2RequestContext* reqContext_;
    const protocol::PROTOCOL_TYPES protoId_;
    DebugPayload payload_;
    std::chrono::steady_clock::time_point timestamp_;
    ActiveRequestsRegistry* registry_;
    const RequestId reqId_;
    const intptr_t rootRequestContextId_;
    folly::IntrusiveListHook activeRequestsPayloadHook_;
    folly::IntrusiveListHook activeRequestsRegistryHook_;
  };
  using ActiveRequestDebugStubList =
      folly::IntrusiveList<DebugStub, &DebugStub::activeRequestsRegistryHook_>;
  using ActiveRequestPayloadList =
      folly::IntrusiveList<DebugStub, &DebugStub::activeRequestsPayloadHook_>;

  ActiveRequestsRegistry(uint64_t requestPayloadMem, uint64_t totalPayloadMem);

  const ActiveRequestDebugStubList& getDebugStubList() {
    return reqDebugStubList_;
  }

  void registerStub(DebugStub& req) {
    uint64_t payloadSize = req.getPayloadSize();
    reqDebugStubList_.push_back(req);
    if (payloadSize > payloadMemoryLimitPerRequest_) {
      req.releasePayload();
      return;
    }
    reqPayloadList_.push_back(req);
    payloadMemoryUsage_ += payloadSize;
    evictStubPayloads();
  }

 private:
  void evictStubPayloads() {
    while (payloadMemoryUsage_ > payloadMemoryLimitTotal_) {
      auto& stub = nextStubToEvict();

      onStubPayloadUnlinked(stub);
      reqPayloadList_.erase(reqPayloadList_.iterator_to(stub));
      stub.releasePayload();
    }
  }
  DebugStub& nextStubToEvict() {
    return reqPayloadList_.front();
  }
  void onStubPayloadUnlinked(const DebugStub& stub) {
    uint64_t payloadSize = stub.getPayloadSize();
    DCHECK(payloadMemoryUsage_ >= payloadSize);
    payloadMemoryUsage_ -= payloadSize;
  }
  RequestId genRequestId();
  uint32_t registryId_;
  uint64_t nextLocalId_{0};
  uint64_t payloadMemoryLimitPerRequest_;
  uint64_t payloadMemoryLimitTotal_;
  uint64_t payloadMemoryUsage_{0};
  ActiveRequestDebugStubList reqDebugStubList_;
  ActiveRequestPayloadList reqPayloadList_;
};

} // namespace thrift
} // namespace apache
