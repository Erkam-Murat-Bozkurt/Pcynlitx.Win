
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

Document_Builder::Document_Builder(){

     this->Memory_Delete_Condition = true;

     this->File_Path_Receive_Status = false;

     this->Document_Name_Receive_Status = false;

     this->FilePath = nullptr;

     this->Document_Name = nullptr;

     this->File_Content = nullptr;

     this->File_Line_Number = 0;
}

Document_Builder::Document_Builder(const Document_Builder & orig){}

Document_Builder::~Document_Builder(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
}

void Document_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         delete [] this->FilePath;

         delete [] this->Document_Name;

         delete [] this->File_Content;

         this->FileManager.Clear_Dynamic_Memory();
     }
}

void Document_Builder::Receive_File_Path(char * path){

    if(*path != '\0'){

       this->Memory_Delete_Condition = false;

       this->File_Path_Receive_Status = true;

       this->Place_String(&this->FilePath,path);
    }
    else{
           std::cout << "\n\n ERROR:";

           std::cout << "\n A valid file name must be entered..";

           std::cout << "\n\n";

           exit(0);
    }
}

void Document_Builder::Determine_File_Size(){

     this->File_Line_Number = 0;

     this->FileManager.SetFilePath(this->FilePath);

     this->FileManager.FileOpen(Rf);

     do {

          std::string string_line = this->FileManager.ReadLine();

          this->File_Line_Number++;

     }while(!this->FileManager.Control_End_of_File());

     this->FileManager.FileClose();
}

void Document_Builder::Allocate_Memory_For_Reading(){

     this->File_Content = new std::string [10*this->File_Line_Number];
}

void Document_Builder::Receive_Document_Name(char * Name){

     this->Document_Name_Receive_Status = true;

     size_t name_size = strlen(Name);

     this->Document_Name = new char [5*name_size];

     int index = 0;

     for(size_t i=0;i<name_size;i++){

         this->Document_Name[index] = Name[i];

         index++;
     }

     this->Document_Name[index] = '\0';
}

void Document_Builder::Read_File(){

     this->FileManager.SetFilePath(this->FilePath);

     this->FileManager.FileOpen(Rf);

     int index = 0;

     do {

          this->File_Content[index] = this->FileManager.ReadLine();

          this->File_Content[index] = this->File_Content[index] + "\n";

          index++;

     }while(!this->FileManager.Control_End_of_File());

     this->FileManager.FileClose();
}

void Document_Builder::Add_To_Document(){

     this->FileManager.SetFilePath(this->Document_Name);

     this->FileManager.FileOpen(Af);

     std::string file_name = "";

     size_t File_Name_Size = strlen(this->FilePath);

     for(size_t i= 0;i<File_Name_Size;i++){

         file_name.append(1,this->FilePath[i]);
     }

     std::string FileHeader = "\n\nFILE NAME: " + file_name;

     for(int i=0;i<80;i++){

         FileHeader = FileHeader + "-";
     }

     FileHeader = FileHeader + "\n\n";

     this->FileManager.WriteToFile(FileHeader);

     for(int i=0;i<this->File_Line_Number;i++){

         this->FileManager.WriteToFile(this->File_Content[i]);
     }

     std::string File_Footer = "\n\nTHE END OF FILE \n\n";

     this->FileManager.WriteToFile(File_Footer);

     this->FileManager.FileClose();
}

void Document_Builder::Add_File_To_Document(){

     if(this->File_Path_Receive_Status && this->Document_Name_Receive_Status){

        this->FileManager.SetFilePath(this->Document_Name);

        this->FileManager.FileOpen(Af);

        this->FileManager.FileClose();

        this->Determine_File_Size();

        this->Allocate_Memory_For_Reading();

        this->Read_File();

        this->Add_To_Document();
     }
     else{

           std::cout << "\n\n ERROR inside Document_Builder class";

           std::cout << "\n\n       File name can not readed..   ";

           exit(0);
     }
}

void Document_Builder::Place_String(char ** Pointer, char * String){

     int String_Size = strlen(String);

     *Pointer = new char [10*String_Size];

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}
