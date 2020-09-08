
#ifndef MT_PROJECT_BUILDER_H
#define MT_PROJECT_BUILDER_H

#include "Descriptor_File_Reader.h"
#include "Compiler_Descriptor_File_Constructor.h"
#include "Compiler.h"
#include "DirectoryOperations.h"
#include "Cpp_FileOperations.h"
#include <iostream>
#include <cstring>
#include <unistd.h>

class MT_Project_Builder
{
public:
  MT_Project_Builder();
  MT_Project_Builder(const MT_Project_Builder & orig);
  virtual ~MT_Project_Builder();
  void Receive_Descriptor_File_Directory(const char * DescriptorFileDirectory);
  void Receive_Descriptor_File_Directory(char * DescriptorFileDirectory);
  void Receive_Descriptor_File_Name(const char * DescriptorFileName);
  void Receive_Descriptor_File_Name(char * DescriptorFileName);
  void Build_Project();
  void Clear_Dynamic_Memory();
private:
  void Remove_Compiler_Output_File();
  Descriptor_File_Reader File_Reader;
  Compiler_Descriptor_File_Constructor File_Constructor;
  Compiler Project_Compiler;
  DirectoryOperations Directory_Manager;
  Cpp_FileOperations File_Manager;
  bool Memory_Delete_Condition;
  char * Compiler_Output_File_Path;
};

#endif /* MT_PROJECT_BUILDER_H */
