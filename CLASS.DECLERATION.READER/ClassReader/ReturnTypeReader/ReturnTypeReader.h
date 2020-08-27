
#ifndef RETURNTYPEREADER_H
#define RETURNTYPEREADER_H

#include <cstring>
#include "CharOperator.h"

class ReturnTypeReader
{
public:
  ReturnTypeReader();
  ReturnTypeReader(const ReturnTypeReader & orig);
  virtual ~ReturnTypeReader();
  void Receive_Method_Name(char * MehodName);
  void SetMethodLine(char * Method);
  void DetermineMethodReturnType();
  void SetSyntaxErrorStatus(bool Status);
  void SetClassConstructorStatus(bool Status);
  void SetClassDestructorStatus(bool Status);
  bool GetClassConstructorStatus();
  bool GetClassDestructorStatus();
  bool GetSyntaxErrorStatus();
  void Clear_Dynamic_Memory();
  char * GetMethodReturnType();
private:
  void Place_String_List(char ** Pointer, char * String, int List_Size);
  void Place_Null(char ** Pointer,int size);
  void Clear_String_List(char ** List);
  CharOperator CharacterOperations;
  bool   ClassConstructorStatus;
  bool   ClassDestructorStatus;
  bool   SyntaxError;
  bool   Memory_Delete_Condition;
  char * MethodLine;
  char * MethodReturnType;
  char * MethodName;
};

#endif /* RETURNTYPEREADER_H */
