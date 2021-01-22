
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

#include "Compiler_Descriptor_File_Reader.h"

Compiler_Descriptor_File_Reader::Compiler_Descriptor_File_Reader(){

       this->Memory_Delete_Condition = false;

       this->ConstString = nullptr;

       this->DescriptorFileDirectory = nullptr;

       this->DescriptorFileName = nullptr;

       this->Include_Directory_List = nullptr;

       this->Library_Directory_List = nullptr;

       this->Source_File_Directory_List = nullptr;

       this->Source_File_Name_List = nullptr;

       this->Header_File_Name_List = nullptr;

       this->Library_Name_List = nullptr;

       this->Main_File_Name = nullptr;

       this->Executable_File_Name = nullptr;

       this->Option_List = nullptr;
}

Compiler_Descriptor_File_Reader::Compiler_Descriptor_File_Reader(const Compiler_Descriptor_File_Reader & orig){

}

Compiler_Descriptor_File_Reader::~Compiler_Descriptor_File_Reader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void Compiler_Descriptor_File_Reader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->ConstString);

         this->Clear_Pointer_Memory(&this->DescriptorFileDirectory);

         this->Clear_Pointer_Memory(&this->DescriptorFileName);

         if((this->Include_Directory_Number > 0) && (this->Include_Directory_List != nullptr)){

            for(int i=0;i<this->Include_Directory_Number;i++){

                this->Clear_Pointer_Memory(&(this->Include_Directory_List[i]));
            }

            delete [] this->Include_Directory_List;

            this->Include_Directory_List = nullptr;
         }

         if((this->Library_Directory_Number > 0) && (this->Library_Directory_List != nullptr)){

            for(int i=0;i<this->Library_Directory_Number;i++){

                this->Clear_Pointer_Memory(&(this->Library_Directory_List[i]));
            }

            delete [] this->Library_Directory_List;

            this->Library_Directory_List = nullptr;
         }

         if((this->Source_File_Directory_Number > 0) && (this->Source_File_Directory_List != nullptr)){

            for(int i=0;i<this->Source_File_Directory_Number;i++){

                this->Clear_Pointer_Memory(&(this->Source_File_Directory_List[i]));
            }

            delete [] this->Source_File_Directory_List;

            this->Source_File_Directory_List = nullptr;
         }

         if((this->Source_File_Names_Number > 0) && (this->Source_File_Name_List != nullptr)){

            for(int i=0;i<this->Source_File_Names_Number;i++){

                this->Clear_Pointer_Memory(&(this->Source_File_Name_List[i]));
            }

            delete [] this->Source_File_Name_List;

            this->Source_File_Name_List = nullptr;
         }

         if((this->Header_File_Names_Number > 0) && (this->Header_File_Name_List != nullptr)){

            for(int i=0;i<this->Header_File_Names_Number;i++){

                this->Clear_Pointer_Memory(&(this->Header_File_Name_List[i]));
            }

            delete [] this->Header_File_Name_List;

            this->Header_File_Name_List = nullptr;
         }

         if((this->Library_Names_Number > 0) && (this->Library_Name_List != nullptr)){

            for(int i=0;i<this->Library_Names_Number;i++){

                this->Clear_Pointer_Memory(&(this->Library_Name_List[i]));
            }

            delete [] this->Library_Name_List;

            this->Library_Name_List = nullptr;
         }

         if((this->Is_There_Main_File_Decleration) && (this->Main_File_Name != nullptr)){

            this->Clear_Pointer_Memory(&this->Main_File_Name);
         }

         if(this->Executable_File_Name != nullptr){

            this->Clear_Pointer_Memory(&this->Executable_File_Name);
         }

         if((this->Option_Number > 0) && (this->Option_List != nullptr)){

            for(int i=0;i<this->Option_Number ;i++){

                this->Clear_Pointer_Memory(&this->Option_List[i]);
            }

            delete [] this->Option_List;

            this->Option_List = nullptr;
         }
     }
}

void Compiler_Descriptor_File_Reader::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void Compiler_Descriptor_File_Reader::Receive_Descriptor_File_Directory(const char * FileDirectory){

     int String_Size = strlen(FileDirectory);

     this->DescriptorFileDirectory = new char [10*String_Size];

     this->Place_String(&this->DescriptorFileDirectory,FileDirectory,String_Size);
}

void Compiler_Descriptor_File_Reader::Receive_Descriptor_File_Directory(char * FileDirectory){

     int String_Size = strlen(FileDirectory);

     this->DescriptorFileDirectory = new char [10*String_Size];

     this->Place_String(&this->DescriptorFileDirectory,FileDirectory,String_Size);
}

void Compiler_Descriptor_File_Reader::Receive_Descriptor_File_Name(const char * FileName){

     int String_Size = strlen(FileName);

     this->DescriptorFileName = new char [10*String_Size];

     this->Place_String(&this->DescriptorFileName,FileName,String_Size);
}

void Compiler_Descriptor_File_Reader::Receive_Descriptor_File_Name(char * FileName){

     int String_Size = strlen(FileName);

     this->DescriptorFileName = new char [10*String_Size];

     this->Place_String(&this->DescriptorFileName,FileName,String_Size);
}

void Compiler_Descriptor_File_Reader::Receive_Descriptor_File_Infomations(){

     this->DirectoryManager.ChangeDirectory(this->DescriptorFileDirectory);

     this->StringOperations.SetFilePath(this->DescriptorFileName);

     this->Determine_Decleration_Locations();

     this->Determine_Decleration_Numbers();

     this->Allocate_Memory_For_Lists();

     this->Receive_Include_Directory_List();

     this->Receive_Library_Directory_List();

     this->Receive_Source_File_Directory_List();

     this->Receive_Source_File_Name_List();

     this->Receive_Header_File_Name_List();

     this->Receive_Library_Name_List();

     this->Receive_Option_List();

     this->Receive_Main_File_Name();

     this->DirectoryManager.Clear_Dynamic_Memory();

     this->StringOperations.Clear_Dynamic_Memory();
}

void Compiler_Descriptor_File_Reader::Determine_Decleration_Locations(){

     // Determination of Include Directories decleration region

     this->ReadConstString("INCLUDE DIRECTORIES:");

     this->Include_Directories_Region[0] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("LIBRARY DIRECTORIES:");

     this->Include_Directories_Region[1] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;

     // Determination of Library Directories decleration Region

     this->ReadConstString("LIBRARY DIRECTORIES:");

     this->Library_Directories_Region[0] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("SOURCE FILE DIRECTORIES:");

     this->Library_Directories_Region[1] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;

     // Determination of Source File Directories Decleration Region

     this->ReadConstString("SOURCE FILE DIRECTORIES:");

     this->SourceFile_Directores_Region[0] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("SOURCE FILE NAMES:");

     this->SourceFile_Directores_Region[1] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;

     // Determination of Source File Names Decleration region

     this->ReadConstString("SOURCE FILE NAMES:");

     this->SourceFile_Names_Region[0] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("HEADER FILE NAMES:");

     this->SourceFile_Names_Region[1] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;

     // Determination of Header File Names Decleration Region

     this->ReadConstString("HEADER FILE NAMES:");

     this->HeaderFile_Names_Region[0] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("MAIN FILE NAME:");

     this->HeaderFile_Names_Region[1] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;

     // Determination of Main File Decleration Region

     this->ReadConstString("MAIN FILE NAME:");

     this->Main_File_Decleration_Region[0] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("EXECUTABLE FILE NAME:");

     this->Main_File_Decleration_Region[1] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;

     // Determine Executable File Name Decleration Region

     this->ReadConstString("EXECUTABLE FILE NAME:");

     this->Executable_File_Name_Region[0] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("OPTIONS:");

     this->Executable_File_Name_Region[1] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;

     // Determine Decleration Region of Option List

     this->ReadConstString("OPTIONS:");

     this->Options_Decleration_Region[0] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("LIBRARY NAMES:");

     this->Options_Decleration_Region[1] = this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;

     // Determination of Library Names Decleration Region

     this->ReadConstString("LIBRARY NAMES:");

     this->Library_Names_Region[0] =  this->StringOperations.FindNextWordLine(this->GetConstString(),1)+1;

     this->ReadConstString("END");

     this->Library_Names_Region[1] =  this->StringOperations.FindNextWordLine(this->GetConstString(),1)-1;
}

void Compiler_Descriptor_File_Reader::Determine_Decleration_Numbers(){

     this->Include_Directory_Number = this->Determine_Record_Number(this->Include_Directories_Region[0],this->Include_Directories_Region[1]);

     this->Library_Directory_Number = this->Determine_Record_Number(this->Library_Directories_Region[0],this->Library_Directories_Region[1]);

     this->Source_File_Directory_Number = this->Determine_Record_Number(this->SourceFile_Directores_Region[0],this->SourceFile_Directores_Region[1]);

     this->Source_File_Names_Number = this->Determine_Record_Number(this->SourceFile_Names_Region[0],this->SourceFile_Names_Region[1]);

     this->Header_File_Names_Number = this->Determine_Record_Number(this->HeaderFile_Names_Region[0],this->HeaderFile_Names_Region[1]);

     this->Library_Names_Number = this->Determine_Record_Number(this->Library_Names_Region[0],this->Library_Names_Region[1]);

     this->Option_Number = this->Determine_Record_Number(this->Options_Decleration_Region[0],this->Options_Decleration_Region[1]);

     int Main_File_Status = this->Determine_Record_Number(this->Main_File_Decleration_Region[0],this->Main_File_Decleration_Region[1]);

     if(Main_File_Status == 1){

        this->Is_There_Main_File_Decleration = true;
     }

     if(Main_File_Status == 0){

        this->Is_There_Main_File_Decleration = false;
     }

     if(Main_File_Status > 1){

        std::cout << "\n There ara more than one main file decleration ..!";

        std::cout << "\n The process has been interrupted ..";

        std::cout << "\n\n PRESS ENTER IN ORDER TO EXIT FROM PROCESS ..";

        std::cin.get();

        std::cin.get();

        exit(0);
     }
}

void Compiler_Descriptor_File_Reader::Allocate_Memory_For_Lists(){

     if(this->Include_Directory_Number > 0){

        this->Include_Directory_List = new char * [10*this->Include_Directory_Number];

        for(int i=0;i<2*this->Include_Directory_Number;i++){

            this->Include_Directory_List[i] = nullptr;
        }
     }

     if(this->Library_Directory_Number > 0){

        this->Library_Directory_List = new char * [10*this->Library_Directory_Number];

        for(int i=0;i<2*this->Library_Directory_Number;i++){

            this->Library_Directory_List[i] = nullptr;
        }
     }

     if(this->Source_File_Directory_Number > 0){

        this->Source_File_Directory_List = new char * [10*this->Source_File_Directory_Number];

        for(int i=0;i<2*this->Source_File_Directory_Number;i++){

            this->Source_File_Directory_List[i] = nullptr;
        }
     }

     if(this->Source_File_Names_Number > 0){

        this->Source_File_Name_List  = new char * [10*this->Source_File_Names_Number];

        for(int i=0;i<2*this->Source_File_Names_Number;i++){

           this->Source_File_Name_List[i] = nullptr;
        }
     }

     if(this->Header_File_Names_Number > 0){

        this->Header_File_Name_List = new char * [10*this->Header_File_Names_Number];

        for(int i=0;i<2*this->Header_File_Names_Number;i++){

            this->Header_File_Name_List[i] = nullptr;
        }
     }

     if(this->Library_Names_Number > 0){

        this->Library_Name_List = new char * [10*this->Library_Names_Number];

        for(int i=0;i<2*this->Library_Names_Number;i++){

            this->Library_Name_List[i] = nullptr;
        }
     }

     if(this->Option_Number > 0){

        this->Option_List = new char * [10*this->Option_Number];

        for(int i=0;i<2*this->Option_Number;i++){

            this->Option_List[i] = nullptr;
        }
     }
}

void Compiler_Descriptor_File_Reader::Receive_Include_Directory_List(){

     int Start_Point = this->Include_Directories_Region[0];

     int End_Point   = this->Include_Directories_Region[1];

     int index_counter = 0;

     for(int i=Start_Point;i<End_Point;i++){

         this->StringOperations.ReadFileLine(i);

         char * String_List = this->StringOperations.GetStringBuffer();

         if(this->Get_Line_Record_Status(String_List)){

            int String_Size = strlen(String_List);

            this->Include_Directory_List[index_counter] = new char [10*String_Size];

            this->Place_String(&(this->Include_Directory_List[index_counter]),String_List,String_Size);

            index_counter++;
         }
     }
}

void Compiler_Descriptor_File_Reader::Receive_Library_Directory_List(){

     int Start_Point = this->Library_Directories_Region[0];

     int End_Point   = this->Library_Directories_Region[1];

     int index_counter = 0;

     for(int i=Start_Point;i<End_Point;i++){

         this->StringOperations.ReadFileLine(i);

         char * String_List = this->StringOperations.GetStringBuffer();

         if(this->Get_Line_Record_Status(String_List)){

            int String_Size = strlen(String_List);

            this->Library_Directory_List[index_counter] = new char [10*String_Size];

            this->Place_String(&(this->Library_Directory_List[index_counter]),String_List,String_Size);

            index_counter++;
         }
     }
}

void Compiler_Descriptor_File_Reader::Receive_Source_File_Directory_List(){

     int Start_Point = this->SourceFile_Directores_Region[0];

     int End_Point   = this->SourceFile_Directores_Region[1];

     int index_counter = 0;

     for(int i=Start_Point;i<End_Point;i++){

         this->StringOperations.ReadFileLine(i);

         char * String_List = this->StringOperations.GetStringBuffer();

         if(this->Get_Line_Record_Status(String_List)){

            int String_Size = strlen(String_List);

            this->Source_File_Directory_List[index_counter] = new char [10*String_Size];

            this->Place_String(&(this->Source_File_Directory_List[index_counter]),String_List,String_Size);

            index_counter++;
         }
     }
}

void Compiler_Descriptor_File_Reader::Receive_Source_File_Name_List(){

     int Start_Point = this->SourceFile_Names_Region[0];

     int End_Point   = this->SourceFile_Names_Region[1];

     int index_counter = 0;

     for(int i=Start_Point;i<End_Point;i++){

         this->StringOperations.ReadFileLine(i);

         char * String_List = this->StringOperations.GetStringBuffer();

         if(this->Get_Line_Record_Status(String_List)){

            int String_Size = strlen(String_List);

            this->Source_File_Name_List[index_counter] = new char [10*String_Size];

            this->Place_String(&(this->Source_File_Name_List[index_counter]),String_List,String_Size);

            index_counter++;
         }
     }
}

void Compiler_Descriptor_File_Reader::Receive_Header_File_Name_List(){

     int Start_Point = this->HeaderFile_Names_Region[0];

     int End_Point   = this->HeaderFile_Names_Region[1];

     int index_counter = 0;

     for(int i=Start_Point;i<End_Point;i++){

         this->StringOperations.ReadFileLine(i);

         char * String_List = this->StringOperations.GetStringBuffer();

         if(this->Get_Line_Record_Status(String_List)){

            int String_Size = strlen(String_List);

            this->Header_File_Name_List[index_counter] = new char [10*String_Size];

            this->Place_String(&(this->Header_File_Name_List[index_counter]),String_List,String_Size);

            index_counter++;
         }
     }
}

void Compiler_Descriptor_File_Reader::Receive_Library_Name_List(){

     int Start_Point = this->Library_Names_Region[0];

     int End_Point   = this->Library_Names_Region[1];

     int index_counter = 0;

     for(int i=Start_Point;i<End_Point;i++){

         this->StringOperations.ReadFileLine(i);

         char * String_List = this->StringOperations.GetStringBuffer();

         if(this->Get_Line_Record_Status(String_List)){

            int String_Size = strlen(String_List);

            this->Library_Name_List[index_counter] = new char [10*String_Size];

            this->Place_String(&(this->Library_Name_List[index_counter]),String_List,String_Size);

            index_counter++;
         }
     }
}

void Compiler_Descriptor_File_Reader::Receive_Option_List(){

     int Start_Point = this->Options_Decleration_Region[0];

     int End_Point   = this->Options_Decleration_Region[1];

     int index_counter = 0;

     for(int i=Start_Point;i<End_Point;i++){

         this->StringOperations.ReadFileLine(i);

         char * String_List = this->StringOperations.GetStringBuffer();

         if(this->Get_Line_Record_Status(String_List)){

            int String_Size = strlen(String_List);

            this->Option_List[index_counter] = new char [10*String_Size];

            this->Place_String(&(this->Option_List[index_counter]),String_List,String_Size);

            index_counter++;
         }
     }
}

void Compiler_Descriptor_File_Reader::Receive_Main_File_Name(){

     if(this->Is_There_Main_File_Decleration){

         int Start_Point = this->Main_File_Decleration_Region[0];

         int End_Point   = this->Main_File_Decleration_Region[1];

         for(int i=Start_Point;i<End_Point;i++){

             this->StringOperations.ReadFileLine(i);

             char * String_List = this->StringOperations.GetStringBuffer();

             if(this->Get_Line_Record_Status(String_List)){

                int String_Size = strlen(String_List);

                this->Main_File_Name = new char [10*String_Size];

                this->Place_String(&(this->Main_File_Name),String_List,String_Size);
             }
         }

         Start_Point = this->Executable_File_Name_Region[0];

         End_Point   = this->Executable_File_Name_Region[1];

         for(int i=Start_Point;i<End_Point;i++){

             this->StringOperations.ReadFileLine(i);

             char * String_List = this->StringOperations.GetStringBuffer();

             if(this->Get_Line_Record_Status(String_List)){

                int String_Size = strlen(String_List);

                this->Executable_File_Name = new char [10*String_Size];

                this->Place_String(&(this->Executable_File_Name),String_List,String_Size);
             }
         }
     }
}

void Compiler_Descriptor_File_Reader::ReadConstString(const char * String){

     this->Clear_Pointer_Memory(&this->ConstString);

     int String_Size = strlen(String);

     this->ConstString = new char [10*String_Size];

     this->Place_String(&this->ConstString,String,String_Size);
}

char * Compiler_Descriptor_File_Reader::GetConstString(){

       return this->ConstString;
}

int Compiler_Descriptor_File_Reader::Determine_Record_Number(int Start_Line,int End_Line){

     this->Record_Number = 0;

     int Total_Line_Number = End_Line - Start_Line;

     int Current_Line = Start_Line;

     for(int i=0;i<Total_Line_Number;i++){

          this->StringOperations.ReadFileLine(Current_Line);

          if(this->StringOperations.GetStringBuffer()[0]!= '\0'){

             this->Record_Number++;
          }

          Current_Line++;
     }

     return this->Record_Number;
}

bool Compiler_Descriptor_File_Reader::Get_Line_Record_Status(char * Read_Line){

     this->Is_This_Record_Line = false;

     if(Read_Line[0]!= '\0'){

        this->Is_This_Record_Line = true;
     }

     return this->Is_This_Record_Line;
}


void Compiler_Descriptor_File_Reader::Place_String(char ** Pointer, char * String,int String_Size){

     int Start_Point = 0;

     while(String[Start_Point] == ' '){

           Start_Point++;
     }

     int index_counter = 0;

     for(int i=Start_Point;i<String_Size;i++){

        (*Pointer)[index_counter] = String[i];

        index_counter++;
     }

     (*Pointer)[index_counter] = '\0';
}

void Compiler_Descriptor_File_Reader::Place_String(char ** Pointer, const char * String, int String_Size){

     int Start_Point = 0;

     while(String[Start_Point] == ' '){

           Start_Point++;
     }

     int index_counter = 0;

     for(int i=Start_Point;i<String_Size;i++){

        (*Pointer)[index_counter] = String[i];

        index_counter++;
     }

     (*Pointer)[index_counter] = '\0';
}
