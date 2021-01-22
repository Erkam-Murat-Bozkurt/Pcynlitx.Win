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

#include "ListFileOrganizer.h"

ListFileOrganizer::ListFileOrganizer(){

     this->Memory_Delete_Condition = true;

     this->DataBaseConstructionPointSetCondition = false;

     this->IncludeDirectorySetCondition = false;

     this->Record_File_Path = nullptr;

     this->Meta_File_Path = nullptr;

     this->HeaderFilePath = nullptr;

     this->IncludeDirectoryPATH = nullptr;

     this->DataBaseConstructionPoint = nullptr;
};

ListFileOrganizer::ListFileOrganizer(const ListFileOrganizer & orig){

};

ListFileOrganizer::~ListFileOrganizer(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void ListFileOrganizer::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->DataBaseConstructionPointSetCondition = false;

         this->IncludeDirectorySetCondition = false;

         this->Clear_Pointer_Memory(&this->Record_File_Path);

         this->Clear_Pointer_Memory(&this->Meta_File_Path);

         this->Clear_Pointer_Memory(&this->HeaderFilePath);

         this->Clear_Pointer_Memory(&this->IncludeDirectoryPATH);

         this->Clear_Pointer_Memory(&this->DataBaseConstructionPoint);
     }
}

void ListFileOrganizer::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void ListFileOrganizer::ReceiveIncludeDirectoryPATH(char * IncludeDirectory){

     int String_Size = strlen(IncludeDirectory);

     this->IncludeDirectoryPATH = new char [10*String_Size];

     this->Place_String(&this->IncludeDirectoryPATH,IncludeDirectory,String_Size);

     this->IncludeDirectorySetCondition = true;
}

void ListFileOrganizer::ReceiveDataBaseConstructionPoint(char * ConstructionPoint){

     int String_Size = strlen(ConstructionPoint);

     this->DataBaseConstructionPoint = new char [10*String_Size];

     this->Place_String(&this->DataBaseConstructionPoint,ConstructionPoint,String_Size);

     this->DataBaseConstructionPointSetCondition = true;
}

void ListFileOrganizer::Set_Target_Header_File_Path(char * Target_Header_File_Path){

     int String_Size = strlen(Target_Header_File_Path);

     this->HeaderFilePath = new char [10*String_Size];

     this->Place_String(&this->HeaderFilePath,Target_Header_File_Path,String_Size);
}

void ListFileOrganizer::CollectInformations(){

     this->Memory_Delete_Condition = false;

     this->DetermineClassName();

     this->DetermineRecordFilePath();

     this->ClassNameDeterminer.Clear_Dynamic_Memory();

     this->DirectoryManager.Clear_Dynamic_Memory();
}

void ListFileOrganizer::DetermineClassName(){

     this->DirectoryManager.ChangeDirectory(this->IncludeDirectoryPATH);

     this->ClassNameDeterminer.ReadClassName(this->HeaderFilePath);

     this->DirectoryManager.ChangeDirectory(this->DataBaseConstructionPoint);
}

void ListFileOrganizer::DetermineRecordFilePath(){

     char decleration_list_word [] = {'_','M','F','D','L','\0'};

     char meta_file_name [] = {'_','M','F','\0'};

     int meta_file_name_size = strlen(meta_file_name);

     int Word_size = strlen(decleration_list_word);

     int ClassNameSize = strlen(this->ClassNameDeterminer.getClassName());

     int ConstructionPoint_Name_Size = strlen(this->DataBaseConstructionPoint);

     int ListNameSize = Word_size + ClassNameSize + ConstructionPoint_Name_Size;

     this->Record_File_Path = new char [10*ListNameSize];

     for(int i=0;i<5*ListNameSize;i++){

         this->Record_File_Path[i] = '\0';
     }

     int counter = 0;

     for(int i=0;i<ConstructionPoint_Name_Size;i++){

         this->Record_File_Path[counter] = this->DataBaseConstructionPoint[i];

         counter++;
     }

     for(int i=0;i<ClassNameSize;i++){

         if((this->ClassNameDeterminer.getClassName()[i] != '\0') && (this->ClassNameDeterminer.getClassName()[i] != ' ')){

              this->Record_File_Path[counter] = this->ClassNameDeterminer.getClassName()[i];

              counter++;
         }
     }

     for(int i=0;i<Word_size;i++){

         if(!(decleration_list_word[i]=='\0')){

              this->Record_File_Path[counter] = decleration_list_word[i];

              counter++;
         }
     }

     counter++;

     this->Record_File_Path[counter] = '\0';

     int MetaFileNameSize = ListNameSize + meta_file_name_size;

     this->Meta_File_Path = new char [10*MetaFileNameSize];

     for(int i=0;i<5*MetaFileNameSize;i++){

         this->Meta_File_Path[i] = '\0';
     }

     counter = 0;

     for(int i=0;i<ListNameSize;i++){

         if((this->Record_File_Path[i] != '\0') && (this->Record_File_Path[i] != ' ')){

              this->Meta_File_Path[counter] = this->Record_File_Path[i];

              counter++;
         }
     }

     for(int i=0;i<meta_file_name_size;i++){

         if((this->Record_File_Path[i] != '\0') && (this->Record_File_Path[i] != ' ')){

             this->Meta_File_Path[counter] = meta_file_name [i];

             counter++;
         }
     }

     counter++;

     this->Meta_File_Path[counter] = '\0';
}


void ListFileOrganizer::Place_String(char ** Pointer,char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void ListFileOrganizer::Place_String(char ** Pointer, const char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

char * ListFileOrganizer::GetRecordFilePath(){

       return this->Record_File_Path;
}

char * ListFileOrganizer::GetMetaDataFilePath(){

       return this->Meta_File_Path;
}

char * ListFileOrganizer::GetHeaderFilePath(){

       return this->HeaderFilePath;
}

char * ListFileOrganizer::GetIncludeDirectoryPATH(){

       return this->IncludeDirectoryPATH;
}

char * ListFileOrganizer::GetDataBaseConstructionPoint(){

       return this->DataBaseConstructionPoint;
}
