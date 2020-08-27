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

#include "ClassRebuilder_Initializer.h"

ClassRebuilder_Initializer::ClassRebuilder_Initializer(){

     this->Memory_Delete_Condition = false;

     this->Class_Data_Type_Receive_Condition = false;

     this->Shared_Data_Type_Receive_Condition = false;

     this->New_Class_Name = nullptr;

     this->Class_Implementation_File_Name = nullptr;

     this->New_Destructor_Name = nullptr;

     this->Base_Class_Destructor_Name = nullptr;

     this->New_Header_File_Name = nullptr;

     this->Object_Name = nullptr;

     this->Base_Class_Name = nullptr;

     this->Base_Class_Header_File_Name = nullptr;

     this->Base_Class_Header_File_Path = nullptr;

     this->Base_Class_Header_File_Location = nullptr;

     this->Base_Class_Instance_Name = nullptr;

     this->Newly_Constructed_Include_Directory = nullptr;

     this->Class_Number = 0;

     this->Data_Type_Number = 0;
};

ClassRebuilder_Initializer::ClassRebuilder_Initializer(const ClassRebuilder_Initializer & orig){

};

ClassRebuilder_Initializer::~ClassRebuilder_Initializer(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
};

void ClassRebuilder_Initializer::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->New_Class_Name);

         this->Clear_Pointer_Memory(&this->Class_Implementation_File_Name);

         this->Clear_Pointer_Memory(&this->New_Destructor_Name);

         this->Clear_Pointer_Memory(&this->Base_Class_Destructor_Name);

         this->Clear_Pointer_Memory(&this->New_Header_File_Name);

         this->Clear_Pointer_Memory(&this->Object_Name);

         this->Clear_Pointer_Memory(&this->Base_Class_Name);

         this->Clear_Pointer_Memory(&this->Base_Class_Header_File_Name);

         this->Clear_Pointer_Memory(&this->Base_Class_Header_File_Path);

         this->Header_Files_Name_Reader.Clear_Dynamic_Memory();

         this->Class_Data_Type_Receive_Condition = false;

         this->Shared_Data_Type_Receive_Condition = false;

         this->Base_Class_Header_File_Location = nullptr;

         this->Base_Class_Instance_Name = nullptr;

         this->Newly_Constructed_Include_Directory = nullptr;

         this->Class_Number = 0;

         this->Data_Type_Number = 0;
     }
}

void ClassRebuilder_Initializer::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void ClassRebuilder_Initializer::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;
}

void ClassRebuilder_Initializer::Receive_Class_Number(int Number){

     this->Class_Data_Type_Receive_Condition = true;

     this->Class_Number = Number;
}

void ClassRebuilder_Initializer::Receive_Data_Type_Number(int Number){

     this->Shared_Data_Type_Receive_Condition = true;

     this->Data_Type_Number = Number;
}

void ClassRebuilder_Initializer::Determine_Informations(){

     this->Memory_Delete_Condition = false;

     this->Newly_Constructed_Include_Directory = this->Reader_Pointer->Get_Constructed_Include_Directory();

     this->Determine_Index_Number_of_Class();

     this->Determine_Base_Class_Informations();

     this->Determine_New_Class_Name();

     this->Determine_New_Header_File_Name();

     this->Determine_New_Class_Implementation_File_Name();

     this->Determine_New_Class_Destructor_Name();

     this->Determine_Base_Class_Destructor_Name();

     this->Determine_Object_Name();

     this->Determine_Included_Header_Files();
}

void ClassRebuilder_Initializer::Determine_Index_Number_of_Class(){

     this->Index_Number = 0;

     if(this->Class_Data_Type_Receive_Condition){

        Class_Data_Type * Class_Data_Holder = this->Reader_Pointer->Get_Class_Names();

        int Total_Class_Number = Class_Data_Holder[0].Total_Class_Number;

        for(int i=0;i<Total_Class_Number;i++){

            if(this->Class_Number == Class_Data_Holder[i].Class_Number){

               this->Index_Number = i;
            }
        }
     }

     if(this->Shared_Data_Type_Receive_Condition){

        Shared_Memory_Data_Type * Data_Type_Holder = this->Reader_Pointer->Get_Shared_Data_Types();

        int Total_Data_Type_Number = Data_Type_Holder[0].Total_Data_Type_Number;

        for(int i=0;i<Total_Data_Type_Number;i++){

            if(this->Data_Type_Number == Data_Type_Holder[i].Data_Number){

               this->Index_Number = i;
            }
        }
     }
}

void ClassRebuilder_Initializer::Determine_Base_Class_Informations(){

     int index_counter = 0;

     char Directory_Operator [] = {'/','\0'};

     if(this->Class_Data_Type_Receive_Condition){

        Class_Data_Type Class_Data_Holder = this->Reader_Pointer->Get_Class_Names()[this->Index_Number];

        char * Class_Name = Class_Data_Holder.Class_Name;

        char * Header_File_Location = Class_Data_Holder.Header_File_Location;

        int Class_Name_Size = strlen(Class_Name);

        this->Base_Class_Name = new char [10*Class_Name_Size];

        this->Place_String(&this->Base_Class_Name,Class_Name,Class_Name_Size);

        char * Header_File_Name = Class_Data_Holder.Header_File_Name;

        int Header_File_Name_Size = strlen(Header_File_Name);

        this->Base_Class_Header_File_Name = new char [10*Header_File_Name_Size];

        this->Place_Information(&this->Base_Class_Header_File_Name,Header_File_Name,&index_counter);

        this->Base_Class_Header_File_Name[index_counter] = '\0';

        this->Base_Class_Header_File_Location = Class_Data_Holder.Header_File_Location;

        this->Base_Class_Instance_Name = Class_Data_Holder.Class_Instance_Name;

        int Header_File_Location_Size = strlen(this->Base_Class_Header_File_Location);

        int Header_File_Path_Size = Header_File_Name_Size + Header_File_Location_Size;

        index_counter = 0;

        this->Base_Class_Header_File_Path = new char [10*Header_File_Path_Size];

        this->Place_Information(&this->Base_Class_Header_File_Path,this->Base_Class_Header_File_Location,&index_counter);

        this->Place_Information(&this->Base_Class_Header_File_Path,Directory_Operator,&index_counter);

        this->Place_Information(&this->Base_Class_Header_File_Path,this->Base_Class_Header_File_Name,&index_counter);

        this->Base_Class_Header_File_Path[index_counter] = '\0';
     }
     else{

            if(this->Shared_Data_Type_Receive_Condition){

               Shared_Memory_Data_Type Data_Holder = this->Reader_Pointer->Get_Shared_Data_Types()[this->Index_Number];

               char Type_Word [] = {'_','T','y','p','e','_','S','m','a','r','t','_','P','o','i','n','t','e','r','\0'};

               char Header_Add_Word [] = {'.','h','\0'};

               char * Class_Name = Data_Holder.Data_Type;

               int Class_Name_Size = strlen(Class_Name);

               int Type_Name_Word_Size = strlen(Type_Word);

               int Base_Class_Name_Size = Class_Name_Size + Type_Name_Word_Size;

               this->Base_Class_Name = new char [10*Base_Class_Name_Size];

               this->Place_Information(&this->Base_Class_Name,Class_Name,&index_counter);

               this->Place_Information(&this->Base_Class_Name,Type_Word,&index_counter);

               this->Base_Class_Name[index_counter] = '\0';

               this->Base_Class_Instance_Name = Data_Holder.Pointer_Name;

               this->Base_Class_Header_File_Location = this->Newly_Constructed_Include_Directory;


               this->Base_Class_Header_File_Name = new char [10*Base_Class_Name_Size];

               index_counter = 0;

               this->Place_Information(&this->Base_Class_Header_File_Name,this->Base_Class_Name,&index_counter);

               this->Place_Information(&this->Base_Class_Header_File_Name,Header_Add_Word,&index_counter);

               this->Base_Class_Header_File_Name[index_counter] = '\0';

               int Newly_Directory_Size = strlen(this->Newly_Constructed_Include_Directory);

               int Base_Class_Header_File_Name = strlen(this->Base_Class_Header_File_Name);

               int Base_Class_Header_File_Path_Size = Newly_Directory_Size + Base_Class_Header_File_Name;

               index_counter = 0;

               this->Base_Class_Header_File_Path = new char [10*Base_Class_Header_File_Path_Size];

               this->Place_Information(&this->Base_Class_Header_File_Path,this->Newly_Constructed_Include_Directory,&index_counter);

               this->Place_Information(&this->Base_Class_Header_File_Path,Directory_Operator,&index_counter);

               this->Place_Information(&this->Base_Class_Header_File_Path,this->Base_Class_Header_File_Name,&index_counter);

               this->Base_Class_Header_File_Path[index_counter] = '\0';
            }
     }
}

void ClassRebuilder_Initializer::Determine_Included_Header_Files(){

     this->Header_Files_Name_Reader.Determine_Included_Header_File_Names(this->Base_Class_Header_File_Name);
}


void ClassRebuilder_Initializer::Determine_Object_Name(){

     int String_Size = strlen(this->Base_Class_Instance_Name);

     this->Object_Name = new char [10*String_Size];

     this->Place_String(&this->Object_Name,this->Base_Class_Instance_Name,String_Size);
}

void ClassRebuilder_Initializer::Determine_New_Class_Name(){

     char Class_Subfix [] = {'_','C','l','i','e','n','t','\0'};

     int Subfix_Name_Size     = strlen(Class_Subfix);

     int Base_Class_Name_Size = strlen(this->Base_Class_Name);

     this->New_Class_Name =  new char [10*Base_Class_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->New_Class_Name,this->Base_Class_Name,&index_counter);

     this->Place_Information(&this->New_Class_Name,Class_Subfix,&index_counter);

     this->New_Class_Name[index_counter] = '\0';
}

void ClassRebuilder_Initializer::Determine_New_Header_File_Name(){

     char Class_Subfix [] = {'_','C','l','i','e','n','t','\0'};

     char Header_Add_Word [] = {'.','h','\0'};

     int Header_File_Name_Size = strlen(this->Base_Class_Name);

     this->New_Header_File_Name =  new char [10*Header_File_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->New_Header_File_Name,this->Base_Class_Name,&index_counter);

     this->Place_Information(&this->New_Header_File_Name,Class_Subfix,&index_counter);

     this->Place_Information(&this->New_Header_File_Name,Header_Add_Word,&index_counter);

     this->New_Header_File_Name[index_counter] = '\0';
}

void ClassRebuilder_Initializer::Determine_New_Class_Implementation_File_Name(){

     char FileExtentation [] = {'.','c','p','p','\0'};

     int ExtentationSize = strlen(FileExtentation);

     int ClassNameSize = strlen(this->New_Class_Name);

     int ImpleMentationFileNameSize = ExtentationSize +  ClassNameSize;

     this->Class_Implementation_File_Name = new char [10*ImpleMentationFileNameSize];

     int index_counter = 0;

     this->Place_Information(&this->Class_Implementation_File_Name,this->New_Class_Name,&index_counter);

     this->Place_Information(&this->Class_Implementation_File_Name,FileExtentation,&index_counter);

     this->Class_Implementation_File_Name[index_counter] = '\0';
}

void ClassRebuilder_Initializer::Determine_New_Class_Destructor_Name(){

     char Tilda_Character [] = {'~','\0'};

     int NewClassNameSize = strlen(this->New_Class_Name);

     this->New_Destructor_Name = new char [10*NewClassNameSize];

     int index_counter = 0;

     this->Place_Information(&this->New_Destructor_Name,Tilda_Character,&index_counter);

     this->Place_Information(&this->New_Destructor_Name,this->New_Class_Name,&index_counter);

     this->New_Destructor_Name[index_counter] = '\0';
}

void ClassRebuilder_Initializer::Determine_Base_Class_Destructor_Name(){

     char Tilda_Character [] = {'~','\0'};

     int BaseClassNameSize = strlen(this->Base_Class_Name);

     this->Base_Class_Destructor_Name = new char [10*BaseClassNameSize];

     int index_counter = 0;

     this->Place_Information(&this->Base_Class_Destructor_Name,Tilda_Character,&index_counter);

     this->Place_Information(&this->Base_Class_Destructor_Name,this->Base_Class_Name,&index_counter);

     this->Base_Class_Destructor_Name[index_counter] = '\0';
}
void ClassRebuilder_Initializer::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void ClassRebuilder_Initializer::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
}

bool ClassRebuilder_Initializer::Is_This_Method_Base_Class_Constructor(char * MethodName)
{
     return this->CharacterOperations.CompareString(MethodName,this->Base_Class_Name);
}

int ClassRebuilder_Initializer::Get_Index_Number_For_Descriptor_File_Reader() const
{
    return this->Index_Number;
}

bool ClassRebuilder_Initializer::Is_This_Method_Base_Class_Destructor(char * MethodName){

     return this->CharacterOperations.CompareString(MethodName,this->Get_Base_Class_Destructor_Name());
}

char * ClassRebuilder_Initializer::Get_New_Class_Constructor_Name() const
{
       return this->New_Class_Name;
}

char * ClassRebuilder_Initializer::Get_New_Class_Destructor_Name() const
{
       return this->New_Destructor_Name;
}

char * ClassRebuilder_Initializer::Get_Base_Class_Destructor_Name() const
{
       return this->Base_Class_Destructor_Name;
}

char * ClassRebuilder_Initializer::Get_New_Class_Implementation_File_Name() const
{
       return this->Class_Implementation_File_Name;
}

char * ClassRebuilder_Initializer::Get_New_Header_File_Name() const
{
       return this->New_Header_File_Name;
}

char * ClassRebuilder_Initializer::Get_New_Class_Name() const
{
       return this->New_Class_Name;
}

char * ClassRebuilder_Initializer::Get_Object_Name() const
{
       return this->Object_Name;
}

char * ClassRebuilder_Initializer::Get_Base_Class_Header_File_Name() const
{
       return this->Base_Class_Header_File_Name;
}

char * ClassRebuilder_Initializer::Get_Base_Class_Header_File_Path() const
{
       return this->Base_Class_Header_File_Path;
}

char * ClassRebuilder_Initializer::Get_Base_Class_Name() const
{
       return this->Base_Class_Name;
}

char * ClassRebuilder_Initializer::Get_Base_Class_Instance_Name() const
{
       return this->Base_Class_Instance_Name;
}

char * ClassRebuilder_Initializer::Get_Base_Class_Header_File_Location() const
{
       return this->Base_Class_Header_File_Location;
}

int ClassRebuilder_Initializer::Get_Included_Header_Files_Number() {

     return this->Header_Files_Name_Reader.Get_Included_Header_File_Number();
}

std::string * ClassRebuilder_Initializer::Get_Header_File_Declarations(){

     return this->Header_Files_Name_Reader.Get_Header_File_Declarations();
}

char ** ClassRebuilder_Initializer::Get_Header_File_Declarations_C_String(){

     return this->Header_Files_Name_Reader.Get_Header_File_Declarations_C_String();
}

char ** ClassRebuilder_Initializer::Get_Header_File_Names_C_String(){

      return this->Header_Files_Name_Reader.Get_Header_File_Names_C_String();
}
