
 #include "Process_Supervisor_Descriptor_File_Data_Collector.h"
 #include "Process_Supervisor_Descriptor_File_Reader_Initializer.h"
 #include "Process_Supervisor_Descriptor_File_Number_Processor.h"
 #include "Library_Descriptions_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     Process_Supervisor_Descriptor_File_Data_Collector File_Data_Collector;

     Process_Supervisor_Descriptor_File_Reader_Initializer Reader_Initializer;

     Process_Supervisor_Descriptor_File_Number_Processor Number_Processor;

     Library_Descriptions_Reader Library_Reader;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

     Reader_Initializer.Read_File_Lists();

     Library_Reader.Receive_Data_Collector(&File_Data_Collector);

     Library_Reader.Receive_Initializer(&Reader_Initializer);

     Library_Reader.Receive_Number_Processor(&Number_Processor);

     Library_Reader.Read_Library_Descriptions();

     std::cout << "\n\n  \e[7;3m Library Directories:\e[0m";

     if(Library_Reader.Get_Library_Directory_Number() > 0){

        for(int i=0;i<Library_Reader.Get_Library_Directory_Number();i++){

            std::cout << "\n\n  " << Library_Reader.Get_Library_Directories()[i];
        }
     }
     else{
            std::cout << " Thread is no library directory ..";
     }

     std::cout << "\n\n  \e[7;3m Library Names:\e[0m";

     if(Library_Reader.Get_Library_Names_Number() > 0){

        for(int i=0;i<Library_Reader.Get_Library_Names_Number();i++){

            std::cout <<  "\n\n  " << Library_Reader.Get_Library_Names()[i];
        }
     }

     std::cout << "\n\n \e[1;3m # THE END OF THE PROGRAM # \e[0m  \n\n";

     return 0;
 };
