
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

#include "Cpp_FileOperations.h"

Cpp_FileOperations::Cpp_FileOperations(){

     this->File_line_Number = 0;

   // Constructor Function
};

Cpp_FileOperations::Cpp_FileOperations(const Cpp_FileOperations & orig){

   // Copy Constructor
};

Cpp_FileOperations::~Cpp_FileOperations(){

    // Destructor Function
};

void Cpp_FileOperations::SetFilePath(std::string FilePATH){

     this->isFilePathReceive = true;

     this->FilePath = "";

     int Name_Size = FilePATH.length();

     for(int i=0;i<Name_Size;i++){

         this->FilePath.append(1,FilePATH[i]) ;
     }

     this->FilePath.append(1,'\0');
}

void Cpp_FileOperations::SetFilePath(const char * String){

     this->isFilePathReceive = true;

     this->FilePath = "";

     int String_Size = strlen(String);

     for(int i=0;i<String_Size;i++){

         this->FilePath.append(1,String[i]);
     }
}

void Cpp_FileOperations::SetFilePath(char * String){

     this->isFilePathReceive = true;

     this->FilePath = "";

     int String_Size = strlen(String);

     for(int i=0;i<String_Size;i++){

         this->FilePath.append(1,String[i]);
     }
}

void Cpp_FileOperations::FileOpen(char Open_Mode){

     if(Open_Mode == 'r'){

        this->DataFile.open(this->FilePath,std::ios::in);
     }

     if(Open_Mode == 'w'){

        this->DataFile.open(this->FilePath,std::ios::out);
     }

     if(Open_Mode == 'x'){

        this->DataFile.open(this->FilePath,std::ios::in | std::ios::out);
     }

     if(Open_Mode == 'b'){

        this->DataFile.open(this->FilePath,std::ios::out | std::ios::trunc);
     }

     if(Open_Mode == 'a'){

        this->DataFile.open(this->FilePath,std::ios::out | std::ios::app);
     }

     if(!this->DataFile.is_open()){

        std::cout << "\n The file" << this->FilePath << " can not be opened ..";
     }
}

void Cpp_FileOperations::FileClose(){

     this->DataFile.close();
}

void Cpp_FileOperations::WriteToFile(std::string string_list){

     this->DataFile <<  string_list;
}

void Cpp_FileOperations::WriteToFile(const char * string_list){

     std::string transfer_string;

     int String_Size = strlen(string_list);

     for(int i=0;i<String_Size;i++){

         transfer_string.append(1,string_list[i]);
     }

     this->DataFile << transfer_string;
}


void Cpp_FileOperations::WriteToFile(char * string_list){

     std::string transfer_string;

     int String_Size = strlen(string_list);

     for(int i=0;i<String_Size;i++){

         transfer_string.append(1,string_list[i]);
     }

     this->DataFile << transfer_string;
}

std::string Cpp_FileOperations::ReadLine(){

     this->String_Line = "";

     std::getline(this->DataFile,this->String_Line);

     this->String_Line = this->String_Line + '\0';

     return this->String_Line;
}

std::string Cpp_FileOperations::Read(){

     this->DataFile >> this->string_word;

     return this->string_word;
}

bool Cpp_FileOperations::Control_End_of_File(){

     this->End_Of_File_Condition = false;

     this->End_Of_File_Condition = this->DataFile.eof();

     return this->End_Of_File_Condition;
}

void Cpp_FileOperations::CpFile(char * path, char * target_path){

     this->Determine_Base_File_Size(path);

     this->Receive_File(path);

     this->Record_File(target_path);
}

void Cpp_FileOperations::MoveFile_Win(char * path, char * target_path){

     this->CpFile(path,target_path);

     int test = DeleteFileA(path);

     if(test == 0){

        std::cout << "\n Th file stay in " << path << " can not be removed .." ;

        exit(0);
     }
}

void Cpp_FileOperations::Receive_File(char * path){

     this->File_Index = new char * [5*this->File_line_Number];

     this->SetFilePath(path);

     this->FileOpen(Rf);

     int line_index = 0;

     do{
           std::string string_line = this->ReadLine();

           int line_size = string_line.length();

           this->File_Index[line_index] = new char [5*line_size];

           for(int i=0;i<line_size;i++){

               this->File_Index[line_index][i] = string_line[i];
           }

           this->File_Index[line_index][line_size] = '\0';

           line_index++;

     }while(!this->Control_End_of_File());

     this->FileClose();
}

void Cpp_FileOperations::Determine_Base_File_Size(char * path){

      this->File_line_Number = 0;

      this->SetFilePath(path);

      this->FileOpen(Rf);

      do {

          std::string string_line = this->ReadLine();

          this->File_line_Number++;

     }while(!this->Control_End_of_File());

     this->FileClose();
}

void Cpp_FileOperations::Record_File(char * target_path){

     this->SetFilePath(target_path);

     this->FileOpen(RWCf);

     for(int  i=0;i<this->File_line_Number;i++){

         this->WriteToFile(this->File_Index[i]);

         if(i < (this->File_line_Number-1)){

            this->WriteToFile("\n");
         }
     }

     this->FileClose();
}
