
#include "Main_File_Builder.h"
#include "Process_Supervisor_Descriptor_File_Reader.h"
#include <iostream>

int main(int argc, char ** argv){

    Process_Supervisor_Descriptor_File_Reader File_Reader;

    File_Reader.Receive_Descriptor_File_Directory("/home/erkam/TestDirectory");

    File_Reader.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

    File_Reader.Receive_Descriptor_File_Infomations();

    Main_File_Builder File_Builder;

    char New_Include_Directory_Name [] = "Sample_Supervisor_Include_Directory";

    File_Builder.Receive_Descriptor_File_Object_Addres(&File_Reader);

    File_Builder.Receive_Newly_Constructed_Include_Directory_Name(New_Include_Directory_Name);

    File_Builder.Build_Main_File();

    File_Reader.Clear_Dynamic_Memory();

    std::cout << "\n\n  The end of program .. \n\n";

    return 0;
}
