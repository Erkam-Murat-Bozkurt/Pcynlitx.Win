
#ifndef MULTI_THREAD_POINTER_BUILDER_H
#define MULTI_THREAD_POINTER_BUILDER_H

#include "Multi_Thread_Pointer_Header_Builder.h"
#include "Multi_Thread_Pointer_File_Data_Collector.h"
#include "Dynamic_Memory_Manager_Builder.h"
#include "Builder_Initializer.h"
#include "Descriptor_File_Reader.h"
#include "CFileOperations.h"
#include "DirectoryOperations.h"
#include "MemberFunctionReader.h"
#include <cstring>
#include <cstdlib>

class Multi_Thread_Pointer_Builder
{
public:
 Multi_Thread_Pointer_Builder();
 Multi_Thread_Pointer_Builder(const Multi_Thread_Pointer_Builder & orig);
 virtual ~Multi_Thread_Pointer_Builder();
 void Receive_Newly_Constructed_Include_Directory(char * New_Include_Directory);
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Receive_Data_Type_Number(int Number);
 void Build_Pointer();
 void Run_System_Commands();
 char * Get_DataType();
 char * Get_DataType_Include_File_Name();
 char * Get_New_Class_Name();
 char * Get_Object_File_List();
 char * Get_Header_File_Name_List();
 char * Get_Shared_Data_Type_Instance_Name();
 char * Get_Data_Type_Include_Directory();
 char ** Get_Header_File_Paths_In_New_Include_Directory();
 void Clear_Dynamic_Memory();
private:
 void Receive_Data_Type(char * DataType);
 void Receive_Construction_Point(char * Construction_Point);
 void Receive_Data_Type_Include_File_Name(char * Include_File_Name);
 void Set_Data_Type_Include_File_Name_Receive_Condition(bool Condition);
 void Set_Class_Name(char * Class_Name);
 void Build_Class_Implementation_File();
 void Start_Implementation_File_Construction();
 void Build_Constructors();
 void Build_Destructor();
 void Write_Space(const char * String, int Line_Number);
 void Build_NewMemory_Member_Functions();
 void Build_DeleteMemory_Member_Function();
 void Build_ReceiveIndexBound_Member_Function();
 void Build_Overload_Operators_Member_Functions();
 void Build_SetFilePath_Member_Functions();
 void Build_Jump_To_Start_Member_Function();
 void Build_Jump_To_End_Member_Function();
 void Build_Thread_User_Member_Functions();
 void Determine_Data_Type_Informations();
 void Determine_Shared_Data_Type_Instance_Name(char * Data_Type_Name);
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 bool Data_Type_Include_File_Name_Receive_Condition;
 bool Memory_Delete_Condition;
 int  Data_Type_Number;
 char * Shared_Data_Type_Instance_Name;
 MemberFunctionReader * FunctionReader;
 Multi_Thread_Pointer_Header_Builder P_Header_Builder;
 Dynamic_Memory_Manager_Builder M_Manager_Builder;
 Multi_Thread_Pointer_File_Data_Collector Data_Collector;
 CFileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Builder_Initializer Initializer;
 Descriptor_File_Reader * Reader_Pointer;
};

#endif /* MULTI_THREAD_POINTER_BUILDER_H */
