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

#include "Main_File_Descriptions_Reader.h"

Main_File_Descriptions_Reader::Main_File_Descriptions_Reader(){

     this->Memory_Delete_Condition = false;

     this->Construction_Point = nullptr;

     this->Server_Class_Name = nullptr;

     this->Server_Class_Header_File_Name = nullptr;

     this->Thread_Function_Names = nullptr;

     this->Main_File_Name = nullptr;

     this->Namespace = nullptr;

     this->OpenMP_Support_Condition = nullptr;

     this->Executable_File_Name = nullptr;

     this->Thread_Function_Number = 0;

     this->Thread_Number = 0;
}

Main_File_Descriptions_Reader::Main_File_Descriptions_Reader(const Main_File_Descriptions_Reader & orig){

}

Main_File_Descriptions_Reader::~Main_File_Descriptions_Reader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void Main_File_Descriptions_Reader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Thread_Function_Names != nullptr){

            for(int i=0;i<this->Thread_Function_Number;i++){

                this->Clear_Pointer_Memory(&this->Thread_Function_Names[i]);
            }

            delete [] this->Thread_Function_Names;

            this->Thread_Function_Names = nullptr;
         }

        this->Clear_Pointer_Memory(&this->Construction_Point);

        this->Clear_Pointer_Memory(&this->Server_Class_Name);

        this->Clear_Pointer_Memory(&this->Server_Class_Header_File_Name);

        this->Clear_Pointer_Memory(&this->Main_File_Name);

        this->Clear_Pointer_Memory(&this->Executable_File_Name);

        this->Clear_Pointer_Memory(&this->Namespace);

        this->Clear_Pointer_Memory(&this->OpenMP_Support_Condition);
     }
}

void Main_File_Descriptions_Reader::Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer){

     this->Data_Collector_Pointer = Pointer;
}

void Main_File_Descriptions_Reader::Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer){

     this->Initializer_Pointer = Pointer;
}

void Main_File_Descriptions_Reader::Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer){

     this->Number_Processor_Pointer = Pointer;
}

void Main_File_Descriptions_Reader::Set_Informations_Comes_From_Data_Collector(){

     this->Thread_Function_Number = this->Data_Collector_Pointer->Thread_Function_Number;

     this->Thread_Number = this->Initializer_Pointer->Get_Thread_Number();

     if(this->Thread_Function_Number > this->Thread_Number){

       this->Print_Read_Error_Information();

       std::cerr << "\n     In descriptions, the number of the function routine is more";

       std::cerr << "\n\n     than the thread number. In contrast, the number of the thread";

       std::cerr << "\n\n     must be equal or more than the number of thread function name.";

       std::cerr << "\n\n     Please check your descriptions.";

       std::cerr << "\n\n     The process will be interrupted ..";

       this->Print_End_of_Program();

       exit(EXIT_FAILURE);
     }
}

void Main_File_Descriptions_Reader::Read_Main_File_Descriptions(){

     this->Set_Informations_Comes_From_Data_Collector();

     this->Receive_Construction_Point();

     this->Receive_Server_Class_Name();

     this->Receive_Thread_Function_Names();

     if(this->Data_Collector_Pointer->Main_File_Name_Record_Number > 0){

        this->Receive_Main_File_Name();
     }

     if(this->Data_Collector_Pointer->Executable_File_Name_Record_Number > 0){

        this->Receive_Executable_File_Name();
     }

     if(this->Data_Collector_Pointer->Namespace_Record_Number > 0){

        this->Receive_Namespace();
     }
     else{

        char Namespace_Info [] = {'p','c','y','n','l','i','t','x','\0'};

        int Name_Size = strlen(Namespace_Info);

        this->Namespace = new char [10*Name_Size];

        this->Place_String(&this->Namespace,Namespace_Info);
     }

     if(this->Data_Collector_Pointer->OpenMP_Support_Condition_Record_Number > 0){

        this->Receive_OpenMP_Support_Condition();
     }
     else{

        char OpenMp_Info [] = {'f','a','l','s','e','\0'};

        int Condition_Size = strlen(OpenMp_Info);

        this->OpenMP_Support_Condition = new char [10*Condition_Size];

        this->Place_String(&this->OpenMP_Support_Condition,OpenMp_Info);
     }
}

void Main_File_Descriptions_Reader::Receive_Construction_Point(){

     char * String_Line = this->Initializer_Pointer->Get_Construction_Directory();

     int String_Size = strlen(String_Line);

     this->Construction_Point = new char [10*String_Size];

     this->Place_String(&this->Construction_Point,String_Line);
}

void Main_File_Descriptions_Reader::Receive_Main_File_Name(){

     char * File_Name = this->Initializer_Pointer->Get_Main_File_Name();

     int File_Name_Size = strlen(File_Name);

     this->Main_File_Name = new char [10*File_Name_Size];

     this->Place_String(&this->Main_File_Name,File_Name);
}

void Main_File_Descriptions_Reader::Receive_Namespace(){

     char * Namespace_Info = this->Initializer_Pointer->Get_Namespace();

     int Name_Size = strlen(Namespace_Info);

     this->Namespace = new char [10*Name_Size];

     this->Place_String(&this->Namespace,Namespace_Info);
}


void Main_File_Descriptions_Reader::Receive_OpenMP_Support_Condition(){

     char * OpenMP_Support = this->Initializer_Pointer->Get_OpenMP_Support_Condition();

     int Condition_Size = strlen(OpenMP_Support);

     this->OpenMP_Support_Condition = new char [10*Condition_Size];

     this->Place_String(&this->OpenMP_Support_Condition,OpenMP_Support);
}

void Main_File_Descriptions_Reader::Receive_Executable_File_Name(){

     char * File_Name = this->Initializer_Pointer->Get_Executable_File_Name();

     int File_Name_Size = strlen(File_Name);

     this->Executable_File_Name = new char [10*File_Name_Size];

     this->Place_String(&this->Executable_File_Name,File_Name);
}

void Main_File_Descriptions_Reader::Receive_Server_Class_Name(){

     char * Class_Name = this->Initializer_Pointer->Get_Server_Class_Name();

     int Class_Name_Size = strlen(Class_Name);

     this->Server_Class_Name = new char [10*Class_Name_Size];

     this->Place_String(&this->Server_Class_Name,Class_Name);

     char * Header_File_Name = this->Initializer_Pointer->Get_Server_Class_Header_File_Name();

     int Header_File_Name_Size = strlen(Header_File_Name);

     this->Server_Class_Header_File_Name =  new char [10*Header_File_Name_Size];

     this->Place_String(&this->Server_Class_Header_File_Name,Header_File_Name);
}

void Main_File_Descriptions_Reader::Receive_Thread_Function_Names(){

     this->Thread_Function_Names = new char * [10*this->Thread_Function_Number];

     for(int i=0;i<this->Thread_Function_Number;i++){

         char * String_Line = this->Initializer_Pointer->Get_Thread_Names_List()[i];

         int String_Size = strlen(String_Line);

         this->Thread_Function_Names[i] = new char [10*String_Size];

         this->Place_String(&(this->Thread_Function_Names[i]),String_Line);
     }
}

void Main_File_Descriptions_Reader::Clear_Pointer_Memory(char ** Pointer){

      if(*Pointer != nullptr){

          delete [] (*Pointer);

          *Pointer = nullptr;
      }
 }

 void Main_File_Descriptions_Reader::Place_String(char ** Pointer, char * String){

      int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String);

      int String_Size = strlen(String);

      int index_counter = 0;

      for(int i=Start_Point;i<String_Size;i++){

          (*Pointer)[index_counter] = String[i];

          index_counter++;
      }

      (*Pointer)[index_counter] = '\0';
 }

 int Main_File_Descriptions_Reader::Get_Thread_Function_Number() const{

     return this->Thread_Function_Number;
 }

 int Main_File_Descriptions_Reader::Get_Thread_Number() const {

     return this->Thread_Number;
 }

 char ** Main_File_Descriptions_Reader::Get_Thread_Function_Names() const {

         return this->Thread_Function_Names;
 }

 char * Main_File_Descriptions_Reader::Get_Main_File_Name() const {

        return this->Main_File_Name;
 }

 char * Main_File_Descriptions_Reader::Get_Namespace() const {

        return this->Namespace;
 }

 char * Main_File_Descriptions_Reader::Get_OpenMP_Support_Condition() const {

        return this->OpenMP_Support_Condition;
 }

 char * Main_File_Descriptions_Reader::Get_Executable_File_Name() const {

        return this->Executable_File_Name;
 }

 char * Main_File_Descriptions_Reader::Get_Server_Class_Name() const {

        return this->Server_Class_Name;
 }

 char * Main_File_Descriptions_Reader::Get_Server_Class_Header_File_Name() const{

        return this->Server_Class_Header_File_Name;
 }

 char * Main_File_Descriptions_Reader::Get_Construction_Point() const {

        return this->Construction_Point;
 }

void Main_File_Descriptions_Reader::Print_Read_Error_Information(){

     std::cerr << "\n";

     std::cerr << "\n  # ERROR MESSAGE";

     std::cerr << "\n";

     std::cerr << "\n  # Error Type: Descriptor File Read Error";

     std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

     std::cerr << "\n\n  {";
}

void Main_File_Descriptions_Reader::Print_End_of_Program(){

     std::cerr << "\n  }";

     std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";
}
