
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

#include "StringOperator.h"

StringOperator::StringOperator(){

     this->StringBuffer = nullptr;

     this->isBufferEmpty = false;

     this->Included_Word_Start_Position = 0;

     this->Included_Word_Start_Position_Set_Condition = false;

     this->Memory_Delete_Condition = false;

     this->File_End_Condition = false;

     this->Word_Count = 0;
}

StringOperator::StringOperator(const StringOperator & orig){}

StringOperator::~StringOperator(){

    if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();

        this->Cpp_File_Manager.Clear_Dynamic_Memory();
    }
}

void StringOperator::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->ClearStringBuffer();

         this->CharacterOperations.Clear_Dynamic_Memory();
     }
}

void StringOperator::SetFilePath(char * TargetFilePath){

     this->Memory_Delete_Condition = false;

     this->Cpp_File_Manager.SetFilePath(TargetFilePath);
}

int StringOperator::GetBufferLength(){

    this->BufferLength = this->CharacterOperations.CharListLength(this->GetStringBuffer());

    return this->BufferLength;
}

bool StringOperator::CheckStringLine(char * readedline){

     this->isStringLine = false;

     bool isNewLine = false , isNull = false;

     if(readedline[0] == '\n'){

        isNewLine = true;
     }

     if(readedline[0] == '\0'){

        isNull = true;
     }

     if((!isNewLine) && (!isNull)){

          this->isStringLine = true;
     }

     return this->isStringLine;
}

void StringOperator::LoadStringBuffer(char * ReadLine){

     this->ClearStringBuffer();

     int spaceCounter = 0;

     while (((ReadLine[spaceCounter]== ' ') || (ReadLine[spaceCounter]== '\t'))) {   // This loop corp the spaceses in the same line the readed worc ..

            spaceCounter++;
     };

     int string_length = this->CharacterOperations.CharListLength(ReadLine)-spaceCounter;

     if(string_length>0){

        this->StringBuffer = new char [10*string_length];

        this->Memory_Delete_Condition = false;

        this->isBufferEmpty = false;

        int BufferLocation = 0;

        for(int k=0;k<string_length;k++){

            if((ReadLine[k+spaceCounter]=='\n') || (ReadLine[k+spaceCounter]=='\0')){

                this->StringBuffer[BufferLocation] = '\0';

                BufferLocation++;

                break;

            }
            else{

                this->StringBuffer[BufferLocation] = ReadLine[k+spaceCounter];

                BufferLocation++;
            }
        }

        this->StringBuffer[BufferLocation] = '\0';
     }
     else{

         this->StringBuffer = new char [10];

         this->Memory_Delete_Condition = false;

         this->isBufferEmpty = false;

         this->StringBuffer[0] = '\0';

         this->StringBuffer[1] = '\0';
     }
}

char * StringOperator::GetStringBuffer(){

       return this->StringBuffer;
}

void StringOperator::ClearStringBuffer(){

     if(!this->isBufferEmpty){

         if(this->StringBuffer != nullptr){

            delete [] this->StringBuffer;

            this->StringBuffer = nullptr;
         }

         this->isBufferEmpty = true;
     }
}

void StringOperator::ReceiveFileLine(char * ReadLine){

     int spaceCounter=0;

     if(this->CheckStringLine(ReadLine)){

         while(ReadLine[spaceCounter]== ' ') {   // This loop corp the spaceses in the same line the readed word ..

               spaceCounter++;

               if(spaceCounter>500){

                  break;
               }
        };

        this->LoadStringBuffer(ReadLine);
    }
    else{

      this->ClearStringBuffer();

      this->StringBuffer = new char [10];

      this->isBufferEmpty = false;

      this->StringBuffer[0] = '\0';

      this->StringBuffer[1] = '\0';

    }
}

int StringOperator::FindNextWordLine(char * search_word,int startPoint){

    this->Cpp_File_Manager.FileOpen(Rf);

    this->CharacterOperations.ForwardFilePointer(&this->Cpp_File_Manager,startPoint);

    this->wordPosition = startPoint;

    do{
            char * string_line = this->Cpp_File_Manager.ReadLine_as_Cstring();

            if(this->Cpp_File_Manager.Control_End_of_File()){

               break;
            }

            if(this->CheckStringLine(string_line)){

               this->ReceiveFileLine(string_line);

               bool include_condition = this->CheckStringInclusion(this->GetStringBuffer(),search_word);

               if(include_condition){

                  break;
               }
               else{
                     this->wordPosition++;
               }
            }
            else{

                this->wordPosition++;
            }

    }while(!this->Cpp_File_Manager.Control_End_of_File());

    this->File_End_Condition = this->Cpp_File_Manager.Control_End_of_File();

    this->Cpp_File_Manager.FileClose();

    return this->wordPosition;
}

void StringOperator::ReadWordBetweenToPoint(char * StringLine, int StartPoint, int EndPoint){

     this->ClearStringBuffer();

     if(this->CheckStringLine(StringLine)){

        int WordSize = EndPoint-StartPoint;

        if(WordSize>0){

           this->Memory_Delete_Condition = false;

           this->StringBuffer = new char [10*WordSize];

           this->isBufferEmpty = false;

           for(int i=0;i<WordSize;i++){

               this->StringBuffer[i] = StringLine[i+StartPoint];

               if(this->StringBuffer[i] == '\n'){

                  this->StringBuffer[i] = '\0';
               }
           }

           this->StringBuffer[WordSize] = '\0';
       }
       else{

           this->Memory_Delete_Condition = false;

           this->StringBuffer = new char [10];

           this->isBufferEmpty = false;

           this->StringBuffer[0] = '\0';

           this->StringBuffer[1] = '\0';
       }
     }
}

int StringOperator::Get_Word_Number_on_String(char * StringLine, char * search_word){

    this->Word_Count = 0;

    this->includeCondition = false;

    int indexCounter = 0;

    int stringSize = this->CharacterOperations.CharListLength(StringLine);

    int wordSize = this->CharacterOperations.CharListLength(search_word);

    if(stringSize < wordSize){

       return this->Word_Count;
    }

    for(int i=0;i<stringSize;i++){

        indexCounter = 0;

        if(StringLine[i] == search_word[indexCounter]){

           this->Included_Word_Start_Position = i;

           if(this->includeCondition){

              this->includeCondition = false;

              indexCounter = 0;
           }

           while(StringLine[i] == search_word[indexCounter]){

                 if(indexCounter == wordSize -1){

                    this->includeCondition = true;

                    this->Word_Count++;
                 }

                 i++;

                 indexCounter++;
           }
        }
   }

   return this->Word_Count;
}

char * StringOperator::ReadFileLine(int lineNumber){

       this->Cpp_File_Manager.FileOpen(Rf);

       this->CharacterOperations.ForwardFilePointer(&this->Cpp_File_Manager,lineNumber);

       char * line = this->Cpp_File_Manager.ReadLine_as_Cstring();

       this->ReceiveFileLine(line);

       this->Cpp_File_Manager.FileClose();

       return this->GetStringBuffer();
}

bool StringOperator::CheckStringInclusion(char * StringLine,char * search_word){

     this->includeCondition = false;

     int indexCounter = 0;

     int stringSize = this->CharacterOperations.CharListLength(StringLine);

     int wordSize = this->CharacterOperations.CharListLength(search_word);

     if(stringSize < wordSize){

        this->includeCondition = false;

        return this->includeCondition;
     }

     for(int i=0;i<stringSize;i++){

         indexCounter = 0;

         if(StringLine[i] == search_word[indexCounter]){

            this->Included_Word_Start_Position = i;

            while(StringLine[i] == search_word[indexCounter]){

                  if(indexCounter == wordSize -1){

                     this->includeCondition = true;

                     return this->includeCondition;
                  }

                  i++;

                  indexCounter++;
            }
         }
      }

      return this->includeCondition;
}

int StringOperator::Get_Start_Position_of_an_included_String(){

    return this->Included_Word_Start_Position;
}

bool StringOperator::Get_File_End_Condition(){

     return this->File_End_Condition;
}
