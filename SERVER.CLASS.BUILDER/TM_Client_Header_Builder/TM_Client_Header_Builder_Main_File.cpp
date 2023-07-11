
#include "TM_Client_Header_Builder.h"
#include <iostream>
#include <cstring>


int main(int argc, char ** argv){

    char Include_Directory [] = "D:\\TestDirectory\\Thread_Server_Include_Directory";

    TM_Client_Header_Builder Header_Builder;

    Header_Builder.Receive_Newly_Constructed_Include_Directory(Include_Directory);

    char * Construction_Point = File_Reader.Get_Construction_Point();

    Header_Builder.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

    Header_Builder.Build_Header_File();

    std::cout << "\n\n The end of the program .. \n\n";

    return 0;
}
