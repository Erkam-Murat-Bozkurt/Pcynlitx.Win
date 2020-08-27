
#ifndef METHODINITIALIZER_H
#define METHODINITIALIZER_H

#include <cstring>
#include "CharOperator.h"

class MethodInitializer
{
public:
  MethodInitializer();
  MethodInitializer(const MethodInitializer & orig);
  virtual ~MethodInitializer();
  void ReceiveMethod(char *);
  void ProcessMethodInformation();
  bool getMethodInitializerErrorCondition();
  void setMethodInitializerErrorCondition(bool condition);
  int  HowManySpaces(char * MethodLine,int startPoint,int endPoint);
  bool getFirstBraceExistance();
  bool getLastBraceExistance();
  bool getMethodNameExistance();
  void Clear_Dynamic_Memory();
  char * getMethodLine();
private:
  CharOperator CharacterOperations;
  void CheckFirstBrace_Existance();
  void CheckLastBrace_Existance();
  void CheckMethodName_Existance();
  void CheckAdressCharacterInsidePharentheses();
  void CheckAdressCharacterBeforeFirstBrace();
  void AddSpaceAfterComma();
  void Delete_Spaces_Before_MethodName();
  void CheckSpaceNumberBeforeFirstBrace();
  bool is_Method_Name_Includes_operator_word();
  bool is_There_Adress_Character_Just_Before_Method_Brace();
  bool is_There_a_new_Adress_Character(int start_position, int end_position);
  int  get_New_Adress_Character_Position(int start_position, int end_position);
  void Delete_Spaces_Between_First_Brace_and_Method_Name();
  void Add_Space_after_predetermined_character(int character_position);
  void Add_Space_before_predetermined_character(int character_position);
  void SpaceCancelProcess();
  int  SpaceCounter(char * MethodLine,int startPoint);
  void RemoveSpaces(char * List,int spaceNumber,int startPoint);
  char * MethodLine;
  bool isFirstBraceExist;
  bool isLastBraceExist;
  bool MethodInitializerErrorCondition;
  bool isMethodNameExist;
  int  SpaceNumber;
  int  HowManySeperateSpaces;
  bool operator_word_inclusion;
  bool is_Adress_Character_Just_Before_Method_Brace;
  bool is_there_another_adress_character;
  int  new_adress_character_position;
  bool Memory_Delete_Condition;
};

#endif /* METHODINITIALIZER_H */
