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

#include "FindSetPoints.h"

FindSetPoints::FindSetPoints(){

    this->Memory_Delete_Condition    = true;

    this->is_There_Public_Methods    = false;

    this->is_There_Private_Methods   = false;

    this->is_There_Protected_Methods = false;

    this->AcessPointList = nullptr;

    this->PublicDeclerationArea    = 0;

    this->PrivateDeclerationArea   = 0;

    this->ProtectedDeclerationArea = 0;

    this->publicLineNumber = 0;

    this->privateLineNumber = 0;

    this->protectedLineNumber = 0;

    this->declerationEnd = 0;
}

FindSetPoints::FindSetPoints(const FindSetPoints & orig){ }

FindSetPoints::~FindSetPoints(){

    if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
    }
}

void FindSetPoints::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->AcessPointList != nullptr){

            delete [] this->AcessPointList;

            this->AcessPointList = nullptr;
         }

         this->is_There_Public_Methods    = false;

         this->is_There_Private_Methods   = false;

         this->is_There_Protected_Methods = false;

         this->PublicDeclerationArea    = 0;

         this->PrivateDeclerationArea   = 0;

         this->ProtectedDeclerationArea = 0;

         this->publicLineNumber = 0;

         this->privateLineNumber = 0;

         this->protectedLineNumber = 0;

         this->declerationEnd = 0;
     }
}

void FindSetPoints::DetermineSetPoints(char * TargetHeaderFile){

     this->Memory_Delete_Condition = false;

     this->ClsSynCntr.CheckClassSyntax(TargetHeaderFile);

     this->FileManager.SetFilePath(TargetHeaderFile);

     this->StringOperations.SetFilePath(TargetHeaderFile);

     if(!this->ClsSynCntr.GetClassSyntaxErrorStatus()){

           this->findDeclerationEnd();

           if(this->ClsSynCntr.isTherePublicKeyWord()){

                this->findPublicWordLine();
            }

           if(this->ClsSynCntr.isTherePrivateKeyWord()){

                this->findPrivateWordLine();
           }

           if(this->ClsSynCntr.isThereProtectedKeyWord()){

                this->findProtectedWordLine();
           }

           this->DetermineHowManyAccessTypesExist();

           if(this->ClsSynCntr.isTherePublicKeyWord()){

                this->findPublicDeclerationArea();
           }

           if(this->ClsSynCntr.isTherePrivateKeyWord()){

               this->findPrivateDeclerationArea();
           }

           if(this->ClsSynCntr.isThereProtectedKeyWord()){

               this->findProtectedDeclerationArea();
           }

           this->Control_Methods_Acess_Types_Error();

           this->Determine_Is_There_Any_Public_Method();

           this->Determine_Is_There_Any_Private_Method();

           this->Determine_Is_There_Any_Protected_Method();
     }

     this->FileManager.Clear_Dynamic_Memory();

     this->StringOperations.Clear_Dynamic_Memory();

     this->ClsSynCntr.Clear_Dynamic_Memory();
}

void FindSetPoints::findPublicWordLine(){

     int Search_Start_Point = 1;

     char Key_Word [] = {'p','u','b','l','i','c',':','\0'};

     this->publicLineNumber = this->StringOperations.FindNextWordLine(Key_Word,Search_Start_Point);
}

void FindSetPoints::findPrivateWordLine(){

     int Search_Start_Point = 1;

     char Key_Word [] = {'p','r','i','v','a','t','e',':','\0'};

     this->privateLineNumber = this->StringOperations.FindNextWordLine(Key_Word,Search_Start_Point);
}

void FindSetPoints::findProtectedWordLine(){

     int Search_Start_Point = 1;

     char Key_Word [] = {'p','r','o','t','e','c','t','e','d',':','\0'};

     this->protectedLineNumber = this->StringOperations.FindNextWordLine(Key_Word,Search_Start_Point);
}

void FindSetPoints::findDeclerationEnd(){

     this->declerationEnd = 0;

     this->FileManager.FileOpen(Rf);

     bool condition = false;

     char * pointer;

     do{

         pointer = this->FileManager.ReadLine_as_Cstring();

         int Line_Size = strlen(pointer);

         for(int i=0;i<Line_Size;i++){

             if(pointer[i] == '}'){

                condition = true;
             }
         }

         this->declerationEnd++;

         if(this->FileManager.Control_End_of_File()){

             break;
         }

    }while(!condition);

    this->FileManager.FileClose();
}

bool FindSetPoints::checkMethodLine(char * lineIndex){

     this->is_This_MethodLine = false;

     int List_Size = strlen(lineIndex);

     for(int i=0;i<List_Size;i++){

         if(lineIndex[i] == '('){

             this->is_This_MethodLine = true;
         }
     }

     return this->is_This_MethodLine;
}

void FindSetPoints::DetermineHowManyAccessTypesExist(){

     this->HowManyAcessTypesExist = 0;

     if(this->ClsSynCntr.isTherePublicKeyWord()){

          this->HowManyAcessTypesExist++;
     }

     if(this->ClsSynCntr.isTherePrivateKeyWord()){

          this->HowManyAcessTypesExist++;
     }

     if(this->ClsSynCntr.isThereProtectedKeyWord()){

          this->HowManyAcessTypesExist++;
     }

     this->AcessPointList = new int [10*(this->HowManyAcessTypesExist)];

     int counter = 0;

     if(this->ClsSynCntr.isTherePublicKeyWord()){

          this->AcessPointList[counter] = this->getPublicLineNumber();

          counter++;
     }

     if(this->ClsSynCntr.isTherePrivateKeyWord()){

          this->AcessPointList[counter] = this->getPrivateLineNumber();

          counter++;
     }

     if(this->ClsSynCntr.isThereProtectedKeyWord()){

          this->AcessPointList[counter] = this->getProtectedLineNumber();

          counter++;
     }

     this->AcessPointList[counter] = this->getDeclerationEnd();

     int buffer = 0;

     for(int i=0;i<this->HowManyAcessTypesExist;i++){

         for(int k=i;k<this->HowManyAcessTypesExist;k++){

             if(this->AcessPointList[i] > this->AcessPointList[k]){

                buffer = this->AcessPointList[i];

                this->AcessPointList[i] = this->AcessPointList[k];

                this->AcessPointList[k] = buffer;
             }
         }
     }
}

int FindSetPoints::SearchIntegerListIndex(int * integerList,int integerValue){

     this->indexNumber = 0;

     for(int i=0;i<this->HowManyAcessTypesExist;i++){

         if(integerList[i]== integerValue){

            this->indexNumber = i;
         }
     }

     return this->indexNumber;
}

void FindSetPoints::findPublicDeclerationArea(){

     int index_number = this->SearchIntegerListIndex(this->AcessPointList,this->getPublicLineNumber());

     this->PublicDeclerationArea = this->AcessPointList[index_number+1] - this->AcessPointList[index_number]-1;
}

void FindSetPoints::findPrivateDeclerationArea(){

     int index_number = this->SearchIntegerListIndex(this->AcessPointList,this->getPrivateLineNumber());

     this->PrivateDeclerationArea = this->AcessPointList[index_number+1] - this->AcessPointList[index_number]-1;
}

void FindSetPoints::findProtectedDeclerationArea(){

     int index_number = this->SearchIntegerListIndex(this->AcessPointList,this->getProtectedLineNumber());

     this->ProtectedDeclerationArea = this->AcessPointList[index_number+1] - this->AcessPointList[index_number]-1;
}

void FindSetPoints::Control_Methods_Acess_Types_Error(){

     this->AcessTypesError = false;

     this->FileManager.FileOpen(Rf);

     char * linePointer;

     int lineNumber = 0;

     int FirstAcessTypeLine = 0;

     for(int i=0;i<this->HowManyAcessTypesExist;i++){

         if(this->AcessPointList[i]!=0){

            FirstAcessTypeLine = this->AcessPointList[0];

            break;
         }
     }

     do{

        linePointer = this->FileManager.ReadLine_as_Cstring();

        if(this->FileManager.Control_End_of_File()){

           break;
        }

        lineNumber++;

        if(this->checkMethodLine(linePointer)){

            if(lineNumber < FirstAcessTypeLine){

                  this->AcessTypesError = true;
            }
        }

     }while(this->getDeclerationEnd() > lineNumber);

     this->FileManager.FileClose();
}

void FindSetPoints::Determine_Is_There_Any_Public_Method(){

     this->is_There_Public_Methods = false;

     if(this->ClsSynCntr.isTherePublicKeyWord() && (this->PublicDeclerationArea > 0)){

        int Search_Start_Point = this->getPublicLineNumber();

        for(int i=Search_Start_Point;i<Search_Start_Point+this->PublicDeclerationArea;i++){

            this->StringOperations.ReadFileLine(i);

            if(this->checkMethodLine(this->StringOperations.GetStringBuffer())){

               this->is_There_Public_Methods = true;
            }
         }
     }
}

void FindSetPoints::Determine_Is_There_Any_Private_Method(){

     this->is_There_Private_Methods = false;

     if(this->ClsSynCntr.isTherePrivateKeyWord() && (this->PrivateDeclerationArea > 0)){

        int Search_Start_Point = this->getPrivateLineNumber();

        for(int i=Search_Start_Point;i< Search_Start_Point+ this->PrivateDeclerationArea;i++){

            this->StringOperations.ReadFileLine(i);

            if(this->checkMethodLine(this->StringOperations.GetStringBuffer())){

               this->is_There_Private_Methods = true;
            }
         }
     }
}

void FindSetPoints::Determine_Is_There_Any_Protected_Method(){

     this->is_There_Protected_Methods = false;

     if(this->ClsSynCntr.isThereProtectedKeyWord() && (this->ProtectedDeclerationArea > 0)){

        int Search_Start_Point = this->getProtectedLineNumber();

        for(int i=Search_Start_Point;i< Search_Start_Point + this->ProtectedDeclerationArea;i++){

            this->StringOperations.ReadFileLine(i);

            if(this->checkMethodLine(this->StringOperations.GetStringBuffer())){

               this->is_There_Protected_Methods = true;
            }
        }
     }
}

bool FindSetPoints::getAcessTypesError(){

     return this->AcessTypesError;
}

int FindSetPoints::getPublicDeclerationArea(){

    return this->PublicDeclerationArea;
}

int FindSetPoints::getPrivateDeclerationArea(){

    return this->PrivateDeclerationArea;
}

int FindSetPoints::getProtectedDeclerationArea(){

    return this->ProtectedDeclerationArea;
}

int FindSetPoints::getPublicLineNumber(){

    return this->publicLineNumber;
}

int FindSetPoints::getPrivateLineNumber(){

    return this->privateLineNumber;
}

int FindSetPoints::getProtectedLineNumber(){

    return this->protectedLineNumber;
}

int FindSetPoints::getDeclerationEnd(){

    return this->declerationEnd;
}

bool FindSetPoints::isTherePublicMethod(){

     return this->is_There_Public_Methods;
}

bool FindSetPoints::isTherePrivateMethod(){

    return this->is_There_Private_Methods;
}

bool FindSetPoints::isThereProtectedMethod(){

    return this->is_There_Protected_Methods;
}
