
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

#include "Multi_Thread_Pointer_Header_Builder.h"

Multi_Thread_Pointer_Header_Builder::Multi_Thread_Pointer_Header_Builder(){

       this->Data_Type_Include_File_Name_Receive_Condition = false;

       this->InclusionWord = nullptr;
};

Multi_Thread_Pointer_Header_Builder::Multi_Thread_Pointer_Header_Builder(const Multi_Thread_Pointer_Header_Builder & orig){

};

Multi_Thread_Pointer_Header_Builder::~Multi_Thread_Pointer_Header_Builder(){

};

void Multi_Thread_Pointer_Header_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;
}

void Multi_Thread_Pointer_Header_Builder::Receive_Data_Type(const char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->Manager_Initializer.Receive_Data_Type(DataType);

     this->ReportFileBuilder_Initializer.Receive_Data_Type(DataType);
}

void Multi_Thread_Pointer_Header_Builder::Receive_Data_Type(char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->Manager_Initializer.Receive_Data_Type(DataType);

     this->ReportFileBuilder_Initializer.Receive_Data_Type(DataType);
}

void Multi_Thread_Pointer_Header_Builder::Receive_Entered_Class_Name(const char * Entered_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->Manager_Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->ReportFileBuilder_Initializer.Receive_Entered_Class_Name(Entered_Class_Name);
}

void Multi_Thread_Pointer_Header_Builder::Receive_Entered_Class_Name(char * Entered_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->Manager_Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->ReportFileBuilder_Initializer.Receive_Entered_Class_Name(Entered_Class_Name);
}

void Multi_Thread_Pointer_Header_Builder::Receive_Construction_Point(const char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->Manager_Initializer.Receive_Construction_Point(Construction_Point);

     this->ReportFileBuilder_Initializer.Receive_Construction_Point(Construction_Point);
}

void Multi_Thread_Pointer_Header_Builder::Receive_Construction_Point(char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->Manager_Initializer.Receive_Construction_Point(Construction_Point);

     this->ReportFileBuilder_Initializer.Receive_Construction_Point(Construction_Point);
}

void Multi_Thread_Pointer_Header_Builder::Receive_Data_Type_Include_File_Name(const char * Include_File_Name){

     if(Include_File_Name != nullptr){

         this->Data_Type_Include_File_Name_Receive_Condition = true;

         this->Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

         this->Manager_Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);
     }
}

void Multi_Thread_Pointer_Header_Builder::Receive_Data_Type_Include_File_Name(char * Include_File_Name){

     if(Include_File_Name != nullptr){

        this->Data_Type_Include_File_Name_Receive_Condition = true;

        this->Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

        this->Manager_Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);
     }
}

void Multi_Thread_Pointer_Header_Builder::Set_New_Class_Name_Directly(const char * Class_Name){

    this->Initializer.Set_New_Class_Name_Directly(Class_Name);

    this->Manager_Initializer.Receive_Entered_Class_Name(Class_Name);

    this->ReportFileBuilder_Initializer.Receive_Entered_Class_Name(Class_Name);
}

void Multi_Thread_Pointer_Header_Builder::Set_New_Class_Name_Directly(char * Class_Name){

    this->Initializer.Set_New_Class_Name_Directly(Class_Name);

    this->Manager_Initializer.Receive_Entered_Class_Name(Class_Name);

    this->ReportFileBuilder_Initializer.Receive_Entered_Class_Name(Class_Name);
}

void Multi_Thread_Pointer_Header_Builder::Build_Header_File(){

     this->Initializer.Receive_Generic_Class_Name("SmartPointer");

     this->Manager_Initializer.Receive_Generic_Class_Name("MemoryManager");

     this->ReportFileBuilder_Initializer.Receive_Generic_Class_Name("ReportFileBuilder");

     this->Initializer.Collect_Informations();

     this->Manager_Initializer.Collect_Informations();

     this->ReportFileBuilder_Initializer.Collect_Informations();

     this->Determine_Inclusion_Word();

     this->DirectoryManager.ChangeDirectory(this->Initializer.Get_Construction_Point());

     this->Write_Header_File();

     this->Manager_Initializer.Clear_Dynamic_Memory();

     this->ReportFileBuilder_Initializer.Clear_Dynamic_Memory();

     this->Initializer.Clear_Dynamic_Memory();

     if(this->InclusionWord != nullptr){

        delete [] this->InclusionWord;
     }
}

char Multi_Thread_Pointer_Header_Builder::ConvertToUpper(char character){

     this->character = toupper(character);

     return this->character;
}

void Multi_Thread_Pointer_Header_Builder::Determine_Inclusion_Word(){

     int WordSize = strlen(this->Initializer.Get_NewClassName());

     this->InclusionWord = new char [10*WordSize];

     for(int i=0;i<WordSize;i++){

        this->InclusionWord[i] = this->ConvertToUpper(this->Initializer.Get_NewClassName()[i]);
     }

     this->InclusionWord[WordSize]='_';

     this->InclusionWord[WordSize+1]= 'H';

     this->InclusionWord[WordSize+2]= '\0';
}

void Multi_Thread_Pointer_Header_Builder::Write_Header_File(){

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

     this->FileManager.WriteToFile(this->Manager_Initializer.Get_NewHeaderFileName());

     this->FileManager.WriteToFile("\"");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("#include \"");

     this->FileManager.WriteToFile(this->ReportFileBuilder_Initializer.Get_NewHeaderFileName());

     this->FileManager.WriteToFile("\"");

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" namespace ");

     this->FileManager.WriteToFile(name_space);

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

     this->FileManager.WriteToFile("\n   void New(int MemorySize);");

     this->FileManager.WriteToFile("\n   void New();");

     this->FileManager.WriteToFile("\n   void Delete();");

     this->FileManager.WriteToFile("\n   void Set_Report_File_Path(const char * FileName);");

     this->FileManager.WriteToFile("\n   void Set_Report_File_Path(char * FileName);");

     this->FileManager.WriteToFile("\n   void Jump_To_Start();");

     this->FileManager.WriteToFile("\n   void Jump_To_End();");

     this->FileManager.WriteToFile("\n   void Disconnect();");

     this->FileManager.WriteToFile("\n   void Set_User_Thread_Number(int Number);");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" & operator * ( );");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" & operator [] (const int & indexNumber);");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" & operator--(int arg);");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" & operator++(int arg);");

     this->FileManager.WriteToFile("\n  private:");

     this->FileManager.WriteToFile("\n   void ReceiveIndexBound();");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Manager_Initializer.Get_NewClassName());

     this->FileManager.WriteToFile(" SmartMemory;");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->ReportFileBuilder_Initializer.Get_NewClassName());

     this->FileManager.WriteToFile(" Reporter;");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" * ControlPointer;");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" * MemoryStartPoint;");

     this->FileManager.WriteToFile("\n   int IndexBound;");

     this->FileManager.WriteToFile("\n   int ReportCounter;");

     this->FileManager.WriteToFile("\n   int adress_counter;");

     this->FileManager.WriteToFile("\n   char * ReportFileName;");

     this->FileManager.WriteToFile("\n   bool ReportFileSetCondition;");

     this->FileManager.WriteToFile("\n   bool MemorySetCondition;");

     this->FileManager.WriteToFile("\n   bool MemoryAreaSetCondition;");

     this->FileManager.WriteToFile("\n  };");

     this->FileManager.WriteToFile("\n};");

     this->FileManager.WriteToFile("\n\n#endif /* ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile(" */");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Header_Builder::Set_Data_Type_Include_File_Name_Receive_Condition(bool Condition){

     this->Data_Type_Include_File_Name_Receive_Condition = Condition;
}
