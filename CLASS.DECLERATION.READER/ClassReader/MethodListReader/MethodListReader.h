
#ifndef METHODLISTREADER_H
#define METHODLISTREADER_H

#include "CFileOperations.h"
#include "CharOperator.h"
#include "MethodListInterpreter.h"

class MethodListReader
{
public:
  MethodListReader();
  MethodListReader(const MethodListReader & orig);
  virtual ~MethodListReader();
  void SetMethodListPath(const char * MethodList);
  void SetMetaFilePath(const char * MetaDataFile);
  void SetMethodListPath(char * MethodList);
  void SetMetaFilePath(char * MetaDataFile);
  void ReadMethodList();
  int GetPublicMethodNumber();
  int GetPrivateMethodNumber();
  int GetProtectedMethodNumber();
  int GetTotalMethodNumber();
  void Clear_Dynamic_Memory();
  char ** GetPublicMethods();
  char ** GetPrivateMethods();
  char ** GetProtectedMethods();
private:
  void ReadPublicMethods();
  void ReadPrivateMethods();
  void ReadProtectedMethods();
  bool isThisMethodLine(char * LinePointer);
  void PlaceMethodLine(char ** MethodPointer, char * LinePointer, int MemoryNeed);
  void Place_Null(char ** Pointer,int size);
  void Clear_Pointer_Memory(char ** Pointer);
  void DetermineTotalMethodNumber();
  int  Get_Memory_Need(char * LinePointer);
  MethodListInterpreter ListInterpreter;
  CFileOperations ListFileManager;
  CFileOperations MetaFileManager;
  CharOperator CharacterOperations;
  bool Memory_Delete_Condition;
  char ** PublicMethods;
  char ** PrivateMethods;
  char ** ProtectedMethods;
  int PublicMethodNumber;
  int PrivateMethodNumber;
  int ProtectedMethodNumber;
  int TotalMethodNumber;
  int PublicMethodsStartLine;
  int PrivateMethodsStartLine;
  int ProtectedMethodsStartLine;
  int Memory_Need;
  int Default_Empty_List_Size;
  bool isMethodLine;
};

#endif /* METHODLISTREADER_H */
