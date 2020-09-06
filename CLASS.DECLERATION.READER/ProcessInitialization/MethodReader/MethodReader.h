#ifndef METHODREADER_H
#define METHODREADER_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ListFileOrganizer.h"
#include "Cpp_FileOperations.h"
#include "FindSetPoints.h"
#include "CharOperator.h"
#include "SyntaxController.h"
#include "ClassNameReader.h"
#include "IntToCharTranslater.h"
#include "DirectoryOperations.h"


class MethodReader
{
public:
  MethodReader();
  MethodReader(const MethodReader & orig);
  virtual ~MethodReader();
  void ReadFunctionDeclerations();
  void Receive_Header_File_Path(char * TargetHeaderFile);
  void ReceiveIncludeDirectoryPATH(char * IncludeDirectoryPATH);
  void ReceiveDataBaseConstructionPoint(char * RecordDirectory);
  void Clear_Dynamic_Memory();
  int GetPublicMethodNumber();
  int GetPrivateMethodNumber();
  int GetProtectedMethodNumber();
  char * GetDataRecordDirectory();
  char * GetRecordFilePath();
  char * GetMetaDataFilePath();
  char * GetHeaderFilePath();
  char * GetIncludeDirectoryPATH();
  char * GetClassName();
  char ** GetPublicMethods();
  char ** GetPrivateMethods();
  char ** GetProtectedMethods();
private:
  void ConstructMethodList();
  void ExtractClassMethods();
  void RecordListMetaData();
  void DeterminePublicMethods();
  void DeterminePrivateMethods();
  void DetermineProtectedMethods();
  void ReceiveMethodLine(char ** MethodPointer,char * MethodLine);
  void Place_String(char ** Pointer, const char * String, int String_Size);
  void Place_String(char ** Pointer, char * String, int String_Size);
  void Place_Null(char ** Pointer, int List_Size);
  void Clear_Pointer_Memory(char ** Pointer);
  bool IsMethodLine(char * ListLine);
  ListFileOrganizer FileOrganizer;
  FindSetPoints SetPointExplorer;
  Cpp_FileOperations FileManager;
  CharOperator CharacterOperations;
  SyntaxController * SyntaxOperations;
  ClassNameReader ClassNameDeterminer;
  IntToCharTranslater TypeConverter;
  DirectoryOperations DirectoryManager;
  bool Memory_Delete_Condition;
  bool isMethodLine;
  int CurrentLineNumber;
  int ListLineNumber;
  int PublicMethodNumber;
  int PrivateMethodNumber;
  int ProtectedMethodNumber;
  int PublicMethodsStartPoint;
  int PrivateMethodsStartPoint;
  int ProtectedMethodsStartPoint;
  int Default_Null_List_Size;
  char ** PublicMethods;
  char ** PrivateMethods;
  char ** ProtectedMethods;
};

#endif /* METHODREADER_H */
