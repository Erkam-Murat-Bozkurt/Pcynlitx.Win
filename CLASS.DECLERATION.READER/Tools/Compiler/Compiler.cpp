
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

#include "Compiler.h"

Compiler::Compiler(){

     this->Memory_Delete_Condition = false;

     this->Include_Directory_Decleration_Command = nullptr;

     this->Library_Directory_Decleration_Command = nullptr;

     this->Source_Files_Directories_Decleration_Command = nullptr;

     this->Source_File_Names_Decleration_Command = nullptr;

     this->Header_Files_Decleration_Command = nullptr;

     this->Libraries_Decleration_Command = nullptr;

     this->Option_List_Decleration_Command = nullptr;

     this->Final_Commad = nullptr;
};

Compiler::Compiler(const Compiler & orig){

};

Compiler::~Compiler(){

      if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
      }
};

void Compiler::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Descriptor_File_Reader.Include_Directory_Number > 0){

            this->Clear_Pointer_Memory(&this->Include_Directory_Decleration_Command);
         }

         if(this->Descriptor_File_Reader.Library_Directory_Number > 0){

            this->Clear_Pointer_Memory(&this->Library_Directory_Decleration_Command);
         }

         if(this->Descriptor_File_Reader.Source_File_Directory_Number > 0){

            this->Clear_Pointer_Memory(&this->Source_Files_Directories_Decleration_Command);
         }

         if(this->Descriptor_File_Reader.Source_File_Names_Number > 0){

            this->Clear_Pointer_Memory(&this->Source_File_Names_Decleration_Command);
         }

         if(this->Descriptor_File_Reader.Header_File_Names_Number > 0){

            this->Clear_Pointer_Memory(&this->Header_Files_Decleration_Command);
         }

         if(this->Descriptor_File_Reader.Library_Names_Number > 0){

            this->Clear_Pointer_Memory(&this->Libraries_Decleration_Command);
         }

         if(this->Descriptor_File_Reader.Option_Number > 0){

            this->Clear_Pointer_Memory(&this->Option_List_Decleration_Command);
         }

         this->Clear_Pointer_Memory(&this->Final_Commad);
     }
}

void Compiler::Receive_Descriptor_File_Directory(const char * FileDirectory){

     this->Descriptor_File_Reader.Receive_Descriptor_File_Directory(FileDirectory);
}

void Compiler::Receive_Descriptor_File_Directory(char * FileDirectory){

     this->Descriptor_File_Reader.Receive_Descriptor_File_Directory(FileDirectory);
}

void Compiler::Receive_Descriptor_File_Name(const char * FileName){

     this->Descriptor_File_Reader.Receive_Descriptor_File_Name(FileName);
}

void Compiler::Receive_Descriptor_File_Name(char * FileName){

     this->Descriptor_File_Reader.Receive_Descriptor_File_Name(FileName);
}

void Compiler::Receive_Descriptor_File_Infomations(){

     this->Descriptor_File_Reader.Receive_Descriptor_File_Infomations();

     this->Collect_Compiler_Process_Informations();

     this->Determine_Final_Command();
}

void Compiler::Build_Project(){

     int system_return_value = system(this->Final_Commad);

     if(system_return_value != 0){

        std::cout << "An error occured in compling process ..";

        std::cerr << "An error occured in compling process ..";

        exit(1);
     }
}

void Compiler::Collect_Compiler_Process_Informations(){

      if(this->Descriptor_File_Reader.Include_Directory_Number > 0){

         this->Determine_Include_Directory_Decleration_Command();
      }

      if(this->Descriptor_File_Reader.Library_Directory_Number > 0){

         this->Determine_Library_Directory_Decleration_Command();
      }

      if(this->Descriptor_File_Reader.Source_File_Directory_Number > 0){

         this->Determine_Source_Files_Directories_Decleration_Command();
      }

      if(this->Descriptor_File_Reader.Source_File_Names_Number > 0){

         this->Determine_Source_File_Names_Decleration_Command();
      }

      if(this->Descriptor_File_Reader.Header_File_Names_Number > 0){

         this->Determine_Header_Files_Decleration_Command();
      }

      if(this->Descriptor_File_Reader.Library_Names_Number > 0){

         this->Determine_Libraries_Decleration_Command();
      }

      if(this->Descriptor_File_Reader.Option_Number > 0){

         this->Determine_Option_List_Decleration_Command();
      }
}

void Compiler::Determine_Include_Directory_Decleration_Command(){

     char Include_Symbol []  = {'-','I','\0'};

     char Space_Character [] = {' ','\0'};

     int Command_Size = 0;

     int Include_Directory_Number = this->Descriptor_File_Reader.Include_Directory_Number;

     for(int i=0;i<Include_Directory_Number;i++){

         Command_Size = Command_Size + strlen(this->Descriptor_File_Reader.Include_Directory_List[i]);
     }

     this->Include_Directory_Decleration_Command = new char [10*Command_Size];

     int index_counter = 0;

     for(int i=0;i<Include_Directory_Number;i++){

         char * Include_Directory_Name = this->Descriptor_File_Reader.Include_Directory_List[i];

         this->Place_Information(&this->Include_Directory_Decleration_Command,Include_Symbol,&index_counter);

         this->Place_Information(&this->Include_Directory_Decleration_Command,Include_Directory_Name,&index_counter);

         this->Place_Information(&this->Include_Directory_Decleration_Command,Space_Character,&index_counter);
     }

     this->Include_Directory_Decleration_Command[index_counter-1] = '\0';
}

void Compiler::Determine_Library_Directory_Decleration_Command(){

     char Library_Symbol []  = {'-','L','\0'};

     char Space_Character [] = {' ','\0'};

     int Command_Size = 0;

     int Library_Directory_Number = this->Descriptor_File_Reader.Library_Directory_Number;

     for(int i=0;i<Library_Directory_Number;i++){

         Command_Size = Command_Size + strlen(this->Descriptor_File_Reader.Library_Directory_List[i]);
     }

     this->Library_Directory_Decleration_Command = new char [10*Command_Size];

     int index_counter = 0;

     for(int i=0;i<Library_Directory_Number;i++){

         char * Library_Directory_Name = this->Descriptor_File_Reader.Library_Directory_List[i];

         this->Place_Information(&this->Library_Directory_Decleration_Command,Library_Symbol,&index_counter);

         this->Place_Information(&this->Library_Directory_Decleration_Command,Library_Directory_Name,&index_counter);

         this->Place_Information(&this->Library_Directory_Decleration_Command,Space_Character,&index_counter);
     }

     this->Library_Directory_Decleration_Command[index_counter-1] = '\0';
}

void Compiler::Determine_Source_Files_Directories_Decleration_Command(){

     char Library_Symbol []  = {'-','L','\0'};

     char Space_Character [] = {' ','\0'};

     int Command_Size = 0;

     int Source_File_Directory_Number = this->Descriptor_File_Reader.Source_File_Directory_Number;

     for(int i=0;i<Source_File_Directory_Number;i++){

         Command_Size = Command_Size + strlen(this->Descriptor_File_Reader.Source_File_Directory_List[i]);
     }

     this->Source_Files_Directories_Decleration_Command = new char [10*Command_Size];

     int index_counter = 0;

     for(int i=0;i<Source_File_Directory_Number;i++){

         char * Source_File_Directory_Name = this->Descriptor_File_Reader.Source_File_Directory_List[i];

         this->Place_Information(&this->Source_Files_Directories_Decleration_Command,Library_Symbol,&index_counter);

         this->Place_Information(&this->Source_Files_Directories_Decleration_Command,Source_File_Directory_Name,&index_counter);

         this->Place_Information(&this->Source_Files_Directories_Decleration_Command,Space_Character,&index_counter);
     }

     this->Source_Files_Directories_Decleration_Command[index_counter-1] = '\0';
}

void Compiler::Determine_Source_File_Names_Decleration_Command(){

     char Space_Character [] = {' ','\0'};

     int Command_Size = 0;

     int Source_File_Names_Number = this->Descriptor_File_Reader.Source_File_Names_Number;

     for(int i=0;i<Source_File_Names_Number;i++){

         Command_Size = Command_Size + strlen(this->Descriptor_File_Reader.Source_File_Name_List[i]);
     }

     this->Source_File_Names_Decleration_Command = new char [10*Command_Size];

     int index_counter = 0;

     for(int i=0;i<Source_File_Names_Number;i++){

         char * Source_File_Name = this->Descriptor_File_Reader.Source_File_Name_List[i];

         this->Place_Information(&this->Source_File_Names_Decleration_Command,Source_File_Name,&index_counter);

         this->Place_Information(&this->Source_File_Names_Decleration_Command,Space_Character,&index_counter);
     }

     this->Source_File_Names_Decleration_Command[index_counter-1] = '\0';
}

void Compiler::Determine_Header_Files_Decleration_Command(){

     char Space_Character [] = {' ','\0'};

     char Include_Word [] = "-include";

     int Command_Size = 0;

     int Header_File_Names_Number = this->Descriptor_File_Reader.Header_File_Names_Number;

     for(int i=0;i<Header_File_Names_Number;i++){

         Command_Size = Command_Size + strlen(this->Descriptor_File_Reader.Header_File_Name_List[i]);
     }

     int Include_Word_Size = strlen(Include_Word);

     Command_Size = Command_Size + Header_File_Names_Number*Include_Word_Size;

     this->Header_Files_Decleration_Command = new char [10*Command_Size];

     int index_counter = 0;

     for(int i=0;i<Header_File_Names_Number ;i++){

         char * Header_File_Name = this->Descriptor_File_Reader.Header_File_Name_List[i];

         this->Place_Information(&this->Header_Files_Decleration_Command,Include_Word,&index_counter);

         this->Place_Information(&this->Header_Files_Decleration_Command,Space_Character,&index_counter);

         this->Place_Information(&this->Header_Files_Decleration_Command,Header_File_Name,&index_counter);

         this->Place_Information(&this->Header_Files_Decleration_Command,Space_Character,&index_counter);
     }

     this->Header_Files_Decleration_Command[index_counter-1] = '\0';
}

void Compiler::Determine_Libraries_Decleration_Command(){

     char Space_Character [] = {' ','\0'};

     char Link_Character [] = {'-','l','\0'};

     int Command_Size = 0;

     int Library_Names_Number = this->Descriptor_File_Reader.Library_Names_Number;

     for(int i=0;i<Library_Names_Number;i++){

         Command_Size = Command_Size + strlen(this->Descriptor_File_Reader.Library_Name_List[i]);
     }

     this->Libraries_Decleration_Command = new char [10*Command_Size];

     int index_counter = 0;

     for(int i=0;i<Library_Names_Number;i++){

         char * Library_Name = this->Descriptor_File_Reader.Library_Name_List[i];

         this->Place_Information(&this->Libraries_Decleration_Command,Link_Character,&index_counter);

         this->Place_Information(&this->Libraries_Decleration_Command,Library_Name,&index_counter);

         this->Place_Information(&this->Libraries_Decleration_Command,Space_Character,&index_counter);
     }

     this->Libraries_Decleration_Command[index_counter-1] = '\0';
}

void Compiler::Determine_Option_List_Decleration_Command(){

     char Space_Character [] = {' ','\0'};

     int Command_Size = 0;

     int Option_Number = this->Descriptor_File_Reader.Option_Number;

     for(int i=0;i<Option_Number;i++){

         Command_Size = Command_Size + strlen(this->Descriptor_File_Reader.Option_List[i]);
     }

     this->Option_List_Decleration_Command = new char [10*Command_Size];

     int index_counter = 0;

     for(int i=0;i<Option_Number;i++){

         char * Option = this->Descriptor_File_Reader.Option_List[i];

         this->Place_Information(&this->Option_List_Decleration_Command,Option,&index_counter);

         this->Place_Information(&this->Option_List_Decleration_Command,Space_Character,&index_counter);
     }

     this->Option_List_Decleration_Command[index_counter-1] = '\0';
}

void Compiler::Determine_Final_Command(){

     char Input_Command [] = {'g','+','+','\0'};

     char Standard_Indicator [] = {'-','s','t','d','=','c','+','+','1','4','\0'};

     char Space_Character [] = {' ','\0'};

     char Executable_File_Indicator [] = {'-','o','\0'};

     char Output_Redirection_Command [] = {'2','>','\0'};

     char Error_Message_File_Name [] = {'C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     int Inpt_Name_Size = 0, IDir_Name_Size = 0, LDir_Name_Size = 0, SDir_Name_Size = 0, SFIN_Name_Size = 0;

     int HFIN_Name_Size = 0, LIBD_Name_Size = 0, Opts_Name_size = 0, ExeF_Name_Size = 0, Main_Name_Size = 0;

     Inpt_Name_Size = strlen(Input_Command);

     if(this->Descriptor_File_Reader.Include_Directory_Number > 0){

        IDir_Name_Size = strlen(this->Include_Directory_Decleration_Command);
     }

     if(this->Descriptor_File_Reader.Library_Directory_Number > 0){

        LDir_Name_Size = strlen(this->Library_Directory_Decleration_Command);
     }

     if(this->Descriptor_File_Reader.Source_File_Directory_Number > 0){

        SDir_Name_Size = strlen(this->Source_Files_Directories_Decleration_Command);
     }

     if(this->Descriptor_File_Reader.Source_File_Names_Number > 0){

        SFIN_Name_Size = strlen(this->Source_File_Names_Decleration_Command);
     }

     if(this->Descriptor_File_Reader.Header_File_Names_Number > 0){

        HFIN_Name_Size = strlen(this->Header_Files_Decleration_Command);
     }

     if(this->Descriptor_File_Reader.Library_Names_Number > 0){

        LIBD_Name_Size = strlen(this->Libraries_Decleration_Command);
     }

     if(this->Descriptor_File_Reader.Option_Number > 0){

        Opts_Name_size = strlen(this->Option_List_Decleration_Command);
     }

     if(this->Descriptor_File_Reader.Is_There_Main_File_Decleration){

        ExeF_Name_Size = strlen(this->Descriptor_File_Reader.Executable_File_Name);

        Main_Name_Size = strlen(this->Descriptor_File_Reader.Main_File_Name);
     }

     int Final_Command_Name_Size = IDir_Name_Size + LDir_Name_Size + SDir_Name_Size + SFIN_Name_Size +

                                   HFIN_Name_Size + LIBD_Name_Size + Opts_Name_size + ExeF_Name_Size +

                                   Main_Name_Size + Inpt_Name_Size;

     this->Final_Commad = new char [10*Final_Command_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->Final_Commad,Input_Command,&index_counter);

     this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);

     if(this->Descriptor_File_Reader.Option_Number>0){

        this->Place_Information(&this->Final_Commad,this->Option_List_Decleration_Command,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     this->Place_Information(&this->Final_Commad,Standard_Indicator,&index_counter);

     this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);

     if(this->Descriptor_File_Reader.Include_Directory_Number > 0){

        this->Place_Information(&this->Final_Commad,this->Include_Directory_Decleration_Command,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     if(this->Descriptor_File_Reader.Library_Directory_Number > 0){

        this->Place_Information(&this->Final_Commad,this->Library_Directory_Decleration_Command,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     if(this->Descriptor_File_Reader.Source_File_Directory_Number > 0){

        this->Place_Information(&this->Final_Commad,this->Source_Files_Directories_Decleration_Command,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     bool Is_There_Main_File_Decleration = this->Descriptor_File_Reader.Is_There_Main_File_Decleration;

     bool Is_There_Executable_Name = false;

     if(this->Descriptor_File_Reader.Executable_File_Name != nullptr){

         Is_There_Executable_Name = true;
     }

     if(Is_There_Main_File_Decleration && Is_There_Executable_Name){

        this->Place_Information(&this->Final_Commad,Executable_File_Indicator,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);

        this->Place_Information(&this->Final_Commad,this->Descriptor_File_Reader.Executable_File_Name,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     if(Is_There_Main_File_Decleration){

        this->Place_Information(&this->Final_Commad,this->Descriptor_File_Reader.Main_File_Name,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     if(this->Descriptor_File_Reader.Source_File_Names_Number > 0){

        this->Place_Information(&this->Final_Commad,this->Source_File_Names_Decleration_Command,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     if(this->Descriptor_File_Reader.Header_File_Names_Number > 0){

        this->Place_Information(&this->Final_Commad,this->Header_Files_Decleration_Command,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     if(this->Descriptor_File_Reader.Library_Names_Number > 0){

        this->Place_Information(&this->Final_Commad,this->Libraries_Decleration_Command,&index_counter);

        this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);
     }

     this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);

     this->Place_Information(&this->Final_Commad,Output_Redirection_Command,&index_counter);

     this->Place_Information(&this->Final_Commad,Space_Character,&index_counter);

     this->Place_Information(&this->Final_Commad,Error_Message_File_Name,&index_counter);

     this->Final_Commad[index_counter] = '\0';
}

void Compiler::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
}

void Compiler::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

char * Compiler::Get_Compiler_Command(){

       return this->Final_Commad;
}
