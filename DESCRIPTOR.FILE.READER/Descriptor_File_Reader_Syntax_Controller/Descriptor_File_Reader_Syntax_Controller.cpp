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

#include "Descriptor_File_Reader_Syntax_Controller.h"

Descriptor_File_Reader_Syntax_Controler::Descriptor_File_Reader_Syntax_Controler(){

      this->Memory_Delete_Condition = false;

      this->Class_Data_Type_Receive_Condition = false;

      this->Shared_Data_Type_Receive_Condition = false;

      this->Header_File_Location = nullptr;

      this->Header_File_Path = nullptr;

      this->Construction_Point = nullptr;
}

Descriptor_File_Reader_Syntax_Controler::Descriptor_File_Reader_Syntax_Controler(const Descriptor_File_Reader_Syntax_Controler & orig){


}

Descriptor_File_Reader_Syntax_Controler::~Descriptor_File_Reader_Syntax_Controler(){

        if(!this->Memory_Delete_Condition){

           this->Clear_Dynamic_Memory();
        }
}

void Descriptor_File_Reader_Syntax_Controler::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Header_File_Path != nullptr){

            delete [] this->Header_File_Path;

            this->Header_File_Path = nullptr;
         }
     }
}

void Descriptor_File_Reader_Syntax_Controler::Receive_Construction_Point(char * Construction_Point){

     this->Construction_Point = Construction_Point;
}

void Descriptor_File_Reader_Syntax_Controler::Determine_Class_Data_Type_Receive_Condition(bool condition){

     this->Class_Data_Type_Receive_Condition = condition;
}

void Descriptor_File_Reader_Syntax_Controler::Determine_Shared_Data_Type_Receive_Condition(bool condition){

     this->Shared_Data_Type_Receive_Condition = condition;
}

void Descriptor_File_Reader_Syntax_Controler::Receive_Inter_Thread_Class_Data(Class_Data_Type * Data){

     this->Class_Data_Type_Holder = Data;
}

void Descriptor_File_Reader_Syntax_Controler::Receive_Inter_Thread_Data_Type_Data(Shared_Memory_Data_Type * Data){

     this->Shared_Memory_Data_Type_Holder = Data;
}

void Descriptor_File_Reader_Syntax_Controler::Control_Process_Syntax(){

     if(this->Class_Data_Type_Receive_Condition){

        int Inter_Thread_Class_Number = this->Class_Data_Type_Holder[0].Total_Class_Number;

        for(int i=0;i<Inter_Thread_Class_Number;i++){

            if(this->Class_Data_Type_Holder[i].Header_File_Name != nullptr){

               this->Determine_Inter_Thread_Class_Informations(this->Class_Data_Type_Holder[i]);

               this->FunctionReader.Receive_Include_Directory_PATH(this->Header_File_Location);

               this->FunctionReader.Receive_Header_File_Path(this->Header_File_Path);

               this->FunctionReader.Receive_Construction_Point(this->Construction_Point);

               this->FunctionReader.Read_Member_Functions();

               this->FunctionReader.Clear_Dynamic_Memory();
            }
        }
     }

     if(this->Shared_Data_Type_Receive_Condition){

        int Shared_Data_Types_Number = this->Shared_Memory_Data_Type_Holder[0].Total_Data_Type_Number;

        for(int i=0;i<Shared_Data_Types_Number;i++){

            if(this->Shared_Memory_Data_Type_Holder[i].Header_File_Name != nullptr){

               this->Determine_Shared_Data_Type_Informations(this->Shared_Memory_Data_Type_Holder[i]);

               this->FunctionReader.Receive_Include_Directory_PATH(this->Header_File_Location);

               this->FunctionReader.Receive_Header_File_Path(this->Header_File_Path);

               this->FunctionReader.Receive_Construction_Point(this->Construction_Point);

               this->FunctionReader.Read_Member_Functions();

               this->FunctionReader.Clear_Dynamic_Memory();
            }
        }
     }
}

void Descriptor_File_Reader_Syntax_Controler::Determine_Inter_Thread_Class_Informations(Class_Data_Type Class_Data_Holder){

     if(this->Header_File_Path != nullptr){

        delete [] this->Header_File_Path;

        this->Header_File_Path = nullptr;
     }

     if(this->Header_File_Location != nullptr){

        this->Header_File_Location = nullptr;
     }

     int index_counter = 0;

     char Directory_Operator [] = {'/','\0'};

     char * Header_File_Name = Class_Data_Holder.Header_File_Name;

     this->Header_File_Location = Class_Data_Holder.Header_File_Location;

     int Header_File_Location_Size = strlen(this->Header_File_Location);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int Header_File_Path_Size = Header_File_Name_Size + Header_File_Location_Size;

     this->Header_File_Path = new char [10*Header_File_Path_Size];

     this->Place_Information(&this->Header_File_Path,this->Header_File_Location,&index_counter);

     this->Place_Information(&this->Header_File_Path,Directory_Operator,&index_counter);

     this->Place_Information(&this->Header_File_Path,Header_File_Name,&index_counter);

     this->Header_File_Path[index_counter] = '\0';
}

void Descriptor_File_Reader_Syntax_Controler::Determine_Shared_Data_Type_Informations(Shared_Memory_Data_Type Data_Holder){

     if(this->Header_File_Path != nullptr){

        delete [] this->Header_File_Path;

        this->Header_File_Path = nullptr;
     }

     if(this->Header_File_Location != nullptr){

        this->Header_File_Location = nullptr;
     }

     int index_counter = 0;

     char Directory_Operator [] = {'/','\0'};

     char * Header_File_Name = Data_Holder.Header_File_Name;

     this->Header_File_Location = Data_Holder.Include_Directory;

     int Header_File_Location_Size = strlen(this->Header_File_Location);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int Header_File_Path_Size = Header_File_Name_Size + Header_File_Location_Size;

     this->Header_File_Path = new char [10*Header_File_Path_Size];

     this->Place_Information(&this->Header_File_Path,this->Header_File_Location,&index_counter);

     this->Place_Information(&this->Header_File_Path,Directory_Operator,&index_counter);

     this->Place_Information(&this->Header_File_Path,Header_File_Name,&index_counter);

     this->Header_File_Path[index_counter] = '\0';
}

void Descriptor_File_Reader_Syntax_Controler::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void Descriptor_File_Reader_Syntax_Controler::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
}
