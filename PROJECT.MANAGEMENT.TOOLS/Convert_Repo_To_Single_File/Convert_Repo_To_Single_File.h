

#ifndef CONVERT_REPO_TO_SINGLE_FILE_H
#define CONVERT_REPO_TO_SINGLE_FILE_H

#include <ctype.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <windows.h>
#include "Document_Builder.h"
#include "DirectoryOperations.h"
#include "Cpp_FileOperations.h"
#include "CharOperator.h"

class Convert_Repo_To_Single_File
{
public:
  Convert_Repo_To_Single_File();
  Convert_Repo_To_Single_File(const Convert_Repo_To_Single_File & orig);
  virtual ~Convert_Repo_To_Single_File();
  void Receive_Repo_Directory(char * name);
  void Construct_Source_File();
  void Clear_Dynamic_Memory();
private:
  void Place_String(char ** Pointer, char * String);
  char * Convert_to_C_String(std::string command);
  void List_Files_in_Repo();
  void Determine_File_Size();
  void Allocate_Memory_For_Reading();
  void Read_File();
  void Add_To_Document();
  char * Repo_Directory;
  char * File_Path;
  char * System_Call;
  int File_Line_Number;
  std::string * File_List_Content;
  Document_Builder Doc_Builder;
  Cpp_FileOperations FileManager;
  DirectoryOperations DirectoryManager;
  bool Memory_Delete_Condition;
  bool Repo_Directory_Receive_Status;
};

#endif /* CONVERT_REPO_TO_SINGLE_FILE_H */
