
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


#include "ParameterReader.h"

ParameterReader::ParameterReader(){

    this->MethodParameterTypes = nullptr;

    this->MethodParameterNames = nullptr;

    this->MethodParenthes = nullptr;

    this->Default_Empty_List_Size = 10;

    this->Memory_Delete_Condition = true;

    this->SyntaxError = false;
}

ParameterReader::ParameterReader(const ParameterReader & orig){ }

ParameterReader::~ParameterReader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void ParameterReader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         int List_Size = 0;

         if((this->getMethodParameterNumber() == 0) || (this->GetSyntaxErrorStatus())){

             List_Size = this->Default_Empty_List_Size;
         }
         else{

             List_Size = this->getMethodParameterNumber();
         }

         if(this->MethodParameterTypes != nullptr){

            for(int i=0;i<List_Size;i++){

                this->Clear_Pointer_Memory(&(this->MethodParameterTypes[i]));
            }

            delete [] this->MethodParameterTypes;

            this->MethodParameterTypes = nullptr;
         }

         if(this->MethodParameterNames != nullptr){

            for(int i=0;i<List_Size;i++){

                this->Clear_Pointer_Memory(&(this->MethodParameterNames[i]));
            }

            delete [] this->MethodParameterNames;

            this->MethodParameterNames = nullptr;
         }

         this->Clear_Pointer_Memory(&this->MethodParenthes);
      }
}

void ParameterReader::Read_Parameter_Informations(){

     this->Memory_Delete_Condition = false;

     this->DetermineMethodParameterTypes();

     this->DetermineMethodParameterNames();

     this->CharacterOperations.Clear_Dynamic_Memory();
}

void ParameterReader::DetermineMethodParameterTypes( ){

     if((this->getMethodParameterNumber() == 0) || (this->GetSyntaxErrorStatus())){

           // Syntax Error or there is no parameter

           int list_size = this->Default_Empty_List_Size;

           this->MethodParameterTypes = new char * [10*list_size];

           for(int i=0;i<list_size;i++){

               this->MethodParameterTypes[i] = new char [10*list_size];

               this->Place_Null_For_String_List(&(this->MethodParameterTypes[i]),list_size);
           }
     }
     else
     {
         this->MethodParameterTypes = new char * [10*(this->getMethodParameterNumber())];

         // this->MethodParameterTypes holds the adress of the pointer list. (Pointer which points a pointer list)
         // An area has been allocated for the pointer list which shows the paramters types

         int startPoint = 0, endPoint = 0;

         int MethodLength = this->CharacterOperations.CharListLength(this->MethodParenthes);

         if(this->getMethodParameterNumber() == 1){

               this->Determine_Is_there_a_parameter_name_in_the_case_of_single_parameter();

               if(!this->Is_there_a_parameter_name_in_the_case_of_single_parameter){

                   int length = this->CharacterOperations.CharListLength(this->MethodParenthes);

                   this->MethodParameterTypes[0] = new char [10*length];

                   for(int k=0;k<length;k++){

                       this->MethodParameterTypes[0][k] = this->MethodParenthes[k];
                   }

                   this->MethodParameterTypes[0][length] = '\0';

                   return;
               }

               endPoint   = this->FindThePreviousCharacterPosition(' ',MethodLength);
         }
         else
         {
               endPoint   = this->CharacterOperations.FindNextCharacterPositon(this->MethodParenthes,startPoint,',');

               endPoint   = this->FindThePreviousCharacterPosition(' ',endPoint);
         }

         int ListSize = endPoint - startPoint; // ListSize indicates the total character number for the method parameter types..

         for(int i=0;i< this->getMethodParameterNumber();i++){

             this->MethodParameterTypes[i] = new char [10*ListSize];

             for(int j=0;j<ListSize;j++){

                this->MethodParameterTypes[i][j] = this->MethodParenthes[startPoint+j];
             }

             this->MethodParameterTypes[i][ListSize] = '\0';


             if(i ==  this->getMethodParameterNumber()){

                break;
             }

             if(i == (this->getMethodParameterNumber()-1)){

                  startPoint = this->FindThePreviousCharacterPosition(',',MethodLength)+2;

                  endPoint   = MethodLength;

                  endPoint   = this->FindThePreviousCharacterPosition(' ',endPoint);
             }
             else
             {
                  startPoint = this->CharacterOperations.FindNextCharacterPositon(this->MethodParenthes,endPoint,',')+1;

                  endPoint   = this->CharacterOperations.FindNextCharacterPositon(this->MethodParenthes,startPoint,',');

                  endPoint   = this->FindThePreviousCharacterPosition(' ',endPoint);

                  startPoint = this->FindThePreviousCharacterPosition(',',endPoint)+2;
             }

             ListSize = endPoint - startPoint;
         };
     }
}

void ParameterReader::DetermineMethodParameterNames(){

     if((this->getMethodParameterNumber() == 0) || (this->GetSyntaxErrorStatus())){

            int list_size = this->Default_Empty_List_Size;

            this->MethodParameterNames = new char * [10*list_size];

            for(int i=0;i<list_size;i++){

                this->MethodParameterNames[i] = new char [10*list_size];

                this->Place_Null_For_String_List(&(this->MethodParameterNames[i]),list_size);
            }
     }
     else
     {

            this->MethodParameterNames = new char * [10*(this->getMethodParameterNumber())];

            int startPoint = 0 , endPoint = 0;

            if( this->getMethodParameterNumber()  == 1){

                 if(!this->Is_there_a_parameter_name_in_the_case_of_single_parameter){

                     int length = this->CharacterOperations.CharListLength(this->MethodParenthes);

                     this->MethodParameterNames[0] = new char [10*length];

                     for(int k=0;k<length;k++){

                           this->MethodParameterNames[0][k] = '\0';
                     }

                     return;
                 }

                 endPoint   = this->CharacterOperations.CharListLength(this->MethodParenthes);

                 startPoint = this->FindThePreviousCharacterPosition(' ',endPoint)+1;
            }
            else
            {
                    endPoint   = this->CharacterOperations.FindNextCharacterPositon(this->MethodParenthes,startPoint,',');

                    startPoint = this->FindThePreviousCharacterPosition(' ',endPoint)+1;
            }

            int ListSize = endPoint - startPoint;

            for(int i=0;i<this->getMethodParameterNumber();i++){

                if(ListSize == 0){

                   this->MethodParameterNames[i] = new char [10];

                   for(int k=0;k<10;k++){

                       this->MethodParameterNames[0][k] = '\0';
                   }
                }
                else{

                      this->MethodParameterNames[i] = new char [10*ListSize];

                      for(int j=0;j<ListSize;j++){

                          this->MethodParameterNames[i][j] = this->MethodParenthes[startPoint+j];
                      }

                      this->MethodParameterNames[i][ListSize] = '\0';
                }

                if(i ==  this->getMethodParameterNumber()){

                   break;
                }

                if(i == ( this->getMethodParameterNumber() - 1)){

                        endPoint = this->CharacterOperations.CharListLength(this->MethodParenthes);

                        startPoint = this->FindThePreviousCharacterPosition(' ',endPoint)+1;
                }
                else{
                        endPoint   = this->CharacterOperations.FindNextCharacterPositon(this->MethodParenthes,endPoint+1,',');

                        startPoint = this->FindThePreviousCharacterPosition(' ',endPoint)+1;
                }

                ListSize =  endPoint - startPoint;
            };
     }
}


int ParameterReader::FindThePreviousCharacterPosition(char Character,int startPoint){

    this->BackPointRemarker = startPoint;

    while((this->MethodParenthes[this->BackPointRemarker]!= Character) && (this->BackPointRemarker > 0)){

          this->BackPointRemarker--;
    }

    return this->BackPointRemarker;
}

void ParameterReader::SetMethodParenthes(char * Parenthes){

     if((this->getMethodParameterNumber() == 0) || (this->GetSyntaxErrorStatus())){

         int List_Size = 10;

         this->MethodParenthes = new char [10*List_Size];

         this->Place_Null_For_String_List(&(this->MethodParenthes),List_Size);
     }
     else{

          int List_Size = strlen(Parenthes);

          this->MethodParenthes = new char [10*List_Size];

          this->Place_String_List(&(this->MethodParenthes),Parenthes,List_Size);
     }
}

void ParameterReader::Determine_Is_there_a_parameter_name_in_the_case_of_single_parameter(){

     this->Is_there_a_parameter_name_in_the_case_of_single_parameter = false;

     bool is_there_a_space = false;

     int length = this->CharacterOperations.CharListLength(this->MethodParenthes);

     int space_position = length;

     for(int i=length;i>0;i--){

         if(this->MethodParenthes[i] == ' '){

            is_there_a_space = true;

            space_position = i;

            break;
         }
     }

     bool is_there_a_character_before_space = false;

     for(int i=space_position;i<length;i++){

         if(this->MethodParenthes[i] != ' '){

            if(((this->MethodParenthes[i] != '*') && (this->MethodParenthes[i] != '&'))){

               is_there_a_character_before_space = true;

               break;
            }
          }
     }

     if(is_there_a_space && is_there_a_character_before_space){

        this->Is_there_a_parameter_name_in_the_case_of_single_parameter = true;
     }
}

void ParameterReader::Place_String_List(char ** Pointer, char * String_List, int List_Size){

     for(int i=0;i<List_Size;i++){

          (*Pointer)[i] = String_List[i];
     }

     (*Pointer)[List_Size] = '\0';
}

void ParameterReader::Place_Null_For_String_List(char ** String_List, int size){

     for(int i=0;i<size;i++){

        (*String_List)[i] = '\0';
     }
}

void ParameterReader::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

char ** ParameterReader::GetMethodParameterTypes(){

        return this->MethodParameterTypes;
}

char ** ParameterReader::GetMethodParameterNames(){

        return this->MethodParameterNames;
}

void ParameterReader::SetMethodParameterNumber(int Number){

     this->MethodParameterNumber = Number;
}

int ParameterReader::getMethodParameterNumber(){

    return this->MethodParameterNumber;
}

void ParameterReader::SetSyntaxErrorStatus(bool Status){

     this->SyntaxError = Status;
}

bool ParameterReader::GetSyntaxErrorStatus(){

     return this->SyntaxError;
}
