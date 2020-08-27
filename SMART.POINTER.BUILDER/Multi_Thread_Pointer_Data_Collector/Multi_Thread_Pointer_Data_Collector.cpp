
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

#include "Multi_Thread_Pointer_Data_Collector.h"

Multi_Thread_Pointer_Data_Collector::Multi_Thread_Pointer_Data_Collector(){

     this->Memory_Delete_Condition = false;

     this->Header_File_List = nullptr;

     this->Source_File_List = nullptr;

     this->Object_File_List = nullptr;

     this->Header_File_Name_Matrix = nullptr;

     this->Source_File_Name_Matrix = nullptr;

     this->Object_File_Name_Matrix = nullptr;
}

Multi_Thread_Pointer_Data_Collector::Multi_Thread_Pointer_Data_Collector(const Multi_Thread_Pointer_Data_Collector & orig){

}

Multi_Thread_Pointer_Data_Collector::~Multi_Thread_Pointer_Data_Collector(){

    if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
    }
}

void Multi_Thread_Pointer_Data_Collector::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->Header_File_List);

         this->Clear_Pointer_Memory(&this->Source_File_List);

         this->Clear_Pointer_Memory(&this->Object_File_List);

         if(this->Header_File_Name_Matrix != nullptr){

            for(int i=0;i<3;i++){

               this->Clear_Pointer_Memory(&this->Header_File_Name_Matrix[i]);
            }

            delete [] this->Header_File_Name_Matrix;

            this->Header_File_Name_Matrix = nullptr;
         }

         if(this->Source_File_Name_Matrix != nullptr){

            for(int i=0;i<3;i++){

                this->Clear_Pointer_Memory(&this->Source_File_Name_Matrix[i]);
            }

            delete [] this->Source_File_Name_Matrix;

            this->Source_File_Name_Matrix = nullptr;
         }

         if(this->Object_File_Name_Matrix != nullptr){

            for(int i=0;i<3;i++){

               this->Clear_Pointer_Memory(&this->Object_File_Name_Matrix[i]);
            }

            delete [] this->Object_File_Name_Matrix;

            this->Object_File_Name_Matrix = nullptr;
         }

         this->Pointer_Initializer.Clear_Dynamic_Memory();

         this->Manager_Initializer.Clear_Dynamic_Memory();

         this->Reporter_Initializer.Clear_Dynamic_Memory();
     }
}

void Multi_Thread_Pointer_Data_Collector::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

void Multi_Thread_Pointer_Data_Collector::Receive_Data_Type(const char * DataType){

     this->Pointer_Initializer.Receive_Data_Type(DataType);

     this->Manager_Initializer.Receive_Data_Type(DataType);

     this->Reporter_Initializer.Receive_Data_Type(DataType);
}

void Multi_Thread_Pointer_Data_Collector::Receive_Data_Type(char * DataType){

     this->Pointer_Initializer.Receive_Data_Type(DataType);

     this->Manager_Initializer.Receive_Data_Type(DataType);

     this->Reporter_Initializer.Receive_Data_Type(DataType);
}

void Multi_Thread_Pointer_Data_Collector::Receive_Construction_Point(const char * Construction_Point){

     this->Pointer_Initializer.Receive_Construction_Point(Construction_Point);

     this->Manager_Initializer.Receive_Construction_Point(Construction_Point);

     this->Reporter_Initializer.Receive_Construction_Point(Construction_Point);
}

void Multi_Thread_Pointer_Data_Collector::Receive_Construction_Point(char * Construction_Point){

     this->Pointer_Initializer.Receive_Construction_Point(Construction_Point);

     this->Manager_Initializer.Receive_Construction_Point(Construction_Point);

     this->Reporter_Initializer.Receive_Construction_Point(Construction_Point);
}

void Multi_Thread_Pointer_Data_Collector::Receive_Data_Type_Include_File_Name(const char * Include_File_Name){

     this->Pointer_Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

     this->Manager_Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

     this->Reporter_Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);
}

void Multi_Thread_Pointer_Data_Collector::Receive_Data_Type_Include_File_Name(char * Include_File_Name){

     this->Pointer_Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

     this->Manager_Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

     this->Reporter_Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);
}

void Multi_Thread_Pointer_Data_Collector::Set_Class_Name(const char * Class_Name){

     this->Pointer_Initializer.Set_New_Class_Name_Directly(Class_Name);

     this->Manager_Initializer.Receive_Entered_Class_Name(Class_Name);

     this->Reporter_Initializer.Receive_Entered_Class_Name(Class_Name);
}

void Multi_Thread_Pointer_Data_Collector::Set_Class_Name(char * Class_Name){

     this->Pointer_Initializer.Set_New_Class_Name_Directly(Class_Name);

     this->Manager_Initializer.Receive_Entered_Class_Name(Class_Name);

     this->Reporter_Initializer.Receive_Entered_Class_Name(Class_Name);
}

void Multi_Thread_Pointer_Data_Collector::Collect_Informations(){

     this->Memory_Delete_Condition = false;

     this->Pointer_Initializer.Receive_Generic_Class_Name("SmartPointer");

     this->Manager_Initializer.Receive_Generic_Class_Name("MemoryManager");

     this->Reporter_Initializer.Receive_Generic_Class_Name("ReportFileBuilder");

     this->Pointer_Initializer.Collect_Informations();

     this->Manager_Initializer.Collect_Informations();

     this->Reporter_Initializer.Collect_Informations();

     // Header File List Determination

     char * Pointer_Header_File_Name  = this->Pointer_Initializer.Get_NewHeaderFileName();

     char * Manager_Header_File_Name  = this->Manager_Initializer.Get_NewHeaderFileName();

     char * Reporter_Header_File_Name = this->Reporter_Initializer.Get_NewHeaderFileName();

     int Pointer_Header_File_Name_Size  = strlen(Pointer_Header_File_Name);

     int Manager_Header_File_Name_Size  = strlen(Manager_Header_File_Name);

     int Reporter_Header_File_Name_Size = strlen(Reporter_Header_File_Name);

     int Header_File_List_Size = Pointer_Header_File_Name_Size + Manager_Header_File_Name_Size +

                                 Reporter_Header_File_Name_Size;

     this->Header_File_List = new char [10*Header_File_List_Size];

     int index_counter = 0;

     this->Place_Information(&this->Header_File_List,Pointer_Header_File_Name,&index_counter);

     this->Add_Space(&this->Header_File_List,&index_counter);

     this->Place_Information(&this->Header_File_List,Manager_Header_File_Name,&index_counter);

     this->Add_Space(&this->Header_File_List,&index_counter);

     this->Place_Information(&this->Header_File_List,Reporter_Header_File_Name,&index_counter);

     this->Header_File_List[index_counter] = '\0';

     // Determination of header file name matrix

     this->Header_File_Name_Matrix = new char * [10];

     this->Header_File_Name_Matrix[0] = new char [10*Pointer_Header_File_Name_Size];

     this->Place_String(&this->Header_File_Name_Matrix[0],Pointer_Header_File_Name,Pointer_Header_File_Name_Size);

     this->Header_File_Name_Matrix[1] = new char [10*Manager_Header_File_Name_Size];

     this->Place_String(&this->Header_File_Name_Matrix[1], Manager_Header_File_Name,Manager_Header_File_Name_Size);

     this->Header_File_Name_Matrix[2] = new char [10*Reporter_Header_File_Name_Size];

     this->Place_String(&this->Header_File_Name_Matrix[2],Reporter_Header_File_Name,Reporter_Header_File_Name_Size);

     // Source File List Determination

     char * Pointer_Source_File_Name  = this->Pointer_Initializer.Get_ClassImplementationFileName();

     char * Manager_Source_File_Name  = this->Manager_Initializer.Get_ClassImplementationFileName();

     char * Reporter_Source_File_Name = this->Reporter_Initializer.Get_ClassImplementationFileName();

     int Pointer_Source_File_Name_Size  = strlen(Pointer_Source_File_Name);

     int Manager_Source_File_Name_Size  = strlen(Manager_Source_File_Name);

     int Reporter_Source_File_Name_Size = strlen(Reporter_Source_File_Name);

     int Source_File_List_Name_Size = Pointer_Source_File_Name_Size + Manager_Source_File_Name_Size

                                      + Reporter_Source_File_Name_Size;

     this->Source_File_List = new char [10*Source_File_List_Name_Size];

     index_counter = 0;

     this->Place_Information(&this->Source_File_List,Pointer_Source_File_Name,&index_counter);

     this->Add_Space(&this->Source_File_List,&index_counter);

     this->Place_Information(&this->Source_File_List,Manager_Source_File_Name,&index_counter);

     this->Add_Space(&this->Source_File_List,&index_counter);

     this->Place_Information(&this->Source_File_List,Reporter_Source_File_Name,&index_counter);

     this->Source_File_List[index_counter] = '\0';

     //Determination of source file name matrix

     this->Source_File_Name_Matrix    = new char * [10];

     this->Source_File_Name_Matrix[0] = new char [10*Pointer_Source_File_Name_Size];

     this->Place_String(&this->Source_File_Name_Matrix[0],Pointer_Source_File_Name,Pointer_Source_File_Name_Size);

     this->Source_File_Name_Matrix[1] = new char [10*Manager_Source_File_Name_Size];

     this->Place_String(&this->Source_File_Name_Matrix[1],Manager_Source_File_Name,Manager_Source_File_Name_Size);

     this->Source_File_Name_Matrix[2] = new char [10*Reporter_Source_File_Name_Size];

     this->Place_String(&this->Source_File_Name_Matrix[2],Reporter_Source_File_Name,Reporter_Source_File_Name_Size);

     char * Pointer_New_Class_Name  = this->Pointer_Initializer.Get_NewClassName();

     char * Manager_New_Class_Name  = this->Manager_Initializer.Get_NewClassName();

     char * Reporter_New_Class_Name = this->Reporter_Initializer.Get_NewClassName();

     char Object_File_Extantion [] = {'.','o','\0'};

     int Pointer_New_Class_Name_Size  = strlen(Pointer_New_Class_Name);

     int Manager_New_Class_Name_Size  = strlen(Manager_New_Class_Name);

     int Reporter_New_Class_Name_Size = strlen(Reporter_New_Class_Name);

     int Object_File_List_Size = Pointer_New_Class_Name_Size + Manager_New_Class_Name_Size +

                                 Reporter_New_Class_Name_Size;

     this->Object_File_List = new char [10*Object_File_List_Size];

     index_counter = 0;

     this->Place_Information(&this->Object_File_List,Pointer_New_Class_Name,&index_counter);

     this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

     this->Add_Space(&this->Object_File_List,&index_counter);

     this->Place_Information(&this->Object_File_List,Manager_New_Class_Name,&index_counter);

     this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

     this->Add_Space(&this->Object_File_List,&index_counter);

     this->Place_Information(&this->Object_File_List,Reporter_New_Class_Name,&index_counter);

     this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

     this->Object_File_List[index_counter] = '\0';

     this->Object_File_Name_Matrix = new char * [10];

     this->Object_File_Name_Matrix[0] = new char [10*Pointer_New_Class_Name_Size ];

     index_counter = 0;

     this->Place_Information(&this->Object_File_Name_Matrix[0],Pointer_New_Class_Name,&index_counter);

     this->Place_Information(&this->Object_File_Name_Matrix[0],Object_File_Extantion,&index_counter);

     this->Object_File_Name_Matrix[0][index_counter] = '\0';

     index_counter = 0;

     this->Object_File_Name_Matrix[1] = new char [10*Manager_New_Class_Name_Size];

     this->Place_Information(&this->Object_File_Name_Matrix[1],Manager_New_Class_Name,&index_counter);

     this->Place_Information(&this->Object_File_Name_Matrix[1],Object_File_Extantion,&index_counter);

     this->Object_File_Name_Matrix[1][index_counter] = '\0';

     index_counter = 0;

     this->Object_File_Name_Matrix[2] = new char [10*Reporter_New_Class_Name_Size];

     this->Place_Information(&this->Object_File_Name_Matrix[2],Reporter_New_Class_Name,&index_counter);

     this->Place_Information(&this->Object_File_Name_Matrix[2],Object_File_Extantion,&index_counter);

     this->Object_File_Name_Matrix[2][index_counter] = '\0';
}

void Multi_Thread_Pointer_Data_Collector::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_List_Size = strlen(Information);

     for(int i=0;i<Information_List_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

void Multi_Thread_Pointer_Data_Collector::Add_Space(char ** Pointer,int * counter){

     (*Pointer)[(*counter)] = ' ';

     (*counter)++;
}

void Multi_Thread_Pointer_Data_Collector::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

char *  Multi_Thread_Pointer_Data_Collector::Get_Source_File_Name_List(){

        return this->Source_File_List;
}

char *  Multi_Thread_Pointer_Data_Collector::Get_Header_File_Name_List(){

        return this->Header_File_List;
}

char *  Multi_Thread_Pointer_Data_Collector::Get_Object_File_List(){

        return this->Object_File_List;
}

char ** Multi_Thread_Pointer_Data_Collector::Get_Header_File_Name_Matrix(){

        return this->Header_File_Name_Matrix;
}

char ** Multi_Thread_Pointer_Data_Collector::Get_Source_File_Name_Matrix(){

        return this->Source_File_Name_Matrix;
}

char ** Multi_Thread_Pointer_Data_Collector::Get_Object_File_Name_Matrix(){

        return this->Object_File_Name_Matrix;
}
