
#include <iostream>
#include <cstring>
#include "DirectoryOperations.h"
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"

int main(){

    char Directory [] = "NewDirectory";

    DirectoryOperations DirectoryManager;

    Cpp_FileOperations FileManager;

    DirectoryManager.DetermineCurrentDirectory();

    char * CurrentDirectory = DirectoryManager.GetCurrentlyWorkingDirectory();

    std::cout << "\n Current Directory :" << CurrentDirectory;

    DirectoryManager.ChangeDirectory(CurrentDirectory);

    std::cin.get();

    DirectoryManager.MakeSubDirectory(Directory);

    std::cout << "\n Directory has been created..";

    DirectoryManager.GoToSubDirectory(Directory);

    DirectoryManager.DetermineCurrentDirectory();

    std::cout << "\n Current Directory :"

         << DirectoryManager.GetCurrentlyWorkingDirectory() << "\n";


    DirectoryManager.RecordCurrentDirectoryPATH();

    IntToCharTranslater Translater;

    int File_Number = 10;

    char File_Name [] = "TestFile_";

    int file_name_size = strlen(File_Name);

    char ** File_List = new char * [5*File_Number];

    for(int i=0;i<File_Number;i++){

        char * File_Number_Add = Translater.Translate(i);

        File_List[i] = new char [5*file_name_size];

        for(int k=0;k<file_name_size;k++){

           File_List[i][k] = File_Name[k];
        }

        File_List[i][file_name_size] = *File_Number_Add;

        File_List[i][file_name_size+1] = '\0';
    }

    for(int i=0;i<File_Number;i++){

        std::cout << "\n File Name:" << File_List[i];
    }

    for(int i=0;i<File_Number;i++){

        FileManager.SetFilePath(File_List[i]);

        FileManager.FileOpen(RWCf);

        FileManager.WriteToFile("\n\n HELLO WORLD ..");

        FileManager.FileClose();
    }

    DirectoryManager.GoToUpperDirectory();

    DirectoryManager.DetermineCurrentDirectory();

    std::cout << "\n Current Directory :"

         << DirectoryManager.GetCurrentlyWorkingDirectory() << "\n";

    DirectoryManager.ReturnRecordedDirectoryPATH();

    DirectoryManager.DetermineCurrentDirectory();


    std::cout << "\n Current Directory :"

         << DirectoryManager.GetCurrentlyWorkingDirectory() << "\n";

    char Target_Directory [] = "D:\\DirectoryOperations\\NewDirectory";

    DirectoryManager.Determine_File_List_In_Directory(Target_Directory);

    int File_Number_In_Directory = DirectoryManager.Get_File_Number_In_Directory();

    std::string * File_List_In_Directory = DirectoryManager.Get_File_List_In_Directory();

    for(int i=0;i<File_Number_In_Directory;i++){

        std::cout << "\n File name -" << i << "=" << File_List_In_Directory[i];
    }

    char Target_File_Name [] =  "TestFile_1";

    bool is_there_file

          = DirectoryManager.Search_File_in_Directory(Target_Directory,Target_File_Name);

    if(is_there_file){

       std::cout << "\n\n That file exists in that location..";
    }

    std::cin.get();

    DirectoryManager.Remove_Directory_Recursively(Target_Directory);

    for(int i=0;i<File_Number;i++){

        delete [] File_List[i];
    }

    delete [] File_List;

    std::cout << "\n\n The end of the program \n\n";

    return 0;
}
