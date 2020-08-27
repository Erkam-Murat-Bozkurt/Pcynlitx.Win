
#include "Included_Header_File_Names_Reader.h"
#include <iostream>

int main(int argc, char ** argv){

    Included_Header_File_Names_Reader Reader;

    Reader.Determine_Included_Header_File_Names(argv[1]);

    std::cout << "\n\n Class Name:" << Reader.Get_Class_Name();

    std::cout << "\n\n Class Source File Name:" << Reader.Get_Class_Source_File_Name();

    std::cout << "\n\n Class Object File Name:" << Reader.Get_Class_Object_File_Name();

    for(int i=0;i<Reader.Get_Included_Header_File_Number();i++){

        std::cout << "\n\n\t\tIncluded Header File [" << i << "]:" << Reader.Get_Included_Header_File_Names()[i];

        std::cout << "\n\n\t\tHeader File Declaration [" << i << "]" << Reader.Get_Header_File_Declarations()[i];

        std::cout << "\n\n\t\tRelated Object File Name [" << i << "]:" << Reader.Get_Included_Object_File_Names()[i];
    }

    std::cout << "\n\n The end of the program..";

   return 0;
}
