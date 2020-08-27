
#include "MT_Project_Builder.h"
#include <iostream>

int main(int argc, char ** argv){

    std::cout << "\n";

    std::cout << "\n\t\tBINARY FILE CONSTRUCTION PROCESS REPORT!";

    MT_Project_Builder Builder;

    Builder.Receive_Descriptor_File_Directory(argv[1]);

    Builder.Receive_Descriptor_File_Name("Project_Descriptor_File");

    Builder.Build_Project();

    Builder.Clear_Dynamic_Memory();

    std::cout << "\n";

    return 0;
}
