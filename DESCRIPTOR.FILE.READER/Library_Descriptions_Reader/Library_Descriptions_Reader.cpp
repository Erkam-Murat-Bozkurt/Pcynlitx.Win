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

#include "Library_Descriptions_Reader.h"

Library_Descriptions_Reader::Library_Descriptions_Reader(){

     this->Memory_Delete_Condition = false;

     this->is_empty_decleration = true;

     this->Library_Names = nullptr;

     this->Library_Directories = nullptr;

     this->Library_Directory_Number = 0;

     this->Library_Names_Number = 0;
}

Library_Descriptions_Reader::Library_Descriptions_Reader(const Library_Descriptions_Reader & orig){

}

Library_Descriptions_Reader::~Library_Descriptions_Reader(){

    if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
    }
}

void Library_Descriptions_Reader::Clear_Dynamic_Memory(){

    if(!this->Memory_Delete_Condition){

        this->Memory_Delete_Condition = true;

        if(this->Library_Directories != nullptr){

           for(int i=0;i<this->Library_Directory_Number;i++){

               this->Clear_Pointer_Memory(&(this->Library_Directories[i]));
           }

           delete [] this->Library_Directories;

           this->Library_Directories = nullptr;
        }

        if(this->Library_Names != nullptr){

           for(int i=0;i<this->Library_Names_Number;i++){

               this->Clear_Pointer_Memory(&(this->Library_Names[i]));
           }

           delete [] this->Library_Names;

           this->Library_Names = nullptr;
        }
    }
}

void Library_Descriptions_Reader::Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer){

     this->Data_Collector_Pointer = Pointer;
}

void Library_Descriptions_Reader::Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer){

     this->Initializer_Pointer = Pointer;
}

void Library_Descriptions_Reader::Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer){

     this->Number_Processor_Pointer = Pointer;
}

void Library_Descriptions_Reader::Set_Informations_Comes_From_Data_Collector(){

     this->Library_Directory_Number = this->Data_Collector_Pointer->Library_Directory_Number;

     this->Library_Names_Number = this->Data_Collector_Pointer->Library_Names_Number;
}

void Library_Descriptions_Reader::Read_Library_Descriptions(){

     this->Set_Informations_Comes_From_Data_Collector();

     if(this->Library_Directory_Number > 0){

        this->Receive_Library_Directories();
     }

     if(this->Library_Names_Number > 0){

        this->Receive_Library_Names();
     }

     char ** Library_Names_Pointer = nullptr;

     if(this->Library_Names_Number > 0){

         Library_Names_Pointer = new char * [5*this->Library_Names_Number];

         char Library_Names_subfix [] = ".a";

         char Library_Names_prefix [] = "lib";

         for(int i=0;i<this->Library_Names_Number;i++){

             int Library_Name_Size = strlen(this->Library_Names[i]);

             Library_Names_Pointer[i] = new char [5*Library_Name_Size];

             int index_counter = 0;

             this->Place_Information(&(Library_Names_Pointer[i]),Library_Names_prefix,&index_counter);

             this->Place_Information(&(Library_Names_Pointer[i]),this->Library_Names[i],&index_counter);

             this->Place_Information(&(Library_Names_Pointer[i]),Library_Names_subfix,&index_counter);

             Library_Names_Pointer[i][index_counter] = '\0';
         }
     }

     for(int i=0;i<this->Library_Names_Number;i++){

         bool is_that_library_exist = false;

         for(int k=0;((k<this->Library_Directory_Number) && (!is_that_library_exist));k++){

             is_that_library_exist = this->Directory_Manager.Search_File_in_Directory(this->Library_Directories[k],Library_Names_Pointer[i]);
         }

         if(!is_that_library_exist){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Library_Names\",";

            std::cerr << "\n\n     there is no a file with name \"" << Library_Names_Pointer[i] << "\"-";

            std::cerr << "\n\n     in the directories descripted as library location.";

            std::cerr << "\n\n     Please check \"Library_Names\" description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }
     }

    if(Library_Names_Pointer != nullptr){

       for(int i=0;i<this->Library_Names_Number;i++){

           delete [] Library_Names_Pointer[i];
       }
    }

    delete [] Library_Names_Pointer;
}

void Library_Descriptions_Reader::Receive_Library_Directories(){

     this->Library_Directories = new char * [5*this->Library_Directory_Number];

     for(int i=0;i<this->Library_Directory_Number;i++){

         char * Library_Directory = this->Initializer_Pointer->Get_Library_Directory_List()[i];

         if(this->Check_Empty_Decleration(Library_Directory)){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Library_Locations\",";

            std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

            std::cerr << "\n\n     but there is no decleration at that line. ";

            std::cerr << "\n\n     Please check \"Library_Locations\" description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int Location_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(Library_Directory);

         if(Location_Number == -1){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Library_Locations\",";

            std::cerr << "\n\n     there is an Empty Brace in location number descriptions.";

            std::cerr << "\n\n     Location number data can not be readed.";

            std::cerr << "\n\n     Please check the description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         if(Location_Number == -2){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Library_Locations\",";

            std::cerr << "\n\n     there is an open brace or missing number in file name -";

            std::cerr << "\n\n     descriptions. Location data can not be readed. ";

            std::cerr << "\n\n     Please check the description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int Library_Directory_Name_Size = strlen(Library_Directory);

         this->Library_Directories[i] = new char [5*Library_Directory_Name_Size];

         this->Place_String(&(this->Library_Directories[i]),Library_Directory);
     }
}

void Library_Descriptions_Reader::Receive_Library_Names(){

     this->Library_Names = new char * [5*this->Library_Names_Number];

     for(int i=0;i<this->Library_Names_Number;i++){

         char * Library_Name = this->Initializer_Pointer->Get_Library_Name_List()[i];

         if(this->Check_Empty_Decleration(Library_Name)){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Library_Names\",";

            std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

            std::cerr << "\n\n     but there is no decleration at that line. ";

            std::cerr << "\n\n     Please check \"Library_Names\" description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int Location_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(Library_Name);

         if(Location_Number == -1){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Library_Names\",";

            std::cerr << "\n\n     there is an Empty Brace in names number descriptions.";

            std::cerr << "\n\n     Name data can not be readed. Please check the description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         if(Location_Number == -2){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In the description of \"Library_Names\",";

            std::cerr << "\n\n     there is an open brace or missing number in library name -";

            std::cerr << "\n\n     descriptions. Name data can not be readed. ";

            std::cerr << "\n\n     Please check the description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int Library_Name_Size = strlen(Library_Name);

         this->Library_Names[i] = new char [5*Library_Name_Size];

         this->Place_String(&(this->Library_Names[i]),Library_Name);
     }
}

bool Library_Descriptions_Reader::Check_Empty_Decleration(char * String){

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

void Library_Descriptions_Reader::Print_Read_Error_Information(){

     std::cerr << "\n";

     std::cerr << "\n  # ERROR MESSAGE";

     std::cerr << "\n";

     std::cerr << "\n  # Error Type: Descriptor File Read Error";

     std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

     std::cerr << "\n\n  {";
}

void Library_Descriptions_Reader::Print_End_of_Program(){

     std::cerr << "\n  }";

     std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";
}

void Library_Descriptions_Reader::Clear_Pointer_Memory(char ** Pointer){

      if(*Pointer != nullptr){

          delete [] (*Pointer);

          *Pointer = nullptr;
      }
 }

 void Library_Descriptions_Reader::Place_Information(char ** Pointer, char * String, int * index_counter){

      int String_Size = strlen(String);

      for(int i=0;i<String_Size;i++){

          (*Pointer)[(*index_counter)] = String[i];

          (*index_counter)++;
      }
 }

 void Library_Descriptions_Reader::Place_String(char ** Pointer, char * String){

      int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String);

      int String_Size = strlen(String);

      int index_counter = 0;

      for(int i=Start_Point;i<String_Size;i++){

          (*Pointer)[index_counter] = String[i];

          index_counter++;
      }

      (*Pointer)[index_counter] = '\0';
 }

 char ** Library_Descriptions_Reader::Get_Library_Directories() const{

         return this->Library_Directories;
 }

 char ** Library_Descriptions_Reader::Get_Library_Names() const{

         return this->Library_Names;
 }

 int Library_Descriptions_Reader::Get_Library_Directory_Number() const{

     return this->Library_Directory_Number;
 }

 int Library_Descriptions_Reader::Get_Library_Names_Number() const{

     return this->Library_Names_Number;
 }
