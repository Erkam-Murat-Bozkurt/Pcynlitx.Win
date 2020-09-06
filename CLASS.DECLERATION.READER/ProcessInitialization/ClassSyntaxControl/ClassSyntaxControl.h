
#ifndef CLASSSYNTAXCONTROL_H
#define CLASSSYNTAXCONTROL_H

#include <cstring>
#include "CharOperator.h"
#include "Cpp_FileOperations.h"
#include "StringOperator.h"


class ClassSyntaxControl
{
public:
  ClassSyntaxControl();
  ClassSyntaxControl(const ClassSyntaxControl & orig);
  virtual ~ClassSyntaxControl();
  void CheckClassSyntax(char * HeaderFile);
  bool GetClassSyntaxErrorStatus();
  int  GetFirstBraceLine();
  int  GetLastBraceLine();
  int  GetClassWordLineNumber();
  bool isThereClassName();
  bool isThereClassWord();
  bool isTherePublicKeyWord();
  bool isTherePrivateKeyWord();
  bool isThereProtectedKeyWord();
  void SetClassSyntaxErrorStatus(bool status);
  void DetermineClassWordLine();
  void CheckClassWord();
  void CheckClassName();
  void CheckStartBrace();
  void CheckEndBrace();
  void CheckPublicKeyWord();
  void CheckPrivateKeyWord();
  void CheckProtectedKeyWord();
  void Clear_Dynamic_Memory();
  char * Get_Class_Word_Line();
private:
  void Place_Null_for_Array(char Array [],int Array_Size);
  void Place_String(char ** Pointer, char * String);
  void Shift_List(char ** Pointer, int Step_Size, int Start_Point);
  void Find_Next_Character_Position(char * Pointer, int * Position, int Start_Point);
  void Find_Next_Space_Position(char * Pointer,int * Position, int Start_Point);
  void Read_Class_Word_Line();
  int  Space_Counter(char * Pointer);
  Cpp_FileOperations FileManager;
  CharOperator CharacterOperations;
  StringOperator StringOperations;
  char * Class_Word_Line;
  int  FirstBraceLine;
  int  LastBraceLine;
  int  ClassWordLineNumber;
  int  PublicKeyWordLine;
  int  Seperate_Space_Number;
  bool ClassSyntaxErrorStatus;
  bool is_record_line;
  bool is_there_a_class_name;
  bool is_there_a_class_word;
  bool is_there_a_public_key_word;
  bool is_there_a_private_key_word;
  bool is_there_a_protected_key_word;
  bool Memory_Delete_Condition;
};

#endif /* CLASSSYNTAXCONTROL_H */
