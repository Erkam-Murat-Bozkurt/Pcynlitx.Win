
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

#include "Inter_Thread_Class_Description_Reader.h"

Inter_Thread_Class_Description_Reader::Inter_Thread_Class_Description_Reader(){

     this->Memory_Delete_Condition = false;

     this->is_empty_decleration = true;

     this->Data_Collector_Pointer = nullptr;

     this->Initializer_Pointer = nullptr;

     this->Number_Processor_Pointer = nullptr;

     this->ID_Description_Reader = nullptr;

     this->Header_File_Data_Type_Pointer = nullptr;

     this->Include_Directory_Pointer = nullptr;

     this->Class_Instance_Data_Type_Pointer = nullptr;

     this->Class_Data_Type_Pointer = nullptr;

     this->Include_Directory_Number = 0;

     this->Inter_Thread_Class_Number = 0;

     this->Inter_Thread_Class_Header_File_Names_Number = 0;
}

Inter_Thread_Class_Description_Reader::Inter_Thread_Class_Description_Reader(const Inter_Thread_Class_Description_Reader & orig){

}

Inter_Thread_Class_Description_Reader::~Inter_Thread_Class_Description_Reader(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
}

void Inter_Thread_Class_Description_Reader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Class_Data_Type_Pointer != nullptr){

            for(int i=0;i<this->Inter_Thread_Class_Number;i++){

                this->Clear_Pointer_Memory(&this->Class_Data_Type_Pointer[i].Class_Name);

                this->Clear_Pointer_Memory(&this->Class_Data_Type_Pointer[i].Class_Instance_Name);

                this->Clear_Pointer_Memory(&this->Class_Data_Type_Pointer[i].Header_File_Name);

                this->Clear_Pointer_Memory(&this->Class_Data_Type_Pointer[i].Header_File_Location);
            }

            delete [] this->Class_Data_Type_Pointer;

            this->Class_Data_Type_Pointer = nullptr;
         }

         this->Directory_Manager.Clear_Dynamic_Memory();
      }
}

void Inter_Thread_Class_Description_Reader::Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer){

     this->Data_Collector_Pointer = Pointer;
}

void Inter_Thread_Class_Description_Reader::Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer){

     this->Initializer_Pointer = Pointer;
}

void Inter_Thread_Class_Description_Reader::Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer){

     this->Number_Processor_Pointer = Pointer;
}

void Inter_Thread_Class_Description_Reader::Receive_Include_Directory_Description_Reader(Include_Directory_Description_Reader * Pointer){

     this->ID_Description_Reader = Pointer;

     this->Include_Directory_Pointer = this->ID_Description_Reader->Get_Include_Directory();
}

void Inter_Thread_Class_Description_Reader::Set_Informations_Comes_From_Data_Collector(){

     this->Include_Directory_Number = this->Data_Collector_Pointer->Include_Directory_Numbers;

     this->Inter_Thread_Class_Number = this->Data_Collector_Pointer->Class_Number;

     this->Inter_Thread_Class_Header_File_Names_Number = this->Data_Collector_Pointer->Inter_Thread_Class_Header_File_Names_Number;
}

void Inter_Thread_Class_Description_Reader::Read_Inter_Thread_Class_Descriptions(){

     this->Memory_Delete_Condition = false;

     this->Set_Informations_Comes_From_Data_Collector();

     if(this->Inter_Thread_Class_Number > 0){

        this->Receive_Inter_Thread_Class_Header_File_Names();

        this->Receive_Inter_Thread_Class_Instance_Names();

        this->Receive_Inter_Thread_Class_Names();
     }
}

void Inter_Thread_Class_Description_Reader::Receive_Inter_Thread_Class_Header_File_Names(){

     int index_counter = 0, Header_File_Location_Counter = 0;

     this->Header_File_Data_Type_Pointer = new Header_File_Data_Type [10*this->Inter_Thread_Class_Header_File_Names_Number];

      for(int i=0;i<this->Inter_Thread_Class_Header_File_Names_Number;i++){

          char * String_Line = this->Initializer_Pointer->Get_Inter_Thread_Class_Header_File_List()[i];

          if(this->Check_Empty_Decleration(String_Line)){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Header_File_Names\",";

             std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

             std::cerr << "\n\n     but there is no decleration at that line. ";

             std::cerr << "\n\n     Please check \"Inter_Thread_Class_Header_File_Names\" description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          int Class_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

          if(Class_Number == -1){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Header_File_Names\",";

             std::cerr << "\n\n     there is an Empty Brace in class number descriptions.";

             std::cerr << "\n\n     Class number data can not be readed. (The leak of number in the brace)";

             std::cerr << "\n\n     Please check Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          if(Class_Number == -2){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Header_File_Names\",";

             std::cerr << "\n\n     there is an open brace or missing number in class number descriptions.";

             std::cerr << "\n\n     Class number data can not be readed. ";

             std::cerr << "\n\n     Please check Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          this->Header_File_Data_Type_Pointer[index_counter].Class_Number = Class_Number;

          int File_Location_Number = this->Number_Processor_Pointer->Read_Second_Record_Number_From_String_Line(String_Line);

          if(File_Location_Number == -1){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Header_File_Names\",";

             std::cerr << "\n\n     There is an empy brace in header file location number decleration.";

             std::cerr << "\n\n     Data can not be readed. Please check description.";

             std::cerr << "\n\n     Please check Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          if(File_Location_Number == -2){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Header_File_Names\",";

             std::cerr << "\n\n     there is an open brace or missing number in header file location number -.";

             std::cerr << "\n\n     descriptions. Data can not be readed. Please check description.";

             std::cerr << "\n\n     Please check Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          bool Wrong_Include_Directory_Set_Condition = true;

          for(int k=0;k<this->Include_Directory_Number;k++){

              int Include_Directory_Number = this->Include_Directory_Pointer[k].Directory_Number;

              if(Include_Directory_Number == File_Location_Number){

                 Wrong_Include_Directory_Set_Condition = false;
              }
          }

          if(Wrong_Include_Directory_Set_Condition){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Header_File_Names\",";

             std::cerr << "\n\n     header file location can not be readed correctly.";

             std::cerr << "\n\n     The number which indicates file location is wrong.";

             std::cerr << "\n\n     There is no such a location in the description of Header_File_Locations.";

             std::cerr << "\n\n     Please check Inter_Thread_Data_Type_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          for(int k=0;k<this->Include_Directory_Number;k++){

              if(File_Location_Number == this->Include_Directory_Pointer[k].Directory_Number){

                char * Include_Directory_String = this->Include_Directory_Pointer[k].Include_Directory;

                int Include_Directory_String_Size = strlen(Include_Directory_String);

                this->Header_File_Data_Type_Pointer[index_counter].File_Location = new char [10*Include_Directory_String_Size];

                this->Place_String(&(this->Header_File_Data_Type_Pointer[index_counter].File_Location),Include_Directory_String);

                Header_File_Location_Counter++;
              }
          }

          int String_Size = strlen(String_Line);

          this->Header_File_Data_Type_Pointer[index_counter].Header_File_Name = new char [10*String_Size];

          this->Place_String(&(this->Header_File_Data_Type_Pointer[index_counter].Header_File_Name),String_Line);

          char * File_Location = nullptr;

          char * File_Name = nullptr;

          if(this->Header_File_Data_Type_Pointer[index_counter].File_Location != nullptr){

             File_Location = this->Header_File_Data_Type_Pointer[index_counter].File_Location;
          }

          if(this->Header_File_Data_Type_Pointer[index_counter].Header_File_Name != nullptr){

             File_Name = this->Header_File_Data_Type_Pointer[index_counter].Header_File_Name;
          }

          if(((File_Location != nullptr) && (File_Name != nullptr))){

               bool is_that_file_exist = this->Directory_Manager.Search_File_in_Directory(File_Location,File_Name);

               if(!is_that_file_exist){

                   this->Print_Read_Error_Information();

                   std::cerr << "\n     In description of \"Inter_Thread_Class_Header_File_Names\",";

                   std::cerr << "\n\n     there is no a file with name \"" << File_Name << "\" in directory -";

                   std::cerr << "\n\n     \"" << File_Location << "\"";

                   std::cerr << "\n\n     Please check \"Inter_Thread_Class_Header_File_Names\" description.";

                   std::cerr << "\n\n     The process will be interrupted ..";

                   this->Print_End_of_Program();

                   exit(1);
               }
          }

          index_counter++;
       }

       if(Header_File_Location_Counter < index_counter){

          this->Print_Read_Error_Information();

          std::cerr << "\n     In \"Inter_Thread_Class_Header_File_Names\" description,";

          std::cerr << "\n\n     The location of some header files can not be determined ..";

          std::cerr << "\n\n     Plase check class header file location declerations!";

          std::cerr << "\n\n     The process will be interrupted ..";

          this->Print_End_of_Program();

          exit(1);
       }
 }

 void Inter_Thread_Class_Description_Reader::Receive_Inter_Thread_Class_Instance_Names(){

      int index_counter = 0, Class_Number_Counter = 0;

      this->Class_Instance_Data_Type_Pointer = new Class_Instance_Data_Type [10*this->Inter_Thread_Class_Number];

      for(int i=0;i<this->Inter_Thread_Class_Number;i++){

          char * String_Line = this->Initializer_Pointer->Get_Inter_Thread_Class_Instance_Name_List()[i];

          int String_Size = strlen(String_Line);

          this->Class_Instance_Data_Type_Pointer[index_counter].Class_Instance_Name = new char [10*String_Size];

          this->Place_String(&(this->Class_Instance_Data_Type_Pointer[index_counter].Class_Instance_Name),String_Line);

          int Class_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

          if(Class_Number == -1){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Instance_Names\",";

             std::cerr << "\n\n     there is an Empty Brace in class number descriptions.";

             std::cerr << "\n\n     Class number data can not be readed. (The leak of number in the brace)";

             std::cerr << "\n\n     Please check Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          if(Class_Number == -2){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Instance_Names\",";

             std::cerr << "\n\n     there is an open brace or missing number in class number descriptions.";

             std::cerr << "\n\n     Class number data can not be readed. ";

             std::cerr << "\n\n     Please check Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          if(this->Check_Empty_Decleration(String_Line)){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Instance_Names\",";

             std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

             std::cerr << "\n\n     but there is no decleration at that line. ";

             std::cerr << "\n\n     Please check \"Inter_Thread_Class_Instance_Names\" description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          this->Class_Instance_Data_Type_Pointer[index_counter].Class_Number = Class_Number;

          index_counter++;
      }
 }

 void Inter_Thread_Class_Description_Reader::Receive_Inter_Thread_Class_Names(){

      int index_counter = 0, Total_Class_Number = this->Inter_Thread_Class_Number;

      int * Class_Number_List = new int [10*Total_Class_Number];

      int * Header_File_Number_holder = new int [10*Total_Class_Number];

      int * Class_Instance_Name_Number_Holder = new int [10*Total_Class_Number];

      int Class_Instance_Name_Counter = 0;

      int Class_Header_File_Counter = 0;

      this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Header_File_Number_holder,2*Total_Class_Number);

      this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Class_Instance_Name_Number_Holder,2*Total_Class_Number);

      this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Class_Number_List,2*Total_Class_Number);

      bool Read_Error_Condition = false;

      this->Class_Data_Type_Pointer = new Class_Data_Type  [10*Total_Class_Number];

      for(int i=0;i<this->Inter_Thread_Class_Number;i++){

          char * String_Line = this->Initializer_Pointer->Get_Inter_Thread_Class_Names_List()[i];

          int String_Size    = strlen(String_Line);

          this->Class_Data_Type_Pointer[index_counter].Class_Name = new char [10*String_Size];

          this->Place_String(&(this->Class_Data_Type_Pointer[index_counter].Class_Name),String_Line);

          int Class_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

          if(this->Check_Empty_Decleration(String_Line)){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Names\",";

             std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

             std::cerr << "\n\n     but there is no decleration at that line. ";

             std::cerr << "\n\n     Please check \"Inter_Thread_Class_Names\" description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          if(Class_Number == -1){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Names\",";

             std::cerr << "\n\n     there is an Empty Brace in class number descriptions.";

             std::cerr << "\n\n     Class number data can not be readed. (The leak of number in the brace)";

             std::cerr << "\n\n     Please check Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          if(Class_Number == -2){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In description of \"Inter_Thread_Class_Names\",";

             std::cerr << "\n\n     there is an open brace or missing number in class number descriptions.";

             std::cerr << "\n\n     Class number data can not be readed. ";

             std::cerr << "\n\n     Please check Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          /*  Inter_Thread_Class_Header_File_Names record start point  */


          bool Wrong_Class_Number_for_header_file = true;

          for(int k=0;k<this->Inter_Thread_Class_Number;k++){

              if(this->Header_File_Data_Type_Pointer[k].Class_Number == Class_Number){

                  Wrong_Class_Number_for_header_file = false;
              }
          }

          if(Wrong_Class_Number_for_header_file){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In \"Inter_Thread_Class_Header_File_Names\" description,";

             std::cerr << "\n\n     There is a class numbers mistach between Inter_Thread_Class_Names -";

             std::cerr << "\n\n     description and Inter_Thread_Class_Header_File_Names description.";

             std::cerr << "\n\n     There is no such a class which descripted with this number in -";

             std::cerr << "\n\n     \"Inter_Thread_Class_Names\" description.";

             std::cerr << "\n\n     Class numbers can not be readed. Please check declerations.";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
          }

          Class_Number_List[index_counter] = Class_Number;

          bool Number_Repitation = this->Number_Processor_Pointer->Check_Number_Repitation(Class_Number_List,Total_Class_Number);

          if(Number_Repitation){

              this->Print_Read_Error_Information();

              std::cerr << "\n     In \"Inter_Thread_Class_Header_File_Names\" description,";

              std::cerr << "\n\n     The same class number readed more than ones time ..";

              std::cerr << "\n\n     Please check class number declerations";

              std::cerr << "\n\n     Process will be interrupted ..";

              this->Print_End_of_Program();

              exit(1);
          }

          this->Class_Data_Type_Pointer[index_counter].Class_Number = Class_Number;

          this->Class_Data_Type_Pointer[index_counter].Total_Class_Number = Total_Class_Number;

          for(int k=0;k<Total_Class_Number;k++){

              if(Class_Number == this->Header_File_Data_Type_Pointer[k].Class_Number){

                 if(Header_File_Number_holder[Class_Number] != 0){

                    this->Print_Read_Error_Information();

                    std::cerr << "\n     In \"Inter_Thread_Class_Header_File_Names\" description,";

                    std::cerr << "\n\n     Some of the header files has same class number .";

                    std::cerr << "\n\n     Each header file must have different class number ..";

                    std::cerr << "\n\n     Please check header files declerations";

                    std::cerr << "\n\n     The process will be interrupted ..";

                    this->Print_End_of_Program();

                    exit(1);
                 }

                 Header_File_Number_holder[Class_Number] = 1;

                 Class_Header_File_Counter++;

                 char * Header_File_Name = this->Header_File_Data_Type_Pointer[k].Header_File_Name;

                 int Header_File_Name_Size = strlen(Header_File_Name);

                 this->Class_Data_Type_Pointer[index_counter].Header_File_Name = new char [10*Header_File_Name_Size];

                 this->Place_String(&(this->Class_Data_Type_Pointer[index_counter].Header_File_Name),Header_File_Name);

                 char * File_Location = this->Header_File_Data_Type_Pointer[k].File_Location;

                 int Location_Name_Size = strlen(File_Location);

                 this->Class_Data_Type_Pointer[index_counter].Header_File_Location = new char [10*Location_Name_Size];

                 this->Place_String(&(this->Class_Data_Type_Pointer[index_counter].Header_File_Location),File_Location);
              }
          }


          /* Class instance name record operation start point .. */


          bool Wrong_Class_Instance_Names_Read = true;

          for(int k=0;k<this->Inter_Thread_Class_Number;k++){

              if(this->Class_Instance_Data_Type_Pointer[k].Class_Number == Class_Number){

                 Wrong_Class_Instance_Names_Read = false;
              }
          }

          if(Wrong_Class_Instance_Names_Read){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In \"Inter_Thread_Class_Names\" description,";

             std::cerr << "\n\n     there are class numbers mistach between Inter_Thread_Class_Names -";

             std::cerr << "\n\n     description and \"Inter_Thread_Class_Instance_Names\" description.";

             std::cerr << "\n\n     Class number in \"Inter_Thread_Class_Instance_Names\" is wrong.";

             std::cerr << "\n\n     There is no class which described with this number in -";

             std::cerr << "\n\n     Inter_Thread_Class_Names description.";

             std::cerr << "\n\n     Class numbers can not be readed correctly.";

             std::cerr << "\n\n     Please check declerations. The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
         }

          for(int k=0;k<Total_Class_Number;k++){

              if(Class_Number == this->Class_Instance_Data_Type_Pointer[k].Class_Number){

                 if(Class_Instance_Name_Number_Holder[Class_Number] != 0){

                    this->Print_Read_Error_Information();

                    std::cerr << "\n     In \"Inter_Thread_Class_Instance_Names\" description,";

                    std::cerr << "\n\n     Some of the class instance name has the same class number .";

                    std::cerr << "\n\n     Each class instance name must have different class number ..";

                    std::cerr << "\n\n     Please check class instance name declerations";

                    std::cerr << "\n\n     The process will be interrupted ..";

                    this->Print_End_of_Program();

                    exit(1);
                 }

                 Class_Instance_Name_Counter++;

                 Class_Instance_Name_Number_Holder[Class_Number] = 1;

                 char * Class_Instance_Name = this->Class_Instance_Data_Type_Pointer[k].Class_Instance_Name;

                 int Class_Instance_Name_Size = strlen(Class_Instance_Name);

                 this->Class_Data_Type_Pointer[index_counter].Class_Instance_Name = new char [10*Class_Instance_Name_Size];

                 this->Place_String(&(this->Class_Data_Type_Pointer[index_counter].Class_Instance_Name),Class_Instance_Name);
              }
          }

          index_counter++;
      }

      if(Class_Header_File_Counter < Total_Class_Number){

         this->Print_Read_Error_Information();

         std::cerr << "\n     In \"Inter_Thread_Class_Header_File_Names\" description,";

         std::cerr << "\n\n     Header file number - Class number mismach !.";

         std::cerr << "\n\n     Class Numbers of header files can not read correctly.";

         std::cerr << "\n\n     Each header file name must include a true class number ..";

         std::cerr << "\n\n     Please check header file name declerations";

         std::cerr << "\n\n     The process will be interrupted ..";

         this->Print_End_of_Program();

         exit(1);
      }

      if(Class_Instance_Name_Counter < Total_Class_Number){

         this->Print_Read_Error_Information();

         std::cerr << "\n     In \"Inter_Thread_Class_Header_File_Names\" description,";

         std::cerr << "\n\n     Class instance number - Class number mismach !.";

         std::cerr << "\n\n     The class Numbers of the class instances can not read correctly.";

         std::cerr << "\n\n     Each class instance name must include a true class number ..";

         std::cerr << "\n\n     Please class instance name declerations";

         std::cerr << "\n\n     The process will be interrupted ..";

         this->Print_End_of_Program();

         exit(1);
      }


      if(this->Header_File_Data_Type_Pointer != nullptr){

         for(int i=0;i<Total_Class_Number;i++){

             this->Clear_Pointer_Memory(&(this->Header_File_Data_Type_Pointer[i].Header_File_Name));

             this->Clear_Pointer_Memory(&(this->Header_File_Data_Type_Pointer[i].File_Location));
         }

         delete [] this->Header_File_Data_Type_Pointer;

         this->Header_File_Data_Type_Pointer = nullptr;
      }

      if(this->Class_Instance_Data_Type_Pointer != nullptr){

         for(int i=0;i<Total_Class_Number;i++){

             this->Clear_Pointer_Memory(&(this->Class_Instance_Data_Type_Pointer[i].Class_Instance_Name));
         }

         delete [] this->Class_Instance_Data_Type_Pointer;

         this->Class_Instance_Data_Type_Pointer = nullptr;
      }

      delete [] Class_Number_List;

      delete [] Header_File_Number_holder;

      delete [] Class_Instance_Name_Number_Holder;
}

void Inter_Thread_Class_Description_Reader::Clear_Pointer_Memory(char ** Pointer){

      if(*Pointer != nullptr){

          delete [] (*Pointer);

          *Pointer = nullptr;
      }
 }

 void Inter_Thread_Class_Description_Reader::Place_String(char ** Pointer, char * String){

      int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String);

      int String_Size = strlen(String);

      int index_counter = 0;

      for(int i=Start_Point;i<String_Size;i++){

          (*Pointer)[index_counter] = String[i];

          index_counter++;
      }

      (*Pointer)[index_counter] = '\0';
 }

bool Inter_Thread_Class_Description_Reader::Check_Empty_Decleration(char * String){

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

void Inter_Thread_Class_Description_Reader::Print_Read_Error_Information(){

     std::cerr << "\n";

     std::cerr << "\n  # ERROR MESSAGE";

     std::cerr << "\n";

     std::cerr << "\n  # Error Type: Descriptor File Read Error";

     std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

     std::cerr << "\n\n  {";
}

void Inter_Thread_Class_Description_Reader::Print_End_of_Program(){

     std::cerr << "\n  }";

     std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";
}

Class_Data_Type * Inter_Thread_Class_Description_Reader::Get_Class_Names() const{

        return this->Class_Data_Type_Pointer;
}

int Inter_Thread_Class_Description_Reader::Get_Class_Number() const {

     return this->Inter_Thread_Class_Number;
}
