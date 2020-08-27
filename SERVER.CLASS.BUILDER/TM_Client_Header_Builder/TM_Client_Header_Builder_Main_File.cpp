
#include "Process_Supervisor_Descriptor_File_Reader.h"
#include "TM_Client_Header_Builder.h"
#include <iostream>
#include <cstring>


int main(int argc, char ** argv){

    Process_Supervisor_Descriptor_File_Reader File_Reader;

    File_Reader.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

    File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

    File_Reader.Receive_Descriptor_File_Infomations();

    char Include_Directory [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/Sample_Supervisor_Include_Directory";

    TM_Client_Header_Builder Header_Builder;

    Header_Builder.Receive_Newly_Constructed_Include_Directory(Include_Directory);

    char * Construction_Point = File_Reader.Get_Construction_Point();

    Header_Builder.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

    Header_Builder.Build_Header_File();

    std::cout << "\n\n The end of the program .. \n\n";

    return 0;
}
