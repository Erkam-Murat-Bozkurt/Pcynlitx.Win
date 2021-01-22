
 #include "Thread_Manager_Header_File_Builder.h"
 #include "Process_Supervisor_Descriptor_File_Reader.h"
 #include <iostream>


 int main(int argc, char** argv){

     Process_Supervisor_Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("D:\\TestDirectory");

     File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File.txt");

     File_Reader.Receive_Descriptor_File_Infomations();

     Thread_Manager_Header_File_Builder HeaderFileBuilder;

     HeaderFileBuilder.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

     HeaderFileBuilder.Build_ThreadSynchronization_Header_File();

     std::cout << "\n\n The and of the program ..\n\n";

     return 0;
 };
