
/*

Copyright ©  2019,  Erkam Murat Bozkurt

This file is part of the research project which is carried by Erkam Murat Bozkurt.

This is a free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation
either version 3 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include "DirectoryOperations.h"
#include <iostream>

DirectoryOperations::DirectoryOperations(){

     this->CurrentDirectory = nullptr;

     this->Sub_Directory = nullptr;

     this->Upper_Directory = nullptr;

     this->RecordDirectoryPATH = nullptr;

     this->SystemCommand = nullptr;

     this->File_List = nullptr;

     this->Memory_Delete_Condition = false;

     this->ReturnCondition = 0;

     this->File_Number = 0;
};

DirectoryOperations::DirectoryOperations(const DirectoryOperations & orig){

};

DirectoryOperations::~DirectoryOperations(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
};

void DirectoryOperations::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->CurrentDirectory != nullptr){

            delete [] this->CurrentDirectory;

            this->CurrentDirectory = nullptr;
         }

         if(this->Sub_Directory != nullptr){

            delete [] this->Sub_Directory;

            this->Sub_Directory = nullptr;
         }

         if(this->Upper_Directory != nullptr){

            delete [] this->Upper_Directory;

            this->Upper_Directory = nullptr;
         }

         if(this->RecordDirectoryPATH != nullptr){

            delete [] this->RecordDirectoryPATH;

            this->RecordDirectoryPATH = nullptr;
         }

         if(this->SystemCommand != nullptr){

            delete [] this->SystemCommand;

            this->SystemCommand = nullptr;
         }

         if(this->File_List != nullptr){

            delete [] this->File_List;
         }
     }
}

void DirectoryOperations::DetermineCurrentDirectory(){

     if(this->CurrentDirectory != nullptr){

         delete [] this->CurrentDirectory;

         this->CurrentDirectory = nullptr;
     }

     CHAR Buffer[BUFSIZE];

     GetCurrentDirectory(BUFSIZE, Buffer);

     char * Directory = Buffer;

     int Directory_Name_Size = strlen(Directory);

     this->Memory_Delete_Condition = false;

     this->CurrentDirectory = new char [5*Directory_Name_Size];

     this->Place_String(&this->CurrentDirectory,Directory,Directory_Name_Size);
}

void DirectoryOperations::DetermineSubDirectoryName(char * DirectoryName){

     if(this->Sub_Directory != nullptr){

        delete [] this->Sub_Directory;

        this->Sub_Directory = nullptr;
     }

     this->DetermineCurrentDirectory();

     char Directory_Character [] {'\\','\0'};

     int CurrentDirectory_Name_Size = strlen(this->GetCurrentlyWorkingDirectory());

     int SubDirectory_Name_Size = strlen(DirectoryName);

     int NewDirectory_Name_Size = CurrentDirectory_Name_Size + SubDirectory_Name_Size;

     this->Memory_Delete_Condition = false;

     this->Sub_Directory  = new char [5*NewDirectory_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->Sub_Directory,this->GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Sub_Directory,Directory_Character,&index_counter);

     this->Place_Information(&this->Sub_Directory,DirectoryName,&index_counter);

     this->Sub_Directory[index_counter] = '\0';
}

void DirectoryOperations::DetermineUpperDirectoryName(){

     if(this->Upper_Directory != nullptr){

        delete [] this->Upper_Directory;

        this->Upper_Directory = nullptr;
     }

     this->DetermineCurrentDirectory();

     int CurrentDirectory_Name_Size = strlen(this->GetCurrentlyWorkingDirectory());

     int upper_directory_point = CurrentDirectory_Name_Size;

     for(int i=CurrentDirectory_Name_Size;i>0;i--){

          if(this->GetCurrentlyWorkingDirectory()[i] == '\\'){

             break;
          }
          else{

              upper_directory_point--;
          }
     }

     upper_directory_point++;

     this->Memory_Delete_Condition = false;

     this->Upper_Directory = new char [5*upper_directory_point];

     this->Place_String(&this->Upper_Directory,this->GetCurrentlyWorkingDirectory(),upper_directory_point);
}

int DirectoryOperations::MakeSubDirectory(char * DirectoryName){

     this->DetermineSubDirectoryName(DirectoryName);

     this->ReturnCondition = this->MakeDirectory(this->GetSubDirectoryName());

     if(this->ReturnCondition == -1){

         this->RemoveSubDirectory(DirectoryName);

         this->ReturnCondition = this->MakeDirectory(this->GetSubDirectoryName());
     }

     return this->ReturnCondition;
}

int DirectoryOperations::RemoveSubDirectory(char * DirectoryName){

     this->DetermineSubDirectoryName(DirectoryName);

     this->ReturnCondition = this->RemoveDirectory(this->GetSubDirectoryName());

     if(this->ReturnCondition == -1){

        this->Remove_Directory_Recursively(DirectoryName);
     }

     return this->ReturnCondition;
}

int DirectoryOperations::MakeDirectory(char * path){

    this->ReturnCondition = CreateDirectoryA(path,NULL);

    return this->ReturnCondition;
};

int DirectoryOperations::ChangeDirectory(char * path){

    this->DetermineCurrentDirectory();

    char * CurrentDirectory = this->GetCurrentlyWorkingDirectory();

    std::string CurrentDirectory_String;

    std::string TargetDirectory_String;

    int CurrentDirectory_Size = strlen(CurrentDirectory);

    for(int i=0;i<CurrentDirectory_Size;i++){

        CurrentDirectory_String.append(1,CurrentDirectory[i]);
    }

    CurrentDirectory_String.append(1,'\0');

    int TargetDirectory_Size = strlen(path);

    for(int i=0;i<TargetDirectory_Size;i++){

       TargetDirectory_String.append(1,path[i]);
    }

    TargetDirectory_String.append(1,'\0');

    this->ReturnCondition = 0;

    if(TargetDirectory_String != CurrentDirectory_String){

       this->ReturnCondition = SetCurrentDirectory(path);
    }

    return this->ReturnCondition;
};

int DirectoryOperations::RemoveDirectory(char * path){

    this->Remove_Directory_Recursively(path);

    return this->ReturnCondition;
};

int DirectoryOperations::GoToUpperDirectory(){

    this->DetermineUpperDirectoryName();

    this->ReturnCondition = this->ChangeDirectory(this->GetUpperDirectoryName());

    return this->ReturnCondition;
};

int DirectoryOperations::GoToSubDirectory(char * DirectoryName){

     this->DetermineSubDirectoryName(DirectoryName);

     this->ReturnCondition = this->ChangeDirectory(this->GetSubDirectoryName());

     return this->ReturnCondition;
};

void DirectoryOperations::LoadSystemFunctionCommand(char * Command,char * DirectoryName){

     if(this->SystemCommand != nullptr){

        delete [] this->SystemCommand;

        this->SystemCommand = nullptr;
     }

     int command_name_size   = strlen(Command);

     int Directory_Name_Size = strlen(DirectoryName);

     int System_Command_Name_Size = Directory_Name_Size + command_name_size;

     this->Memory_Delete_Condition = false;

     this->SystemCommand = new char [10*System_Command_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->SystemCommand,Command,&index_counter);

     this->Place_Information(&this->SystemCommand,DirectoryName,&index_counter);

     this->SystemCommand[index_counter] = '\0';
}

void DirectoryOperations::RecordCurrentDirectoryPATH(){

     if(this->RecordDirectoryPATH != nullptr){

        delete [] this->RecordDirectoryPATH;

        this->RecordDirectoryPATH = nullptr;
     }

     this->DetermineCurrentDirectory();

     int Name_Size = strlen(this->GetCurrentlyWorkingDirectory());

     this->Memory_Delete_Condition = false;

     this->RecordDirectoryPATH = new char [5*Name_Size];

     this->Place_String(&this->RecordDirectoryPATH,this->GetCurrentlyWorkingDirectory(),Name_Size);
}

void DirectoryOperations::ReturnRecordedDirectoryPATH(){

     int return_condition = this->ChangeDirectory(this->GetRecordedDirectoryPATH());

     if(return_condition == -1){

        std::cout << "\n The directory can not be change ..";
     }
}

void DirectoryOperations::Determine_File_List_In_Directory(char * Directory_Name){

     this->Memory_Delete_Condition = false;

     if(this->File_List != nullptr){

        delete [] this->File_List;

        this->File_List = nullptr;
     }


     this->File_Number = 0;

     WIN32_FIND_DATA ffdn;

     ffdn.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;

     HANDLE hFindn = INVALID_HANDLE_VALUE;

     size_t dir_name_length = strlen(Directory_Name);

     TCHAR dir_name[MAX_PATH];

     int index = 0;

     for(size_t k=0;k<dir_name_length;k++){

        dir_name[index] = Directory_Name[k];

        index++;
     }

     dir_name[index] = '\\';

     index++;

     dir_name[index] = '*';

     index++;

     size_t next_start = index;

     for(size_t k=next_start;k<MAX_PATH;k++){

         dir_name[index] = '\0';

         index++;
     }

     // Find the first file in the directory.

     hFindn = FindFirstFile(dir_name,&ffdn);

     if (INVALID_HANDLE_VALUE == hFindn)
     {
         std::cout << "\n Error in DirectoryOperations::Determine_File_List_In_Directory";
     }

     // List all the files in the directory with some info about them.

     do{
          if (ffdn.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
          {
            //std::cout << "\n this is a directory..";
          }
          else
          {
             this->File_Number++;
          }
     }
     while (FindNextFile(hFindn,&ffdn) != 0);

     FindClose(hFindn);


     if( this->File_Number > 0 ){

         this->File_List = new std::string [5*this->File_Number];

         size_t index_counter = 0;

         WIN32_FIND_DATA ffd;

         ffd.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;

         HANDLE hFind = INVALID_HANDLE_VALUE;


         hFind = FindFirstFile(dir_name, &ffd);

         if (INVALID_HANDLE_VALUE == hFind)
         {
                std::cout << "\n Error in DirectoryOperations::Determine_File_List_In_Directory";
         }

         // List all the files in the directory with some info about them.

         do{
              if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
              {
                   // _tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
              }
              else{

                    char * File_Name = ffd.cFileName;

                    size_t file_name_size = strlen(File_Name);

                    this->File_List[index_counter] = "";

                    for(size_t i=0;i<file_name_size;i++){

                        this->File_List[index_counter].append(1,File_Name[i]) ;
                    }

                    this->File_List[index_counter].append(1,'\0');

                    index_counter++;
              }
          }
          while (FindNextFile(hFind, &ffd) != 0);

          FindClose(hFind);
     }
}


bool DirectoryOperations::Search_File_in_Directory(char * Director_Name, char * File_Name){

     this->Determine_File_List_In_Directory(Director_Name);

     size_t file_name_size = strlen(File_Name);

     std::string File_Name_String = "";

     for(size_t i=0;i<file_name_size;i++){

         File_Name_String.append(1,File_Name[i]);
     }

     File_Name_String.append(1,'\0');

     this->File_Exist_Condition = false;

     int File_Number = this->Get_File_Number_In_Directory();

     for(int i=0;i<File_Number;i++){

         if(File_Name_String == this->Get_File_List_In_Directory()[i]){

            this->File_Exist_Condition = true;

            break;
         }
     }

     return this->File_Exist_Condition;
}


void DirectoryOperations::Remove_Directory_Recursively(char * Directory_Name){

     this->Determine_File_List_In_Directory(Directory_Name);

     int File_Number = this->Get_File_Number_In_Directory();

     int Directory_Name_Size = strlen(Directory_Name);

     char Directory_Character [] = {'\\','\0'};

     char * File_Name = nullptr;

     char * File_Path = nullptr;

     for(int i=0;i<File_Number;i++){

         std::string File_Name_String = this->Get_File_List_In_Directory()[i];

         int File_Name_String_Size = File_Name_String.length();

         File_Name = new char [5*File_Name_String_Size];

         for(int k=0;k<File_Name_String_Size;k++){

             File_Name[k] = File_Name_String[k];
         }

         File_Name[File_Name_String_Size] = '\0';

         int File_Path_Size = File_Name_String_Size + Directory_Name_Size;

         File_Path = new char [5*File_Path_Size];

         int index_counter = 0;

         this->Place_Information(&File_Path,Directory_Name,&index_counter);

         this->Place_Information(&File_Path,Directory_Character,&index_counter);

         this->Place_Information(&File_Path,File_Name,&index_counter);

         File_Path[index_counter] = '\0';

         this->Delete_File(File_Path);

         delete [] File_Path;

         delete [] File_Name;
     }

     this->Delete_File(Directory_Name);
}

void DirectoryOperations::Delete_File(char * path){

     int path_length = strlen(path);

     TCHAR * path_pointer = new TCHAR[5*path_length];

     for(int i=0;i<path_length;i++){

         path_pointer[i] = path[i];
     }

     path_pointer[path_length] = '\0';

     path_pointer[path_length+1] = '\0';

     SHFILEOPSTRUCT fileop;

     fileop.wFunc = FO_DELETE;

     fileop.pFrom = path_pointer;

     fileop.pTo = NULL;

     fileop.hwnd = NULL;

     fileop.fFlags = FOF_FILESONLY | FOF_NOCONFIRMATION;

     this->ReturnCondition = SHFileOperationA(&fileop);

     if(this->ReturnCondition != 0) {

        std::cout << "\n The file can not be removed ..";
     }

     delete [] path_pointer;
}

std::string * DirectoryOperations::Get_File_List_In_Directory(){

    return this->File_List;
}

int DirectoryOperations::Get_File_Number_In_Directory(){

   return this->File_Number;
}

void DirectoryOperations::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void DirectoryOperations::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

        (*Pointer)[(*index_counter)] = Information[i];

        (*index_counter)++;
     }
}

void DirectoryOperations::Place_Information(char ** Pointer, const char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

        (*Pointer)[(*index_counter)] = Information[i];

        (*index_counter)++;
     }
}

char * DirectoryOperations::GetCurrentlyWorkingDirectory(){

       this->DetermineCurrentDirectory();

       return this->CurrentDirectory;
}

char * DirectoryOperations::GetRecordedDirectoryPATH(){

       return this->RecordDirectoryPATH;
}

char * DirectoryOperations::GetSystemFunctionCommand(){

       return this->SystemCommand;
}

char * DirectoryOperations::GetSubDirectoryName(){

       return this->Sub_Directory;
}

char * DirectoryOperations::GetUpperDirectoryName(){

       return this->Upper_Directory;
}
