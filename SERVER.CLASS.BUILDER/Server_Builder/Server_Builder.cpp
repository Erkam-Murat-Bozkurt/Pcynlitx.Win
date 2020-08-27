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

#include "Server_Builder.h"

Server_Builder::Server_Builder(){

      this->Memory_Delete_Condition = false;

      this->Server_Class_Object_File_Name = nullptr;

      this->Server_Class_Implementation_File_Name = nullptr;

      this->Compiler_Command_For_Server_Class = nullptr;
};

Server_Builder::Server_Builder(const Server_Builder & orig){

};

Server_Builder::~Server_Builder(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void Server_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->Server_Class_Implementation_File_Name);

         this->Clear_Pointer_Memory(&this->Compiler_Command_For_Server_Class);

         this->Clear_Pointer_Memory(&this->Server_Class_Object_File_Name);
     }
}

void Server_Builder::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void Server_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->Header_File_Builder.Receive_Descriptor_File_Reader(Pointer);
}

void Server_Builder::Receive_Newly_Constructed_Include_Directory(char * Newly_Constructed_Include_Directory){

     this->New_Include_Directory = Newly_Constructed_Include_Directory;
}

void Server_Builder::Build_Server_Class(){

     this->Memory_Delete_Condition = false;

     this->Directory_Manager.DetermineCurrentDirectory();

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->Directory_Manager.ChangeDirectory(Construction_Point);

     this->Header_File_Builder.Build_Server_Header_File();

     this->Determine_File_Names();

     this->FileManager.SetFilePath(this->Server_Class_Implementation_File_Name);

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n\n #include \"");

     char * Server_Class_Header_File_Name = this->Reader_Pointer->Get_Server_Class_Header_File_Name();

     this->FileManager.WriteToFile(Server_Class_Header_File_Name);

     this->FileManager.WriteToFile("\"");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" ");

     char * Server_Class_Name = this->Reader_Pointer->Get_Server_Class_Name();

     int Member_Class_Number = this->Reader_Pointer->Get_Class_Number();

     Class_Data_Type * Class_Data_Type_List = this->Reader_Pointer->Get_Class_Names();

     int Shared_Data_Types_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     Shared_Memory_Data_Type * Shared_Data_Type_List = this->Reader_Pointer->Get_Shared_Data_Types();


     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("(){");

     for(int i=0;i<Member_Class_Number;i++){

         this->FileManager.WriteToFile("\n\n");

         this->FileManager.WriteToFile("  this->Transfer_Pointers.");

         this->FileManager.WriteToFile(Class_Data_Type_List[i].Class_Instance_Name);

         this->FileManager.WriteToFile("_Tsp = ");

         this->FileManager.WriteToFile("&this->");

         this->FileManager.WriteToFile(Class_Data_Type_List[i].Class_Instance_Name);

         this->FileManager.WriteToFile(";");
     }

     for(int i=0;i<Shared_Data_Types_Number;i++){

         this->FileManager.WriteToFile("\n\n");

         this->FileManager.WriteToFile("  this->Transfer_Pointers.");

         this->FileManager.WriteToFile(Shared_Data_Type_List[i].Pointer_Name);

         this->FileManager.WriteToFile("_Tsp = ");

         this->FileManager.WriteToFile("&this->");

         this->FileManager.WriteToFile(Shared_Data_Type_List[i].Pointer_Name);

         this->FileManager.WriteToFile(";");
     }

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("  this->Transfer_Pointers.Manager_Tsp = ");

     this->FileManager.WriteToFile(" &this->Manager;");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("(const ");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile(" & orig){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" };");

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("::~");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("(){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" }");

     this->FileManager.FileClose();

     this->Write_Thread_Activation_Member_Function();

     this->Write_Join_Member_Function();

     this->Determine_Compiler_Command_For_Server_Class();

     this->FileManager.Clear_Dynamic_Memory();

     this->Directory_Manager.Clear_Dynamic_Memory();
}

void Server_Builder::Write_Thread_Activation_Member_Function(){

     char * Server_Class_Name = this->Reader_Pointer->Get_Server_Class_Name();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("::Activate(int Thread_Number, void (* Function_Name) (thds * arg)){");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space("void ");

     this->FileManager.WriteToFile("this->Thread_Data_Container[Thread_Number].itds_Pointer = &(this->Transfer_Pointers);");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space("void ");

     this->FileManager.WriteToFile("this->Thread_Data_Container[Thread_Number].Thread_Number = Thread_Number;");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space("void ");

     this->FileManager.WriteToFile("this->Thread[Thread_Number] = std::thread(Function_Name,&(this->Thread_Data_Container[Thread_Number]));");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Server_Builder::Write_Join_Member_Function(){

     char * Server_Class_Name = this->Reader_Pointer->Get_Server_Class_Name();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(Server_Class_Name);

     this->FileManager.WriteToFile("::Join(int Thread_Number){");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space("void ");

     this->FileManager.WriteToFile("this->Thread[Thread_Number].join();");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Server_Builder::Determine_File_Names(){

     char Cpp_Add_Word [] = {'.','c','p','p','\0'};

     char Object_Add_Word [] = {'.','o','\0'};

     char * Server_Class_Name = this->Reader_Pointer->Get_Server_Class_Name();

     int Class_Name_Size = strlen(Server_Class_Name);

     this->Server_Class_Implementation_File_Name = new char [10*Class_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->Server_Class_Implementation_File_Name,Server_Class_Name,&index_counter);

     this->Place_Information(&this->Server_Class_Implementation_File_Name,Cpp_Add_Word,&index_counter);

     this->Server_Class_Implementation_File_Name[index_counter] = '\0';

     this->Server_Class_Object_File_Name = new char [10*Class_Name_Size];

     index_counter = 0;

     this->Place_Information(&this->Server_Class_Object_File_Name,Server_Class_Name,&index_counter);

     this->Place_Information(&this->Server_Class_Object_File_Name,Object_Add_Word,&index_counter);

     this->Server_Class_Object_File_Name[index_counter] = '\0';
}

void Server_Builder::Determine_Compiler_Command_For_Server_Class(){

     char Compile_Command [] = {'g','+','+',' ','-','c',' ','-','s','t','d','=','c','+','+','1','4',' ','\0'};

     char Include_Therm [] = {'-','I','\0'};

     char Directory_Character [] = {'/','\0'};

     char Space_Character [] = {' ','\0'};

     char Header_Add_Word [] = {'.','h','\0'};

     char Type_Word [] = {'_','T','y','p','e','_','S','m','a','r','t','_','P','o','i','n','t','e','r','\0'};

     char Thread_Syncronization_Class [] = {'T','h','r','e','a','d','_','M','a','n','a','g','e','r','.','h','\0'};

     char Thread_Syncronization_Class_Data_manager [] = {'T','h','r','e','a','d','_','D','a','t','a','_','M','a','n','a','g','e','r','.','h','\0'};

     char itds_file [] = {'i','t','d','s','.','h','\0'};

     char Include_Word [] = {'-','i','n','c','l','u','d','e','\0'};

     char Output_Redirection_Command [] = {'2','>','\0'};

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     int String_Length = 0;

     this->Update_String_Length(Compile_Command,&String_Length);

     int Member_Class_Number = this->Reader_Pointer->Get_Class_Number();

     Class_Data_Type * Class_Data_Type_List = this->Reader_Pointer->Get_Class_Names();

     for(int i=0;i<Member_Class_Number;i++){

         this->Update_String_Length(this->New_Include_Directory,&String_Length);

         this->Update_String_Length(Class_Data_Type_List[i].Class_Name,&String_Length);

         this->Update_String_Length(Header_Add_Word,&String_Length);
     }

     for(int i=0;i<Member_Class_Number;i++){

         this->Update_String_Length(this->New_Include_Directory,&String_Length);

         this->Update_String_Length(Class_Data_Type_List[i].Class_Name,&String_Length);

         this->Update_String_Length(Header_Add_Word,&String_Length);
     }

     int Shared_Data_Types_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     Shared_Memory_Data_Type * Shared_Data_Type_List = this->Reader_Pointer->Get_Shared_Data_Types();

     for(int i=0;i<Shared_Data_Types_Number;i++){

         this->Update_String_Length(this->New_Include_Directory,&String_Length);

         this->Update_String_Length(Shared_Data_Type_List[i].Data_Type,&String_Length);

         this->Update_String_Length(Type_Word,&String_Length);

         this->Update_String_Length(Header_Add_Word,&String_Length);
     }

     for(int i=0;i<Shared_Data_Types_Number;i++){

         this->Update_String_Length(this->New_Include_Directory,&String_Length);

         this->Update_String_Length(Shared_Data_Type_List[i].Data_Type,&String_Length);

         this->Update_String_Length(Type_Word,&String_Length);

         this->Update_String_Length(Header_Add_Word,&String_Length);
     }

     this->Update_String_Length(this->New_Include_Directory,&String_Length);

     this->Update_String_Length(this->Server_Class_Implementation_File_Name,&String_Length);

     this->Update_String_Length(this->New_Include_Directory,&String_Length);

     char * Server_Class_Header_File_Name = this->Reader_Pointer->Get_Server_Class_Header_File_Name();

     this->Update_String_Length(Server_Class_Header_File_Name,&String_Length);

     this->Update_String_Length(this->Directory_Manager.GetCurrentlyWorkingDirectory(),&String_Length);

     int Include_Directory_Number = this->Reader_Pointer->Get_Include_Directory_Number();

     for(int i=0;i<Include_Directory_Number;i++){

         Include_Directory_Type Data_Type_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

         char * Next_Directory = Data_Type_Holder.Include_Directory;

         this->Update_String_Length(Next_Directory,&String_Length);
     }

     int Header_File_Number_To_Be_Linked = this->Reader_Pointer->Get_Header_Files_Number();

     for(int i=0;i<Header_File_Number_To_Be_Linked;i++)
     {
          char * header_file_name = this->Reader_Pointer->Get_Header_File_Names()[i];

          this->Update_String_Length(header_file_name,&String_Length);
     }

     this->Compiler_Command_For_Server_Class = new char [10*String_Length];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Compile_Command,&index_counter);

     for(int i=0;i<Include_Directory_Number;i++){

         Include_Directory_Type Data_Type_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

         char * Next_Directory = Data_Type_Holder.Include_Directory;

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Therm,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Next_Directory,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);
     }

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Therm,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,this->New_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Construction_Point,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,this->Server_Class_Implementation_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,this->New_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Server_Class_Header_File_Name,&index_counter);

     for(int i=0;i<Shared_Data_Types_Number;i++){

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Word,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,this->New_Include_Directory,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Directory_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Shared_Data_Type_List[i].Data_Type,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Type_Word,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Header_Add_Word,&index_counter);
     }

     for(int i=0;i<Member_Class_Number;i++){

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Word,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Class_Data_Type_List[i].Header_File_Location,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Directory_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Class_Data_Type_List[i].Header_File_Name,&index_counter);
     }

     for(int i=0;i<Shared_Data_Types_Number;i++){

         if(Shared_Data_Type_List[i].Header_File_Name != nullptr){

            this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

            this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Word,&index_counter);

            this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

            this->Place_Information(&this->Compiler_Command_For_Server_Class,Shared_Data_Type_List[i].Include_Directory,&index_counter);

            this->Place_Information(&this->Compiler_Command_For_Server_Class,Directory_Character,&index_counter);

            this->Place_Information(&this->Compiler_Command_For_Server_Class,Shared_Data_Type_List[i].Header_File_Name,&index_counter);
         }
     }

     // Add Thread_Manager class

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,this->New_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Thread_Syncronization_Class,&index_counter);


     // Add Thread_Data_Manager class

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,this->New_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Thread_Syncronization_Class_Data_manager,&index_counter);


     // Add itds_file

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,this->New_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,itds_file,&index_counter);


     int header_file_number_for_linking = this->Reader_Pointer->Get_Header_Files_Number();

     for(int i=0;i<header_file_number_for_linking;i++)
     {
         char * header_file_name = this->Reader_Pointer->Get_Header_File_Names()[i];

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Include_Word,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_Command_For_Server_Class,header_file_name,&index_counter);
     }

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Output_Redirection_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,this->Reader_Pointer->Get_Construction_Point(),&index_counter);

     this->Place_Information(&this->Compiler_Command_For_Server_Class,Error_Message_File_Name,&index_counter);

     this->Compiler_Command_For_Server_Class[index_counter] = '\0';
}

void Server_Builder::Remove_Source_File(){

     char Directory_Character [] = {'/','\0'};

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     int Source_File_Name_Size = strlen(this->Server_Class_Implementation_File_Name);

     int Construction_Point_Name_Size = strlen(Construction_Point);

     int Source_File_Path_Size = Source_File_Name_Size + Construction_Point_Name_Size;

     char * Source_File_Path = new char [10*Source_File_Path_Size];

     int index_counter = 0;

     this->Place_Information(&Source_File_Path,Construction_Point,&index_counter);

     this->Place_Information(&Source_File_Path,Directory_Character,&index_counter);

     this->Place_Information(&Source_File_Path,this->Server_Class_Implementation_File_Name,&index_counter);

     Source_File_Path[index_counter] = '\0';

     this->Directory_Manager.ChangeDirectory(Construction_Point);

     this->FileManager.DeleteFile(Source_File_Path);

     delete [] Source_File_Path;
}

void Server_Builder::Run_System_Commands(){

     this->Move_Header_File();

     int system_return_value = this->System_Interface.System_Function(this->Compiler_Command_For_Server_Class);

     if(system_return_value != 0){

        std::cerr << "An error occured in server class compiling ..!" << std::endl;

        exit(1);
     }

     this->Remove_Source_File();
}

void Server_Builder::Move_Header_File(){

     char * Server_Class_Header_File = this->Reader_Pointer->Get_Server_Class_Header_File_Name();

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     char Directory_Character [] = {'/','\0'};

     int Construction_Point_Name_Size = strlen(Construction_Point);

     int Header_File_Name_Size = strlen(Server_Class_Header_File);

     int Header_File_Path_Size = Construction_Point_Name_Size + Header_File_Name_Size;

     char * Header_File_Path = new char [10*Header_File_Path_Size];

     int index_counter = 0;

     this->Place_Information(&Header_File_Path,Construction_Point,&index_counter);

     this->Place_Information(&Header_File_Path,Directory_Character,&index_counter);

     this->Place_Information(&Header_File_Path,Server_Class_Header_File,&index_counter);

     Header_File_Path[index_counter] = '\0';

     int New_Include_Directory_Name_Size = strlen(this->New_Include_Directory);

     int Header_File_New_Path_Size = New_Include_Directory_Name_Size + Header_File_Name_Size;

     char * Header_File_New_Path = new char [10*Header_File_New_Path_Size];

     index_counter = 0;

     this->Place_Information(&Header_File_New_Path,this->New_Include_Directory,&index_counter);

     this->Place_Information(&Header_File_New_Path,Directory_Character,&index_counter);

     this->Place_Information(&Header_File_New_Path,Server_Class_Header_File,&index_counter);

     Header_File_New_Path[index_counter] = '\0';

     this->FileManager.Move_File(Header_File_New_Path,Header_File_Path);

     delete [] Header_File_Path;

     delete [] Header_File_New_Path;
}

void Server_Builder::Update_String_Length(char * String, int * String_Length){

     (*String_Length) = (*String_Length) + strlen(String);
}

void Server_Builder::Write_Space(const char * String){

     int String_Size = strlen(String);

     for(int i=0;i<String_Size+1;i++){

         this->FileManager.WriteToFile(" ");
     }
}

void Server_Builder::Write_Space(char * String){

     int String_Size = strlen(String);

     for(int i=0;i<String_Size+1;i++){

         this->FileManager.WriteToFile(" ");
     }
}

void Server_Builder::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void Server_Builder::Place_String(char ** Pointer, const char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void Server_Builder::Place_Information(char ** Pointer, char * String, int * index_counter){

     int String_Size = strlen(String);

     for(int i=0;i<String_Size;i++){

         (*Pointer)[(*index_counter)] = String[i];

         (*index_counter)++;
     }
}

char * Server_Builder::Get_Compiler_Command(){

       return this->Compiler_Command_For_Server_Class;
}

char * Server_Builder::Get_Server_Class_Object_File_Name(){

       return this->Server_Class_Object_File_Name;
}

char * Server_Builder::Get_Server_Class_Source_File_Name(){

       return this->Server_Class_Implementation_File_Name;
}
