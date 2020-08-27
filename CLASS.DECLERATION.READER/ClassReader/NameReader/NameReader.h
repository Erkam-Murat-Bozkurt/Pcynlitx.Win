
#ifndef NAMEREADER_H
#define NAMEREADER_H

#include <cstring>
#include "StringOperator.h"
#include "CharOperator.h"


class NameReader
{
public:
  NameReader();
  NameReader(const NameReader & orig);
  virtual ~NameReader();
  void DetermineMethodName();
  void SetMethodReturnType(char * ReturnType);
  void SetMethodLine(char * MethodLine);
  void SetSyntaxErrorStatus(bool Status);
  bool GetSyntaxErrorStatus();
  void SetClassConstructorStatus(bool Status);
  bool GetClassConstructorStatus();
  void SetClassDestructorStatus(bool Status);
  bool GetClassDestructorStatus();
  void Clear_Dynamic_Memory();
  char * GetMethodName();
  char * GetMethodReturnType();
private:
  void Place_Null_For_String_List(char ** String_List, int List_Size);
  void Clear_String_List(char ** String_List);
  void Place_String_List(char ** Pointer, char * String_List, int List_Size);
  CharOperator CharacterOperations;
  StringOperator StringOperations;
  bool   Memory_Delete_Condition;
  bool   ClassConstructorStatus;
  bool   ClassDestructorStatus;
  bool   SyntaxError;
  char * MethodLine;
  char * MethodName;
  char * ReturnType;
};

#endif /* NAMEREADER_H */
