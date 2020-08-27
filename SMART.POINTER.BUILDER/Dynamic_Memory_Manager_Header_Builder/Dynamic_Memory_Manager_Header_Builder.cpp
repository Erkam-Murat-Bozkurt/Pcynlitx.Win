
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

#include "Dynamic_Memory_Manager_Header_Builder.h"

Dynamic_Memory_Manager_Header_Builder::Dynamic_Memory_Manager_Header_Builder(){

     this->Data_Type_Include_File_Name_Receive_Condition = false;

     this->InclusionWord = nullptr;

     this->name_space_info = nullptr;
};

Dynamic_Memory_Manager_Header_Builder::Dynamic_Memory_Manager_Header_Builder(const Dynamic_Memory_Manager_Header_Builder & orig){

};

Dynamic_Memory_Manager_Header_Builder::~Dynamic_Memory_Manager_Header_Builder(){

};

void Dynamic_Memory_Manager_Header_Builder::Receive_Data_Type(const char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->ReportFileBuilder_Initializer.Receive_Data_Type(DataType);
}

void Dynamic_Memory_Manager_Header_Builder::Receive_Data_Type(char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->ReportFileBuilder_Initializer.Receive_Data_Type(DataType);
}

void Dynamic_Memory_Manager_Header_Builder::Receive_Entered_Class_Name(const char * Entered_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->ReportFileBuilder_Initializer.Receive_Entered_Class_Name(Entered_Class_Name);
}


void Dynamic_Memory_Manager_Header_Builder::Receive_Entered_Class_Name(char * Entered_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->ReportFileBuilder_Initializer.Receive_Entered_Class_Name(Entered_Class_Name);
}

void Dynamic_Memory_Manager_Header_Builder::Receive_Construction_Point(const char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->ReportFileBuilder_Initializer.Receive_Construction_Point(Construction_Point);
}

void Dynamic_Memory_Manager_Header_Builder::Receive_Construction_Point(char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->ReportFileBuilder_Initializer.Receive_Construction_Point(Construction_Point);
}

void Dynamic_Memory_Manager_Header_Builder::Receive_Data_Type_Include_File_Name(const char * Include_File_Name){

     this->Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

     this->Data_Type_Include_File_Name_Receive_Condition = true;
}

void Dynamic_Memory_Manager_Header_Builder::Receive_Data_Type_Include_File_Name(char * Include_File_Name){

     this->Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

     this->Data_Type_Include_File_Name_Receive_Condition = true;
}

void Dynamic_Memory_Manager_Header_Builder::Set_Data_Type_Include_File_Name_Receive_Condition(bool Condition){

     this->Data_Type_Include_File_Name_Receive_Condition = Condition;
}

void Dynamic_Memory_Manager_Header_Builder::Receive_Namespace(char * name_space_info){

     this->name_space_info = name_space_info;
}

void Dynamic_Memory_Manager_Header_Builder::Build_Header_File(){

     this->Initializer.Receive_Generic_Class_Name("MemoryManager");

     this->ReportFileBuilder_Initializer.Receive_Generic_Class_Name("ReportFileBuilder");

     this->Initializer.Collect_Informations();

     this->ReportFileBuilder_Initializer.Collect_Informations();

     this->Determine_Inclusion_Word();

     this->DirectoryManager.ChangeDirectory(this->Initializer.Get_Construction_Point());

     this->Write_Header_File();

     this->Initializer.Clear_Dynamic_Memory();

     this->ReportFileBuilder_Initializer.Clear_Dynamic_Memory();

     if(this->InclusionWord != nullptr){

        delete [] this->InclusionWord;
     }
}

char Dynamic_Memory_Manager_Header_Builder::ConvertToUpper(char character){

     this->character = toupper(character);

     return this->character;
}

void Dynamic_Memory_Manager_Header_Builder::Determine_Inclusion_Word(){

     int WordSize = strlen(this->Initializer.Get_NewClassName());

     this->InclusionWord = new char [10*WordSize];

     for(int i=0;i<WordSize;i++){

        this->InclusionWord[i] = this->ConvertToUpper(this->Initializer.Get_NewClassName()[i]);
     }

     this->InclusionWord[WordSize]='_';

     this->InclusionWord[WordSize+1]= 'H';

     this->InclusionWord[WordSize+2]= '\0';
}

void Dynamic_Memory_Manager_Header_Builder::Write_Header_File(){

     this->FileManager.SetFilePath(this->Initializer.Get_NewHeaderFileName());

     this->FileManager.FileOpen(RWC);

     this->FileManager.FileClose();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n#ifndef ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n#define ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n\n");

     if(this->Data_Type_Include_File_Name_Receive_Condition){

        this->FileManager.WriteToFile("#include \"");

        this->FileManager.WriteToFile(this->Initializer.Get_DataType_IncludeFileName());

        this->FileManager.WriteToFile("\"");

        this->FileManager.WriteToFile("\n");
     }

     this->FileManager.WriteToFile("#include \"");

     this->FileManager.WriteToFile(this->ReportFileBuilder_Initializer.Get_NewHeaderFileName());

     this->FileManager.WriteToFile("\"");

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile("namespace ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("{");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("  class ");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("\n  {");

     this->FileManager.WriteToFile("\n  public:");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_Class_Constructor_Name());

     this->FileManager.WriteToFile("();");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_Class_Constructor_Name());

     this->FileManager.WriteToFile("(const ");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile(" & orig);");

     this->FileManager.WriteToFile("\n   virtual ~");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("();");

     this->FileManager.WriteToFile("\n   void NewMemory(");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" ** TypePointer, int MemorySize);");

     this->FileManager.WriteToFile("\n   void NewMemory(");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" ** TypePointer);");

     this->FileManager.WriteToFile("\n   void DeleteMemory();");

     this->FileManager.WriteToFile("\n   void ReceiveReportFileManager(");

     this->FileManager.WriteToFile(this->ReportFileBuilder_Initializer.Get_NewClassName());

     this->FileManager.WriteToFile(" * ReportManager);");

     this->FileManager.WriteToFile("\n   int  GetMemorySize();");

     this->FileManager.WriteToFile("\n   void Exit();");

     this->FileManager.WriteToFile("\n   void Set_User_Thread_Number(int Number);");

     this->FileManager.WriteToFile("\n   bool Control_Memory_Usage();");

     this->FileManager.WriteToFile("\n   void MemoryCanNotDelete();");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" * GetMemoryAdress();");

     this->FileManager.WriteToFile("\n  private:");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->ReportFileBuilder_Initializer.Get_NewClassName());

     this->FileManager.WriteToFile(" * Reporter;");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" * MemoryCellPointer;");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" * MemoryAreaPointer;");

     this->FileManager.WriteToFile("\n   bool MemoryAreaSetCondition;");

     this->FileManager.WriteToFile("\n   bool MemoryCellSetCondition;");

     this->FileManager.WriteToFile("\n   bool MemoryAreaDeleteCondition;");

     this->FileManager.WriteToFile("\n   bool MemoryCellDeleteCondition;");

     this->FileManager.WriteToFile("\n   bool ReportFileSetCondition;");

     this->FileManager.WriteToFile("\n   int  MemorySize;");

     this->FileManager.WriteToFile("\n   int  Not_User_Thread_Number;");

     this->FileManager.WriteToFile("\n   int  Memory_User_Thread_Number;");

     this->FileManager.WriteToFile("\n   int  User_Thread_Number;");

     this->FileManager.WriteToFile("\n   bool Memory_Usage;");

     this->FileManager.WriteToFile("\n   char * ReportFileName;");

     this->FileManager.WriteToFile("\n  };");

     this->FileManager.WriteToFile("\n};");

     this->FileManager.WriteToFile("\n\n#endif /* ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile(" */");

     this->FileManager.FileClose();
}
