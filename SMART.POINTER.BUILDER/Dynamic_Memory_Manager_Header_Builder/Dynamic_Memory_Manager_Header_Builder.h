
#ifndef DYNAMIC_MEMORY_MANAGER_HEADER_BUILDER_H
#define DYNAMIC_MEMORY_MANAGER_HEADER_BUILDER_H

#include "DirectoryOperations.h"
#include "Builder_Initializer.h"
#include "Cpp_FileOperations.h"
#include <cstring>
#include <ctype.h>

class Dynamic_Memory_Manager_Header_Builder
{
public:
 Dynamic_Memory_Manager_Header_Builder();
 Dynamic_Memory_Manager_Header_Builder(const Dynamic_Memory_Manager_Header_Builder & orig);
 virtual ~Dynamic_Memory_Manager_Header_Builder();
 void Receive_Data_Type(const char * DataType);
 void Receive_Data_Type(char * DataType);
 void Receive_Entered_Class_Name(const char * Entered_Class_Name);
 void Receive_Entered_Class_Name(char * Entered_Class_Name);
 void Receive_Construction_Point(const char * Construction_Point);
 void Receive_Construction_Point(char * Construction_Point);
 void Receive_Data_Type_Include_File_Name(const char * Include_File_Name);
 void Receive_Data_Type_Include_File_Name(char * Include_File_Name);
 void Set_Data_Type_Include_File_Name_Receive_Condition(bool Condition);
 void Receive_Namespace(char * name_space_info);
 void Build_Header_File();
private:
 void Write_Header_File();
 void Determine_Inclusion_Word();
 char ConvertToUpper(char character);
 Cpp_FileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Builder_Initializer Initializer;
 Builder_Initializer ReportFileBuilder_Initializer;
 bool   Pointer_Name_Receive_Condition;
 bool   Data_Type_Include_File_Name_Receive_Condition;
 char * InclusionWord;
 char   character;
 char * Menager_Class_Name;
 char * ReportFileBuilder_Class_Name;
 char * name_space_info;
};

#endif /* DYNAMIC_MEMORY_MANAGER_HEADER_BUILDER_H */
