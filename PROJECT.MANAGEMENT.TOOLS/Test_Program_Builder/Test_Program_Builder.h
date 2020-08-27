
#ifndef TEST_PROGRAM_BUILDER_H
#define TEST_PROGRAM_BUILDER_H

#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>

class Test_Program_Builder
{
public:
 Test_Program_Builder();
 Test_Program_Builder(const Test_Program_Builder & orig);
 virtual ~Test_Program_Builder();
 void Build_Test_Program(const char * Header_Files_Directory, const char * Object_Files_Directory, const char * Library_Directory, const char * Library_Name);
 void Clear_Dynamic_Memory();
private:
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 void Place_Information(char ** Pointer, const char * Information, int * index_counter);
 void Find_Class_Name();
 void Determine_Compiler_System_Command(const char * Header_Files_Directory, const char * Object_Files_Directory, const char * Library_Directory, const char * Library_Name);
 void Determine_Included_Header_Files_Number();
 void Read_Include_File_Names();
 void Determine_Object_File_Names();
 bool Include_Line_Determiner(std::string String_Line);
 std::fstream DataFile;
 std::string String_Line;
 char * Class_Name;
 char * Class_Object_File_Name;
 char * Class_Header_File_Name;
 char * Compiler_System_Command;
 char * Executable_File_Name;
 char * Main_File_Name;
 char ** Included_Header_Files;
 char ** Included_Object_Files;
 int  Included_Header_Files_Number;
 bool Include_Line_Condition;
 bool Memory_Delete_Condition;
};

#endif /* TEST_PROGRAM_BUILDER_H */
