
#include "Process_Supervisor_Descriptor_File_Data_Collector.h"
#include "Process_Supervisor_Descriptor_File_Reader_Initializer.h"
#include "Process_Supervisor_Descriptor_File_Number_Processor.h"
#include "Include_Directory_Description_Reader.h"
#include "Header_File_Descriptions_Reader.h"
#include <iostream>


int main(int argc, char** argv){

    Process_Supervisor_Descriptor_File_Data_Collector File_Data_Collector;

    Process_Supervisor_Descriptor_File_Reader_Initializer Reader_Initializer;

    Process_Supervisor_Descriptor_File_Number_Processor Number_Processor;

    Include_Directory_Description_Reader ID_Description_Reader;

    Header_File_Descriptions_Reader HF_Descriptions_Reader;

    File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

    File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

    File_Data_Collector.Collect_Descriptor_File_Datas();

    Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

    Reader_Initializer.Read_File_Lists();

    ID_Description_Reader.Receive_Data_Collector(&File_Data_Collector);

    ID_Description_Reader.Receive_Initializer(&Reader_Initializer);

    ID_Description_Reader.Receive_Number_Processor(&Number_Processor);

    ID_Description_Reader.Read_Include_Directory_Descriptions();

    HF_Descriptions_Reader.Receive_Data_Collector(&File_Data_Collector);

    HF_Descriptions_Reader.Receive_Initializer(&Reader_Initializer);

    HF_Descriptions_Reader.Receive_Number_Processor(&Number_Processor);

    HF_Descriptions_Reader.Receive_Include_Directory_Description_Reader(&ID_Description_Reader);

    HF_Descriptions_Reader.Receive_Header_File_Names();

    std::cout << "\n\n  \e[7;3m Header_File_Names:\e[0m";

    int Header_File_Number = HF_Descriptions_Reader.Get_Header_Files_Number();

    if(Header_File_Number > 0){

       for(int i=0;i<Header_File_Number;i++){

           std::cout << "\n\n  [" << i+1 << "] " << HF_Descriptions_Reader.Get_Header_File_Names()[i];
       }
    }
    else{

          std::cout << " There is no header file name ..";
    }

    std::cout << "\n\n  \e[7;3m Header_File_Paths:\e[0m";

    if(Header_File_Number > 0){

       for(int i=0;i<Header_File_Number;i++){

           std::cout << "\n\n  [" << i+1 << "] " << HF_Descriptions_Reader.Get_Header_File_Paths()[i];
       }
    }
    else{

          std::cout << " There is no header file name ..";
    }

    std::cout << "\n\n \e[1;3m # THE END OF THE PROGRAM # \e[0m  \n\n";

   return 0;
};
