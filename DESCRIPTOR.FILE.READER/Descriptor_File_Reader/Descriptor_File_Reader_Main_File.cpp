
 #include "Descriptor_File_Reader.h"
 #include "Cpp_FileOperations.h"
 #include "DirectoryOperations.h"
 #include <cstring>
 #include <iostream>

 void Print_Descriptions(Descriptor_File_Reader & Reader);

 int main(int argc, char** argv){

     Descriptor_File_Reader File_Reader;

     if(argc != 2){

        std::cout << "\n\n The usage: Descriptor_File_Reader <Project Directory> \n\n";

        exit(0);
     }

     File_Reader.Receive_Descriptor_File_Directory(argv[1]);

     File_Reader.Receive_Gui_Read_Status(false);

     File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File.txt");

     File_Reader.Receive_Descriptor_File_Infomations();

     Print_Descriptions(File_Reader);

     Cpp_FileOperations File_Manager;

     DirectoryOperations Directory_Manager;

     char File_Name [] = "\\Construction_Point_Holder";

     size_t Directory_Size = strlen(argv[1]);

     size_t File_Name_Size = strlen(File_Name);

     size_t Path_Size = Directory_Size + File_Name_Size;

     char * Construction_Point_File = new char [5*Path_Size];

     for(size_t i= 0;i<Path_Size;i++){

         Construction_Point_File[i] = '\0';
     }

     int index_counter = 0;

     for(int i=0;i<Directory_Size;i++){

         Construction_Point_File[index_counter] = argv[1][i];

         index_counter++;
     }

     if(Construction_Point_File[index_counter] == '\\'){

        index_counter--;
     }

     for(int i=0;i<File_Name_Size;i++){

         Construction_Point_File[index_counter] = File_Name[i];

         index_counter++;
     }

     Construction_Point_File[index_counter] = '\0';

     Directory_Manager.ChangeDirectory(argv[1]);

     File_Manager.SetFilePath(Construction_Point_File);

     File_Manager.FileOpen(RWCf);

     File_Manager.WriteToFile(File_Reader.Get_Construction_Point());

     File_Manager.FileClose();

     File_Manager.Clear_Dynamic_Memory();

     Directory_Manager.Clear_Dynamic_Memory();

     delete [] Construction_Point_File;

     std::cout << File_Reader.Get_Executable_File_Name() << std::endl;

     Print_Descriptions(File_Reader);

     return 0;
 };


void Print_Descriptions(Descriptor_File_Reader & Reader){

     std::cout << "\n Server Class Name:" << Reader.Get_Server_Class_Name();

     std::cout << "\n Server Class Header File Name:" << Reader.Get_Server_Class_Header_File_Name();

     std::cout << "\n Main File Name:" << Reader.Get_Main_File_Name();

     std::cout << "\n Namespace:" << Reader.Get_Namespace();

     std::cout << "\n Executable File Name:" << Reader.Get_Executable_File_Name();

     std::cout << "\n Construction Point:"   << Reader.Get_Construction_Point();

     std::cout << "\n Include Directory:"    << Reader.Get_Constructed_Include_Directory();

     for(int i=0;i<Reader.Get_Thread_Function_Number();i++){

         std::cout << "\n Function name - " << i << " " << Reader.Get_Thread_Function_Names()[i];
     }

     for(int i=0;i<Reader.Get_Library_Directory_Number();i++){

         std::cout << "\n Library directory name - " << i << " "  << Reader.Get_Library_Directories()[i];
     }

     for(int i=0;i<Reader.Get_Library_Names_Number();i++){

         std::cout << "\n Library name - " << i << " "  << Reader.Get_Library_Names()[i];
     }

     for(int i=0;i<Reader.Get_Source_File_Location_Number();i++){

         std::cout << "\n Source file location - " << i << " "  << Reader.Get_Source_File_Locations()[i];
     }

     for(int i=0;i<Reader.Get_Source_File_Names_Number();i++){

         std::cout << "\n Source file name - " << i << " "  << Reader.Get_Source_File_Names()[i];
     }

     for(int i=0;i<Reader.Get_Header_Files_Number();i++){

         std::cout << "\n Header file name - " << i << " "  << Reader.Get_Header_File_Names()[i];
     }

     for(int i=0;i<Reader.Get_Header_Files_Number();i++){

         std::cout << "\n Header file name - " << i << " "  << Reader.Get_Header_File_Paths()[i];
     }     
}