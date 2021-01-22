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


#include "ReturnTypeReader.h"

ReturnTypeReader::ReturnTypeReader(){

     this->Memory_Delete_Condition = true;

     this->MethodReturnType = nullptr;

     this->MethodName = nullptr;

     this->MethodLine = nullptr;
}

ReturnTypeReader::ReturnTypeReader(const ReturnTypeReader & orig){}

ReturnTypeReader::~ReturnTypeReader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void ReturnTypeReader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_String_List(&this->MethodName);

         this->Clear_String_List(&this->MethodLine);

         this->Clear_String_List(&this->MethodReturnType);
     }
}

void ReturnTypeReader::SetMethodLine(char * MethodPointer){

     if(!this->GetSyntaxErrorStatus()){

         this->Memory_Delete_Condition = false;

         int List_Size = strlen(MethodPointer);

         this->MethodLine = new char [10*List_Size];

         this->Place_String_List(&this->MethodLine,MethodPointer,List_Size);
     }
}

void ReturnTypeReader::Receive_Method_Name(char * Method_Name){

     if(!this->GetSyntaxErrorStatus()){

         this->Memory_Delete_Condition = false;

         int List_Size = strlen(Method_Name);

         this->MethodName = new char [10*List_Size];

         this->Place_String_List(&(this->MethodName),Method_Name,List_Size);
     }
}

void ReturnTypeReader::DetermineMethodReturnType(){

      if(this->GetSyntaxErrorStatus()){

         this->Memory_Delete_Condition = false;

         int List_Size = 10;

         this->MethodReturnType = new char [10*List_Size];

         this->Place_Null(&(this->MethodReturnType),List_Size);
      }
      else{

           int FirstCharacterPosition = this->CharacterOperations.FindFirstCharacterPosition(this->MethodLine);

           int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

           int SpaceNumber = 0;

           for(int i=FirstCharacterPosition;i<FirstBracePosition;i++){

               if(this->MethodLine[i] == ' '){

                  SpaceNumber++;
               }
           }

           bool DestructorHasReturnType = false;

           int FirstSpacePoint = 0;

           if(SpaceNumber>0){

              FirstSpacePoint = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,' ');

              if((this->GetClassDestructorStatus()) && (FirstSpacePoint>FirstCharacterPosition)){

                  DestructorHasReturnType = true;
              }
           }

           if(this->GetClassConstructorStatus() || ((this->GetClassDestructorStatus()) && (!DestructorHasReturnType))){

              this->Memory_Delete_Condition = false;

              int List_Size = 10;

              this->MethodReturnType = new char [10*List_Size];

              this->Place_Null(&this->MethodReturnType,List_Size);
           }
           else
           {
               int Method_Name_Length = strlen(this->MethodName);

               int ReturnType_End_Point = FirstBracePosition - Method_Name_Length;

               int ReturnType_NameSize = ReturnType_End_Point - FirstCharacterPosition;

               this->Memory_Delete_Condition = false;

               this->MethodReturnType = new char [10*ReturnType_NameSize];

               int index_counter = 0;

               for(int i=FirstCharacterPosition ;i<ReturnType_End_Point;i++){

                   this->MethodReturnType[index_counter] = this->MethodLine[i];

                   index_counter++;
               }

               this->MethodReturnType[index_counter] = '\0';

               if(this->MethodReturnType[index_counter-1] == ' '){

                  while(this->MethodReturnType[index_counter -1] == ' '){

                        this->MethodReturnType[index_counter-1] = '\0';

                        index_counter--;
                  }
               }

               this->MethodReturnType[index_counter] = '\0';
           }
      }

      this->CharacterOperations.Clear_Dynamic_Memory();
}

void ReturnTypeReader::Place_String_List(char ** Pointer, char * String, int List_Size){

     for(int i=0;i<List_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[List_Size] = '\0';
}

void ReturnTypeReader::Place_Null(char ** Pointer,int size){

     for(int i=0;i<size;i++){

         (*Pointer)[i] = '\0';
     }
}

void ReturnTypeReader::Clear_String_List(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

          *Pointer = nullptr;
     }
}

char * ReturnTypeReader::GetMethodReturnType(){

       return this->MethodReturnType;
}

void ReturnTypeReader::SetSyntaxErrorStatus(bool Status){

     this->SyntaxError = Status;
}

bool ReturnTypeReader::GetSyntaxErrorStatus(){

     return this->SyntaxError;
}

void ReturnTypeReader::SetClassConstructorStatus(bool Status){

     this->ClassConstructorStatus = Status;
}

void ReturnTypeReader::SetClassDestructorStatus(bool Status){

     this->ClassDestructorStatus = Status;
}

bool ReturnTypeReader::GetClassConstructorStatus(){

     return this->ClassConstructorStatus;
}

bool ReturnTypeReader::GetClassDestructorStatus(){

     return this->ClassDestructorStatus;
}
