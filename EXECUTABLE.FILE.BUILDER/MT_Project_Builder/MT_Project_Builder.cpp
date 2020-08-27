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

#include "MT_Project_Builder.h"

MT_Project_Builder::MT_Project_Builder(){

    this->Memory_Delete_Condition = false;
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

void MT_Project_Builder::Build_Project(){

     this->File_Reader.Receive_Descriptor_File_Infomations();

     this->Remove_Compiler_Output_File();

     std::cout << "\n ";

     std::cout << "\n\t\t(\u2713 ) Descriptor file information has been readed\n";

     this->File_Constructor.Receive_Descriptor_File_Reader(&this->File_Reader);

     this->File_Constructor.Build_Compiler_Descriptor_File();

     this->File_Constructor.Clear_Dynamic_Memory();

     this->Directory_Manager.DetermineCurrentDirectory();

     std::cout << "\n\t\t(\u2713 ) Builder started to process \n";

     this->Project_Compiler.Receive_Descriptor_File_Directory(this->File_Reader.Get_Construction_Point());

     this->Project_Compiler.Receive_Descriptor_File_Name("Compiler_Descriptor_File");

     this->Project_Compiler.Receive_Descriptor_File_Infomations();

     this->Project_Compiler.Build_Project();

     char Compiler_Descriptor_File_Name [] = "Compiler_Descriptor_File";

     this->File_Manager.DeleteFile(Compiler_Descriptor_File_Name);

     this->Remove_Compiler_Output_File();

     this->File_Reader.Clear_Dynamic_Memory();

     std::cout << "\n\t\t(\u2713 ) The executable file is ready \n\n";
}

void MT_Project_Builder::Remove_Compiler_Output_File(){

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     int Error_Message_File_Name_Size = strlen(Error_Message_File_Name);

     int Construction_Point_Name_Size = strlen(this->File_Reader.Get_Construction_Point());

     this->Compiler_Output_File_Path = new char [10*Construction_Point_Name_Size];

     int index_counter = 0;

     for(int i=0;i<Construction_Point_Name_Size;i++){

         this->Compiler_Output_File_Path[index_counter] = this->File_Reader.Get_Construction_Point()[i];

         index_counter++;
     }

     for(int i=0;i<Error_Message_File_Name_Size;i++){

         this->Compiler_Output_File_Path[index_counter] = Error_Message_File_Name[i];

         index_counter++;
     }

     this->Compiler_Output_File_Path[index_counter] = '\0';

     int Is_Compiler_Output_File_Exist = access(this->Compiler_Output_File_Path,F_OK);

     if(Is_Compiler_Output_File_Exist == 0){

        unlink(this->Compiler_Output_File_Path);
     }

     delete [] this->Compiler_Output_File_Path;
}
