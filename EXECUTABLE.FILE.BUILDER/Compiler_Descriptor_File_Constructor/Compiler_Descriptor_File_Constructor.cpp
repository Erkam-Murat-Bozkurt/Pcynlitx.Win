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

#include "Compiler_Descriptor_File_Constructor.h"

Compiler_Descriptor_File_Constructor::Compiler_Descriptor_File_Constructor(){

     this->Memory_Delete_Condition = false;

     this->Include_Directories = nullptr;

     this->Library_Directories = nullptr;

     this->Source_File_Directories = nullptr;

     this->Source_File_Names = nullptr;

     this->Header_File_Names = nullptr;

     this->Library_Names = nullptr;

     this->New_Include_Directory_Name = nullptr;

     this->Header_File_Path_In_New_Include_Directory = nullptr;

     this->Client_Class_Name = nullptr;

     this->Shared_Data_Type_Pointer_Class_Name = nullptr;

     this->Base_Class_Header_File_Path = nullptr;

     this->Shared_Data_Type_Header_File_Path = nullptr;

     this->Shared_Data_Type_Pointer_Header_File_Name = nullptr;

     this->Server_Class_Header_File_Name = nullptr;

     this->Include_Directory_Counter = 0;

     this->Library_Directory_Counter = 0;

     this->Source_File_Directory_Counter = 0;

     this->Source_File_Name_Counter = 0;

     this->Header_File_Name_Counter = 0;

     this->Library_Name_Counter = 0;

     this->Header_File_Location_Counter = 0;

     this->Source_File_Location_Counter = 0;

     this->Include_Directory_Number = 0;

     this->Library_Directory_Number = 0;

     this->Source_File_Directory_Number = 0;

     this->Source_File_Number = 0;

     this->Header_File_Number = 0;

     this->Library_Name_Number = 0;
};

Compiler_Descriptor_File_Constructor::Compiler_Descriptor_File_Constructor(const Compiler_Descriptor_File_Constructor & orig){

};

Compiler_Descriptor_File_Constructor::~Compiler_Descriptor_File_Constructor(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void Compiler_Descriptor_File_Constructor::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         for(int i=0;i<this->Include_Directory_Counter;i++){

             this->Clear_Pointer_Memory(&this->Include_Directories[i]);
         }

         delete [] this->Include_Directories;

         for(int i=0;i<this->Library_Directory_Counter;i++){

             this->Clear_Pointer_Memory(&this->Library_Directories[i]);
         }

         delete [] this->Library_Directories;

         for(int i=0;i<this->Source_File_Directory_Counter;i++){

             this->Clear_Pointer_Memory(&this->Source_File_Directories[i]);
         }

         delete [] this->Source_File_Directories;

         for(int i=0;i<this->Source_File_Name_Counter;i++){

             this->Clear_Pointer_Memory(&this->Source_File_Names[i]);
         }

         delete [] this->Source_File_Names;

         for(int i=0;i<this->Header_File_Name_Counter;i++){

             this->Clear_Pointer_Memory(&this->Header_File_Names[i]);
         }

         delete [] this->Header_File_Names;

         for(int i=0;i<this->Library_Name_Counter;i++){

             this->Clear_Pointer_Memory(&this->Library_Names[i]);
         }

         delete [] this->Library_Names;

         this->Clear_Pointer_Memory(&this->New_Include_Directory_Name);

         this->Clear_Pointer_Memory(&this->Client_Class_Name);

         this->Clear_Pointer_Memory(&this->Shared_Data_Type_Pointer_Class_Name);

         this->Clear_Pointer_Memory(&this->Header_File_Path_In_New_Include_Directory);

         this->Clear_Pointer_Memory(&this->Base_Class_Header_File_Path);

         this->Clear_Pointer_Memory(&this->Shared_Data_Type_Header_File_Path);

         this->Clear_Pointer_Memory(&this->Shared_Data_Type_Pointer_Header_File_Name);

         this->Clear_Pointer_Memory(&this->Server_Class_Header_File_Name);

         this->FileManager.Clear_Dynamic_Memory();
     }
}

void Compiler_Descriptor_File_Constructor::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

void Compiler_Descriptor_File_Constructor::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;
}

void Compiler_Descriptor_File_Constructor::Collect_Informations(){

     this->Determine_New_Include_Directory_Name();

     this->Determine_Server_Class_Header_File_Path();

     char Thread_Library_Name [] = {'p','t','h','r','e','a','d','\0'};

     int Total_Include_Directory_Number = this->Reader_Pointer->Get_Include_Directory_Number();

     if(Total_Include_Directory_Number == 0){

        this->Reserve_Memory_For_Include_Directories(10);
     }
     else{

          this->Reserve_Memory_For_Include_Directories(10*Total_Include_Directory_Number);
     }

     this->Receive_Include_Directory(this->New_Include_Directory_Name);

     for(int i=0;i<Total_Include_Directory_Number;i++){

            Include_Directory_Type Directory_Holder = this->Reader_Pointer->Get_Include_Directory()[i];

            if(Directory_Holder.Include_Directory != nullptr){

               this->Receive_Include_Directory(Directory_Holder.Include_Directory);
           }
     }

     int Library_Directory_Number = this->Reader_Pointer->Get_Library_Directory_Number();

     if(Library_Directory_Number == 0){

           this->Reserve_Memory_For_Library_Directories(10);
     }
     else{

           this->Reserve_Memory_For_Library_Directories(10*Library_Directory_Number);
     }

     this->Receive_Library_Directory(this->Reader_Pointer->Get_Construction_Point());

     for(int i=0;i<Library_Directory_Number;i++){

         this->Receive_Library_Directory(this->Reader_Pointer->Get_Library_Directories()[i]);
     }

     int Library_Names_Number = this->Reader_Pointer->Get_Library_Names_Number();

     if(Library_Names_Number == 0){

           this->Reserve_Memory_For_Library_Names(10);
     }
     else{

           this->Reserve_Memory_For_Library_Names(10*Library_Names_Number);
     }

     char * Constructed_Library_Name = this->Reader_Pointer->Get_Server_Class_Name();

     this->Receive_Library_Name(Constructed_Library_Name);

     this->Receive_Library_Name(Thread_Library_Name);

     for(int i=0;i<Library_Names_Number;i++){

         this->Receive_Library_Name(this->Reader_Pointer->Get_Library_Names()[i]);
     }

     int Source_File_Directory_Number = this->Reader_Pointer->Get_Source_File_Location_Number();

     if(Source_File_Directory_Number == 0){

            this->Reserve_Memory_For_Source_File_Directories(10);
     }
     else{

            this->Reserve_Memory_For_Source_File_Directories(10*Source_File_Directory_Number);
     }

     if(Source_File_Directory_Number > 0){

        for(int i=0;i<Source_File_Directory_Number;i++){

            this->Receive_Source_File_Directory(this->Reader_Pointer->Get_Source_File_Locations()[i]);
        }
     }

     int Source_File_Names_Number = this->Reader_Pointer->Get_Source_File_Names_Number();

     if(Source_File_Names_Number == 0){

        this->Reserve_Memory_For_Source_File_Names(10);
     }
     else{

        this->Reserve_Memory_For_Source_File_Names(10*Source_File_Names_Number);
     }

     for(int i=0;i<Source_File_Names_Number;i++){

         this->Receive_Source_File_Name(this->Reader_Pointer->Get_Source_File_Names()[i]);
     }

     int Total_Header_File_Number = 10*this->Reader_Pointer->Get_Shared_Data_Types_Number() +

                                    10*this->Reader_Pointer->Get_Header_Files_Number() +

                                    10*this->Reader_Pointer->Get_Class_Number() +1;

     if(Total_Header_File_Number == 0){

          this->Reserve_Memory_For_Header_File_Names(10);
     }
     else{

          this->Reserve_Memory_For_Header_File_Names(10*Total_Header_File_Number);
     }

     this->Receive_Header_File_Name(this->Server_Class_Header_File_Name);

     int Total_Class_Number = this->Reader_Pointer->Get_Class_Number();

     for(int i=0;i<Total_Class_Number;i++){

         char * Header_File_Path = this->Get_File_Path_For_Base_Class_Header_File(i);

         this->Receive_Header_File_Name(Header_File_Path);
     }

     int Shared_Data_Types_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     for(int i=0;i<Shared_Data_Types_Number;i++){

         char * Header_File_Path = this->Get_File_Path_For_Shared_Data_Type_Header_File(i);

         if(Header_File_Path != nullptr){

              this->Receive_Header_File_Name(Header_File_Path);
         }
     }

     char Syncronizer_Class_Header_File_Name [] = {'T','h','r','e','a','d','_','M','a','n','a','g','e','r','.','h','\0'};

     char * Syncronizer_Class_Header_File_Path = this->Get_Header_File_Paths_In_New_Include_Directory(Syncronizer_Class_Header_File_Name);

     this->Receive_Header_File_Name(Syncronizer_Class_Header_File_Path);

     char Synchronizer_Class_Data_Manager_Header_File [] = {'T','h','r','e','a','d','_','D','a','t','a','_','M','a','n','a','g','e','r','.','h','\0'};

     char * Synchronizer_Class_Data_Manager_Header_File_Path = this->Get_Header_File_Paths_In_New_Include_Directory(Synchronizer_Class_Data_Manager_Header_File);

     this->Receive_Header_File_Name(Synchronizer_Class_Data_Manager_Header_File_Path);

     char Syncronizer_Client_Header_File_Name [] = {'T','M','_','C','l','i','e','n','t','.','h','\0'};

     char * Syncronizer_Client_Header_File_Path = this->Get_Header_File_Paths_In_New_Include_Directory(Syncronizer_Client_Header_File_Name);

     this->Receive_Header_File_Name(Syncronizer_Client_Header_File_Path);

     const char * Pointer_Subfix = "_Type_Smart_Pointer.h";

     const char * Memory_Manager_Subfix = "_Type_Smart_Pointer_MemoryManager.h";

     const char * ReportFileBuilder_Subfix = "_Type_Smart_Pointer_ReportFileBuilder.h";

     for(int i=0;i<Shared_Data_Types_Number;i++){

         Shared_Memory_Data_Type Data_Type_Holder = this->Reader_Pointer->Get_Shared_Data_Types()[i];

         char * Data_Type = Data_Type_Holder.Data_Type;

         char * Pointer_Header_File_Name = this->Get_Shared_Data_Type_Pointer_Header_File_Name(Data_Type,Pointer_Subfix);

         char * Pointer_Header_Path      = this->Get_Header_File_Paths_In_New_Include_Directory(Pointer_Header_File_Name);

         this->Receive_Header_File_Name(Pointer_Header_Path);

         char * Memory_Manager_Header    = this->Get_Shared_Data_Type_Pointer_Header_File_Name(Data_Type,Memory_Manager_Subfix);

         char * Memory_Manager_Path      = this->Get_Header_File_Paths_In_New_Include_Directory(Memory_Manager_Header);

         this->Receive_Header_File_Name(Memory_Manager_Path);

         char * ReportFileBuilder_Header = this->Get_Shared_Data_Type_Pointer_Header_File_Name(Data_Type,ReportFileBuilder_Subfix);

         char * ReportFileBuilder_Path = this->Get_Header_File_Paths_In_New_Include_Directory(ReportFileBuilder_Header);

         this->Receive_Header_File_Name(ReportFileBuilder_Path);
     }

     for(int i=0;i<Total_Class_Number;i++){

         Class_Data_Type Class_Data_Type_Holder = this->Reader_Pointer->Get_Class_Names()[i];

         char * Client_Class_Header_File_Name = this->Get_Client_Class_Header_File_Name(Class_Data_Type_Holder.Class_Name);

         char * Client_Class_Header_File_Path = this->Get_Header_File_Paths_In_New_Include_Directory(Client_Class_Header_File_Name);

         this->Receive_Header_File_Name(Client_Class_Header_File_Path);
     }

     int Standart_Header_File_Number = this->Reader_Pointer->Get_Header_Files_Number();

     for(int i=0;i<Standart_Header_File_Number;i++){

         this->Receive_Header_File_Name(this->Reader_Pointer->Get_Header_File_Paths()[i]);
     }
}

void Compiler_Descriptor_File_Constructor::Determine_New_Include_Directory_Name(){

     this->Memory_Delete_Condition = false;

     char Include_Directory_Word [] = {'_','I','n','c','l','u','d','e','_','D','i','r','e','c','t','o','r','y','\0'};

     char Directory_Character [] = {'/','\0'};

     int Class_Name_Size = strlen(this->Reader_Pointer->Get_Server_Class_Name());

     int Include_Directory_Word_Name_Size = strlen(Include_Directory_Word);

     int Construction_Point_Name_Size = strlen(this->Reader_Pointer->Get_Construction_Point());

     int Directory_Name_Size = Class_Name_Size + Include_Directory_Word_Name_Size + Construction_Point_Name_Size;

     this->New_Include_Directory_Name = new char [10*Directory_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->New_Include_Directory_Name,this->Reader_Pointer->Get_Construction_Point(),&index_counter);

     this->Place_Information(&this->New_Include_Directory_Name,Directory_Character,&index_counter);

     this->Place_Information(&this->New_Include_Directory_Name,this->Reader_Pointer->Get_Server_Class_Name(),&index_counter);

     this->Place_Information(&this->New_Include_Directory_Name,Include_Directory_Word,&index_counter);

     this->New_Include_Directory_Name[index_counter] = '\0';
}

void Compiler_Descriptor_File_Constructor::Determine_Server_Class_Header_File_Path(){

     char Directory_Character [] = {'/','\0'};

     char * Server_Class_Header_File_Name = this->Reader_Pointer->Get_Server_Class_Header_File_Name();

     int New_Include_Directory_Name_Size = strlen(this->New_Include_Directory_Name);

     int Server_Class_Header_File_Name_Size = strlen(Server_Class_Header_File_Name);

     int Path_Size = New_Include_Directory_Name_Size + Server_Class_Header_File_Name_Size;

     this->Server_Class_Header_File_Name = new char [10*Path_Size];

     int index_counter = 0;

     this->Place_Information(&this->Server_Class_Header_File_Name,this->New_Include_Directory_Name,&index_counter);

     this->Place_Information(&this->Server_Class_Header_File_Name,Directory_Character,&index_counter);

     this->Place_Information(&this->Server_Class_Header_File_Name,Server_Class_Header_File_Name,&index_counter);

     this->Server_Class_Header_File_Name[index_counter] = '\0';
}

void Compiler_Descriptor_File_Constructor::Reserve_Memory_For_Include_Directories(int Number){

     this->Include_Directory_Number = Number;

     if(this->Include_Directory_Number > 0){

        this->Include_Directories = new char * [10*this->Include_Directory_Number];
     }
}

void Compiler_Descriptor_File_Constructor::Reserve_Memory_For_Library_Directories(int Number){

     this->Library_Directory_Number = Number;

     if(this->Library_Directory_Number > 0){

        this->Library_Directories = new char * [10*this->Library_Directory_Number];
     }
}

void Compiler_Descriptor_File_Constructor::Reserve_Memory_For_Source_File_Directories(int Number){

     this->Source_File_Directory_Number = Number;

     if(this->Source_File_Directory_Number > 0){

        this->Source_File_Directories = new char * [10*this->Source_File_Directory_Number];
     }
}

void Compiler_Descriptor_File_Constructor::Reserve_Memory_For_Source_File_Names(int Number){

     this->Source_File_Number = Number;

     if(this->Source_File_Number > 0){

        this->Source_File_Names = new char * [10*this->Source_File_Number];
     }
}

void Compiler_Descriptor_File_Constructor::Reserve_Memory_For_Header_File_Names(int Number){

     this->Header_File_Number = Number;

     if(this->Header_File_Number > 0){

        this->Header_File_Names = new char * [10*this->Header_File_Number];
     }
}

void Compiler_Descriptor_File_Constructor::Reserve_Memory_For_Library_Names(int Number){

     this->Library_Name_Number = Number;

     if(this->Library_Name_Number > 0){

        this->Library_Names = new char * [10*this->Library_Name_Number];
     }
}

void Compiler_Descriptor_File_Constructor::Receive_Include_Directory(char * IncludeDirectory){

     int String_Size = strlen(IncludeDirectory);

     this->Include_Directories[this->Include_Directory_Counter] = new char [10*String_Size];

     this->Place_String(&(this->Include_Directories[this->Include_Directory_Counter]),IncludeDirectory,String_Size);

     this->Include_Directory_Counter++;
}

void Compiler_Descriptor_File_Constructor::Receive_Library_Directory(char * LibraryDirectory){

     int String_Size = strlen(LibraryDirectory);

     this->Library_Directories[this->Library_Directory_Counter] = new char [10*String_Size];

     this->Place_String(&(this->Library_Directories[this->Library_Directory_Counter]),LibraryDirectory,String_Size);

     this->Library_Directory_Counter++;
}

void Compiler_Descriptor_File_Constructor::Receive_Source_File_Name(char * SourceFileName){

     int String_Size = strlen(SourceFileName);

     this->Source_File_Names[this->Source_File_Name_Counter] = new char [10*String_Size];

     this->Place_String(&(this->Source_File_Names[this->Source_File_Name_Counter]),SourceFileName,String_Size);

     this->Source_File_Name_Counter++;
}

void Compiler_Descriptor_File_Constructor::Receive_Header_File_Name(char * HeaderFileName){

     int String_Size = strlen(HeaderFileName);

     this->Header_File_Names[this->Header_File_Name_Counter] = new char [10*String_Size];

     this->Place_String(&(this->Header_File_Names[this->Header_File_Name_Counter]),HeaderFileName,String_Size);

     this->Header_File_Name_Counter++;
}

void Compiler_Descriptor_File_Constructor::Receive_Library_Name(char * LibraryName){

     int String_Size = strlen(LibraryName);

     this->Library_Names[this->Library_Name_Counter] = new char [10*String_Size];

     this->Place_String(&(this->Library_Names[this->Library_Name_Counter]),LibraryName,String_Size);

     this->Library_Name_Counter++;
}

void Compiler_Descriptor_File_Constructor::Receive_Source_File_Directory(char * SourceFileDirectory){

     int String_Size = strlen(SourceFileDirectory);

     this->Source_File_Directories[this->Source_File_Directory_Counter] = new char [10*String_Size];

     this->Place_String(&(this->Source_File_Directories[this->Source_File_Directory_Counter]),SourceFileDirectory,String_Size);

     this->Source_File_Directory_Counter++;
}

void Compiler_Descriptor_File_Constructor::Build_Compiler_Descriptor_File(){

     this->Collect_Informations();

     this->FileManager.SetFilePath("Compiler_Descriptor_File");

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n\nINCLUDE DIRECTORIES:\n");

     if(this->Include_Directory_Counter > 0){

         this->Write_String_List_To_File(this->Include_Directories,this->Include_Directory_Counter);
     }

     this->FileManager.WriteToFile("\n\nLIBRARY DIRECTORIES:\n");

     if(this->Library_Directory_Counter > 0){

        this->Write_String_List_To_File(this->Library_Directories,this->Library_Directory_Counter);
     }

     this->FileManager.WriteToFile("\n\nSOURCE FILE DIRECTORIES:\n");

     if(this->Source_File_Directory_Counter > 0 ){

        this->Write_String_List_To_File(this->Source_File_Directories,this->Source_File_Directory_Counter);
     }

     this->FileManager.WriteToFile("\n\nSOURCE FILE NAMES:\n");

     if(this->Source_File_Name_Counter > 0){

        this->Write_String_List_To_File(this->Source_File_Names,this->Source_File_Name_Counter);
     }

     this->FileManager.WriteToFile("\n\nHEADER FILE NAMES:\n");

     if(this->Header_File_Name_Counter > 0){

        this->Write_String_List_To_File(this->Header_File_Names,this->Header_File_Name_Counter);
     }

     this->FileManager.WriteToFile("\n\nMAIN FILE NAME:");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(this->Reader_Pointer->Get_Main_File_Name());

     this->FileManager.WriteToFile("\n\nEXECUTABLE FILE NAME:");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(this->Reader_Pointer->Get_Executable_File_Name());

     this->FileManager.WriteToFile("\n\nOPTIONS:");

     this->FileManager.WriteToFile("\n\nLIBRARY NAMES:\n");

     if(this->Library_Name_Counter > 0){

        this->Write_String_List_To_File(this->Library_Names,this->Library_Name_Counter);
     }

     this->FileManager.WriteToFile("\n\nEND");

     this->FileManager.FileClose();
}


char * Compiler_Descriptor_File_Constructor::Get_Header_File_Paths_In_New_Include_Directory(char * Header_File_Name){

       char Directory_Character [] = {'/','\0'};

       int Directory_Name_Size   = strlen(this->New_Include_Directory_Name);

       int Header_File_Name_Size = strlen(Header_File_Name);

       int Path_Size = Directory_Name_Size + Header_File_Name_Size;

       this->Clear_Pointer_Memory(&this->Header_File_Path_In_New_Include_Directory);

       this->Header_File_Path_In_New_Include_Directory = new char [10*Path_Size];

       int index_counter = 0;

       this->Place_Information(&this->Header_File_Path_In_New_Include_Directory,this->New_Include_Directory_Name,&index_counter);

       this->Place_Information(&this->Header_File_Path_In_New_Include_Directory,Directory_Character,&index_counter);

       this->Place_Information(&this->Header_File_Path_In_New_Include_Directory,Header_File_Name,&index_counter);

       this->Header_File_Path_In_New_Include_Directory[index_counter] = '\0';

       return this->Header_File_Path_In_New_Include_Directory;
}

char *  Compiler_Descriptor_File_Constructor::Get_File_Path_For_Base_Class_Header_File(int Index_Number){

        Class_Data_Type Class_Data_Type_Holder = this->Reader_Pointer->Get_Class_Names()[Index_Number];

        char * Header_File_Location = Class_Data_Type_Holder.Header_File_Location;

        char * Header_File_Name = Class_Data_Type_Holder.Header_File_Name;

        char Directory_Character [] = {'/','\0'};

        int Directory_Name_Size   = strlen(Header_File_Location);

        int Header_File_Name_Size = strlen(Header_File_Name);

        int Path_Size = Directory_Name_Size + Header_File_Name_Size;

        this->Clear_Pointer_Memory(&this->Base_Class_Header_File_Path);

        this->Base_Class_Header_File_Path = new char [10*Path_Size];

        int index_counter = 0;

        this->Place_Information(&this->Base_Class_Header_File_Path,Header_File_Location,&index_counter);

        this->Place_Information(&this->Base_Class_Header_File_Path,Directory_Character,&index_counter);

        this->Place_Information(&this->Base_Class_Header_File_Path,Header_File_Name,&index_counter);

        this->Base_Class_Header_File_Path[index_counter] = '\0';

        return this->Base_Class_Header_File_Path;
}

char * Compiler_Descriptor_File_Constructor::Get_File_Path_For_Shared_Data_Type_Header_File(int Index_Number){

       Shared_Memory_Data_Type Data_Type_Holder = this->Reader_Pointer->Get_Shared_Data_Types()[Index_Number];

       this->Clear_Pointer_Memory(&this->Shared_Data_Type_Header_File_Path);

       if(Data_Type_Holder.Header_File_Name != nullptr){

          char * Header_File_Location = Data_Type_Holder.Include_Directory;

          char * Header_File_Name =  Data_Type_Holder.Header_File_Name;

          char Directory_Character [] = {'/','\0'};

          int Directory_Name_Size   = strlen(Header_File_Location);

          int Header_File_Name_Size = strlen(Header_File_Name);

          int Path_Size = Directory_Name_Size + Header_File_Name_Size;

          this->Shared_Data_Type_Header_File_Path = new char [10*Path_Size];

          int index_counter = 0;

          this->Place_Information(&this->Shared_Data_Type_Header_File_Path,Header_File_Location,&index_counter);

          this->Place_Information(&this->Shared_Data_Type_Header_File_Path,Directory_Character,&index_counter);

          this->Place_Information(&this->Shared_Data_Type_Header_File_Path,Header_File_Name,&index_counter);

          this->Shared_Data_Type_Header_File_Path[index_counter] = '\0';
       }
       else{

             this->Shared_Data_Type_Header_File_Path = nullptr;
       }

       return  this->Shared_Data_Type_Header_File_Path;
}

char * Compiler_Descriptor_File_Constructor::Get_Client_Class_Header_File_Name(char * Class_Name){

       char Client_Subfix [] = {'_','C','l','i','e','n','t','.','h','\0'};

       this->Clear_Pointer_Memory(&this->Client_Class_Name);

       int Class_Name_Size = strlen(Class_Name);

       int Subfix_Name_Size = strlen(Client_Subfix);

       int Client_Class_Name_Size = Class_Name_Size + Subfix_Name_Size;

       this->Client_Class_Name = new char [10*Client_Class_Name_Size];

       int index_counter = 0;

       this->Place_Information(&this->Client_Class_Name,Class_Name,&index_counter);

       this->Place_Information(&this->Client_Class_Name,Client_Subfix,&index_counter);

       this->Client_Class_Name[index_counter] = '\0';

       return this->Client_Class_Name;
}

char * Compiler_Descriptor_File_Constructor::Get_Shared_Data_Type_Pointer_Header_File_Name(char * Data_Type, const char * Type_Subfix){

       this->Clear_Pointer_Memory(&this->Shared_Data_Type_Pointer_Header_File_Name);

       int Type_Subfix_Name_Size = strlen(Type_Subfix);

       int Data_Type_Name_Size = strlen(Data_Type);

       int Pointer_Name_Size = Type_Subfix_Name_Size + Data_Type_Name_Size;

       this->Shared_Data_Type_Pointer_Header_File_Name = new char [10*Pointer_Name_Size];

       int index_counter = 0;

       this->Place_Information(&this->Shared_Data_Type_Pointer_Header_File_Name,Data_Type,&index_counter);

       this->Place_Information(&this->Shared_Data_Type_Pointer_Header_File_Name,Type_Subfix,&index_counter);

       this->Shared_Data_Type_Pointer_Header_File_Name[index_counter] = '\0';

       return this->Shared_Data_Type_Pointer_Header_File_Name;
}

void Compiler_Descriptor_File_Constructor::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

void Compiler_Descriptor_File_Constructor::Place_Information(char ** Pointer, const char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

void Compiler_Descriptor_File_Constructor::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void Compiler_Descriptor_File_Constructor::Write_String_List_To_File(char ** Pointer, int List_Size){

     for(int i=0;i<List_Size;i++){

         this->FileManager.WriteToFile(Pointer[i]);

         this->FileManager.WriteToFile("\n");
     }
}
