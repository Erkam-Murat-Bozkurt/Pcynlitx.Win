
 #include "Descriptor_File_Reader.h"
 #include "CFileOperations.h"
 #include "DirectoryOperations.h"
 #include <cstring>
 #include <iostream>

 int main(int argc, char** argv){

     Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory(argv[1]);

     File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

     File_Reader.Receive_Descriptor_File_Infomations();

     CFileOperations File_Manager;

     DirectoryOperations Directory_Manager;

     char File_Name [] = "/Construction_Point_Holder";

     int Directory_Size = strlen(argv[1]);

     int File_Name_Size = strlen(File_Name);

     int Path_Size = Directory_Size + File_Name_Size;

     char * Construction_Point_File = new char [5*Path_Size];

     for(int i= 0;i<Path_Size;i++){

         Construction_Point_File[i] = '\0';
     }

     int index_counter = 0;

     for(int i=0;i<Directory_Size;i++){

         Construction_Point_File[index_counter] = argv[1][i];

         index_counter++;
     }

     if(Construction_Point_File[index_counter] == '/'){

        index_counter--;
     }

     for(int i=0;i<File_Name_Size;i++){

         Construction_Point_File[index_counter] = File_Name[i];

         index_counter++;
     }

     Construction_Point_File[index_counter] = '\0';

     Directory_Manager.ChangeDirectory(argv[1]);

     File_Manager.SetFilePath(Construction_Point_File);

     File_Manager.FileOpen(RWC);

     File_Manager.WriteToFile(File_Reader.Get_Construction_Point());

     File_Manager.FileClose();

     File_Manager.Clear_Dynamic_Memory();

     Directory_Manager.Clear_Dynamic_Memory();

     delete [] Construction_Point_File;

     std::cout << File_Reader.Get_Executable_File_Name() << std::endl;

     return 0;
 };
