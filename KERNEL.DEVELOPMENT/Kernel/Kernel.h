
#ifndef KERNEL_H
#define KERNEL_H

#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include "CFileOperations.h"
#include "ClassRebuilder.h"
#include "Inter_Thread_Data_Structure_Builder.h"
#include "Multi_Thread_Pointer_Builder.h"
#include "Multi_Thread_Pointer_Client_Builder.h"
#include "Descriptor_File_Reader.h"
#include "Server_Builder.h"
#include "Multi_Thread_Pointer_File_Data_Collector.h"
#include "Thread_Manager_Builder.h"
#include "TM_Client_Builder.h"
#include "Main_File_Builder.h"
#include "Kernel_Data_Collector.h"
#include "IntToCharTranslater.h"


class Kernel
{
public:
 Kernel();
 Kernel(const Kernel & orig);
 virtual ~Kernel();
 void Receive_Descriptor_File_Directory(const char * DescriptorFileDirectory);
 void Receive_Descriptor_File_Directory(char * DescriptorFileDirectory);
 void Receive_Descriptor_File_Name(const char * DescriptorFileName);
 void Receive_Descriptor_File_Name(char * DescriptorFileName);
 void Build_Server();
 void Clear_Dynamic_Memory();
private:
 void Construct_Smart_Pointers();
 void Construct_Thread_Manager_Class();
 void Construct_Thread_Manager_Class_Client();
 void Construct_Client_Clases();
 void Construct_Inter_Thread_Data_Structure();
 void Construct_Server_Class();
 void Construct_New_Library();
 void Construct_Main_File();
 void Construct_Compiler_Descriptor_File();
 void Remove_Compiler_Output_File();
 Descriptor_File_Reader Description_Reader;
 Inter_Thread_Data_Structure_Builder ITDS_Builder;
 Server_Builder Srv_Builder;
 Multi_Thread_Pointer_Builder Smart_Pointer_Builder;
 Multi_Thread_Pointer_File_Data_Collector File_Data_Collector;
 Multi_Thread_Pointer_Client_Builder Pointer_Client_Builder;
 Kernel_Data_Collector Factory_Data_Collector;
 ClassRebuilder ReBuilder;
 Thread_Manager_Builder Thread_Manager_Class_Builder;
 TM_Client_Builder Thread_Manager_Client_Builder_Pointer;
 Main_File_Builder Main_File_Builder_Object;
 IntToCharTranslater Translater;
 char * Compiler_Output_File_Path;
};

#endif /* KERNEL_H */
