
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

#include "Multi_Thread_Pointer_Client_Builder.h"

Multi_Thread_Pointer_Client_Builder::Multi_Thread_Pointer_Client_Builder(){

      this->Memory_Delete_Condition = false;

      this->Base_Class_Name = nullptr;

      this->Base_Class_Header_File_Name = nullptr;

      this->Data_Type = nullptr;

      this->Newly_Constructed_Include_Directory = nullptr;

      this->Reader_Pointer = nullptr;

      this->name_space_info = nullptr;

      this->Construction_Point = nullptr;

      this->Client_Class_Implementation_File_Name = nullptr;

      this->Client_Class_Object_File_Name = nullptr;

      this->Client_Class_Header_File_Name = nullptr;

      this->Client_Class_Name = nullptr;

      this->Smart_Pointer_Instance_Name = nullptr;
};

Multi_Thread_Pointer_Client_Builder::Multi_Thread_Pointer_Client_Builder(const Multi_Thread_Pointer_Client_Builder & orig){

};

Multi_Thread_Pointer_Client_Builder::~Multi_Thread_Pointer_Client_Builder(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};


void Multi_Thread_Pointer_Client_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

          this->Memory_Delete_Condition = true;

          this->Clear_Pointer_Memory(&this->Base_Class_Header_File_Name);

          this->Clear_Pointer_Memory(&this->Client_Class_Implementation_File_Name);

          this->Clear_Pointer_Memory(&this->Client_Class_Object_File_Name);

          this->Clear_Pointer_Memory(&this->Compiler_Command);

          this->FileManager.Clear_Dynamic_Memory();

          this->DirectoryManager.Clear_Dynamic_Memory();

          this->P_Header_Builder.Clear_Dynamic_Memory();
     }
}

void Multi_Thread_Pointer_Client_Builder::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void Multi_Thread_Pointer_Client_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->P_Header_Builder.Receive_Descriptor_File_Reader(Pointer);

     this->name_space_info = this->Reader_Pointer->Get_Namespace();

     this->Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     this->Newly_Constructed_Include_Directory = this->Reader_Pointer->Get_Constructed_Include_Directory();
}


void Multi_Thread_Pointer_Client_Builder::Receive_Base_Class_Name(char * Base_Class_Name){

     this->Base_Class_Name = Base_Class_Name;

     this->Determine_Base_Class_Header_File_Name();

     this->P_Header_Builder.Receive_Base_Class_Name(Base_Class_Name);

     this->P_Header_Builder.Receive_Base_Class_Header_File_Name(this->Base_Class_Header_File_Name);
}


void Multi_Thread_Pointer_Client_Builder::Determine_Base_Class_Header_File_Name(){

     char header_add [] = {'.','h','\0'};

     int Base_Class_Name_Size = strlen(this->Base_Class_Name);

     int Header_Add_Name_Size = strlen(header_add);

     int Header_Name_Size = Base_Class_Name_Size + Header_Add_Name_Size;

     this->Base_Class_Header_File_Name = new char [10*Header_Name_Size];

     int index_counter = 0;

     for(int i=0;i<Base_Class_Name_Size;i++){

         this->Base_Class_Header_File_Name[index_counter] = this->Base_Class_Name[i];

         index_counter++;
     }

     for(int i=0;i<Header_Name_Size;i++){

         this->Base_Class_Header_File_Name[index_counter] = header_add[i];

         index_counter++;
     }

     this->Base_Class_Header_File_Name[index_counter] = '\0';
}


void Multi_Thread_Pointer_Client_Builder::Receive_Data_Type(char * DataType){

     this->Data_Type = DataType;

     this->P_Header_Builder.Receive_Data_Type(DataType);
}

void Multi_Thread_Pointer_Client_Builder::Receive_Data_Type_Include_Directory(char * Data_Type_Include_Directory){

     this->Data_Type_Include_Directory = Data_Type_Include_Directory;
}

void Multi_Thread_Pointer_Client_Builder::Receive_Smart_Pointer_Instance_Name(char * Smart_Pointer_Instance_Name){

     this->Smart_Pointer_Instance_Name = Smart_Pointer_Instance_Name;
}

void Multi_Thread_Pointer_Client_Builder::Build_Pointer_Client(){

     this->Memory_Delete_Condition = false;

     this->name_space_info = this->Reader_Pointer->Get_Namespace();

     this->Newly_Constructed_Include_Directory = this->Reader_Pointer->Get_Constructed_Include_Directory();

     this->Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     // The header builder will be jump in to the director which has been constructed for the Header

     // files of the library to be constructed

     this->P_Header_Builder.Build_Header_File();

     // Client Class Header Builder Builded the header file.

     this->Client_Class_Header_File_Name = this->P_Header_Builder.Get_Client_Class_Header_File_Name();

     this->Client_Class_Name = this->P_Header_Builder.Get_Client_Class_Name();

     // The information about the constructed header file received from the header builder.

     this->DirectoryManager.DetermineCurrentDirectory();

     this->DirectoryManager.ChangeDirectory(this->Reader_Pointer->Get_Construction_Point());

     this->Determine_Client_Class_Implementation_File_Name();

     this->Determine_Include_Options_Size();

     this->Determine_Compiler_Command();

     this->Build_Class_Implementation_File();
}


void Multi_Thread_Pointer_Client_Builder::Build_Class_Implementation_File(){

     this->FileManager.SetFilePath(this->Client_Class_Implementation_File_Name);

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n\n #include \"");

     this->FileManager.WriteToFile(this->Client_Class_Header_File_Name);

     this->FileManager.WriteToFile("\"");


     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("(thds * arg){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connect_Condition = false;");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connect(arg);");

     this->FileManager.WriteToFile("\n };");


     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::~");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("(){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("\n };");


     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::Connect(thds * dp){");

     this->FileManager.WriteToFile("\n\n      this->Connect_Condition = true;");

     this->FileManager.WriteToFile("\n\n      this->Connection_Pointer = dp->itds_Pointer->");

     this->FileManager.WriteToFile(this->Smart_Pointer_Instance_Name);

     this->FileManager.WriteToFile("_Tsp;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n");



     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::New(int MemorySize){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->New(MemorySize);");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::New(){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->New();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::Delete(){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->Delete();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::Set_Report_File_Path(const char * FileName){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->Set_Report_File_Path(FileName);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::Set_Report_File_Path(char * FileName){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->Set_Report_File_Path(FileName);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::Jump_To_Start(){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->Jump_To_Start();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::Jump_To_End(){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->Jump_To_End();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::Disconnect(){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->Disconnect();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::Set_User_Thread_Number(int Number){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      this->Connection_Pointer->Set_User_Thread_Number(Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" & ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::operator * ( ){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("           return this->Connection_Pointer->operator * ( );");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" & ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::operator [] (const int & indexNumber){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("           return this->Connection_Pointer->operator [] (indexNumber);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" & ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::operator--(int arg){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("           return this->Connection_Pointer->operator--(arg);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");


     this->FileManager.WriteToFile(" ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" & ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("::operator++(int arg){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("           return this->Connection_Pointer->operator--(arg);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Client_Builder::Determine_Client_Class_Implementation_File_Name(){

     char * Client_Class_Name = this->P_Header_Builder.Get_Client_Class_Name();

     char cpp_add [] = {'.','c','p','p','\0'};

     char object_add [] = {'.','o','\0'};

     int Client_Class_Name_Size = strlen(Client_Class_Name);

     int cpp_add_size = strlen(cpp_add);

     int object_add_size = strlen(object_add);

     int file_name_size = Client_Class_Name_Size + cpp_add_size;

     this->Client_Class_Implementation_File_Name = new char [10*file_name_size];

     int index_counter = 0;

     for(int i=0;i<Client_Class_Name_Size;i++){

         this->Client_Class_Implementation_File_Name[index_counter] = Client_Class_Name[i];

         index_counter++;
     }

     for(int i=0;i<cpp_add_size;i++){

         this->Client_Class_Implementation_File_Name[index_counter] = cpp_add[i];

         index_counter++;
     }

     this->Client_Class_Implementation_File_Name[index_counter] = '\0';

     this->Client_Class_Object_File_Name = new char [10*file_name_size];

     index_counter = 0;

     for(int i=0;i<Client_Class_Name_Size;i++){

         this->Client_Class_Object_File_Name[index_counter] = Client_Class_Name[i];

         index_counter++;
     }

     for(int i=0;i<object_add_size;i++){

         this->Client_Class_Object_File_Name[index_counter] = object_add[i];

         index_counter++;
     }

     this->Client_Class_Object_File_Name[index_counter] = '\0';
}

void Multi_Thread_Pointer_Client_Builder::Determine_Include_Options_Size()
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

void Multi_Thread_Pointer_Client_Builder::Determine_Compiler_Command(){

     char compile_command [] = {'g','+','+',' ','-','c',' ','-','s','t','d','=','c','+','+','1','4','\0'};

     char Include_Link_Determiner [] = {'-','I','\0'};

     char Include_Word [] = {'-','i','n','c','l','u','d','e','\0'};

     char itds_file [] = {'i','t','d','s','.','h','\0'};

     char space [] = {' ','\0'};

     char directory_character [] = {'/','\0'};

     char Output_Redirection_Command [] = {'2','>','\0'};

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};


     Class_Data_Type * Class_Data_Type_List = this->Reader_Pointer->Get_Class_Names();

     int Member_Class_Number = this->Reader_Pointer->Get_Class_Number();

     Shared_Memory_Data_Type * Shared_Data_Type_List = this->Reader_Pointer->Get_Shared_Data_Types();

     int Shared_Data_Types_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();


     int Variable_Header_File_Name_Size = 0;

     for(int i=0;i<Member_Class_Number;i++){

         Variable_Header_File_Name_Size = Variable_Header_File_Name_Size + strlen(Class_Data_Type_List[i].Header_File_Location);

         Variable_Header_File_Name_Size = Variable_Header_File_Name_Size + strlen(Class_Data_Type_List[i].Header_File_Name);
     }

     for(int i=0;i<Shared_Data_Types_Number;i++){

         if(Shared_Data_Type_List[i].Header_File_Name != nullptr){

            Variable_Header_File_Name_Size = Variable_Header_File_Name_Size + strlen(Shared_Data_Type_List[i].Include_Directory);

            Variable_Header_File_Name_Size = Variable_Header_File_Name_Size + strlen(Shared_Data_Type_List[i].Header_File_Name);
         }
     }


     int Include_Directory_Name_Size = strlen(this->Newly_Constructed_Include_Directory);

     int Command_Name_Size = strlen(compile_command);

     int Include_Link_Determiner_Size = strlen(Include_Link_Determiner);

     int Base_Class_Header_File_Name_Size = strlen(this->Base_Class_Header_File_Name);

     int Client_Class_Name_Size = strlen(this->Client_Class_Name);

     int Client_Class_Header_File_Name_Size = strlen(this->Client_Class_Header_File_Name);

     int Construction_Point_Path_Size = strlen(this->Construction_Point);

     int Error_Message_File_Name_Size = strlen(Error_Message_File_Name);

     int itds_file_name_size = strlen(itds_file);

     int Compiler_Command_Name_Size = Command_Name_Size + Client_Class_Name_Size +

                                      Include_Link_Determiner_Size + Client_Class_Header_File_Name_Size +

                                      Base_Class_Header_File_Name_Size + Construction_Point_Path_Size +

                                      Include_Directory_Name_Size + Error_Message_File_Name_Size +

                                      itds_file_name_size + Variable_Header_File_Name_Size +

                                      this->include_options_size;

     this->Compiler_Command = new char [10*Compiler_Command_Name_Size];

     char * Server_Class_Header_File = this->Reader_Pointer->Get_Server_Class_Header_File_Name();

     int index_counter = 0;

     // Include directory declerations

     this->Place_Information(&this->Compiler_Command,compile_command,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Newly_Constructed_Include_Directory,&index_counter);

     if(this->Data_Type_Include_Directory != nullptr){

        this->Place_Information(&this->Compiler_Command,space,&index_counter);

        this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

        this->Place_Information(&this->Compiler_Command,this->Data_Type_Include_Directory,&index_counter);
     }

     // THE DECLARATIONOF THE DIRECTORIES TO BE INCLUDED

     int Include_Directory_Number = this->Reader_Pointer->Get_Include_Directory_Number();

     for(int i=0;i<Include_Directory_Number;i++){

         Include_Directory_Type Data_Type_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

         char * Next_Directory = Data_Type_Holder.Include_Directory;

         this->Place_Information(&this->Compiler_Command,space,&index_counter);

         this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

         this->Place_Information(&this->Compiler_Command,Next_Directory,&index_counter);
     }

     for(int i=0;i<Member_Class_Number;i++){

         this->Place_Information(&this->Compiler_Command,space,&index_counter);

         this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

         this->Place_Information(&this->Compiler_Command,Class_Data_Type_List[i].Header_File_Location,&index_counter);
     }

     for(int i=0;i<Shared_Data_Types_Number;i++){

         if(Shared_Data_Type_List[i].Header_File_Name != nullptr){

            this->Place_Information(&this->Compiler_Command,space,&index_counter);

            this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

            this->Place_Information(&this->Compiler_Command,Shared_Data_Type_List[i].Include_Directory,&index_counter);
         }
     }


     // Class implementation file name decleration

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Construction_Point,&index_counter);

     this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Client_Class_Implementation_File_Name,&index_counter);

     // Class header file name decleration

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Client_Class_Header_File_Name,&index_counter);


     // Base class header file name decleration

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Base_Class_Header_File_Name,&index_counter);


     // Inter-thread class header file name declerations

     for(int i=0;i<Member_Class_Number;i++){

         this->Place_Information(&this->Compiler_Command,space,&index_counter);

         this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

         this->Place_Information(&this->Compiler_Command,space,&index_counter);

         this->Place_Information(&this->Compiler_Command,Class_Data_Type_List[i].Header_File_Location,&index_counter);

         this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

         this->Place_Information(&this->Compiler_Command,Class_Data_Type_List[i].Header_File_Name,&index_counter);
      }


      // Shared data types header file name declerations

      for(int i=0;i<Shared_Data_Types_Number;i++){

          if(Shared_Data_Type_List[i].Header_File_Name != nullptr){

             this->Place_Information(&this->Compiler_Command,space,&index_counter);

             this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

             this->Place_Information(&this->Compiler_Command,space,&index_counter);

             this->Place_Information(&this->Compiler_Command,Shared_Data_Type_List[i].Include_Directory,&index_counter);

             this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

             this->Place_Information(&this->Compiler_Command,Shared_Data_Type_List[i].Header_File_Name,&index_counter);
          }
      }

      // The header files to be included ..

      int header_file_number_for_linking = this->Reader_Pointer->Get_Header_Files_Number();

      for(int i=0;i<header_file_number_for_linking;i++)
      {
          char * header_file_name = this->Reader_Pointer->Get_Header_File_Names()[i];

          this->Place_Information(&this->Compiler_Command,space,&index_counter);

          this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

          this->Place_Information(&this->Compiler_Command,space,&index_counter);

          this->Place_Information(&this->Compiler_Command,header_file_name,&index_counter);
      }

      this->Place_Information(&this->Compiler_Command,space,&index_counter);

      this->Place_Information(&this->Compiler_Command,Output_Redirection_Command,&index_counter);

      this->Place_Information(&this->Compiler_Command,space,&index_counter);

      this->Place_Information(&this->Compiler_Command,this->Construction_Point,&index_counter);

      this->Place_Information(&this->Compiler_Command,Error_Message_File_Name,&index_counter);

      this->Compiler_Command[index_counter] = '\0';
}

void Multi_Thread_Pointer_Client_Builder::Remove_Class_Implementation_File(){

     char directory_character [] = {'/','\0'};

     int Client_Class_Implementation_File_Name_Size = strlen(this->Client_Class_Implementation_File_Name);

     int Current_Directory_Directory_Path_Size = strlen(this->Construction_Point);

     int File_Name_Size = Current_Directory_Directory_Path_Size + Client_Class_Implementation_File_Name_Size;

     char * File_Name = new char [10*File_Name_Size];

     int index_counter = 0;

     this->Place_Information(&File_Name,this->Construction_Point,&index_counter);

     this->Place_Information(&File_Name,directory_character,&index_counter);

     this->Place_Information(&File_Name,this->Client_Class_Implementation_File_Name,&index_counter);

     File_Name[index_counter] = '\0';

     this->FileManager.DeleteFile(File_Name);

     delete [] File_Name;
}

void Multi_Thread_Pointer_Client_Builder::Remove_Header_Extra(){

     char gch_word [] = {'.','g','c','h','\0'};

     char directory_character [] = {'/','\0'};

     int Header_File_Name_Size = strlen(this->Client_Class_Header_File_Name);

     int Construction_Point_Path_Size = strlen(this->Construction_Point);

     int File_Name_Size = Construction_Point_Path_Size + Header_File_Name_Size;

     char * File_Name  = new char [10*File_Name_Size];

     int index_counter = 0;

     this->Place_Information(&File_Name,this->Construction_Point,&index_counter);

     this->Place_Information(&File_Name,directory_character,&index_counter);

     this->Place_Information(&File_Name,this->Client_Class_Header_File_Name,&index_counter);

     this->Place_Information(&File_Name,gch_word,&index_counter);

     File_Name[index_counter] = '\0';

     this->FileManager.DeleteFile(File_Name);

     delete [] File_Name;
}

void Multi_Thread_Pointer_Client_Builder::Run_System_Commands(){

     int system_return_value = system(this->Compiler_Command);

     if(system_return_value != 0){

        std::cerr << "\n An error occured in client class comiling ..";

        exit(1);
     }

     this->Remove_Class_Implementation_File();

     this->Remove_Header_Extra();
}

void Multi_Thread_Pointer_Client_Builder::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
}
