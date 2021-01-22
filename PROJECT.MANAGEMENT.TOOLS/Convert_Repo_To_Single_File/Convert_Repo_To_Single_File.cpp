

/*

Copyright ©  2021,  Erkam Murat Bozkurt

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

#include "Document_Builder.h"

Convert_Repo_To_Single_File::Convert_Repo_To_Single_File(){

     this->Memory_Delete_Condition = true;

     this->Repo_Directory_Receive_Status = false;

     this->Repo_Directory = nullptr;

     this->System_Call = nullptr;

     this->File_List_Content = nullptr;

     this->File_Line_Number = 0;
}

Convert_Repo_To_Single_File::Convert_Repo_To_Single_File(const Convert_Repo_To_Single_File & orig){


}

Convert_Repo_To_Single_File::~Convert_Repo_To_Single_File(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
}

void Convert_Repo_To_Single_File::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->System_Call != nullptr){

            delete [] this->System_Call;

            this->System_Call = nullptr;
         }

         if(this->Repo_Directory != nullptr){

            delete [] this->Repo_Directory;

            this->Repo_Directory = nullptr;
         }

         if(this->File_List_Content != nullptr){

            delete [] this->File_List_Content;

            this->File_List_Content = nullptr;
         }

         this->FileManager.Clear_Dynamic_Memory();

         this->DirectoryManager.Clear_Dynamic_Memory();
     }
}

void Convert_Repo_To_Single_File::Receive_Repo_Directory(char * Directory){

    if(*Directory != '\0'){

       this->Memory_Delete_Condition = false;

       this->Repo_Directory_Receive_Status = true;

       this->Place_String(&this->Repo_Directory,Directory);
    }
    else{
           std::cout << "\n\n ERROR:";

           std::cout << "\n Inside Convert_Repo_To_Single_File class";

           std::cout << "\n A valid directory name must be entered..";

           std::cout << "\n\n";

           exit(0);
    }
}

void Convert_Repo_To_Single_File::List_Files_in_Repo(){

     char repo_list_file [] = "repo_files.txt";

     if(this->FileManager.Is_Path_Exist(repo_list_file)){

        this->FileManager.Delete_File(repo_list_file);
     }

     char Listing_Command [] = "git ls-files > repo_files.txt";

     this->DirectoryManager.ChangeDirectory(this->Repo_Directory);

     int system_return_value = system(Listing_Command);
}

void Convert_Repo_To_Single_File::Determine_File_Size(){

     this->File_Line_Number = 0;

     char Repo_File_List [] = "repo_files.txt";

     this->FileManager.SetFilePath(Repo_File_List);

     this->FileManager.FileOpen(Rf);

     do {

          std::string string_line = this->FileManager.ReadLine();

          this->File_Line_Number++;

     }while(!this->FileManager.Control_End_of_File());

     this->FileManager.FileClose();
}

void Convert_Repo_To_Single_File::Allocate_Memory_For_Reading(){

     this->File_List_Content = new std::string [10*this->File_Line_Number];
}

void Convert_Repo_To_Single_File::Read_File(){

     char Repo_File_List [] = "repo_files.txt";

     this->FileManager.SetFilePath(Repo_File_List);

     this->FileManager.FileOpen(Rf);

     int index = 0;

     do {

          this->File_List_Content[index] = this->FileManager.ReadLine();

          this->File_List_Content[index] = this->File_List_Content[index] + "\n";

          index++;

     }while(!this->FileManager.Control_End_of_File());

     this->FileManager.FileClose();
}

void Convert_Repo_To_Single_File::Construct_Source_File(){

     if(this->Repo_Directory_Receive_Status){

        this->List_Files_in_Repo();

        this->Determine_File_Size();

        this->Allocate_Memory_For_Reading();

        this->Read_File();

        for(int i=0;i<this->File_Line_Number-1;i++){

            char Document_Name [] = "D:\\PCYNLITX.PROJECT.WINDOWS\\Pcyn.Win.SCode.txt";

            this->Doc_Builder.Receive_Document_Name(Document_Name);

            char * file_path = this->Convert_to_C_String(this->File_List_Content[i]);

            this->Doc_Builder.Receive_File_Path(file_path);

            this->Doc_Builder.Receive_Document_Name(Document_Name);

            this->Doc_Builder.Add_File_To_Document();
        }
     }
}

char * Convert_Repo_To_Single_File::Convert_to_C_String(std::string command){

     if(this->System_Call != nullptr){

        delete [] this->System_Call;

        this->System_Call = nullptr;
     }

     size_t command_length = command.length();

     this->System_Call = new char [5*command_length];

     int index = 0;

     for(size_t i=0;i<command_length;i++){

         this->System_Call[index] = command[i];

         index++;
     }

     this->System_Call[index] = '\0';

     return this->System_Call;
}

void Convert_Repo_To_Single_File::Place_String(char ** Pointer, char * String){

     int String_Size = strlen(String);

     *Pointer = new char [10*String_Size];

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}
