
#ifndef SERVER_HEADER_FILE_BUILDER_H
#define SERVER_HEADER_FILE_BUILDER_H

#include <cstring>
#include <ctype.h>
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"
#include "Descriptor_File_Reader.h"
#include "MemberFunctionReader.h"

class Server_Header_File_Builder
{
public:
 Server_Header_File_Builder();
 Server_Header_File_Builder(const Server_Header_File_Builder & orig);
 virtual ~Server_Header_File_Builder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Build_Server_Header_File();
 void Move_Header_File();
 void Clear_Dynamic_Memory();
private:
 void Determine_Inclusion_Word();
 void Place_Information(char ** Pointer,char * String,int * index_counter);
 char ConvertToUpper(char character);
 Cpp_FileOperations FileManager;
 IntToCharTranslater Translater;
 Descriptor_File_Reader * Reader_Pointer;
 MemberFunctionReader FunctionReader;
 bool Memory_Delete_Condition;
 char * InclusionWord;
 char * New_Include_Directory;
 char * Construction_Point;
 char * Move_Command;
 char   character;
};

#endif /* SERVER_HEADER_FILE_BUILDER_H */
