
#ifndef MULTI_THREAD_POINTER_FILE_DATA_COLLECTOR_H
#define MULTI_THREAD_POINTER_FILE_DATA_COLLECTOR_H

#include "Builder_Initializer.h"
#include "Descriptor_File_Reader.h"
#include "DirectoryOperations.h"
#include "Multi_Thread_Pointer_Data_Collector.h"
#include "Multi_Thread_Pointer_Compile_Data_Collector.h"
#include "Multi_Thread_Pointer_File_Cleaner.h"
#include "Custom_System_Interface.h"
#include "Cpp_FileOperations.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>

class Multi_Thread_Pointer_File_Data_Collector
{
public:
 Multi_Thread_Pointer_File_Data_Collector();
 Multi_Thread_Pointer_File_Data_Collector(const Multi_Thread_Pointer_File_Data_Collector & orig);
 virtual ~Multi_Thread_Pointer_File_Data_Collector();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * File_Reader);
 void Receive_Newly_Constructed_Include_Directory(char * New_Include_Directory);
 void Receive_Data_Type_Number(int Number);
 void Build_File_List();
 void Clear_Dynamic_Memory();
 void Run_System_Commands();
 char *  Get_Source_File_Name_List();
 char *  Get_Header_File_Name_List();
 char *  Get_Compiler_Command_For_ReportFileBuilder();
 char *  Get_Compiler_Command_For_MemoryManager();
 char *  Get_Compiler_Command_For_SmartPointer();
 char *  Get_Remove_Command_For_Source_Files();
 char *  Get_Remove_Command_For_Header_File_Extras();
 char *  Get_Move_Command_For_File_List();
 char *  Get_Object_File_List();
 char *  Get_New_Class_Name();
 char *  Get_Data_Type_Include_Directory();
 char ** Get_Header_File_Name_Matrix();
 char ** Get_Implementation_File_Name_Matrix();
 char ** Get_Header_File_Paths_In_New_Include_Directory();
private:
 void Clear_Pointer_Memory(char ** Pointer);
 void Place_String(char ** Pointer, char * String);
 void Place_Information(char ** Pointer,char * Information, int * index_counter);
 void Determine_New_Pointer_Class_Name();
 void Build_Output_Stream_File();
 void Move_Header_Files();
 void Determine_Data_Type_Informations();
 void Determine_Shared_Data_Type_Instance_Name(char * Data_Type);
 void Determine_Header_File_Paths_In_New_Include_Directory();
 Multi_Thread_Pointer_Data_Collector Data_Collector;
 Multi_Thread_Pointer_Compile_Data_Collector Compile_Data_Collector;
 Multi_Thread_Pointer_File_Cleaner File_Cleaner;
 Cpp_FileOperations File_Manager;
 DirectoryOperations DirectoryManager;
 Custom_System_Interface System_Interface;
 Descriptor_File_Reader * Reader_Pointer;
 int    Data_Type_Number;
 bool   Memory_Delete_Condition;
 char * Include_Directory;
 char * New_Class_Name;
 char * New_Include_Directory;
 char * Move_Command_For_File_List;
 char * Shared_Data_Type_Instance_Name;
 char ** Header_File_Paths_In_New_Include_Directory;
};

#endif /* MULTI_THREAD_POINTER_FILE_DATA_COLLECTOR_H */
