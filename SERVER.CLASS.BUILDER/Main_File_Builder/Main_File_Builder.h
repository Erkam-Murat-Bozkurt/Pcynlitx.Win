
#ifndef MAIN_FILE_BUILDER_H
#define MAIN_FILE_BUILDER_H

#include <cstring>
#include <cstdlib>
#include "Cpp_FileOperations.h"
#include "DirectoryOperations.h"
#include "Descriptor_File_Reader.h"
#include "IntToCharTranslater.h"

class Main_File_Builder
{
public:
  Main_File_Builder();
  Main_File_Builder(const Main_File_Builder & orig);
  virtual ~Main_File_Builder();
  void Receive_Descriptor_File_Object_Addres(Descriptor_File_Reader * File_Reader);
  void Receive_Newly_Constructed_Include_Directory_Name(char * Directory_Name);
  void Build_Main_File();
private:
  void Move_Header_File_List_To_New_Include_Directory();
  void Place_Information(char ** Pointer, char * Information, int * counter);
  void Write_Space(const char * String);
  Cpp_FileOperations File_Manager;
  DirectoryOperations Directory_Manager;
  Descriptor_File_Reader * File_Reader;
  IntToCharTranslater Translater;
  char * Supervisor_Class_Header_File_Name;
  char * New_Include_Directory_Name;
  bool   Memory_Delete_Condition;
};

#endif /* MAIN_FILE_BUILDER_H */
