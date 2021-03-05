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

#include "Include_Directory_Description_Reader.h"

Include_Directory_Description_Reader::Include_Directory_Description_Reader(){

    this->Memory_Delete_Condition = false;

    this->is_empty_decleration = true;

    this->Include_Directory_Pointer = nullptr;

    this->Data_Collector_Pointer = nullptr;

    this->Initializer_Pointer = nullptr;

    this->Number_Processor_Pointer = nullptr;

    this->Include_Directory_Number = 0;
}

Include_Directory_Description_Reader::Include_Directory_Description_Reader(const Include_Directory_Description_Reader & orig){

}

Include_Directory_Description_Reader::~Include_Directory_Description_Reader(){

      if(!this->Memory_Delete_Condition){

           this->Clear_Dynamic_Memory();
      }
}

void Include_Directory_Description_Reader::Clear_Dynamic_Memory(){

      if(!this->Memory_Delete_Condition){

          this->Memory_Delete_Condition = true;

          if(this->Include_Directory_Pointer!= nullptr){

             for(int i=0;i<this->Include_Directory_Number;i++){

                this->Clear_Pointer_Memory(&(this->Include_Directory_Pointer[i].Include_Directory));
             }

             delete [] this->Include_Directory_Pointer;

             this->Include_Directory_Pointer = nullptr;
          }
      }
}

void Include_Directory_Description_Reader::Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer){

     this->Data_Collector_Pointer = Pointer;
}

void Include_Directory_Description_Reader::Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer){

     this->Initializer_Pointer = Pointer;
}

void Include_Directory_Description_Reader::Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer){

     this->Number_Processor_Pointer = Pointer;
}

void Include_Directory_Description_Reader::Set_Informations_Comes_From_Data_Collector(){

     this->Include_Directory_Number = this->Data_Collector_Pointer->Include_Directory_Numbers;
}

void Include_Directory_Description_Reader::Read_Include_Directory_Descriptions(){

     this->Set_Informations_Comes_From_Data_Collector();

     if(this->Include_Directory_Number > 0){

        this->Receive_Include_Directory();
     }
}

void Include_Directory_Description_Reader::Receive_Include_Directory(){

     int index_counter = 0;

     if(this->Include_Directory_Number > 0){

        int * Directory_Number_Holder = new int [10*this->Include_Directory_Number];

        this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Directory_Number_Holder,2*this->Include_Directory_Number);

        this->Include_Directory_Pointer = new Include_Directory_Type [10*this->Include_Directory_Number];

        for(int i=0;i<this->Include_Directory_Number;i++){

            char * String_Line = this->Initializer_Pointer->Get_Include_Directory_List()[i];

            if(this->Check_Empty_Decleration(String_Line)){

               this->Print_Read_Error_Information();

               std::cerr << "\n     In description of \"Header_File_Locations\",";

               std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

               std::cerr << "\n\n     but there is no decleration at that line. ";

               std::cerr << "\n\n     Please check \"Header_File_Locations\" description.";

               std::cerr << "\n\n     The process will be interrupted ..";

               this->Print_End_of_Program();

               exit(1);
            }

            int Include_Directory_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

            if(Include_Directory_Number == -1){

               this->Print_Read_Error_Information();

               std::cerr << "\n     In description of \"Header_File_Locations\",";

               std::cerr << "\n\n     there is an Empty Brace in location number descriptions.";

               std::cerr << "\n\n     Header file location number data can not be readed.";

               std::cerr << "\n\n     Please check \"Header_File_Locations\" description.";

               std::cerr << "\n\n     The process will be interrupted ..";

               this->Print_End_of_Program();

               exit(1);

             }

             if(Include_Directory_Number == -2){

                this->Print_Read_Error_Information();

                std::cerr << "\n     In description of \"Header_File_Locations\",";

                std::cerr << "\n\n     there is an open brace or missing number in location number descriptions.";

                std::cerr << "\n\n     Header file location number data can not be readed. ";

                std::cerr << "\n\n     Please check description. The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(Directory_Number_Holder[Include_Directory_Number] != 0){

                this->Print_Read_Error_Information();

                std::cerr << "\n     In \"Header_File_Locations\" description,";

                std::cerr << "\n\n     Some of the directories indicating the location of the header files -";

                std::cerr << "\n\n     has the same directory number ! Each directory must have different number..";

                std::cerr << "\n\n     Plase check Header File Location directory declerations!";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
              }

              Directory_Number_Holder[Include_Directory_Number] = 1;

              this->Include_Directory_Pointer[index_counter].Directory_Number = Include_Directory_Number;

              this->Include_Directory_Pointer[index_counter].Total_Include_Directory_Number = this->Include_Directory_Number;

              size_t String_Size = strlen(String_Line);

              this->Include_Directory_Pointer[index_counter].Include_Directory = new char [10*String_Size];

              this->Place_String(&(this->Include_Directory_Pointer[index_counter].Include_Directory),String_Line);

              index_counter++;
          }

          delete [] Directory_Number_Holder;
     }
 }

 void Include_Directory_Description_Reader::Clear_Pointer_Memory(char ** Pointer){

       if(*Pointer != nullptr){

           delete [] (*Pointer);

           *Pointer = nullptr;
       }
 }

 void Include_Directory_Description_Reader::Place_String(char ** Pointer, char * String){

      int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String);

      size_t String_Size = strlen(String);

      int index_counter = 0;

      for(size_t i=Start_Point;i<String_Size;i++){

          (*Pointer)[index_counter] = String[i];

          index_counter++;
      }

      (*Pointer)[index_counter] = '\0';
 }

 bool Include_Directory_Description_Reader::Check_Empty_Decleration(char * String){

      this->is_empty_decleration = true;

      int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String);

      int String_Size = strlen(String);

      for(int i=Start_Point;i<String_Size;i++){

          if(((String[i] != ' ') && (String[i] != '\t') && (String[i] != '\n') && (String[i] != '\0'))){

              this->is_empty_decleration = false;
          }
      }

      return this->is_empty_decleration;
  }

 void Include_Directory_Description_Reader::Print_Read_Error_Information(){

      std::cerr << "\n";

      std::cerr << "\n  # ERROR MESSAGE";

      std::cerr << "\n";

      std::cerr << "\n  # Error Type: Descriptor File Read Error";

      std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

      std::cerr << "\n\n  {";
 }

 void Include_Directory_Description_Reader::Print_End_of_Program(){

      std::cerr << "\n  }";

      std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";
 }

 Include_Directory_Type * Include_Directory_Description_Reader::Get_Include_Directory() const {

     return this->Include_Directory_Pointer;
 }

 int Include_Directory_Description_Reader::Get_Include_Directory_Number() const {

     return this->Include_Directory_Number;
 }
