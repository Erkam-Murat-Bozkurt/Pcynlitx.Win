
#ifndef THREAD_MANAGER_HEADER_FILE_BUILDER_H
#define THREAD_MANAGER_HEADER_FILE_BUILDER_H

#include "Thread_Data_Manager_Header_Builder.h"
#include "CFileOperations.h"
#include "IntToCharTranslater.h"
#include "Descriptor_File_Reader.h"

class Thread_Manager_Header_File_Builder
{
public:
 Thread_Manager_Header_File_Builder();
 Thread_Manager_Header_File_Builder(const Thread_Manager_Header_File_Builder & orig);
 virtual ~Thread_Manager_Header_File_Builder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Build_Thread_Manager_Header_File();
private:
 Thread_Data_Manager_Header_Builder Data_Manager_Header_Builder;
 CFileOperations FileManager;
 IntToCharTranslater Translater;
 Descriptor_File_Reader * Reader_Pointer;
};

#endif /* THREAD_MANAGER_HEADER_FILE_BUILDER_H */
