
 #include "Dynamic_Memory_Manager_Builder.h"

 void Place_Information(char ** Pointer, const char * Information, int List_Size){

     for(int i=0;i<List_Size;i++){

         (*Pointer)[i] = Information[i];
     }

     (*Pointer)[List_Size] = '\0';
 }

 int main(int argc, char** argv){

     Dynamic_Memory_Manager_Builder Manager_Builder;

     const char * Data_Type = "CFileOperations";

     int Data_Type_Name_Size = strlen(Data_Type);

     char * Data_Type_Name = new char [5*Data_Type_Name_Size];

     Place_Information(&Data_Type_Name,Data_Type,Data_Type_Name_Size);

     const char * Data_Type_Header_File_Name = "CFileOperations.h";

     int Data_Type_Name_Header_File_Name_Size = strlen(Data_Type_Header_File_Name);

     char * Data_Type_Header_File_Pointer = new char [5*Data_Type_Name_Header_File_Name_Size];

     Place_Information(&Data_Type_Header_File_Pointer,Data_Type_Header_File_Name,Data_Type_Name_Header_File_Name_Size);

     const char * Construction_Point = "/home/erkam/Smart.Pointer.Builder/Dynamic_Memory_Manager_Header_Builder";

     int Construction_Point_Name_Size = strlen(Construction_Point);

     char * Construction_Point_Pointer = new char [5*Construction_Point_Name_Size];

     Place_Information(&Construction_Point_Pointer,Construction_Point,Construction_Point_Name_Size);

     const char * Entered_Class_Name = "SmartPointer";

     int Class_Name_Size = strlen(Entered_Class_Name);

     char * Entered_Class_Name_Pointer = new char [5*Class_Name_Size];

     Place_Information(&Entered_Class_Name_Pointer,Entered_Class_Name,Class_Name_Size);

     Manager_Builder.Receive_Data_Type(Data_Type_Name);

     Manager_Builder.Receive_Entered_Class_Name(Entered_Class_Name_Pointer);

     Manager_Builder.Receive_Construction_Point(Construction_Point_Pointer);

     Manager_Builder.Receive_Data_Type_Include_File_Name(Data_Type_Header_File_Pointer);

     Manager_Builder.Build_Memory_Manager();

     delete [] Data_Type_Name;

     delete [] Construction_Point_Pointer;

     delete [] Entered_Class_Name_Pointer;

     delete [] Data_Type_Header_File_Pointer;

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
