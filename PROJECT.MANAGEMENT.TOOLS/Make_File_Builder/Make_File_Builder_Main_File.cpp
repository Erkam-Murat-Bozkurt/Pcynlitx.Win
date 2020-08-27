
#include <iostream>
#include <cstring>
#include "Make_File_Builder.h"

void Place_String(char ** Pointer, const char * String);

int main(int argc, char ** argv){

    Make_File_Builder File_Builder;

    char * Project_Header_Files_Location = argv[1];

    char * Object_Files_Location = argv[2];

    char * Project_Library_Location = argv[3];

    char * Project_Library_Name = argv[4];

    if(argv[5][0] == 'g'){

       File_Builder.Make_For_GUI(true);
    }

    int Header_Files_Location_String_Size = strlen(Project_Header_Files_Location);

    int Project_Library_Location_String_Size = strlen(Project_Library_Location);

    int Object_Files_Location_String_Size = strlen(Object_Files_Location);

    int Project_Library_Name_String_Size = strlen(Project_Library_Name);

    char * Header_Files_Location = new char [10*Header_Files_Location_String_Size];

    char * Object_Files_Directory = new char [10*Object_Files_Location_String_Size];

    char * Library_Directory = new char [10*Project_Library_Location_String_Size];

    char * Library_Name = new char [10*Project_Library_Name_String_Size];

    Place_String(&Header_Files_Location,Project_Header_Files_Location);

    Place_String(&Library_Directory,Project_Library_Location);

    Place_String(&Object_Files_Directory,Object_Files_Location);

    Place_String(&Library_Name,Project_Library_Name);

    File_Builder.Build_MakeFile(Header_Files_Location,Object_Files_Directory,Library_Directory,Library_Name);

    delete [] Header_Files_Location;

    delete [] Object_Files_Directory;

    delete [] Library_Directory;

    delete [] Library_Name;

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
