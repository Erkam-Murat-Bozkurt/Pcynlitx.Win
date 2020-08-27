
#ifndef DYNAMIC_MEMORY_MANAGER_BUILDER_H
#define DYNAMIC_MEMORY_MANAGER_BUILDER_H

#include "Dynamic_Memory_Manager_Header_Builder.h"
#include "ReportFileBuilder_Writer.h"
#include "Builder_Initializer.h"
#include "DirectoryOperations.h"
#include "CFileOperations.h"
#include <cstring>

class Dynamic_Memory_Manager_Builder
{
public:
 Dynamic_Memory_Manager_Builder();
 Dynamic_Memory_Manager_Builder(const Dynamic_Memory_Manager_Builder & orig);
 virtual ~Dynamic_Memory_Manager_Builder();
 void Receive_Data_Type(const char * DataType);
 void Receive_Data_Type(char * DataType);
 void Receive_Construction_Point(const char * Construction_Point);
 void Receive_Construction_Point(char * Construction_Point);
 void Receive_Entered_Class_Name(const char * Entered_Class_Name);
 void Receive_Entered_Class_Name(char * Entered_Class_Name);
 void Receive_Data_Type_Include_File_Name(const char * Include_File_Name);
 void Receive_Data_Type_Include_File_Name(char * Include_File_Name);
 void Set_Data_Type_Include_File_Name_Receive_Condition(bool Condition);
 void Receive_Namespace(char * name_space_info);
 void Build_Memory_Manager();
private:
 void Build_Class_Implementation_File();
 void Build_Constructors();
 void Build_Destructor();
 void Write_Space();
 void Build_NewMemory_Member_Functions();
 void Build_DeleteMemory_Member_Function();
 void Build_GetMemoryAdress_Member_Function();
 void Build_ReceiveReportFileManager_Member_Function();
 void Build_GetMemorySize_Member_Function();
 void Build_User_Number_Determiner_Member_Functions();
 bool Data_Type_Include_File_Name_Receive_Condition;
 CFileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Builder_Initializer Initializer;
 Builder_Initializer ReportFileBuilder_Initializer;
 Dynamic_Memory_Manager_Header_Builder Header_Builder;
 ReportFileBuilder_Writer Report_File_Builder_Writer;
 char * name_space_info;
};

#endif /* DYNAMIC_MEMORY_MANAGER_BUILDER_H */
