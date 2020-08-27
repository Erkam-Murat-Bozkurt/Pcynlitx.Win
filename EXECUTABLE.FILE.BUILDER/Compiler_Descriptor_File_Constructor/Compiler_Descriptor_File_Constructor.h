
/*

This program constructs a descriptor file using by the executable file builder program
The executable file builder program produces an executable binary code for
the applications developed with the help of pcynlitx platform.

The executable file builder builds the executable file using the main file of the
application developed and the library that is constructed by the pcynlitx platform.

*/

#ifndef COMPILER_DESCRIPTOR_FILE_CONSTRUCTOR_H
#define COMPILER_DESCRIPTOR_FILE_CONSTRUCTOR_H

#include <cstring>
#include "CFileOperations.h"
#include "Descriptor_File_Reader.h"

class Compiler_Descriptor_File_Constructor
{
public:
 Compiler_Descriptor_File_Constructor();
 Compiler_Descriptor_File_Constructor(const Compiler_Descriptor_File_Constructor & orig);
 virtual ~Compiler_Descriptor_File_Constructor();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Build_Compiler_Descriptor_File();
 void Clear_Dynamic_Memory();
private:
 void Clear_Pointer_Memory(char ** Pointer);
 void Determine_New_Include_Directory_Name();
 void Place_String(char ** Pointer, char * String, int String_Size);
 void Place_Information(char ** Pointer, const char * Information, int * index_counter);
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 void Write_String_List_To_File(char ** String_List, int List_Size);
 void Collect_Informations();
 void Reserve_Memory_For_Include_Directories(int Number);
 void Reserve_Memory_For_Library_Directories(int Number);
 void Reserve_Memory_For_Source_File_Directories(int Number);
 void Reserve_Memory_For_Source_File_Names(int Number);
 void Reserve_Memory_For_Header_File_Names(int Number);
 void Reserve_Memory_For_Library_Names(int Number);
 void Receive_Include_Directory(char * IncludeDirectory);
 void Receive_Library_Directory(char * LibraryDirectory);
 void Receive_Source_File_Directory(char * SourceFileDirectory);
 void Receive_Source_File_Name(char * SourceFileName);
 void Receive_Header_File_Name(char * HeaderFileName);
 void Receive_Library_Name(char * LibraryName);
 void Receive_Main_File_Name(char * File_Name);
 void Determine_Server_Class_Header_File_Path();
 char * Get_Client_Class_Header_File_Name(char * Class_Name);
 char * Get_Shared_Data_Type_Pointer_Header_File_Name(char * Data_Type, const char * Type_Subfix);
 char * Get_File_Path_For_Base_Class_Header_File(int Index_Number);
 char * Get_File_Path_For_Shared_Data_Type_Header_File(int Index_Number);
 char * Get_Header_File_Paths_In_New_Include_Directory(char * Header_File_Name);
 CFileOperations FileManager;
 Descriptor_File_Reader * Reader_Pointer;
 int Include_Directory_Counter;
 int Library_Directory_Counter;
 int Source_File_Directory_Counter;
 int Source_File_Name_Counter;
 int Header_File_Name_Counter;
 int Library_Name_Counter;
 int Header_File_Location_Counter;
 int Source_File_Location_Counter;
 int Include_Directory_Number;
 int Library_Directory_Number;
 int Source_File_Directory_Number;
 int Source_File_Number;
 int Header_File_Number;
 int Library_Name_Number;
 char *  Server_Class_Header_File_Name;
 char  * Header_File_Path_In_New_Include_Directory;
 char  * Shared_Data_Type_Pointer_Class_Name;
 char  * Base_Class_Header_File_Path;
 char  * Shared_Data_Type_Header_File_Path;
 char  * New_Include_Directory_Name;
 char  * Client_Class_Name;
 char  * Shared_Data_Type_Pointer_Header_File_Name;
 char ** Include_Directories;
 char ** Library_Directories;
 char ** Source_File_Directories;
 char ** Source_File_Names;
 char ** Header_File_Names;
 char ** Library_Names;
 bool    Memory_Delete_Condition;
};

#endif /* COMPILER_DESCRIPTOR_FILE_CONSTRUCTOR_H */
