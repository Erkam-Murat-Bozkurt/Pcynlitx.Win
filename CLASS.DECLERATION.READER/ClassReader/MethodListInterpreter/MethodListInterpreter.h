
#ifndef METHODLISTINTERPRETER_H
#define METHODLISTINTERPRETER_H

#include <cstring>
#include "CharOperator.h"
#include "IntToCharTranslater.h"
#include "StringOperator.h"

class MethodListInterpreter
{
public:
  MethodListInterpreter();
  MethodListInterpreter(const MethodListInterpreter &orig);
  virtual ~MethodListInterpreter();
  void SetFilePath(const char * TargetFileName);
  void SetFilePath(char * TargetFileName);
  void ReadMetaData();
  void Clear_Dynamic_Memory();
  bool GetPublicDeclerationExistance();
  bool GetPrivateDeclerationExistance();
  bool GetProtectedDeclerationExistance();
  int  GetPublicMethodNumber();
  int  GetPrivateMethodNumber();
  int  GetProtectedMethodNumber();
  int  GetPublicRecordsStartLine();
  int  GetPrivateRecordsStartLine();
  int  GetProtectedRecordsStartLine();
private:
  void SetupSetPointMarkers();
  void DetermineMethodAcessTypes();
  void ReadReferenceNumbers(char * DeclerationMarker, int * methodNumber, int * lineNumber);
  void SearchDeclerationMarker(char * DeclerationMarker,bool * existance_condition);
  int  ReadRecordedInformation(char * linePointer);
  void Place_Null_For_String_List(char ** String_List, int List_Size);
  void Clear_String_List(char ** String_List);
  void Place_String_List(char ** Pointer, char * String_List, int List_Size);
  IntToCharTranslater Translater;
  CharOperator CharacterOperations;
  StringOperator StringOperations;
  int  publicLineNumber;
  int  privateLineNumber;
  int  protectedLineNumber;
  int  RecordEndLine;
  int  PublicMethodNumber;
  int  PrivateMethodNumber;
  int  ProtectedMethodNumber;
  int  RecordInformation;
  bool Memory_Delete_Condition;
  bool isTherePublicDecleration;
  bool isTherePrivateDecleration;
  bool isThereProtectedDecleration;
  char * FilePath;
  char * public_decleration_marker;
  char * private_decleration_marker;
  char * protected_decleration_marker;
  char * record_end_marker;
};

#endif /* METHODLISTINTERPRETER_H */
