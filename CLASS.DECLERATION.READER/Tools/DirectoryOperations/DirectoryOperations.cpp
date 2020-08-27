
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

     char * Directory = get_current_dir_name();

     int Directory_Name_Size = strlen(Directory);

     this->Memory_Delete_Condition = false;

     this->CurrentDirectory = new char [10*Directory_Name_Size];

     this->Place_String(&this->CurrentDirectory,Directory,Directory_Name_Size);

     free(Directory);
}

void DirectoryOperations::DetermineSubDirectoryName(char * DirectoryName){

     if(this->Sub_Directory != nullptr){

        delete [] this->Sub_Directory;

        this->Sub_Directory = nullptr;
     }

     this->DetermineCurrentDirectory();

     char Directory_Character [] {'/','\0'};

     int CurrentDirectory_Name_Size = strlen(this->GetCurrentlyWorkingDirectory());

     int SubDirectory_Name_Size = strlen(DirectoryName);

     int NewDirectory_Name_Size = CurrentDirectory_Name_Size + SubDirectory_Name_Size;

     this->Memory_Delete_Condition = false;

     this->Sub_Directory  = new char [10*NewDirectory_Name_Size];

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

          if(this->GetCurrentlyWorkingDirectory()[i] == '/'){

             break;
          }
          else{

              upper_directory_point--;
          }
     }

     this->Memory_Delete_Condition = false;

     this->Upper_Directory = new char [10*upper_directory_point];

     this->Place_String(&this->Upper_Directory,this->GetCurrentlyWorkingDirectory(),upper_directory_point);
}

int DirectoryOperations::MakeSubDirectory(char * DirectoryName,mode_t mode){

     this->DetermineSubDirectoryName(DirectoryName);

     this->ReturnCondition = this->MakeDirectory(this->GetSubDirectoryName(),mode);

     if(this->ReturnCondition == -1){

         this->RemoveSubDirectory(DirectoryName);

         this->ReturnCondition = this->MakeDirectory(this->GetSubDirectoryName(),mode);
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


int DirectoryOperations::ChangeDirectoryMode(const char * path, mode_t mode){

    this->ReturnCondition = chmod(path,mode);

    return this->ReturnCondition;
};

int DirectoryOperations::MakeDirectory(const char * path, mode_t mode){

    this->ReturnCondition = mkdir(path,mode);

    return this->ReturnCondition;
};

int DirectoryOperations::ChangeDirectory(const char * path){

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

       this->ReturnCondition = chdir(path);
    }

    return this->ReturnCondition;
};

int DirectoryOperations::RemoveDirectory(const char * path){

     this->ReturnCondition = rmdir(path);

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

void DirectoryOperations::LoadSystemFunctionCommand(const char * Command,char * DirectoryName){

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

     this->RecordDirectoryPATH = new char [10*Name_Size];

     this->Place_String(&this->RecordDirectoryPATH,this->GetCurrentlyWorkingDirectory(),Name_Size);
}

void DirectoryOperations::ReturnRecordedDirectoryPATH(){

     int return_condition = this->ChangeDirectory(this->GetRecordedDirectoryPATH());

     if(return_condition == -1){

        std::cout << "\n The directory can not be change ..";
     }
}

void DirectoryOperations::Determine_File_List_In_Directory(char * Director_Name){

     this->Memory_Delete_Condition = false;

     DIR *d;

     struct dirent *dir;

     if(this->File_List != nullptr){

        delete [] this->File_List;
     }

     this->File_Number = 0;

     d = opendir(Director_Name);

     if (d){

         while ((dir = readdir(d)) != NULL)
          {

              this->File_Number++;
          }

          closedir(d);
     }

     this->File_List = new std::string [10*this->File_Number];

     int index_counter = 0;

     d = opendir(Director_Name);

     if (d){

          while ((dir = readdir(d)) != NULL)
          {

              int file_name_size = strlen(dir->d_name);

              char * File_Name = dir->d_name;

              for(int i=0;i<file_name_size;i++){

                  this->File_List[index_counter].append(1,File_Name[i]) ;
              }

              this->File_List[index_counter].append(1,'\0');

              index_counter++;
          }

          closedir(d);
       }
}

bool DirectoryOperations::Search_File_in_Directory(char * Director_Name, char * File_Name){

     this->Determine_File_List_In_Directory(Director_Name);

     int file_name_size = strlen(File_Name);

     std::string File_Name_String;

     for(int i=0;i<file_name_size;i++){

         File_Name_String.append(1,File_Name[i]) ;
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

     char Directory_Character [] = {'/','\0'};

     for(int i=0;i<File_Number;i++){

         std::string File_Name_String = this->Get_File_List_In_Directory()[i];

         int File_Name_String_Size = File_Name_String.length();

         char * File_Name = new char [10*File_Name_String_Size];

         for(int k=0;k<File_Name_String_Size;k++){

             File_Name[k] = File_Name_String[k];
         }

         File_Name[File_Name_String_Size] = '\0';

         int File_Path_Size = File_Name_String_Size + Directory_Name_Size;

         char * File_Path = new char [10*File_Path_Size];

         int index_counter = 0;

         this->Place_Information(&File_Path,Directory_Name,&index_counter);

         this->Place_Information(&File_Path,Directory_Character,&index_counter);

         this->Place_Information(&File_Path,File_Name,&index_counter);

         File_Path[index_counter] = '\0';

         unlink(File_Path);

         delete [] File_Path;

         delete [] File_Name;
     }

     this->RemoveDirectory(Directory_Name);
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
