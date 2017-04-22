/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */


import java.util.List;

import com.facebook.thrift.lite.*;
import com.facebook.thrift.lite.protocol.*;


public class Module {

  public enum EventType {
    ComplexUnion, FinalComplexUnion;
  }

  public static final ThriftProperty<Long> ComplexUnion_intValue =
      new ThriftProperty<Long>("intValue", TType.I64, (short) 1);
  public static final ThriftProperty<String> ComplexUnion_stringValue =
      new ThriftProperty<String>("stringValue", TType.STRING, (short) 2);
  public static final ThriftProperty<List<Long>> ComplexUnion_intListValue =
      new ThriftProperty<List<Long>>("intListValue", TType.LIST, (short) 3);
  public static final ThriftProperty<List<String>> ComplexUnion_stringListValue =
      new ThriftProperty<List<String>>("stringListValue", TType.LIST, (short) 4);
  public static final ThriftProperty<String> ComplexUnion_stringRef =
      new ThriftProperty<String>("stringRef", TType.STRING, (short) 5);
  public static final ThriftProperty<String> FinalComplexUnion_thingOne =
      new ThriftProperty<String>("thingOne", TType.STRING, (short) 1);
  public static final ThriftProperty<String> FinalComplexUnion_thingTwo =
      new ThriftProperty<String>("thingTwo", TType.STRING, (short) 2);
  
}
