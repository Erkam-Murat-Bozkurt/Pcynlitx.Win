
 #include "ClassRebuilder.h"
 #include "Descriptor_File_Reader.h"
 #include <cstring>
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("/home/erkam/ThreadStack_Apps");

     File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

     File_Reader.Receive_Descriptor_File_Infomations();

     ClassRebuilder Rebuilder;

     char Newly_Constructed_Directory [] = "/home/erkam/ThreadStack_Apps/Thread_Server_Include_Directory";

     int Class_Number = 2;

     int Data_Type_Number = 2;

     bool Class_Data_Type_Receive_Condition = false;

     bool Shared_Data_Type_Receive_Condition = true;

     if(Class_Data_Type_Receive_Condition){

        Rebuilder.Receive_Class_Number(Class_Number);
     }

     if(Shared_Data_Type_Receive_Condition){

        Rebuilder.Receive_Data_Type_Number(Data_Type_Number);
     }

     Rebuilder.Receive_Process_Descriptor_File_Reader(&File_Reader);

     Rebuilder.Re_Construct_Class();

     std::cout << "\n New_Class_Name:" << Rebuilder.Get_New_Class_Name() << "#";

     std::cout << "\n Object_File_Name:" << Rebuilder.Get_Object_File_Name() << "#";

     Rebuilder.Print_System_Commands();

     Rebuilder.Run_System_Commands();

     Rebuilder.Clear_Dynamic_Memory();

     File_Reader.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
