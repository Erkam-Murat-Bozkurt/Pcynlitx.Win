
#ifndef COMPILER_H
#define COMPILER_H

#include <cstring>
#include <cstdlib>
#include "Compiler_Descriptor_File_Reader.h"

class Compiler
{
public:
 Compiler();
 Compiler(const Compiler & orig);
 virtual ~Compiler();
 void Receive_Descriptor_File_Directory(const char * DescriptorFileDirectory);
 void Receive_Descriptor_File_Directory(char * DescriptorFileDirectory);
 void Receive_Descriptor_File_Name(const char * DescriptorFileName);
 void Receive_Descriptor_File_Name(char * DescriptorFileName);
 void Receive_Descriptor_File_Infomations();
 void Build_Project();
 void Clear_Dynamic_Memory();
 char * Get_Compiler_Command();
private:
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 void Clear_Pointer_Memory(char ** Pointer);
 void Collect_Compiler_Process_Informations();
 void Determine_Include_Directory_Decleration_Command();
 void Determine_Library_Directory_Decleration_Command();
 void Determine_Source_Files_Directories_Decleration_Command();
 void Determine_Source_File_Names_Decleration_Command();
 void Determine_Header_Files_Decleration_Command();
 void Determine_Libraries_Decleration_Command();
 void Determine_Option_List_Decleration_Command();
 void Determine_Final_Command();
 void Export_Path_Information(char * Directory);
 Compiler_Descriptor_File_Reader Descriptor_File_Reader;
 bool    Memory_Delete_Condition;
 char *  Include_Directory_Decleration_Command;
 char *  Library_Directory_Decleration_Command;
 char *  Source_Files_Directories_Decleration_Command;
 char *  Source_File_Names_Decleration_Command;
 char *  Header_Files_Decleration_Command;
 char *  Libraries_Decleration_Command;
 char *  Option_List_Decleration_Command;
 char *  Final_Commad;
};

#endif /* COMPILER_H */
