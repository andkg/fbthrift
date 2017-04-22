/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/complex-union/gen-cpp2/module_types.h"

#include "thrift/compiler/test/fixtures/complex-union/gen-cpp2/module_types.tcc"

#include <algorithm>

#include <folly/Indestructible.h>

#include "thrift/compiler/test/fixtures/complex-union/gen-cpp2/module_data.h"



namespace cpp2 {

void ComplexUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::intValue:
    {
      destruct(value_.intValue);
      break;
    }
    case Type::stringValue:
    {
      destruct(value_.stringValue);
      break;
    }
    case Type::intListValue:
    {
      destruct(value_.intListValue);
      break;
    }
    case Type::stringListValue:
    {
      destruct(value_.stringListValue);
      break;
    }
    case Type::stringRef:
    {
      destruct(value_.stringRef);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool ComplexUnion::operator==(const ComplexUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::intValue:
    {
      return value_.intValue == rhs.value_.intValue;
      break;
    }
    case Type::stringValue:
    {
      return value_.stringValue == rhs.value_.stringValue;
      break;
    }
    case Type::intListValue:
    {
      return value_.intListValue == rhs.value_.intListValue;
      break;
    }
    case Type::stringListValue:
    {
      return value_.stringListValue == rhs.value_.stringListValue;
      break;
    }
    case Type::stringRef:
    {
      return *value_.stringRef == *rhs.value_.stringRef;
      break;
    }
    default:
    {
      return true;
      break;
    }
  }
}

void swap(ComplexUnion& a, ComplexUnion& b) {
  ComplexUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template uint32_t ComplexUnion::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ComplexUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ComplexUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ComplexUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ComplexUnion::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t ComplexUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ComplexUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ComplexUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
namespace cpp2 {

void FinalComplexUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::thingOne:
    {
      destruct(value_.thingOne);
      break;
    }
    case Type::thingTwo:
    {
      destruct(value_.thingTwo);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool FinalComplexUnion::operator==(const FinalComplexUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::thingOne:
    {
      return value_.thingOne == rhs.value_.thingOne;
      break;
    }
    case Type::thingTwo:
    {
      return value_.thingTwo == rhs.value_.thingTwo;
      break;
    }
    default:
    {
      return true;
      break;
    }
  }
}

void swap(FinalComplexUnion& a, FinalComplexUnion& b) {
  FinalComplexUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template uint32_t FinalComplexUnion::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t FinalComplexUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t FinalComplexUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t FinalComplexUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t FinalComplexUnion::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t FinalComplexUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t FinalComplexUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t FinalComplexUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
namespace cpp2 {

} // cpp2
