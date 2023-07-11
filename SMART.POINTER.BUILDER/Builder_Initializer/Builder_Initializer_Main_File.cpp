
 #include "Builder_Initializer.h"
 #include <iostream>

 int main(int argc, char** argv){

     Builder_Initializer Initializer;

     Initializer.Receive_Data_Type(File_Reader.Get_Shared_Data_Types()[0].Data_Type);

     Initializer.Receive_Generic_Class_Name("ReferenceCounter");

     if(File_Reader.Get_Shared_Data_Types()[0].Header_File_Name !='\0'){

         Initializer.Receive_Data_Type_Include_File_Name(File_Reader.Get_Shared_Data_Types()[0].Header_File_Name);
     }

     Initializer.Receive_Base_Directory("D:\\TestDirectory");

     Initializer.Receive_Construction_Point("D:\\TestDirectory");

     Initializer.Collect_Informations();

     std::cout << "\n DataType          :"

               << Initializer.Get_DataType();

     std::cout << "\n NewClassName      :"

               << Initializer.Get_NewClassName();

     std::cout << "\n NewHeaderFileName :"

               << Initializer.Get_NewHeaderFileName();

     std::cout << "\n Source File Name  :"

               << Initializer.Get_ClassImplementationFileName();

     std::cout << "\n Constructor Name  :"

               << Initializer.Get_Class_Constructor_Name();

     std::cout << "\n Destructor Name   :"

               << Initializer.Get_Class_Destructor_Name();

     std::cout << "\n Data_Type_Include_File_Name_Receive_Condition:"

               << Initializer.Get_Data_Type_Include_File_Name_Receive_Condition();

     if(Initializer.Get_DataType_IncludeFileName() == nullptr){

        std::cout << "\n DataType_IncludeFileName is null ";
     }

     std::cout << "\n Data Type include File Name:"

               << Initializer.Get_DataType_IncludeFileName();

     std::cout << "\n Base Directory :"

               << Initializer.Get_Base_Directory();

     std::cout << "\n Construction Point:"

               << Initializer.Get_Construction_Point();

     std::cout << "\n\n The end of the program .. \n\n";

     File_Reader.Clear_Dynamic_Memory();

     Initializer.Clear_Dynamic_Memory();

     return 0;
 };
