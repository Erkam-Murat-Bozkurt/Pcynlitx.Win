
 #include "Thread_Manager_Builder.h"
 #include "Descriptor_File_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("D:\\Project_Apps");

     File_Reader.Receive_Descriptor_File_Name("D:\\Project_Apps\\Project_Descriptor_File.txt");

     File_Reader.Receive_Descriptor_File_Infomations();

     Thread_Manager_Builder Builder;

     char Newly_Constructed_Directory []

          = "D:\\Project_Apps\\Thread_Server_Include_Directory";

     Builder.Receive_Constructed_Include_Directory(Newly_Constructed_Directory);

     Builder.Receive_Descriptor_File_Reader(&File_Reader);

     Builder.Build_Thread_Manager();

     Builder.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
