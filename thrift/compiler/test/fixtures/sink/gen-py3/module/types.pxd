#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libc.stdint cimport (
    int8_t as cint8_t,
    int16_t as cint16_t,
    int32_t as cint32_t,
    int64_t as cint64_t,
    uint32_t as cuint32_t,
)
from libcpp.string cimport string
from libcpp cimport bool as cbool, nullptr, nullptr_t
from cpython cimport bool as pbool
from libcpp.memory cimport shared_ptr, unique_ptr
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap, pair as cpair
from thrift.py3.exceptions cimport cTException
cimport folly.iobuf as __iobuf
cimport thrift.py3.exceptions
cimport thrift.py3.types
from thrift.py3.common cimport Protocol as __Protocol
from thrift.py3.types cimport (
    bstring,
    field_ref as __field_ref,
    optional_field_ref as __optional_field_ref,
    required_field_ref as __required_field_ref,
)
from folly.optional cimport cOptional
cdef extern from "src/gen-py3/module/types.h":
  pass





cdef extern from "src/gen-cpp2/module_types_custom_protocol.h" namespace "::cpp2":
    cdef cppclass cInitialResponse__isset "::cpp2::InitialResponse::__isset":
        bint content

    cdef cppclass cInitialResponse "::cpp2::InitialResponse":
        cInitialResponse() except +
        cInitialResponse(const cInitialResponse&) except +
        bint operator==(cInitialResponse&)
        bint operator!=(cInitialResponse&)
        bint operator<(cInitialResponse&)
        bint operator>(cInitialResponse&)
        bint operator<=(cInitialResponse&)
        bint operator>=(cInitialResponse&)
        __field_ref[string] content_ref()
        string content
        cInitialResponse__isset __isset

    cdef cppclass cFinalResponse__isset "::cpp2::FinalResponse::__isset":
        bint content

    cdef cppclass cFinalResponse "::cpp2::FinalResponse":
        cFinalResponse() except +
        cFinalResponse(const cFinalResponse&) except +
        bint operator==(cFinalResponse&)
        bint operator!=(cFinalResponse&)
        bint operator<(cFinalResponse&)
        bint operator>(cFinalResponse&)
        bint operator<=(cFinalResponse&)
        bint operator>=(cFinalResponse&)
        __field_ref[string] content_ref()
        string content
        cFinalResponse__isset __isset

    cdef cppclass cSinkPayload__isset "::cpp2::SinkPayload::__isset":
        bint content

    cdef cppclass cSinkPayload "::cpp2::SinkPayload":
        cSinkPayload() except +
        cSinkPayload(const cSinkPayload&) except +
        bint operator==(cSinkPayload&)
        bint operator!=(cSinkPayload&)
        bint operator<(cSinkPayload&)
        bint operator>(cSinkPayload&)
        bint operator<=(cSinkPayload&)
        bint operator>=(cSinkPayload&)
        __field_ref[string] content_ref()
        string content
        cSinkPayload__isset __isset

    cdef cppclass cCompatibleWithKeywordSink__isset "::cpp2::CompatibleWithKeywordSink::__isset":
        bint sink

    cdef cppclass cCompatibleWithKeywordSink "::cpp2::CompatibleWithKeywordSink":
        cCompatibleWithKeywordSink() except +
        cCompatibleWithKeywordSink(const cCompatibleWithKeywordSink&) except +
        bint operator==(cCompatibleWithKeywordSink&)
        bint operator!=(cCompatibleWithKeywordSink&)
        bint operator<(cCompatibleWithKeywordSink&)
        bint operator>(cCompatibleWithKeywordSink&)
        bint operator<=(cCompatibleWithKeywordSink&)
        bint operator>=(cCompatibleWithKeywordSink&)
        __field_ref[string] sink_ref()
        string sink
        cCompatibleWithKeywordSink__isset __isset

    cdef cppclass cInitialException__isset "::cpp2::InitialException::__isset":
        bint reason

    cdef cppclass cInitialException "::cpp2::InitialException"(cTException):
        cInitialException() except +
        cInitialException(const cInitialException&) except +
        bint operator==(cInitialException&)
        bint operator!=(cInitialException&)
        bint operator<(cInitialException&)
        bint operator>(cInitialException&)
        bint operator<=(cInitialException&)
        bint operator>=(cInitialException&)
        __field_ref[string] reason_ref()
        string reason
        cInitialException__isset __isset

    cdef cppclass cSinkException1__isset "::cpp2::SinkException1::__isset":
        bint reason

    cdef cppclass cSinkException1 "::cpp2::SinkException1"(cTException):
        cSinkException1() except +
        cSinkException1(const cSinkException1&) except +
        bint operator==(cSinkException1&)
        bint operator!=(cSinkException1&)
        bint operator<(cSinkException1&)
        bint operator>(cSinkException1&)
        bint operator<=(cSinkException1&)
        bint operator>=(cSinkException1&)
        __field_ref[string] reason_ref()
        string reason
        cSinkException1__isset __isset

    cdef cppclass cSinkException2__isset "::cpp2::SinkException2::__isset":
        bint reason

    cdef cppclass cSinkException2 "::cpp2::SinkException2"(cTException):
        cSinkException2() except +
        cSinkException2(const cSinkException2&) except +
        bint operator==(cSinkException2&)
        bint operator!=(cSinkException2&)
        bint operator<(cSinkException2&)
        bint operator>(cSinkException2&)
        bint operator<=(cSinkException2&)
        bint operator>=(cSinkException2&)
        __field_ref[cint64_t] reason_ref()
        cint64_t reason
        cSinkException2__isset __isset




cdef class InitialResponse(thrift.py3.types.Struct):
    cdef shared_ptr[cInitialResponse] _cpp_obj

    @staticmethod
    cdef unique_ptr[cInitialResponse] _make_instance(
        cInitialResponse* base_instance,
        bint* __isNOTSET,
        str content
    ) except *

    @staticmethod
    cdef create(shared_ptr[cInitialResponse])



cdef class FinalResponse(thrift.py3.types.Struct):
    cdef shared_ptr[cFinalResponse] _cpp_obj

    @staticmethod
    cdef unique_ptr[cFinalResponse] _make_instance(
        cFinalResponse* base_instance,
        bint* __isNOTSET,
        str content
    ) except *

    @staticmethod
    cdef create(shared_ptr[cFinalResponse])



cdef class SinkPayload(thrift.py3.types.Struct):
    cdef shared_ptr[cSinkPayload] _cpp_obj

    @staticmethod
    cdef unique_ptr[cSinkPayload] _make_instance(
        cSinkPayload* base_instance,
        bint* __isNOTSET,
        str content
    ) except *

    @staticmethod
    cdef create(shared_ptr[cSinkPayload])



cdef class CompatibleWithKeywordSink(thrift.py3.types.Struct):
    cdef shared_ptr[cCompatibleWithKeywordSink] _cpp_obj

    @staticmethod
    cdef unique_ptr[cCompatibleWithKeywordSink] _make_instance(
        cCompatibleWithKeywordSink* base_instance,
        bint* __isNOTSET,
        str sink
    ) except *

    @staticmethod
    cdef create(shared_ptr[cCompatibleWithKeywordSink])



cdef class InitialException(thrift.py3.exceptions.GeneratedError):
    cdef shared_ptr[cInitialException] _cpp_obj

    @staticmethod
    cdef unique_ptr[cInitialException] _make_instance(
        cInitialException* base_instance,
        bint* __isNOTSET,
        str reason
    ) except *

    @staticmethod
    cdef create(shared_ptr[cInitialException])



cdef class SinkException1(thrift.py3.exceptions.GeneratedError):
    cdef shared_ptr[cSinkException1] _cpp_obj

    @staticmethod
    cdef unique_ptr[cSinkException1] _make_instance(
        cSinkException1* base_instance,
        bint* __isNOTSET,
        str reason
    ) except *

    @staticmethod
    cdef create(shared_ptr[cSinkException1])



cdef class SinkException2(thrift.py3.exceptions.GeneratedError):
    cdef shared_ptr[cSinkException2] _cpp_obj

    @staticmethod
    cdef unique_ptr[cSinkException2] _make_instance(
        cSinkException2* base_instance,
        bint* __isNOTSET,
        object reason
    ) except *

    @staticmethod
    cdef create(shared_ptr[cSinkException2])



