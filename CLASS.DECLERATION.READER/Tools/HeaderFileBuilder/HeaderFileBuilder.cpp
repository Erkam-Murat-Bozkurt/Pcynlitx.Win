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

#include "HeaderFileBuilder.h"

HeaderFileBuilder::HeaderFileBuilder(){

     this->ClassNameReceiveCondition = false;

     this->Memory_Delete_Condition = false;

     this->ClassName = nullptr;

     this->InclusionWord = nullptr;

     this->HeaderFileName = nullptr;
}

HeaderFileBuilder::HeaderFileBuilder(const HeaderFileBuilder & orig){}

HeaderFileBuilder::~HeaderFileBuilder(){

     if(this->ClassNameReceiveCondition && !this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
}

void HeaderFileBuilder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->ClassName);

         this->Clear_Pointer_Memory(&this->InclusionWord);

         this->Clear_Pointer_Memory(&this->HeaderFileName);

         this->FileManager.Clear_Dynamic_Memory();

         this->CharacterOperations.Clear_Dynamic_Memory();
     }
}

void HeaderFileBuilder::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

char HeaderFileBuilder::ConvertToUpper(char character){

     this->character = toupper(character);

     return this->character;
}

void HeaderFileBuilder::ReceiveClassName(char * Name){

     this->Place_String(&this->ClassName,Name);

     this->ClassNameReceiveCondition = true;

     this->Memory_Delete_Condition = false;
}

void HeaderFileBuilder::ReceiveHeaderFileName(char * FileName){

    if(*FileName != '\0'){

       this->Memory_Delete_Condition = false;

       this->Place_String(&this->HeaderFileName,FileName);
    }
    else{
           this->Memory_Delete_Condition = false;

           this->Place_String(&this->HeaderFileName,this->ClassName);
    }
}

void HeaderFileBuilder::DetermineInclusionWord(){

     int WordSize = this->CharacterOperations.CharListLength(this->ClassName);

     this->Memory_Delete_Condition = false;

     this->InclusionWord = new char [10*WordSize];

     for(int i=0;i<WordSize;i++){

        this->InclusionWord[i] = this->ConvertToUpper(this->ClassName[i]);
     }

     this->InclusionWord[WordSize]='_';

     this->InclusionWord[WordSize+1]= 'H';

     this->InclusionWord[WordSize+2]= '\0';
}

void HeaderFileBuilder::BuildHeaderFile(){

     this->DetermineInclusionWord();

     this->FileManager.SetFilePath(this->GetHeaderFileName());

     this->FileManager.FileOpen(RWC);

     this->FileManager.FileClose();

     this->FileManager.FileOpen(A);

     this->FileManager.WriteToFile("\n#ifndef ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n#define ");

     this->FileManager.WriteToFile(this->InclusionWord);

     this->FileManager.WriteToFile("\n\n\n");

     this->FileManager.WriteToFile("class ");

     this->FileManager.WriteToFile(this->GetClassName());

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("{\n");

     this->FileManager.WriteToFile("public:");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" ");

     this->FileManager.WriteToFile(this->GetClassName());

     this->FileManager.WriteToFile("();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" ");

     this->FileManager.WriteToFile(this->GetClassName());

     this->FileManager.WriteToFile("(const ");

     this->FileManager.WriteToFile(this->GetClassName());

     this->FileManager.WriteToFile(" & orig);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(" ");

     this->FileManager.WriteToFile("virtual ~");

     this->FileManager.WriteToFile(this->GetClassName());

     this->FileManager.WriteToFile("();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("private:");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("};");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("#endif /* ");

     this->FileManager.WriteToFile(this->GetInclusionWord());

     this->FileManager.WriteToFile(" */");

     this->FileManager.FileClose();
}

void HeaderFileBuilder::Place_String(char ** Pointer, char * String){

     int String_Size = strlen(String);

     *Pointer = new char [10*String_Size];

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

char * HeaderFileBuilder::GetInclusionWord(){

       return this->InclusionWord;
}

char * HeaderFileBuilder::GetClassName(){

       return this->ClassName;
}

char * HeaderFileBuilder::GetHeaderFileName(){

       return this->HeaderFileName;
}
