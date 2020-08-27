
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

#include "Multi_Thread_Pointer_Compile_Data_Collector.h"

Multi_Thread_Pointer_Compile_Data_Collector::Multi_Thread_Pointer_Compile_Data_Collector(){

      this->Memory_Delete_Condition = false;

      this->Compile_Command = nullptr;

      this->Include_Linker = nullptr;

      this->Compiler_Command_For_ReportFileBuilder = nullptr;

      this->Compiler_Command_For_Memory_Manager = nullptr;

      this->Compiler_Command_For_Pointer = nullptr;

      this->Include_Directory = nullptr;
};

Multi_Thread_Pointer_Compile_Data_Collector::Multi_Thread_Pointer_Compile_Data_Collector(const Multi_Thread_Pointer_Compile_Data_Collector & orig){

};

Multi_Thread_Pointer_Compile_Data_Collector::~Multi_Thread_Pointer_Compile_Data_Collector(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void Multi_Thread_Pointer_Compile_Data_Collector::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->Compile_Command);

         this->Clear_Pointer_Memory(&this->Include_Linker);

         this->Clear_Pointer_Memory(&this->Compiler_Command_For_ReportFileBuilder);

         this->Clear_Pointer_Memory(&this->Compiler_Command_For_Memory_Manager);

         this->Clear_Pointer_Memory(&this->Compiler_Command_For_Pointer);
     }
}

void Multi_Thread_Pointer_Compile_Data_Collector::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

void Multi_Thread_Pointer_Compile_Data_Collector::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Reader){

     this->Reader_Pointer = Reader;
}


void Multi_Thread_Pointer_Compile_Data_Collector::Receive_Pointer_Initializer_Adress(Builder_Initializer * Pointer){

     this->Pointer_Initializer = Pointer;
}

void Multi_Thread_Pointer_Compile_Data_Collector::Receive_Manager_Initializer_Adress(Builder_Initializer * Pointer){

     this->Manager_Initializer = Pointer;
}

void Multi_Thread_Pointer_Compile_Data_Collector::Receive_Reporter_Initializer_Adress(Builder_Initializer * Pointer){

     this->Reporter_Initializer = Pointer;
}

void Multi_Thread_Pointer_Compile_Data_Collector::Receive_Include_Directory(char * Directory){

     this->Include_Directory = Directory;
}

void Multi_Thread_Pointer_Compile_Data_Collector::Receive_Construction_Point(char * Construction_Point){

     this->Construction_Point_Holder = Construction_Point;
}

void Multi_Thread_Pointer_Compile_Data_Collector::Collect_Informations(){

     this->Memory_Delete_Condition = false;

     this->Directory_Manager.DetermineCurrentDirectory();

     this->Determine_Command_Informations();

     this->Determine_Include_Options_Size();

     this->Determine_Compiler_Command_For_Report_File_Builder();

     this->Determine_Compiler_Command_For_Memory_Manager();

     this->Determine_Compiler_Command_For_Smart_Pointer();
}

void Multi_Thread_Pointer_Compile_Data_Collector::Determine_Command_Informations(){

     char Compiler_Command [] = {'g','+','+',' ','-','c',' ','-','s','t','d','=','c','+','+','1','4','\0'};

     int String_Size = strlen(Compiler_Command);

     this->Memory_Delete_Condition = false;

     this->Compile_Command = new char [10*String_Size];

     this->Place_String(&this->Compile_Command,Compiler_Command,String_Size);

     char Include_Link_Determiner [] = {'-','I','\0'};

     String_Size = strlen(Include_Link_Determiner);

     this->Include_Linker = new char [10*String_Size];

     this->Place_String(&this->Include_Linker,Include_Link_Determiner,String_Size);
}

void Multi_Thread_Pointer_Compile_Data_Collector::Determine_Include_Options_Size()
{
     this->include_options_size = 0;

     int Header_File_Number_To_Be_Linked = this->Reader_Pointer->Get_Header_Files_Number();

     for(int i=0;i<Header_File_Number_To_Be_Linked;i++)
     {
         char * header_file_name = this->Reader_Pointer->Get_Header_File_Names()[i];

         this->include_options_size = this->include_options_size + strlen(header_file_name);
     }

     int Directory_Number_To_Be_Included = this->Reader_Pointer->Get_Include_Directory_Number();

     for(int i=0;i<Directory_Number_To_Be_Included;i++){

         Include_Directory_Type Data_Type_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

         char * Next_Directory = Data_Type_Holder.Include_Directory;

         this->include_options_size =  this->include_options_size + strlen(Next_Directory);
     }
}


void Multi_Thread_Pointer_Compile_Data_Collector::Determine_Compiler_Command_For_Report_File_Builder(){

     char * Source_File_Name = this->Reporter_Initializer->Get_ClassImplementationFileName();

     char * New_Header_Name  = this->Reporter_Initializer->Get_NewHeaderFileName();

     char Output_Redirection_Command [] = {'2','>','\0'};

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     char Space_Character [] = {' ','\0'};

     char Directory_Character [] = {'/','\0'};

     char Include_Linker [] = {'-','I','\0'};

     char Include_Word [] = {'-','i','n','c','l','u','d','e','\0'};

     int Source_File_Name_Size = strlen(Source_File_Name);

     int New_Header_Name_Size = strlen(New_Header_Name);

     int Compiler_input_Command_List_Size = strlen(this->Compile_Command);

     int Compiler_Command_Size = Compiler_input_Command_List_Size + New_Header_Name_Size +

                                 Source_File_Name_Size + this->include_options_size;

     this->Compiler_Command_For_ReportFileBuilder = new char [10*Compiler_Command_Size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,this->Compile_Command,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_ReportFileBuilder,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,this->Include_Linker,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);


     int Include_Directory_Number = this->Reader_Pointer->Get_Include_Directory_Number();

     for(int i=0;i<Include_Directory_Number;i++){

         Include_Directory_Type Data_Type_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

         char * Next_Directory = Data_Type_Holder.Include_Directory;

         this->Add_Space(&this->Compiler_Command_For_ReportFileBuilder,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Include_Linker,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Next_Directory,&index_counter);
     }

     this->Add_Space(&this->Compiler_Command_For_ReportFileBuilder,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Source_File_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_ReportFileBuilder,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Include_Word,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_ReportFileBuilder,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,New_Header_Name,&index_counter);

     int header_file_number_for_linking = this->Reader_Pointer->Get_Header_Files_Number();

     for(int i=0;i<header_file_number_for_linking;i++)
     {
         char * header_file_name = this->Reader_Pointer->Get_Header_File_Names()[i];

         this->Add_Space(&this->Compiler_Command_For_ReportFileBuilder,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Include_Word,&index_counter);

         this->Add_Space(&this->Compiler_Command_For_ReportFileBuilder,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,header_file_name,&index_counter);
     }

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Output_Redirection_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,this->Construction_Point_Holder,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_ReportFileBuilder,Error_Message_File_Name,&index_counter);

     this->Compiler_Command_For_ReportFileBuilder[index_counter] = '\0';
}


void Multi_Thread_Pointer_Compile_Data_Collector::Determine_Compiler_Command_For_Memory_Manager(){

     char * Source_File_Name = this->Manager_Initializer->Get_ClassImplementationFileName();

     char * New_Header_Name  = this->Manager_Initializer->Get_NewHeaderFileName();

     char * Header_Name = nullptr;

     if(this->Manager_Initializer->Get_Data_Type_Include_File_Name_Receive_Condition()){

         Header_Name = this->Manager_Initializer->Get_DataType_IncludeFileName();
     }

     bool Data_Type_Header_File_Name_Receive_Condition = this->Manager_Initializer->Get_Data_Type_Include_File_Name_Receive_Condition();

     bool Include_Directory_Receive_Condition = false;

     if(this->Include_Directory != nullptr){

        Include_Directory_Receive_Condition = true;
     }

     char Output_Redirection_Command [] = {'2','>','\0'};

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     char Space_Character [] = {' ','\0'};

     char Directory_Character [] = {'/','\0'};

     char Include_Linker [] = {'-','I','\0'};

     char Include_Word [] = {'-','i','n','c','l','u','d','e','\0'};

     char * ReportFileBuilder_Name = this->Reporter_Initializer->Get_ClassImplementationFileName();

     char * ReportFileBuilder_Header_File_Name = this->Reporter_Initializer->Get_NewHeaderFileName();

     int Source_File_Name_Size = strlen(Source_File_Name);

     int New_Header_Name_Size = strlen(New_Header_Name);

     int Compiler_Command_Size = Source_File_Name_Size + New_Header_Name_Size + strlen(this->Compiler_Command_For_ReportFileBuilder);

     this->Compiler_Command_For_Memory_Manager = new char [10*Compiler_Command_Size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Compile_Command,&index_counter);


     // DECLARATION OF THE DIRECTORIES TO BE INCLUDED ..

     int Include_Directory_Number = this->Reader_Pointer->Get_Include_Directory_Number();

     for(int i=0;i<Include_Directory_Number;i++){

         Include_Directory_Type Data_Type_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

         char * Next_Directory = Data_Type_Holder.Include_Directory;

         this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Include_Linker,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Next_Directory,&index_counter);
     }


     this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

     if((Data_Type_Header_File_Name_Receive_Condition) && (Include_Directory_Receive_Condition)){

        this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Include_Linker,&index_counter);

        this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Include_Directory,&index_counter);

        this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

        this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Include_Linker,&index_counter);

        this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

        this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);
     }

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Source_File_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,ReportFileBuilder_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,ReportFileBuilder_Header_File_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Include_Word,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,New_Header_Name,&index_counter);

     if((Data_Type_Header_File_Name_Receive_Condition) && (Include_Directory_Receive_Condition)){

         this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Include_Word,&index_counter);

         this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Include_Directory,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Directory_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Header_Name,&index_counter);
     }


     // DECLARATION OF THE HEADER FILES TO BE INCLUDED

     int header_file_number_for_linking = this->Reader_Pointer->Get_Header_Files_Number();

     for(int i=0;i<header_file_number_for_linking;i++)
     {
         char * header_file_name = this->Reader_Pointer->Get_Header_File_Names()[i];

         this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Include_Word,&index_counter);

         this->Add_Space(&this->Compiler_Command_For_Memory_Manager,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Memory_Manager,header_file_name,&index_counter);
     }


     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Output_Redirection_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,this->Construction_Point_Holder,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Memory_Manager,Error_Message_File_Name,&index_counter);

     this->Compiler_Command_For_Memory_Manager[index_counter] = '\0';
}

void Multi_Thread_Pointer_Compile_Data_Collector::Determine_Compiler_Command_For_Smart_Pointer(){

     char * Source_File_Name = this->Pointer_Initializer->Get_ClassImplementationFileName();

     char * New_Header_Name  = this->Pointer_Initializer->Get_NewHeaderFileName();

     char * Header_Name = nullptr;

     if(this->Pointer_Initializer->Get_Data_Type_Include_File_Name_Receive_Condition()){

        Header_Name = this->Pointer_Initializer->Get_DataType_IncludeFileName();
     }

     bool Data_Type_Header_File_Name_Receive_Condition = this->Pointer_Initializer->Get_Data_Type_Include_File_Name_Receive_Condition();

     bool Include_Directory_Receive_Condition = false;

     if(this->Include_Directory != nullptr){

        Include_Directory_Receive_Condition = true;
     }

     char Output_Redirection_Command [] = {'2','>','\0'};

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     char Space_Character [] = {' ','\0'};

     char Directory_Character [] = {'/','\0'};

     char Include_Linker [] = {'-','I','\0'};

     char Include_Word [] = {'-','i','n','c','l','u','d','e','\0'};

     char * Memory_Manager_File_Name   = this->Manager_Initializer->Get_ClassImplementationFileName();

     char * Memory_Manager_Header_Name = this->Manager_Initializer->Get_NewHeaderFileName();

     char * ReportFileBuilder_Name     = this->Reporter_Initializer->Get_ClassImplementationFileName();

     char * ReportFileBuilder_Header_File_Name = this->Reporter_Initializer->Get_NewHeaderFileName();

     int Source_File_Name_Size = strlen(Source_File_Name);

     int New_Header_Name_Size = strlen(New_Header_Name);

     int Compiler_Command_Size = Source_File_Name_Size + New_Header_Name_Size + strlen(this->Compiler_Command_For_Memory_Manager);

     this->Compiler_Command_For_Pointer = new char [10*Compiler_Command_Size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_Command_For_Pointer,this->Compile_Command,&index_counter);


     // DECLARATION OF THE DIRECTORIES TO BE INCLUDED ..

     int Include_Directory_Number = this->Reader_Pointer->Get_Include_Directory_Number();

     for(int i=0;i<Include_Directory_Number;i++){

         Include_Directory_Type Data_Type_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

         char * Next_Directory = Data_Type_Holder.Include_Directory;

         this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,Include_Linker,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,Next_Directory,&index_counter);
     }


     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     if((Data_Type_Header_File_Name_Receive_Condition) && (Include_Directory_Receive_Condition)){

         this->Place_Information(&this->Compiler_Command_For_Pointer,Include_Linker,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,this->Include_Directory,&index_counter);

         this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,Include_Linker,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

         this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);
     }

     this->Place_Information(&this->Compiler_Command_For_Pointer,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Source_File_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Memory_Manager_File_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,ReportFileBuilder_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Include_Word,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,New_Header_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Include_Word,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Memory_Manager_Header_Name,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Include_Word,&index_counter);

     this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,ReportFileBuilder_Header_File_Name,&index_counter);

     if((Data_Type_Header_File_Name_Receive_Condition) && (Include_Directory_Receive_Condition)){

         this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,Include_Word,&index_counter);

         this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,this->Include_Directory,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,Directory_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,Header_Name,&index_counter);
     }


     // DECLARATION OF THE HEADER FILES TO BE INCLUDED

     int header_file_number_for_linking = this->Reader_Pointer->Get_Header_Files_Number();

     for(int i=0;i<header_file_number_for_linking;i++)
     {
         char * header_file_name = this->Reader_Pointer->Get_Header_File_Names()[i];

         this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,Include_Word,&index_counter);

         this->Add_Space(&this->Compiler_Command_For_Pointer,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Pointer,header_file_name,&index_counter);
     }

     this->Place_Information(&this->Compiler_Command_For_Pointer,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Output_Redirection_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,this->Construction_Point_Holder,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Pointer,Error_Message_File_Name,&index_counter);

     this->Compiler_Command_For_Pointer[index_counter] = '\0';
}

void Multi_Thread_Pointer_Compile_Data_Collector::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_List_Size = strlen(Information);

     for(int i=0;i<Information_List_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

void Multi_Thread_Pointer_Compile_Data_Collector::Add_Space(char ** Pointer,int * counter){

     (*Pointer)[(*counter)] = ' ';

     (*counter)++;
}

void Multi_Thread_Pointer_Compile_Data_Collector::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

char * Multi_Thread_Pointer_Compile_Data_Collector::Get_Compiler_Command_For_ReportFile_Builder(){

      return this->Compiler_Command_For_ReportFileBuilder;
}

char * Multi_Thread_Pointer_Compile_Data_Collector::Get_Compiler_Command_For_Memory_Manager_Builder(){

       return this->Compiler_Command_For_Memory_Manager;
}

char * Multi_Thread_Pointer_Compile_Data_Collector::Get_Compiler_Command_For_Pointer(){

       return this->Compiler_Command_For_Pointer;
}
