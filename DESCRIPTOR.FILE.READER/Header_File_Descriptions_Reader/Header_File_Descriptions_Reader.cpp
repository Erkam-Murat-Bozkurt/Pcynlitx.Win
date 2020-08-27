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


#include "Header_File_Descriptions_Reader.h"

Header_File_Descriptions_Reader::Header_File_Descriptions_Reader(){

    this->Memory_Delete_Condition = false;

    this->is_empty_decleration = true;

    this->Header_File_Names = nullptr;

    this->Header_File_Paths = nullptr;
}

Header_File_Descriptions_Reader::Header_File_Descriptions_Reader(const Header_File_Descriptions_Reader & orig){

}

Header_File_Descriptions_Reader::~Header_File_Descriptions_Reader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void Header_File_Descriptions_Reader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Header_File_Names != nullptr){

            for(int i=0;i<this->Header_File_Names_Number;i++){

                this->Clear_Pointer_Memory(&this->Header_File_Names[i]);

                this->Clear_Pointer_Memory(&this->Header_File_Paths[i]);
            }

            delete [] this->Header_File_Names;

            delete [] this->Header_File_Paths;
         }
     }
}


void Header_File_Descriptions_Reader::Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer){

     this->Data_Collector_Pointer = Pointer;
}

void Header_File_Descriptions_Reader::Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer){

     this->Initializer_Pointer = Pointer;
}

void Header_File_Descriptions_Reader::Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer){

     this->Number_Processor_Pointer = Pointer;
}

void Header_File_Descriptions_Reader::Receive_Include_Directory_Description_Reader(Include_Directory_Description_Reader * Pointer){

     this->ID_Description_Reader = Pointer;
}

void Header_File_Descriptions_Reader::Set_Informations_Comes_From_Data_Collector(){

     this->Include_Directory_Number = this->Data_Collector_Pointer->Include_Directory_Numbers;

     this->Header_File_Names_Number = this->Data_Collector_Pointer->Header_File_Names_Number;
}

void Header_File_Descriptions_Reader::Receive_Header_File_Names(){

     this->Memory_Delete_Condition = false;

     this->Set_Informations_Comes_From_Data_Collector();

     int * Header_File_Names_Number_Holder = new int [10*this->Header_File_Names_Number];

     this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Header_File_Names_Number_Holder,5*this->Header_File_Names_Number);

     char Directory_Character [] = {'/','\0'};

     int Directory_Character_Name_Size = strlen(Directory_Character);

     this->Header_File_Names = new char * [10*this->Header_File_Names_Number];

     this->Header_File_Paths = new char * [10*this->Header_File_Names_Number];

     for(int i=0;i<this->Header_File_Names_Number;i++){

         char * String_Line = this->Initializer_Pointer->Get_Header_File_List()[i];

         if(this->Check_Empty_Decleration(String_Line)){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Header_File_Names\",";

            std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

            std::cerr << "\n\n     but there is no decleration at that line. ";

            std::cerr << "\n\n     Please check \"Header_File_Names\" description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int File_Names_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

         Header_File_Names_Number_Holder[i] = File_Names_Number;

         bool Number_Repitation = this->Number_Processor_Pointer->Check_Number_Repitation(Header_File_Names_Number_Holder,this->Header_File_Names_Number);

         if(Number_Repitation){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In \"Header_File_Names\" description,";

            std::cerr << "\n\n     The same header file number readed more than ones time ..";

            std::cerr << "\n\n     Please check header file number declerations";

            std::cerr << "\n\n     Process will be interrupted ..";


            this->Print_End_of_Program();

            exit(1);
         }

         char Header_File_Number [] = "header file number";

         this->Print_Brace_Data_Read_Error(File_Names_Number,Header_File_Number);

         int Header_File_Location_Number = this->Number_Processor_Pointer->Read_Second_Record_Number_From_String_Line(String_Line);

         char Header_File_Location_Word [] = "header file location";

         this->Print_Brace_Data_Read_Error(Header_File_Location_Number,Header_File_Location_Word);

         bool Wrong_Include_Directory_Set_Condition = true;

         for(int k=0;k<this->Include_Directory_Number;k++){

            int Include_Directory_Number = this->ID_Description_Reader->Get_Include_Directory()[k].Directory_Number;

            if(Include_Directory_Number == Header_File_Location_Number){

               Wrong_Include_Directory_Set_Condition = false;
            }
         }

         if(Wrong_Include_Directory_Set_Condition){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Header_File_Names\",";

            std::cerr << "\n\n     header file location can not be readed correctly.";

            std::cerr << "\n\n     The number which indicates file location is wrong or";

            std::cerr << "\n\n     the description of the location can be missed. ";

            std::cerr << "\n\n     Please check the description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         char * Header_File_Location = nullptr;

         for(int k=0;k<this->Include_Directory_Number;k++){

             if(Header_File_Location_Number  == this->ID_Description_Reader->Get_Include_Directory()[k].Directory_Number){

                 Header_File_Location = this->ID_Description_Reader->Get_Include_Directory()[k].Include_Directory;
              }
         }

         if(Header_File_Location == nullptr){

            this->Print_Read_Error_Information();

            std::cerr << "\n\n     The location of the header file can not be determined !";

            std::cerr << "\n\n     Please check the number indicates the header file location";

            std::cerr << "\n\n     Process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int String_Size = strlen(String_Line);

         this->Header_File_Names[i] = new char [10*String_Size];

         this->Place_String(&(this->Header_File_Names[i]),String_Line);

         int Location_Name_Size = strlen(Header_File_Location);

         int Header_File_Name_Size = Directory_Character_Name_Size + Location_Name_Size + String_Size;

         this->Header_File_Paths[i] = new char [10*Header_File_Name_Size];

         int Start_Point = 0, index_counter = 0;

         this->Place_Information(&(this->Header_File_Paths[i]),Header_File_Location,&index_counter,Start_Point);

         this->Place_Information(&(this->Header_File_Paths[i]),Directory_Character,&index_counter,Start_Point);

         Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String_Line);

         this->Place_Information(&(this->Header_File_Paths[i]),String_Line,&index_counter,Start_Point);

         this->Header_File_Paths[i][index_counter] = '\0';

         bool is_that_file_exist = this->Directory_Manager.Search_File_in_Directory(Header_File_Location,this->Header_File_Names[i]);

         if(!is_that_file_exist){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Header_File_Names\",";

             std::cerr << "\n\n     there is no a file with name \"" << this->Header_File_Names[i] << "\"";

             std::cerr << "\n\n     in the directories descripted as header file locations.";

             std::cerr << "\n\n     Please check Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
         }
     }

     delete [] Header_File_Names_Number_Holder;
}

void Header_File_Descriptions_Reader::Print_Read_Error_Information(){

     std::cerr << "\n  # ERROR MESSAGE";

     std::cerr << "\n";

     std::cerr << "\n  # Error Type: Descriptor File Read Error";

     std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

     std::cerr << "\n\n  {";
}

void Header_File_Descriptions_Reader::Print_End_of_Program(){

     std::cerr << "\n  }";

     std::cerr << "\n\n  THE END OF THE MESSAGE \n\n";
}

void Header_File_Descriptions_Reader::Print_Brace_Data_Read_Error(int Readed_Data, char * Data_Type){

     if(Readed_Data == -1){

        this->Print_Read_Error_Information();

        std::cerr << "\n     In description of \"Header_File_Names\",";

        std::cerr << "\n\n     there is an Empty Brace in " << Data_Type << " descriptions.";

        std::cerr << "\n\n     " << Data_Type << " data can not be readed.";

        std::cerr << "\n\n     Please check the description.";

        std::cerr << "\n\n     The process will be interrupted ..";

        this->Print_End_of_Program();

        exit(1);
     }

     if(Readed_Data == -2){

        this->Print_Read_Error_Information();

        std::cerr << "\n     In description of \"Header_File_Names\",";

        std::cerr << "\n\n     there is an open brace or missing number in " << Data_Type;

        std::cerr << "\n\n     descriptions. " << Data_Type << " can not be readed. ";

        std::cerr << "\n\n     Please check the description.";

        std::cerr << "\n\n     The process will be interrupted ..";

        this->Print_End_of_Program();

        exit(1);
     }
}

bool Header_File_Descriptions_Reader::Check_Empty_Decleration(char * String){

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

void Header_File_Descriptions_Reader::Place_Information(char ** Pointer, char * Information, int * index_counter, int Start_Point){

     int String_Size = strlen(Information);

     for(int i=Start_Point;i<String_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
 }

void Header_File_Descriptions_Reader::Clear_Pointer_Memory(char ** Pointer){

      if(*Pointer != nullptr){

          delete [] (*Pointer);

          *Pointer = nullptr;
      }
 }

 void Header_File_Descriptions_Reader::Place_String(char ** Pointer, char * String){

      int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String);

      int String_Size = strlen(String);

      int index_counter = 0;

      for(int i=Start_Point;i<String_Size;i++){

          (*Pointer)[index_counter] = String[i];

          index_counter++;
      }

      (*Pointer)[index_counter] = '\0';
 }

 char ** Header_File_Descriptions_Reader::Get_Header_File_Names() const {

         return this->Header_File_Names;
 }

 char ** Header_File_Descriptions_Reader::Get_Header_File_Paths() const{

         return this->Header_File_Paths;
 }

 int Header_File_Descriptions_Reader::Get_Header_Files_Number() const {

     return this->Header_File_Names_Number;
 }
