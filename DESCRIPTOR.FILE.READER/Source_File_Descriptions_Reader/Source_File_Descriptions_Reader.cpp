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

#include "Source_File_Descriptions_Reader.h"

Source_File_Descriptions_Reader::Source_File_Descriptions_Reader(){

     this->Memory_Delete_Condition = false;

     this->is_empty_decleration = true;

     this->Source_File_Locations_Pointer = nullptr;

     this->Source_File_Locations = nullptr;

     this->Source_File_Names = nullptr;
}

Source_File_Descriptions_Reader::Source_File_Descriptions_Reader(const Source_File_Descriptions_Reader & orig){

}

Source_File_Descriptions_Reader::~Source_File_Descriptions_Reader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void Source_File_Descriptions_Reader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Source_File_Locations != nullptr){

            for(int i=0;i<this->Source_File_Location_Number;i++){

                this->Clear_Pointer_Memory(&(this->Source_File_Locations[i]));
            }

            delete [] this->Source_File_Locations;

            this->Source_File_Locations = nullptr;
         }

         if(this->Source_File_Names != nullptr){

            for(int i=0;i<this->Source_File_Number;i++){

                this->Clear_Pointer_Memory(&(this->Source_File_Names[i]));
            }

            delete [] this->Source_File_Names;

            this->Source_File_Names = nullptr;
         }
     }
}

void Source_File_Descriptions_Reader::Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer){

     this->Data_Collector_Pointer = Pointer;
}

void Source_File_Descriptions_Reader::Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer){

     this->Initializer_Pointer = Pointer;
}

void Source_File_Descriptions_Reader::Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer){

     this->Number_Processor_Pointer = Pointer;
}

void Source_File_Descriptions_Reader::Receive_Include_Directory_Description_Reader(Include_Directory_Description_Reader * Pointer){

     this->ID_Description_Reader = Pointer;
}

void Source_File_Descriptions_Reader::Set_Informations_Comes_From_Data_Collector(){

     this->Include_Directory_Number = this->Data_Collector_Pointer->Include_Directory_Numbers;

     this->Source_File_Location_Number = this->Data_Collector_Pointer->Source_File_Location_Number;

     this->Source_File_Number = this->Data_Collector_Pointer->Source_File_Number;
}

void Source_File_Descriptions_Reader::Read_Source_File_Descriptions(){

     this->Set_Informations_Comes_From_Data_Collector();

     if(this->Source_File_Location_Number > 0){

        this->Receive_Source_File_Locations();
     }

     if(this->Source_File_Number > 0){

        this->Receive_Source_File_Names();
     }
}

void Source_File_Descriptions_Reader::Receive_Source_File_Locations(){

     int * Location_Number_holder = new int [10*this->Source_File_Location_Number];

     this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Location_Number_holder,10*this->Source_File_Location_Number);

     this->Source_File_Locations_Pointer = new Source_File_Location_Data_Type [10*this->Source_File_Location_Number];

     this->Source_File_Locations = new char * [10*this->Source_File_Location_Number];

     for(int i=0;i<this->Source_File_Location_Number;i++){

         char * String_Line = this->Initializer_Pointer->Get_Source_File_Location_List()[i];

         if(this->Check_Empty_Decleration(String_Line)){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Source_File_Locations\",";

            std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

            std::cerr << "\n\n     but there is no decleration at that line. ";

            std::cerr << "\n\n     Please check \"Source_File_Locations\" description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int Location_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

         if(Location_Number == -1){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Source_File_Locations\",";

            std::cerr << "\n\n     there is an Empty Brace in location number descriptions.";

            std::cerr << "\n\n     Location number data can not be readed.";

            std::cerr << "\n\n     Please check description. The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         if(Location_Number == -2){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Source_File_Locations\",";

            std::cerr << "\n\n     there is an open brace or missing number in location number descriptions.";

            std::cerr << "\n\n     Location number data can not be readed. Please check description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         Location_Number_holder[i] = Location_Number;

         bool Number_Repitation = this->Number_Processor_Pointer->Check_Number_Repitation(Location_Number_holder,this->Source_File_Location_Number);

         if(Number_Repitation){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In \"Source_File_Locations\" description,";

             std::cerr << "\n\n     A number for source file locations readed more than ones time !";

             std::cerr << "\n\n     Each location must have different number ..";

             std::cerr << "\n\n     Please check the declerations";

             std::cerr << "\n\n     Process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
         }

         int String_Size = strlen(String_Line);

         this->Source_File_Locations_Pointer[i].Location_Number = Location_Number;

         this->Source_File_Locations_Pointer[i].Source_File_Location = new char [10*String_Size];

         this->Source_File_Locations[i] = new char [10*String_Size];

         this->Place_String(&(this->Source_File_Locations_Pointer[i].Source_File_Location),String_Line);

         this->Place_String(&(this->Source_File_Locations[i]),String_Line);
     }

     delete [] Location_Number_holder;
}

void Source_File_Descriptions_Reader::Receive_Source_File_Names(){

     int * Source_File_Names_Number_Holder = new int [10*this->Source_File_Number];

     this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Source_File_Names_Number_Holder,2*this->Source_File_Number);

     this->Source_File_Names = new char * [10*this->Source_File_Number];

     char Directory_Character [] = {'/','\0'};

     int Directory_Character_Name_Size = strlen(Directory_Character);

     for(int i=0;i<this->Source_File_Number;i++){

         char * String_Line = this->Initializer_Pointer->Get_Source_File_List()[i];

         if(this->Check_Empty_Decleration(String_Line)){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Source_File_Names\",";

            std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

            std::cerr << "\n\n     but there is no decleration at that line. ";

            std::cerr << "\n\n     Please check \"Source_File_Names\" description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         char * Source_File_Location = nullptr;

         int String_Size = strlen(String_Line);

         int Source_File_Names_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

         char Source_File_Number [] = "source file number";

         this->Print_Brace_Data_Read_Error(Source_File_Names_Number,Source_File_Number);

         Source_File_Names_Number_Holder[i] = Source_File_Names_Number;

         bool Number_Repitation = this->Number_Processor_Pointer->Check_Number_Repitation(Source_File_Names_Number_Holder,this->Source_File_Number);

         if(Number_Repitation){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In \"Source_File_Names\" description,";

            std::cerr << "\n\n     The same class number readed more than ones time ..";

            std::cerr << "\n\n     Please check class number declerations";

            std::cerr << "\n\n     Process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int Location_Number = this->Number_Processor_Pointer->Read_Second_Record_Number_From_String_Line(String_Line);

         char Source_File_Location_word [] = "source file location";

         this->Print_Brace_Data_Read_Error(Location_Number,Source_File_Location_word);

         for(int k=0;k<this->Source_File_Location_Number;k++){

             if(Location_Number == this->Source_File_Locations_Pointer[k].Location_Number){

                Source_File_Location = this->Source_File_Locations_Pointer[k].Source_File_Location;
             }
         }

         if(Source_File_Location == nullptr){

           this->Print_Read_Error_Information();

           std::cerr << "\n\n     Source File location can not be determined !";

           std::cerr << "\n\n     Source file location number is wrong.";

           std::cerr << "\n\n     There is no location which descripted with this number.";

           std::cerr << "\n\n     Please check sorce file location number decleration.";

           std::cerr << "\n\n     Process will be interrupted ..";

           this->Print_End_of_Program();

           exit(1);
         }

         int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String_Line);

         int Location_Name_Size = strlen(Source_File_Location);

         int Source_File_Name_Size = String_Size + Location_Name_Size + Directory_Character_Name_Size;

         this->Source_File_Names[i] = new char [10*Source_File_Name_Size];

         int index_counter = 0;

         for(int k=0;k<Location_Name_Size;k++){

             this->Source_File_Names[i][index_counter] = Source_File_Location[k];

             index_counter++;
         }

         for(int k=0;k<Directory_Character_Name_Size;k++){

             this->Source_File_Names[i][index_counter] = Directory_Character[k];

             index_counter++;
         }

         for(int k=Start_Point;k<String_Size;k++){

             this->Source_File_Names[i][index_counter] = String_Line[k];

             index_counter++;
         }

         this->Source_File_Names[i][index_counter] = '\0';

         int File_Name_Size = String_Size - Start_Point;

         char * Source_File_Name_Pointer = new char [10*File_Name_Size];

         index_counter = 0;

         for(int k=Start_Point;k<String_Size;k++){

             Source_File_Name_Pointer[index_counter] = String_Line[k];

             index_counter++;
         }

         Source_File_Name_Pointer[index_counter] = '\0';

         bool is_that_file_exist = this->Directory_Manager.Search_File_in_Directory(Source_File_Location,Source_File_Name_Pointer);

         if(!is_that_file_exist){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Source_File_Names\",";

             std::cerr << "\n\n     there is no a file with name \"" << Source_File_Name_Pointer << "\" in directory -";

             std::cerr << "\n\n    " << Source_File_Location;

             std::cerr << "\n\n     Please check \"Source_File_Names\" description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
         }

         delete [] Source_File_Name_Pointer;
     }

     if(this->Source_File_Locations_Pointer != nullptr){

        for(int i=0;i<this->Source_File_Location_Number;i++){

           this->Clear_Pointer_Memory(&(this->Source_File_Locations_Pointer[i].Source_File_Location));
        }

        delete [] this->Source_File_Locations_Pointer;
     }

     delete [] Source_File_Names_Number_Holder;
}


void Source_File_Descriptions_Reader::Print_Read_Error_Information(){

     std::cerr << "\n  # ERROR MESSAGE";

     std::cerr << "\n";

     std::cerr << "\n  # Error Type: Descriptor File Read Error";

     std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

     std::cerr << "\n\n  {";
}

void Source_File_Descriptions_Reader::Print_End_of_Program(){

     std::cerr << "\n  }";

     std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";
}

void Source_File_Descriptions_Reader::Print_Brace_Data_Read_Error(int Readed_Data, char * Data_Type){

     if(Readed_Data == -1){

        this->Print_Read_Error_Information();

        std::cerr << "\n     In description of \"Source_File_Names\",";

        std::cerr << "\n\n     there is an Empty Brace in " << Data_Type << " descriptions.";

        std::cerr << "\n\n     " << Data_Type << " data can not be readed.";

        std::cerr << "\n\n     Please check the description.";

        std::cerr << "\n\n     The process will be interrupted ..";

        this->Print_End_of_Program();

        exit(1);
     }

     if(Readed_Data == -2){

        this->Print_Read_Error_Information();

        std::cerr << "\n     In description of \"Source_File_Names\",";

        std::cerr << "\n\n     there is an open brace or missing number in " << Data_Type;

        std::cerr << "\n\n     descriptions. " << Data_Type << " can not be readed. ";

        std::cerr << "\n\n     Please check the description.";

        std::cerr << "\n\n     The process will be interrupted ..";

        this->Print_End_of_Program();

        exit(1);
     }
}

void Source_File_Descriptions_Reader::Place_Information(char ** Pointer, char * Information, int * index_counter, int Start_Point){

     int String_Size = strlen(Information);

     for(int i=Start_Point;i<String_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
 }

void Source_File_Descriptions_Reader::Clear_Pointer_Memory(char ** Pointer){

      if(*Pointer != nullptr){

          delete [] (*Pointer);

          *Pointer = nullptr;
      }
 }

 bool Source_File_Descriptions_Reader::Check_Empty_Decleration(char * String){

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


 void Source_File_Descriptions_Reader::Place_String(char ** Pointer, char * String){

      int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String);

      int String_Size = strlen(String);

      int index_counter = 0;

      for(int i=Start_Point;i<String_Size;i++){

          (*Pointer)[index_counter] = String[i];

          index_counter++;
      }

      (*Pointer)[index_counter] = '\0';
 }

 char ** Source_File_Descriptions_Reader::Get_Source_File_Locations() const{

         return this->Source_File_Locations;
 }

 char ** Source_File_Descriptions_Reader::Get_Source_File_Names() const{

         return this->Source_File_Names;
 }

 int Source_File_Descriptions_Reader::Get_Source_File_Location_Number() const{

     return this->Source_File_Location_Number;
 }

 int Source_File_Descriptions_Reader::Get_Source_File_Names_Number() const{

     return this->Source_File_Number;
 }
