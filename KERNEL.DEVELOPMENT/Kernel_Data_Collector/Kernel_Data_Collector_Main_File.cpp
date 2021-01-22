

 #include "Kernel_Data_Collector.h"
 #include "Descriptor_File_Reader.h"
 #include <cstring>
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("D:\\TestDirectory");

     File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File.txt");

     File_Reader.Receive_Descriptor_File_Infomations();

     Kernel_Data_Collector Data_Collector;

     Data_Collector.Receive_Descriptor_File_Reader(&File_Reader);

     Data_Collector.Jump_To_Construction_Point();

     Data_Collector.Construct_New_Include_Directory();

     Data_Collector.Determine_Object_File_List();

     Data_Collector.Construct_New_Library();

     Data_Collector.Remove_Object_Files();

     Data_Collector.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
