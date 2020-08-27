
 #include "Process_Supervisor_Descriptor_File_Reader.h"
 #include "Multi_Thread_Pointer_File_Data_Collector.h"
 #include <iostream>
 #include <cstring>


 int main(int argc, char** argv){

     Process_Supervisor_Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Reader.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Reader.Receive_Descriptor_File_Infomations();

     Multi_Thread_Pointer_File_Data_Collector File_Data_Collector;

     int Data_Type_Number = 1;

     File_Data_Collector.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

     File_Data_Collector.Receive_Data_Type_Number(Data_Type_Number);

     char Include_Directory [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/Sample_Supervisor_Include_Directory";

     File_Data_Collector.Receive_Newly_Constructed_Include_Directory(Include_Directory);

     File_Data_Collector.Build_File_List();

     std::cout << "\n Header File Name List :" << File_Data_Collector.Get_Header_File_Name_List() << "#";

     std::cout << "\n Source File Name List :" << File_Data_Collector.Get_Source_File_Name_List() << "#";

     std::cout << "\n Header_File_Name_Matrix:";

     for(int i=0;i<3;i++){

         std::cout << "\n                         :" << File_Data_Collector.Get_Header_File_Name_Matrix()[i];
     }

     std::cout << "\n Implementation_File_Name_Matrix:";

     for(int i=0;i<3;i++){

         std::cout << "\n                         :" << File_Data_Collector.Get_Implementation_File_Name_Matrix()[i];
     }

     std::cout << "\n\n Compiler_Command_For_ReportFileBuilder:" << File_Data_Collector.Get_Compiler_Command_For_ReportFileBuilder() << "#";

     std::cout << "\n\n Compiler_Command_For_Memory_Manager:" << File_Data_Collector.Get_Compiler_Command_For_MemoryManager() << "#";

     std::cout << "\n\n Compiler_Command_For_Smart_Pointer:" << File_Data_Collector.Get_Compiler_Command_For_SmartPointer() << "#";

     std::cout << "\n\n Object_File_List:" << File_Data_Collector.Get_Object_File_List();

     std::cout << "\n\n New_Class_Name:" << File_Data_Collector.Get_New_Class_Name() << "#";

     //std::cout << "\n\n Move command for header file list:" << File_Data_Collector.Get_Move_Command_For_File_List();

     std::cout << "\n\n Header file paths in new include directory:";

     for(int i=0;i<3;i++){

         std::cout << "\n\n" << File_Data_Collector.Get_Header_File_Paths_In_New_Include_Directory()[i] << "#";
     }

     File_Data_Collector.Clear_Dynamic_Memory();

     File_Reader.Clear_Dynamic_Memory();

     std::cout << "\n\n  The end of the program ..\n\n";

     return 0;
 };
