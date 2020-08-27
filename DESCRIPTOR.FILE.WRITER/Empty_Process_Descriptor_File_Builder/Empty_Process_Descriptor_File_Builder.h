
#ifndef EMPTY_PROCESS_DESCRIPTOR_FILE_BUILDER_H
#define EMPTY_PROCESS_DESCRIPTOR_FILE_BUILDER_H

#include "CFileOperations.h"
#include "DirectoryOperations.h"

class Empty_Process_Descriptor_File_Builder
{
public:
  Empty_Process_Descriptor_File_Builder();
  Empty_Process_Descriptor_File_Builder(const Empty_Process_Descriptor_File_Builder & orig);
  virtual ~Empty_Process_Descriptor_File_Builder();
  void Read_Construction_Point(char * path);
  void Build_Descriptor_File();
  void Clear_Dynamic_Memory();
private:
  CFileOperations File_Manager;
  DirectoryOperations Directory_Manager;
  bool Memory_Delete_Condition;
};

#endif /* EMPTY_PROCESS_DESCRIPTOR_FILE_BUILDER_H */
