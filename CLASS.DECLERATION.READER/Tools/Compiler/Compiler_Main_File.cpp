
 #include "Compiler.h"
 #include <iostream>


 int main(int argc, char** argv){

     Compiler MyCompiler;

     std::cout << "\n\n \e[1;3;30;43m  COMPILER STARTED TO PROCESS \e[0m \n\n";

     MyCompiler.Receive_Descriptor_File_Directory(argv[1]);

     MyCompiler.Receive_Descriptor_File_Name(argv[2]);

     MyCompiler.Receive_Descriptor_File_Infomations();

     MyCompiler.Build_Project();

     std::cout << "\n\n \e[3m # THE END OF THE PROGRAM # \e[0m \n\n";

     return 0;
 };
