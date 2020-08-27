
#include "Descriptor_File_Reader.h"
#include "Inter_Thread_Data_Structure_Builder.h"
#include "TM_Client_Builder.h"
#include <iostream>
#include <cstring>

int main(int argc, char ** argv){

    Descriptor_File_Reader File_Reader;

    File_Reader.Receive_Descriptor_File_Directory("/home/erkam/Project_Apps");

    File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

    File_Reader.Receive_Descriptor_File_Infomations();

    TM_Client_Builder Builder;

    Builder.Receive_Descriptor_File_Reader(&File_Reader);

    Builder.Build_Thread_Manager_Client();

    Builder.Clear_Dynamic_Memory();

    File_Reader.Clear_Dynamic_Memory();

    std::cout << "\n\n The end of the program .. \n\n";

    return 0;
}
