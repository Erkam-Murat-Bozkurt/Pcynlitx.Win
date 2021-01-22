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

#include "IntToCharTranslater.h"

IntToCharTranslater::IntToCharTranslater(){

    this->char_number = nullptr;

    this->int_number = 0;

    this->Memory_Empty_Status = true;
}

IntToCharTranslater::IntToCharTranslater(const IntToCharTranslater & oring){

}

IntToCharTranslater::~IntToCharTranslater(){

     if(!this->Memory_Empty_Status){

         this->Clear_Character_Memory();
     }
}

void IntToCharTranslater::Clear_Character_Memory()
{
     if(this->char_number != nullptr){

        delete [] this->char_number;

        this->char_number = nullptr;
     }

     this->Memory_Empty_Status = true;
}

void IntToCharTranslater::Fill_Character_Memory(std::string string_number)
{
     this->Memory_Empty_Status = false;

     int string_lenght = string_number.length();

     this->char_number = new char [5*string_lenght];

     int index_counter = 0;

     for(int i=0;i<string_lenght;i++){

         this->char_number[index_counter] = string_number[i];

         index_counter++;
     }

     this->char_number[index_counter] = '\0';
}


char * IntToCharTranslater::Translate(int integer){

       this->temp_str = std::to_string(integer);

       this->Clear_Character_Memory();

       this->Fill_Character_Memory(this->temp_str);

       return this->char_number;
}

int IntToCharTranslater::TranslateFromCharToInt(char * ch){

    this->int_number = atoi(ch);

    return this->int_number;
}
