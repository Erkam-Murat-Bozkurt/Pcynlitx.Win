

 #include "ClassRebuilder_Initializer.h"
 #include "ClassRebuilder_Data_Collector.h"
 #include "DirectoryOperations.h"
 #include "Descriptor_File_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Reader File_Reader;

     DirectoryOperations DirectoryManager;

     File_Reader.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Reader.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Reader.Receive_Descriptor_File_Infomations();

     ClassRebuilder_Initializer Initializer;

     Initializer.Receive_Descriptor_File_Reader(&File_Reader);

     int Class_Number = 1;

     Initializer.Receive_Class_Number(Class_Number);

     Initializer.Determine_Informations();

     char Newly_Constructed_Directory [ ] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/ClassRebuilder";

     ClassRebuilder_Data_Collector Data_Collector;

     Data_Collector.Receive_Descriptor_File_Reader(&File_Reader);

     Data_Collector.Receive_Supervisor_Newly_Constructed_Include_Directory(Newly_Constructed_Directory);

     Data_Collector.Receive_ClassRebuilder_Initializer(&Initializer);

     Data_Collector.Reiceve_Directory_Manager(&DirectoryManager);

     Data_Collector.Collect_System_Command_Informations();

     Data_Collector.Print_System_Commands();

     Initializer.Clear_Dynamic_Memory();

     File_Reader.Clear_Dynamic_Memory();

     Data_Collector.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
