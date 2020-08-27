
#include <Descriptor_File_Reader.h>
#include "Compiler_Descriptor_File_Constructor.h"
#include <iostream>
#include <cstring>


 int main(int argc, char** argv){

     Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory(argv[1]);

     File_Reader.Receive_Descriptor_File_Name(argv[2]);

     File_Reader.Receive_Descriptor_File_Infomations();

     std::cout << "\n After reading..";

     std::cin.get();

     Compiler_Descriptor_File_Constructor Constructor;

     Constructor.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

     Constructor.Build_Compiler_Descriptor_File();

     Constructor.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program..\n\n";

     return 0;
 };
