
#ifndef INTER_THREAD_DATA_STRUCTURE_BUILDER_H
#define INTER_THREAD_DATA_STRUCTURE_BUILDER_H

#include "CFileOperations.h"
#include "Descriptor_File_Reader.h"

class Inter_Thread_Data_Structure_Builder
{
public:
 Inter_Thread_Data_Structure_Builder();
 Inter_Thread_Data_Structure_Builder(const Inter_Thread_Data_Structure_Builder & orig);
 virtual ~Inter_Thread_Data_Structure_Builder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Reader_Pointer);
 void Build_Inter_Thread_Data_Structure();
 void Move_Header_File();
 void Clear_Dynamic_Memory();
private:
 void Determine_Header_File_Path(char * Header_File_Location, char * Header_File_Name);
 void Place_Information(char ** Pointer,char * String,int * index_counter);
 MemberFunctionReader FunctionReader;
 CFileOperations File_Manager;
 Descriptor_File_Reader * Reader_Pointer;
 bool Memory_Delete_Condition;
 char * Header_File_Path;
 char * New_Include_Directory;
 char * Construction_Point;
 char * Move_Command;
};

#endif /* INTER_THREAD_DATA_STRUCTURE_BUILDER_H */
