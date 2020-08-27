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

#include "ClassRebuilder.h"

ClassRebuilder::ClassRebuilder(){

     this->Memory_Delete_Condition = false;

     this->Object_File_Name = nullptr;

     this->New_Header_File_Name = nullptr;

     this->New_Class_Name = nullptr;

     this->Reader_Pointer = nullptr;
};

ClassRebuilder::ClassRebuilder(const ClassRebuilder & orig){ };

ClassRebuilder::~ClassRebuilder(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
};

void ClassRebuilder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->Object_File_Name);

         this->Clear_Pointer_Memory(&this->New_Header_File_Name);

         this->Clear_Pointer_Memory(&this->New_Class_Name);

         this->Data_Collector.Clear_Dynamic_Memory();

         this->HeaderFileRebuilder.Clear_Dynamic_Memory();

         this->Initializer.Clear_Dynamic_Memory();

         this->HeaderFileRebuilder.Clear_Dynamic_Memory();

         this->FunctionReader.Clear_Dynamic_Memory();

         this->DataTranslater.Clear_Dynamic_Memory();

         this->FileManager.Clear_Dynamic_Memory();

         this->CharacterOperations.Clear_Dynamic_Memory();

         this->DirectoryManager.Clear_Dynamic_Memory();
     }
}

void ClassRebuilder::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

void ClassRebuilder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->HeaderFileRebuilder.Receive_Descriptor_File_Reader(Pointer);

     this->Initializer.Receive_Descriptor_File_Reader(Pointer);

     this->Data_Collector.Receive_Descriptor_File_Reader(Pointer);
}

void ClassRebuilder::Receive_Class_Number(int Number){

     this->Initializer.Receive_Class_Number(Number);
}

void ClassRebuilder::Receive_Data_Type_Number(int Number){

    this->Initializer.Receive_Data_Type_Number(Number);
}

void ClassRebuilder::Read_Informations(){

     this->Memory_Delete_Condition = false;

     this->Initializer.Determine_Informations();

     this->FunctionReader.Receive_Include_Directory_PATH(this->Initializer.Get_Base_Class_Header_File_Location());

     this->FunctionReader.Receive_Construction_Point(this->Reader_Pointer->Get_Construction_Point());

     this->FunctionReader.Receive_Header_File_Path(this->Initializer.Get_Base_Class_Header_File_Path());

     this->FunctionReader.Read_Member_Functions();

     this->Data_Collector.Receive_ClassRebuilder_Initializer(&this->Initializer);

     this->Data_Collector.Reiceve_Directory_Manager(&this->DirectoryManager);

     this->Data_Collector.Collect_System_Command_Informations();

     this->HeaderFileRebuilder.Receive_ClassRebuilder_Initializer(&this->Initializer);

     this->HeaderFileRebuilder.Receive_MemberFunctionReader(&this->FunctionReader);

     this->DataTranslater.Receive_Namespace(this->Reader_Pointer->Get_Namespace());
}

void ClassRebuilder::Re_Construct_Class(){

     this->Read_Informations();

     this->DirectoryManager.DetermineCurrentDirectory();

     this->DirectoryManager.ChangeDirectory(this->Initializer.Get_Base_Class_Header_File_Location());

     this->HeaderFileRebuilder.Build_Header_File();

     this->DirectoryManager.DetermineCurrentDirectory();

     this->DataTranslater.ReceiveClassName(this->Initializer.Get_New_Class_Name());

     this->DataTranslater.ReceiveObjectName(this->Initializer.Get_Object_Name());

     this->DirectoryManager.ChangeDirectory(this->Reader_Pointer->Get_Construction_Point());

     this->DirectoryManager.DetermineCurrentDirectory();

     this->Start_Implementation_File_Construction();

     this->Construct_Class_Implementation_File();

     this->Receive_New_Class_Name();

     this->Receive_Object_File_Name();
}

void ClassRebuilder::Start_Implementation_File_Construction(){

     this->FileManager.SetFilePath(this->Initializer.Get_New_Class_Implementation_File_Name());

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n\n #include \"");

     this->FileManager.WriteToFile(this->Initializer.Get_New_Header_File_Name());

     this->FileManager.WriteToFile("\"");

     this->FileManager.FileClose();
}

void ClassRebuilder::Construct_Class_Implementation_File(){

     this->FileManager.FileOpen(A);

     int PublicMethodNumber = this->FunctionReader.Get_Public_Method_Number();

     for(int i=0;i<PublicMethodNumber;i++){

         bool isConstructor = this->Initializer.Is_This_Method_Base_Class_Constructor(this->FunctionReader.GetPublicMethods()[i].Method_Name);

         bool isDestructor  = this->Initializer.Is_This_Method_Base_Class_Destructor(this->FunctionReader.GetPublicMethods()[i].Method_Name);

         if(isConstructor){

              this->Write_Constructor_Function_Definition(i);
         }

         if(isDestructor){

              this->Write_Dectructor_Function_Definition(i);
         }

         if(!isConstructor && !isDestructor){

              this->Write_Member_Function_Definition(i);
          }
      }

      this->Write_Connection_Method();

      this->Write_Connection_Error_Printing_Method();

      this->FileManager.FileClose();
}

void ClassRebuilder::Write_Constructor_Function_Definition(int FunctionNumber){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile("\n\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_New_Class_Constructor_Name());

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_New_Class_Constructor_Name());

     int ParameterNumber = this->FunctionReader.GetPublicMethods()[FunctionNumber].Parameter_Number;

     char ** ParameterTypes = this->FunctionReader.GetPublicMethods()[FunctionNumber].Parameter_Types;

     if(this->Is_This_Method_Copy_Constructor(ParameterNumber,ParameterTypes)){

         this->FileManager.WriteToFile("(const ");

         this->FileManager.WriteToFile(this->Initializer.Get_New_Class_Constructor_Name());

         this->FileManager.WriteToFile(" & orig ){");

         this->FileManager.WriteToFile("\n\n");
     }
     else{

         this->FileManager.WriteToFile("(thds * arg){");

         this->Write_Space(4);

         this->FileManager.WriteToFile("\n\n");

         this->FileManager.WriteToFile("      this->Connect_Condition = false;");

         this->FileManager.WriteToFile("\n\n      this->Connect(arg);");
     }

     this->FileManager.WriteToFile("\n };");
}

void ClassRebuilder::Write_Dectructor_Function_Definition(int FunctionNumber){

     this->FileManager.WriteToFile("\n\n ");

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_New_Class_Constructor_Name());

     this->FileManager.WriteToFile("::~");

     this->FileManager.WriteToFile(this->Initializer.Get_New_Class_Constructor_Name());

     this->FileManager.WriteToFile("(){");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("\n };");
}

void ClassRebuilder::Write_Member_Function_Definition(int FunctionNumber){

     this->DataTranslater.ReceiveMethodInformations(&this->FunctionReader.GetPublicMethods()[FunctionNumber]);

     this->DataTranslater.Collect_Informations();

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(this->DataTranslater.GetFunctionImplementationCodeLine());

     this->FileManager.WriteToFile("{");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space(this->DataTranslater.GetReturnTypeNameSize());

     this->FileManager.WriteToFile("if(this->Connect_Condition){");

     this->FileManager.WriteToFile("\n\n   ");

     this->Write_Space(this->DataTranslater.GetReturnTypeNameSize());

     this->FileManager.WriteToFile("this->Connection_Pointer->");

     this->FileManager.WriteToFile(this->DataTranslater.Get_Function_Call_Line());

     this->FileManager.WriteToFile("\n");

     this->Write_Space(this->DataTranslater.GetReturnTypeNameSize());

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n");

     this->Write_Space(this->DataTranslater.GetReturnTypeNameSize());

     this->FileManager.WriteToFile("else{");

     this->FileManager.WriteToFile("\n");

     this->Write_Space(this->DataTranslater.GetReturnTypeNameSize());

     this->FileManager.WriteToFile("      this->Print_Connection_Error();");

     this->FileManager.WriteToFile("\n");

     this->Write_Space(this->DataTranslater.GetReturnTypeNameSize());

     this->FileManager.WriteToFile("}");

     this->FileManager.WriteToFile("\n };");
}

void ClassRebuilder::Write_Connection_Method(){

     char * Member_Class_Instace = this->Initializer.Get_Base_Class_Instance_Name();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_New_Class_Constructor_Name());

     this->FileManager.WriteToFile("::Connect(thds * dp){");

     this->FileManager.WriteToFile("\n\n      this->Connect_Condition = true;");

     this->FileManager.WriteToFile("\n\n      this->Connection_Pointer = dp->itds_Pointer->");

     this->FileManager.WriteToFile(Member_Class_Instace);

     this->FileManager.WriteToFile("_Tsp;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");
}

void ClassRebuilder::Write_Connection_Error_Printing_Method(){

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::");

     this->FileManager.WriteToFile(this->Initializer.Get_New_Class_Constructor_Name());

     this->FileManager.WriteToFile("::Print_Connection_Error(){");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space(4);

     this->FileManager.WriteToFile("std::cout << \"\\e\[1;37m [ERROR] \";");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space(4);

     this->FileManager.WriteToFile("std::cout << \"\\e\[2;33m  In Thread, client object can not connect server object .. \";");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space(4);

     this->FileManager.WriteToFile("std::cout << \"\\e\[2;33m  Please check cleint object connections ..\";");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space(4);

     this->FileManager.WriteToFile("std::cout << \"\\e\[2;33m  Process will be interrupted ..\";");

     this->FileManager.WriteToFile("\n\n");

     this->Write_Space(4);

     this->FileManager.WriteToFile("exit(0);");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");
}

bool ClassRebuilder::Is_This_Method_Copy_Constructor(int ParameterNumber,char ** ParameterTypes){

     if(ParameterNumber == 1){

        char * Base_Class_Name = this->Initializer.Get_Base_Class_Name();

        char const_word [] = {'c','o','n','s','t','\0'};

        int const_word_size = strlen(const_word);

        int base_class_constructor_name_size = strlen(Base_Class_Name);

        char * NameBuffer = new char [10*base_class_constructor_name_size];

        int index_counter = 0;

        for(int i=0;i<const_word_size;i++){

            NameBuffer[index_counter] = const_word[i];

            index_counter++;
        }

        NameBuffer[index_counter] = ' ';

        index_counter++;

        for(int i=0;i<base_class_constructor_name_size;i++){

            NameBuffer[index_counter] =  Base_Class_Name[i];

            index_counter++;
        }

        NameBuffer[index_counter] = ' ';

        index_counter++;

        NameBuffer[index_counter] ='&';

        index_counter++;

        NameBuffer[index_counter] = '\0';

        while(ParameterTypes[0][0] == ' '){

           int ParameterTypes_Name_Size = strlen(ParameterTypes[0]);

           for(int k=0;k<ParameterTypes_Name_Size;k++){

               ParameterTypes[0][k] = ParameterTypes[0][k+1];
           }

           ParameterTypes[0][ParameterTypes_Name_Size] = '\0';
        }

        this->IsThisCopyConstructor = this->CharacterOperations.CompareString(ParameterTypes[0],NameBuffer);

        delete [] NameBuffer;

        return this->IsThisCopyConstructor;
     }
     else{

          this->IsThisCopyConstructor = false;

          return this->IsThisCopyConstructor;
     }
}

void ClassRebuilder::Receive_New_Class_Name(){

     int String_Size = strlen(this->Initializer.Get_New_Class_Name());

     this->New_Class_Name = new char [10*String_Size];

     this->Place_String(&this->New_Class_Name,this->Initializer.Get_New_Class_Name(),String_Size);
}

void ClassRebuilder::Receive_Object_File_Name(){

     char * File_Name = this->Data_Collector.Get_Object_File_Name();

     int String_Size = strlen(File_Name);

     this->Object_File_Name = new char [10*String_Size];

     this->Place_String(&this->Object_File_Name,File_Name,String_Size);
}

void ClassRebuilder::Print_System_Commands(){

     this->Data_Collector.Print_System_Commands();
}

void ClassRebuilder::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

void ClassRebuilder::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void ClassRebuilder::Run_System_Commands(){

     this->Data_Collector.Run_System_Commands();
}

char * ClassRebuilder::Get_Object_File_Name() const
{
       return this->Object_File_Name;
}

char * ClassRebuilder::Get_New_Class_Name() const
{
       return this->New_Class_Name;
}

void ClassRebuilder::Write_Space(int Space_Number){

     for(int i=0;i<Space_Number+2;i++){

         this->FileManager.WriteToFile(" ");
     }
}
