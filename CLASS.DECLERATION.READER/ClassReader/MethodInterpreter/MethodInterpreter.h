
#ifndef METHODINTERPRETER_H
#define METHODINTERPRETER_H

#include <cstring>
#include "MethodReceiver.h"
#include "NameReader.h"
#include "ReturnTypeReader.h"
#include "ParameterReader.h"


class MethodInterpreter
{
public:
  MethodInterpreter();
  MethodInterpreter(const MethodInterpreter & orig);
  virtual ~MethodInterpreter();
  void ReceiveMethodLine(char * MethodInterpreter);
  void SetClassName(char * ClassName);
  void ReadMethod();
  void setMethodAccessType(char * MethodAxessType);
  void setMethodIDNumber(int);
  void Clear_Dynamic_Memory();
  bool    getMethodSyntaxErrorStatus();
  int     getMethodIDNumber();
  int     getMethodParameterNumber();
  char *  GetClassName();
  char *  getMethodAccessType();
  char *  getMethodName();
  char *  getMethodReturnType();
  char ** getMethodParameterNames();
  char ** getMethodParameterTypes();
private:
  void SetMethodReturnType(char * ReturnType);
  void SetMethodName(char * MethodName);
  void SetParameterTypes(char ** ParameterTypes);
  void SetParameterNames(char ** ParameterNames);
  void SetMethodParameterNumber(int Number);
  void setMethodSyntaxErrorStatus(bool);
  void Place_Null(char ** Pointer, int size);
  void Place_String_List(char ** Pointer, char * String, int List_Size);
  void Clear_String_List(char ** Pointer);
  MethodReceiver MethodLineReceiver;
  ReturnTypeReader MethodReturnTypeReader;
  NameReader MethodNameReader;
  ParameterReader MethodParameterReader;
  bool   Memory_Delete_Condition;
  bool   SyntaxErrorCondition;
  int    MethodIDNumber;
  int    MethodParameterNumber;
  int    Default_Empty_List_Size;
  char * MethodAccessType;
  char * ClassName;
  char * ReturnType;
  char * MethodName;
  char ** ParameterTypes;
  char ** ParameterNames;
};

#endif /*  METHODINTERPRETER_H */
