

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

#include "Smart_Pointer_Data_Conveyor.h"

Smart_Pointer_Data_Conveyor::Smart_Pointer_Data_Conveyor(){

     this->New_Class_Name = nullptr;
     this->Data_Type = nullptr;
     this->Data_Type_Include_Directory = nullptr;
     this->Instance_Name = nullptr;
     this->type_count = 0;
     this->Memory_Delete_Status = true;
}

void Smart_Pointer_Data_Conveyor::Receive_Data_Type_Count(int count) {

      // How many data type has been declareted.

     this->type_count = count;

     this->New_Class_Name = new char * [10*this->type_count];

     this->Data_Type = new char * [10*this->type_count];

     this->Data_Type_Include_Directory = new char * [10*this->type_count];

     this->Instance_Name = new char * [10*this->type_count];

     this->Memory_Delete_Status = false;
}

Smart_Pointer_Data_Conveyor::Smart_Pointer_Data_Conveyor(const Smart_Pointer_Data_Conveyor & orig){


}

Smart_Pointer_Data_Conveyor::~Smart_Pointer_Data_Conveyor(){

     if(!this->Memory_Delete_Status){

        this->Clear_Dynamic_Memory();
     }
}

void Smart_Pointer_Data_Conveyor::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Status){

        this->Memory_Delete_Status = true;

         for(int i=0;i<this->type_count;i++){

             delete [] this->Data_Type[i];

             delete [] this->New_Class_Name[i];

             delete [] this->Data_Type_Include_Directory[i];

             delete [] this->Instance_Name[i];
         }

         delete [] this->Data_Type;

         delete [] this->New_Class_Name;

         delete [] this->Data_Type_Include_Directory;

         delete [] this->Instance_Name;
     }
}

void Smart_Pointer_Data_Conveyor::Receive_Data_Type(char * type, int type_number){

     size_t type_name_size = strlen(type);

     this->Data_Type[type_number] = new char [10*type_name_size];

     for(size_t k=0;k<type_name_size;k++){

        this->Data_Type[type_number][k] = type[k];
     }

     this->Data_Type[type_number][type_name_size] = '\0';
  }

void Smart_Pointer_Data_Conveyor::Receive_New_Class_Name(char * class_name, int type_number){

     size_t class_name_size = strlen(class_name);

     this->New_Class_Name[type_number] = new char [10*class_name_size];

     for(size_t k=0;k<class_name_size;k++){

         this->New_Class_Name[type_number][k] = class_name[k];
     }

     this->New_Class_Name[type_number][class_name_size] = '\0';
}

void Smart_Pointer_Data_Conveyor::Receive_Data_Type_Instance_Name(char * Instance_Name, int type_number){

     size_t instance_name_size = strlen(Instance_Name);

     this->Instance_Name[type_number] = new char [10*instance_name_size];

     for(size_t k=0;k<instance_name_size;k++){

         this->Instance_Name[type_number][k] = Instance_Name[k];
     }

     this->Instance_Name[type_number][instance_name_size] = '\0';
}

void Smart_Pointer_Data_Conveyor::Receive_Data_Type_Include_Directory(char * Directory, int type_number){

     size_t directory_name_size = strlen(Directory);

     this->Data_Type_Include_Directory[type_number] = new char [10*directory_name_size];

     for(size_t k=0;k<directory_name_size;k++){

        this->Data_Type_Include_Directory[type_number][k] = Directory[k];
     }

     this->Data_Type_Include_Directory[type_number][directory_name_size] = '\0';
}

char * Smart_Pointer_Data_Conveyor::Get_DataType(int type_number){

       return this->Data_Type[type_number];
}

char * Smart_Pointer_Data_Conveyor::Get_New_Class_Name(int type_number){

       return this->New_Class_Name[type_number];
}

char * Smart_Pointer_Data_Conveyor::Get_Shared_Data_Type_Instance_Name(int type_number){

       return this->Instance_Name[type_number];
}

char * Smart_Pointer_Data_Conveyor::Get_Data_Type_Include_Directory(int type_number){

       return this->Data_Type_Include_Directory[type_number];
}
