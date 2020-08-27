
 #include "ReportFileBuilder_Writer.h"
 #include <iostream>


 void Place_Information(char ** Pointer, const char * Information, int List_Size){

     for(int i=0;i<List_Size;i++){

         (*Pointer)[i] = Information[i];
     }

     (*Pointer)[List_Size] = '\0';
}

 int main(int argc, char** argv){

     const char * Data_Type = "float";

     int Data_Type_Name_Size = strlen(Data_Type);

     char * Data_Type_Name = new char [5*Data_Type_Name_Size];

     Place_Information(&Data_Type_Name,Data_Type,Data_Type_Name_Size);

     const char * Construction_Point = "/home/erkam/Smart.Pointer.Builder/ReportFileBuilder_HeaderWriter";

     int Construction_Point_Name_Size = strlen(Construction_Point);

     char * Construction_Point_Pointer = new char [5*Construction_Point_Name_Size];

     Place_Information(&Construction_Point_Pointer,Construction_Point,Construction_Point_Name_Size);

     const char * Entered_Class_Name = "SmartPointer";

     int Class_Name_Size = strlen(Entered_Class_Name);

     char * Entered_Class_Name_Pointer = new char [5*Class_Name_Size];

     Place_Information(&Entered_Class_Name_Pointer,Entered_Class_Name,Class_Name_Size);

     ReportFileBuilder_Writer Writer;

     Writer.Receive_Data_Type(Data_Type);

     Writer.Receive_Construction_Point(Construction_Point);

     Writer.Receive_Entered_Class_Name(Entered_Class_Name);

     Writer.Write_ReportFileBuilder();

     delete [] Data_Type_Name;

     delete [] Construction_Point_Pointer;

     delete [] Entered_Class_Name_Pointer;

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
