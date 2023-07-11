
#include "Main_File_Builder.h"
#include <iostream>

int main(int argc, char ** argv){

    Main_File_Builder File_Builder;

    char New_Include_Directory_Name [] = "Thread_Server_Include_Directory";

    File_Builder.Receive_Newly_Constructed_Include_Directory_Name(New_Include_Directory_Name);

    File_Builder.Build_Main_File();

    File_Reader.Clear_Dynamic_Memory();

    std::cout << "\n\n  The end of program .. \n\n";

    return 0;
}
