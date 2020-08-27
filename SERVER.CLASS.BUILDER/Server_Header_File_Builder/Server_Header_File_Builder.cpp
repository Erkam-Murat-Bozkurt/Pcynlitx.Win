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

#include "Server_Header_File_Builder.h"

Server_Header_File_Builder::Server_Header_File_Builder(){

     this->Memory_Delete_Condition = false;

     this->InclusionWord = nullptr;

     this->Reader_Pointer = nullptr;

     this->Construction_Point = nullptr;

     this->New_Include_Directory = nullptr;
};

Server_Header_File_Builder::Server_Header_File_Builder(const Server_Header_File_Builder & orig){

};

Server_Header_File_Builder::~Server_Header_File_Builder(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void Server_Header_File_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->InclusionWord != nullptr){

            delete [] this->InclusionWord;

            this->InclusionWord = nullptr;
         }

         this->FileManager.Clear_Dynamic_Memory();
     }
}

void Server_Header_File_Builder::Determine_Inclusion_Word(){

     char * Server_Class_Name = this->Reader_Pointer->Get_Server_Class_Name();

     int WordSize = strlen(Server_Class_Name);

     this->InclusionWord = new char [10*WordSize];

     for(int i=0;i<WordSize;i++){

        this->InclusionWord[i] = this->ConvertToUpper(Server_Class_Name[i]);
     }

     this->InclusionWord[WordSize]='_';

     this->InclusionWord[WordSize+1]= 'H';

     this->InclusionWord[WordSize+2]= '\0';
}

char Server_Header_File_Builder::ConvertToUpper(char character){

     this->character = toupper(character);

     return this->character;
}

void Server_Header_File_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->New_Include_Directory = this->Reader_Pointer->Get_Constructed_Include_Directory();

     this->Construction_Point = this->Reader_Pointer->Get_Construction_Point();
}

void Server_Header_File_Builder::Build_Server_Header_File(){

     this->Determine_Inclusion_Word();

     char * Server_Class_Header_File_Name =

          this->Reader_Pointer->Get_Server_Class_Header_File_Name();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     int Member_Class_Number = this->Reader_Pointer->Get_Class_Number();

     Class_Data_Type * Class_Data_Type_List = this->Reader_Pointer->Get_Class_Names();

     int Shared_Data_Types_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     Shared_Memory_Data_Type * Shared_Data_Type_List = this->Reader_Pointer->Get_Shared_Data_Types();


     this->FileManager.SetFilePath(Server_Class_Header_File_Name);

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n #ifndef ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n #define ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #include \"itds.h\"");

     this->FileManager.WriteToFile("\n #include <thread>");

     char * Server_Class_Name = this->Reader_Pointer->Get_Server_Class_Name();

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" namespace ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("{");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("  class ");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("  {\n");

     this->FileManager.WriteToFile("  public:");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("   ");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("   ");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("(const ");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile(" & orig);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("   ");

     this->FileManager.WriteToFile("virtual ~");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("();");

     this->FileManager.WriteToFile("\n   void Activate(int Thread_Number, void (* Function_Name) (thds * arg));");

     this->FileManager.WriteToFile("\n   void Join(int Thread_Number);");

     for(int i=0;i<Member_Class_Number;i++){

         this->FileManager.WriteToFile("\n   ");

         this->FileManager.WriteToFile(Class_Data_Type_List[i].Class_Name);

         this->FileManager.WriteToFile(" ");

         this->FileManager.WriteToFile(Class_Data_Type_List[i].Class_Instance_Name);

         this->FileManager.WriteToFile(";");
     }

     for(int i=0;i<Shared_Data_Types_Number;i++){

         this->FileManager.WriteToFile("\n  ");

         this->FileManager.WriteToFile(Shared_Data_Type_List[i].Data_Type);

         this->FileManager.WriteToFile("_Type_Smart_Pointer ");

         this->FileManager.WriteToFile(Shared_Data_Type_List[i].Pointer_Name);

         this->FileManager.WriteToFile(";");
     }

     this->FileManager.WriteToFile("\n   Thread_Manager Manager;");

     int Thread_Number = this->Reader_Pointer->Get_Thread_Number();

     char * Number = this->Translater.Translate(Thread_Number);

     this->FileManager.WriteToFile("\n   itds Transfer_Pointers;");

     this->FileManager.WriteToFile("\n   thds Thread_Data_Container[");

     this->FileManager.WriteToFile(Number);

     this->FileManager.WriteToFile("];");

     this->FileManager.WriteToFile("\n  private:");

     this->FileManager.WriteToFile("\n   std::thread Thread[");

     this->FileManager.WriteToFile(Number);

     this->FileManager.WriteToFile("];");

     this->FileManager.WriteToFile("\n  };");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n #endif");

     this->FileManager.FileClose();

     this->Move_Header_File();

     this->FileManager.Clear_Dynamic_Memory();

     this->Clear_Dynamic_Memory();
}

void Server_Header_File_Builder::Move_Header_File(){

     char * Header_File_Name = this->Reader_Pointer->Get_Server_Class_Header_File_Name();

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

     this->FileManager.Move_File(New_Path_Name,Current_Path_Name);

     delete [] Current_Path_Name;

     delete [] New_Path_Name;
}

void Server_Header_File_Builder::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}
