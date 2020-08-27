
#ifndef TM_CLIENT_BULDER_H
#define TM_CLIENT_BULDER_H

#include "Descriptor_File_Reader.h"
#include "TM_Client_Header_Builder.h"
#include "CFileOperations.h"
#include "DirectoryOperations.h"
#include "Custom_System_Interface.h"
#include <cstring>
#include <cstdlib>

class TM_Client_Builder
{
public:
  TM_Client_Builder();
  TM_Client_Builder(const TM_Client_Builder & orig);
  virtual ~TM_Client_Builder();
  void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
  void Build_Thread_Manager_Client();
  void Run_System_Commands();
  void Clear_Dynamic_Memory();
private:
  void Clear_Pointer_Memory(char ** Pointer);
  void Place_Information(char ** Pointer,char * String,int * index_counter);
  void Determine_Compiler_Command();
  void Write_Space(int Space_Number);
  void Remove_Source_File();
  Descriptor_File_Reader * Reader_Pointer;
  TM_Client_Header_Builder Header_Builder;
  CFileOperations File_Manager;
  DirectoryOperations Directory_Manager;
  Custom_System_Interface System_Interface;
  char * Compiler_Command;
  char * Constructed_Include_Directory;
  bool Memory_Delete_Condition;
};

#endif /* TM_CLIENT_BULDER_H */
