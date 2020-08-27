
#ifndef MULTI_THREAD_POINTER_COMPILE_DATA_COLLECTOR_H
#define MULTI_THREAD_POINTER_COMPILE_DATA_COLLECTOR_H

#include "Descriptor_File_Reader.h"
#include "Builder_Initializer.h"
#include "DirectoryOperations.h"
#include <cstring>

class Multi_Thread_Pointer_Compile_Data_Collector
{
public:
 Multi_Thread_Pointer_Compile_Data_Collector();
 Multi_Thread_Pointer_Compile_Data_Collector(const Multi_Thread_Pointer_Compile_Data_Collector & orig);
 virtual ~Multi_Thread_Pointer_Compile_Data_Collector();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Reader);
 void Receive_Pointer_Initializer_Adress(Builder_Initializer * Pointer);
 void Receive_Manager_Initializer_Adress(Builder_Initializer * Pointer);
 void Receive_Reporter_Initializer_Adress(Builder_Initializer * Pointer);
 void Receive_Include_Directory(char * Include_Directory);
 void Receive_Construction_Point(char * Contruction_Point);
 void Collect_Informations();
 void Clear_Dynamic_Memory();
 char * Get_Compiler_Command_For_ReportFile_Builder();
 char * Get_Compiler_Command_For_Memory_Manager_Builder();
 char * Get_Compiler_Command_For_Pointer();
private:
 void Determine_Command_Informations();
 void Determine_Compiler_Command_For_Report_File_Builder();
 void Determine_Compiler_Command_For_Memory_Manager();
 void Determine_Compiler_Command_For_Smart_Pointer();
 void Determine_Include_Options_Size();
 void Clear_Pointer_Memory(char ** Pointer);
 void Place_Information(char ** Pointer, char * Information, int * counter);
 void Place_String(char ** Pointer, char * String, int String_Size);
 void Add_Space(char ** Pointer,int * counter);
 Builder_Initializer * Pointer_Initializer;
 Builder_Initializer * Manager_Initializer;
 Builder_Initializer * Reporter_Initializer;
 DirectoryOperations Directory_Manager;
 Descriptor_File_Reader * Reader_Pointer;
 int    include_options_size;
 bool   Memory_Delete_Condition;
 char * Construction_Point_Holder;
 char * Compile_Command;
 char * Include_Linker;
 char * Include_Directory;
 char * Compiler_Command_For_ReportFileBuilder;
 char * Compiler_Command_For_Memory_Manager;
 char * Compiler_Command_For_Pointer;
};

#endif /* MULTI_THREAD_POINTER_COMPILE_DATA_COLLECTOR_H */
