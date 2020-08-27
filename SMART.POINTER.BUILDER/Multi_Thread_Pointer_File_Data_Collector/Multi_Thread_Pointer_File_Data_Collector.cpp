
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

#include "Multi_Thread_Pointer_File_Data_Collector.h"

Multi_Thread_Pointer_File_Data_Collector::Multi_Thread_Pointer_File_Data_Collector(){

     this->Memory_Delete_Condition = false;

     this->Include_Directory = nullptr;

     this->Shared_Data_Type_Instance_Name = nullptr;

     this->New_Class_Name = nullptr;

     this->Move_Command_For_File_List = nullptr;

     this->New_Include_Directory = nullptr;

     this->Reader_Pointer = nullptr;

     this->Header_File_Paths_In_New_Include_Directory = nullptr;
};

Multi_Thread_Pointer_File_Data_Collector::Multi_Thread_Pointer_File_Data_Collector(const Multi_Thread_Pointer_File_Data_Collector & orig){

};

Multi_Thread_Pointer_File_Data_Collector::~Multi_Thread_Pointer_File_Data_Collector(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void Multi_Thread_Pointer_File_Data_Collector::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->New_Class_Name);

         this->Clear_Pointer_Memory(&this->New_Include_Directory);

         this->Clear_Pointer_Memory(&this->Shared_Data_Type_Instance_Name);

         if(this->Header_File_Paths_In_New_Include_Directory != nullptr){

             for(int i=0;i<3;i++){

                 this->Clear_Pointer_Memory(&(this->Header_File_Paths_In_New_Include_Directory[i]));
             }

             delete [] this->Header_File_Paths_In_New_Include_Directory;

             this->Header_File_Paths_In_New_Include_Directory = nullptr;
         }

         this->Data_Collector.Clear_Dynamic_Memory();

         this->Compile_Data_Collector.Clear_Dynamic_Memory();
     }
}

void Multi_Thread_Pointer_File_Data_Collector::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void Multi_Thread_Pointer_File_Data_Collector::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->Compile_Data_Collector.Receive_Descriptor_File_Reader(Pointer);
}

void Multi_Thread_Pointer_File_Data_Collector::Receive_Data_Type_Number(int Number){

     this->Data_Type_Number = Number;
}

void Multi_Thread_Pointer_File_Data_Collector::Determine_Data_Type_Informations(){

     int index_number = 0;

     int Total_Data_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     for(int i=0;i<Total_Data_Number;i++){

         Shared_Memory_Data_Type Data_Type_Holder = this->Reader_Pointer->Get_Shared_Data_Types()[i];

         if(this->Data_Type_Number == Data_Type_Holder.Data_Number){

            index_number = i;
         }
     }

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     Shared_Memory_Data_Type Data_Type_Holder = this->Reader_Pointer->Get_Shared_Data_Types()[index_number];

     this->Data_Collector.Receive_Data_Type(Data_Type_Holder.Data_Type);

     this->Data_Collector.Receive_Construction_Point(Construction_Point);

     if(Data_Type_Holder.Header_File_Name != nullptr){

        this->Data_Collector.Receive_Data_Type_Include_File_Name(Data_Type_Holder.Header_File_Name);

        this->Include_Directory = Data_Type_Holder.Include_Directory;
     }
     else{

         this->Include_Directory = nullptr;
     }

     this->Determine_Shared_Data_Type_Instance_Name(Data_Type_Holder.Data_Type);

     this->Data_Collector.Set_Class_Name(this->Shared_Data_Type_Instance_Name);
}

void Multi_Thread_Pointer_File_Data_Collector::Determine_Shared_Data_Type_Instance_Name(char * Data_Type_Name){

     char Type_Word [] = {'T','y','p','e','_','S','m','a','r','t','_','P','o','i','n','t','e','r','\0'};

     char Subline_Character [] = {'_','\0'};

     int Data_Type_Object_Name_Size = strlen(Data_Type_Name);

     int Type_Word_List_Size = strlen(Type_Word);

     int Instance_Name_Size = Data_Type_Object_Name_Size + Type_Word_List_Size;

     this->Memory_Delete_Condition = false;

     this->Shared_Data_Type_Instance_Name = new char [10*Instance_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->Shared_Data_Type_Instance_Name,Data_Type_Name,&index_counter);

     this->Place_Information(&this->Shared_Data_Type_Instance_Name,Subline_Character,&index_counter);

     this->Place_Information(&this->Shared_Data_Type_Instance_Name,Type_Word,&index_counter);

     this->Shared_Data_Type_Instance_Name[index_counter] = '\0';
}

void Multi_Thread_Pointer_File_Data_Collector::Receive_Newly_Constructed_Include_Directory(char * Include_Directory){

     int String_Size = strlen(Include_Directory);

     this->Memory_Delete_Condition = false;

     this->New_Include_Directory = new char [10*String_Size];

     this->Place_String(&this->New_Include_Directory,Include_Directory);
}

void Multi_Thread_Pointer_File_Data_Collector::Build_File_List(){

     this->Memory_Delete_Condition = false;

     this->Determine_Data_Type_Informations();

     this->Data_Collector.Collect_Informations();

     this->Determine_New_Pointer_Class_Name();

     this->Compile_Data_Collector.Receive_Pointer_Initializer_Adress(&(this->Data_Collector.Pointer_Initializer));

     this->Compile_Data_Collector.Receive_Manager_Initializer_Adress(&(this->Data_Collector.Manager_Initializer));

     this->Compile_Data_Collector.Receive_Reporter_Initializer_Adress(&(this->Data_Collector.Reporter_Initializer));

     this->Compile_Data_Collector.Receive_Include_Directory(this->Include_Directory);

     this->Compile_Data_Collector.Receive_Construction_Point(this->Reader_Pointer->Get_Construction_Point());

     this->Compile_Data_Collector.Collect_Informations();

     this->File_Cleaner.Remove_Source_Files(this->Data_Collector.Get_Source_File_Name_Matrix());

     this->File_Cleaner.Remove_Header_File_Extras(this->Data_Collector.Get_Header_File_Name_Matrix());

     this->File_Cleaner.Remove_Object_Files(this->Data_Collector.Get_Object_File_Name_Matrix());

     this->Determine_Header_File_Paths_In_New_Include_Directory();
}

void Multi_Thread_Pointer_File_Data_Collector::Determine_New_Pointer_Class_Name(){

     char * Class_Name = this->Data_Collector.Pointer_Initializer.Get_NewClassName();

     int Class_Name_Size = strlen(Class_Name);

     this->New_Class_Name = new char [10*Class_Name_Size];

     this->Place_String(&this->New_Class_Name,Class_Name);
}

void Multi_Thread_Pointer_File_Data_Collector::Move_Header_Files(){

     char * Current_Directory = get_current_dir_name();

     char Directory_Character [] = {'/','\0'};

     int Current_Directory_String_Size = strlen(Current_Directory);

     char ** Header_File_Name = this->Get_Header_File_Name_Matrix();

     for(int i=0;i<3;i++){

         char * Header_File_Full_Path = new char [10*Current_Directory_String_Size];

         int index_counter = 0;

         this->Place_Information(&Header_File_Full_Path,Current_Directory,&index_counter);

         this->Place_Information(&Header_File_Full_Path,Directory_Character,&index_counter);

         this->Place_Information(&Header_File_Full_Path,Header_File_Name[i],&index_counter);

         Header_File_Full_Path[index_counter] = '\0';

         char * Header_File_New_Path = new char [10*Current_Directory_String_Size];

         index_counter = 0;

         this->Place_Information(&Header_File_New_Path,this->New_Include_Directory,&index_counter);

         this->Place_Information(&Header_File_New_Path,Directory_Character,&index_counter);

         this->Place_Information(&Header_File_New_Path,Header_File_Name[i],&index_counter);

         Header_File_New_Path[index_counter] = '\0';

         this->File_Manager.Move_File(Header_File_New_Path,Header_File_Full_Path);

         delete [] Header_File_Full_Path;

         delete [] Header_File_New_Path;
     }

     free(Current_Directory);
}

void Multi_Thread_Pointer_File_Data_Collector::Run_System_Commands(){

     int system_return_value = this->System_Interface.System_Function(this->Get_Compiler_Command_For_ReportFileBuilder());

     if(system_return_value != 0){

        std::cerr << "An error occured in smart pointer construction ..";

        exit(EXIT_FAILURE);
     }

     system_return_value = this->System_Interface.System_Function(this->Get_Compiler_Command_For_MemoryManager());

     if(system_return_value != 0){

        std::cerr << "An error occured in smart pointer construction ..";

        exit(EXIT_FAILURE);
     }

     system_return_value = this->System_Interface.System_Function(this->Get_Compiler_Command_For_SmartPointer());

     if(system_return_value != 0){

        std::cerr << "An error occured in smart pointer construction ..";

        exit(EXIT_FAILURE);
     }

     this->Move_Header_Files();

     this->File_Cleaner.Remove_Source_Files(this->Get_Implementation_File_Name_Matrix());

     this->File_Cleaner.Remove_Header_File_Extras(this->Get_Header_File_Name_Matrix());
}

void Multi_Thread_Pointer_File_Data_Collector::Determine_Header_File_Paths_In_New_Include_Directory(){

     char Directory_Character [] = {'/','\0'};

     this->Header_File_Paths_In_New_Include_Directory = new char * [10];

     int Directory_Name_Size = strlen(this->New_Include_Directory);

     for(int i=0;i<3;i++){

         char * Header_File_Name = this->Get_Header_File_Name_Matrix()[i];

         int Header_File_Name_Size = strlen(Header_File_Name);

         int Path_Size = Directory_Name_Size + Header_File_Name_Size;

         this->Header_File_Paths_In_New_Include_Directory[i] = new char [10*Path_Size];

         int index_counter = 0;

         this->Place_Information(&(this->Header_File_Paths_In_New_Include_Directory[i]),this->New_Include_Directory,&index_counter);

         this->Place_Information(&(this->Header_File_Paths_In_New_Include_Directory[i]),Directory_Character,&index_counter);

         this->Place_Information(&(this->Header_File_Paths_In_New_Include_Directory[i]),Header_File_Name,&index_counter);

         this->Header_File_Paths_In_New_Include_Directory[i][index_counter] = '\0';
     }
}

void Multi_Thread_Pointer_File_Data_Collector::Place_String(char ** Pointer, char * String){

     int String_Size = strlen(String);

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void Multi_Thread_Pointer_File_Data_Collector::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_New_Class_Name(){

       return this->New_Class_Name;
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_Move_Command_For_File_List(){

       return this->Move_Command_For_File_List;
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_Source_File_Name_List(){

       return this->Data_Collector.Get_Source_File_Name_List();
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_Header_File_Name_List(){

       return this->Data_Collector.Get_Header_File_Name_List();
}

char ** Multi_Thread_Pointer_File_Data_Collector::Get_Header_File_Name_Matrix(){

        return this->Data_Collector.Get_Header_File_Name_Matrix();
}

char ** Multi_Thread_Pointer_File_Data_Collector::Get_Implementation_File_Name_Matrix(){

        return this->Data_Collector.Get_Source_File_Name_Matrix();
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_Object_File_List(){

       return this->Data_Collector.Get_Object_File_List();
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_Compiler_Command_For_ReportFileBuilder(){

       return this->Compile_Data_Collector.Get_Compiler_Command_For_ReportFile_Builder();
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_Compiler_Command_For_MemoryManager(){

       return this->Compile_Data_Collector.Get_Compiler_Command_For_Memory_Manager_Builder();
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_Compiler_Command_For_SmartPointer(){

       return this->Compile_Data_Collector.Get_Compiler_Command_For_Pointer();
}

char ** Multi_Thread_Pointer_File_Data_Collector::Get_Header_File_Paths_In_New_Include_Directory(){

        return this->Header_File_Paths_In_New_Include_Directory;
}

char * Multi_Thread_Pointer_File_Data_Collector::Get_Data_Type_Include_Directory(){

       return this->Include_Directory;
}
