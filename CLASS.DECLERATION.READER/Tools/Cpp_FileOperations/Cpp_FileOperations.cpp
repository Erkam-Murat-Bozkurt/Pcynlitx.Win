
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

     this->CString = nullptr;

     this->CString_FilePATH = nullptr;

     this->Memory_Delete_Condition = false;

     this->Delete_Return_Status = 0;

     this->file_open_status = false;

     this->is_path_exist = false;

   // Constructor Function
};

Cpp_FileOperations::Cpp_FileOperations(const Cpp_FileOperations & orig){

   // Copy Constructor
};

Cpp_FileOperations::~Cpp_FileOperations(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }

    // Destructor Function
};

void Cpp_FileOperations::Clear_Dynamic_Memory(){

      if(!this->Memory_Delete_Condition){

          this->Memory_Delete_Condition = true;

          if(this->CString != nullptr){

             delete [] this->CString;

             this->CString = nullptr;
          }

          if(this->CString_FilePATH != nullptr){

             delete [] this->CString_FilePATH;

             this->CString_FilePATH = nullptr;
          }
      }
}

void Cpp_FileOperations::SetFilePath(std::string FilePATH){

     this->isFilePathReceive = true;

     this->FilePath = "";

     int Name_Size = FilePATH.length();

     for(int i=0;i<Name_Size;i++){

         this->FilePath.append(1,FilePATH[i]) ;
     }

     int string_size = this->FilePath.length();

     if(this->CString_FilePATH != nullptr){

        delete [] this->CString_FilePATH;

        this->CString_FilePATH = nullptr;
     }

     int index_counter = 0;

     this->CString_FilePATH = new char [5*string_size];

     for(int i=0;i<string_size;i++){

         this->CString_FilePATH[index_counter] = this->FilePath[i];

         index_counter++;
     }

     this->CString_FilePATH[index_counter] = '\0';
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

     int string_size = this->FilePath.length();

     if(this->CString_FilePATH != nullptr){

        delete [] this->CString_FilePATH;

        this->CString_FilePATH = nullptr;
     }

     int index_counter = 0;

     this->CString_FilePATH = new char [5*string_size];

     for(int i=0;i<string_size;i++){

         this->CString_FilePATH[index_counter] = this->FilePath[i];

         index_counter++;
     }

     this->CString_FilePATH[index_counter] = '\0';
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

          std::cout << "\n ERROR:";

          std::cout << "\n";

          std::cout << "\n Class : Cpp_FileOperations";

          std::cout << "\n";

          std::cout << "\n The file " << this->FilePath << " can not be opened ..";

          std::cout << "\n\n";

          exit(0);
     }
}

bool Cpp_FileOperations::TryOpen(char Open_Mode){

     // This function is used in order to determine whether the file exist or not
;
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

     this->file_open_status = false;

     if(this->DataFile.is_open()){

       this->file_open_status = true;
     }
     else{

          this->file_open_status = false;
     }

     return this->file_open_status;
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

char * Cpp_FileOperations::ReadLine_as_Cstring(){;

       this->ReadLine();

       return this->Conver_Std_String_To_Char(this->String_Line);
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

void Cpp_FileOperations::MoveFile_Win(char * current_path, char * target_path){

     int current_path_length = strlen(current_path);

     TCHAR * current_path_pointer = new TCHAR[5*current_path_length];

     for(int i=0;i<current_path_length;i++){

         current_path_pointer[i] = current_path[i];
     }

     current_path_pointer[current_path_length] = '\0';

     current_path_pointer[current_path_length+1] = '\0';



     int target_path_length = strlen(target_path);

     TCHAR * target_path_pointer = new TCHAR[5*target_path_length];

     for(int i=0;i<target_path_length;i++){

         target_path_pointer[i] = target_path[i];
     }

     target_path_pointer[target_path_length] = '\0';

     target_path_pointer[target_path_length+1] = '\0';


     CopyFile(current_path_pointer,target_path_pointer,false);


     if(this->Is_Path_Exist(current_path)){

        int test = DeleteFileA(current_path);

        if(test == 0){

           std::cout << "\n Th file stay in " << current_path << " can not be removed .." ;

            exit(0);
        }
    }
}

void Cpp_FileOperations::Receive_File(char * path){

     this->Memory_Delete_Condition = true;

     if(this->File_Index != nullptr){

        delete [] this->File_Index;
     }

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

char * Cpp_FileOperations::Conver_Std_String_To_Char(std::string string_line){

       if(this->CString != nullptr){

          delete [] this->CString;
       }

       int string_size = string_line.length();

       this->Memory_Delete_Condition = false;

       this->CString = new char [5*string_size];

       for(int i=0;i<string_size;i++){

           this->CString[i] = string_line[i];
       }

       this->CString[string_size] = '\0';

       return this->CString;
}

bool Cpp_FileOperations::Is_Path_Exist(char * path){

     this->is_path_exist = true;

     struct _stat buf;

     int result = 0;

     result = _stat( path, &buf );

     if( result != 0 ){

       this->is_path_exist = false;
     }

     /*

     this->SetFilePath(path);

     if(this->TryOpen(Rf)){

        this->is_path_exist = true;

        this->FileClose();
     }

     */

     return this->is_path_exist;
}

int Cpp_FileOperations::Delete_File(char * path){

     int path_length = strlen(path);

     TCHAR * path_pointer = new TCHAR[5*path_length];

     for(int i=0;i<path_length;i++){

         path_pointer[i] = path[i];
     }

     path_pointer[path_length] = '\0';

     path_pointer[path_length+1] = '\0';

     if(this->Is_Path_Exist(path_pointer)){

        SHFILEOPSTRUCT fileop;

        fileop.wFunc = FO_DELETE;

        fileop.pFrom = path_pointer;

        fileop.pTo = NULL;

        fileop.hwnd = NULL;

        fileop.fFlags = FOF_FILESONLY | FOF_NOCONFIRMATION;

        this->Delete_Return_Status = SHFileOperationA(&fileop);

        if(this->Delete_Return_Status != 0) {

          std::cout << "\n The file can not be removed ..";
        }
     }
     else{

          std::cout << "\n Error inside Cpp_FileOperations";

          std::cout << "\n Inside Delete_File:";

          std::cout << "\n The file " << path_pointer << " is not exist..";
     }

     delete [] path_pointer;

     return this->Delete_Return_Status;
}


char * Cpp_FileOperations::GetFilePath(){

       return this->CString_FilePATH;
}
