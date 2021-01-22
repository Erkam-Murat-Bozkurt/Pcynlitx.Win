
#include "Test_Program_Builder.h"
#include <iostream>

void Place_String(char ** Pointer, const char * String);

int main(int argc, char ** argv){

    const char * Headers_Files_Location

          = "D:\\PCYNLITX.WIND.IMPL.LIBRARY\\PROJECT.LIBRARY\\OBJECT.FILES";

    const char * Object_Files_Location

          = "D:\\PCYNLITX.WIND.IMPL.LIBRARY\\PROJECT.LIBRARY\\OBJECT.FILES";

    const char * Directory_Location

          = "D:\\PCYNLITX.WIND.IMPL.LIBRARY\\PROJECT.LIBRARY";

    const char * Library_Name = "mptools";

    Test_Program_Builder Builder;

    Builder.Build_Test_Program(Headers_Files_Location,Object_Files_Location,Directory_Location,Library_Name);

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
