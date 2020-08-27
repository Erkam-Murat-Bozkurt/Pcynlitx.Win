
#ifndef PARAMETERREADER_H
#define PARAMETERREADER_H

#include "CharOperator.h"

class ParameterReader
{
public:
  ParameterReader();
  ParameterReader(const ParameterReader & orig);
  virtual ~ParameterReader();
  void Read_Parameter_Informations();
  void SetSyntaxErrorStatus(bool Status);
  void SetMethodParameterNumber(int ParameterNumber);
  void SetMethodParenthes(char * MethodParenthes);
  bool GetSyntaxErrorStatus();
  void Clear_Dynamic_Memory();
  int  getMethodParameterNumber();
  char ** GetMethodParameterTypes();
  char ** GetMethodParameterNames();
private:
  void DetermineMethodParameterTypes();
  void DetermineMethodParameterNames();
  int  FindThePreviousCharacterPosition(char Character,int startPoint);
  void Place_Null_For_String_List(char ** String_List, int List_Size);
  void Clear_Pointer_Memory(char ** Pointer);
  void Place_String_List(char ** Pointer, char * String_List, int List_Size);
  void Determine_Is_there_a_parameter_name_in_the_case_of_single_parameter();
  CharOperator CharacterOperations;
  bool    SyntaxError;
  int     MethodParameterNumber;
  int     BackPointRemarker;
  int     Default_Empty_List_Size;
  char *  MethodParenthes;
  char ** MethodParameterTypes;
  char ** MethodParameterNames;
  bool    Memory_Delete_Condition;
  bool    Is_there_a_parameter_name_in_the_case_of_single_parameter;
};

#endif /* PARAMETERREADER_H */
