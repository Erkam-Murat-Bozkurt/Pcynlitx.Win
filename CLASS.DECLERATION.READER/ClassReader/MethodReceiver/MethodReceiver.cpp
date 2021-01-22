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


#include "MethodReceiver.h"

MethodReceiver::MethodReceiver(){

    this->Memory_Delete_Condition = true;

    this->ClassName = nullptr;

    this->ClassConstructorName = nullptr;

    this->ClassDestructorName = nullptr;

    this->MethodLine = nullptr;

    this->MethodNameBuffer = nullptr;

    this->MethodParenthes = nullptr;

    this->setMethodSyntaxErrorStatus(false);
}

MethodReceiver::MethodReceiver(const MethodReceiver & orig){ }

MethodReceiver::~MethodReceiver(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void MethodReceiver::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_String_List(&this->ClassName);

         this->Clear_String_List(&this->ClassConstructorName);

         this->Clear_String_List(&this->ClassDestructorName);

         this->Clear_String_List(&this->MethodLine);

         this->Clear_String_List(&this->MethodNameBuffer);

         this->Clear_String_List(&this->MethodParenthes);
     }
}

void MethodReceiver::ReceiveMethodLine(char * MethodLine){

     this->Memory_Delete_Condition = false;

     if(MethodLine[0] == '\0'){

        this->setMethodSyntaxErrorStatus(true);

        int List_Size = 10;

        this->MethodLine = new char [10*List_Size];

        this->Place_Null(&this->MethodLine,List_Size);

        this->MethodParenthes = new char [10*List_Size];

        this->Place_Null(&this->MethodParenthes,List_Size);

        this->MethodNameBuffer = new char [10*List_Size];

        this->Place_Null(&this->MethodNameBuffer,List_Size);

        this->ClassConstructorName = new char [10*List_Size];

        this->Place_Null(&this->ClassConstructorName,List_Size);

        this->ClassDestructorName = new char [10*List_Size];

        this->Place_Null(&this->ClassDestructorName,List_Size);

        this->ParenthesOperations.SetSyntaxErrorStatus(true);

        this->ParenthesOperations.ReadMethodParenthes(this->MethodLine);

        this->MethodParameterNumber = 0;

        this->ClassConstructorStatus = false;

        this->ClassDestructorStatus = false;
     }
     else
     {
          int MethodLength = strlen(MethodLine);

          this->MethodLine = new char [10*MethodLength];

          bool IndexEndPoint = false;

          for(int i=0; i< MethodLength;i++){

              this->MethodLine[i] = MethodLine[i];

              if(this->MethodLine[i] == ';'){

                  IndexEndPoint = true;
              }

              if(IndexEndPoint){

                 this->MethodLine[i] = '\0';
              }

              if(this->MethodLine[i] == '\n'){

                 this->MethodLine[i] = '\0';
              }
          }

          this->MethodLine[MethodLength] = '\0';

          this->ParenthesOperations.SetSyntaxErrorStatus(false);

          this->ParenthesOperations.ReadMethodParenthes(this->MethodLine);

          if(this->ParenthesOperations.getMethodParenthes()[0] != '\0'){

               int ParenthesLength = strlen(this->ParenthesOperations.getMethodParenthes());

               this->MethodParenthes = new char [10*ParenthesLength];

               char * parenthesPointer = this->ParenthesOperations.getMethodParenthes();

               for(int i=0;i<ParenthesLength;i++){

                   this->MethodParenthes[i] = parenthesPointer[i];
                }

                this->MethodParenthes[ParenthesLength] = '\0';
          }
          else{

                int List_Size = 10;

                this->MethodParenthes = new char [10*List_Size];

                this->Place_Null(&this->MethodParenthes,List_Size);
          }

          this->MethodParameterNumber = this->ParenthesOperations.getMethodParameterNumber();

          this->DetermineMethodName();

          this->DetermineClassConstructorStatus();

          this->DetermineClassDestructorStatus();
      }

      this->ParenthesOperations.Clear_Dynamic_Memory();

      this->CharacterOperations.Clear_Dynamic_Memory();
}

void MethodReceiver::SetClassName(char * className){

     int NameSize = this->CharacterOperations.CharListLength(className);

     this->ClassName = new char [10*NameSize];

     for(int i=0;i<NameSize;i++){

         this->ClassName[i] = className[i];

         if((this->ClassName[i] == '\n') || (this->ClassName[i] == ' ')){

            this->ClassName[i] = '\0';
         }
     }

     this->ClassName[NameSize] = '\0';

     this->ClassConstructorName = new char [10*NameSize];

     for(int i=0;i<NameSize;i++){

          this->ClassConstructorName[i] = this->ClassName[i];
     }

     this->ClassConstructorName[NameSize] = '\0';

     this->ClassDestructorName = new char [10*NameSize+1];

     this->ClassDestructorName[0] = '~';

     for(int i=0;i<NameSize;i++){

        this->ClassDestructorName[i+1] = this->ClassConstructorName[i];
     }

     this->ClassDestructorName[NameSize+1] = '\0';
}

void MethodReceiver::DetermineMethodName(){

     int FirstCharacterPosition = this->CharacterOperations.FindFirstCharacterPosition(this->MethodLine);

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     int SpaceNumber = this->CharacterOperations.DetermineCharacterRepitation(this->MethodLine,' ');

     int Last_Space_Before_First_Brace = 0, NameSize = 0;

     if(SpaceNumber!=0){

           for(int i=0;i<SpaceNumber;i++){

               Last_Space_Before_First_Brace = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,Last_Space_Before_First_Brace,' ');
           }
     }

     if((SpaceNumber!=0) && (FirstBracePosition > Last_Space_Before_First_Brace)){

           NameSize = FirstBracePosition - Last_Space_Before_First_Brace -1;

           this->MethodNameBuffer = new char [10*NameSize];

           for(int i=0;i<NameSize;i++){

               this->MethodNameBuffer[i] = this->MethodLine[i+Last_Space_Before_First_Brace+1];
           }

           this->MethodNameBuffer[NameSize] = '\0';
     }
     else{

           NameSize = FirstBracePosition - FirstCharacterPosition;

           this->MethodNameBuffer = new char[10*NameSize];

           for(int i=0;i<NameSize;i++){

                this->MethodNameBuffer[i] = this->MethodLine[i+FirstCharacterPosition];
           }

           this->MethodNameBuffer[NameSize] = '\0';
      }
}

void MethodReceiver::DetermineClassConstructorStatus(){

     if(this->CharacterOperations.CompareString(this->MethodNameBuffer,this->ClassConstructorName)){

         this->ClassConstructorStatus = true;
     }
     else{

        this->ClassConstructorStatus = false;
     }
}

void MethodReceiver::DetermineClassDestructorStatus(){

     if(this->CharacterOperations.CompareString(this->MethodNameBuffer,this->ClassDestructorName)){

        this->ClassDestructorStatus = true;
     }
     else{

          this->ClassDestructorStatus = false;
     }
}

void MethodReceiver::Place_Null(char ** Pointer, int List_Size){

     for(int i=0;i<List_Size;i++){

         (*Pointer)[i] = '\0';
     }
}

void MethodReceiver::Clear_String_List(char ** String_List){

     if(*String_List != nullptr){

        delete [] (*String_List);

        *String_List = nullptr;
     }
}

void MethodReceiver::setMethodSyntaxErrorStatus(bool condition){

     this->SyntaxErrorCondition = condition;
}


char * MethodReceiver::getMethodLine(){

       return this->MethodLine;
}

bool MethodReceiver::getMethodSyntaxErrorStatus(){

     return this->SyntaxErrorCondition;
}

int MethodReceiver::getMethodParameterNumber(){

    return this->MethodParameterNumber;
}

char * MethodReceiver::getClassName(){

     return this->ClassName;
}

char * MethodReceiver::getMethodParenthes(){

    return this->MethodParenthes;
}

bool MethodReceiver::getClassDestructorStatus(){

     return this->ClassDestructorStatus;
}

bool MethodReceiver::getClassConstructorStatus(){

     return this->ClassConstructorStatus;
}

char * MethodReceiver::getClassConstructorName(){

     return this->ClassConstructorName;
}

char * MethodReceiver::getClassDestructorName(){

     return this->ClassDestructorName;
}
