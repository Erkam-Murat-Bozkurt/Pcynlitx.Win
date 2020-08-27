
#ifndef THREAD_LOCKER_BUILDER_H
#define THREAD_LOCKER_BUILDER_H

#include "CFileOperations.h"
#include "DirectoryOperations.h"
#include "Thread_Locker_Header_File_Builder.h"
#include "Descriptor_File_Reader.h"
#include "Custom_System_Interface.h"
#include <cstring>
#include <cstdlib>

class Thread_Locker_Builder
{
public:
 Thread_Locker_Builder();
 Thread_Locker_Builder(const Thread_Locker_Builder & orig);
 virtual ~Thread_Locker_Builder();
 void Build_Thread_Locker();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Run_System_Commands();
 void Clear_Dynamic_Memory();
private:
 void Determine_Compiler_Command();
 void Remove_Header_Extra_File();
 void Place_Information(char ** Pointer, char * Information, int * Counter);
 Thread_Locker_Header_File_Builder HeaderFileBuilder;
 CFileOperations FileManager;
 Custom_System_Interface System_Interface;
 DirectoryOperations Directory_Manager;
 Descriptor_File_Reader * Reader_Pointer;
 bool   Memory_Delete_Condition;
 char * Construction_Point_Holder;
 char * Compiler_Command;
};

#endif /* THREAD_LOCKER_BUILDER_H */
