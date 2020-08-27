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


#include "NameReader.h"

NameReader::NameReader(){

     this->SetSyntaxErrorStatus(false);

     this->Memory_Delete_Condition = true;

     this->MethodLine = nullptr;

     this->MethodName = nullptr;
}

NameReader::NameReader(const NameReader & orig){}

NameReader::~NameReader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void NameReader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_String_List(&this->MethodLine);

         this->Clear_String_List(&this->MethodName);
     }
}

void NameReader::DetermineMethodName(){

     this->Memory_Delete_Condition = false;

     char operator_word [] = {'o','p','e','r','a','t','o','r','\0'};

     if(this->GetSyntaxErrorStatus()){

         int List_Size = 10;

         this->MethodName = new char [10*List_Size];

         this->Place_Null_For_String_List(&this->MethodName,List_Size);
     }
     else{

            bool Is_Method_Line_Includes_Operator_Word = this->StringOperations.CheckStringInclusion(this->MethodLine,operator_word);

            int FirstCharacterPosition = this->CharacterOperations.FindFirstCharacterPosition(this->MethodLine);

            int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

            int SpaceNumber = 0;

            for(int i=0;i<FirstBracePosition;i++){

                if(this->MethodLine[i] == ' '){

                    SpaceNumber++;
                }
            }

            bool DestructorHasReturnType = false;

            int FirstSpacePoint = 0;

            if(SpaceNumber>0){

                  FirstSpacePoint = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,' ');

                  if((this->GetClassDestructorStatus()) && (FirstSpacePoint>FirstCharacterPosition)){

                      DestructorHasReturnType = true; // Destructor may be declreated as virtual !!
                  }
            }

            bool Is_There_Return_Type;

            if((this->GetClassConstructorStatus()) || ((this->GetClassDestructorStatus()) && (!DestructorHasReturnType))){

                 Is_There_Return_Type = false;
            }
            else
            {
                 Is_There_Return_Type = true;
            }

            int Last_Space_Before_First_Brace = 0;

            if(SpaceNumber!=0){

                for(int i=0;i<SpaceNumber;i++){

                    Last_Space_Before_First_Brace = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,Last_Space_Before_First_Brace+1,' ');
                }
            }

            if(Is_Method_Line_Includes_Operator_Word){

               Last_Space_Before_First_Brace = this->StringOperations.Get_Start_Position_of_an_included_String() -1;
            }

            if(Is_There_Return_Type){

               int NameSize = FirstBracePosition - Last_Space_Before_First_Brace -1;

               this->MethodName = new char [10*NameSize];

               for(int i=0;i<NameSize;i++){

                   this->MethodName[i] = this->MethodLine[i+Last_Space_Before_First_Brace+1];
               }

               this->MethodName[NameSize] = '\0';
             }
             else{

                  int NameSize = FirstBracePosition - FirstCharacterPosition;

                  this->MethodName = new char[10*NameSize];

                  for(int i=0;i<NameSize;i++){

                      this->MethodName[i] = this->MethodLine[i+FirstCharacterPosition];
                  }

                  this->MethodName[NameSize] = '\0';
             }
     }

     this->StringOperations.ClearStringBuffer();

     this->CharacterOperations.Clear_Dynamic_Memory();
}

void NameReader::SetMethodLine(char * MethodPointer){

     if(this->GetSyntaxErrorStatus()){

         int List_Size = 10;

         this->MethodLine = new char [10*List_Size];

         this->Place_Null_For_String_List(&this->MethodLine,10);
     }
     else{

           int List_Size = strlen(MethodPointer);

           this->MethodLine = new char [10*List_Size];

           this->Place_String_List(&this->MethodLine,MethodPointer,List_Size);
     }
}

void NameReader::Place_String_List(char ** Pointer, char * String_List, int List_Size){

      for(int i=0;i<List_Size;i++){

          (*Pointer)[i] = String_List[i];
      }

      (*Pointer)[List_Size] = '\0';
}

void NameReader::Place_Null_For_String_List(char ** String_List, int size){

     for(int i=0;i<size;i++){

        (*String_List)[i] = '\0';
     }
}

void NameReader::Clear_String_List(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

char * NameReader::GetMethodName(){

       return this->MethodName;
}

void NameReader::SetSyntaxErrorStatus(bool Status){

     this->SyntaxError = Status;
}

bool NameReader::GetSyntaxErrorStatus(){

     return this->SyntaxError;
}

void NameReader::SetClassConstructorStatus(bool Status){

     this->ClassConstructorStatus = Status;
}

void NameReader::SetClassDestructorStatus(bool Status){

     this->ClassDestructorStatus = Status;
}

bool NameReader::GetClassConstructorStatus(){

     return this->ClassConstructorStatus;
}

bool NameReader::GetClassDestructorStatus(){

     return this->ClassDestructorStatus;
}
