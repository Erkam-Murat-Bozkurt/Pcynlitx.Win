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

#include "SyntaxController.h"

SyntaxController::SyntaxController(){

    this->Memory_Delete_Condition = true;

    this->ClassContructorName = nullptr;

    this->ClassDestructorName = nullptr;

    this->MethodLine = nullptr;
}

SyntaxController::SyntaxController(const SyntaxController & orig){

}

SyntaxController::~SyntaxController(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
}

void SyntaxController::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(!this->getSyntaxErrorCondition()){

             this->Clear_Pointer_Memory(&this->MethodLine);

             this->Clear_Pointer_Memory(&this->ClassContructorName);

             this->Clear_Pointer_Memory(&this->ClassDestructorName);
         }
     }
}

void SyntaxController::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void SyntaxController::ReceiveClassContructorName(char * constructorName){

     this->MethodInitializer.setClassContructorName(constructorName);
}

void SyntaxController::ReceiveMethod(char * Method){

     this->Memory_Delete_Condition = false;

     this->setSyntaxErrorCondition(false);

     this->MethodInitializer.setMethodProcessorErrorCondition(false);

     this->MethodInitializer.ReceiveMethod(Method);

     this->MethodInitializer.CollectInformation();

     this->setSyntaxErrorCondition(this->MethodInitializer.getMethodProcessorErrorCondition());

     if(this->getSyntaxErrorCondition()){

          int Name_Size = 10;

          this->ClassContructorName = new char [10*Name_Size];

          this->ClassDestructorName = new char [10*Name_Size];

          this->MethodLine = new char [10*Name_Size];

          this->Place_Null(&this->ClassContructorName,Name_Size);

          this->Place_Null(&this->ClassDestructorName,Name_Size);

          this->Place_Null(&this->MethodLine,Name_Size);
     }
     else{

          int Constructor_Name_Size = strlen(this->MethodInitializer.getClassContructorName());

          int Destructor_Name_Size  = strlen(this->MethodInitializer.getClassDestructorName());

          this->ClassContructorName = new char [10*Constructor_Name_Size];

          this->ClassDestructorName = new char [10*Destructor_Name_Size];

          this->Place_Null(&this->ClassContructorName,10*Constructor_Name_Size);

          this->Place_Null(&this->ClassDestructorName,10*Destructor_Name_Size);

          this->Place_String(&this->ClassContructorName,this->MethodInitializer.getClassContructorName(),Constructor_Name_Size);

          this->Place_String(&this->ClassDestructorName,this->MethodInitializer.getClassDestructorName(),Destructor_Name_Size);

          this->setFirstBraceExistance(this->MethodInitializer.getFirstBraceExistance());

          this->setLastBraceExistance(this->MethodInitializer.getLastBraceExistance());

          this->setFirstBracePosition(this->MethodInitializer.getFirstBracePosition());

          this->setLastBracePosition(this->MethodInitializer.getLastBracePosition());

          this->setMethodParameterNumber(this->MethodInitializer.getMethodParameterNumber());

          this->setClassConstructorStatus(this->MethodInitializer.getClassConstructorStatus());

          this->setClassDestructorStatus(this->MethodInitializer.getClassDestructorStatus());

          int MethodLength = strlen(this->MethodInitializer.getMethodLine());

          this->MethodLine = new char [10*MethodLength];

          this->Place_Null(&this->MethodLine,10*MethodLength);

          for(int i=0;i<MethodLength;i++){

             this->MethodLine[i] = this->MethodInitializer.getMethodLine()[i];

             if(this->MethodLine[i]=='\n'){

                this->MethodLine[i]= '\0';
             }
          }

          this->MethodLine[MethodLength]= '\0';
     }
}

void SyntaxController::CheckMethodSyntax(){

     if(!this->getSyntaxErrorCondition()){

         this->checkFirstSpace();

         this->checkMethodName();

         this->checkParameterSyntax();

         this->checkEndComma();
     }

     this->MethodInitializer.Clear_Dynamic_Memory();

     this->CharacterOperations.Clear_Dynamic_Memory();
}

void SyntaxController::checkFirstSpace(){

     bool FistSpaceExistanceCondition = false;

     if((!this->getClassConstructorStatus()) && (!this->getClassDestructorStatus())){

         if((this->getFirstBraceExistance()) && (this->MethodLine[0]!=' ')){

              for(int i = 0;i<this->getFirstBracePosition();i++){

                   if(this->MethodLine[i]==' '){

                       FistSpaceExistanceCondition = true;
                   }
              }
         }

         if(!FistSpaceExistanceCondition){

              this->setSyntaxErrorCondition(true);
         }
     }
}

void SyntaxController::checkParameterSyntax(){

     int firstCharacterPositionInParenthes = this->getFirstBracePosition()+1;

     int lastCharacterPositionInParenthes  = this->getLastBracePosition()-1;

     int searcher = firstCharacterPositionInParenthes;

     int spaceRepitation = 0;

     if(this->MethodLine[firstCharacterPositionInParenthes]==','){

         this->setSyntaxErrorCondition(true);
     }

     if(this->MethodLine[lastCharacterPositionInParenthes]== ','){

         this->setSyntaxErrorCondition(true);
     }

     if(this->getMethodParameterNumber() > 1){

        while(this->MethodLine[searcher]!=','){

              if(this->MethodLine[searcher]==' '){

                 spaceRepitation++;
              }

              searcher++;
        }

        if(spaceRepitation < 1){

               this->setSyntaxErrorCondition(true);
        }

        if(this->MethodLine[searcher]==','){

           searcher++;
        }

        spaceRepitation = 0;

        do{

            while(this->MethodLine[searcher]!=','){

                  if(searcher>this->getLastBracePosition()){

                    break;
                  }

                  if(this->MethodLine[searcher]==' '){

                     spaceRepitation++;
                  }

                  searcher++;
            }

            if(spaceRepitation < 2){

               this->setSyntaxErrorCondition(true);
            }

            spaceRepitation = 0;

            searcher++;

        }
        while(searcher < this->getLastBracePosition());
      }

      int TotalCommaNumber = this->CharacterOperations.DetermineCharacterRepitation(this->MethodLine,',');

      int NextCharacterPosition = 0;

      for(int i=0;i<TotalCommaNumber;i++){

          NextCharacterPosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,NextCharacterPosition,',');

          if((this->MethodLine[NextCharacterPosition-1]== '*') || (this->MethodLine[NextCharacterPosition-1]== '&') ){

             this->setSyntaxErrorCondition(true);
          }
      }
}

void SyntaxController::checkMethodName(){

     if(this->MethodLine[this->getFirstBracePosition()-1] == ' '){

         this->setSyntaxErrorCondition(true);
     }
}

void SyntaxController::checkEndComma(){

     this->isEndCommaExist = false;

     int Comma_Number = this->CharacterOperations.DetermineCharacterRepitation(this->MethodLine,';');

     if(Comma_Number > 1){

        this->setSyntaxErrorCondition(true);
     }
     else{

          int LastBracePosition = this->getLastBracePosition();

          int Method_Line_Size = this->CharacterOperations.CharListLength(this->MethodLine);

          for(int i=LastBracePosition;i<=Method_Line_Size;i++){

              if(this->MethodLine[i] == ';'){

                 this->isEndCommaExist = true;

                 break;
              }
          }

          if(!this->isEndCommaExist){

             this->setSyntaxErrorCondition(true);
          }
     }
}

void SyntaxController::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void SyntaxController::Place_Null(char ** Pointer, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = '\0';
     }
}


bool SyntaxController::getEndCommaExistance(){

     return this->isEndCommaExist;
}

void SyntaxController::setClassConstructorStatus(bool status){

     this->isThisClassConstructor = status;
}

bool SyntaxController::getClassConstructorStatus(){

     return this->isThisClassConstructor;
}

void SyntaxController::setClassDestructorStatus(bool status){

     this->isThisClassDestructor = status;
}

bool SyntaxController::getClassDestructorStatus(){

     return this->isThisClassDestructor;
}

void SyntaxController::setFirstBraceExistance(bool status){

     this->isFirstBraceExist = status;
}

void SyntaxController::setLastBraceExistance(bool status){

     this->isLastBraceExist = status;
}

void SyntaxController::setFirstBracePosition(int position){

     this->FirstBracePosition = position;
}

void SyntaxController::setLastBracePosition(int position){

     this->LastBracePosition = position;
}

void SyntaxController::setMethodParameterNumber(int parameterNumber){

     this->MethodParameterNumber = parameterNumber;
}

void SyntaxController::setSyntaxErrorCondition(bool condition){

     this->SyntaxErrorCondition = condition;
}

bool SyntaxController::getSyntaxErrorCondition(){

     return this->SyntaxErrorCondition;
}

int SyntaxController::getFirstBracePosition(){

    return this->FirstBracePosition;
}

int SyntaxController::getLastBracePosition(){

    return this->LastBracePosition;
}

bool SyntaxController::getFirstBraceExistance(){

     return this->isFirstBraceExist;
}

bool SyntaxController::getLastBraceExistance(){

     return this->isLastBraceExist;
}

int SyntaxController::getMethodParameterNumber(){

    return this->MethodParameterNumber;
}

char * SyntaxController::getMethodLine(){

       return this->MethodLine;
}

char * SyntaxController::getClassConstructorName(){

       return this->ClassContructorName;
}

char * SyntaxController::getClassDestructorName(){

      return this->ClassDestructorName;
}
