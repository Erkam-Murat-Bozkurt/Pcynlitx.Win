
#ifndef MULTI_THREAD_POINTER_HEADER_BUILDER_H
#define MULTI_THREAD_POINTER_HEADER_BUILDER_H

#include "Builder_Initializer.h"
#include "DirectoryOperations.h"
#include "Descriptor_File_Reader.h"
#include "CFileOperations.h"
#include <cstring>
#include <ctype.h>

class Multi_Thread_Pointer_Header_Builder
{
public:
 Multi_Thread_Pointer_Header_Builder();
 Multi_Thread_Pointer_Header_Builder(const Multi_Thread_Pointer_Header_Builder & orig);
 virtual ~Multi_Thread_Pointer_Header_Builder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Receive_Data_Type(const char * DataType);
 void Receive_Data_Type(char * DataType);
 void Receive_Entered_Class_Name(const char * Entered_Class_Name);
 void Receive_Entered_Class_Name(char * Entered_Class_Name);
 void Receive_Construction_Point(const char * Construction_Point);
 void Receive_Construction_Point(char * Construction_Point);
 void Receive_Data_Type_Include_File_Name(const char * Include_File_Name);
 void Receive_Data_Type_Include_File_Name(char * Include_File_Name);
 void Set_New_Class_Name_Directly(const char * Class_Name);
 void Set_New_Class_Name_Directly(char * Class_Name);
 void Set_Data_Type_Include_File_Name_Receive_Condition(bool Condition);
 void Build_Header_File();
private:
 void Write_Header_File();
 void Determine_Inclusion_Word();
 char ConvertToUpper(char character);
 CFileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Builder_Initializer Initializer;
 Builder_Initializer Manager_Initializer;
 Builder_Initializer ReportFileBuilder_Initializer;
 Descriptor_File_Reader * Reader_Pointer;
 bool   Memory_Delete_Condition;
 bool   Pointer_Name_Receive_Condition;
 bool   Data_Type_Include_File_Name_Receive_Condition;
 char * Menager_Class_Name;
 char * ReportFileBuilder_Class_Name;
 char * InclusionWord;
 char   character;
 char * ClassName;
};

#endif /* MULTI_THREAD_POINTER_HEADER_BUILDER_H */
