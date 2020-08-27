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

#include "TM_Client_Builder.h"

TM_Client_Builder::TM_Client_Builder(){

     this->Memory_Delete_Condition = false;

     this->Compiler_Command = nullptr;

     this->Constructed_Include_Directory = nullptr;
}

TM_Client_Builder::TM_Client_Builder(const TM_Client_Builder & orig){

}

TM_Client_Builder::~TM_Client_Builder(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void TM_Client_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->Compiler_Command);

         this->Header_Builder.Clear_Dynamic_Memory();

         this->File_Manager.Clear_Dynamic_Memory();

         this->Directory_Manager.Clear_Dynamic_Memory();
     }
}

void TM_Client_Builder::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void TM_Client_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->Header_Builder.Receive_Descriptor_File_Reader(Pointer);

     this->Constructed_Include_Directory = this->Reader_Pointer->Get_Constructed_Include_Directory();
}

void TM_Client_Builder::Build_Thread_Manager_Client(){

     this->Header_Builder.Build_Header_File();

     this->Determine_Compiler_Command();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->File_Manager.SetFilePath("TM_Client.cpp");

     this->File_Manager.FileOpen(RWC);

     this->File_Manager.WriteToFile("\n\n #include \"TM_Client.h\"");

     this->File_Manager.WriteToFile("\n\n ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::TM_Client(thds * data, std::string Thread_Function_Name){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer = nullptr;");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connect(data,Thread_Function_Name);");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::TM_Client(const TM_Client & orig){");

     this->File_Manager.WriteToFile("\n\n }");

     this->File_Manager.WriteToFile("\n\n ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::~TM_Client(){");

     this->File_Manager.WriteToFile("\n\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::Connect(thds * dp, std::string Thread_Function_Name){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer = dp->itds_Pointer->Manager_Tsp;");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->Receive_Thread_ID(Thread_Function_Name,dp->Thread_Number);");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->barrier_wait();");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::lock(){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->lock();");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::unlock(){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->unlock();");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::Exit(){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->Exit();");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::yield(){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->yield();");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::barrier_wait(){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->barrier_wait();");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::wait(int Number){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->wait(Number);");

     this->File_Manager.WriteToFile("\n };");


     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::switch_wait(int Number){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->switch_wait(Number);");

     this->File_Manager.WriteToFile("\n };");


     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::start_serial(int start_number, int end_number, int thread_number){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->start_serial(start_number,end_number,thread_number);");

     this->File_Manager.WriteToFile("\n };");



     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::end_serial(int start_number, int end_number, int thread_number){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->end_serial(start_number,end_number,thread_number);");

     this->File_Manager.WriteToFile("\n };");




     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::wait(int Number, int Rescuer_Thread){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->wait(Number,Rescuer_Thread);");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::wait_until_exit(int Number, int Rescuer_Thread){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->wait_until_exit(Number,Rescuer_Thread);");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::wait(std::string Function_Name, int Resquer_Thread_Number){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->wait(Function_Name,Resquer_Thread_Number);");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::wait(std::string Function_Name){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->wait(Function_Name);");

     this->File_Manager.WriteToFile("\n };");



     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::rescue(int Number){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->rescue(Number);");

     this->File_Manager.WriteToFile("\n };");


     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::rescue(int Number, int Rescuer_Thread_Number){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->rescue(Number,Rescuer_Thread_Number);");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" void ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::rescue(std::string Function_Name, int Rescuer_Thread_Number){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("this->Connection_Pointer->rescue(Function_Name,Rescuer_Thread_Number);");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" int ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::Get_Thread_Number() const{");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("return this->Connection_Pointer->Get_Thread_Number();");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" bool ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::Get_Thread_Block_Status(int Thread_Number) const {");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(6);

     this->File_Manager.WriteToFile("return this->Connection_Pointer->Get_Thread_Block_Status(Thread_Number);");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile(" int ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::TM_Client::Get_Operational_Thread_Number() const {");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(5);

     this->File_Manager.WriteToFile("return this->Connection_Pointer->Get_Operational_Thread_Number();");

     this->File_Manager.WriteToFile("\n };");

     this->File_Manager.FileClose();

     this->Run_System_Commands();
}

void TM_Client_Builder::Determine_Compiler_Command(){

     char compile_command [] = {'g','+','+',' ','-','c',' ','-','s','t','d','=','c','+','+','1','4','\0'};

     char Include_Link_Determiner [] = {'-','I','\0'};

     char Include_Word [] = {'-','i','n','c','l','u','d','e','\0'};

     char space [] = {' ','\0'};

     char directory_character [] = {'/','\0'};

     char Header_File_Name [ ] = {'T','M','_','C','l','i','e','n','t','.','h','\0'};

     char Manager_Class_Header_File_Name [] = {'T','h','r','e','a','d','_','M','a','n','a','g','e','r','.','h','\0'};

     char Source_File_Name [ ] = {'T','M','_','C','l','i','e','n','t','.','c','p','p',' ','\0'};

     char itds_file [] = {'i','t','d','s','.','h','\0'};

     char Output_Redirection_Command [] = {'2','>','\0'};

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     this->Directory_Manager.DetermineCurrentDirectory();

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

     int Header_File_Number_To_Be_Linked = this->Reader_Pointer->Get_Header_Files_Number();

     for(int i=0;i<Header_File_Number_To_Be_Linked;i++)
     {
         char * header_file_name = this->Reader_Pointer->Get_Header_File_Names()[i];

         Variable_Header_File_Name_Size = Variable_Header_File_Name_Size + strlen(header_file_name);
     }

     int Include_Directory_Number_Memory_Allocation = this->Reader_Pointer->Get_Include_Directory_Number();


     for(int i=0;i<Include_Directory_Number_Memory_Allocation;i++){

         Include_Directory_Type Data_Type_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

         char * Next_Directory = Data_Type_Holder.Include_Directory;

         Variable_Header_File_Name_Size = Variable_Header_File_Name_Size + strlen(Next_Directory);
     }

     char * Current_Directory = this->Directory_Manager.GetCurrentlyWorkingDirectory();

     int New_Include_Directory_Name_Size = strlen(this->Constructed_Include_Directory);

     int Include_Directory_Name_Size = strlen(Current_Directory);

     int Command_Name_Size = strlen(compile_command);

     int Include_Link_Determiner_Size = strlen(Include_Link_Determiner);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int Source_File_Name_Size = strlen(Source_File_Name);

     int itds_file_name_size = strlen(itds_file);

     int Compiler_Command_Name_Size = Command_Name_Size + Source_File_Name_Size + Include_Link_Determiner_Size +

                                      Include_Directory_Name_Size +  Header_File_Name_Size + New_Include_Directory_Name_Size +

                                      Variable_Header_File_Name_Size + itds_file_name_size ;

     this->Memory_Delete_Condition = false;

     this->Compiler_Command = new char [10*Compiler_Command_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_Command,compile_command,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

     this->Place_Information(&this->Compiler_Command,Current_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Constructed_Include_Directory,&index_counter);

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

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Current_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Source_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Current_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Header_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Constructed_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Manager_Class_Header_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Constructed_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

     this->Place_Information(&this->Compiler_Command,itds_file,&index_counter);

     for(int i=0;i<Member_Class_Number;i++){

         this->Place_Information(&this->Compiler_Command,space,&index_counter);

         this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

         this->Place_Information(&this->Compiler_Command,space,&index_counter);

         this->Place_Information(&this->Compiler_Command,Class_Data_Type_List[i].Header_File_Location,&index_counter);

         this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

         this->Place_Information(&this->Compiler_Command,Class_Data_Type_List[i].Header_File_Name,&index_counter);
     }

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

     this->Place_Information(&this->Compiler_Command,this->Reader_Pointer->Get_Construction_Point(),&index_counter);

     this->Place_Information(&this->Compiler_Command,Error_Message_File_Name,&index_counter);

     this->Compiler_Command[index_counter] = '\0';
}

void TM_Client_Builder::Remove_Source_File(){

     char Source_File_Name [] = {'T','M','_','C','l','i','e','n','t','.','c','p','p','\0'};

     char Directory_Character [] = {'/','\0'};

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     int Construction_Point_Name_Size = strlen(Construction_Point);

     int Source_File_Name_Size = strlen(Source_File_Name);

     int File_Path_Size = Source_File_Name_Size + Construction_Point_Name_Size;

     char * File_Path = new char [10*File_Path_Size];

     int index_counter = 0;

     this->Place_Information(&File_Path,Construction_Point,&index_counter);

     this->Place_Information(&File_Path,Directory_Character,&index_counter);

     this->Place_Information(&File_Path,Source_File_Name,&index_counter);

     File_Path[index_counter] = '\0';

     this->File_Manager.DeleteFile(File_Path);

     delete [] File_Path;
}

void TM_Client_Builder::Write_Space(int Space_Number){

     for(int i=0;i<Space_Number;i++){

         this->File_Manager.WriteToFile(" ");
     }
}

void TM_Client_Builder::Run_System_Commands(){

     int system_return_value = this->System_Interface.System_Function(this->Compiler_Command);

     if(system_return_value != 0){

        std::cout << "\n\n";

        std::cerr << "An error occured in Thread_Manager_Client class building ..";

        std::cout << "\n\n";

        exit(1);
     }

     this->Header_Builder.Move_Header_File();

     this->Remove_Source_File();
}

void TM_Client_Builder::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}
