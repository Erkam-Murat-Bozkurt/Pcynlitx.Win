
#include "Empty_Process_Descriptor_File_Builder.h"
#include <iostream>

int main(int argc, char ** argv){

    Empty_Process_Descriptor_File_Builder Builder;

    Builder.Read_Construction_Point(argv[1]);

    Builder.Build_Descriptor_File();

    Builder.Clear_Dynamic_Memory();

    return 0;
}
