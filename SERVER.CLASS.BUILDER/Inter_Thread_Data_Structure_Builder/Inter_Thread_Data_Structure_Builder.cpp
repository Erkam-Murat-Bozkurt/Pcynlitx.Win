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

#include "Inter_Thread_Data_Structure_Builder.h"

Inter_Thread_Data_Structure_Builder::Inter_Thread_Data_Structure_Builder(){

       this->Memory_Delete_Condition = false;

       this->Reader_Pointer = nullptr;

       this->Header_File_Path = nullptr;

       this->Construction_Point = nullptr;

       this->New_Include_Directory = nullptr;
}

Inter_Thread_Data_Structure_Builder::Inter_Thread_Data_Structure_Builder(const Inter_Thread_Data_Structure_Builder & orig){

}

Inter_Thread_Data_Structure_Builder::~Inter_Thread_Data_Structure_Builder(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
}

void Inter_Thread_Data_Structure_Builder::Clear_Dynamic_Memory(){

      if(!this->Memory_Delete_Condition){

          this->Memory_Delete_Condition = true;

          if(this->Header_File_Path != nullptr){

             delete [] this->Header_File_Path;
          }

          this->File_Manager.Clear_Dynamic_Memory();
      }
}

void Inter_Thread_Data_Structure_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Reader_Pointer){

     this->Reader_Pointer = Reader_Pointer;

     this->New_Include_Directory = this->Reader_Pointer->Get_Constructed_Include_Directory();

     this->Construction_Point = this->Reader_Pointer->Get_Construction_Point();
}

void Inter_Thread_Data_Structure_Builder::Build_Inter_Thread_Data_Structure(){

     char * Server_Class_Name = this->Reader_Pointer->Get_Server_Class_Name();

     char * Namespace = this->Reader_Pointer->Get_Namespace();

     this->File_Manager.SetFilePath("itds.h");

     this->File_Manager.FileOpen(RWC);

     this->File_Manager.WriteToFile("\n #ifndef ITDS_H");

     this->File_Manager.WriteToFile("\n #define ITDS_H");

     this->File_Manager.WriteToFile("\n");

     this->File_Manager.WriteToFile("\n #include \"Thread_Manager.h\"");

     int Member_Class_Number = this->Reader_Pointer->Get_Class_Number();

     Class_Data_Type * Class_Data_Type_List = this->Reader_Pointer->Get_Class_Names();

     if(Member_Class_Number > 0){

        for(int i=0;i<Member_Class_Number;i++){

            this->FunctionReader.Receive_Include_Directory_PATH(Class_Data_Type_List[i].Header_File_Location);

            this->FunctionReader.Receive_Construction_Point(this->Reader_Pointer->Get_Construction_Point());

            this->Determine_Header_File_Path(Class_Data_Type_List[i].Header_File_Location,Class_Data_Type_List[i].Header_File_Name);

            this->FunctionReader.Receive_Header_File_Path(this->Header_File_Path);

            this->FunctionReader.Read_Member_Functions();

            this->FunctionReader.Clear_Dynamic_Memory();
        }

        for(int i=0;i<Member_Class_Number;i++){

            this->File_Manager.WriteToFile("\n #include \"");

            this->File_Manager.WriteToFile(Class_Data_Type_List[i].Header_File_Name);

            this->File_Manager.WriteToFile("\"");
        }
     }

     int Shared_Data_Types_Include_File_Names_Number = this->Reader_Pointer->Get_Shared_Data_Types_Include_File_Names_Number();

     int Shared_Data_Types_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     Shared_Memory_Data_Type * Shared_Data_Type_List = this->Reader_Pointer->Get_Shared_Data_Types();

     if(Shared_Data_Types_Include_File_Names_Number > 0){

        for(int i=0;i<Shared_Data_Types_Number;i++){

            if(Shared_Data_Type_List[i].Include_Directory != nullptr){

               this->FunctionReader.Receive_Include_Directory_PATH(Shared_Data_Type_List[i].Include_Directory);

               this->FunctionReader.Receive_Construction_Point(this->Reader_Pointer->Get_Construction_Point());

               this->Determine_Header_File_Path(Shared_Data_Type_List[i].Include_Directory,Shared_Data_Type_List[i].Header_File_Name);

               this->FunctionReader.Receive_Header_File_Path(this->Header_File_Path);

               this->FunctionReader.Read_Member_Functions();

               this->FunctionReader.Clear_Dynamic_Memory();
           }
        }
     }

     if(Shared_Data_Types_Include_File_Names_Number > 0){

        for(int i=0;i<Shared_Data_Types_Number;i++){

            if(Shared_Data_Type_List[i].Header_File_Name != nullptr){

               this->File_Manager.WriteToFile("\n #include \"");

               this->File_Manager.WriteToFile(Shared_Data_Type_List[i].Header_File_Name);

               this->File_Manager.WriteToFile("\"");
            }
        }
     }

     for(int i=0;i<Shared_Data_Types_Number;i++){

       this->File_Manager.WriteToFile("\n #include \"");

       this->File_Manager.WriteToFile(Shared_Data_Type_List[i].Data_Type);

       this->File_Manager.WriteToFile("_Type_Smart_Pointer.h\"");
     }

     this->File_Manager.WriteToFile("\n");

     this->File_Manager.WriteToFile("\n namespace ");

     this->File_Manager.WriteToFile(Namespace);

     this->File_Manager.WriteToFile(" {");

     this->File_Manager.WriteToFile("\n");

     this->File_Manager.WriteToFile("\n   struct itds  // itds is an abbreviation for inter-thread data structure");

     this->File_Manager.WriteToFile("\n   {");

     for(int i=0;i<Member_Class_Number;i++){

         this->File_Manager.WriteToFile("\n    ");

         this->File_Manager.WriteToFile(Class_Data_Type_List[i].Class_Name);

         this->File_Manager.WriteToFile(" * ");

         this->File_Manager.WriteToFile(Class_Data_Type_List[i].Class_Instance_Name);

         this->File_Manager.WriteToFile("_Tsp;");

     }

     for(int i=0;i<Shared_Data_Types_Number;i++){

         this->File_Manager.WriteToFile("\n   ");

         this->File_Manager.WriteToFile(Shared_Data_Type_List[i].Data_Type);

         this->File_Manager.WriteToFile("_Type_Smart_Pointer * ");

         this->File_Manager.WriteToFile(Shared_Data_Type_List[i].Pointer_Name);

         this->File_Manager.WriteToFile("_Tsp;");

     }

     this->File_Manager.WriteToFile("\n    Thread_Manager * Manager_Tsp;");

     this->File_Manager.WriteToFile("\n   };");

     this->File_Manager.WriteToFile("\n");

     this->File_Manager.WriteToFile("\n   struct thds  // itds is an abbreviation for thread specific data structure");

     this->File_Manager.WriteToFile("\n   {");

     this->File_Manager.WriteToFile("\n     itds * itds_Pointer;");

     this->File_Manager.WriteToFile("\n     int Thread_Number;");

     this->File_Manager.WriteToFile("\n   };");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n #endif");

     this->File_Manager.FileClose();

     this->File_Manager.Clear_Dynamic_Memory();

     this->Move_Header_File();

     this->Clear_Dynamic_Memory();
}


void Inter_Thread_Data_Structure_Builder::Move_Header_File(){

     char Header_File_Name [ ] = {'i','t','d','s','.','h','\0'};

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


void Inter_Thread_Data_Structure_Builder::Determine_Header_File_Path(char * Header_File_Location, char * Header_File_Name){

     if(this->Header_File_Path != nullptr){

        delete [] this->Header_File_Path;
     }

     int Header_File_Location_Size = strlen(Header_File_Location);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int Header_File_Path_Size = Header_File_Location_Size + Header_File_Name_Size;

     this->Header_File_Path = new char [10*Header_File_Path_Size];

     int index_counter = 0;

     for(int i=0;i<Header_File_Location_Size;i++){

         this->Header_File_Path[index_counter] = Header_File_Location[i];

         index_counter++;
     }

     this->Header_File_Path[index_counter] = '/';

     index_counter++;

     for(int i=0;i<Header_File_Name_Size;i++){

        this->Header_File_Path[index_counter] = Header_File_Name[i];

        index_counter++;
     }

     this->Header_File_Path[index_counter] = '\0';
}

void Inter_Thread_Data_Structure_Builder::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}
