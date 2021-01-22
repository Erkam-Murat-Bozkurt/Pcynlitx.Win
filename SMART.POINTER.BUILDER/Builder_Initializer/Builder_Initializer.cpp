
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

#include "Builder_Initializer.h"

Builder_Initializer::Builder_Initializer(){

     this->Memory_Delete_Condition = false;

     this->Entered_Class_Name_Receive_Conditon = false;

     this->Data_Type_Include_File_Name_Receive_Condition = false;

     this->Direct_New_Class_Name_Determination = false;

     this->Data_Type_Include_File_Name = nullptr;

     this->New_Class_Name = nullptr;

     this->Data_Type = nullptr;

     this->New_Header_File_Name = nullptr;

     this->Class_Implementation_File_Name = nullptr;

     this->Constructor = nullptr;

     this->Destructor = nullptr;

     this->Generic_Class_Name = nullptr;

     this->Base_Directory = nullptr;

     this->Construction_Point = nullptr;

     this->Entered_Class_Name = nullptr;
};

Builder_Initializer::Builder_Initializer(const Builder_Initializer & orig){

};

Builder_Initializer::~Builder_Initializer(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
      }
};

void Builder_Initializer::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->Data_Type);

         this->Clear_Pointer_Memory(&this->New_Header_File_Name);

         this->Clear_Pointer_Memory(&this->Constructor);

         this->Clear_Pointer_Memory(&this->Destructor);

         this->Clear_Pointer_Memory(&this->Class_Implementation_File_Name);

         this->Clear_Pointer_Memory(&this->Generic_Class_Name);

         if(this->Data_Type_Include_File_Name_Receive_Condition){

             this->Clear_Pointer_Memory(&this->Data_Type_Include_File_Name);
         }

         this->Clear_Pointer_Memory(&this->New_Class_Name);

         if(this->Entered_Class_Name_Receive_Conditon){

             this->Clear_Pointer_Memory(&this->Entered_Class_Name);
         }

         this->Clear_Pointer_Memory(&this->Base_Directory);

         this->Clear_Pointer_Memory(&this->Construction_Point);

         this->Entered_Class_Name_Receive_Conditon = false;

         this->Data_Type_Include_File_Name_Receive_Condition = false;

         this->Direct_New_Class_Name_Determination = false;
     }
}

void Builder_Initializer::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

void Builder_Initializer::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void Builder_Initializer::Place_String(char ** Pointer, const char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void Builder_Initializer::Place_Information(char ** Pointer, char * Information, int * index_counter){

     size_t Information_Size = strlen(Information);

     for(size_t i=0;i<Information_Size;i++){

        (*Pointer)[(*index_counter)] = Information[i];

        (*index_counter)++;
     }
}

void Builder_Initializer::Set_New_Class_Name_Directly(char * New_Class_Name){

     this->Direct_New_Class_Name_Determination = true;

     size_t String_Size = strlen(New_Class_Name);

     this->New_Class_Name = new char [10*String_Size];

     this->Place_String(&this->New_Class_Name,New_Class_Name,String_Size);
}

void Builder_Initializer::Set_New_Class_Name_Directly(const char * New_Class_Name){

     this->Direct_New_Class_Name_Determination = true;

     size_t String_Size = strlen(New_Class_Name);

     this->New_Class_Name = new char [10*String_Size];

     this->Place_String(&this->New_Class_Name,New_Class_Name,String_Size);
}

void Builder_Initializer::Receive_Data_Type(const char * DataType){

     size_t String_Size = strlen(DataType);

     this->Data_Type = new char [5*String_Size];

     this->Place_String(&this->Data_Type,DataType,String_Size);
}

void Builder_Initializer::Receive_Data_Type(char * DataType){

     size_t String_Size = strlen(DataType);

     this->Data_Type = new char [10*String_Size];

     this->Place_String(&this->Data_Type,DataType,String_Size);
}

void Builder_Initializer::Receive_Generic_Class_Name(const char * Class_Name){

     size_t String_Size = strlen(Class_Name);

     this->Generic_Class_Name = new char [10*String_Size];

     this->Place_String(&this->Generic_Class_Name,Class_Name,String_Size);
}

void Builder_Initializer::Receive_Generic_Class_Name(char * Class_Name){

     size_t String_Size = strlen(Class_Name);

     this->Generic_Class_Name = new char [10*String_Size];

     this->Place_String(&this->Generic_Class_Name,Class_Name,String_Size);
}

void Builder_Initializer::Receive_Data_Type_Include_File_Name(const char * Include_File_Name){

     this->Data_Type_Include_File_Name_Receive_Condition = true;

     size_t String_Size = strlen(Include_File_Name);

     this->Data_Type_Include_File_Name = new char [10*String_Size];

     this->Place_String(&this->Data_Type_Include_File_Name,Include_File_Name,String_Size);
}

void Builder_Initializer::Receive_Data_Type_Include_File_Name(char * Include_File_Name){

     this->Data_Type_Include_File_Name_Receive_Condition = true;

     size_t String_Size = strlen(Include_File_Name);

     this->Data_Type_Include_File_Name = new char [10*String_Size];

     this->Place_String(&this->Data_Type_Include_File_Name,Include_File_Name,String_Size);
}

void Builder_Initializer::Receive_Entered_Class_Name(const char * New_Class_Name){

     this->Entered_Class_Name_Receive_Conditon = true;

     size_t String_Size = strlen(New_Class_Name);

     this->Entered_Class_Name = new char [10*String_Size];

     this->Place_String(&this->Entered_Class_Name,New_Class_Name,String_Size);
}

void Builder_Initializer::Receive_Entered_Class_Name(char * New_Class_Name){

     this->Entered_Class_Name_Receive_Conditon = true;

     size_t String_Size = strlen(New_Class_Name);

     this->Entered_Class_Name = new char [10*String_Size];

     this->Place_String(&this->Entered_Class_Name,New_Class_Name,String_Size);
}

void Builder_Initializer::Receive_Base_Directory(const char * Base_Directory){

     size_t String_Size = strlen(Base_Directory);

     this->Base_Directory = new char [10*String_Size];

     this->Place_String(&this->Base_Directory,Base_Directory,String_Size);
}

void Builder_Initializer::Receive_Base_Directory(char * Base_Directory){

     size_t String_Size = strlen(Base_Directory);

     this->Base_Directory = new char [10*String_Size];

     this->Place_String(&this->Base_Directory,Base_Directory,String_Size);
}

void Builder_Initializer::Receive_Construction_Point(const char * Construction_Point){

     size_t String_Size = strlen(Construction_Point);

     this->Construction_Point = new char [10*String_Size];

     this->Place_String(&this->Construction_Point,Construction_Point,String_Size);
}

void Builder_Initializer::Receive_Construction_Point(char * Construction_Point){

     size_t String_Size = strlen(Construction_Point);

     this->Construction_Point = new char [10*String_Size];

     this->Place_String(&this->Construction_Point,Construction_Point,String_Size);
}

void Builder_Initializer::Collect_Informations(){

     this->Memory_Delete_Condition = false;

     if(!this->Direct_New_Class_Name_Determination){

         if(this->Entered_Class_Name_Receive_Conditon){

            this->Set_Entered_New_Class_Name();
         }
         else{
                this->Set_Default_New_Class_Name();
         }
     }

     this->Determine_New_Header_File_Name();

     this->Determine_Constructor_Function_Names();

     this->Determine_Class_Implementation_File_Name();
}

void Builder_Initializer::Set_Default_New_Class_Name(){

     char TypeWord [] = {'T','y','p','e','\0'};

     char Subline_Character [] = {'_','\0'};

     size_t Generic_Class_Name_WordSize = strlen(this->Generic_Class_Name);

     size_t DataType_Word_Size = strlen(this->Data_Type);

     size_t TypeWord_Size = strlen(TypeWord);

     size_t NewClass_NameSize = Generic_Class_Name_WordSize +  DataType_Word_Size + TypeWord_Size;

     this->New_Class_Name = new char [10*NewClass_NameSize];

     int index_counter = 0;

     this->Place_Information(&this->New_Class_Name,this->Data_Type,&index_counter);

     this->Place_Information(&this->New_Class_Name,Subline_Character,&index_counter);

     this->Place_Information(&this->New_Class_Name,TypeWord,&index_counter);

     this->Place_Information(&this->New_Class_Name,Subline_Character,&index_counter);

     this->Place_Information(&this->New_Class_Name,this->Generic_Class_Name,&index_counter);

     this->New_Class_Name[index_counter] = '\0';
}

void Builder_Initializer::Set_Entered_New_Class_Name(){

     size_t Generic_Class_Name_WordSize = strlen(this->Generic_Class_Name);

     size_t Entered_Class_Name_Size = strlen(this->Entered_Class_Name);

     char Subline_Character [] = {'_','\0'};

     size_t NewClass_NameSize = Generic_Class_Name_WordSize + Entered_Class_Name_Size;

     this->New_Class_Name = new char [10*NewClass_NameSize];

     int index_counter = 0;

     this->Place_Information(&this->New_Class_Name,this->Entered_Class_Name,&index_counter);

     this->Place_Information(&this->New_Class_Name,Subline_Character,&index_counter);

     this->Place_Information(&this->New_Class_Name,this->Generic_Class_Name,&index_counter);

     this->New_Class_Name[index_counter] = '\0';
}

void Builder_Initializer::Determine_New_Header_File_Name(){

     char Header_Add_Word [] = {'.','h','\0'};

     size_t NameSize = strlen(this->New_Class_Name);

     this->New_Header_File_Name = new char [10*NameSize];

     int index_counter = 0;

     this->Place_Information(&this->New_Header_File_Name,this->New_Class_Name,&index_counter);

     this->Place_Information(&this->New_Header_File_Name,Header_Add_Word,&index_counter);

     this->New_Header_File_Name[index_counter] = '\0';
}

void Builder_Initializer::Determine_Class_Implementation_File_Name(){

     char File_Type [] = {'.','c','p','p','\0'};

     size_t Class_Name_Size = strlen(this->Get_NewClassName());

     size_t File_Type_Name_Size = strlen(File_Type);

     size_t Implementation_File_Name_Size = Class_Name_Size + File_Type_Name_Size;

     this->Class_Implementation_File_Name = new char [10*Implementation_File_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->Class_Implementation_File_Name,this->Get_NewClassName(),&index_counter);

     this->Place_Information(&this->Class_Implementation_File_Name,File_Type,&index_counter);

     this->Class_Implementation_File_Name[index_counter] = '\0';
}

void Builder_Initializer::Determine_Constructor_Function_Names(){

     size_t String_Size = strlen(this->New_Class_Name);

     this->Constructor = new char [10*String_Size];

     this->Place_String(&this->Constructor,this->New_Class_Name,String_Size);

     char Tilda_Character [] = {'~','\0'};

     size_t DestructorNameSize = strlen(this->Constructor) + 1;

     int index_counter = 0;

     this->Destructor = new char [10*DestructorNameSize];

     this->Place_Information(&this->Destructor,Tilda_Character,&index_counter);

     this->Place_Information(&this->Destructor,this->Constructor,&index_counter);

     this->Destructor[index_counter] = '\0';
}

char * Builder_Initializer::Get_NewClassName(){

       return this->New_Class_Name;
}

char * Builder_Initializer::Get_DataType(){

       return this->Data_Type;
}

char * Builder_Initializer::Get_NewHeaderFileName(){

       return this->New_Header_File_Name;
}

char * Builder_Initializer::Get_Class_Constructor_Name(){

       return this->Constructor;
}

char * Builder_Initializer::Get_Class_Destructor_Name(){

       return this->Destructor;
}

char * Builder_Initializer::Get_ClassImplementationFileName(){

       return this->Class_Implementation_File_Name;
}

char * Builder_Initializer::Get_DataType_IncludeFileName(){

       return this->Data_Type_Include_File_Name;
}

char * Builder_Initializer::Get_Base_Directory(){

       return this->Base_Directory;
}

char * Builder_Initializer::Get_Construction_Point(){

       return this->Construction_Point;
}

bool  Builder_Initializer::Get_Data_Type_Include_File_Name_Receive_Condition(){

      return this->Data_Type_Include_File_Name_Receive_Condition;
}
