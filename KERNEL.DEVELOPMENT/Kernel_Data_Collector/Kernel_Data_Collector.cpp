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

#include "Kernel_Data_Collector.h"

Kernel_Data_Collector::Kernel_Data_Collector(){

     this->Memory_Delete_Condition = false;

     this->New_Include_Directory_Name = nullptr;

     this->Object_File_List = nullptr;

     this->Library_Construction_Command = nullptr;
}

Kernel_Data_Collector::Kernel_Data_Collector(const Kernel_Data_Collector & orig){

}

Kernel_Data_Collector::~Kernel_Data_Collector(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void Kernel_Data_Collector::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->New_Include_Directory_Name);

         this->Clear_Pointer_Memory(&this->Object_File_List);

         this->Clear_Pointer_Memory(&this->Library_Construction_Command);

         this->DirectoryManager.Clear_Dynamic_Memory();
     }
}

void Kernel_Data_Collector::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void Kernel_Data_Collector::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;
}

void Kernel_Data_Collector::Remove_Object_Files(){

     this->Memory_Delete_Condition = false;

     char Manager_Class_Name [] = "Thread_Manager";

     char Data_Manager_Class_Name [] = "Thread_Data_Manager";

     char Manager_Client_Class_Name [] = "TM_Client";

     char Locker_Class_Name [] = "Thread_Locker";

     char Smart_Pointer_Add_Word  [] = "_Type_Smart_Pointer";

     char Memory_Manager_Add_Word [] = "_Type_Smart_Pointer_MemoryManager";

     char Report_File_Add_Word    [] = "_Type_Smart_Pointer_ReportFileBuilder";

     char Object_File_Extantion [] = {'.','o','\0'};

     char Directory_Character [] = {'/','\0'};

     char Client_Add_Word [] = "_Client.o";

     int Total_Class_Number = this->Reader_Pointer->Get_Class_Number();

     int Total_Data_Type_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     int Construction_Point_Name_Size = strlen(this->Reader_Pointer->Get_Construction_Point());

     if(Total_Data_Type_Number > 0){

        for(int i=0;i<Total_Data_Type_Number;i++){

            int index_counter = 0;

            int File_Name_Size = strlen(this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type) + Construction_Point_Name_Size;

            char * Smart_Pointer_File_Name = new char [10*File_Name_Size];

            char * Memory_Manager_File_Name = new char [10*File_Name_Size];

            char * Report_File_Builder_Name = new char [10*File_Name_Size];

            char * Smart_Pointer_Client_File_Name = new char [10*File_Name_Size];

            this->Place_Information(&Smart_Pointer_File_Name,Construction_Point,&index_counter);

            this->Place_Information(&Smart_Pointer_File_Name,Directory_Character,&index_counter);

            this->Place_Information(&Smart_Pointer_File_Name,this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type,&index_counter);

            this->Place_Information(&Smart_Pointer_File_Name,Smart_Pointer_Add_Word,&index_counter);

            this->Place_Information(&Smart_Pointer_File_Name,Object_File_Extantion,&index_counter);

            Smart_Pointer_File_Name[index_counter] = '\0';

            unlink(Smart_Pointer_File_Name);

            delete [] Smart_Pointer_File_Name;

            index_counter = 0;

            this->Place_Information(&Smart_Pointer_Client_File_Name,Construction_Point,&index_counter);

            this->Place_Information(&Smart_Pointer_Client_File_Name,Directory_Character,&index_counter);

            this->Place_Information(&Smart_Pointer_Client_File_Name,this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type,&index_counter);

            this->Place_Information(&Smart_Pointer_Client_File_Name,Smart_Pointer_Add_Word,&index_counter);

            this->Place_Information(&Smart_Pointer_Client_File_Name,Client_Add_Word,&index_counter);

            Smart_Pointer_Client_File_Name[index_counter] = '\0';

            unlink(Smart_Pointer_Client_File_Name); //Remove Smart pointer client object file

            delete [] Smart_Pointer_Client_File_Name;

            index_counter = 0;

            this->Place_Information(&Memory_Manager_File_Name,Construction_Point,&index_counter);

            this->Place_Information(&Memory_Manager_File_Name,Directory_Character,&index_counter);

            this->Place_Information(&Memory_Manager_File_Name,this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type,&index_counter);

            this->Place_Information(&Memory_Manager_File_Name,Memory_Manager_Add_Word,&index_counter);

            this->Place_Information(&Memory_Manager_File_Name,Object_File_Extantion,&index_counter);

            Memory_Manager_File_Name[index_counter] = '\0';

            unlink(Memory_Manager_File_Name); // Remove Memory Manager File

            delete [] Memory_Manager_File_Name;

            index_counter = 0;

            this->Place_Information(&Report_File_Builder_Name,Construction_Point,&index_counter);

            this->Place_Information(&Report_File_Builder_Name,Directory_Character,&index_counter);

            this->Place_Information(&Report_File_Builder_Name,this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type,&index_counter);

            this->Place_Information(&Report_File_Builder_Name,Report_File_Add_Word,&index_counter);

            this->Place_Information(&Report_File_Builder_Name,Object_File_Extantion,&index_counter);

            Report_File_Builder_Name[index_counter] = '\0';

            unlink(Report_File_Builder_Name);

            delete [] Report_File_Builder_Name;

            }
        }

        if(Total_Class_Number > 0){

           for(int i=0;i<Total_Class_Number;i++){

               int index_counter = 0;

               int File_Name_Size = strlen(this->Reader_Pointer->Get_Class_Names()[i].Class_Name) + Construction_Point_Name_Size;

               char * Class_Name = new char [10*File_Name_Size];

               this->Place_Information(&Class_Name,Construction_Point,&index_counter);

               this->Place_Information(&Class_Name,Directory_Character,&index_counter);

               this->Place_Information(&Class_Name,this->Reader_Pointer->Get_Class_Names()[i].Class_Name,&index_counter);

               this->Place_Information(&Class_Name,Client_Add_Word,&index_counter);

               Class_Name[index_counter] = '\0';

               unlink(Class_Name);

               delete [] Class_Name;
           }
        }

        int index_counter = 0;

        int Server_Class_Name_Size = strlen(this->Reader_Pointer->Get_Server_Class_Name()) + Construction_Point_Name_Size;

        char * Server_Class_Name = new char [10*Server_Class_Name_Size];

        this->Place_Information(&Server_Class_Name,Construction_Point,&index_counter);

        this->Place_Information(&Server_Class_Name,Directory_Character,&index_counter);

        this->Place_Information(&Server_Class_Name,this->Reader_Pointer->Get_Server_Class_Name(),&index_counter);

        this->Place_Information(&Server_Class_Name,Object_File_Extantion,&index_counter);

        Server_Class_Name [index_counter] = '\0';

        unlink(Server_Class_Name);

        delete [] Server_Class_Name;

        index_counter = 0;

        int Manager_Class_Name_Size = strlen(Manager_Class_Name) + Construction_Point_Name_Size;

        char * Manager_Class_Object_File_Name = new char [10*Manager_Class_Name_Size];

        this->Place_Information(&Manager_Class_Object_File_Name,Construction_Point,&index_counter);

        this->Place_Information(&Manager_Class_Object_File_Name,Directory_Character,&index_counter);

        this->Place_Information(&Manager_Class_Object_File_Name,Manager_Class_Name,&index_counter);

        this->Place_Information(&Manager_Class_Object_File_Name,Object_File_Extantion,&index_counter);

        Manager_Class_Object_File_Name[index_counter] = '\0';

        unlink(Manager_Class_Object_File_Name);

        delete [] Manager_Class_Object_File_Name;


        index_counter = 0;

        int Data_Manager_Class_Name_Size = strlen(Data_Manager_Class_Name) + Construction_Point_Name_Size;

        char * Data_Manager_Class_Object_File_Name = new char [10*Manager_Class_Name_Size];

        this->Place_Information(&Data_Manager_Class_Object_File_Name,Construction_Point,&index_counter);

        this->Place_Information(&Data_Manager_Class_Object_File_Name,Directory_Character,&index_counter);

        this->Place_Information(&Data_Manager_Class_Object_File_Name,Data_Manager_Class_Name,&index_counter);

        this->Place_Information(&Data_Manager_Class_Object_File_Name,Object_File_Extantion,&index_counter);

        Data_Manager_Class_Object_File_Name[index_counter] = '\0';

        unlink(Data_Manager_Class_Object_File_Name);

        delete [] Data_Manager_Class_Object_File_Name;



        index_counter = 0;

        int Manager_Client_Class_Name_Size = strlen(Manager_Client_Class_Name) + Construction_Point_Name_Size;

        char * Manager_Client_Class_Object_File_Name = new char [10*Manager_Client_Class_Name_Size];

        this->Place_Information(&Manager_Client_Class_Object_File_Name,Construction_Point,&index_counter);

        this->Place_Information(&Manager_Client_Class_Object_File_Name,Directory_Character,&index_counter);

        this->Place_Information(&Manager_Client_Class_Object_File_Name,Manager_Client_Class_Name,&index_counter);

        this->Place_Information(&Manager_Client_Class_Object_File_Name,Object_File_Extantion,&index_counter);

        Manager_Client_Class_Object_File_Name[index_counter] = '\0';

        unlink(Manager_Client_Class_Object_File_Name);

        delete [] Manager_Client_Class_Object_File_Name;

        index_counter = 0;

        int Locker_Class_Name_Size = strlen(Locker_Class_Name) + Construction_Point_Name_Size;

        char * Locker_Class_Object_File_Name = new char [10*Locker_Class_Name_Size];

        this->Place_Information(&Locker_Class_Object_File_Name,Construction_Point,&index_counter);

        this->Place_Information(&Locker_Class_Object_File_Name,Directory_Character,&index_counter);

        this->Place_Information(&Locker_Class_Object_File_Name,Locker_Class_Name,&index_counter);

        this->Place_Information(&Locker_Class_Object_File_Name,Object_File_Extantion,&index_counter);

        Locker_Class_Object_File_Name[index_counter] = '\0';

        unlink(Locker_Class_Object_File_Name);

        delete [] Locker_Class_Object_File_Name;
}

void Kernel_Data_Collector::Construct_New_Library(){

     this->Memory_Delete_Condition = false;

     char Command [] = {'a','r',' ','r','s',' ','l','i','b','\0'};

     char add_word [] = {'.','a','\0'};

     char Space_Character [] = {' ','\0'};

     int Command_Size = strlen(Command);

     int Adword_Size = strlen(add_word);

     int Server_Class_Name_Size = strlen(this->Reader_Pointer->Get_Server_Class_Name());

     int Object_File_List_Name_Size = strlen(this->Object_File_List);

     int Library_Command_Name_Size = Command_Size + Server_Class_Name_Size +

                                     Adword_Size +  Object_File_List_Name_Size;

     char Lib_word [] = "lib";

     int lib_word_size = strlen(Lib_word);

     int Library_Name_Size = Server_Class_Name_Size + Adword_Size + lib_word_size;

     char * Library_Name = new char [10*Library_Name_Size];

     int index_counter = 0;

     this->Place_Information(&Library_Name,Lib_word,&index_counter);

     this->Place_Information(&Library_Name,this->Reader_Pointer->Get_Server_Class_Name(),&index_counter);

     this->Place_Information(&Library_Name,add_word,&index_counter);

     Library_Name[index_counter] = '\0';

     unlink(Library_Name);

     index_counter = 0;

     this->Library_Construction_Command = new char [10*Library_Command_Name_Size];

     this->Place_Information(&this->Library_Construction_Command,Command,&index_counter);

     this->Place_Information(&this->Library_Construction_Command,this->Reader_Pointer->Get_Server_Class_Name(),&index_counter);

     this->Place_Information(&this->Library_Construction_Command,add_word,&index_counter);

     this->Place_Information(&this->Library_Construction_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Library_Construction_Command,this->Object_File_List,&index_counter);

     this->Library_Construction_Command[index_counter] = '\0';

     this->Jump_To_Construction_Point();

     int system_return_value = system(this->Library_Construction_Command);

     if(system_return_value != 0){

        std::cerr << "An error occured in library construction ..";

        exit(1);
     }

     delete [] Library_Name;
}

void Kernel_Data_Collector::Determine_Object_File_List(){

     this->Memory_Delete_Condition = false;

     char Manager_Class_Name [] = "Thread_Manager";

     char Data_Manager_Class_Name [] = "Thread_Data_Manager";

     char Manager_Client_Class_Name [] = "TM_Client";

     char Locker_Class_Name [] = "Thread_Locker";

     char Smart_Pointer_Add_Word  [] = "_Type_Smart_Pointer";

     char Memory_Manager_Add_Word [] = "_Type_Smart_Pointer_MemoryManager";

     char Report_File_Add_Word    [] = "_Type_Smart_Pointer_ReportFileBuilder";

     char Space_Character [] = {' ','\0'};

     char Object_File_Extantion [] = {'.','o','\0'};

     char Client_Add_Word [] = "_Client.o";

     int Object_File_List_Size = strlen(Manager_Class_Name) + strlen(Manager_Client_Class_Name) +

                                 + strlen(Data_Manager_Class_Name) + strlen(Locker_Class_Name);

     int Total_Class_Number = this->Reader_Pointer->Get_Class_Number();

     int Total_Data_Type_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     if(Total_Class_Number > 0){

        for(int i=0;i<Total_Class_Number;i++){

            Object_File_List_Size = Object_File_List_Size + strlen(this->Reader_Pointer->Get_Class_Names()[i].Class_Name);
        }
     }

     if(Total_Data_Type_Number > 0){

         for(int i=0;i<Total_Data_Type_Number;i++){

            Object_File_List_Size = Object_File_List_Size + strlen(this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type);
         }
     }

     Object_File_List_Size = Object_File_List_Size + strlen(this->Reader_Pointer->Get_Server_Class_Name());

     this->Object_File_List = new char [10*Object_File_List_Size];

     int index_counter = 0;

     if(Total_Data_Type_Number > 0){

        for(int i=0;i<Total_Data_Type_Number;i++){

            this->Place_Information(&this->Object_File_List,this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type,&index_counter);

            this->Place_Information(&this->Object_File_List,Smart_Pointer_Add_Word,&index_counter);

            this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

            this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);

            this->Place_Information(&this->Object_File_List,this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type,&index_counter);

            this->Place_Information(&this->Object_File_List,Memory_Manager_Add_Word,&index_counter);

            this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

            this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);

            this->Place_Information(&this->Object_File_List,this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type,&index_counter);

            this->Place_Information(&this->Object_File_List,Report_File_Add_Word,&index_counter);

            this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

            this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);
        }
     }

     this->Place_Information(&this->Object_File_List,Manager_Class_Name,&index_counter);

     this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

     this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);

     this->Place_Information(&this->Object_File_List,Data_Manager_Class_Name,&index_counter);

     this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

     this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);

     this->Place_Information(&this->Object_File_List,this->Reader_Pointer->Get_Server_Class_Name(),&index_counter);

     this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

     this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);

     if(Total_Class_Number > 0){

        for(int i=0;i<Total_Class_Number;i++){

            this->Place_Information(&this->Object_File_List,this->Reader_Pointer->Get_Class_Names()[i].Class_Name,&index_counter);

            this->Place_Information(&this->Object_File_List,Client_Add_Word,&index_counter);

            this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);
        }
     }

     if(Total_Data_Type_Number > 0){

        for(int i=0;i<Total_Data_Type_Number;i++){

            this->Place_Information(&this->Object_File_List,this->Reader_Pointer->Get_Shared_Data_Types()[i].Data_Type,&index_counter);

            this->Place_Information(&this->Object_File_List,Smart_Pointer_Add_Word,&index_counter);

            this->Place_Information(&this->Object_File_List,Client_Add_Word,&index_counter);

            this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);
        }
    }

    this->Place_Information(&this->Object_File_List,Manager_Client_Class_Name,&index_counter);

    this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

    this->Place_Information(&this->Object_File_List,Space_Character,&index_counter);

    this->Place_Information(&this->Object_File_List,Locker_Class_Name,&index_counter);

    this->Place_Information(&this->Object_File_List,Object_File_Extantion,&index_counter);

    this->Object_File_List[index_counter] = '\0';
}

void Kernel_Data_Collector::Construct_New_Include_Directory(){

     this->Memory_Delete_Condition = false;

     this->New_Include_Directory_Name = this->Reader_Pointer->Get_Constructed_Include_Directory();

     this->Jump_To_Construction_Point();

     int return_value = this->DirectoryManager.ChangeDirectory(this->New_Include_Directory_Name);

     if(return_value == 0){

        this->Jump_To_Construction_Point();

        this->DirectoryManager.Remove_Directory_Recursively(this->New_Include_Directory_Name);
     }

     this->DirectoryManager.MakeDirectory(this->New_Include_Directory_Name,0777);
}

void Kernel_Data_Collector::Jump_To_Construction_Point(){

     this->DirectoryManager.DetermineCurrentDirectory();

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     this->DirectoryManager.ChangeDirectory(Construction_Point);

     this->DirectoryManager.DetermineCurrentDirectory();
}

void Kernel_Data_Collector::Place_String(char ** Pointer,char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void Kernel_Data_Collector::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

char * Kernel_Data_Collector::Get_New_Include_Directory_Name(){

       return this->New_Include_Directory_Name;
}
