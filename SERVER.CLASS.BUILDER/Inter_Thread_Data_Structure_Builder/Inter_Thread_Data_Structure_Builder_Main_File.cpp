


#include "Process_Supervisor_Descriptor_File_Reader.h"
#include "Inter_Thread_Data_Structure_Builder.h"
#include <iostream>
#include <cstring>

int main(int argc, char ** argv){

    Process_Supervisor_Descriptor_File_Reader File_Reader;

    File_Reader.Receive_Descriptor_File_Directory(argv[1]);

    File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

    File_Reader.Receive_Descriptor_File_Infomations();

    Inter_Thread_Data_Structure_Builder Builder;

    Builder.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

    Builder.Build_Inter_Thread_Data_Structure();

    Builder.Clear_Dynamic_Memory();

    File_Reader.Clear_Dynamic_Memory();

    std::cout << "\n\n The end of the program .. \n\n";

    return 0;
}
