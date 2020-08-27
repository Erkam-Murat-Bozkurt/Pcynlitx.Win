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

#include "Thread_Locker_Builder.h"

Thread_Locker_Builder::Thread_Locker_Builder(){

    this->Memory_Delete_Condition = false;

    this->Compiler_Command = nullptr;
};

Thread_Locker_Builder::Thread_Locker_Builder(const Thread_Locker_Builder & orig){

};

Thread_Locker_Builder::~Thread_Locker_Builder(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
};

void Thread_Locker_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Compiler_Command != nullptr){

            delete [] this->Compiler_Command;

            this->Compiler_Command = nullptr;
         }

         this->FileManager.Clear_Dynamic_Memory();

         this->Directory_Manager.Clear_Dynamic_Memory();
     }
}

void Thread_Locker_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->Construction_Point_Holder = this->Reader_Pointer->Get_Construction_Point();

     this->HeaderFileBuilder.Receive_Descriptor_File_Reader(Pointer);
}

void Thread_Locker_Builder::Build_Thread_Locker(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->Memory_Delete_Condition = false;

     this->Directory_Manager.DetermineCurrentDirectory();

     this->Determine_Compiler_Command();

     this->HeaderFileBuilder.Build_thread_locker_header_file();

     this->FileManager.SetFilePath("Thread_Locker.cpp");

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #include <Thread_Locker.h>");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Locker::Thread_Locker(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Locker::Thread_Locker(const Thread_Locker & orig){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Locker::~Thread_Locker(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n ");

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Locker::lock(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->lock_mutex.lock();");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Locker::unlock(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->lock_mutex.unlock();");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n");

     this->FileManager.FileClose();
}

void Thread_Locker_Builder::Determine_Compiler_Command(){

     char Process_Command [] = {'g','+','+',' ','-','c',' ','-','s','t','d','=','c','+','+','1','4',' ','\0'};

     char Source_File_Name [] = "Thread_Locker.cpp";

     char Header_File_Name [] = "Thread_Locker.h";

     char Include_Directory_Determiner [] = {'-','I','\0'};

     char Include_Word [] = "-include";

     char Thread_Library_Name [] = {'-','l','p','t','h','r','e','a','d','\0'};

     char Space_Character [] = {' ','\0'};

     char Output_Redirection_Command [] = {'2','>',' ','\0'};

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     int Source_File_Name_Size = strlen(Source_File_Name);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int Process_Command_Name_Size = strlen(Process_Command);

     int Thread_Library_Name_Size = strlen(Thread_Library_Name);

     int Include_Directory_Determiner_Size = strlen(Include_Directory_Determiner);

     int Current_Directory_Name_Size = strlen(this->Directory_Manager.GetCurrentlyWorkingDirectory());

     int Include_Word_Name_Size = strlen(Include_Word);

     int Compiler_Command_Size = Source_File_Name_Size + Header_File_Name_Size

                                + Process_Command_Name_Size + Thread_Library_Name_Size

                                + Current_Directory_Name_Size + Include_Directory_Determiner_Size

                                + Include_Word_Name_Size;

     this->Compiler_Command = new char [10*Compiler_Command_Size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_Command,Process_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Directory_Determiner,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Source_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Header_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Thread_Library_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Output_Redirection_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Construction_Point_Holder,&index_counter);

     this->Place_Information(&this->Compiler_Command,Error_Message_File_Name,&index_counter);

     this->Compiler_Command[index_counter] = '\0';
}

void Thread_Locker_Builder::Remove_Header_Extra_File(){

     char Header_Extra_File [] = "Thread_Locker.h.gch";

     char Directory_Character [] = {'/','\0'};

     char * Current_Directory = this->Directory_Manager.GetCurrentlyWorkingDirectory();

     int Current_Directory_Size = strlen(Current_Directory);

     int Header_File_Name_Size = strlen(Header_Extra_File);

     int File_Path_Size = Current_Directory_Size  + Header_File_Name_Size;

     char * File_Path = new char [10*File_Path_Size];

     int index_counter = 0;

     this->Place_Information(&File_Path,Current_Directory,&index_counter);

     this->Place_Information(&File_Path,Directory_Character,&index_counter);

     this->Place_Information(&File_Path,Header_Extra_File,&index_counter);

     File_Path[index_counter] = '\0';

     this->FileManager.DeleteFile(File_Path);

     delete [] File_Path;
}

void Thread_Locker_Builder::Run_System_Commands(){

     int system_return_value =  this->System_Interface.System_Function(this->Compiler_Command);

     if(system_return_value != 0 ){

        std::cerr << "An error occured in Thread_Locker class compiling.." << std::endl;

        exit(1);
     }

     this->Remove_Header_Extra_File();
}

void Thread_Locker_Builder::Place_Information(char ** Pointer, char * Information, int * Counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

        (*Pointer)[(*Counter)] = Information[i];

        (*Counter)++;
     }
}
