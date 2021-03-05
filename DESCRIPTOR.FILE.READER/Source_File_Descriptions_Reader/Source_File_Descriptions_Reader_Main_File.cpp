
 #include "Descriptor_File_Data_Collector.h"
 #include "Descriptor_File_Reader_Initializer.h"
 #include "Descriptor_File_Number_Processor.h"
 #include "Include_Directory_Description_Reader.h"
 #include "Source_File_Descriptions_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Data_Collector File_Data_Collector;

     Descriptor_File_Reader_Initializer Reader_Initializer;

     Descriptor_File_Number_Processor Number_Processor;

     Include_Directory_Description_Reader ID_Description_Reader;

     Source_File_Descriptions_Reader SF_Descriptions_Reader;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

     Reader_Initializer.Read_File_Lists();

     ID_Description_Reader.Receive_Data_Collector(&File_Data_Collector);

     ID_Description_Reader.Receive_Initializer(&Reader_Initializer);

     ID_Description_Reader.Receive_Number_Processor(&Number_Processor);

     ID_Description_Reader.Read_Include_Directory_Descriptions();

     SF_Descriptions_Reader.Receive_Data_Collector(&File_Data_Collector);

     SF_Descriptions_Reader.Receive_Initializer(&Reader_Initializer);

     SF_Descriptions_Reader.Receive_Number_Processor(&Number_Processor);

     SF_Descriptions_Reader.Receive_Include_Directory_Description_Reader(&ID_Description_Reader);

     SF_Descriptions_Reader.Read_Source_File_Descriptions();

     int Source_File_Location_Number = SF_Descriptions_Reader.Get_Source_File_Location_Number();

     std::cout << "\n\n  \e[7;3m Source_File_Locations:\e[0m";

     if(Source_File_Location_Number > 0){

        for(int i=0;i<Source_File_Location_Number;i++){

            std::cout << "\n\n  [" << i+1 << "] " << SF_Descriptions_Reader.Get_Source_File_Locations()[i];
        }
     }
     else{

            std::cout << " There is no source file locations ..";
     }

     std::cout << "\n\n  \e[7;3m Source_File_Names:\e[0m";

     int Source_File_Number = SF_Descriptions_Reader.Get_Source_File_Names_Number();

     if(Source_File_Number > 0){

        for(int i=0;i<Source_File_Number;i++){

            std::cout << "\n\n  [" << i+1 << "] " << SF_Descriptions_Reader.Get_Source_File_Names()[i];
        }
     }
     else{

            std::cout << " There is no source file name..";
     }

     std::cout << "\n\n \e[1;3m # THE END OF THE PROGRAM # \e[0m  \n\n";

     return 0;
 };
