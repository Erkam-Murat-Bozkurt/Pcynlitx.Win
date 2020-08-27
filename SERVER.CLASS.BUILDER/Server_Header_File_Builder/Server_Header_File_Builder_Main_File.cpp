
 #include "Descriptor_File_Reader.h"
 #include "Server_Header_File_Builder.h"
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Reader Des_File_Reader;

     Des_File_Reader.Receive_Descriptor_File_Directory("/home/erkam/Project_Apps");

     Des_File_Reader.Receive_Descriptor_File_Name("/home/erkam/Project_Apps/Project_Descriptor_File");

     Des_File_Reader.Receive_Descriptor_File_Infomations();;

     Server_Header_File_Builder File_Builder;

     File_Builder.Receive_Process_Descriptor_File_Reader(&Des_File_Reader);

     File_Builder.Build_Supervisor_Header_File();

     File_Builder.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
