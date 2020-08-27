
#include "Test_Program_Builder.h"
#include <iostream>

void Place_String(char ** Pointer, const char * String);

int main(int argc, char ** argv){

    Test_Program_Builder Builder;

    Builder.Build_Test_Program(argv[1],argv[2],argv[3],argv[4]);

    return 0;
}

// The Function that places the location Informations listed in below

void Place_String(char ** Pointer, const char * String){

     int String_Size = strlen(String);

     for(int i=0;i<String_Size;i++){

          (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}
