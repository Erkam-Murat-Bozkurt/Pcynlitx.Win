
 #include <iostream>
 #include <cstring>
 #include "Multi_Thread_Pointer_Compile_Data_Collector.h"
 #include "Multi_Thread_Pointer_Data_Collector.h"

 void Place_Information(char ** Pointer, const char * String, int String_Size){

      for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
      }

      (*Pointer)[String_Size] = '\0';
 }

 int main(int argc, char** argv){

     Multi_Thread_Pointer_Compile_Data_Collector Compiler_Data_Collector;

     Multi_Thread_Pointer_Data_Collector Data_Collector;

     const char * Data_Type_Name = "CFileOperations";

     int Data_Type_Name_Size = strlen(Data_Type_Name);

     char * Data_Type = new char [5*Data_Type_Name_Size];

     Place_Information(&Data_Type,Data_Type_Name,Data_Type_Name_Size);

     const char * Construction_Point_Name = "/home/erkam/Smart.Pointer.Builder/Multi_Thread_Pointer_File_Data_Collector";

     int Construction_Point_Name_Size = strlen(Construction_Point_Name);

     char * Construction_Point_Pointer = new char [5*Construction_Point_Name_Size];

     Place_Information(&Construction_Point_Pointer,Construction_Point_Name,Construction_Point_Name_Size);

     const char * New_Class_Name = "Sample";

     int New_Class_Name_Size = strlen(New_Class_Name);

     char * New_Class_Name_Pointer = new char [5*New_Class_Name_Size];

     Place_Information(&New_Class_Name_Pointer,New_Class_Name,New_Class_Name_Size);

     const char * Data_Type_Header_File_Name =  "CFileOperations.h";

     int Header_File_Name_Size = strlen(Data_Type_Header_File_Name);

     char * Header_File_Name_Pointer = new char [5*Header_File_Name_Size];

     Place_Information(&Header_File_Name_Pointer,Data_Type_Header_File_Name,Header_File_Name_Size);

     const char * Include_Directory = "/home/erkam/Smart.Pointer.Builder/Builder_Initializer";

     int Include_Directory_Size = strlen(Include_Directory);

     char * Include_Directory_Pointer = new char [5*Include_Directory_Size];

     Place_Information(&Include_Directory_Pointer,Include_Directory,Include_Directory_Size);

     Data_Collector.Receive_Data_Type(Data_Type);

     Data_Collector.Receive_Construction_Point(Construction_Point_Pointer);

     Data_Collector.Receive_Data_Type_Include_File_Name(Data_Type_Header_File_Name);

     Data_Collector.Set_Class_Name(New_Class_Name_Pointer);

     Data_Collector.Collect_Informations();

     Compiler_Data_Collector.Receive_Pointer_Initializer_Adress(&Data_Collector.Pointer_Initializer);

     Compiler_Data_Collector.Receive_Manager_Initializer_Adress(&Data_Collector.Manager_Initializer);

     Compiler_Data_Collector.Receive_Reporter_Initializer_Adress(&Data_Collector.Reporter_Initializer);

     Compiler_Data_Collector.Receive_Include_Directory(Include_Directory_Pointer);

     Compiler_Data_Collector.Collect_Informations();

     std::cout << "\n\n Pointer Compiler Command :" << Compiler_Data_Collector.Get_Compiler_Command_For_Pointer() << "\n\n";

     std::cout << "\n\n Memory Manager Compiler Command :" << Compiler_Data_Collector.Get_Compiler_Command_For_Memory_Manager_Builder()  << "\n\n";

     std::cout << "\n\n Report File Builder Compiler Command :" << Compiler_Data_Collector.Get_Compiler_Command_For_ReportFile_Builder() << "\n\n";

     Data_Collector.Clear_Dynamic_Memory();

     Compiler_Data_Collector.Clear_Dynamic_Memory();

     delete [] Data_Type;

     delete [] Construction_Point_Pointer;

     delete [] Header_File_Name_Pointer;

     delete [] New_Class_Name_Pointer;

     delete [] Include_Directory_Pointer;

     std::cout << "\n\n The end of the program .. \n\n";

     return 0;
 };
