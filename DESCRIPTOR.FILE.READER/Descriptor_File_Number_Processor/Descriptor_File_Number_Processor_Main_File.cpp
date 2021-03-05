
 #include "Descriptor_File_Data_Collector.h"
 #include "Descriptor_File_Reader_Initializer.h"
 #include "Descriptor_File_Number_Processor.h"
 #include <iostream>

 void Print_Record_Area(int array []){

      std::cout << "\n    Start_Point:" << array[0];

      std::cout << "\n    End_Point:" << array[1];
 }

 int main(int argc, char** argv){

     Descriptor_File_Data_Collector File_Data_Collector;

     Descriptor_File_Reader_Initializer Reader_Initializer;

     Descriptor_File_Number_Processor Number_Processor;

     File_Data_Collector.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Data_Collector.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Data_Collector.Collect_Descriptor_File_Datas();

     Reader_Initializer.Receve_Data_Collector(&File_Data_Collector);

     Reader_Initializer.Read_File_Lists();

     if(File_Data_Collector.Shared_Data_Types_Include_File_Names_Number > 0){

         for(int i=0;i<File_Data_Collector.Shared_Data_Types_Include_File_Names_Number;i++){

             std::cout << "\n  " << Reader_Initializer.Get_Shared_Data_Type_Header_File_List()[i] << "#";
         }

        char * String_Line = Reader_Initializer.Get_Shared_Data_Type_Header_File_List()[0];

        int First_Number = Number_Processor.Read_Record_Number_From_String_Line(String_Line);

        int Second_Number = Number_Processor.Read_Second_Record_Number_From_String_Line(String_Line);

        std::cout << "\n  First_Number:" << First_Number;

        std::cout << "\n  Second Number:" << Second_Number;

        std::cout << "\n  ";

        int Read_Start_Point =  Number_Processor.Get_Read_Operation_Start_Point(String_Line);

        for(int i=Read_Start_Point;i<strlen(String_Line);i++){

            std::cout << String_Line[i];
        }

        std::cout << "#";
     }
     else{

          std::cout << " There is no shared data type header file name ..";
     }

     int Number_Set_1 [] = {1,2,3,4,5};

     int Number_Set_2 [] = {1,2,2,3,4};

     bool Set_1_Condition = Number_Processor.Check_Number_Repitation(Number_Set_1,5);

     bool Set_2_Condition = Number_Processor.Check_Number_Repitation(Number_Set_2,5);

     std::cout << "\n\n  Set_1_Condition:" << Set_1_Condition;

     std::cout << "\n\n  Set_2_Condition:" << Set_2_Condition;

     File_Data_Collector.Clear_Dynamic_Memory();

     Reader_Initializer.Clear_Dynamic_Memory();

     Number_Processor.Clear_Dynamic_Memory();

     std::cout << "\n\n \e[2;3m # THE END OF THE PROGRAM # \e[0m \n\n";

     return 0;
 };
