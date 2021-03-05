
 #include "Descriptor_File_Data_Collector.h"
 #include <iostream>

 void Print_Record_Area(int array []){

      std::cout << "\n    Start_Point:" << array[0];

      std::cout << "\n    End_Point:" << array[1];
 }

 int main(int argc, char** argv){

     Descriptor_File_Data_Collector File_Data_Collector;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/OpenMP_Support_Test");

     File_Data_Collector.Receive_Descriptor_File_Name("/home/erkam/OpenMP_Support_Test/Project_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     std::cout << "\n\n \e[1;3;37;44m DescriptorFileDirectory:\e[0m " << File_Data_Collector.Get_DescriptorFileDirectory() << "#";

     std::cout << "\n\n \e[1;3;37;44m DescriptorFileName:\e[0m "      << File_Data_Collector.Get_DescriptorFileName() << "#";

     std::cout << "\n\n \e[1;3;37;44m Include_Directory_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Include_Directory_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Source_File_Locations_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Source_File_Locations_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Library_Locations_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Library_Directories_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Header_File_Names_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Header_File_Names_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Source_File_Names_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Source_File_Names_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Library_Names_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Library_Names_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Main_File_Name_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Main_File_Name_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Executable_File_Name_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Executable_File_Name_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Inter_Thread_Class_Header_File_Names_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Inter_Thread_Class_Header_File_Names_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Inter_Thread_Class_Names_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Class_Names_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Inter_Thread_Class_Instance_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Class_Instance_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Inter_Thread_Data_Type_Header_File_Names:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Shared_Data_Types_Include_Files_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Inter_Thread_Data_Types_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Shared_Data_Types_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Inter_Thread_Data_Type_Pointer_Names_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Shared_Data_Type_Pointer_Names_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Construction_Point_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Supervisor_Class_Construction_Point_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Server_Class_Name_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Supervisor_Class_Name_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Thread_Numbers_Record_Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Thread_Numbers_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Thread Names Record Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Thread_Names_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Namespace Record Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.Namespace_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m OpenMP_Support Record Area:\e[0m\n";

     Print_Record_Area(File_Data_Collector.OpenMP_Support_Record_Area);

     std::cout << "\n\n \e[1;3;37;44m Include_Directory_Numbers:\e[0m " << File_Data_Collector.Include_Directory_Numbers;

     std::cout << "\n\n \e[1;3;37;44m Source_File_Locations_Number:\e[0m " << File_Data_Collector.Source_File_Location_Number;

     std::cout << "\n\n \e[1;3;37;44m Source_File_Number:\e[0m " << File_Data_Collector.Source_File_Number;

     std::cout << "\n\n \e[1;3;37;44m Library_Directory_Number:\e[0m " << File_Data_Collector.Library_Directory_Number;

     std::cout << "\n\n \e[1;3;37;44m Library_Names_Number:\e[0m " << File_Data_Collector.Library_Names_Number;

     std::cout << "\n\n \e[1;3;37;44m Header_File_Names_Number:\e[0m " << File_Data_Collector.Header_File_Names_Number;

     std::cout << "\n\n \e[1;3;37;44m Inter_Thread_Class_Header_File_Names_Number:\e[0m " << File_Data_Collector.Inter_Thread_Class_Header_File_Names_Number;

     std::cout << "\n\n \e[1;3;37;44m Class_Number:\e[0m " << File_Data_Collector.Class_Number;

     std::cout << "\n\n \e[1;3;37;44m Class_Instance_Number:\e[0m " << File_Data_Collector.Class_Instance_Number;

     std::cout << "\n\n \e[1;3;37;44m Shared_Data_Types_Number:\e[0m " << File_Data_Collector.Shared_Data_Types_Number;

     std::cout << "\n\n \e[1;3;37;44m Shared_Data_Types_Include_File_Names_Number:\e[0m " << File_Data_Collector.Shared_Data_Types_Include_File_Names_Number;

     std::cout << "\n\n \e[1;3;37;44m Shared_Data_Type_Pointer_Names_Number:\e[0m " << File_Data_Collector.Shared_Data_Type_Pointer_Names_Number;

     std::cout << "\n\n \e[1;3;37;44m Construction_Point_Record_Number:\e[0m " << File_Data_Collector.Construction_Point_Record_Number;

     std::cout << "\n\n \e[1;3;37;44m Supervisor_Class_Name_Record_Number:\e[0m " << File_Data_Collector.Supervisor_Class_Name_Record_Number;

     std::cout << "\n\n \e[1;3;37;44m Thread Names Number:\e[0m " << File_Data_Collector.Thread_Function_Number;


     File_Data_Collector.Clear_Dynamic_Memory();

     std::cout << "\n\n \e[2;3m # THE END OF THE PROGRAM # \e[0m \n\n";

     return 0;
 };
