
#ifndef COMPILER_DESCRIPTOR_FILE_READER_H
#define COMPILER_DESCRIPTOR_FILE_READER_H

#include "StringOperator.h"
#include "DirectoryOperations.h"
#include <cstring>
#include <cstdlib>

class Compiler_Descriptor_File_Reader
{
public:
  Compiler_Descriptor_File_Reader();
  Compiler_Descriptor_File_Reader(const Compiler_Descriptor_File_Reader & orig);
  virtual ~Compiler_Descriptor_File_Reader();
  void Receive_Descriptor_File_Directory(const char * DescriptorFileDirectory);
  void Receive_Descriptor_File_Directory(char * DescriptorFileDirectory);
  void Receive_Descriptor_File_Name(const char * DescriptorFileName);
  void Receive_Descriptor_File_Name(char * DescriptorFileName);
  void Receive_Descriptor_File_Infomations();
  void Clear_Dynamic_Memory();
  char ** Include_Directory_List;
  char ** Library_Directory_List;
  char ** Source_File_Directory_List;
  char ** Source_File_Name_List;
  char ** Header_File_Name_List;
  char ** Library_Name_List;
  char ** Option_List;
  char *  Main_File_Name;
  char *  Executable_File_Name;
  char *  DescriptorFileDirectory;
  char *  DescriptorFileName;
  int Include_Directory_Number;
  int Library_Directory_Number;
  int Source_File_Directory_Number;
  int Source_File_Names_Number;
  int Header_File_Names_Number;
  int Library_Names_Number;
  int Option_Number;
  bool Is_There_Main_File_Decleration;
private:
  void Determine_Decleration_Locations();
  void Determine_Decleration_Numbers();
  void Allocate_Memory_For_Lists();
  int  Determine_Record_Number(int Start_Line,int End_Line);
  void ReadConstString(const char * String);
  char * GetConstString();
  bool Get_Line_Record_Status(char * Read_Line);
  void Place_String(char ** Pointer, char * String, int String_Size);
  void Place_String(char ** Pointer, const char * String, int String_Size);
  void Place_Information(char ** Pointer, char * Information, int * index_counter);
  void Clear_Pointer_Memory(char ** Pointer);
  void Receive_Include_Directory_List();
  void Receive_Library_Directory_List();
  void Receive_Source_File_Directory_List();
  void Receive_Source_File_Name_List();
  void Receive_Header_File_Name_List();
  void Receive_Library_Name_List();
  void Receive_Option_List();
  void Receive_Main_File_Name();
  StringOperator StringOperations;
  DirectoryOperations DirectoryManager;
  char * ConstString;
  int Options_Decleration_Region[2];
  int Executable_File_Name_Region[2];
  int Include_Directories_Region[2];
  int Library_Directories_Region[2];
  int SourceFile_Directores_Region[2];
  int SourceFile_Names_Region[2];
  int HeaderFile_Names_Region[2];
  int Library_Names_Region[2];
  int Main_File_Decleration_Region[2];
  int Record_Number;
  bool Memory_Delete_Condition;
  bool Is_This_Record_Line;
};


#endif /* COMPILER_DESCRIPTOR_FILE_READER_H */
