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

#include "HeaderRebuilder.h"

HeaderRebuilder::HeaderRebuilder(){

     this->Memory_Delete_Condition = false;

     this->Inclusion_Word = nullptr;

     this->Initializer = nullptr;

     this->Reader_Pointer = nullptr;

     this->Function_Reader_Pointer = nullptr;
};

HeaderRebuilder::HeaderRebuilder(const HeaderRebuilder & orig){

};

HeaderRebuilder::~HeaderRebuilder(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
};

void HeaderRebuilder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

          this->Memory_Delete_Condition = true;

          if(this->Inclusion_Word != nullptr){

             delete [] this->Inclusion_Word;

             this->Inclusion_Word = nullptr;
          }

          this->Initializer = nullptr;

          this->Reader_Pointer = nullptr;

          this->Function_Reader_Pointer = nullptr;
     }
}

void HeaderRebuilder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;
}

void HeaderRebuilder::Receive_ClassRebuilder_Initializer(ClassRebuilder_Initializer * Pointer){

     this->Initializer = Pointer;
}

void HeaderRebuilder::Receive_MemberFunctionReader(MemberFunctionReader * Pointer){

     this->Function_Reader_Pointer = Pointer;
}

char HeaderRebuilder::ConvertToUpper(char character){

     this->character = toupper(character);

     return this->character;
}

void HeaderRebuilder::Determine_Inclusion_Word(){

     this->Memory_Delete_Condition = false;

     char * New_Class_Name = this->Initializer->Get_New_Class_Name();

     int WordSize = strlen(New_Class_Name);

     this->Inclusion_Word = new char [10*WordSize];

     for(int i=0;i<WordSize;i++){

        this->Inclusion_Word[i] = this->ConvertToUpper(New_Class_Name[i]);
     }

     this->Inclusion_Word[WordSize]='_';

     this->Inclusion_Word[WordSize+1]= 'H';

     this->Inclusion_Word[WordSize+2]= '\0';
}

void HeaderRebuilder::Build_Header_File(){

     this->Determine_Inclusion_Word();

     char * New_Header_File_Name = this->Initializer->Get_New_Header_File_Name();

     char * New_Class_Name = this->Initializer->Get_New_Class_Name();

     char * Base_Class_Name = this->Initializer->Get_Base_Class_Name();

     char * Base_Class_Header_File_Name = this->Initializer->Get_Base_Class_Header_File_Name();

     char * Base_Class_Destructor_Name = this->Initializer->Get_Base_Class_Destructor_Name();

     //char * Object_Name = this->Initializer->Get_Object_Name();

     this->DirectoryManager.ChangeDirectory(this->Reader_Pointer->Get_Constructed_Include_Directory());

     this->FileManager.SetFilePath(New_Header_File_Name);

     this->FileManager.FileOpen(RWCf);

     this->FileManager.FileClose();

     this->FileManager.FileOpen(Af);

     this->FileManager.WriteToFile("\n#ifndef ");

     this->FileManager.WriteToFile(this->Inclusion_Word);

     this->FileManager.WriteToFile("\n#define ");

     this->FileManager.WriteToFile(this->Inclusion_Word);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("#include \"");

     this->FileManager.WriteToFile(Base_Class_Header_File_Name);

     this->FileManager.WriteToFile("\"");

     this->FileManager.WriteToFile("\n#include \"itds.h\"");

     this->FileManager.WriteToFile("\n#include <cstdlib>");

     int included_header_file_number = this->Initializer->Get_Included_Header_Files_Number();

     for(int i=0;i<included_header_file_number;i++){

         this->FileManager.WriteToFile("\n#include ");

         std::string declaration = this->Initializer->Get_Header_File_Declarations()[i];

         this->FileManager.WriteToFile(declaration);
     }

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("namespace ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("{");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("  class ");

     this->FileManager.WriteToFile(New_Class_Name);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("  {\n");

     this->FileManager.WriteToFile("  public:");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("   ");

     this->FileManager.WriteToFile(New_Class_Name);

     this->FileManager.WriteToFile("(thds * thread_data);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("   ");

     this->FileManager.WriteToFile(New_Class_Name);

     this->FileManager.WriteToFile("(const ");

     this->FileManager.WriteToFile(New_Class_Name);

     this->FileManager.WriteToFile(" & orig);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("   ");

     this->FileManager.WriteToFile("virtual ~");

     this->FileManager.WriteToFile(New_Class_Name);

     this->FileManager.WriteToFile("();");

     int PublicMethodNumber = this->Function_Reader_Pointer->Get_Public_Method_Number();

     for(int i=0;i<PublicMethodNumber;i++){

         bool isConstructor = this->CharacterOperations.CompareString(Base_Class_Name,this->Function_Reader_Pointer->GetPublicMethods()[i].Method_Name);

         bool isDestructor = this->CharacterOperations.CompareString(Base_Class_Destructor_Name,this->Function_Reader_Pointer->GetPublicMethods()[i].Method_Name);

         if(!isConstructor && !isDestructor){

            this->FileManager.WriteToFile("\n   ");

            this->FileManager.WriteToFile(this->Function_Reader_Pointer->GetPublicMethods()[i].Return_Type);

            this->FileManager.WriteToFile(" ");

            this->FileManager.WriteToFile(this->Function_Reader_Pointer->GetPublicMethods()[i].Method_Name);

            this->FileManager.WriteToFile("(");

            int ParameterNumber = this->Function_Reader_Pointer->GetPublicMethods()[i].Parameter_Number;

            if(ParameterNumber > 0){

               for(int j=0;j<ParameterNumber;j++){

                   this->FileManager.WriteToFile(this->Function_Reader_Pointer->GetPublicMethods()[i].Parameter_Types[j]);

                   this->FileManager.WriteToFile(" ");

                   this->FileManager.WriteToFile(this->Function_Reader_Pointer->GetPublicMethods()[i].Parameter_Names[j]);

                   if(j == ParameterNumber-1){

                        this->FileManager.WriteToFile(");");
                   }
                   else{

                        this->FileManager.WriteToFile(", ");
                   }
               }
            }
            else{

                  this->FileManager.WriteToFile(");");
            }
         }
      }

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("   void Connect(thds * thread_data);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("  private:");

     this->FileManager.WriteToFile("\n   void Print_Connection_Error();");

     this->FileManager.WriteToFile("\n   ");

     this->FileManager.WriteToFile(Base_Class_Name);

     this->FileManager.WriteToFile(" * Connection_Pointer;");

     this->FileManager.WriteToFile("\n   bool Connect_Condition;");

     this->FileManager.WriteToFile("\n  };");

     this->FileManager.WriteToFile("\n};");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("#endif");

     this->FileManager.FileClose();

     this->DirectoryManager.ChangeDirectory(this->Reader_Pointer->Get_Construction_Point());

     this->DirectoryManager.Clear_Dynamic_Memory();
}
