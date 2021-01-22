
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

#include "Multi_Thread_Pointer_Client_Header_Builder.h"

Multi_Thread_Pointer_Client_Header_Builder::Multi_Thread_Pointer_Client_Header_Builder(){

       this->Memory_Delete_Condition = false;

       this->InclusionWord = nullptr;

       this->Data_Type = nullptr;

       this->Construction_Point = nullptr;

       this->name_space_info = nullptr;

       this->Base_Class_Header_File_Name = nullptr;

       this->Base_Class_Name = nullptr;

       this->Client_Class_Name = nullptr;

       this->Client_Class_Header_File_Name = nullptr;
};

Multi_Thread_Pointer_Client_Header_Builder::Multi_Thread_Pointer_Client_Header_Builder(const Multi_Thread_Pointer_Client_Header_Builder & orig){

};

Multi_Thread_Pointer_Client_Header_Builder::~Multi_Thread_Pointer_Client_Header_Builder(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void Multi_Thread_Pointer_Client_Header_Builder::Clear_Dynamic_Memory(){

  if(!this->Memory_Delete_Condition){

      this->Memory_Delete_Condition = true;

      this->Clear_Pointer_Memory(&this->InclusionWord);

      this->Clear_Pointer_Memory(&this->Client_Class_Name);

      this->Clear_Pointer_Memory(&this->Client_Class_Header_File_Name);

      this->FileManager.Clear_Dynamic_Memory();

      this->DirectoryManager.Clear_Dynamic_Memory();
  }
}

void Multi_Thread_Pointer_Client_Header_Builder::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void Multi_Thread_Pointer_Client_Header_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->Construction_Point = this->Reader_Pointer->Get_Constructed_Include_Directory();

     this->name_space_info = this->Reader_Pointer->Get_Namespace();
}

void Multi_Thread_Pointer_Client_Header_Builder::Receive_Data_Type(char * DataType){

     this->Data_Type = DataType;
}

void Multi_Thread_Pointer_Client_Header_Builder::Receive_Base_Class_Header_File_Name(char * Base_Class_Hader_File_Name){

     this->Base_Class_Header_File_Name = Base_Class_Hader_File_Name;
}

void Multi_Thread_Pointer_Client_Header_Builder::Receive_Base_Class_Name(char * Base_Class_Name){

     this->Base_Class_Name = Base_Class_Name;
}

void Multi_Thread_Pointer_Client_Header_Builder::Build_Header_File(){

     this->Determine_Client_Header_File_Name();

     this->Determine_Inclusion_Word();

     this->DirectoryManager.DetermineCurrentDirectory();

     this->DirectoryManager.ChangeDirectory(this->Construction_Point);

     this->Write_Header_File();
}

char Multi_Thread_Pointer_Client_Header_Builder::ConvertToUpper(char character){

     this->character = toupper(character);

     return this->character;
}

void Multi_Thread_Pointer_Client_Header_Builder::Determine_Client_Header_File_Name(){

     char Client_Add_Word [] = {'_','C','l','i','e','n','t','\0'};

     char Header_Add_Word [] = {'.','h','\0'};

     size_t Pointer_Name_Size = strlen(this->Base_Class_Name);

     size_t Client_Add_Word_Size = strlen(Client_Add_Word);

     size_t Client_Class_Name_Size = Pointer_Name_Size + Client_Add_Word_Size;

     this->Client_Class_Name = new char [10*Client_Class_Name_Size];

     int index_counter = 0;

     for(size_t i=0;i<Pointer_Name_Size;i++){

         this->Client_Class_Name[index_counter] = this->Base_Class_Name[i];

         index_counter++;
     }

     for(size_t i=0;i<Client_Add_Word_Size;i++){

         this->Client_Class_Name[index_counter] = Client_Add_Word[i];

         index_counter++;
     }

     this->Client_Class_Name[index_counter] = '\0';

     Client_Class_Name_Size = strlen(this->Client_Class_Name);

     this->Client_Class_Header_File_Name = new char [10*Client_Class_Name_Size];

     index_counter = 0;

     for(size_t i=0;i<Client_Class_Name_Size;i++){

         this->Client_Class_Header_File_Name[index_counter] = this->Client_Class_Name[i];

         index_counter++;
     }

     size_t Header_Add_Word_Size = strlen(Header_Add_Word);

     for(size_t i=0;i<Header_Add_Word_Size;i++){

         this->Client_Class_Header_File_Name[index_counter] = Header_Add_Word[i];

         index_counter++;
     }

     this->Client_Class_Header_File_Name[index_counter] = '\0';
}

void Multi_Thread_Pointer_Client_Header_Builder::Determine_Inclusion_Word(){

     size_t WordSize = strlen(this->Client_Class_Name);

     this->InclusionWord = new char [10*WordSize];

     for(size_t i=0;i<WordSize;i++){

        this->InclusionWord[i] = this->ConvertToUpper(this->Client_Class_Name[i]);
     }

     this->InclusionWord[WordSize]='_';

     this->InclusionWord[WordSize+1]= 'H';

     this->InclusionWord[WordSize+2]= '\0';
}

void Multi_Thread_Pointer_Client_Header_Builder::Write_Header_File(){

     this->FileManager.SetFilePath(this->Client_Class_Header_File_Name);

     this->FileManager.FileOpen(RWCf);

     this->FileManager.WriteToFile("\n#ifndef ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n#define ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("\n#include \"itds.h\"");

     this->FileManager.WriteToFile("\n#include <cstdlib>");

     this->FileManager.WriteToFile("\n#include \"");

     this->FileManager.WriteToFile(this->Base_Class_Header_File_Name);

     this->FileManager.WriteToFile("\"");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" namespace ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("{");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("  class ");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("\n  {");

     this->FileManager.WriteToFile("\n  public:");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("(thds * arg);");

     this->FileManager.WriteToFile("\n   virtual ~");

     this->FileManager.WriteToFile(this->Client_Class_Name);

     this->FileManager.WriteToFile("();");

     this->FileManager.WriteToFile("\n   void New(int MemorySize);");

     this->FileManager.WriteToFile("\n   void New();");

     this->FileManager.WriteToFile("\n   void Delete();");

     this->FileManager.WriteToFile("\n   void Set_Report_File_Path(const char * FileName);");

     this->FileManager.WriteToFile("\n   void Set_Report_File_Path(char * FileName);");

     this->FileManager.WriteToFile("\n   void Jump_To_Start();");

     this->FileManager.WriteToFile("\n   void Jump_To_End();");

     this->FileManager.WriteToFile("\n   void Connect(thds * thread_data);");

     this->FileManager.WriteToFile("\n   void Disconnect();");

     this->FileManager.WriteToFile("\n   void Set_User_Thread_Number(int Number);");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" & operator * ( );");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" & operator [] (const int & indexNumber);");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" & operator--(int arg);");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" & operator++(int arg);");

     this->FileManager.WriteToFile("\n  private:");

     this->FileManager.WriteToFile("\n   void ReceiveIndexBound();");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Base_Class_Name);

     this->FileManager.WriteToFile(" * Connection_Pointer;");

     this->FileManager.WriteToFile("\n   bool Connect_Condition;");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" * ControlPointer;");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Data_Type);

     this->FileManager.WriteToFile(" * MemoryStartPoint;");

     this->FileManager.WriteToFile("\n   int IndexBound;");

     this->FileManager.WriteToFile("\n   int ReportCounter;");

     this->FileManager.WriteToFile("\n   int adress_counter;");

     this->FileManager.WriteToFile("\n   char * ReportFileName;");

     this->FileManager.WriteToFile("\n   bool ReportFileSetCondition;");

     this->FileManager.WriteToFile("\n   bool MemorySetCondition;");

     this->FileManager.WriteToFile("\n   bool MemoryAreaSetCondition;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n};");

     this->FileManager.WriteToFile("\n\n#endif /* ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile(" */");

     this->FileManager.FileClose();
}

char * Multi_Thread_Pointer_Client_Header_Builder::Get_Client_Class_Name(){

      return this->Client_Class_Name;
}


char * Multi_Thread_Pointer_Client_Header_Builder::Get_Client_Class_Header_File_Name(){

       return this->Client_Class_Header_File_Name;
}
