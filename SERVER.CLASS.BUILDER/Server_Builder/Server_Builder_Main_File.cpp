
 #include "Descriptor_File_Reader.h"
 #include "Server_Builder.h"
 #include <iostream>
 #include <cstring>

 int main(int argc, char** argv){

     Descriptor_File_Reader Des_File_Reader;

     Des_File_Reader.Receive_Descriptor_File_Directory("/home/erkam/Project_Apps");

     Des_File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

     Des_File_Reader.Receive_Descriptor_File_Infomations();;

     Server_Builder File_Builder;

     File_Builder.Receive_Process_Descriptor_File_Reader(&Des_File_Reader);

     char New_Include_Directory [ ] = "/home/erkam/Project_Apps/Thread_Server_Include_Directory";

     File_Builder.Receive_Newly_Constructed_Include_Directory(New_Include_Directory);

     File_Builder.Build_Supervisor_Class();

     //File_Builder.Run_System_Commands();

     std::cout << "\n\n Compiler Command :" << File_Builder.Get_Compiler_Command() << "#";

     std::cout << "\n\n Server Class Object File Name:" << File_Builder.Get_Supervisor_Class_Object_File_Name() << "#";

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
