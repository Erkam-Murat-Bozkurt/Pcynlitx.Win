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

#include "MethodProcessor.h"

MethodProcessor::MethodProcessor(){

     this->MethodProcessorErrorCondition = false;

     this->isClassConstructor = false;

     this->isClassDestructor  = false;

     this->FirstBracePosition = 0;

     this->LastBracePosition = 0;

     this->Memory_Delete_Condition = true;

     this->MethodLine = nullptr;

     this->MethodName = nullptr;

     this->ClassConstructorName = nullptr;

     this->ClassDestructorName = nullptr;

     this->ReturnType = nullptr;

     this->isThereReturnType = false;
}

MethodProcessor::MethodProcessor(const MethodProcessor & orig){}

MethodProcessor::~MethodProcessor(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void MethodProcessor::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->MethodLine);

         this->Clear_Pointer_Memory(&this->MethodName);

         this->Clear_Pointer_Memory(&this->ClassConstructorName);

         this->Clear_Pointer_Memory(&this->ClassDestructorName);

         if(this->isThereReturnType){

            this->Clear_Pointer_Memory(&this->ReturnType);
         }
     }
}

void MethodProcessor::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] *Pointer;

        *Pointer = nullptr;
     }
}

void MethodProcessor::ReceiveMethod(char * Method){

     this->Initializer.setMethodInitializerErrorCondition(false);

     this->Initializer.ReceiveMethod(Method);

     this->Initializer.ProcessMethodInformation();

     int MethodSize = this->CharacterOperations.CharListLength(this->Initializer.getMethodLine());

     this->MethodLine = new char [10*MethodSize];

     for(int i=0;i<MethodSize;i++){

         this->MethodLine[i] = this->Initializer.getMethodLine()[i];
     }

     this->MethodLine[MethodSize] = '\0';
}

void MethodProcessor::CollectInformation(){

     this->isClassConstructor = false;

     this->isClassDestructor  = false;

     this->Memory_Delete_Condition = false;

     this->setMethodProcessorErrorCondition(false);

     if(this->Initializer.getMethodInitializerErrorCondition()){

            this->setMethodProcessorErrorCondition(true);
     }
     else{
            this->FindFirstBracePosition();

            this->FindLastBracePosition();

            this->DetermineMethodName();

            if(!this->getMethodProcessorErrorCondition()){

                this->DetermineMethodParameterNumber();

                this->checkClassContructorMatching();

                this->checkClassDestructorMatching();
            }
     }

     if((this->getClassConstructorStatus()) && (this->isThereReturnType)){

         this->setMethodProcessorErrorCondition(true);
     }

     if((this->getClassDestructorStatus()) && (this->isThereReturnType)){

         char virtual_word [] = {'v','i','r','t','u','a','l','\0'};

         if(this->CharacterOperations.CompareString(this->ReturnType,virtual_word)){

              this->setMethodProcessorErrorCondition(true);
         }
     }

     this->First_Brace_Existance = this->Initializer.getFirstBraceExistance();

     this->Last_Brace_Existance  = this->Initializer.getLastBraceExistance();

     this->Initializer.Clear_Dynamic_Memory();

     this->CharacterOperations.Clear_Dynamic_Memory();
}

void MethodProcessor::FindFirstBracePosition(){

     this->FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');
}

void MethodProcessor::FindLastBracePosition(){

     this->LastBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,')');
}

void MethodProcessor::setClassContructorName(char * name){

     int NameSize = this->CharacterOperations.CharListLength(name);

     this->ClassConstructorName = new char [10*NameSize];

     for(int i=0;i<NameSize;i++){

        this->ClassConstructorName[i] = name[i];

        if(this->ClassConstructorName[i] == ' '){

            this->ClassConstructorName[i] = '\0';
        }
     }

     this->ClassConstructorName[NameSize] = '\0';

     this->ClassDestructorName = new char [10*NameSize+1];

     this->ClassDestructorName[0] = '~';

     for(int i=1;i<NameSize+1;i++){

         this->ClassDestructorName[i]=name[i-1];

         if(this->ClassDestructorName[i] == ' '){

             this->ClassDestructorName[i] = '\0';
         }
     }

     this->ClassDestructorName[NameSize+1] = '\0';
}

void MethodProcessor::DetermineMethodName(){

     int FirstBracePosition = this->getFirstBracePosition();

     int SpaceNumber = this->Initializer.HowManySpaces(this->MethodLine,0,FirstBracePosition);

     this->isThereReturnType = false;

     if(SpaceNumber>=1){

         this->isThereReturnType = true;

         int position_searcher = 0;

         while(this->MethodLine[FirstBracePosition - position_searcher-1] != ' '){

              position_searcher++;
         }

         this->MethodName = new char [10*position_searcher];

         int MethodName_StartPoint = FirstBracePosition - position_searcher;

         for(int i=0;i<position_searcher;i++){

             this->MethodName[i] = this->MethodLine[i+MethodName_StartPoint];
         }

         this->MethodName[position_searcher] = '\0';

         this->ReturnType = new char [10*MethodName_StartPoint];

         for(int i=0;i<MethodName_StartPoint;i++){

             this->ReturnType[i] = this->MethodLine[i];
         }

         this->ReturnType[MethodName_StartPoint] = '\0';
     }
     else{

         this->isThereReturnType = false;

         int MemoryNeed = FirstBracePosition;

         this->MethodName = new char [10*MemoryNeed];

         for(int i=0;i<MemoryNeed;i++){

             this->MethodName[i] = this->MethodLine[i];
         }

         this->MethodName[MemoryNeed] = '\0';
     }
}


void MethodProcessor::checkClassContructorMatching(){

     if(this->CharacterOperations.CompareString(this->getClassContructorName(),this->getMethodName())){

         this->isClassConstructor = true;
     }
}

void MethodProcessor::checkClassDestructorMatching(){

     if(this->CharacterOperations.CompareString(this->getClassDestructorName(),this->getMethodName())){

        this->isClassDestructor = true;
     }
}

void MethodProcessor::DetermineMethodParameterNumber(){

     this->MethodParameterNumber = 0;

     int commaNumber = this->CharacterOperations.DetermineCharacterRepitation(this->MethodLine,',');

     int FirstBrace = this->getFirstBracePosition();

     int LastBrace  = this->getLastBracePosition();

     int spaceSize  = LastBrace - FirstBrace;

     if(commaNumber !=0){

        this->MethodParameterNumber = commaNumber+1;
     }
     else
     {
        if(spaceSize == 0){

           this->MethodParameterNumber = 0;
        }
        else
        {
           for(int i=0;i<spaceSize-1;i++){

               if(this->MethodLine[i+FirstBrace+1]!= ' '){

                  this->MethodParameterNumber = 1;

                  break;
               }
               else
               {
                  this->MethodParameterNumber = 0;
               }
           }
         }
     }
}

int MethodProcessor::getFirstBracePosition(){

    return this->FirstBracePosition;
}

int MethodProcessor::getLastBracePosition(){

    return this->LastBracePosition;
}

int MethodProcessor::getMethodParameterNumber(){

    return this->MethodParameterNumber;
}

bool MethodProcessor::getClassConstructorStatus(){

     return this->isClassConstructor;
}

bool MethodProcessor::getClassDestructorStatus(){

     return this->isClassDestructor;
}

bool MethodProcessor::getFirstBraceExistance(){

     return this->First_Brace_Existance;
}

bool MethodProcessor::getLastBraceExistance(){

     return this->Last_Brace_Existance;
}


char * MethodProcessor::getClassContructorName(){

       return this->ClassConstructorName;
}

char * MethodProcessor::getClassDestructorName(){

       return this->ClassDestructorName;
}

char * MethodProcessor::getMethodLine(){

       return this->MethodLine;
}

bool MethodProcessor::getMethodProcessorErrorCondition(){

     return this->MethodProcessorErrorCondition;
}

void MethodProcessor::setMethodProcessorErrorCondition(bool condition){

     this->MethodProcessorErrorCondition = condition;
}

char * MethodProcessor::getMethodName(){

       return this->MethodName;
}
