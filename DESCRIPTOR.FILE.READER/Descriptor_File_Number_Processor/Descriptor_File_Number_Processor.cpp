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

#include "Descriptor_File_Number_Processor.h"

Descriptor_File_Number_Processor::Descriptor_File_Number_Processor(){

     this->Memory_Delete_Condition = false;
}

Descriptor_File_Number_Processor::Descriptor_File_Number_Processor(const Descriptor_File_Number_Processor & orig){

}

Descriptor_File_Number_Processor::~Descriptor_File_Number_Processor(){

}

void Descriptor_File_Number_Processor::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->CharacterOperations.Clear_Dynamic_Memory();
     }
}

int Descriptor_File_Number_Processor::Read_Record_Number_From_String_Line(char * String){

    this->Record_Number = 0;

    int String_Size = strlen(String);

    int First_Brace_Number = this->CharacterOperations.DetermineCharacterRepitation(String,'[');

    int Last_Brace_Number = this->CharacterOperations.DetermineCharacterRepitation(String,']');

    if((First_Brace_Number == 0) || (Last_Brace_Number == 0)){

        this->Record_Number = -2;  // There is a Missing record number or open brace in some place

        return this->Record_Number;
    }

    if(((First_Brace_Number > 1) || (Last_Brace_Number > 1))){

         if(((First_Brace_Number == 1) && (Last_Brace_Number == 2))){

              int first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,'[');

              int last_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,']');

              if(first_brace_position > last_brace_position){

                 this->Record_Number = -2;   // There is a Missing record number or open brace in some place

                 return this->Record_Number;
              }
         }

         if(((First_Brace_Number == 2) && (Last_Brace_Number == 1))){

              int first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,'[');

              int next_first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,first_brace_position+1,'[');

              int last_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,']');

              if(last_brace_position > next_first_brace_position){

                 this->Record_Number = -2;   // There is a Missing record number or open brace in some place

                 return this->Record_Number;
              }
         }
    }

    int Record_Start_Point = 0, Record_End_Point = 0, Number_Size = 0;

    int first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,'[');

    int last_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,']');

    for(int k=first_brace_position+1;k<last_brace_position;k++){

        while(String[k] == ' '){

              k++;
        }

        Record_Start_Point = k;

        while(String[k] != ']'){

              k++;
        }

        Record_End_Point = k;

        break;
    }

    Number_Size = Record_End_Point - Record_Start_Point;

    if(Number_Size == 0){

       this->Record_Number = -1; // There is an Empty Brace

       return this->Record_Number;
    }

    char * Character_Number = new char [10*Number_Size];

    int index_counter = 0;

    for(int i=Record_Start_Point;i<Record_End_Point;i++){

        Character_Number[index_counter] = String[i];

        index_counter++;
    }

    Character_Number[index_counter] = '\0';

    this->Record_Number = this->Translater.TranslateFromCharToInt(Character_Number);

    delete [] Character_Number;

    return this->Record_Number;
}

int Descriptor_File_Number_Processor::Read_Second_Record_Number_From_String_Line(char * String){

    this->Record_Number = 0;

    int String_Size = strlen(String);

    int Record_Start_Point = 0, Record_End_Point = 0, Number_Size = 0;

    int First_Brace_Number = this->CharacterOperations.DetermineCharacterRepitation(String,'[');

    int Last_Brace_Number = this->CharacterOperations.DetermineCharacterRepitation(String,']');

    if(((First_Brace_Number == 2) && (Last_Brace_Number == 1))){

        int first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,'[');

        int next_first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,first_brace_position+1,'[');

        int last_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,']');

        if(next_first_brace_position > last_brace_position){

           this->Record_Number = -2;   // There is a Missing record number or open brace in some place

           return this->Record_Number;
        }
     }

     if(((First_Brace_Number == 1) && (Last_Brace_Number == 2))){

         int first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,'[');

         int last_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,']');

         if(last_brace_position > first_brace_position){

            this->Record_Number = -2;   // There is a Missing record number or open brace in some place

            return this->Record_Number;
         }
     }

     if(((First_Brace_Number == 2) && (Last_Brace_Number == 2))){

         int first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,'[');

         int next_first_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,first_brace_position+1,'[');

         int last_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,0,']');

         int next_last_brace_position = this->CharacterOperations.FindNextCharacterPositon(String,last_brace_position+1,']');

         if(next_first_brace_position > next_last_brace_position){

            this->Record_Number = -2;   // There is a Missing record number or open brace in some place

            return this->Record_Number;
         }

         for(int k=next_first_brace_position+1;k<next_last_brace_position;k++){

             while(String[k] == ' '){

                   k++;
             }

             Record_Start_Point = k;

             while(String[k] != ']'){

                   k++;
             }

             Record_End_Point = k;

             break;
         }

         Number_Size = Record_End_Point - Record_Start_Point;

         if(Number_Size == 0){

            this->Record_Number = -1; // There is an Empty Brace ..

            return this->Record_Number;
         }
         else{

               char * Character_Number = new char [10*Number_Size];

               int index_counter = 0;

               for(int i=Record_Start_Point;i<Record_End_Point;i++){

                   Character_Number[index_counter] = String[i];

                   index_counter++;
               }

               Character_Number[index_counter] = '\0';

               this->Record_Number = this->Translater.TranslateFromCharToInt(Character_Number);

               delete [] Character_Number;
         }
     }

     return this->Record_Number;
}

int Descriptor_File_Number_Processor::Get_Read_Operation_Start_Point(char * String){

    this->Read_Operation_Start_Point = 0;

    int Brace_Number = this->CharacterOperations.DetermineCharacterRepitation(String,'[');

    int Single_Line_Number = this->CharacterOperations.DetermineCharacterRepitation(String,'-');

    int String_Size = strlen(String);

    if((Brace_Number > 0) && (Single_Line_Number > 0)){

       int Search_Point = String_Size;

       while(String[Search_Point] != ']'){

             Search_Point--;
       }

       Search_Point++;

       this->Read_Operation_Start_Point = Search_Point;

       while((String[this->Read_Operation_Start_Point] == ' ') || (String[this->Read_Operation_Start_Point] == '-')){

             this->Read_Operation_Start_Point++;
       }
    }
    else{

         if(Brace_Number > 0){

            int Start_Point = 0;

            int Search_Point = String_Size;

            while(String[Search_Point] != ']'){

                  Search_Point--;
            }

            Search_Point++;

            this->Read_Operation_Start_Point = Search_Point;

            while(String[this->Read_Operation_Start_Point] == ' '){

                  this->Read_Operation_Start_Point++;
            }
         }
         else{

                while(String[this->Read_Operation_Start_Point] == ' '){

                      this->Read_Operation_Start_Point++;
                }
         }
    }

    return this->Read_Operation_Start_Point;
}

void Descriptor_File_Number_Processor::Set_Zero_For_Integer_List(int ** list, int list_size){

     for(int i=0;i<list_size;i++){

         (*list)[i] = 0;
     }
}

bool Descriptor_File_Number_Processor::Check_Number_Repitation(int * list, int list_size){

     this->Number_Repitation = false;

     for(int j=0;j<list_size;j++){

         for(int k=0;k<list_size -j -1;k++){

             if((list[j] != 0) && (list[j] == list[j+k+1])){

                 this->Number_Repitation = true;
             }
         }
     }

     return this->Number_Repitation;
}
