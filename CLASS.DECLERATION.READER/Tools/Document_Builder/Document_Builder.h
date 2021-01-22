
#ifndef DOCUMENT_BUILDER_H
#define DOCUMENT_BUILDER_H

#include <ctype.h>
#include <cstring>
#include <string>
#include "Cpp_FileOperations.h"

class Document_Builder
{
public:
  Document_Builder();
  Document_Builder(const Document_Builder & orig);
  virtual ~Document_Builder();
  void Receive_Document_Name(char * name);
  void Receive_File_Path(char * path);
  void Add_File_To_Document();
  void Clear_Dynamic_Memory();
private:
  void Place_String(char ** Pointer, char * String);
  void Determine_File_Size();
  void Allocate_Memory_For_Reading();
  void Read_File();
  void Add_To_Document();
  char * FilePath;
  char * Document_Name;
  std::string * File_Content;
  Cpp_FileOperations FileManager;
  bool Memory_Delete_Condition;
  bool File_Path_Receive_Status;
  bool Document_Name_Receive_Status;
  int File_Line_Number;
};

#endif /* DOCUMENT_BUILDER_H */
