
 #include "Process_Supervisor_Descriptor_File_Data_Collector.h"
 #include "Process_Supervisor_Descriptor_File_Reader_Initializer.h"
 #include "Process_Supervisor_Descriptor_File_Number_Processor.h"
 #include "Include_Directory_Description_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     Process_Supervisor_Descriptor_File_Data_Collector File_Data_Collector;

     Process_Supervisor_Descriptor_File_Reader_Initializer Reader_Initializer;

     Process_Supervisor_Descriptor_File_Number_Processor Number_Processor;

     Include_Directory_Description_Reader ID_Description_Reader;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/IntelligentObject/TestDirectory");

     File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

     Reader_Initializer.Read_File_Lists();

     ID_Description_Reader.Receive_Data_Collector(&File_Data_Collector);

     ID_Description_Reader.Receive_Initializer(&Reader_Initializer);

     ID_Description_Reader.Receive_Number_Processor(&Number_Processor);

     ID_Description_Reader.Read_Include_Directory_Descriptions();

     int Total_Include_Directory_Number = ID_Description_Reader.Get_Include_Directory()[0].Total_Include_Directory_Number;

     if(Total_Include_Directory_Number > 0){

        std::cout << "\n  \e[7;3m Include Directories: \e[0m \n";

        for(int i=0;i<Total_Include_Directory_Number;i++){

            std::cout << "\n  [" << ID_Description_Reader.Get_Include_Directory()[i].Directory_Number << "]";

            std::cout << " " << ID_Description_Reader.Get_Include_Directory()[i].Include_Directory << "#";

            std::cout << "\n";
        }
     }

     std::cout << "\n\n \e[1;3m # THE END OF THE PROGRAM # \e[0m  \n\n";

     return 0;
 };
