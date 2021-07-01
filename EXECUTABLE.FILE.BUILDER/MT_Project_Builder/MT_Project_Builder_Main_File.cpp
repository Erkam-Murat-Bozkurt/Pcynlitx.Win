
#include "MT_Project_Builder.h"
#include <iostream>

int main(int argc, char ** argv){

    if(argc <2){

      std::cout << "\n";

      std::cout << "\n the usage MT_Project_Builder.exe <Project_Directory>";

      std::cout << "\n\n";

      exit(0);
    }

    std::cout << "\n";

    std::cout << "\n\t\tBINARY FILE CONSTRUCTION PROCESS REPORT!";

    MT_Project_Builder Builder;

    Builder.Receive_Descriptor_File_Directory(argv[1]);

    Builder.Receive_Descriptor_File_Name("Project_Descriptor_File.txt");

    int construction_success_status = Builder.Build_Project();

    Builder.Clear_Dynamic_Memory();

    std::cout << "\n";

    if(construction_success_status != 0){

       std::cout << "\n\t\tThe Construction has been failed..";

       std::cout << "\n\n\n";

       exit(EXIT_FAILURE);
    }
    else{

        exit(0);
    }
}
