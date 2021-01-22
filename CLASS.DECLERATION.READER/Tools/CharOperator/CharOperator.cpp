
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

#include "CharOperator.h"

CharOperator::CharOperator(){

   this->String_Buffer = nullptr;

   this->Memory_Delete_Condition = false;
}

CharOperator::CharOperator(const CharOperator &orig){

}

CharOperator::~CharOperator(){

}

void CharOperator::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         if(this->String_Buffer != nullptr){

            delete [] this->String_Buffer;
         }
     }
}

void CharOperator::SetFilePath(const char * TargetFile){

     this->FileManager.SetFilePath(TargetFile);
}

int CharOperator::DetermineTotalMethodNumber(){

    this->TotalMethodNumber = 0;

    int TheFileEND = this->FindTheSpecificWordLine("END");

    this->FileManager.FileOpen(Rf);

    char * pointer;

    bool condition;

    // FileEND shows the line number includes END word.
    // END word is used to specify the meta data file end.

    for(int i=0;i<TheFileEND;i++){

        pointer = this->Conver_Std_String_To_Char(this->FileManager.ReadLine());

        condition = this->CharacterCheck(pointer,'(');

        if(condition){

           this->TotalMethodNumber++;
        }
    }

    this->FileManager.FileClose();

    return this->TotalMethodNumber;
}

void CharOperator::ForwardFilePointer(Cpp_FileOperations * FileManager,int stepSize){

    for(int i=0;i<stepSize-1;i++){

        FileManager->ReadLine();
    }
}

int CharOperator::FindNextCharacterPositon(char * targetList,int startPoint, char character){

     this->CharacterPosition = 0;

     int ListSize = this->CharListLength(targetList);

     int Position = startPoint;

     while(targetList[Position]!= character){

          Position++;

          if(Position == ListSize){

              this->CharacterPosition = Position;

              break;
          }
     };

     this->CharacterPosition = Position;

     return this->CharacterPosition;
}

int CharOperator::DetermineCharacterRepitation(char * listPointer, char character){

     this->CharacterRepitation = 0;

     int ListSize = this->CharListLength(listPointer);

     for(int k=0;k<ListSize+1;k++){

          if(listPointer[k]== character){

             this->CharacterRepitation++;
          }
     }

     return this->CharacterRepitation;
}

int CharOperator::FindTheSpecificWordLine(std::string word){

     this->FileManager.FileOpen(Rf);

     this->WordPosition = 0;

     std::string buffer = " ";

     while(true){

           buffer = this->FileManager.ReadLine();

           if(buffer != word){

              break;
           }

           bool end_of_file = this->FileManager.Control_End_of_File();

           if(end_of_file){

              break;
           }

           this->WordPosition++;
      }

      this->FileManager.FileClose();

      return this->WordPosition;
}

size_t CharOperator::CharListLength(char * Characterlist){

    this->ListLength = 0;

    if((Characterlist[this->ListLength] != '\0') && (Characterlist[this->ListLength] != '\n') ){

        while((Characterlist[this->ListLength] != '\0') && (Characterlist[this->ListLength] != '\n')){

             this->ListLength++;
        }
    }

    return this->ListLength;
}

bool CharOperator::CharacterCheck(char * list,char character){

    int listLength;

    listLength = this->CharListLength(list);

    for(int i=0;i<listLength;i++){

         if(list[i]== character){

             return true;
         }
    }

    return false;
}

int CharOperator::FindFirstCharacterPosition(char * list){

    this->FirstCharacterPosition = 0;

    while(list[this->FirstCharacterPosition]==' '){

          this->FirstCharacterPosition++;
    }

    return this->FirstCharacterPosition;
}

bool CharOperator::CompareString(char * firstString,char * secondString){

     int firstStringLength  = this->CharListLength(firstString);

     int secondStringLength = this->CharListLength(secondString);

     if(firstStringLength==secondStringLength){

        for(int i=0;i<firstStringLength;i++){

            if(firstString[i]!=secondString[i]){

               this->isStringsEqual = false;

               return this->isStringsEqual;
            }
        }

        this->isStringsEqual = true;

        return this->isStringsEqual;
     }
     else{

          this->isStringsEqual = false;

          return this->isStringsEqual;
     }
}

char * CharOperator::Conver_Std_String_To_Char(std::string string_line){

       if(this->String_Buffer != nullptr){

          delete [] this->String_Buffer;
       }

       int string_size = string_line.length();

       this->Memory_Delete_Condition = false;

       this->String_Buffer = new char [5*string_size];

       for(int i=0;i<string_size;i++){

           this->String_Buffer[i] = string_line[i];
       }

       this->String_Buffer[string_size] = '\0';

       return this->String_Buffer;
}
