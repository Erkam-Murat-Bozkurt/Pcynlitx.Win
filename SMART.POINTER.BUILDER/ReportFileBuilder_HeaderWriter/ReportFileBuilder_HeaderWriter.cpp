
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

#include "ReportFileBuilder_HeaderWriter.h"

ReportFileBuilder_HeaderWriter::ReportFileBuilder_HeaderWriter(){

     this->InclusionWord = nullptr;

     this->name_space_info = nullptr;
};

ReportFileBuilder_HeaderWriter::ReportFileBuilder_HeaderWriter(const ReportFileBuilder_HeaderWriter & orig){

};

ReportFileBuilder_HeaderWriter::~ReportFileBuilder_HeaderWriter(){

};

void ReportFileBuilder_HeaderWriter::Receive_Data_Type(const char * DataType){

     this->Initializer.Receive_Data_Type(DataType);
}

void ReportFileBuilder_HeaderWriter::Receive_Data_Type(char * DataType){

    this->Initializer.Receive_Data_Type(DataType);
}

void ReportFileBuilder_HeaderWriter::Receive_Namespace(char * name_space_info){

    this->name_space_info = name_space_info;
}

void ReportFileBuilder_HeaderWriter::Receive_Entered_Class_Name(const char * New_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(New_Class_Name);
}

void ReportFileBuilder_HeaderWriter::Receive_Entered_Class_Name(char * New_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(New_Class_Name);
}

void ReportFileBuilder_HeaderWriter::Receive_Construction_Point(const char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);
}

void ReportFileBuilder_HeaderWriter::Receive_Construction_Point(char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);
}

void ReportFileBuilder_HeaderWriter::Build_Header_File(){

     this->Initializer.Receive_Generic_Class_Name("ReportFileBuilder");

     this->Initializer.Collect_Informations();

     this->Determine_Inclusion_Word();

     this->DirectoryManager.ChangeDirectory(this->Initializer.Get_Construction_Point());

     this->Write_Header_File();

     this->Initializer.Clear_Dynamic_Memory();

     if(this->InclusionWord != nullptr){

        delete [] this->InclusionWord;
     }
}

char ReportFileBuilder_HeaderWriter::ConvertToUpper(char character){

     this->character = toupper(character);

     return this->character;
}

void ReportFileBuilder_HeaderWriter::Determine_Inclusion_Word(){

     size_t WordSize = strlen(this->Initializer.Get_NewClassName());

     this->InclusionWord = new char [10*WordSize];

     for(size_t i=0;i<WordSize;i++){

        this->InclusionWord[i] = this->ConvertToUpper(this->Initializer.Get_NewClassName()[i]);
     }

     this->InclusionWord[WordSize]='_';

     this->InclusionWord[WordSize+1]= 'H';

     this->InclusionWord[WordSize+2]= '\0';
}

void ReportFileBuilder_HeaderWriter::Write_Header_File(){

     this->FileManager.SetFilePath(this->Initializer.Get_NewHeaderFileName());

     this->FileManager.FileOpen(RWCf);

     this->FileManager.FileClose();

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n#ifndef ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n#define ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n#include <fstream>");

     this->FileManager.WriteToFile("\n#include <string>");

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

     this->FileManager.WriteToFile("\n   void SetReportFileName(std::string FileName);");

     this->FileManager.WriteToFile("\n   void MemoryCanNotDelete();");

     this->FileManager.WriteToFile("\n   void MemoryAllocationError();");

     this->FileManager.WriteToFile("\n   void IndexOutOfBoundError();");

     this->FileManager.WriteToFile("\n   void AdressSearchError();");

     this->FileManager.WriteToFile("\n   void PointerAdressChangeError();");

     this->FileManager.WriteToFile("\n   void SetFilePath(std::string FilePATH);");

     this->FileManager.WriteToFile("\n   void FileConstruct();");

     this->FileManager.WriteToFile("\n   void FileOpen();");

     this->FileManager.WriteToFile("\n   void FileClose();");

     this->FileManager.WriteToFile("\n   void WriteToFile(std::string list);");

     this->FileManager.WriteToFile("\n  private:");

     this->FileManager.WriteToFile("\n   void WriteReportEnd();");

     this->FileManager.WriteToFile("\n   std::fstream DataFile;");

     this->FileManager.WriteToFile("\n   std::string FilePath;");

     this->FileManager.WriteToFile("\n   std::string ReportFileName;");

     this->FileManager.WriteToFile("\n   int  ReportCounter;");

     this->FileManager.WriteToFile("\n   bool ReportFileSetCondition;");

     this->FileManager.WriteToFile("\n   bool MemoryCanNotDeleteReport;");

     this->FileManager.WriteToFile("\n   bool IndexOutOfBoundErrorReport;");

     this->FileManager.WriteToFile("\n   bool AdressSearchErrorReport;");

     this->FileManager.WriteToFile("\n   bool MemoryAllocationErrorReport;");

     this->FileManager.WriteToFile("\n   bool PointerAdressChangeErrorReport;");

     this->FileManager.WriteToFile("\n  };");

     this->FileManager.WriteToFile("\n};");

     this->FileManager.WriteToFile("\n\n#endif /* ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile(" */");

     this->FileManager.FileClose();
  }
