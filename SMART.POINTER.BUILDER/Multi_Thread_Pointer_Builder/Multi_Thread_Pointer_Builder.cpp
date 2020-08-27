
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

#include "Multi_Thread_Pointer_Builder.h"

Multi_Thread_Pointer_Builder::Multi_Thread_Pointer_Builder(){

      this->Memory_Delete_Condition = false;

      this->Shared_Data_Type_Instance_Name = nullptr;
};

Multi_Thread_Pointer_Builder::Multi_Thread_Pointer_Builder(const Multi_Thread_Pointer_Builder & orig){

};

Multi_Thread_Pointer_Builder::~Multi_Thread_Pointer_Builder(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void Multi_Thread_Pointer_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

          this->Memory_Delete_Condition = true;

          if(this->Shared_Data_Type_Instance_Name != nullptr){

             delete [] this->Shared_Data_Type_Instance_Name;

             this->Shared_Data_Type_Instance_Name = nullptr;
          }

          this->Initializer.Clear_Dynamic_Memory();

          this->Data_Collector.Clear_Dynamic_Memory();
     }
}

void Multi_Thread_Pointer_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->Data_Collector.Receive_Descriptor_File_Reader(Pointer);

     this->P_Header_Builder.Receive_Descriptor_File_Reader(Pointer);
}

void Multi_Thread_Pointer_Builder::Receive_Data_Type_Number(int Number){

     this->Data_Type_Number = Number;

     this->Data_Collector.Receive_Data_Type_Number(Number);
}

void Multi_Thread_Pointer_Builder::Receive_Newly_Constructed_Include_Directory(char * New_Include_Directory){

     this->Data_Collector.Receive_Newly_Constructed_Include_Directory(New_Include_Directory);
}


void Multi_Thread_Pointer_Builder::Determine_Data_Type_Informations(){

     int index_number = 0;

     int Total_Data_Number = this->Reader_Pointer->Get_Shared_Data_Types_Number();

     for(int i=0;i<Total_Data_Number;i++){

         Shared_Memory_Data_Type Data_Type_Holder = this->Reader_Pointer->Get_Shared_Data_Types()[i];

         if(this->Data_Type_Number == Data_Type_Holder.Data_Number){

            index_number = i;
         }
     }

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     Shared_Memory_Data_Type Data_Type_Holder = this->Reader_Pointer->Get_Shared_Data_Types()[index_number];

     this->Receive_Data_Type(Data_Type_Holder.Data_Type);

     this->Receive_Construction_Point(Construction_Point);

     if(Data_Type_Holder.Header_File_Name != nullptr){

        int Include_Directory_Name_Size = strlen(Data_Type_Holder.Include_Directory);

        int Header_File_Name_Size = strlen(Data_Type_Holder.Header_File_Name);

        int Header_File_Path_Size = Include_Directory_Name_Size + Header_File_Name_Size;

        char Directory_Operator [] = {'/','\0'};

        char * Header_File_Path = new char [10*Header_File_Path_Size];

        for(int i=0;i<5*Header_File_Path_Size;i++){

            Header_File_Path[i] = '\0';
        }

        int index_counter = 0;

        this->Place_Information(&Header_File_Path,Data_Type_Holder.Include_Directory,&index_counter);

        this->Place_Information(&Header_File_Path,Directory_Operator,&index_counter);

        this->Place_Information(&Header_File_Path,Data_Type_Holder.Header_File_Name,&index_counter);

        Header_File_Path[index_counter] = '\0';

        this->FunctionReader = new MemberFunctionReader;

        this->FunctionReader->Receive_Include_Directory_PATH(Data_Type_Holder.Include_Directory);

        this->FunctionReader->Receive_Construction_Point(this->Reader_Pointer->Get_Construction_Point());

        this->FunctionReader->Receive_Header_File_Path(Header_File_Path);

        this->FunctionReader->Read_Member_Functions();

        this->FunctionReader->Clear_Dynamic_Memory();

        delete this->FunctionReader;

        delete [] Header_File_Path;

        this->Receive_Data_Type_Include_File_Name(Data_Type_Holder.Header_File_Name);

        this->Set_Data_Type_Include_File_Name_Receive_Condition(true);
     }
     else{

          this->Set_Data_Type_Include_File_Name_Receive_Condition(false);
     }

     this->Determine_Shared_Data_Type_Instance_Name(Data_Type_Holder.Data_Type);

     this->Set_Class_Name(this->Shared_Data_Type_Instance_Name);
}

void Multi_Thread_Pointer_Builder::Receive_Data_Type(char * DataType){

     this->Initializer.Receive_Data_Type(DataType);

     this->P_Header_Builder.Receive_Data_Type(DataType);

     this->M_Manager_Builder.Receive_Data_Type(DataType);
}


void Multi_Thread_Pointer_Builder::Receive_Construction_Point(char * Construction_Point){

     this->Initializer.Receive_Construction_Point(Construction_Point);

     this->P_Header_Builder.Receive_Construction_Point(Construction_Point);

     this->M_Manager_Builder.Receive_Construction_Point(Construction_Point);
}


void Multi_Thread_Pointer_Builder::Receive_Data_Type_Include_File_Name(char * Include_File_Name){

     if(Include_File_Name != nullptr){

        this->Initializer.Receive_Data_Type_Include_File_Name(Include_File_Name);

        this->M_Manager_Builder.Receive_Data_Type_Include_File_Name(Include_File_Name);

        this->P_Header_Builder.Receive_Data_Type_Include_File_Name(Include_File_Name);

        this->Data_Type_Include_File_Name_Receive_Condition = true;
     }
}

void Multi_Thread_Pointer_Builder::Set_Data_Type_Include_File_Name_Receive_Condition(bool Condition){

     this->P_Header_Builder.Set_Data_Type_Include_File_Name_Receive_Condition(Condition);

     this->M_Manager_Builder.Set_Data_Type_Include_File_Name_Receive_Condition(Condition);
}

void Multi_Thread_Pointer_Builder::Set_Class_Name(char * Class_Name){

     this->Initializer.Set_New_Class_Name_Directly(Class_Name);

     this->P_Header_Builder.Set_New_Class_Name_Directly(Class_Name);

     this->M_Manager_Builder.Receive_Entered_Class_Name(Class_Name);
}

void Multi_Thread_Pointer_Builder::Build_Pointer(){

     this->Memory_Delete_Condition = false;

     this->M_Manager_Builder.Receive_Namespace(this->Reader_Pointer->Get_Namespace());

     this->Data_Collector.Build_File_List();

     this->Determine_Data_Type_Informations();

     if(this->Initializer.Get_DataType() == nullptr){

        std::cout << "\n ERROR IN SMART POINTER CONSTRUCTION !";

        std::cout << "\n ERROR :Data Type can not be received ..!";

        std::cout << "\n Process has been interrupted ..";

        std::cout << "\n\n";

        std::cerr << "\n ERROR IN SMART POINTER CONSTRUCTION !";

        std::cerr << "\n ERROR :Data Type can not be received ..!";

        std::cerr << "\n Process has been interrupted ..";

        std::cerr << "\n\n";

        exit(EXIT_FAILURE);
     }

     this->DirectoryManager.ChangeDirectory(this->Initializer.Get_Construction_Point());

     this->Initializer.Receive_Generic_Class_Name("SmartPointer");

     this->Initializer.Collect_Informations();

     this->P_Header_Builder.Build_Header_File();

     this->M_Manager_Builder.Build_Memory_Manager();

     this->Build_Class_Implementation_File();
}

void Multi_Thread_Pointer_Builder::Build_Class_Implementation_File(){

     this->Start_Implementation_File_Construction();

     this->Build_Constructors();

     this->Build_Destructor();

     this->Build_NewMemory_Member_Functions();

     this->Build_DeleteMemory_Member_Function();

     this->Build_ReceiveIndexBound_Member_Function();

     this->Build_Overload_Operators_Member_Functions();

     this->Build_SetFilePath_Member_Functions();

     this->Build_Jump_To_Start_Member_Function();

     this->Build_Jump_To_End_Member_Function();

     this->Build_Thread_User_Member_Functions();
}

void Multi_Thread_Pointer_Builder::Start_Implementation_File_Construction(){

     this->FileManager.SetFilePath(this->Initializer.Get_ClassImplementationFileName());

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n #include \"");

     this->FileManager.WriteToFile(this->Initializer.Get_NewHeaderFileName());

     this->FileManager.WriteToFile("\"");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_Constructors(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n ");

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->ReportFileSetCondition = false;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->MemorySetCondition = false;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->MemoryAreaSetCondition = false;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(name_space);

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

void Multi_Thread_Pointer_Builder::Build_Destructor(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n ");

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::~");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->MemorySetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->SmartMemory.DeleteMemory();");

     this->FileManager.WriteToFile("\n      };");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_NewMemory_Member_Functions(){

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::New(int MemorySize){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(!this->MemorySetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->SmartMemory.NewMemory(&this->ControlPointer,MemorySize);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->MemorySetCondition = true;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->MemoryAreaSetCondition = true;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->ReceiveIndexBound();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->MemoryStartPoint = this->ControlPointer;");

     this->FileManager.WriteToFile("\n      }");

     this->FileManager.WriteToFile("\n      else{");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    if(this->ReportFileSetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("       this->Reporter.MemoryAllocationError();");

     this->FileManager.WriteToFile("\n          }");

     this->FileManager.WriteToFile("\n      }");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::New(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(!this->MemorySetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->SmartMemory.NewMemory(&this->ControlPointer);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->MemorySetCondition = true;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->MemoryAreaSetCondition = true;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->ReceiveIndexBound();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    this->MemoryStartPoint = this->ControlPointer;");

     this->FileManager.WriteToFile("\n      }");

     this->FileManager.WriteToFile("\n      else{");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("    if(this->ReportFileSetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("       this->Reporter.MemoryAllocationError();");

     this->FileManager.WriteToFile("\n          }");

     this->FileManager.WriteToFile("\n      }");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_DeleteMemory_Member_Function(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Delete(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->MemorySetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   if(!this->SmartMemory.Control_Memory_Usage()){;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("        this->ControlPointer = nullptr;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("        this->SmartMemory.DeleteMemory();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("        this->MemorySetCondition = false;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("  }");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("  else{");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("         this->SmartMemory.MemoryCanNotDelete();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile(" }");

     this->FileManager.WriteToFile("\n      }");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_ReceiveIndexBound_Member_Function(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::ReceiveIndexBound(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->IndexBound = this->SmartMemory.GetMemorySize();");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->adress_counter = 0;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_Overload_Operators_Member_Functions(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" & ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::operator [ ](const int & indexNumber){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("if((indexNumber >= 0) && (indexNumber < this->IndexBound)){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("    return this->ControlPointer[indexNumber];");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("}");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("else{");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("      if(this->ReportFileSetCondition){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("         this->Reporter.IndexOutOfBoundError();");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("         return this->ControlPointer[this->IndexBound-1];");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("      }");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("      else{");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("            return this->ControlPointer[this->IndexBound-1];");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("      }");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" & ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::operator * ( ){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("  return *this->ControlPointer;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" & ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::operator--(int arg){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("if(this->adress_counter >= 1){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("   this->adress_counter--;");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("   return *(this->ControlPointer--);");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("}");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("else{");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("      if(this->ReportFileSetCondition){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("         this->Reporter.PointerAdressChangeError();");

     this->Write_Space(this->Initializer.Get_DataType(),1);

      this->FileManager.WriteToFile("      }");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("      return *this->MemoryStartPoint;");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n }");

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(this->Initializer.Get_DataType());

     this->FileManager.WriteToFile(" & ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::operator++(int arg){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("if(this->adress_counter <= this->IndexBound-1){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("   this->adress_counter++;");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("     return *(this->ControlPointer++);");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("}");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("else{");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("      if(this->ReportFileSetCondition){");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("         this->Reporter.PointerAdressChangeError();");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("       }");

     this->Write_Space(this->Initializer.Get_DataType(),2);

     this->FileManager.WriteToFile("       return this->MemoryStartPoint[this->IndexBound-1];");

     this->Write_Space(this->Initializer.Get_DataType(),1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n}");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_SetFilePath_Member_Functions(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Set_Report_File_Path(const char * FileName){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->Reporter.SetReportFileName(FileName);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->SmartMemory.ReceiveReportFileManager(&this->Reporter);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->ReportFileSetCondition = true;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Set_Report_File_Path(char * FileName){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->Reporter.SetReportFileName(FileName);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->SmartMemory.ReceiveReportFileManager(&this->Reporter);");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->ReportFileSetCondition = true;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_Jump_To_Start_Member_Function(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Jump_To_Start(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->MemoryAreaSetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->adress_counter = 0;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->ControlPointer = this->MemoryStartPoint;");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_Jump_To_End_Member_Function(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Jump_To_End(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("if(this->MemoryAreaSetCondition){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->adress_counter = this->IndexBound-1;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   this->ControlPointer = this->MemoryStartPoint;");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("   for(int i=0;i<this->IndexBound-1;i++){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("       this->ControlPointer++;");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("    };");

     this->Write_Space("void",1);

     this->FileManager.WriteToFile("};");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.FileClose();
}

void Multi_Thread_Pointer_Builder::Build_Thread_User_Member_Functions(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Disconnect(){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->SmartMemory.Exit();");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_NewClassName());

     this->FileManager.WriteToFile("::Set_User_Thread_Number(int Number){");

     this->Write_Space("void",2);

     this->FileManager.WriteToFile("this->SmartMemory.Set_User_Thread_Number(Number);");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.FileClose();
}


void Multi_Thread_Pointer_Builder::Determine_Shared_Data_Type_Instance_Name(char * Data_Type_Name){

     char Type_Word [] = {'T','y','p','e','_','S','m','a','r','t','_','P','o','i','n','t','e','r','\0'};

     char Subline_Character [] = {'_','\0'};

     int Data_Type_Object_Name_Size = strlen(Data_Type_Name);

     int Type_Word_List_Size = strlen(Type_Word);

     int Instance_Name_Size = Data_Type_Object_Name_Size + Type_Word_List_Size;

     this->Shared_Data_Type_Instance_Name = new char [10*Instance_Name_Size];

     int index_counter = 0;

     this->Place_Information(&this->Shared_Data_Type_Instance_Name,Data_Type_Name,&index_counter);

     this->Place_Information(&this->Shared_Data_Type_Instance_Name,Subline_Character,&index_counter);

     this->Place_Information(&this->Shared_Data_Type_Instance_Name,Type_Word,&index_counter);

     this->Shared_Data_Type_Instance_Name[index_counter] = '\0';
}

void Multi_Thread_Pointer_Builder::Run_System_Commands(){

     this->Data_Collector.Run_System_Commands();
}

void Multi_Thread_Pointer_Builder::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
}

void Multi_Thread_Pointer_Builder::Write_Space(const char * String, int Line_Number){

     int String_Size = strlen(String);

     for(int i=0;i<Line_Number;i++){

         this->FileManager.WriteToFile("\n");
     }

     for(int i=0;i<String_Size+2;i++){

         this->FileManager.WriteToFile(" ");
     }
}

char ** Multi_Thread_Pointer_Builder::Get_Header_File_Paths_In_New_Include_Directory(){

        return this->Data_Collector.Get_Header_File_Paths_In_New_Include_Directory();
}

char * Multi_Thread_Pointer_Builder::Get_Object_File_List(){

       return this->Data_Collector.Get_Object_File_List();
}

char * Multi_Thread_Pointer_Builder::Get_Header_File_Name_List(){

      return this->Data_Collector.Get_Header_File_Name_List();
}

char * Multi_Thread_Pointer_Builder::Get_New_Class_Name(){

       return this->Data_Collector.Get_New_Class_Name();
}

char * Multi_Thread_Pointer_Builder::Get_DataType(){

       return this->Initializer.Get_DataType();
}

char * Multi_Thread_Pointer_Builder::Get_Shared_Data_Type_Instance_Name(){

      return this->Shared_Data_Type_Instance_Name;
}

char * Multi_Thread_Pointer_Builder::Get_DataType_Include_File_Name(){

       return this->Initializer.Get_DataType_IncludeFileName();
}

char * Multi_Thread_Pointer_Builder::Get_Data_Type_Include_Directory(){

       return this->Data_Collector.Get_Data_Type_Include_Directory();
}
