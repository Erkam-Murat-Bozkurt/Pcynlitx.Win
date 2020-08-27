
#ifndef PARENTHESREADER_H
#define PARENTHESREADER_H

#include <cstring>
#include "CharOperator.h"

class ParenthesReader
{
public:
  ParenthesReader();
  ParenthesReader(const ParenthesReader & orig);
  virtual ~ ParenthesReader();
  void ReadMethodParenthes(char *);
  int  getMethodParameterNumber();
  void SetSyntaxErrorStatus(bool status);
  bool GetSyntaxErrorStatus();
  void Clear_Dynamic_Memory();
  char * getMethodParenthes();
private:
  CharOperator CharacterOperations;
  void Place_Null(char ** Pointer, int size);
  void Clear_String_List(char ** Pointer);
  void ExtractMethodParenthes();
  void ReceiveMethodLine(char *);
  void DetermineMethodParameterNumber();
  bool SyntaxError;
  bool Memory_Delete_Condition;
  int  MethodParameterNumber;
  char * MethodLine;
  char * MethodParenthes;
};

#endif /* PARENTHESREADER_H */
