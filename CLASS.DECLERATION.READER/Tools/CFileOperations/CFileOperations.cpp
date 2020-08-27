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


#include <iostream>
#include "CFileOperations.h"

CFileOperations::CFileOperations(){

     this->Memory_Delete_Condition = false;

     this->FilePath = nullptr;

     this->stream = nullptr;

     this->isLongPath = false;

     this->characterBuffer = '\0';

     this->FileDeleteCondition = -1;

     this->End_of_File_Condition = false;
}

CFileOperations::CFileOperations(const CFileOperations& orig) {

}

CFileOperations::~CFileOperations(){

    if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
    }
}

void CFileOperations::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->FilePath != nullptr){

            delete [] this->FilePath;

            this->FilePath = nullptr;
         }
     }
}

void CFileOperations::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

int CFileOperations::DeleteFile(char * FileName){

     this->FileDeleteCondition = unlink(FileName);

     return this->FileDeleteCondition;
}

bool CFileOperations::Is_This_Long_Path(const char * FileName){

     this->isLongPath = false;

     int NameSize = strlen(FileName);

     for(int i=NameSize ;i>0;i--){

         if(FileName[i] == '/'){

            this->isLongPath  = true;

            break;
         }
     }

     return this->isLongPath;
}

bool CFileOperations::Is_This_Long_Path(char * FileName){

     this->isLongPath = false;

     int NameSize = this->Get_String_Size(FileName);

     for(int i= NameSize;i>0;i--){

         if(FileName[i] == '/'){

            this->isLongPath  = true;

            break;
         }
     }

     return this->isLongPath;
}

void CFileOperations::SetFilePath(const char * FileName){

     this->Memory_Delete_Condition = false;

     this->Clear_Pointer_Memory(&this->FilePath);

     int File_Name_size = strlen(FileName);

     bool is_long_path = this->Is_This_Long_Path(FileName);

     if(is_long_path){

         this->FilePath = new char [10*File_Name_size];

         this->Place_String(&this->FilePath,FileName,File_Name_size);
     }
     else{
            char Directory_Character [] = {'/','\0'};

            char * Current_Directory = get_current_dir_name();

            int Directory_Name_Size  = strlen(Current_Directory);

            int Path_Name_Size = File_Name_size + Directory_Name_Size;

            int index_counter = 0;

            this->FilePath = new char [10*Path_Name_Size];

            this->Place_Information(&this->FilePath,Current_Directory ,&index_counter);

            this->Place_Information(&this->FilePath,Directory_Character,&index_counter);

            this->Place_Information(&this->FilePath,FileName,&index_counter);

            this->FilePath[index_counter] = '\0';

            free(Current_Directory);
     }
}

void CFileOperations::SetFilePath(char * FileName){

     this->Memory_Delete_Condition = false;

     this->Clear_Pointer_Memory(&this->FilePath);

     if(this->Is_This_Long_Path(FileName)){

         int File_Name_size = strlen(FileName);

         this->FilePath = new char [10*File_Name_size];

         this->Place_String(&this->FilePath,FileName,File_Name_size);
     }
     else{
            char Directory_Character [] = {'/','\0'};

            char * Current_Directory = get_current_dir_name();

            int File_Name_size = strlen(FileName);

            int Directory_Name_Size  = strlen(Current_Directory);

            int Path_Name_Size = File_Name_size + Directory_Name_Size;

            int index_counter = 0;

            this->FilePath = new char [10*Path_Name_Size];

            this->Place_Information(&this->FilePath,Current_Directory ,&index_counter);

            this->Place_Information(&this->FilePath,Directory_Character,&index_counter);

            this->Place_Information(&this->FilePath,FileName,&index_counter);

            this->FilePath[index_counter] = '\0';

            free(Current_Directory);
     }
}


void CFileOperations::FileOpen(const char * mode){

    this->stream = fopen(this->GetFilePath(),mode);

    if(this->stream == NULL){

         std::cout << "\n The File can not be openned .. ! \n";
    }
}

void CFileOperations::FileClose( ){

    int test;

    test=fclose(this->stream);

    if(test==EOF){

       std::cout << "\n The File can not be closed .. !";
    }
}

char * CFileOperations::ReadLine( ){

       if(this->stream != nullptr){

          for(int i=0;i<LINE_MAX;i++){

              this->buffer[i] = '\0';
          }

          char * read_buffer = nullptr;

          size_t len = 0;

          ssize_t nread = 0;

          nread = getline(&read_buffer,&len,this->stream);

          if(nread != -1){

              for(int i=0;i<nread+1;i++){

                  this->buffer[i] = read_buffer[i];
              }

              this->buffer[nread+1] = '\0';
          }

          if(read_buffer != nullptr){

             free(read_buffer);
          }
       }

       return this->buffer;
}

void CFileOperations::Copy_File(char * Target_Location, char * Base_Location){

     int read_fd = 0;

     int write_fd = 0;

     struct stat stat_buf;

     stat_buf.st_mode = S_IFREG;

     off_t offset = 0;

     /* Open the input file. */

     read_fd = open(Base_Location,O_RDONLY,stat_buf.st_mode);

     int stat_return = fstat (read_fd, &stat_buf);

     /* Open the output file for writing, with the same permissions as the source file. */

     write_fd = open(Target_Location, O_WRONLY | O_CREAT,stat_buf.st_mode);

     /* Blast the bytes from one file to the other. */

     sendfile(write_fd,read_fd,&offset,stat_buf.st_size);

     /* Close up. */

     close (read_fd);

     close (write_fd);
}

void CFileOperations::Move_File(char * New_File_Path, char * File_Path){

     this->Copy_File(New_File_Path,File_Path);

     this->DeleteFile(File_Path);
}

void CFileOperations::PrintLineToConsole(){

     if(this->stream != NULL){

        if(!this->Check_End_of_File())
        {
            this->ReadLine();

            std::cout << "\n" << this->buffer;
        }
        else
        {
            std::cout << "\n The End of File..";
        }
     }
}

void CFileOperations::WriteToFile(const char* string){

    int test;

    test=fputs(string,this->stream);

    if(test==EOF){

         std::cout << "\n The write operation has been failed .. !";
    }
}

void CFileOperations::PrintFileToConsole(){

     if(this->stream != NULL){

        while(!this->Check_End_of_File()){

               std::cout << this->ReadLine();
        };

        std::cout << "\n\n THE END OF FILE ..\n\n";
     }
}

bool CFileOperations::Check_End_of_File(){

     this->End_of_File_Condition = false;

     if(feof(this->stream)){

        this->End_of_File_Condition =  true;
     }

     return this->End_of_File_Condition;
}

char CFileOperations::ReadCharacter(){

     this->characterBuffer = fgetc(this->stream);

     if(!this->characterBuffer)
     {
         if(!this->Check_End_of_File()){

             std::cout << "\n The line can not be readed ..!";
         }
     }

     return this->characterBuffer;
}

int CFileOperations::Get_String_Size(char * String){

    this->String_Size = 0;

    while(String[this->String_Size]!= '\0'){

         this->String_Size++;

         if(this->String_Size == LINE_MAX){

            break;
         }
    }

    return this->String_Size;
}

void CFileOperations::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void CFileOperations::Place_String(char ** Pointer, const char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void CFileOperations::Place_Information(char ** Pointer, const char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
}

void CFileOperations::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
}

char * CFileOperations::GetFilePath(){

       return this->FilePath;
}

void CFileOperations::SetEndOfFile(){

     fseek(this->stream,0,SEEK_END);
}

FILE * CFileOperations::GetFileStreamPointer(){

    return this->stream;
}

void CFileOperations::ClearEndOfFile(){

    clearerr(this->stream);
}
