
 #include "Thread_Manager_Header_File_Builder.h"
 #include <iostream>


 int main(int argc, char** argv){


     Thread_Manager_Header_File_Builder HeaderFileBuilder;

     HeaderFileBuilder.Build_ThreadSynchronization_Header_File();

     std::cout << "\n\n The and of the program ..\n\n";

     return 0;
 };
