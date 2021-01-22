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

#include "ClassNameReader.h"

ClassNameReader::ClassNameReader(){

    this->Memory_Delete_Condition = true;

    this->Class_Syntax_Error_Status = false;
}

ClassNameReader::ClassNameReader(const ClassNameReader & orig){

}

ClassNameReader::~ClassNameReader(){

    if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
    }
}

void ClassNameReader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->ClassName);
     }
}

void ClassNameReader::ReadClassName(char * HeaderFileName){

     this->Memory_Delete_Condition = false;

     this->Class_Syntax_Error_Status = false;

     this->ClsSynCntr.CheckClassSyntax(HeaderFileName);

     if(this->ClsSynCntr.GetClassSyntaxErrorStatus()){

        int List_Size = 10;

        this->ClassName = new char [10*List_Size];

        this->Place_Null(&this->ClassName,List_Size);

        this->Class_Syntax_Error_Status = true;
     }
     else{

          int FirstSpacePoint = 0, NextCharacterPoint = 0;

          while(this->ClsSynCntr.Get_Class_Word_Line()[FirstSpacePoint] != ' '){    // Search for the first space after the class key word ..

                FirstSpacePoint++;                       //  (FirstSpacePoint) is the first space after the class key word..
          }

          NextCharacterPoint = FirstSpacePoint;

          while(this->ClsSynCntr.Get_Class_Word_Line()[NextCharacterPoint] == ' '){    // Search for the start of the second word coming after class key word..

                NextCharacterPoint++;                       // (NextCharacterPoint) is the first character point in the list after class key word..
          }

          int ListLength = strlen(this->ClsSynCntr.Get_Class_Word_Line());

          int NameSize = ListLength - NextCharacterPoint;

          this->ClassName = new char [10*NameSize];

          for(int i = NextCharacterPoint;i<NameSize;i++){

              if(this->ClsSynCntr.Get_Class_Word_Line()[i] == ' '){

                 int List_Size = 10;

                 this->Place_Null(&this->ClassName,List_Size);

                 this->Class_Syntax_Error_Status = true;

                 break;
              }
          }

          if(!this->Class_Syntax_Error_Status){

              int index_counter = 0;

              for(int i= NextCharacterPoint;i<ListLength;i++){

                  this->ClassName[index_counter] = this->ClsSynCntr.Get_Class_Word_Line()[i];

                  index_counter++;
              }

              if((this->ClassName[index_counter-1] == '\n') || (this->ClassName[index_counter-1] == '{')){

                  this->ClassName[index_counter-1] = '\0';
              }

              this->ClassName[index_counter] ='\0';
          }
     }

     this->ClsSynCntr.Clear_Dynamic_Memory();
}

void ClassNameReader::Place_Null(char ** Pointer, int List_Size){

     for(int i=0;i<List_Size;i++){

         (*Pointer)[i] = '\0';
     }
}

void ClassNameReader::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

char * ClassNameReader::getClassName(){

       return this->ClassName;
}

bool ClassNameReader::GetClassSyntaxErrorStatus(){

     return this->Class_Syntax_Error_Status;
}
