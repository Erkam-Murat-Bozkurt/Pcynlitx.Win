
 #include "Descriptor_File_Data_Collector.h"
 #include "Descriptor_File_Reader_Initializer.h"
 #include "Descriptor_File_Number_Processor.h"
 #include "Include_Directory_Description_Reader.h"
 #include "Inter_Thread_Class_Description_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Data_Collector File_Data_Collector;

     Descriptor_File_Reader_Initializer Reader_Initializer;

     Descriptor_File_Number_Processor Number_Processor;

     Include_Directory_Description_Reader ID_Description_Reader;

     Inter_Thread_Class_Description_Reader Class_Description_Reader;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

     Reader_Initializer.Read_File_Lists();

     ID_Description_Reader.Receive_Data_Collector(&File_Data_Collector);

     ID_Description_Reader.Receive_Initializer(&Reader_Initializer);

     ID_Description_Reader.Receive_Number_Processor(&Number_Processor);

     ID_Description_Reader.Read_Include_Directory_Descriptions();

     Class_Description_Reader.Receive_Data_Collector(&File_Data_Collector);

     Class_Description_Reader.Receive_Initializer(&Reader_Initializer);

     Class_Description_Reader.Receive_Number_Processor(&Number_Processor);

     Class_Description_Reader.Receive_Include_Directory_Description_Reader(&ID_Description_Reader);

     Class_Description_Reader.Read_Inter_Thread_Class_Descriptions();

     int Total_Class_Number = Class_Description_Reader.Get_Class_Names()[0].Total_Class_Number;

     if(Total_Class_Number > 0){

        std::cout << "\n\n  \e[7;3m Class Names:\e[0m \n";

        for(int i=0;i<Total_Class_Number;i++){

            std::cout << "\n  Class Name      : " << Class_Description_Reader.Get_Class_Names()[i].Class_Name << "#";

            std::cout << "\n  Class Number    : " << Class_Description_Reader.Get_Class_Names()[i].Class_Number << "#";

            std::cout << "\n  Class Instace   : " << Class_Description_Reader.Get_Class_Names()[i].Class_Instance_Name << "#";

            std::cout << "\n  Header File     : " << Class_Description_Reader.Get_Class_Names()[i].Header_File_Name << "#";

            std::cout << "\n  Header Location : " << Class_Description_Reader.Get_Class_Names()[i].Header_File_Location << "#";

            std::cout << "\n";
        }
     }
     else{

            std::cout << "\n\n \e[1;37;42m Class Names:\e[0m" << "\n\n There is no class name";

            std::cout << "\n\n \e[1;37;42m Object Names:\e[0m" << "\n\n There is no class instance name";
     }

     std::cout << "\n\n \e[1;3m # THE END OF THE PROGRAM # \e[0m  \n\n";

     return 0;
 };
