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

#include "ClassRebuilder_Data_Collector.h"

ClassRebuilder_Data_Collector::ClassRebuilder_Data_Collector(){

     this->Memory_Delete_Condition = false;

     this->Compiler_Command = nullptr;

     this->Object_File_Name = nullptr;

     this->Constructed_Include_Directory = nullptr;
}

ClassRebuilder_Data_Collector::ClassRebuilder_Data_Collector(const ClassRebuilder_Data_Collector & orig){

}

ClassRebuilder_Data_Collector::~ClassRebuilder_Data_Collector(){

}

void ClassRebuilder_Data_Collector::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Compiler_Command != nullptr){

            delete [] this->Compiler_Command;

            this->Compiler_Command = nullptr;
         }

         if(this->Object_File_Name != nullptr){

            delete [] this->Object_File_Name;

            this->Object_File_Name = nullptr;
         }

         this->File_Manager.Clear_Dynamic_Memory();

         this->Directory_Manager.Clear_Dynamic_Memory();
     }
}

void ClassRebuilder_Data_Collector::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;
}

void ClassRebuilder_Data_Collector::Receive_ClassRebuilder_Initializer(ClassRebuilder_Initializer * Pointer){

     this->Initializer = Pointer;
}

void ClassRebuilder_Data_Collector::Reiceve_Directory_Manager(DirectoryOperations * Pointer){

     this->Directory_Manager_Pointer = Pointer;
}

void ClassRebuilder_Data_Collector::Collect_System_Command_Informations(){

     this->Memory_Delete_Condition = false;

     this->Constructed_Include_Directory = this->Reader_Pointer->Get_Constructed_Include_Directory();

     this->Determine_Compiler_Command();
}

void ClassRebuilder_Data_Collector::Determine_Compiler_Command(){

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

     int Included_Header_Files_Number = this->Initializer->Get_Included_Header_Files_Number();


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

      for(int i=0;i<Included_Header_Files_Number;i++){

          std::string included_header_file_name = this->Initializer->Get_Header_File_Declarations()[i];

          Variable_Header_File_Name_Size = Variable_Header_File_Name_Size + included_header_file_name.length();
      }

     this->Directory_Manager_Pointer->DetermineCurrentDirectory();

     char * Header_File_Location = this->Initializer->Get_Base_Class_Header_File_Location();

     char * Header_File_Name = this->Initializer->Get_Base_Class_Header_File_Name();

     char * Server_Class_Header_File = this->Reader_Pointer->Get_Server_Class_Header_File_Name();

     int Include_Directory_Name_Size = strlen(Header_File_Location);

     int Command_Name_Size = strlen(compile_command);

     int Include_Link_Determiner_Size = strlen(Include_Link_Determiner);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int itds_file_name_size = strlen(itds_file);

     int New_Class_Name_Size = strlen(this->Initializer->Get_New_Class_Implementation_File_Name());

     int New_Class_Header_File_Name_Size = strlen(this->Initializer->Get_New_Header_File_Name());

     int Compiler_Command_Name_Size = Command_Name_Size + New_Class_Name_Size +

                                      Include_Link_Determiner_Size + itds_file_name_size +

                                      New_Class_Header_File_Name_Size + Header_File_Name_Size +

                                      Variable_Header_File_Name_Size;

     this->Compiler_Command = new char [10*Compiler_Command_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_Command,compile_command,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

     this->Place_Information(&this->Compiler_Command,Header_File_Location,&index_counter);

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

     this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Constructed_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Link_Determiner,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Directory_Manager_Pointer->GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Directory_Manager_Pointer->GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Initializer->Get_New_Class_Implementation_File_Name(),&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Constructed_Include_Directory,&index_counter);

     this->Place_Information(&this->Compiler_Command,directory_character,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Initializer->Get_New_Header_File_Name(),&index_counter);

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

     for(int i=0;i<Included_Header_Files_Number;i++)
     {
         char * Header_File_Name = this->Initializer->Get_Header_File_Names_C_String()[i];

         this->Place_Information(&this->Compiler_Command,space,&index_counter);

         this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

         this->Place_Information(&this->Compiler_Command,space,&index_counter);

         this->Place_Information(&this->Compiler_Command,Header_File_Name,&index_counter);
     }

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,Output_Redirection_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command,space,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Reader_Pointer->Get_Construction_Point(),&index_counter);

     this->Place_Information(&this->Compiler_Command,Error_Message_File_Name,&index_counter);

     this->Compiler_Command[index_counter] = '\0';

     this->Object_File_Name = new char [10*New_Class_Name_Size];

     index_counter = 0;

     this->Place_Information(&this->Object_File_Name,this->Initializer->Get_New_Class_Name(),&index_counter);

     this->Object_File_Name[index_counter] = '.';

     index_counter++;

     this->Object_File_Name[index_counter] = 'o';

     index_counter++;

     this->Object_File_Name[index_counter] = '\0';
}

void ClassRebuilder_Data_Collector::Remove_Class_Implementation_File(){

     char directory_character [] = {'/','\0'};

     this->Directory_Manager.DetermineCurrentDirectory();

     char * Current_Directory = this->Directory_Manager.GetCurrentlyWorkingDirectory();

     char * New_Class_Implementation_File_Name = this->Initializer->Get_New_Class_Implementation_File_Name();

     int New_Class_Implementation_File_Name_Size = strlen(New_Class_Implementation_File_Name);

     int Current_Directory_Name_Size = strlen(Current_Directory);

     int File_Name_Size = Current_Directory_Name_Size + New_Class_Implementation_File_Name_Size;

     char * File_Name = new char [10*File_Name_Size];

     int index_counter = 0;

     this->Place_Information(&File_Name,Current_Directory,&index_counter);

     this->Place_Information(&File_Name,directory_character,&index_counter);

     this->Place_Information(&File_Name,New_Class_Implementation_File_Name,&index_counter);

     File_Name[index_counter] = '\0';

     this->File_Manager.DeleteFile(File_Name);

     delete [] File_Name;
}

void ClassRebuilder_Data_Collector::Remove_Header_Extra(){

     char gch_word [] = {'.','g','c','h','\0'};

     char directory_character [] = {'/','\0'};

     this->Directory_Manager.DetermineCurrentDirectory();

     char * Current_Directory = this->Directory_Manager.GetCurrentlyWorkingDirectory();

     char * Header_File_Name = this->Initializer->Get_New_Header_File_Name();

     int Current_Directory_Name_Size = strlen(Current_Directory);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int File_Name_Size = Current_Directory_Name_Size + Header_File_Name_Size;

     char * File_Name  = new char [10*File_Name_Size];

     int index_counter = 0;

     this->Place_Information(&File_Name,Current_Directory,&index_counter);

     this->Place_Information(&File_Name,directory_character,&index_counter);

     this->Place_Information(&File_Name,Header_File_Name,&index_counter);

     this->Place_Information(&File_Name,gch_word,&index_counter);

     File_Name[index_counter] = '\0';

     this->File_Manager.DeleteFile(File_Name);

     delete [] File_Name;
}

void ClassRebuilder_Data_Collector::Run_System_Commands(){

     int system_return_value = this->System_Interface.System_Function(this->Compiler_Command);

     if(system_return_value != 0){

        std::cerr << "\n An error occured in client class comiling ..";

        exit(1);
     }

     this->Remove_Class_Implementation_File();

     this->Remove_Header_Extra();
}

void ClassRebuilder_Data_Collector::Print_System_Commands(){

     std::cout << "\n\n Compiler Command:" << this->Compiler_Command << "#";
}

void ClassRebuilder_Data_Collector::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

void ClassRebuilder_Data_Collector::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

char * ClassRebuilder_Data_Collector::Get_Object_File_Name() const
{
       return this->Object_File_Name;
}
