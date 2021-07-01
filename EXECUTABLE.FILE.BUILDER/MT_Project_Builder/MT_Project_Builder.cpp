/*

Copyright ©  2021,  Erkam Murat Bozkurt

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

#include "MT_Project_Builder.h"

MT_Project_Builder::MT_Project_Builder(){

    this->Memory_Delete_Condition = false;

    this->construction_success = 1;
}

MT_Project_Builder::MT_Project_Builder(const MT_Project_Builder & orig){

}

MT_Project_Builder::~MT_Project_Builder(){

}

void MT_Project_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->File_Manager.Clear_Dynamic_Memory();

         this->Directory_Manager.Clear_Dynamic_Memory();

         this->Project_Compiler.Clear_Dynamic_Memory();

         this->File_Constructor.Clear_Dynamic_Memory();

         this->File_Reader.Clear_Dynamic_Memory();

         delete [] this->Compiler_Output_File_Path;
     }
}

void MT_Project_Builder::Receive_Descriptor_File_Directory(const char * DescriptorFileDirectory){

     this->File_Reader.Receive_Descriptor_File_Directory(DescriptorFileDirectory);
}

void MT_Project_Builder::Receive_Descriptor_File_Directory(char * DescriptorFileDirectory){

     this->File_Reader.Receive_Descriptor_File_Directory(DescriptorFileDirectory);
}

void MT_Project_Builder::Receive_Descriptor_File_Name(const char * DescriptorFileName){

     this->File_Reader.Receive_Descriptor_File_Name(DescriptorFileName);
}

void MT_Project_Builder::Receive_Descriptor_File_Name(char * DescriptorFileName){

     this->File_Reader.Receive_Descriptor_File_Name(DescriptorFileName);
}

int  MT_Project_Builder::Build_Project(){

     this->File_Reader.Receive_Descriptor_File_Infomations();

     this->Determine_Compiler_Output_File_Path();

     this->Remove_Compiler_Output_File();

     std::cout << "\n ";

     std::cout << "\n\t\t# Descriptor file information has been readed\n";

     this->File_Constructor.Receive_Descriptor_File_Reader(&this->File_Reader);

     this->File_Constructor.Build_Compiler_Descriptor_File();

     this->Directory_Manager.DetermineCurrentDirectory();

     std::cout << "\n\t\t# Builder started to process \n";

     this->Project_Compiler.Receive_Descriptor_File_Directory(this->File_Reader.Get_Construction_Point());

     this->Project_Compiler.Receive_Descriptor_File_Name("Compiler_Descriptor_File");

     this->Project_Compiler.Receive_Descriptor_File_Infomations();

     int return_value = this->Project_Compiler.Build_Project();

     if(return_value!=0){

        this->construction_success = 1;

        std::cout << "\n MT_Project_Builder will return :" << this->construction_success;
     }

     char Compiler_Descriptor_File_Name [] = "Compiler_Descriptor_File";

     this->File_Manager.Delete_File(Compiler_Descriptor_File_Name);

     if(this->File_Manager.Is_This_File_Empty(this->Compiler_Output_File_Path)){

        this->construction_success = 0;
     }
     else{

           this->construction_success = 1;
     }

     std::cout << "\n\t\t# The executable file is ready \n\n";

     return this->construction_success;
}

bool MT_Project_Builder::Is_There_Error_On_Buffer(){

     this->Is_There_Std_Error_Message = false;

     this->Is_There_Std_Error_Message = this->File_Manager.Is_This_File_Empty(this->Compiler_Output_File_Path);

     return this->Is_There_Std_Error_Message;
}

void MT_Project_Builder::Determine_Compiler_Output_File_Path(){

     char Compiler_Output_File_Name [] = "Compiler_Output.txt";

     int Compiler_Output_File_Name_Size = strlen(Compiler_Output_File_Name);

     int Construction_Point_Name_Size = strlen(this->File_Reader.Get_Construction_Point());

     int Compiler_Output_File_Path_Size = Compiler_Output_File_Name_Size + Construction_Point_Name_Size;


     bool is_directory_operator_exist = false;

     for(int i=Construction_Point_Name_Size-10;i<Construction_Point_Name_Size;i++){

         if(this->File_Reader.Get_Construction_Point()[i] == '\\'){

            is_directory_operator_exist = true;
         }
     }

     this->Compiler_Output_File_Path = new char [10*Compiler_Output_File_Path_Size];

     int index_counter = 0;

     for(int i=0;i<Construction_Point_Name_Size;i++){

         this->Compiler_Output_File_Path[index_counter] = this->File_Reader.Get_Construction_Point()[i];

         index_counter++;
     }

     if(!is_directory_operator_exist){

         this->Compiler_Output_File_Path[index_counter] = '\\';

         index_counter++;
     }

     for(int i=0;i<Compiler_Output_File_Name_Size;i++){

         this->Compiler_Output_File_Path[index_counter] = Compiler_Output_File_Name[i];

         index_counter++;
     }

     this->Compiler_Output_File_Path[index_counter] = '\0';
}

void MT_Project_Builder::Remove_Compiler_Output_File(){

     int Is_Compiler_Output_File_Exist = access(this->Compiler_Output_File_Path,F_OK);

     if(Is_Compiler_Output_File_Exist == 0){

        this->File_Manager.Delete_File(this->Compiler_Output_File_Path);
     }
}
