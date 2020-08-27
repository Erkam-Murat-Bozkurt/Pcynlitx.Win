
#include <iostream>
#include <cstring>
#include <string>
#include "Cpp_FileOperations.h"

 int main(int argc, char ** argv){

     Cpp_FileOperations FileManager;

     FileManager.SetFilePath(argv[1]);

     FileManager.FileOpen(Rf);

     int File_Lenght = 0;

     while(!FileManager.Control_End_of_File()){

           FileManager.ReadLine();

           File_Lenght++;
     }

     FileManager.FileClose();

     FileManager.FileOpen(Rf);

     File_Lenght = File_Lenght/2;

     char ** data_pointer = new char * [2*File_Lenght];

     char new_line [] = {'\n',' ','\0'};

     for(int i=0;i<File_Lenght;i++){

         std::string string_line = FileManager.ReadLine();

         int string_length = string_line.length();

         int new_line_size = strlen(new_line);

         int data_size = string_length + new_line_size;

         data_pointer[i] = new char [2*data_size];

         int index_counter = 0;

         for(int j=0;j<new_line_size;j++){

             data_pointer[i][index_counter] = new_line[j];

             index_counter++;
         }

         for(int j=0;j<string_length;j++){

             data_pointer[i][index_counter] = string_line[j];

             index_counter++;
         }

         data_pointer[i][index_counter] = '\0';

     }

     FileManager.FileClose();

     FileManager.SetFilePath("TestFile");

     FileManager.FileOpen(RWCf);

     for(int i=0;i<File_Lenght;i++){

         FileManager.WriteToFile(data_pointer[i]);
     }

     FileManager.FileClose();

     for(int i=0;i<File_Lenght;i++){

         delete [] data_pointer[i];
     }

     delete [] data_pointer;

     return 0;

  }
