/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/types/gen-cpp2/module_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::apache::thrift::fixtures::types::has_bitwise_ops> {
  using type = ::apache::thrift::fixtures::types::has_bitwise_ops;
  static constexpr const std::size_t size = 5;
  static constexpr const std::array<type, size> values = {{
    type::none,
    type::zero,
    type::one,
    type::two,
    type::three,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "none",
    "zero",
    "one",
    "two",
    "three",
  }};
};
template <> struct TEnumDataStorage<::apache::thrift::fixtures::types::is_unscoped> {
  using type = ::apache::thrift::fixtures::types::is_unscoped;
  static constexpr const std::size_t size = 2;
  static constexpr const std::array<type, size> values = {{
    type::hello,
    type::world,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "hello",
    "world",
  }};
};
template <> struct TEnumDataStorage<::apache::thrift::fixtures::types::MyForwardRefEnum> {
  using type = ::apache::thrift::fixtures::types::MyForwardRefEnum;
  static constexpr const std::size_t size = 2;
  static constexpr const std::array<type, size> values = {{
    type::ZERO,
    type::NONZERO,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "ZERO",
    "NONZERO",
  }};
};
template <> struct TEnumDataStorage<::apache::thrift::fixtures::types::MyEnumA> {
  using type = ::apache::thrift::fixtures::types::MyEnumA;
  static constexpr const std::size_t size = 3;
  static constexpr const std::array<type, size> values = {{
    type::fieldA,
    type::fieldB,
    type::fieldC,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "fieldA",
    "fieldB",
    "fieldC",
  }};
};

template <> struct TEnumDataStorage<::apache::thrift::fixtures::types::NoExceptMoveUnion::Type> {
  using type = ::apache::thrift::fixtures::types::NoExceptMoveUnion::Type;
  static constexpr const std::size_t size = 2;
  static constexpr const std::array<type, size> values = {{
    type::string_field,
    type::i32_field,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "string_field",
    "i32_field",
  }};
};

}} // apache::thrift
