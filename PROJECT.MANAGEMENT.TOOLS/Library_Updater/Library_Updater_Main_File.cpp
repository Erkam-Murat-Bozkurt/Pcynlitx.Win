
#include "Library_Updater.h"

void Place_String(char ** Pointer, const char * String);

int main(){

    const char * Project_Object_Files_Location = "/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY/OBJECT.FILES";

    const char * Library_Directory_Decleration = "/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY";

    const char * Library_Name_Decleration = "mptools";

    int Object_Files_Location_String_Size = strlen(Project_Object_Files_Location);

    int Library_Directory_Decleration_Name_Size = strlen(Library_Directory_Decleration);

    int Library_Name_Decleration_Size = strlen(Library_Name_Decleration);

    char * Object_Files_Location = new char [5*Object_Files_Location_String_Size];

    char * Library_Directory = new char [5*Library_Directory_Decleration_Name_Size];

    char * Library_Name = new char [5*Library_Name_Decleration_Size];

    Place_String(&Object_Files_Location,Project_Object_Files_Location);

    Place_String(&Library_Directory,Library_Directory_Decleration);

    Place_String(&Library_Name,Library_Name_Decleration);

    Library_Updater Updater;

    Updater.Build_Library(Object_Files_Location,Library_Name);

    Updater.Send_Library_New_Location(Object_Files_Location,Library_Directory,Library_Name);

    delete [] Object_Files_Location;

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
