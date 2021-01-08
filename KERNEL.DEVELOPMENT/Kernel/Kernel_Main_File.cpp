

 #include <cstring>
 #include <iostream>
 #include <windows.h>
 #include <tchar.h>
 #include "Kernel.h"

 int main(int argc, char** argv){

     if(argv[1] == NULL){

        std::cout << "\n\n The usage: Pcynlitx_Kernel.exe <Project File Path>";

        std::cout << "\n\n";

        exit(0);
     }

     size_t Project_File_Path_Name_Size = strlen(argv[1]);

     if(Project_File_Path_Name_Size == 0){

        std::cout << "\n\n The usage: Pcynlitx_Kernel.exe <Project File Path>";

        std::cout << "\n\n";

        exit(0);
     }

     size_t Directory_Name_Size = 0;

     for(size_t i=Project_File_Path_Name_Size;i>0;i--){

         if(argv[1][i] == '\\'){

            Directory_Name_Size = i;

            break;
         }
     }

     size_t Project_File_Name_Size = Project_File_Path_Name_Size - Directory_Name_Size;



     char * Project_File_Directory_Name = new char [5*Project_File_Path_Name_Size];

     char * Project_File_Name = new char [5*Project_File_Name_Size];



     // This is the point for first "\" character from rigth

     // For instance: \ ......\ ..... \ Project_Descriptor_File.txt

     //                             ->  <-

     size_t pro_file_start_point = 0;

     if(Directory_Name_Size!=0){

        pro_file_start_point = Directory_Name_Size+1;
     }
     else{

         pro_file_start_point = 0;
     }


     int index_counter = 0;

     for(size_t i=pro_file_start_point;i<Project_File_Path_Name_Size;i++){

         Project_File_Name[index_counter] = argv[1][i];

         index_counter++;
     }

     Project_File_Name[index_counter] = '\0';


     if(Directory_Name_Size == 0){

        char current_directory [] = ".";

        Directory_Name_Size = strlen(current_directory);

        for(int i=0;i<Directory_Name_Size;i++){

            Project_File_Directory_Name[i] = current_directory[i];
        }
     }
     else{
            for(int i=0;i<Directory_Name_Size;i++){

                Project_File_Directory_Name[i] = argv[1][i];
            }
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
