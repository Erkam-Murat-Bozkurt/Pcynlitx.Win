
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

#include "Dynamic_Memory_Manager_Builder.h"

Dynamic_Memory_Manager_Builder::Dynamic_Memory_Manager_Builder(){

    this->name_space_info = nullptr;
};

Dynamic_Memory_Manager_Builder::Dynamic_Memory_Manager_Builder(const Dynamic_Memory_Manager_Builder & orig){

};

Dynamic_Memory_Manager_Builder::~Dynamic_Memory_Manager_Builder(){

};

void Dynamic_Memory_Manager_Builder::Receive_Data_Type(const char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->ReportFileBuilder_Initializer.Receive_Data_Type(DataType);

     this->Header_Builder.Receive_Data_Type(DataType);

     this->Report_File_Builder_Writer.Receive_Data_Type(DataType);
}

void Dynamic_Memory_Manager_Builder::Receive_Data_Type(char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->ReportFileBuilder_Initializer.Receive_Data_Type(DataType);

     this->Header_Builder.Receive_Data_Type(DataType);

     this->Report_File_Builder_Writer.Receive_Data_Type(DataType);
}

void Dynamic_Memory_Manager_Builder::Receive_Entered_Class_Name(const char * Entered_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->ReportFileBuilder_Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->Header_Builder.Receive_Entered_Class_Name(Entered_Class_Name);

     this->Report_File_Builder_Writer.Receive_Entered_Class_Name(Entered_Class_Name);
}

void Dynamic_Memory_Manager_Builder::Receive_Entered_Class_Name(char * Entered_Class_Name){

     this->Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->ReportFileBuilder_Initializer.Receive_Entered_Class_Name(Entered_Class_Name);

     this->Header_Builder.Receive_Entered_Class_Name(Entered_Class_Name);

     this->Report_File_Builder_Writer.Receive_Entered_Class_Name(Entered_Class_Name);
}

void Dynamic_Memory_Manager_Builder::Receive_Construction_Point(const char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->ReportFileBuilder_Initializer.Receive_Construction_Point(Construction_Point);

     this->Header_Builder.Receive_Construction_Point(Construction_Point);

     this->Report_File_Builder_Writer.Receive_Construction_Point(Construction_Point);
}

void Dynamic_Memory_Manager_Builder::Receive_Construction_Point(char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->ReportFileBuilder_Initializer.Receive_Construction_Point(Construction_Point);

     this->Header_Builder.Receive_Construction_Point(Construction_Point);

     this->Report_File_Builder_Writer.Receive_Construction_Point(Construction_Point);
}

void Dynamic_Memory_Manager_Builder::Receive_Data_Type_Include_File_Name(const char * Include_File_Name){

     this->Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

     this->Header_Builder.Receive_Data_Type_Include_File_Name(Include_File_Name);
}

void Dynamic_Memory_Manager_Builder::Receive_Data_Type_Include_File_Name(char * Include_File_Name){

     this->Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

     this->Header_Builder.Receive_Data_Type_Include_File_Name(Include_File_Name);
}

void Dynamic_Memory_Manager_Builder::Set_Data_Type_Include_File_Name_Receive_Condition(bool Condition){

     this->Header_Builder.Set_Data_Type_Include_File_Name_Receive_Condition(Condition);
}

void Dynamic_Memory_Manager_Builder::Receive_Namespace(char * name_space_info){

     this->name_space_info = name_space_info;

     this->Header_Builder.Receive_Namespace(name_space_info);

     this->Report_File_Builder_Writer.Receive_Namespace(name_space_info);
}

void Dynamic_Memory_Manager_Builder::Build_Memory_Manager(){

     this->Initializer.Receive_Generic_Class_Name("MemoryManager");

     this->ReportFileBuilder_Initializer.Receive_Generic_Class_Name("ReportFileBuilder");

     this->Initializer.Collect_Informations();

     this->ReportFileBuilder_Initializer.Collect_Informations();

     this->DirectoryManager.ChangeDirectory(this->Initializer.Get_Construction_Point());

     this->Report_File_Builder_Writer.Write_ReportFileBuilder();

     this->Header_Builder.Build_Header_File();

     this->Build_Class_Implementation_File();

     this->Initializer.Clear_Dynamic_Memory();

     this->ReportFileBuilder_Initializer.Clear_Dynamic_Memory();
}

void Dynamic_Memory_Manager_Builder::Build_Class_Implementation_File(){

     this->FileManager.SetFilePath(this->Initializer.Get_ClassImplementationFileName());

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n #include \"");

     this->FileManager.WriteToFile(this->Initializer.Get_NewHeaderFileName());

     this->FileManager.WriteToFile("\"");

     this->FileManager.FileClose();

     this->Build_Constructors();

     this->Build_Destructor();

     this->Build_NewMemory_Member_Functions();

     this->Build_DeleteMemory_Member_Function();

     this->Build_GetMemoryAdress_Member_Function();

     this->Build_ReceiveReportFileManager_Member_Function();

     this->Build_GetMemorySize_Member_Function();

     this->Build_User_Number_Determiner_Member_Functions();
}

void Dynamic_Memory_Manager_Builder::Build_Constructors(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("(){");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryAreaSetCondition = false;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryAreaDeleteCondition = false;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryCellSetCondition = false;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryCellDeleteCondition = false;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->ReportFileSetCondition = false;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryCellPointer = nullptr;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryAreaPointer = nullptr;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemorySize = 0;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->Not_User_Thread_Number = 0;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->User_Thread_Number = 0;");

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

void Dynamic_Memory_Manager_Builder::Build_Destructor(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::~");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("(){");

     this->Write_Space();

     this->FileManager.WriteToFile("if(!this->MemoryCellDeleteCondition && this->MemoryCellSetCondition){");

     this->Write_Space();

     this->FileManager.WriteToFile("    delete this->MemoryCellPointer;");

     this->FileManager.WriteToFile("\n      };");

     this->Write_Space();

     this->FileManager.WriteToFile("if(!this->MemoryAreaDeleteCondition && this->MemoryAreaSetCondition){");

     this->Write_Space();

     this->FileManager.WriteToFile("    delete [] this->MemoryAreaPointer;");

     this->FileManager.WriteToFile("\n     };");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Dynamic_Memory_Manager_Builder::Build_NewMemory_Member_Functions(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::NewMemory(");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" ** TypePointer, int MemorySize){");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemorySize = MemorySize;");

     this->Write_Space();

     this->FileManager.WriteToFile("*TypePointer = new ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" [MemorySize];");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryAreaSetCondition = true;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryAreaDeleteCondition = false;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryAreaPointer = *TypePointer;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::NewMemory(");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" ** TypePointer){");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemorySize = 1;");

     this->Write_Space();

     this->FileManager.WriteToFile("*TypePointer = new ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(";");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryCellSetCondition = true;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryCellDeleteCondition = false;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->MemoryCellPointer = *TypePointer;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Dynamic_Memory_Manager_Builder::Build_DeleteMemory_Member_Function(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::DeleteMemory(){");

     this->Write_Space();

     this->FileManager.WriteToFile("if(!this->MemoryAreaDeleteCondition && this->MemoryAreaSetCondition){");

     this->Write_Space();

     this->FileManager.WriteToFile("   if(!this->Control_Memory_Usage()){");

     this->Write_Space();

     this->FileManager.WriteToFile("      delete [] this->MemoryAreaPointer;");

     this->Write_Space();

     this->FileManager.WriteToFile("      this->MemoryAreaDeleteCondition = true;");

     this->Write_Space();

     this->FileManager.WriteToFile("      this->MemoryAreaSetCondition = false;");

     this->FileManager.WriteToFile("\n         }");

     this->FileManager.WriteToFile("\n         else{");

     this->Write_Space();

     this->FileManager.WriteToFile("       if(this->ReportFileSetCondition){");

     this->Write_Space();

     this->FileManager.WriteToFile("          this->Reporter->MemoryCanNotDelete();");

     this->FileManager.WriteToFile("\n             }");

     this->FileManager.WriteToFile("\n         }");

     this->FileManager.WriteToFile("\n      }");

     this->Write_Space();

     this->FileManager.WriteToFile("if(!this->MemoryCellDeleteCondition && this->MemoryCellSetCondition){");

     this->Write_Space();

     this->FileManager.WriteToFile("   if(!this->Control_Memory_Usage()){");

     this->Write_Space();

     this->FileManager.WriteToFile("      delete this->MemoryCellPointer;");

     this->Write_Space();

     this->FileManager.WriteToFile("      this->MemoryCellDeleteCondition = true;");

     this->Write_Space();

     this->FileManager.WriteToFile("      this->MemoryCellSetCondition = false;");

     this->FileManager.WriteToFile("\n         }");

     this->FileManager.WriteToFile("\n         else{");

     this->Write_Space();

     this->FileManager.WriteToFile("     if(this->ReportFileSetCondition){");

     this->Write_Space();

     this->FileManager.WriteToFile("        this->Reporter->MemoryCanNotDelete();");

     this->FileManager.WriteToFile("\n           }");

     this->FileManager.WriteToFile("\n         }");

     this->FileManager.WriteToFile("\n      }");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::MemoryCanNotDelete(){");

     this->Write_Space();

     this->FileManager.WriteToFile(" this->Reporter->MemoryCanNotDelete();");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void Dynamic_Memory_Manager_Builder::Build_GetMemoryAdress_Member_Function(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" * ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::GetMemoryAdress(){");

     this->Write_Space();

     this->FileManager.WriteToFile(" if(((!this->MemoryAreaDeleteCondition) && (this->MemoryAreaSetCondition))){");

     this->Write_Space();

     this->FileManager.WriteToFile("      return this->MemoryAreaPointer;");

     this->FileManager.WriteToFile("\n       }");

     this->Write_Space();

     this->FileManager.WriteToFile(" if(((!this->MemoryCellDeleteCondition) && (this->MemoryCellSetCondition))){");

     this->Write_Space();

     this->FileManager.WriteToFile("      return this->MemoryCellPointer;");

     this->FileManager.WriteToFile("\n       };");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("      return this->MemoryCellPointer;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Dynamic_Memory_Manager_Builder::Build_ReceiveReportFileManager_Member_Function(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::ReceiveReportFileManager(");

     this->FileManager.WriteToFile(this->ReportFileBuilder_Initializer.Get_NewClassName());

    this->FileManager.WriteToFile(" * ReportFileManager){");

     this->Write_Space();

     this->FileManager.WriteToFile("this->Reporter = ReportFileManager;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->ReportFileSetCondition = true;");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void Dynamic_Memory_Manager_Builder::Build_GetMemorySize_Member_Function(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" int ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::GetMemorySize(){");

     this->Write_Space();

     this->FileManager.WriteToFile("return this->MemorySize;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Dynamic_Memory_Manager_Builder::Build_User_Number_Determiner_Member_Functions(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Exit(){");

     this->Write_Space();

     this->FileManager.WriteToFile("this->Not_User_Thread_Number++;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Set_User_Thread_Number(int Number){");

     this->Write_Space();

     this->FileManager.WriteToFile("this->User_Thread_Number = Number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" bool ");

     this->FileManager.WriteToFile(this->name_space_info);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Control_Memory_Usage(){");

     this->Write_Space();

     this->FileManager.WriteToFile("this->Memory_Usage = false;");

     this->Write_Space();

     this->FileManager.WriteToFile("this->Memory_User_Thread_Number = this->User_Thread_Number - this->Not_User_Thread_Number;");

     this->Write_Space();

     this->FileManager.WriteToFile("if(this->Memory_User_Thread_Number > 0){");

     this->Write_Space();

     this->FileManager.WriteToFile("   this->Memory_Usage = true;");

     this->Write_Space();

     this->FileManager.WriteToFile("   return this->Memory_Usage;");

     this->FileManager.WriteToFile("\n      };");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("       return this->Memory_Usage;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Dynamic_Memory_Manager_Builder::Write_Space(){

     this->FileManager.WriteToFile("\n\n");

     for(int i=0;i<6;i++){

         this->FileManager.WriteToFile(" ");
     }
}
