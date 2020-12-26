
#ifndef SERVER_BUILDER_H
#define SERVER_BUILDER_H

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"
#include "DirectoryOperations.h"
#include "Server_Header_File_Builder.h"
#include "Descriptor_File_Reader.h"
#include "Custom_System_Interface.h"

class Server_Builder
{
public:
 Server_Builder();
 Server_Builder(const Server_Builder & orig);
 virtual ~Server_Builder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Receive_Newly_Constructed_Include_Directory(char * New_Include_Directory);
 void Build_Server_Class();
 void Run_System_Commands();
 void Clear_Dynamic_Memory();
 char * Get_Compiler_Command();
 char * Get_Server_Class_Object_File_Name();
 char * Get_Server_Class_Source_File_Name();
 char * Get_Remove_Command_For_Source_File_Name();
private:
 void Place_String(char ** Pointer, char * String, int String_Size);
 void Place_String(char ** Pointer, const char * String, int String_Size);
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 void Determine_File_Names();
 void Determine_Compiler_Command_For_Server_Class();
 void Build_Output_Stream_File();
 void Clear_Pointer_Memory(char ** Pointer);
 void Write_Space(char * String);
 void Write_Space(const char * String);
 void Update_String_Length(char * String, int * index_counter);
 void Remove_Source_File();
 void Move_Header_File();
 void Write_Thread_Activation_Member_Function();
 void Write_Join_Member_Function();
 Server_Header_File_Builder Header_File_Builder;
 Descriptor_File_Reader * Reader_Pointer;
 Cpp_FileOperations FileManager;
 DirectoryOperations Directory_Manager;
 IntToCharTranslater Translater;
 Custom_System_Interface System_Interface;
 bool Memory_Delete_Condition;
 char *  New_Include_Directory;
 char *  Server_Class_Implementation_File_Name;
 char *  Server_Class_Object_File_Name;
 char *  Compiler_Command_For_Server_Class;
};

#endif /* SERVER_BUILDER_H */
