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

#include "TM_Client_Header_Builder.h"

TM_Client_Header_Builder::TM_Client_Header_Builder(){

    this->Construction_Point = nullptr;

    this->New_Include_Directory = nullptr;

    this->Inclusion_Word = nullptr;

    this->Memory_Delete_Condition = false;
}

TM_Client_Header_Builder::TM_Client_Header_Builder(const TM_Client_Header_Builder & orig){

}

TM_Client_Header_Builder::~TM_Client_Header_Builder(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
}

void TM_Client_Header_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->Inclusion_Word);

         this->File_Manager.Clear_Dynamic_Memory();
     }
}

void TM_Client_Header_Builder::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void TM_Client_Header_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->New_Include_Directory = this->Reader_Pointer->Get_Constructed_Include_Directory();
}

char TM_Client_Header_Builder::ConvertToUpper(char character){

     this->character = toupper(character);

     return this->character;
}

void TM_Client_Header_Builder::Determine_Inclusion_Word(){

     char Class_Name [ ] = {'T','M','_','C','l','i','e','n','t','\0'};

     int WordSize = strlen(Class_Name);

     this->Memory_Delete_Condition = false;

     this->Inclusion_Word = new char [10*WordSize];

     for(int i=0;i<WordSize;i++){

        this->Inclusion_Word[i] = this->ConvertToUpper(Class_Name[i]);
     }

     this->Inclusion_Word[WordSize]='_';

     this->Inclusion_Word[WordSize+1]= 'H';

     this->Inclusion_Word[WordSize+2]= '\0';
}

void TM_Client_Header_Builder::Move_Header_File(){

     this->Memory_Delete_Condition = false;

     char Header_File_Name [ ] = {'T','M','_','C','l','i','e','n','t','.','h','\0'};

     char Directory_Character [] = {'/','\0'};

     int Header_File_Name_Size = strlen(Header_File_Name);

     int New_Include_Directory_Name_Size = strlen(this->New_Include_Directory);

     int Construction_Point_Name_Size = strlen(this->Construction_Point);

     int Current_Path_Name_Size = Construction_Point_Name_Size + Header_File_Name_Size;

     int New_Path_Name_Size = New_Include_Directory_Name_Size + Header_File_Name_Size;

     char * Current_Path_Name = new char [10*Current_Path_Name_Size];

     char * New_Path_Name = new char [10*New_Path_Name_Size];

     int index_counter = 0;

     this->Place_Information(&Current_Path_Name,this->Construction_Point,&index_counter);

     this->Place_Information(&Current_Path_Name,Directory_Character,&index_counter);

     this->Place_Information(&Current_Path_Name,Header_File_Name,&index_counter);

     Current_Path_Name[index_counter] = '\0';

     index_counter = 0;

     this->Place_Information(&New_Path_Name,this->New_Include_Directory,&index_counter);

     this->Place_Information(&New_Path_Name,Directory_Character,&index_counter);

     this->Place_Information(&New_Path_Name,Header_File_Name,&index_counter);

     New_Path_Name[index_counter] = '\0';

     this->File_Manager.Move_File(New_Path_Name,Current_Path_Name);

     delete [] Current_Path_Name;

     delete [] New_Path_Name;
}

void TM_Client_Header_Builder::Build_Header_File(){

     this->Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     char * Supervisor_Class_Header_File_Name = this->Reader_Pointer->Get_Server_Class_Header_File_Name();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->Determine_Inclusion_Word();

     this->File_Manager.SetFilePath("TM_Client.h");

     this->File_Manager.FileOpen(RWC);

     this->File_Manager.WriteToFile("\n#ifndef ");

     this->File_Manager.WriteToFile(this->Inclusion_Word);

     this->File_Manager.WriteToFile("\n#define ");

     this->File_Manager.WriteToFile(this->Inclusion_Word);

     this->File_Manager.WriteToFile("\n");

     this->File_Manager.WriteToFile("\n#include \"itds.h\"");

     this->File_Manager.WriteToFile("\n#include \"Thread_Manager.h\"");

     this->File_Manager.WriteToFile("\n#include <string>");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("namespace ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("{");

     this->File_Manager.WriteToFile("\n");

     this->File_Manager.WriteToFile("\n  class TM_Client {");

     this->File_Manager.WriteToFile("\n  public:");

     this->File_Manager.WriteToFile("\n    TM_Client(thds * data_str, std::string Thread_Function_Name);");

     this->File_Manager.WriteToFile("\n    TM_Client(const TM_Client & orig);");

     this->File_Manager.WriteToFile("\n    virtual ~TM_Client();");

     this->File_Manager.WriteToFile("\n    void Connect(thds * data_str, std::string Thread_Function_Name);");

     this->File_Manager.WriteToFile("\n    void lock();");

     this->File_Manager.WriteToFile("\n    void unlock();");

     this->File_Manager.WriteToFile("\n    void barrier_wait();");

     this->File_Manager.WriteToFile("\n    void wait(int Number);");

     this->File_Manager.WriteToFile("\n    void switch_wait(int Number);");

     this->File_Manager.WriteToFile("\n     void start_serial(int start_number, int end_number, int thread_number);");

     this->File_Manager.WriteToFile("\n     void end_serial(int start_number, int end_number, int thread_number);");

     this->File_Manager.WriteToFile("\n    void wait(int Number, int Rescuer_Thread);");

     this->File_Manager.WriteToFile("\n    void wait_until_exit(int Number, int Rescuer_Thread);");

     this->File_Manager.WriteToFile("\n    void wait(std::string Function_Name, int Rescuer_Thread_Number);");

     this->File_Manager.WriteToFile("\n    void wait(std::string Function_Name);");

     this->File_Manager.WriteToFile("\n    void rescue(int Number);");

     this->File_Manager.WriteToFile("\n    void rescue(int Number, int Rescuer_Thread_Number);");

     this->File_Manager.WriteToFile("\n    void rescue(std::string Function_Name, int Rescuer_Thread_Number);");

     this->File_Manager.WriteToFile("\n    void Exit();");

     this->File_Manager.WriteToFile("\n    void yield();");

     this->File_Manager.WriteToFile("\n    int  Get_Thread_Number() const;");

     this->File_Manager.WriteToFile("\n    bool Get_Thread_Block_Status(int Thread_Number) const;");

     this->File_Manager.WriteToFile("\n    int  Get_Operational_Thread_Number() const;");

     this->File_Manager.WriteToFile("\n  private:");

     this->File_Manager.WriteToFile("\n    Thread_Manager * Connection_Pointer;");

     this->File_Manager.WriteToFile("\n  };");

     this->File_Manager.WriteToFile("\n};");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("#endif");

     this->File_Manager.FileClose();
}

void TM_Client_Header_Builder::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}
