
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

#include "Library_Updater.h"

Library_Updater::Library_Updater(){

    this->Memory_Delete_Condition = false;

    this->Object_File_List = nullptr;

    this->Archive_Build_Command = nullptr;
}

Library_Updater::Library_Updater(const Library_Updater & orig){

}

Library_Updater::~Library_Updater(){

    if(!this->Memory_Delete_Condition){

       this->Clear_Dynamic_Memory();
    }
}

void Library_Updater::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Object_File_List != nullptr){

            delete [] this->Object_File_List;

            this->Object_File_List = nullptr;
         }

         if(this->Archive_Build_Command != nullptr){

            delete [] this->Archive_Build_Command;

            this->Archive_Build_Command = nullptr;
         }
     }
}

void Library_Updater::Build_Library(char * Object_Files_Directory, char * Library_Name){

     this->Clear_Dynamic_Memory();

     this->Memory_Delete_Condition = false;

     DIR *d;

     struct dirent *dir;

     int list_character_size = 0;

     d = opendir(Object_Files_Directory);

     if (d){

        while ((dir = readdir(d)) != NULL)
        {

            int file_name_size = strlen(dir->d_name);

            char * name = dir->d_name;

            if(((name[file_name_size-1] == 'o') && (name[file_name_size-2] == '.'))){

                list_character_size = list_character_size + file_name_size;
            }
        }

        closedir(d);
     }

     char Space_Character [] = {' ','\0'};

     this->Object_File_List = new char [5*list_character_size];

     int index_counter = 0;

     d = opendir(Object_Files_Directory);

     if (d){

        while ((dir = readdir(d)) != NULL)
        {

            int file_name_size = strlen(dir->d_name);

            char * name = dir->d_name;

            if(((name[file_name_size-1] == 'o') && (name[file_name_size-2] == '.'))){

                this->Place_Information(&this->Object_File_List,name,&index_counter);

                this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);
            }
        }

        this->Object_File_List[index_counter] = '\0';

        closedir(d);
     }

     char Library_Construction_Command [] = {'a','r',' ','r','s',' ','l','i','b','\0'};

     char Library_Add_word [] = {'.','a','\0'};

     index_counter = 0; // Reset index counter value

     int Object_File_List_Character_Size = strlen(this->Object_File_List);

     this->Archive_Build_Command = new char [2*Object_File_List_Character_Size];

     this->Place_Information(&this->Archive_Build_Command,Library_Construction_Command,&index_counter);

     this->Place_Information(&this->Archive_Build_Command,Library_Name,&index_counter);

     this->Place_Information(&this->Archive_Build_Command,Library_Add_word,&index_counter);

     this->Place_Information(&this->Archive_Build_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Archive_Build_Command,this->Object_File_List,&index_counter);

     this->Archive_Build_Command[index_counter-1] = '\0';

     chdir(Object_Files_Directory);

     system(this->Archive_Build_Command);
}

void Library_Updater::Send_Library_New_Location(char * Object_Files_Directory, char * New_Location, char * Library_Name){

     int Library_Name_Size = strlen(Library_Name);

     char library_prefix [] = {'l','i','b','\0'};

     char library_subfix [] = {'.','a','\0'};

     char * Library_File_Name = new char [5*Library_Name_Size];

     int index_counter = 0;

     this->Place_Information(&Library_File_Name,library_prefix,&index_counter);

     this->Place_Information(&Library_File_Name,Library_Name,&index_counter);

     this->Place_Information(&Library_File_Name,library_subfix,&index_counter);

     Library_File_Name[index_counter] = '\0';

     char Directory_Character [] = {'/','\0'};

     char * Current_Directory = get_current_dir_name();

     int Directory_Name_Size = strlen(Current_Directory);

     char * Current_Library_Path = new char [5*Directory_Name_Size];

     index_counter = 0;

     this->Place_Information(&Current_Library_Path,Current_Directory,&index_counter);

     this->Place_Information(&Current_Library_Path,Directory_Character,&index_counter);

     this->Place_Information(&Current_Library_Path,Library_File_Name,&index_counter);

     Current_Library_Path[index_counter] = '\0';

     char * Target_Library_Path = new char [5*Directory_Name_Size];

     index_counter = 0;

     this->Place_Information(&Target_Library_Path,New_Location,&index_counter);

     this->Place_Information(&Target_Library_Path,Directory_Character,&index_counter);

     this->Place_Information(&Target_Library_Path,Library_File_Name,&index_counter);

     Target_Library_Path[index_counter] = '\0';

     unlink(Target_Library_Path);

     link(Current_Library_Path,Target_Library_Path);

     unlink(Current_Library_Path);

     free(Current_Directory);

     delete [] Current_Library_Path;

     delete [] Target_Library_Path;

     delete [] Library_File_Name;
}

void Library_Updater::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int String_Size = strlen(Information);

     for(int i=0;i<String_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
 }
