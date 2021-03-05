
 #include "Descriptor_File_Reader.h"
 #include "Descriptor_File_Reader_Initializer.h"
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Data_Collector File_Data_Collector;

     Descriptor_File_Reader_Initializer Reader_Initializer;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

     Reader_Initializer.Read_File_Lists();

     std::cout << "\n\n \e[1;3;37;44m Include Directory List: \e[0m \n";

     if(File_Data_Collector.Include_Directory_Numbers > 0){

        for(int i=0;i<File_Data_Collector.Include_Directory_Numbers;i++){

            std::cout << "\n  " << Reader_Initializer.Get_Include_Directory_List()[i] << "#";
        }
     }
     else{

          std::cout << " There is no Include Directory ..";
     }

     std::cout << "\n\n \e[1;3;37;44m Library Directory list: \e[0m \n";

     if(File_Data_Collector.Library_Directory_Number > 0){

         for(int i=0;i<File_Data_Collector.Library_Directory_Number;i++){

             std::cout << "\n  " << Reader_Initializer.Get_Library_Directory_List()[i] << "#";
         }
     }
     else{

          std::cout << " There is no library directory ..";
     }

     std::cout << "\n\n \e[1;3;37;44m Source_File_Location_List: \e[0m \n";

     if(File_Data_Collector.Source_File_Location_Number > 0){

        for(int i=0;i<File_Data_Collector.Source_File_Location_Number;i++){

            std::cout << "\n  " << Reader_Initializer.Get_Source_File_Location_List()[i] << "#";
        }
     }
     else{

          std::cout << " There is no source file location ..";
     }

     std::cout << "\n\n \e[1;3;37;44m Source_File_Name_List: \e[0m \n";

     if(File_Data_Collector.Source_File_Number > 0){

        for(int i=0;i<File_Data_Collector.Source_File_Number;i++){

            std::cout << "\n " << Reader_Initializer.Get_Source_File_List()[i];
        }
     }
     else{

         std::cout << " There is no source file ..";
     }

     std::cout << "\n\n \e[1;3;37;44m Library Name list: \e[0m \n";

     if(File_Data_Collector.Library_Names_Number > 0){

         for(int i=0;i<File_Data_Collector.Library_Names_Number;i++){

             std::cout << "\n  " << Reader_Initializer.Get_Library_Name_List()[i] << "#";
         }
     }
     else{

          std::cout << " There is no library name..";
     }

     std::cout << "\n\n \e[1;3;37;44m Header File name list: \e[0m \n";

     if(File_Data_Collector.Header_File_Names_Number > 0){

        for(int i=0;i<File_Data_Collector.Header_File_Names_Number;i++){

            std::cout <<  "\n  " << Reader_Initializer.Get_Header_File_List()[i] << "#";
        }
     }
     else{

          std::cout << " There is no header file name";
     }

     std::cout << "\n\n \e[1;3;37;44m Header File name list: \e[0m \n";

     if(File_Data_Collector.Inter_Thread_Class_Header_File_Names_Number > 0){

        for(int i=0;i<File_Data_Collector.Inter_Thread_Class_Header_File_Names_Number;i++){

            std::cout <<  "\n  " << Reader_Initializer.Get_Inter_Thread_Class_Header_File_List()[i] << "#";
        }
     }
     else{

          std::cout << " There is no header file name";
     }

     std::cout << "\n\n \e[1;3;37;44m Class name list: \e[0m \n";

     if(File_Data_Collector.Class_Number > 0){

         for(int i=0;i<File_Data_Collector.Class_Number;i++){

             std::cout << "\n  " << Reader_Initializer.Get_Inter_Thread_Class_Names_List()[i] << "#";
         }
     }
     else{

         std::cout << " There is no Class Name..";
     }

     std::cout << "\n\n \e[1;3;37;44m Class Instance name list: \e[0m \n";

     if(File_Data_Collector.Class_Instance_Number > 0){

         for(int i=0;i<File_Data_Collector.Class_Instance_Number;i++){

             std::cout << "\n  " << Reader_Initializer.Get_Inter_Thread_Class_Instance_Name_List()[i] << "#";
         }
     }
     else{

          std::cout << " There is no Class Instance Name ..";
     }

     std::cout << "\n\n \e[1;3;37;44m Shared Data type name list: \e[0m \n";

     if(File_Data_Collector.Shared_Data_Types_Number > 0){

         for(int i=0;i<File_Data_Collector.Shared_Data_Types_Number;i++){

             std::cout << "\n  " << Reader_Initializer.Get_Shared_Data_Type_List()[i] << "#";
         }
     }
     else{

          std::cout << " There is no shared data type.. ";
     }

     std::cout << "\n\n \e[1;3;37;44m Shared data type header file name list: \e[0m \n";

     if(File_Data_Collector.Shared_Data_Types_Include_File_Names_Number > 0){

         for(int i=0;i<File_Data_Collector.Shared_Data_Types_Include_File_Names_Number;i++){

             std::cout << "\n  " << Reader_Initializer.Get_Shared_Data_Type_Header_File_List()[i] << "#";
         }
     }
     else{

          std::cout << " There is no shared data type header file name ..";
     }

     std::cout << "\n\n \e[1;3;37;44m Shared memory pointer name list: \e[0m \n";

     if(File_Data_Collector.Shared_Data_Type_Pointer_Names_Number > 0){

         for(int i=0;i<File_Data_Collector.Shared_Data_Type_Pointer_Names_Number;i++){

             std::cout << "\n  " << Reader_Initializer.Get_Shared_Memory_Pointer_Name_List()[i] << "#";
         }
     }
     else{

          std::cout << " There is no shared memory pointer name ..";
     }

     std::cout << "\n\n \e[1;3;37;44m Thread Names are :\e[0m \n";

     if(File_Data_Collector.Thread_Function_Number > 0){

        for(int i=0;i<File_Data_Collector.Thread_Function_Number;i++){

            std::cout << "\n  " << Reader_Initializer.Get_Thread_Names_List()[i] << "#";
        }
     }
     else{

          std::cout << " There is no thread names ..";
     }

     std::cout << "\n\n \e[1;3;37;44m Construction Point: \e[0m \n\n  " << Reader_Initializer.Get_Construction_Directory() << "#";

     std::cout << "\n\n \e[1;3;37;44m Server_Class_Name: \e[0m \n\n  " << Reader_Initializer.Get_Server_Class_Name() << "#";

     std::cout << "\n\n \e[1;3;37;44m Server_Class_Header_File_Name: \e[0m \n\n  " << Reader_Initializer.Get_Server_Class_Header_File_Name() << "#";

     std::cout << "\n\n \e[1;3;37;44m Main_File_Name: \e[0m \n\n  " << Reader_Initializer.Get_Main_File_Name();

     std::cout << "\n\n \e[1;3;37;44m Executable_File_Name: \e[0m \n\n  " << Reader_Initializer.Get_Executable_File_Name();

     std::cout << "\n\n \e[1;3;37;44m Thread Number: \e[0m \n\n  " << Reader_Initializer.Get_Thread_Number();

     File_Data_Collector.Clear_Dynamic_Memory();

     Reader_Initializer.Clear_Dynamic_Memory();

     std::cout << "\n\n \e[2;3m # THE END OF THE PROGRAM # \e[0m \n\n";

     return 0;
 };
