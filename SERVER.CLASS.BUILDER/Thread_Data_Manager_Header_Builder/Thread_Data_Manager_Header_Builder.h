
#ifndef THREAD_DATA_MANAGER_HEADER_BUILDER_H
#define THREAD_DATA_MANAGER_HEADER_BUILDER_H

#include "CFileOperations.h"
#include "IntToCharTranslater.h"
#include "Descriptor_File_Reader.h"

class Thread_Data_Manager_Header_Builder
{
public:
  Thread_Data_Manager_Header_Builder();
  Thread_Data_Manager_Header_Builder(const Thread_Data_Manager_Header_Builder & orig);
  virtual ~Thread_Data_Manager_Header_Builder();
  void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
  void Build_Thread_Data_Manager_Header_File();
private:
  CFileOperations FileManager;
  IntToCharTranslater Translater;
  Descriptor_File_Reader * Reader_Pointer;
};

#endif /* THREAD_DATA_MANAGER_HEADER_BUILDER_H */
