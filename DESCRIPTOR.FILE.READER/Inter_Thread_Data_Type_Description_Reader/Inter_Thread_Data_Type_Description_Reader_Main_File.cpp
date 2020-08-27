
 #include "Descriptor_File_Data_Collector.h"
 #include "Descriptor_File_Reader_Initializer.h"
 #include "Descriptor_File_Number_Processor.h"
 #include "Include_Directory_Description_Reader.h"
 #include "Inter_Thread_Data_Type_Description_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Data_Collector File_Data_Collector;

     Descriptor_File_Reader_Initializer Reader_Initializer;

     Descriptor_File_Number_Processor Number_Processor;

     Include_Directory_Description_Reader ID_Description_Reader;

     Inter_Thread_Data_Type_Description_Reader Data_Type_Description_Reader;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

     Reader_Initializer.Read_File_Lists();

     ID_Description_Reader.Receive_Data_Collector(&File_Data_Collector);

     ID_Description_Reader.Receive_Initializer(&Reader_Initializer);

     ID_Description_Reader.Receive_Number_Processor(&Number_Processor);

     ID_Description_Reader.Read_Include_Directory_Descriptions();

     Data_Type_Description_Reader.Receive_Data_Collector(&File_Data_Collector);

     Data_Type_Description_Reader.Receive_Initializer(&Reader_Initializer);

     Data_Type_Description_Reader.Receive_Number_Processor(&Number_Processor);

     Data_Type_Description_Reader.Receive_Include_Directory_Description_Reader(&ID_Description_Reader);

     Data_Type_Description_Reader.Read_Inter_Thread_Data_Type_Descriptions();

     std::cout << "\n  \e[7;3m Shared Data Types:\e[0m \n";

     int Total_Data_Type_Number = Data_Type_Description_Reader.Get_Shared_Data_Types_Number();

     if(Total_Data_Type_Number > 0){

        for(int i=0;i<Total_Data_Type_Number;i++){

            std::cout << "\n  Data Type        : " << Data_Type_Description_Reader.Get_Shared_Data_Types()[i].Data_Type << "#";

            std::cout << "\n  Data Number      : " << Data_Type_Description_Reader.Get_Shared_Data_Types()[i].Data_Number << "#";

            std::cout << "\n  Pointer Name     : " << Data_Type_Description_Reader.Get_Shared_Data_Types()[i].Pointer_Name << "#";

            if(Data_Type_Description_Reader.Get_Shared_Data_Types()[i].Header_File_Name != nullptr){

                std::cout << "\n  Header file name : " << Data_Type_Description_Reader.Get_Shared_Data_Types()[i].Header_File_Name << "#";
            }
            else{

                 std::cout << "\n  There is no header file name..";
            }

            if(Data_Type_Description_Reader.Get_Shared_Data_Types()[i].Include_Directory != nullptr){

                std::cout << "\n  Include_Directory: " << Data_Type_Description_Reader.Get_Shared_Data_Types()[i].Include_Directory << "#";
            }
            else{

                std::cout << "\n  There is no include directory ..";
            }

            std::cout << "\n";
        }
     }
     else{

         std::cout << "\n  There is no Shared_Data_Types";
     }

     File_Data_Collector.Clear_Dynamic_Memory();

     Reader_Initializer.Clear_Dynamic_Memory();

     Number_Processor.Clear_Dynamic_Memory();

     ID_Description_Reader.Clear_Dynamic_Memory();

     Data_Type_Description_Reader.Clear_Dynamic_Memory();

     std::cout << "\n\n \e[1;3m # THE END OF THE PROGRAM # \e[0m  \n\n";

     return 0;
 };
