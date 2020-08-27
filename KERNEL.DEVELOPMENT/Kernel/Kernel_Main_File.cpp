

 #include <cstring>
 #include <iostream>
 #include "Kernel.h"

 int main(int argc, char** argv){

     int Project_File_Path_Name_Size = strlen(argv[1]);

     char * Project_File_Directory_Name = new char [5*Project_File_Path_Name_Size];

     int Directory_Name_Size = 0;

     for(int i=Project_File_Path_Name_Size;i>0;i--){

         if(argv[1][i] == '/'){

            Directory_Name_Size = i;

            break;
         }
     }

     int Project_File_Name_Size = Project_File_Path_Name_Size - Directory_Name_Size;

     char * Project_File_Name = new char [5*Project_File_Name_Size];

     int index_counter = 0;

     for(int i=Directory_Name_Size+1;i<Project_File_Path_Name_Size;i++){

         Project_File_Name[index_counter] = argv[1][i];

         index_counter++;
     }

     Project_File_Name[index_counter] = '\0';

     for(int i=0;i<Directory_Name_Size;i++){

         Project_File_Directory_Name[i] = argv[1][i];
     }

     Project_File_Directory_Name[Directory_Name_Size] = '\0';

     Kernel Factory;

     Factory.Receive_Descriptor_File_Directory(Project_File_Directory_Name);

     Factory.Receive_Descriptor_File_Name(Project_File_Name);

     Factory.Build_Server();

     delete [] Project_File_Directory_Name;

     delete [] Project_File_Name;

     exit(EXIT_SUCCESS);
 };
