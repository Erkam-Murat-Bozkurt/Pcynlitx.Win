
#ifndef METHODRECEIVER_H
#define METHODRECEIVER_H

#include <cstring>
#include "CharOperator.h"
#include "ParenthesReader.h"


class MethodReceiver
{
public:
  MethodReceiver();
  MethodReceiver(const MethodReceiver & orig);
  virtual ~ MethodReceiver();
  void SetClassName(char * ClassName);
  void ReceiveMethodLine(char * MethodLine);
  void DetermineMethodName();
  void DetermineClassConstructorStatus();
  void DetermineClassDestructorStatus();
  bool getMethodSyntaxErrorStatus();
  int  getMethodParameterNumber();
  bool getClassConstructorStatus();
  bool getClassDestructorStatus();
  void Clear_Dynamic_Memory();
  char * getMethodLine();
  char * getMethodParenthes();
  char * getClassName();
  char * getClassConstructorName();
  char * getClassDestructorName();
private:
  CharOperator CharacterOperations;
  ParenthesReader ParenthesOperations;
  void Place_Null(char ** Pointer, int List_Size);
  void setMethodSyntaxErrorStatus(bool);
  void Clear_String_List(char ** String_List);
  int    MethodParameterNumber;
  bool   SyntaxErrorCondition;
  bool   ClassConstructorStatus;
  bool   ClassDestructorStatus;
  bool   Memory_Delete_Condition;
  char * MethodLine;
  char * MethodParenthes;
  char * ClassName;
  char * MethodNameBuffer;
  char * ClassConstructorName;
  char * ClassDestructorName;
};

#endif /* METHODRECEIVER_H */
