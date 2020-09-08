
#ifndef MULTI_THREAD_POINTER_FILE_CLEANER_H
#define MULTI_THREAD_POINTER_FILE_CLEANER_H

#include "Cpp_FileOperations.h"
#include <cstring>
#include <unistd.h>

class Multi_Thread_Pointer_File_Cleaner
{
public:
  Multi_Thread_Pointer_File_Cleaner();
  Multi_Thread_Pointer_File_Cleaner(const Multi_Thread_Pointer_File_Cleaner & orig);
  virtual ~Multi_Thread_Pointer_File_Cleaner();
  void Remove_Source_Files(char ** Source_File_List);
  void Remove_Header_File_Extras(char ** Header_File_Matrix);
  void Remove_Object_Files(char ** Object_File_List);
private:
  void Clear_Pointer_Memory(char ** Pointer);
  void Place_Information(char ** Pointer, char * Information, int * index_counter);
  Cpp_FileOperations File_Manager;
};

#endif /* MULTI_THREAD_POINTER_FILE_CLEANER_H*/
