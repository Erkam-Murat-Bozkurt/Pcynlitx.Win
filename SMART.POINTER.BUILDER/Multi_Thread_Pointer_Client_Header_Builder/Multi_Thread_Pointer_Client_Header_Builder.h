
#ifndef MULTI_THREAD_POINTER_CLIENT_HEADER_BUILDER_H
#define MULTI_THREAD_POINTER_CLIENT_HEADER_BUILDER_H

#include "Builder_Initializer.h"
#include "DirectoryOperations.h"
#include "Descriptor_File_Reader.h"
#include "CFileOperations.h"
#include <cstring>
#include <ctype.h>

class Multi_Thread_Pointer_Client_Header_Builder
{
public:
 Multi_Thread_Pointer_Client_Header_Builder();
 Multi_Thread_Pointer_Client_Header_Builder(const Multi_Thread_Pointer_Client_Header_Builder & orig);
 virtual ~Multi_Thread_Pointer_Client_Header_Builder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Receive_Base_Class_Header_File_Name(char * Base_Class_Header_File_Name);
 void Receive_Base_Class_Name(char * Base_Class_Name);
 void Receive_Data_Type(char * DataType);
 void Clear_Dynamic_Memory();
 char * Get_Client_Class_Name();
 char * Get_Client_Class_Header_File_Name();
 void Build_Header_File();
private:
 void Write_Header_File();
 void Determine_Inclusion_Word();
 void Determine_Client_Header_File_Name();
 char ConvertToUpper(char character);
 void Clear_Pointer_Memory(char ** Pointer);
 CFileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Descriptor_File_Reader * Reader_Pointer;
 bool   Memory_Delete_Condition;
 char * InclusionWord;
 char   character;
 char * Data_Type;
 char * Construction_Point;
 char * name_space_info;
 char * Base_Class_Header_File_Name;
 char * Base_Class_Name;
 char * Client_Class_Name;
 char * Client_Class_Header_File_Name;
};

#endif /* MULTI_THREAD_POINTER_CLIENT_HEADER_BUILDER_H */
