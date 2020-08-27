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


#include "ParenthesReader.h"

ParenthesReader::ParenthesReader(){

    this->Memory_Delete_Condition = true;

    this->MethodLine = nullptr;

    this->MethodParenthes = nullptr;

    this->SetSyntaxErrorStatus(false);
}

ParenthesReader::ParenthesReader(const ParenthesReader & orig){ }

ParenthesReader::~ParenthesReader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void ParenthesReader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_String_List(&this->MethodLine);

         this->Clear_String_List(&this->MethodParenthes);
     }
}

void ParenthesReader::ReadMethodParenthes(char * MethodLine){

     this->Memory_Delete_Condition = false;

     if((this->GetSyntaxErrorStatus()) || (MethodLine[0] == '\0')){

        int List_Size = 10;

        this->MethodLine = new char [10*List_Size];

        this->Place_Null(&this->MethodLine,List_Size);

        this->MethodParenthes = new char [10*List_Size];

        this->Place_Null(&this->MethodParenthes,List_Size);
     }
     else{

        this->ReceiveMethodLine(MethodLine);

        this->DetermineMethodParameterNumber();

        this->ExtractMethodParenthes();
     }

     this->CharacterOperations.Clear_Dynamic_Memory();
}

void ParenthesReader::ReceiveMethodLine(char * Method){

     int ListSize =  strlen(Method);

     this->MethodLine = new char [10*ListSize];

     for(int i=0;i<ListSize;i++){

         this->MethodLine[i] = Method[i];
     }

     this->MethodLine[ListSize] = '\0';
}

void ParenthesReader::DetermineMethodParameterNumber(){

      this->MethodParameterNumber = 0;

      int commaNumber = this->CharacterOperations.DetermineCharacterRepitation(this->MethodLine,',');

      if(commaNumber !=0){

          this->MethodParameterNumber = commaNumber+1;
      }
      else
      {
          int startPoint = 0;

          int FirstBrace = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,startPoint,'(');

          int LastBrace  = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,startPoint,')');

          int spaceSize = LastBrace - FirstBrace;

          if(spaceSize>1){

             for(int i=FirstBrace+1;i<LastBrace;i++){

                 if(this->MethodLine[i]!=' '){

                     this->MethodParameterNumber = 1;
                 }
             }
          }
      }
}

void ParenthesReader::ExtractMethodParenthes(){

     int FirstBrace = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     int LastBrace  = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,')');

     int ListSize = LastBrace - FirstBrace -1;

     if(this->getMethodParameterNumber() == 0){

         int List_Size = 10;

         this->MethodParenthes = new char [10*List_Size];

         this->Place_Null(&this->MethodParenthes,List_Size);
     }
     else{

         this->MethodParenthes = new char [10*ListSize];

         for(int i=0;i<ListSize;i++){

            this->MethodParenthes[i] = this->MethodLine[i+FirstBrace+1];
         }

         this->MethodParenthes[ListSize] = '\0';
     }
}

void ParenthesReader::Place_Null(char ** Pointer,int size){

     for(int i=0;i<size;i++){

        (*Pointer)[i] = '\0';
     }
}

void ParenthesReader::Clear_String_List(char ** String_List){

     if(*String_List != nullptr){

         delete [] (*String_List);

         *String_List = nullptr;
     }
}

char * ParenthesReader::getMethodParenthes(){

    return this->MethodParenthes;
}

int ParenthesReader::getMethodParameterNumber(){

    return this->MethodParameterNumber;
}

void ParenthesReader::SetSyntaxErrorStatus(bool status){

     this->SyntaxError = status;
}

bool ParenthesReader::GetSyntaxErrorStatus(){

    return this->SyntaxError;
}
