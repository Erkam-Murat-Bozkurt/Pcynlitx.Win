


#include "Inter_Thread_Data_Structure_Builder.h"
#include <iostream>
#include <cstring>

int main(int argc, char ** argv){

    Inter_Thread_Data_Structure_Builder Builder;

    Builder.Build_Inter_Thread_Data_Structure();

    Builder.Clear_Dynamic_Memory();

    File_Reader.Clear_Dynamic_Memory();

    std::cout << "\n\n The end of the program .. \n\n";

    return 0;
}
