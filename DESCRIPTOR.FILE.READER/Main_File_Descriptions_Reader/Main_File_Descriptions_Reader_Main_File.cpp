
 #include "Descriptor_File_Data_Collector.h"
 #include "Descriptor_File_Reader_Initializer.h"
 #include "Descriptor_File_Number_Processor.h"
 #include "Main_File_Descriptions_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Data_Collector File_Data_Collector;

     Descriptor_File_Reader_Initializer Reader_Initializer;

     Descriptor_File_Number_Processor Number_Processor;

     Main_File_Descriptions_Reader MF_Descriptions_Reader;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/IntelligentObject/TestDirectory");

     File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

     Reader_Initializer.Read_File_Lists();

     MF_Descriptions_Reader.Receive_Data_Collector(&File_Data_Collector);

     MF_Descriptions_Reader.Receive_Initializer(&Reader_Initializer);

     MF_Descriptions_Reader.Receive_Number_Processor(&Number_Processor);

     MF_Descriptions_Reader.Read_Main_File_Descriptions();

     int Thread_Function_Number = MF_Descriptions_Reader.Get_Thread_Function_Number();

     std::cout << "\n  \e[7;3m Thread Names:\e[0m";

     if(Thread_Function_Number > 0){

        char ** Thread_Names = MF_Descriptions_Reader.Get_Thread_Function_Names();

        for(int i=0;i<Thread_Function_Number;i++){

            std::cout << "\n\n  " << Thread_Names[i];
        }
     }
     else{
            std::cout << " There is no thread name ..";
     }

     std::cout << "\n\n  \e[7;3m Main File Name:\e[0m";

     if(MF_Descriptions_Reader.Get_Main_File_Name() != nullptr){

        std::cout << "\n\n  " << MF_Descriptions_Reader.Get_Main_File_Name();
     }
     else{

           std::cout << "\n There is no main file name";
     }

     std::cout << "\n\n  \e[7;3m Executable_File_Name \e[0m";

     if(MF_Descriptions_Reader.Get_Executable_File_Name() != nullptr){

        std::cout << "\n\n  " << MF_Descriptions_Reader.Get_Executable_File_Name();
     }
     else{
            std::cout << " There is no Executable_File_Name ..";
     }

     std::cout << "\n\n  \e[7;3m Construction Point:\e[0m\n\n  "    << MF_Descriptions_Reader.Get_Construction_Point() << "#";

     std::cout << "\n\n  \e[7;3m Supervisor_Class_Name:\e[0m\n\n  " << MF_Descriptions_Reader.Get_Server_Class_Name() << "#";

     std::cout << "\n\n  \e[7;3m Supervisor_Class_Header_File_Name:\e[0m\n\n  " << MF_Descriptions_Reader.Get_Server_Class_Header_File_Name() << "#";

     std::cout << "\n\n \e[1;3m # THE END OF THE PROGRAM # \e[0m  \n\n";

     return 0;
 };
