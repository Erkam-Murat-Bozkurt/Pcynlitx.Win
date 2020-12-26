
#ifndef MULTI_THREAD_POINTER_CLIENT_BUILDER_H
#define MULTI_THREAD_POINTER_CLIENT_BUILDER_H

#include "Multi_Thread_Pointer_Client_Header_Builder.h"
#include "Descriptor_File_Reader.h"
#include "Cpp_FileOperations.h"
#include "DirectoryOperations.h"
#include <cstring>
#include <cstdlib>

class Multi_Thread_Pointer_Client_Builder
{
public:
 Multi_Thread_Pointer_Client_Builder();
 Multi_Thread_Pointer_Client_Builder(const Multi_Thread_Pointer_Client_Builder & orig);
 virtual ~Multi_Thread_Pointer_Client_Builder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Receive_Base_Class_Name(char * Base_Class_Name);
 void Receive_Smart_Pointer_Instance_Name(char * Smart_Pointer_Instance_Name);
 void Receive_Data_Type_Include_Directory(char * Data_Type_Include_Directory);
 void Determine_Include_Options_Size();
 void Receive_Data_Type(char * DataType);
 void Build_Pointer_Client();
 void Run_System_Commands();
 void Clear_Dynamic_Memory();
private:
 void Build_Output_Stream_File();
 void Build_Class_Implementation_File();
 void Determine_Base_Class_Header_File_Name();
 void Determine_Client_Class_Implementation_File_Name();
 void Determine_Compiler_Command();
 void Remove_Class_Implementation_File();
 void Remove_Header_Extra();
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 void Clear_Pointer_Memory(char ** Pointer);
 bool Memory_Delete_Condition;
 int  include_options_size;
 Multi_Thread_Pointer_Client_Header_Builder P_Header_Builder;
 Cpp_FileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Descriptor_File_Reader * Reader_Pointer;
 char * Construction_Point;
 char * Base_Class_Name;
 char * Base_Class_Header_File_Name;
 char * Data_Type;
 char * Newly_Constructed_Include_Directory;
 char * Compiler_Command;
 char * name_space_info;
 char * Client_Class_Implementation_File_Name;
 char * Client_Class_Object_File_Name;
 char * Client_Class_Header_File_Name;
 char * Smart_Pointer_Instance_Name;
 char * Client_Class_Name;
 char * Data_Type_Include_Directory;
};

#endif /* MULTI_THREAD_POINTER_BUILDER_H */
