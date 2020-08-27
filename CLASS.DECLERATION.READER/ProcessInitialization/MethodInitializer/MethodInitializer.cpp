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

#include "MethodInitializer.h"

MethodInitializer::MethodInitializer(){

    this->isFirstBraceExist = false;

    this->isLastBraceExist = false;

    this->setMethodInitializerErrorCondition(false);

    this->Memory_Delete_Condition = true;

    this->MethodLine = nullptr;
}

MethodInitializer::MethodInitializer(const MethodInitializer & orig){

}

MethodInitializer::~MethodInitializer(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void MethodInitializer::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->MethodLine != nullptr){

            delete [] this->MethodLine;

            this->MethodLine = nullptr;
         }
     }
}

void MethodInitializer::ReceiveMethod(char * Method_Pointer){

     int MethodSize = strlen(Method_Pointer);

     this->MethodLine = new char [10*MethodSize];

     for(int i=0;i<10*MethodSize;i++){

         this->MethodLine[i] = '\0';
     }

     for(int i=0;i<MethodSize;i++){

         this->MethodLine[i] = Method_Pointer[i];
     }

     this->MethodLine[MethodSize] = '\0';
}

void MethodInitializer::ProcessMethodInformation(){

     this->Memory_Delete_Condition = false;

     this->isFirstBraceExist = false;

     this->isLastBraceExist = false;

     this->setMethodInitializerErrorCondition(false);

     this->CheckFirstBrace_Existance();

     if(!this->getFirstBraceExistance()){

         this->setMethodInitializerErrorCondition(true);
     }
     else{

          this->CheckLastBrace_Existance();

          if(!this->getLastBraceExistance()){

              this->setMethodInitializerErrorCondition(true);
          }
          else{

                this->CheckMethodName_Existance();

                if(!this->getMethodNameExistance()){

                    this->setMethodInitializerErrorCondition(true);
                }
                else{

                    this->Delete_Spaces_Before_MethodName();

                    this->SpaceCancelProcess();

                    this->CheckSpaceNumberBeforeFirstBrace();

                    this->CheckAdressCharacterBeforeFirstBrace();

                    this->CheckAdressCharacterInsidePharentheses();

                    this->AddSpaceAfterComma();
                }
          }
     }

     this->CharacterOperations.Clear_Dynamic_Memory();
}

void MethodInitializer::CheckFirstBrace_Existance(){

     for(int i=0;i<strlen(this->MethodLine);i++){

         if(this->MethodLine[i]== '('){

            this->isFirstBraceExist = true;
         }
     }
}

void MethodInitializer::CheckLastBrace_Existance(){

     for(int i=0;i<strlen(this->MethodLine);i++){

         if(this->MethodLine[i]== ')'){

            this->isLastBraceExist = true;
         }
     }
}

void MethodInitializer::CheckMethodName_Existance(){

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     int FirstCharacterPosition = 0;

     while(this->MethodLine[FirstCharacterPosition] == ' '){

          FirstCharacterPosition++;
     }

     if(FirstBracePosition == FirstCharacterPosition){

         this->isMethodNameExist = false;

         this->setMethodInitializerErrorCondition(true);
     }
     else{

          this->isMethodNameExist = true;
     }
}

void MethodInitializer::RemoveSpaces(char * MethodLine,int spaceNumber,int startPoint){

     if(spaceNumber<=0){

        return;
     }
     else{
           int MethodLength = strlen(this->MethodLine);

           for(int i= startPoint;i<MethodLength;i++){

               this->MethodLine[i]= this->MethodLine[i+spaceNumber];
           }
     }
}

int MethodInitializer::SpaceCounter(char * MethodLine,int startPoint){

    this->SpaceNumber = 0;  // RESET TOTAL SPACE COUNT

    if(MethodLine[startPoint]!= ' '){

        return this->SpaceNumber;
    }
    else{
            while(MethodLine[startPoint + this->SpaceNumber] == ' '){

                  this->SpaceNumber++;
            }

            return  this->SpaceNumber;
    }
}

int MethodInitializer::HowManySpaces(char * MethodLine,int startPoint,int endPoint){

    this->HowManySeperateSpaces = 0;

    int SpacePoint = 0, CharacterPoint = 0;

    for(int i=startPoint;i<=endPoint;i++){

        if(MethodLine[i]== ' '){

           SpacePoint++;

           do{

              i++;

           }while((MethodLine[i]== ' ') && (i<=endPoint));

        }

        if(MethodLine[i]!=' '){

           CharacterPoint++;

           do{

              i++;

           }while((MethodLine[i]!= ' ') && (i<=endPoint));

           i--;
        }

        if((SpacePoint>0) && (CharacterPoint>0)){

            this->HowManySeperateSpaces++;

            SpacePoint = 0;

            CharacterPoint = 0;
        }

    }

    return this->HowManySeperateSpaces;
}

void MethodInitializer::SpaceCancelProcess(){

     int FirstSpacePoint, SecondSpacePoint;

     int spaceCounter = 0;

     // FOLLOWING LINES OF CODES REMOVES THE POSSIBLE SPACES BETWEEN METHOD START POINT AND RETURN TYPE

     if(this->MethodLine[0] == ' '){

         spaceCounter = this->SpaceCounter(this->MethodLine,0);
     }

     this->RemoveSpaces(this->MethodLine,spaceCounter,0);   // REMOVE SPACES BEFORE RETURN TYPE

     // FOLLOWING LINES OF CODES DETERMINES HOW MANY SEPERATE SPACES ARE THERE BETWEEN THE START AND FIRST BRACE

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     int SeperateSpaceNumber = this->HowManySpaces(this->MethodLine,0,FirstBracePosition);  // COMPUTES SEPERATE SPACE NUMBER BETWEEN START AND METHOD FIRST BRACE

     int SpaceNumber = this->CharacterOperations.DetermineCharacterRepitation(this->MethodLine,' ');  // COMPUTES TOTAL SPACE NUMBER BETWEEB START AND FIRST BRACE

     if(SpaceNumber<=1){    // If there is no more than one space, there may be three possible structure for the method signature
                            // The first is that there is only one spaces between return type and method name --> ReturnType FunctionName();
        return;             // The secons is that there is only one spaces between braces --> FunctionName( );
     }                      // The third one is that there is no space -- > FunctionName();  For all these condition there is no need any operations on the method.

     if(SeperateSpaceNumber>1){

          // FOLLOWING LINES OF CODES REMOVES THE SPACES BETWEEN RETURN TYPE AND METHOD NAMES (AT THE END OF PROCESS ,ONE SPACE WILL REMAIN)

          FirstSpacePoint = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,' ');

          spaceCounter = this->SpaceCounter(this->MethodLine,FirstSpacePoint); // SPACE COUNT FOR THE FIRST SPACE WHERE IS LOCATED BETWEEN RETURN TYPE AND METHOD NAME

          this->RemoveSpaces(this->MethodLine,spaceCounter-1,FirstSpacePoint); // A ONE SPACE MUST REMAIN BETWEEN RETURN TYPE AND METHOD NAME

          SecondSpacePoint = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,FirstSpacePoint,' ');

          // FOLLOWING LINES OF CODES REMOVES THE SPACES BETWEEN METHOD NAME AND FIRST PHARENTHES BRACE

          FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'('); // UPDATE FIRST BRACE POINT

          spaceCounter = this->SpaceCounter(this->MethodLine,SecondSpacePoint);

          this->RemoveSpaces(this->MethodLine,spaceCounter,SecondSpacePoint);  // REMOVE SPACES BETWEEN METHOD NAME AND FIRST BRACE
     }
     else{
            FirstSpacePoint = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,' ');

            spaceCounter = this->SpaceCounter(this->MethodLine,FirstSpacePoint); // SPACE COUNT FOR THE FIRST SPACE WHERE IS LOCATED BETWEEN RETURN TYPE AND METHOD NAME

            if(this->MethodLine[FirstBracePosition-1] != ' '){

               // THE CONDITION STATES THAT THERE IS ONLY ONE SPACE LOCATION AND IT IS LOCATED BETWEEN RETURN TYPE ANS METHOD NAME

               // MEMBER FUNCTION REMOVES THE SPACES BETWEEN RETURN TYPE AND METHOD NAMES

               this->RemoveSpaces(this->MethodLine,spaceCounter-1,FirstSpacePoint); // A ONE SPACE MUST REMAIN BETWEEN RETURN TYPE AND METHOD NAME
            }
            else{

              // THE CONDITION STATES THAT THERE IS ONLY ONE SPACE LOCATION AND IT IS LOCATED BETWEEN METHOD NAME AND FIRST BRACE

              // MEMBER FUNCTION REMOVES THE SPACES BETWEEN RETURN TYPE AND METHOD NAMES

               this->RemoveSpaces(this->MethodLine,spaceCounter,FirstSpacePoint); // SPACE MUST NOT REMAIN BETWEEN METHOD NAME AND FIRST BRACE
            }
     }

    // FOLLOWING LINES OF CODES REMOVES SPACES JUST AFTER THE FIRST BRACE IN THE METHOD PHARENTHES

    int MethodLength  = this->CharacterOperations.CharListLength(this->MethodLine);

    FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');  // UPDATE FIRST BRACE POSITION

    if(this->MethodLine[FirstBracePosition+1] == ' '){

        spaceCounter = this->SpaceCounter(this->MethodLine,FirstBracePosition+1);

        this->RemoveSpaces(this->MethodLine,spaceCounter,FirstBracePosition+1);

    }

    // FOLLOWING LINES OF CODES REMOVES THE SPACES BETWEEN METHOD PHARENTHES

    int loopCounter = FirstBracePosition;

    do{
           if(this->MethodLine[loopCounter] == ' '){

               spaceCounter = 0;

               spaceCounter = this->SpaceCounter(this->MethodLine,loopCounter);

               this->RemoveSpaces(this->MethodLine,spaceCounter-1,loopCounter);
           }

          loopCounter++;

    }while(loopCounter<MethodLength);

    // FOLLOWING LINES OF CODES REMOVES SPACES BEFORE EACH COMMA IN THE METHOD PHARENTHES

    loopCounter=0;

    do{
           if(this->MethodLine[loopCounter] == ','){

               spaceCounter = 0;

               spaceCounter = this->SpaceCounter(this->MethodLine,loopCounter-1);

               this->RemoveSpaces(this->MethodLine,spaceCounter,loopCounter-1);
           }

          loopCounter++;

    }while(loopCounter<MethodLength);

     // FOLLOWING LINES OD CODES REMOVES SPACES JUST BEFORE LAST BRACE

    int LastBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,')');

    if(this->MethodLine[LastBracePosition-1] == ' '){

        this->RemoveSpaces(this->MethodLine,1,LastBracePosition-1);
    }

    // UPDATE LAST BRACE POSITION

    LastBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,')');

    bool is_there_a_comma_in_method_line = false;

    for(int i=0;i<MethodLength;i++){

        if(this->MethodLine[i] == ';'){

           is_there_a_comma_in_method_line = true;
        }
    }

    if(!is_there_a_comma_in_method_line){

        this->setMethodInitializerErrorCondition(true);
    }

    bool is_there_a_comma_at_the_end_of_the_line = false;

    for(int i=LastBracePosition;i<MethodLength;i++){

        if(this->MethodLine[i]== ';'){

           is_there_a_comma_at_the_end_of_the_line = true;
        }
    }

    if(!is_there_a_comma_at_the_end_of_the_line){

        this->setMethodInitializerErrorCondition(true);
    }
    else{
          // PLACE A COMMA AFTER LASTBRACE

          this->MethodLine[LastBracePosition+1] = ';';

          // PLACE NULL CHARACTER REST OF THE CHRACTER LIST
    }

    for(int i=LastBracePosition+2;i<MethodLength+1;i++){

         this->MethodLine[i] = '\0';
    }
}

void MethodInitializer::AddSpaceAfterComma(){

     int LineSize = strlen(this->MethodLine);

     for(int i=0;i<LineSize;i++){

         if(this->MethodLine[i] == ','){

            if(this->MethodLine[i+1] != ' '){

               for(int k=LineSize+1;k>i;k--){

                   this->MethodLine[k+1] = this->MethodLine[k];
               }

               this->MethodLine[i+1] = ' ';

               LineSize = this->CharacterOperations.CharListLength(this->MethodLine);
            }
         }
     }
}


void MethodInitializer::Delete_Spaces_Before_MethodName(){

     int listSize = strlen(this->MethodLine);

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     int loopCounter = 0;

     while(this->MethodLine[FirstBracePosition-loopCounter]!= ' '){

         loopCounter++;

         if((FirstBracePosition-loopCounter) == 0){

            return;
         }
     }

     int FirstSpacePointBeforeMethodName = FirstBracePosition - loopCounter;

     int Space_Counter = 0;

     if(FirstSpacePointBeforeMethodName > 0){

         while(this->MethodLine[FirstSpacePointBeforeMethodName - Space_Counter] == ' '){

               Space_Counter++;

               if((FirstSpacePointBeforeMethodName - Space_Counter) == 0){

                   break;
               }
         }
     }

     if(Space_Counter > 1){

        int Start_Point = FirstSpacePointBeforeMethodName - Space_Counter + 1;

        int Step_Size = Space_Counter - 1;

        int List_Size = strlen(this->MethodLine);

        for(int i= Start_Point; i< List_Size - Step_Size;i++){

            this->MethodLine[i] = this->MethodLine[i+Step_Size];
        }

        this->MethodLine[(List_Size - Step_Size)] = '\0';
     }
}

void MethodInitializer::CheckSpaceNumberBeforeFirstBrace(){

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     int FirstCharacterPosition = 0;

     while(this->MethodLine[FirstCharacterPosition]==' '){

           FirstCharacterPosition++;
     }

     int HowManySpacesAreThere = this->HowManySpaces(this->MethodLine,FirstCharacterPosition,FirstBracePosition);

     if(this->MethodLine[FirstBracePosition-1] == ' '){

         if(HowManySpacesAreThere>4){  // const char * method

            this->setMethodInitializerErrorCondition(true);
         }
     }
     else{

         if(HowManySpacesAreThere>3){

            this->setMethodInitializerErrorCondition(true);
         }
     }
}

bool MethodInitializer::is_Method_Name_Includes_operator_word(){

     this->operator_word_inclusion = false;

     char operator_name [] = {'o','p','e','r','a','t','o','r','\0'};

     int operator_name_size = strlen(operator_name);

     int method_size = strlen(this->MethodLine);

     for(int i=0;i<method_size;i++){

         if(this->MethodLine[i] == operator_name[0]){

            this->operator_word_inclusion = true;

            for(int j=0;j<operator_name_size;j++){

                if(this->MethodLine[i] != operator_name[j]){

                   this->operator_word_inclusion = false;

                   break;
                }

                i++;
            }

            if(this->operator_word_inclusion){

               break;
            }
         }
     }

     return this->operator_word_inclusion;
}

bool MethodInitializer::is_There_Adress_Character_Just_Before_Method_Brace(){

     this->is_Adress_Character_Just_Before_Method_Brace = false;

     int  FirstCharacterPosition_Just_Before_Method_Brace = 0;

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     for(int i=FirstBracePosition;i>0;i--){

         if(this->MethodLine[i] != ' '){

            FirstCharacterPosition_Just_Before_Method_Brace = i;
         }
      }

      if((this->MethodLine[FirstCharacterPosition_Just_Before_Method_Brace] == '*') || (this->MethodLine[FirstCharacterPosition_Just_Before_Method_Brace] == '&')){

          this->is_Adress_Character_Just_Before_Method_Brace = true;
      }

      return this->is_Adress_Character_Just_Before_Method_Brace;
}

bool MethodInitializer::is_There_a_new_Adress_Character(int start_position,int end_position){

     this->is_there_another_adress_character = false;

     for(int i=start_position;i<end_position;i++){

         if((this->MethodLine[i] == '*') || (this->MethodLine[i] == '&')){

             this->is_there_another_adress_character = true;
         }
     }

     return this->is_there_another_adress_character;
}

int  MethodInitializer::get_New_Adress_Character_Position(int start_position, int end_position){

     this->new_adress_character_position = 0;

     for(int i=start_position;i<end_position;i++){

         if((this->MethodLine[i] == '*') || (this->MethodLine[i] == '&')){

             this->new_adress_character_position = i;

             return this->new_adress_character_position;
         }
     }

     this->new_adress_character_position = start_position;

     return this->new_adress_character_position;
}

void MethodInitializer::Delete_Spaces_Between_First_Brace_and_Method_Name(){

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     int listSize = strlen(this->MethodLine);

     // FOLLOWING LINES OF CODES REMOVES POSSIBLE SPACES BETWEEN FIRST BRACE POSITION AND METHOD NAME

     if(this->MethodLine[FirstBracePosition-1] == ' '){

        int spaceCounter = 1;

        while(this->MethodLine[FirstBracePosition-spaceCounter]== ' '){

              spaceCounter++;
        }

        spaceCounter--;

        for(int i=FirstBracePosition-spaceCounter;i<listSize+1;i++){

            this->MethodLine[i] = this->MethodLine[i+spaceCounter];
        }
     }
}

void MethodInitializer::Add_Space_after_predetermined_character(int character_position){

     int listSize = strlen(this->MethodLine);

     if(this->MethodLine[character_position+1]!=' '){

        for(int i=listSize;i>character_position;i--){

            this->MethodLine[i+1] = this->MethodLine[i];
        }

        this->MethodLine[character_position+1] = ' ';
     }
}

void MethodInitializer::Add_Space_before_predetermined_character(int character_position){

     int listSize = strlen(this->MethodLine);

     if((this->MethodLine[character_position-1]!=' ') && (character_position > 0)){

        for(int i=listSize+1;i>character_position-1;i--){

            this->MethodLine[i+1] = this->MethodLine[i];
        }

        this->MethodLine[character_position] = ' ';
     }
}

void MethodInitializer::CheckAdressCharacterBeforeFirstBrace(){

     bool Is_There_Operator_Word = this->is_Method_Name_Includes_operator_word();

     bool Is_There_Adress_Operator_Just_Before_First_Brace = this->is_There_Adress_Character_Just_Before_Method_Brace();

     int listSize = strlen(this->MethodLine);

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     this->Delete_Spaces_Between_First_Brace_and_Method_Name();

     int character_position = 0;

     for(int i=0;i<FirstBracePosition;i++){

         if(this->is_There_a_new_Adress_Character(i,FirstBracePosition)){

            character_position = this->get_New_Adress_Character_Position(i,FirstBracePosition);

            if((this->MethodLine[character_position -1] != ' ') && (this->MethodLine[character_position -1] != '*') && (this->MethodLine[character_position -1] != '&')){

               this->Add_Space_before_predetermined_character(character_position);

               FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

               character_position = this->get_New_Adress_Character_Position(i,FirstBracePosition);
            }

            if((this->MethodLine[character_position+1]!= '*') && (this->MethodLine[character_position +1] != '&')){

                this->Add_Space_after_predetermined_character(character_position);

                FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

                character_position = this->get_New_Adress_Character_Position(i,FirstBracePosition);
            }
            else{

                 while((this->MethodLine[character_position+1] == '*') || (this->MethodLine[character_position+1] == '&')){

                      character_position++;
                 }

                 this->Add_Space_after_predetermined_character(character_position);

                 FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

                 character_position = this->get_New_Adress_Character_Position(i,FirstBracePosition);
            }
         }
     }

     FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'('); // UPDATE FIST BRACE POSITION

     if(Is_There_Operator_Word){

        int shift_counter = 1;

        int position = FirstBracePosition - shift_counter;

        while(this->MethodLine[position] == ' '){

              int listSize = this->CharacterOperations.CharListLength(this->MethodLine);

              for(int i=position;i<listSize+1;i++){

                  this->MethodLine[i] = this->MethodLine[i+1];
              }

              shift_counter++;

              position =  FirstBracePosition - shift_counter;
        }
     }

     if(Is_There_Operator_Word){

        FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'('); // UPDATE FIST BRACE POSITION

        if(this->MethodLine[FirstBracePosition-2] == ' '){

           int shift_counter = 2;

           int position = FirstBracePosition - shift_counter;

           while(this->MethodLine[position] == ' '){

                 int listSize = strlen(this->MethodLine);

                 for(int i=position;i<listSize+1;i++){

                     this->MethodLine[i] = this->MethodLine[i+1];
                 }

                shift_counter++;

                position =  FirstBracePosition - shift_counter;
          }
        }
     }
}

void MethodInitializer::CheckAdressCharacterInsidePharentheses(){

     int listSize = strlen(this->MethodLine);

     int FirstBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,'(');

     int LastBracePosition = this->CharacterOperations.FindNextCharacterPositon(this->MethodLine,0,')');

     int character_position = 0;

     for(int i=FirstBracePosition;i<LastBracePosition;i++){

         if(this->is_There_a_new_Adress_Character(i,LastBracePosition)){

            character_position = this->get_New_Adress_Character_Position(i,LastBracePosition);

            if((this->MethodLine[character_position -1] != ' ') && (this->MethodLine[character_position -1] != '*') && (this->MethodLine[character_position -1] != '&')){

                this->Add_Space_before_predetermined_character(character_position);

                character_position = this->get_New_Adress_Character_Position(i,LastBracePosition);
            }

            if((this->MethodLine[character_position+1]!= '*') && (this->MethodLine[character_position+1] != '&')){

                this->Add_Space_after_predetermined_character(character_position);

                character_position = this->get_New_Adress_Character_Position(i,LastBracePosition);
            }
            else{

                  while((this->MethodLine[character_position+1] == '*') || (this->MethodLine[character_position+1] == '&')){

                       character_position++;
                  }

                  this->Add_Space_after_predetermined_character(character_position);

                  character_position = this->get_New_Adress_Character_Position(i,LastBracePosition);
            }
         }
    }
}

bool MethodInitializer::getFirstBraceExistance(){

     return this->isFirstBraceExist;
}

bool MethodInitializer::getLastBraceExistance(){

     return this->isLastBraceExist;
}

bool MethodInitializer::getMethodInitializerErrorCondition(){

     return this->MethodInitializerErrorCondition;
}

void MethodInitializer::setMethodInitializerErrorCondition(bool condition){

     this->MethodInitializerErrorCondition = condition;
}

char * MethodInitializer::getMethodLine(){

    return this->MethodLine;
}

bool MethodInitializer::getMethodNameExistance(){

     return this->isMethodNameExist;
}
