
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

#include "ReportFileBuilder_Writer.h"

ReportFileBuilder_Writer::ReportFileBuilder_Writer(){

     this->name_space_info = nullptr;
};

ReportFileBuilder_Writer::ReportFileBuilder_Writer(const ReportFileBuilder_Writer & orig){

};

ReportFileBuilder_Writer::~ReportFileBuilder_Writer(){

};

void ReportFileBuilder_Writer::Receive_Namespace(char * name_space_info){

     this->name_space_info = name_space_info;

     this->Header_Writer.Receive_Namespace(name_space_info);
}

void ReportFileBuilder_Writer::Receive_Data_Type(const char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->Header_Writer.Receive_Data_Type(DataType);
}

void ReportFileBuilder_Writer::Receive_Data_Type(char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->Header_Writer.Receive_Data_Type(DataType);
}

void ReportFileBuilder_Writer::Receive_Entered_Class_Name(const char * Entered_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->Header_Writer.Receive_Entered_Class_Name(Entered_Class_Name);
}

void ReportFileBuilder_Writer::Receive_Entered_Class_Name(char * Entered_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->Header_Writer.Receive_Entered_Class_Name(Entered_Class_Name);
}

void ReportFileBuilder_Writer::Receive_Construction_Point(const char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->Header_Writer.Receive_Construction_Point(Construction_Point);
}

void ReportFileBuilder_Writer::Receive_Construction_Point(char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->Header_Writer.Receive_Construction_Point(Construction_Point);
}

void ReportFileBuilder_Writer::Write_ReportFileBuilder(){

     this->Initializer.Receive_Generic_Class_Name("ReportFileBuilder");

     this->Initializer.Collect_Informations();

     this->DirectoryManager.ChangeDirectory(this->Initializer.Get_Construction_Point());

     this->Header_Writer.Build_Header_File();

     this->Build_Class_Implementation_File();

     this->Initializer.Clear_Dynamic_Memory();
}


void ReportFileBuilder_Writer::Build_Class_Implementation_File(){

     this->Start_Implementation_File_Construction();

     this->Build_Constructors();

     this->Build_Destructor();

     this->Build_SetFilePath_Member_Function();

     this->Build_File_Operations_Member_Functions();

     this->Build_SetReportFileName_Member_Function();

     this->Build_WriteReportEnd_Member_Function();

     this->Build_MemoryAllocationError_Member_Function();

     this->Build_MemoryCanNotDelete_Member_Function();

     this->Build_IndexOutOfBoundError_Member_Function();

     this->Build_AdressSearchError_Member_Function();

     this->Build_PointerAdressChangeError_Member_Function();
}

void ReportFileBuilder_Writer::Start_Implementation_File_Construction(){

     this->FileManager.SetFilePath(this->Initializer.Get_ClassImplementationFileName());

     this->FileManager.FileOpen(RWCf);

     this->FileManager.WriteToFile("\n #include \"");

     this->FileManager.WriteToFile(this->Initializer.Get_NewHeaderFileName());

     this->FileManager.WriteToFile("\"");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_Constructors(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->ReportFileSetCondition = false;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->MemoryAllocationErrorReport = false;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->IndexOutOfBoundErrorReport = false;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->AdressSearchErrorReport = false;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->MemoryCanNotDeleteReport =false;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->PointerAdressChangeErrorReport = false;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("(const ");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile(" & orig){");

     this->FileManager.WriteToFile("\n\n };");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_Destructor(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::~");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->ReportFileSetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteReportEnd();");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("};");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_SetFilePath_Member_Function(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::SetFilePath(std::string FilePATH){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("int Name_Size = FilePATH.length();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("for(int i=0;i<Name_Size;i++){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->FilePath.append(1,FilePATH[i]) ;");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("}");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->FilePath.append(1,\'\\0\');");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_File_Operations_Member_Functions(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::FileConstruct(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->DataFile.open(this->FilePath,std::ios::out | std::ios::trunc);");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::FileOpen(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->DataFile.open(this->FilePath,std::ios::out | std::ios::app);");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::WriteToFile(std::string list){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->DataFile <<  list;");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::FileClose(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->DataFile.close();");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_SetReportFileName_Member_Function(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::SetReportFileName(std::string FileName){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->SetFilePath(FileName);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->FileConstruct();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->WriteToFile(\"\\n\\n MEMORY MANAGER OPERATION REPORTS:\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->FileClose();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->ReportCounter = 1;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->ReportFileSetCondition = true;");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_WriteReportEnd_Member_Function(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::WriteReportEnd(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->ReportFileSetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileOpen();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   if(this->ReportCounter == 1){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("      this->WriteToFile(\"\\n\\n There is no report \");");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("   }");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n END ( The end of report file ) \\n\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileClose();");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_MemoryAllocationError_Member_Function(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::MemoryAllocationError(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->ReportFileSetCondition && !this->MemoryAllocationErrorReport){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileOpen();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n \");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   std::string list = std::to_string(this->ReportCounter);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(list);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\") MEMORY ALLOCATION REPORT\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n        REPORT: Pointer attemps to allocate new memory before delete memory\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n                Please check NewMemory() and DeleteMemory() functions..\\n\\n\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileClose();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->ReportCounter++;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->MemoryAllocationErrorReport = true;");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_MemoryCanNotDelete_Member_Function(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::MemoryCanNotDelete(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->ReportFileSetCondition && !this->MemoryCanNotDeleteReport){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileOpen();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n \");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   std::string list = std::to_string(this->ReportCounter);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(list);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\") FUNCTION EXECUTION REPORT\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n        Function Name  : DeleteMemory()\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n        Function Report: The memory area is used by a pointer!..\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n                         The memory area can not be deleted ..\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileClose();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->ReportCounter++;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->MemoryCanNotDeleteReport = true;");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_IndexOutOfBoundError_Member_Function(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::IndexOutOfBoundError(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->ReportFileSetCondition && !this->IndexOutOfBoundErrorReport){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileOpen();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n \");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   std::string list = std::to_string(this->ReportCounter);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(list);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\") INDEX OUT OF BOUND REPORT\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n        REPORT: Pointer attemps to read data from the out of memory bound \");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n                Pointer index is out of bound..\\n\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileClose();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->ReportCounter++;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->IndexOutOfBoundErrorReport = true;");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_AdressSearchError_Member_Function(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::AdressSearchError(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->ReportFileSetCondition && !this->AdressSearchErrorReport){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileOpen();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n \");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   std::string list = std::to_string(this->ReportCounter);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(list);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\") UNEXPECTED BEHAVIOUR IN SMART POINTER\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n        REPORT: Posible cases, (adress_counter > IndexBound \");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n                   (adress_counter < 0)\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileClose();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->ReportCounter++;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->AdressSearchErrorReport = true;");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Build_PointerAdressChangeError_Member_Function(){

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::PointerAdressChangeError(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->ReportFileSetCondition && !this->PointerAdressChangeErrorReport){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->FileOpen();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n \");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   std::string list = std::to_string(this->ReportCounter);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(list);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\") POINTER ADRES CAN NOT BE CHANGED\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n\\n        REPORT: Posible cases, The algorithm tries to increase or decrease \");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n        pointer adress to the out of the allocated memory locations\");");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->WriteToFile(\"\\n        please check ++ and -- operations for pointer\");");

     this->FileManager.WriteToFile("   this->ReportCounter++;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->PointerAdressChangeErrorReport = true;");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void ReportFileBuilder_Writer::Write_Space(const char * String, size_t Line_Number){

     size_t String_Size = strlen(String);

     for(size_t i=0;i<Line_Number;i++){

         this->FileManager.WriteToFile("\n");
     }

     for(size_t i=0;i<String_Size+2;i++){

         this->FileManager.WriteToFile(" ");
     }
}
