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

#include "Descriptor_File_Reader_Initializer.h"

Descriptor_File_Reader_Initializer::Descriptor_File_Reader_Initializer(){

     this->Memory_Delete_Condition = false;

     this->Include_Directory_List = nullptr;

     this->Library_Directory_List = nullptr;

     this->Source_File_Location_List = nullptr;

     this->Source_File_Name_List = nullptr;

     this->Main_File_Name = nullptr;

     this->Executable_File_Name = nullptr;

     this->Library_Name_List = nullptr;

     this->Header_File_List = nullptr;

     this->Inter_Thread_Class_Name_List = nullptr;

     this->Inter_Thread_Class_Instance_Name_List = nullptr;

     this->Shared_Data_Type_List = nullptr;

     this->Shared_Memory_Pointer_Name_List = nullptr;

     this->Shared_Data_Type_Header_File_List = nullptr;

     this->Supervisor_Class_Name = nullptr;

     this->Supervisor_Class_Header_File_Name = nullptr;

     this->Construction_Directory = nullptr;

     this->Thread_Name_List = nullptr;

     this->Namespace = nullptr;

     this->OpenMp_Support_Condition = nullptr;
}

Descriptor_File_Reader_Initializer::Descriptor_File_Reader_Initializer(const Descriptor_File_Reader_Initializer &){

}

Descriptor_File_Reader_Initializer::~Descriptor_File_Reader_Initializer(){

      if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
      }
}

void Descriptor_File_Reader_Initializer::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if((this->File_Data_Collector->Include_Directory_Numbers > 0) && (this->Include_Directory_List != nullptr)){

            for(int i=0;i<this->File_Data_Collector->Include_Directory_Numbers;i++){

                this->Clear_Pointer_Memory(&this->Include_Directory_List[i]);
            }

            delete [] this->Include_Directory_List;

            this->Include_Directory_List = nullptr;
         }

         if((this->File_Data_Collector->Source_File_Location_Number > 0) && (this->Source_File_Location_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Source_File_Location_Number;i++){

                 this->Clear_Pointer_Memory(&(this->Source_File_Location_List[i]));
             }

             delete [] this->Source_File_Location_List;

             this->Source_File_Location_List = nullptr;
         }

         if((this->File_Data_Collector->Source_File_Number > 0) && (this->Source_File_Name_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Source_File_Number ;i++){

                 this->Clear_Pointer_Memory(&(this->Source_File_Name_List[i]));
             }

             delete [] this->Source_File_Name_List;

             this->Source_File_Name_List = nullptr;
         }

         if((this->File_Data_Collector->Library_Directory_Number > 0) && (this->Library_Directory_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Library_Directory_Number;i++){

                this->Clear_Pointer_Memory(&this->Library_Directory_List[i]);
             }

             delete [] this->Library_Directory_List;

             this->Library_Directory_List = nullptr;
         }

         if((this->File_Data_Collector->Library_Names_Number > 0) && (this->Library_Name_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Library_Names_Number;i++){

                this->Clear_Pointer_Memory(&this->Library_Name_List[i]);
             }

             delete [] this->Library_Name_List;

             this->Library_Name_List = nullptr;
         }

         if((this->File_Data_Collector->Header_File_Names_Number > 0) && (this->Header_File_List != nullptr)){

            for(int i=0;i<this->File_Data_Collector->Header_File_Names_Number;i++){

                this->Clear_Pointer_Memory(&this->Header_File_List[i]);
            }

            delete [] this->Header_File_List;

            this->Header_File_List = nullptr;
         }

         if((this->File_Data_Collector->Inter_Thread_Class_Header_File_Names_Number > 0) && (this->Inter_Thread_Class_Header_File_List != nullptr)){

            for(int i=0;i<this->File_Data_Collector->Inter_Thread_Class_Header_File_Names_Number;i++){

                this->Clear_Pointer_Memory(&this->Inter_Thread_Class_Header_File_List[i]);
            }

            delete [] this->Inter_Thread_Class_Header_File_List;

            this->Inter_Thread_Class_Header_File_List = nullptr;
         }

         if((this->File_Data_Collector->Class_Number > 0) && (this->Inter_Thread_Class_Name_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Class_Number;i++){

                 this->Clear_Pointer_Memory(&this->Inter_Thread_Class_Name_List[i]);
             }

             delete [] this->Inter_Thread_Class_Name_List;

             this->Inter_Thread_Class_Name_List = nullptr;
         }

         if((this->File_Data_Collector->Class_Instance_Number > 0) && (this->Inter_Thread_Class_Instance_Name_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Class_Instance_Number;i++){

                 this->Clear_Pointer_Memory(&this->Inter_Thread_Class_Instance_Name_List[i]);
             }

             delete [] this->Inter_Thread_Class_Instance_Name_List;

             this->Inter_Thread_Class_Instance_Name_List = nullptr;
         }

         if((this->File_Data_Collector->Shared_Data_Types_Number > 0) && (this->Shared_Data_Type_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Shared_Data_Types_Number;i++){

                this->Clear_Pointer_Memory(&this->Shared_Data_Type_List[i]);
             }

             delete [] this->Shared_Data_Type_List;

             this->Shared_Data_Type_List = nullptr;
         }

         if((this->File_Data_Collector->Shared_Data_Types_Include_File_Names_Number > 0) && (this->Shared_Data_Type_Header_File_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Shared_Data_Types_Include_File_Names_Number;i++){

                 this->Clear_Pointer_Memory(&this->Shared_Data_Type_Header_File_List[i]);
             }

             delete [] this->Shared_Data_Type_Header_File_List;

             this->Shared_Data_Type_Header_File_List = nullptr;
         }

         if((this->File_Data_Collector->Shared_Data_Type_Pointer_Names_Number > 0) && (this->Shared_Memory_Pointer_Name_List != nullptr)){

             for(int i=0;i<this->File_Data_Collector->Shared_Data_Type_Pointer_Names_Number;i++){

                 this->Clear_Pointer_Memory(&this->Shared_Memory_Pointer_Name_List[i]);
             }

             delete [] this->Shared_Memory_Pointer_Name_List;

             this->Shared_Memory_Pointer_Name_List = nullptr;
         }

         if(this->Thread_Name_List != nullptr){

            for(int i=0;i<this->File_Data_Collector->Thread_Function_Number;i++){

                this->Clear_Pointer_Memory(&this->Thread_Name_List[i]);
            }

            delete [] this->Thread_Name_List;

            this->Thread_Name_List = nullptr;
         }

         if(this->File_Data_Collector->Namespace_Record_Number > 0 ){

            delete [] this->Namespace;

            this->Namespace = nullptr;

         }

         this->Clear_Pointer_Memory(&this->Construction_Directory);

         this->Clear_Pointer_Memory(&this->Supervisor_Class_Name);

         this->Clear_Pointer_Memory(&this->Supervisor_Class_Header_File_Name);

         this->Clear_Pointer_Memory(&this->Main_File_Name);

         this->Clear_Pointer_Memory(&this->Executable_File_Name);

         this->Clear_Pointer_Memory(&this->OpenMp_Support_Condition);
     }
}

void Descriptor_File_Reader_Initializer::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

void Descriptor_File_Reader_Initializer::Receve_Data_Collector(Descriptor_File_Data_Collector * Data_Collector){

     this->File_Data_Collector = Data_Collector;
}

void Descriptor_File_Reader_Initializer::Read_File_Lists(){

     this->Memory_Delete_Condition = false;

     if(this->File_Data_Collector->Include_Directory_Numbers > 0){

         this->Receive_Include_Directory_List();
     }

     if(this->File_Data_Collector->Source_File_Location_Number > 0){

        this->Receive_Source_File_Location_List();
     }

     if(this->File_Data_Collector->Library_Directory_Number > 0){

         this->Receive_Library_Directory_List();
     }

     if(this->File_Data_Collector->Source_File_Number > 0){

         this->Receive_Source_File_Name_List();
     }

     if(this->File_Data_Collector->Main_File_Name_Record_Number > 0){

        this->Receive_Main_File_Name();
     }

     if(this->File_Data_Collector->Executable_File_Name_Record_Number > 0){

        this->Receive_Executable_File_Name();
     }

     if(this->File_Data_Collector->Library_Names_Number > 0){

        this->Receive_Library_Name_List();
     }

     if(this->File_Data_Collector->Header_File_Names_Number > 0 ){

        this->Receive_Header_File_Names();
     }

     if(this->File_Data_Collector->Inter_Thread_Class_Header_File_Names_Number > 0){

        this->Receive_Inter_Thread_Class_Header_File_Names();
     }

     if(this->File_Data_Collector->Class_Number > 0 ){

        this->Receive_Inter_Thread_Class_Names();
     }

     if(this->File_Data_Collector->Class_Instance_Number > 0){

        this->Receive_Inter_Thread_Class_Instance_Names();
     }

     if(this->File_Data_Collector->Shared_Data_Types_Number > 0){

        this->Receive_Shared_Memory_Data_Types();
     }

     if(this->File_Data_Collector->Shared_Data_Type_Pointer_Names_Number > 0){

        this->Receive_Shared_Memory_Pointer_Names();
     }

     if(this->File_Data_Collector->Shared_Data_Types_Include_File_Names_Number > 0 ){

        this->Receive_Shared_Memory_Data_Types_Header_File_Names();
     }

     if(this->File_Data_Collector->Namespace_Record_Number > 0 ){

        this->Receive_Namespace();
     }

     if(this->File_Data_Collector->OpenMP_Support_Condition_Record_Number > 0 ){

        this->Receive_OpenMp_Support_Condition();
     }

     this->Receive_Construction_Point();

     this->Receive_Supervisor_Class_Name();

     this->Receive_Thread_Function_Names();

     this->Receive_Thread_Number();
}

void Descriptor_File_Reader_Initializer::Receive_Include_Directory_List(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Include_Directory_Record_Area[0];

     Record_End   = this->File_Data_Collector->Include_Directory_Record_Area[1];

     int Directory_Number = this->File_Data_Collector->Include_Directory_Numbers;

     this->Include_Directory_List = new char * [10*Directory_Number];

     int index_counter = 0;

     for(int i= Record_Start+1;i< Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Include_Directory_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&(this->Include_Directory_List[index_counter]),String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Library_Directory_List(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Library_Directories_Record_Area[0];

     Record_End   = this->File_Data_Collector->Library_Directories_Record_Area[1];

     int Directory_Number = this->File_Data_Collector->Library_Directory_Number;

     this->Library_Directory_List = new char * [10*Directory_Number];

     int index_counter = 0;

     for(int i= Record_Start+1;i< Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Library_Directory_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&(this->Library_Directory_List[index_counter]),String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Source_File_Location_List(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Source_File_Locations_Record_Area[0];

     Record_End   = this->File_Data_Collector->Source_File_Locations_Record_Area[1];

     int Directory_Number = this->File_Data_Collector->Source_File_Location_Number;

     this->Source_File_Location_List = new char * [10*Directory_Number];

     int index_counter = 0;

     for(int i= Record_Start+1;i< Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Source_File_Location_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&(this->Source_File_Location_List[index_counter]),String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Header_File_Names(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Header_File_Names_Record_Area[0];

     Record_End   = this->File_Data_Collector->Header_File_Names_Record_Area[1];

     int Directory_Number = this->File_Data_Collector->Header_File_Names_Number;

     this->Header_File_List= new char * [10*Directory_Number];

     int index_counter = 0;

     for(int i= Record_Start+1;i< Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Header_File_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&(this->Header_File_List[index_counter]),String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Source_File_Name_List(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Source_File_Names_Record_Area[0];

     Record_End   = this->File_Data_Collector->Source_File_Names_Record_Area[1];

     int Directory_Number = this->File_Data_Collector->Source_File_Number;

     this->Source_File_Name_List = new char * [10*Directory_Number];

     int index_counter = 0;

     for(int i= Record_Start+1;i< Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Source_File_Name_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&(this->Source_File_Name_List[index_counter]),String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Library_Name_List(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Library_Names_Record_Area[0];

     Record_End   = this->File_Data_Collector->Library_Names_Record_Area[1];

     int Directory_Number = this->File_Data_Collector->Library_Names_Number;

     this->Library_Name_List = new char * [10*Directory_Number];

     int index_counter = 0;

     for(int i= Record_Start+1;i< Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Library_Name_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&(this->Library_Name_List[index_counter]),String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Inter_Thread_Class_Header_File_Names(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Inter_Thread_Class_Header_File_Names_Record_Area[0];

     Record_End   = this->File_Data_Collector->Inter_Thread_Class_Header_File_Names_Record_Area[1];

     int Header_File_Names_Number = this->File_Data_Collector->Inter_Thread_Class_Header_File_Names_Number;

     this->Inter_Thread_Class_Header_File_List = new char * [10*Header_File_Names_Number];

     int index_counter = 0;

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Inter_Thread_Class_Header_File_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&(this->Inter_Thread_Class_Header_File_List[index_counter]),String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Inter_Thread_Class_Names(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Class_Names_Record_Area[0];

     Record_End   = this->File_Data_Collector->Class_Names_Record_Area[1];

     int Class_Number = this->File_Data_Collector->Class_Number;

     this->Inter_Thread_Class_Name_List = new char * [10*Class_Number];

     int index_counter = 0;

     for(int i=Record_Start+1;i< Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size =strlen(String_Line);

             this->Inter_Thread_Class_Name_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Inter_Thread_Class_Name_List[index_counter],String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Inter_Thread_Class_Instance_Names(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Class_Instance_Record_Area[0];

     Record_End   = this->File_Data_Collector->Class_Instance_Record_Area[1];

     int Class_Instance_Number = this->File_Data_Collector->Class_Instance_Number;

     this->Inter_Thread_Class_Instance_Name_List = new char * [10*Class_Instance_Number];

     int index_counter = 0;

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Inter_Thread_Class_Instance_Name_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Inter_Thread_Class_Instance_Name_List[index_counter],String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Shared_Memory_Data_Types(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Shared_Data_Types_Record_Area[0];

     Record_End   = this->File_Data_Collector->Shared_Data_Types_Record_Area[1];

     int Data_Type_Number = this->File_Data_Collector->Shared_Data_Types_Number;

     this->Shared_Data_Type_List = new char * [10*Data_Type_Number];

     int index_counter = 0;

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Shared_Data_Type_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Shared_Data_Type_List[index_counter],String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Shared_Memory_Pointer_Names(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Shared_Data_Type_Pointer_Names_Record_Area[0];

     Record_End   = this->File_Data_Collector->Shared_Data_Type_Pointer_Names_Record_Area[1];

     int Pointer_Names_Number = this->File_Data_Collector->Shared_Data_Type_Pointer_Names_Number;

     this->Shared_Memory_Pointer_Name_List = new char * [10*Pointer_Names_Number];

     int index_counter = 0;

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Shared_Memory_Pointer_Name_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Shared_Memory_Pointer_Name_List[index_counter],String_Line,String_Size);

             index_counter++;
         }
    }
}

void Descriptor_File_Reader_Initializer::Receive_Shared_Memory_Data_Types_Header_File_Names(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Shared_Data_Types_Include_Files_Record_Area[0];

     Record_End   = this->File_Data_Collector->Shared_Data_Types_Include_Files_Record_Area[1];

     int Data_Type_Number = this->File_Data_Collector->Shared_Data_Types_Number;

     this->Shared_Data_Type_Header_File_List = new char * [10*Data_Type_Number];

     int index_counter = 0;

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Shared_Data_Type_Header_File_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Shared_Data_Type_Header_File_List[index_counter],String_Line,String_Size);

             index_counter++;
         }
     }

     for(int i=index_counter;i<Data_Type_Number;i++){

         this->Shared_Data_Type_Header_File_List[i] = nullptr;
     }
}

void Descriptor_File_Reader_Initializer::Receive_Construction_Point(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Supervisor_Class_Construction_Point_Record_Area[0];

     Record_End   = this->File_Data_Collector->Supervisor_Class_Construction_Point_Record_Area[1];

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Construction_Directory = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Construction_Directory,String_Line,String_Size);
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Main_File_Name(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Main_File_Name_Record_Area[0];

     Record_End   = this->File_Data_Collector->Main_File_Name_Record_Area[1];

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Main_File_Name = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Main_File_Name,String_Line,String_Size);
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Namespace(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Namespace_Record_Area[0];

     Record_End   = this->File_Data_Collector->Namespace_Record_Area[1];

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Namespace = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Namespace,String_Line,String_Size);
         }
     }
}


void Descriptor_File_Reader_Initializer::Receive_OpenMp_Support_Condition(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->OpenMP_Support_Record_Area[0];

     Record_End   = this->File_Data_Collector->OpenMP_Support_Record_Area[1];

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->OpenMp_Support_Condition = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->OpenMp_Support_Condition,String_Line,String_Size);
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Executable_File_Name(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Executable_File_Name_Record_Area[0];

     Record_End   = this->File_Data_Collector->Executable_File_Name_Record_Area[1];

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Executable_File_Name = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Executable_File_Name,String_Line,String_Size);
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Supervisor_Class_Name(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Supervisor_Class_Name_Record_Area[0];

     Record_End   = this->File_Data_Collector->Supervisor_Class_Name_Record_Area[1];

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Supervisor_Class_Name = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Supervisor_Class_Name,String_Line,String_Size);
           }
       }

       int Supervisor_Class_Name_Size = strlen(this->Supervisor_Class_Name);

       this->Supervisor_Class_Header_File_Name =  new char [10*Supervisor_Class_Name_Size];

       for(int i=0;i<Supervisor_Class_Name_Size;i++){

          this->Supervisor_Class_Header_File_Name[i] = this->Supervisor_Class_Name[i];
       }

       this->Supervisor_Class_Header_File_Name[Supervisor_Class_Name_Size] = '.';

       this->Supervisor_Class_Header_File_Name[Supervisor_Class_Name_Size+1] = 'h';

       this->Supervisor_Class_Header_File_Name[Supervisor_Class_Name_Size+2] = '\0';
}

void Descriptor_File_Reader_Initializer::Receive_Thread_Function_Names(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Thread_Names_Record_Area[0];

     Record_End   = this->File_Data_Collector->Thread_Names_Record_Area[1];

     int Thread_Number = this->File_Data_Collector->Thread_Function_Number;

     this->Thread_Name_List = new char * [10*Thread_Number];

     int index_counter = 0;

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             int String_Size = strlen(String_Line);

             this->Thread_Name_List[index_counter] = new char [10*String_Size];

             this->File_Data_Collector->Place_String(&this->Thread_Name_List[index_counter],String_Line,String_Size);

             index_counter++;
         }
     }
}

void Descriptor_File_Reader_Initializer::Receive_Thread_Number(){

     int Record_Start = 0, Record_End = 0;

     Record_Start = this->File_Data_Collector->Thread_Numbers_Record_Area[0];

     Record_End   = this->File_Data_Collector->Thread_Numbers_Record_Area[1];

     this->Thread_Number = 0;

     int index_counter = 0, Record_Line_Number = 0;

     for(int i=Record_Start+1;i<Record_End;i++){

         this->File_Data_Collector->StringOperations.ReadFileLine(i);

         char * String_Line = this->File_Data_Collector->StringOperations.GetStringBuffer();

         if((String_Line[0]!= '\0') && (String_Line[0]!= '\n')){

             Record_Line_Number = i;
         }
     }

     if(Record_Line_Number != 0){

        char * Record_Line = this->File_Data_Collector->StringOperations.ReadFileLine(Record_Line_Number);

        int String_Size = strlen(Record_Line);

        char * Record_Number_Pointer = new char [10*String_Size];

        for(int i=0;i<String_Size;i++){

            while(Record_Line[i] == ' '){

                  i++;
            }

            Record_Number_Pointer[index_counter] = Record_Line[i];

            index_counter++;
        }

        Record_Number_Pointer[index_counter] = '\0';

        this->Thread_Number = this->Translater.TranslateFromCharToInt(Record_Number_Pointer);

        delete [] Record_Number_Pointer;
     }

     if(this->Thread_Number == 0){

        std::cerr << "\n";

        std::cerr << "\n  # ERROR MESSAGE";

        std::cerr << "\n";

        std::cerr << "\n  # Error Type: Descriptor File Read Error";

        std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

        std::cerr << "\n\n  {";

        std::cerr << "\n       Thread number can not be determined..,";

        std::cerr << "\n";

        std::cerr << "\n       There is no thread number decleration..";

        std::cerr << "\n";

        std::cerr << "\n       Please check thread number description.";

        std::cerr << "\n  }";

        std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";

        exit(EXIT_FAILURE);
     }
}


char * Descriptor_File_Reader_Initializer::Get_Main_File_Name() const
{
       return this->Main_File_Name;
}

char * Descriptor_File_Reader_Initializer::Get_Namespace() const
{
       return this->Namespace;
}

char * Descriptor_File_Reader_Initializer::Get_OpenMP_Support_Condition() const
{
       return this->OpenMp_Support_Condition;
}

char * Descriptor_File_Reader_Initializer::Get_Executable_File_Name() const
{
       return this->Executable_File_Name;
}

char * Descriptor_File_Reader_Initializer::Get_Server_Class_Name() const
{
       return this->Supervisor_Class_Name;
}

char * Descriptor_File_Reader_Initializer::Get_Server_Class_Header_File_Name() const
{
       return this->Supervisor_Class_Header_File_Name;
}

char * Descriptor_File_Reader_Initializer::Get_Construction_Directory() const
{
       return this->Construction_Directory;
}

char ** Descriptor_File_Reader_Initializer::Get_Include_Directory_List() const
{
        return this->Include_Directory_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Library_Directory_List() const
{
        return this->Library_Directory_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Source_File_Location_List() const
{
        return this->Source_File_Location_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Library_Name_List() const
{
        return this->Library_Name_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Source_File_List() const
{
        return this->Source_File_Name_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Header_File_List() const
{
        return this->Header_File_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Inter_Thread_Class_Header_File_List() const
{
        return this->Inter_Thread_Class_Header_File_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Inter_Thread_Class_Names_List() const
{
        return this->Inter_Thread_Class_Name_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Inter_Thread_Class_Instance_Name_List() const
{
        return this->Inter_Thread_Class_Instance_Name_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Shared_Data_Type_List() const
{
        return this->Shared_Data_Type_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Shared_Memory_Pointer_Name_List() const
{
        return this->Shared_Memory_Pointer_Name_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Shared_Data_Type_Header_File_List() const
{
        return this->Shared_Data_Type_Header_File_List;
}

char ** Descriptor_File_Reader_Initializer::Get_Thread_Names_List() const
{
        return this->Thread_Name_List;
}

int Descriptor_File_Reader_Initializer::Get_Thread_Number() const
{
    return this->Thread_Number;
}
