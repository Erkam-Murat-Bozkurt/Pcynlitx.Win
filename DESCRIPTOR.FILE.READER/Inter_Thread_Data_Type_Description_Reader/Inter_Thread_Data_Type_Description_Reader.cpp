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

#include "Inter_Thread_Data_Type_Description_Reader.h"

Inter_Thread_Data_Type_Description_Reader::Inter_Thread_Data_Type_Description_Reader(){

    this->Memory_Delete_Condition = false;

    this->is_empty_decleration = true;

    this->Data_Collector_Pointer = nullptr;

    this->Initializer_Pointer = nullptr;

    this->Number_Processor_Pointer = nullptr;

    this->ID_Description_Reader = nullptr;

    this->Shared_Memory_Header_Pointer = nullptr;

    this->Shared_Memory_Pointer_Names_Holder = nullptr;

    this->Include_Directory_Pointer = nullptr;

    this->Shared_Memory_Data_Type_Pointer = nullptr;

    this->Shared_Data_Types_Header_File_Names_Number = 0;

    this->Shared_Data_Types_Number = 0;

    this->Include_Directory_Number = 0;
}

Inter_Thread_Data_Type_Description_Reader::Inter_Thread_Data_Type_Description_Reader(const Inter_Thread_Data_Type_Description_Reader & orig){

}

Inter_Thread_Data_Type_Description_Reader::~Inter_Thread_Data_Type_Description_Reader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
    }
}

void Inter_Thread_Data_Type_Description_Reader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Shared_Memory_Data_Type_Pointer != nullptr){

            for(int i=0;i<this->Shared_Data_Types_Number;i++){

                this->Clear_Pointer_Memory(&this->Shared_Memory_Data_Type_Pointer[i].Data_Type);

                this->Clear_Pointer_Memory(&this->Shared_Memory_Data_Type_Pointer[i].Header_File_Name);

                this->Clear_Pointer_Memory(&this->Shared_Memory_Data_Type_Pointer[i].Include_Directory);

                this->Clear_Pointer_Memory(&this->Shared_Memory_Data_Type_Pointer[i].Pointer_Name);
            }

            delete [] this->Shared_Memory_Data_Type_Pointer;

            this->Shared_Memory_Data_Type_Pointer = nullptr;
         }
     }
}

void Inter_Thread_Data_Type_Description_Reader::Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer){

     this->Data_Collector_Pointer = Pointer;
}

void Inter_Thread_Data_Type_Description_Reader::Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer){

     this->Initializer_Pointer = Pointer;
}

void Inter_Thread_Data_Type_Description_Reader::Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer){

     this->Number_Processor_Pointer = Pointer;
}

void Inter_Thread_Data_Type_Description_Reader::Receive_Include_Directory_Description_Reader(Include_Directory_Description_Reader * Pointer){

     this->ID_Description_Reader = Pointer;

     this->Include_Directory_Pointer = this->ID_Description_Reader->Get_Include_Directory();
}

void Inter_Thread_Data_Type_Description_Reader::Set_Informations_Comes_From_Data_Collector(){

     this->Include_Directory_Number = this->Data_Collector_Pointer->Include_Directory_Numbers;

     this->Shared_Data_Types_Number = this->Data_Collector_Pointer->Shared_Data_Types_Number;

     this->Shared_Data_Types_Header_File_Names_Number = this->Data_Collector_Pointer->Shared_Data_Types_Include_File_Names_Number;
}

void Inter_Thread_Data_Type_Description_Reader::Read_Inter_Thread_Data_Type_Descriptions(){

     this->Memory_Delete_Condition = false;

     this->Set_Informations_Comes_From_Data_Collector();

     if(this->Include_Directory_Number > 0){

        this->Receive_Include_Directory();
     }

     if(this->Shared_Data_Types_Number > 0){

        this->Receive_Shared_Memory_Data_Types_Header_File_Names();

        this->Receive_Shared_Memory_Pointer_Names();

        this->Receive_Shared_Memory_Data_Types();
     }
}

void Inter_Thread_Data_Type_Description_Reader::Receive_Include_Directory(){

     int index_counter = 0;

     int * Directory_Number_Holder = new int [10*this->Include_Directory_Number];

     this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Directory_Number_Holder,10*this->Include_Directory_Number);

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

         int Include_Directory_Number =  this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

         if(Directory_Number_Holder[Include_Directory_Number] != 0){

            this->Print_Read_Error_Information();

            std::cerr << "\n     Some of the include directories has the same directory number !";

            std::cerr << "\n\n     Each directory must have different number..";

            std::cerr << "\n\n     Plase check include directories declerations!";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         Directory_Number_Holder[Include_Directory_Number] = 1;

         this->Include_Directory_Pointer[index_counter].Directory_Number = Include_Directory_Number;

         this->Include_Directory_Pointer[index_counter].Total_Include_Directory_Number = this->Include_Directory_Number;

         int String_Size = strlen(String_Line);

         this->Include_Directory_Pointer[index_counter].Include_Directory = new char [10*String_Size];

         this->Place_String(&(this->Include_Directory_Pointer[index_counter].Include_Directory),String_Line);

         index_counter++;
     }

     delete [] Directory_Number_Holder;
 }


void Inter_Thread_Data_Type_Description_Reader::Receive_Shared_Memory_Data_Types_Header_File_Names(){

     int * Data_Type_Number_holder = new int [10*this->Shared_Data_Types_Number];

     this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Data_Type_Number_holder,10*this->Shared_Data_Types_Number);

     this->Shared_Memory_Header_Pointer = new Shared_Memory_Header [10*this->Shared_Data_Types_Number];

     if(this->Initializer_Pointer->Get_Shared_Data_Type_Header_File_List() != nullptr){

        for(int i=0;i<this->Shared_Data_Types_Number;i++){

            if(this->Initializer_Pointer->Get_Shared_Data_Type_Header_File_List()[i] != nullptr){

               char * String_Line = this->Initializer_Pointer->Get_Shared_Data_Type_Header_File_List()[i];

               if(this->Check_Empty_Decleration(String_Line)){

                  this->Print_Read_Error_Information();

                  std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\",";

                  std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

                  std::cerr << "\n\n     but there is no decleration at that line. ";

                  std::cerr << "\n\n     Please check \"Inter_Thread_Data_Type_Header_File_Names\" description.";

                  std::cerr << "\n\n     The process will be interrupted ..";

                  this->Print_End_of_Program();

                  exit(1);
               }

               int String_Size = strlen(String_Line);

               int Data_Type_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

               if(Data_Type_Number == -1){

                  this->Print_Read_Error_Information();

                  std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\",";

                  std::cerr << "\n\n     there is an Empty Brace in data type number descriptions.";

                  std::cerr << "\n\n     Data type number data can not be readed. (The leak of number in the brace)";

                  std::cerr << "\n\n     Please check description. The process will be interrupted ..";

                  this->Print_End_of_Program();

                  exit(1);
               }

               if(Data_Type_Number == -2){

                  this->Print_Read_Error_Information();

                  std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\",";

                  std::cerr << "\n\n     there is an open brace or missing number in data type number descriptions.";

                  std::cerr << "\n\n     Data type number can not be readed. Please check description.";

                  std::cerr << "\n\n     The process will be interrupted ..";

                  this->Print_End_of_Program();

                  exit(1);
               }

               this->Shared_Memory_Header_Pointer[i].Data_Type_Number = new int;

               this->Shared_Memory_Header_Pointer[i].Data_Type_Number[0] = Data_Type_Number;

               int File_Location_Number = this->Number_Processor_Pointer->Read_Second_Record_Number_From_String_Line(String_Line);

               if(File_Location_Number == -1){

                  this->Print_Read_Error_Information();

                  std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\",";

                  std::cerr << "\n\n     There is an empy brace in header file location number decleration.";

                  std::cerr << "\n\n     The data can not be readed. Please check description.";

                  std::cerr << "\n\n     The process will be interrupted ..";

                  this->Print_End_of_Program();

                  exit(1);
               }

               if(File_Location_Number == -2){

                  this->Print_Read_Error_Information();

                  std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\",";

                  std::cerr << "\n\n     there is an open brace or missing number in header file location number -";

                  std::cerr << "\n\n     descriptions. Data can not be readed. Please check description.";

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

                  std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\",";

                  std::cerr << "\n\n     header file location can not be readed correctly.";

                  std::cerr << "\n\n     The number which indicates the file location is wrong.";

                  std::cerr << "\n\n     There is no such a location in the description of Header_File_Locations.";

                  std::cerr << "\n\n     Please check description. The process will be interrupted ..";

                  this->Print_End_of_Program();

                  exit(1);
                }

                Data_Type_Number_holder [i] = Data_Type_Number;

                bool Number_Repitation = this->Number_Processor_Pointer->Check_Number_Repitation(Data_Type_Number_holder,this->Shared_Data_Types_Number);

                if(Number_Repitation){

                   this->Print_Read_Error_Information();

                   std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\",";

                   std::cerr << "\n\n     the some data type number readed more than ones time !";

                   std::cerr << "\n\n     Each data type must have different number ..";

                   std::cerr << "\n\n     Please check data type number declerations in description";

                   std::cerr << "\n\n     Process will be interrupted ..";

                   this->Print_End_of_Program();

                   exit(1);
                }

                for(int k=0;k<this->Include_Directory_Number;k++){

                    if(File_Location_Number == this->Include_Directory_Pointer[k].Directory_Number){

                       char * File_Location = this->Include_Directory_Pointer[k].Include_Directory;

                       int Location_Name_Size = strlen(File_Location);

                       this->Shared_Memory_Header_Pointer[i].Include_Directory = new char [10*Location_Name_Size];

                       this->Place_String(&(this->Shared_Memory_Header_Pointer[i].Include_Directory),File_Location);

                       break;
                    }
                 }

                 this->Shared_Memory_Header_Pointer[i].Header_File_Name = new char [10*String_Size];

                 this->Place_String(&(this->Shared_Memory_Header_Pointer[i].Header_File_Name),String_Line);

                 char * File_Location = nullptr;

                 char * File_Name = nullptr;

                 if(this->Shared_Memory_Header_Pointer[i].Include_Directory != nullptr){

                    File_Location = this->Shared_Memory_Header_Pointer[i].Include_Directory;
                 }

                 if(this->Shared_Memory_Header_Pointer[i].Header_File_Name != nullptr){

                    File_Name = this->Shared_Memory_Header_Pointer[i].Header_File_Name;
                 }

                 if(((File_Location != nullptr) && (File_Name != nullptr))){

                      bool is_that_file_exist = this->Directory_Manager.Search_File_in_Directory(File_Location,File_Name);

                      if(!is_that_file_exist){

                          this->Print_Read_Error_Information();

                          std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\",";

                          std::cerr << "\n\n     there is no a file with name \"" << File_Name << "\" in directory -";

                          std::cerr << "\n\n     \"" << File_Location << "\"";

                          std::cerr << "\n\n     Please check Inter_Thread_Data_Type_Header_File_Names description.";

                          std::cerr << "\n\n     The process will be interrupted ..";

                          this->Print_End_of_Program();

                          exit(1);
                       }
                  }
             }
             else{

                   this->Shared_Memory_Header_Pointer[i].Header_File_Name = nullptr;

                   this->Shared_Memory_Header_Pointer[i].Include_Directory = nullptr;

                   this->Shared_Memory_Header_Pointer[i].Data_Type_Number = nullptr;
             }
        }
    }
    else{

          for(int i=0;i<this->Shared_Data_Types_Number;i++){

              this->Shared_Memory_Header_Pointer[i].Header_File_Name = nullptr;

              this->Shared_Memory_Header_Pointer[i].Include_Directory = nullptr;

              this->Shared_Memory_Header_Pointer[i].Data_Type_Number = nullptr;
          }
    }

    delete [] Data_Type_Number_holder;
}

void Inter_Thread_Data_Type_Description_Reader::Receive_Shared_Memory_Pointer_Names(){

     int index_counter = 0;

     this->Shared_Memory_Pointer_Names_Holder = new Shared_Memory_Pointer [10*this->Shared_Data_Types_Number];

     for(int i= 0;i<this->Shared_Data_Types_Number;i++){

         char * String_Line   = this->Initializer_Pointer->Get_Shared_Memory_Pointer_Name_List()[i];

         if(this->Check_Empty_Decleration(String_Line)){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Pointer_Names\",";

            std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

            std::cerr << "\n\n     but there is no decleration at that line. ";

            std::cerr << "\n\n     Please check \"Inter_Thread_Data_Type_Pointer_Names\" description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int Data_Type_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

         if(Data_Type_Number == -1){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Pointer_Names\",";

            std::cerr << "\n\n     there is an Empty Brace in data type number descriptions.";

            std::cerr << "\n\n     Data type number can not be readed. (The leak of number in the brace)";

            std::cerr << "\n\n     Please check Inter_Thread_Data_Type_Pointer_Names description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         if(Data_Type_Number == -2){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Pointer_Names\",";

            std::cerr << "\n\n     there is an open brace or missing number in data type number -";

            std::cerr << "\n\n     descriptions. Data type number can not be readed. ";

            std::cerr << "\n\n     Please check description. The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         this->Shared_Memory_Pointer_Names_Holder[index_counter].Data_Type_Number = Data_Type_Number;

         int String_Size = strlen(String_Line);

         this->Shared_Memory_Pointer_Names_Holder[index_counter].Pointer_Names = new char [10*String_Size];

         this->Place_String(&(this->Shared_Memory_Pointer_Names_Holder[index_counter].Pointer_Names),String_Line);

         index_counter++;
     }
}

void Inter_Thread_Data_Type_Description_Reader::Receive_Shared_Memory_Data_Types(){

     int index_counter = 0;

     int * Data_Type_Number_holder     = new int [10*this->Shared_Data_Types_Number];

     int * Header_Names_Number_Holder  = new int [10*this->Shared_Data_Types_Number];

     int * Pointer_Names_Number_Holder = new int [10*this->Shared_Data_Types_Number];

     this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Data_Type_Number_holder,10*this->Shared_Data_Types_Number);

     this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Header_Names_Number_Holder,10*this->Shared_Data_Types_Number);

     this->Number_Processor_Pointer->Set_Zero_For_Integer_List(&Pointer_Names_Number_Holder,10*this->Shared_Data_Types_Number);

     this->Shared_Memory_Data_Type_Pointer = new Shared_Memory_Data_Type [10*this->Shared_Data_Types_Number];

     for(int i=0;i<this->Shared_Data_Types_Number;i++){

         char * String_Line = this->Initializer_Pointer->Get_Shared_Data_Type_List()[i];

         if(this->Check_Empty_Decleration(String_Line)){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Inter_Thread_Data_Types\",";

            std::cerr << "\n\n     there is an empty decleration. There is a decleration number";

            std::cerr << "\n\n     but there is no decleration at that line. ";

            std::cerr << "\n\n     Please check \"Inter_Thread_Data_Types\" description.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         int String_Size = strlen(String_Line);

         this->Shared_Memory_Data_Type_Pointer[index_counter].Data_Type = new char [10*String_Size];

         this->Place_String(&(this->Shared_Memory_Data_Type_Pointer[index_counter].Data_Type),String_Line);

         int Data_Type_Number = this->Number_Processor_Pointer->Read_Record_Number_From_String_Line(String_Line);

         if(Data_Type_Number == -1){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Inter_Thread_Data_Types\",";

            std::cerr << "\n\n     there is an Empty Brace in data type number descriptions.";

            std::cerr << "\n\n     Data type number can not be readed. (The leak of number in the brace)";

            std::cerr << "\n\n     Please check description. The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         if(Data_Type_Number == -2){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In description of \"Inter_Thread_Data_Types\",";

            std::cerr << "\n\n     there is an open brace or missing number in data type number -";

            std::cerr << "\n\n     descriptions. Data type number data can not be readed.";

            std::cerr << "\n\n     Please check description. The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         this->Shared_Memory_Data_Type_Pointer[index_counter].Data_Number = Data_Type_Number;

         this->Shared_Memory_Data_Type_Pointer[index_counter].Total_Data_Type_Number = this->Shared_Data_Types_Number;

         Data_Type_Number_holder [i] = Data_Type_Number;

         bool Number_Repitation = this->Number_Processor_Pointer->Check_Number_Repitation(Data_Type_Number_holder,this->Shared_Data_Types_Number);

         if(Number_Repitation){

             this->Print_Read_Error_Information();

             std::cerr << "\n     In \"Inter_Thread_Data_Types\" description, ";

             std::cerr << "\n\n     The one of the data type numbers readed more than ones time !";

             std::cerr << "\n\n     Each data type must have different number.";

             std::cerr << "\n\n     Please check data type number declerations";

             std::cerr << "\n\n     The process will be interrupted ..";

             this->Print_End_of_Program();

             exit(1);
         }

         this->Shared_Memory_Data_Type_Pointer[index_counter].Header_File_Name = nullptr;

         this->Shared_Memory_Data_Type_Pointer[index_counter].Include_Directory = nullptr;

         bool Wrong_Data_Type_for_header_file = true;

         if(this->Shared_Memory_Header_Pointer[index_counter].Data_Type_Number == nullptr){

            Wrong_Data_Type_for_header_file = false;
         }

         for(int k=0;k<this->Shared_Data_Types_Number;k++){

             if(this->Shared_Memory_Header_Pointer[k].Data_Type_Number != nullptr){

                if(this->Shared_Memory_Header_Pointer[k].Data_Type_Number[0] == Data_Type_Number){

                   Wrong_Data_Type_for_header_file = false;
                }
             }
             else{

                  Wrong_Data_Type_for_header_file = false;
             }
         }

         if(Wrong_Data_Type_for_header_file){

            this->Print_Read_Error_Information();

            std::cerr << "\n     In \"Inter_Thread_Data_Types\" description,";

            std::cerr << "\n\n     There are data type numbers mistach between Inter_Thread_Data_Types ";

            std::cerr << "\n\n     description and Inter_Thread_Data_Type_Header_File_Names description.";

            std::cerr << "\n\n     Data type numbers con not be readed. Please check declerations.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         bool Wrong_Data_Type_for_Pointer_Names = true;

         for(int k=0;k<this->Shared_Data_Types_Number;k++){

            if(this->Shared_Memory_Pointer_Names_Holder[k].Data_Type_Number == Data_Type_Number){

                Wrong_Data_Type_for_Pointer_Names = false;
            }
         }

         if(Wrong_Data_Type_for_Pointer_Names){

            this->Print_Read_Error_Information();

            std::cerr << "\n     There are data type numbers mistach between Inter_Thread_Data_Type_Pointer_Names";

            std::cerr << "\n\n     description and Inter_Thread_Data_Types description.";

            std::cerr << "\n\n     Data type numbers can not be readed correctly. Please check declerations.";

            std::cerr << "\n\n     The process will be interrupted ..";

            this->Print_End_of_Program();

            exit(1);
         }

         for(int k=0;k<this->Shared_Data_Types_Header_File_Names_Number;k++){

             if(this->Shared_Memory_Header_Pointer[k].Data_Type_Number[0] == Data_Type_Number){

                if(Header_Names_Number_Holder [Data_Type_Number] != 0){

                   this->Print_Read_Error_Information();

                   std::cerr << "\n     In \"Inter_Thread_Data_Type_Header_File_Names\" description,";

                   std::cerr << "\n     The one of the data types has more than one header file .";

                   std::cerr << "\n\n     Each data type must have exactly one header file ..";

                   std::cerr << "\n\n     Please check shared data type header file names declerations";

                   std::cerr << "\n\n     The process will be interrupted ..";

                   this->Print_End_of_Program();

                   exit(1);
                }

                Header_Names_Number_Holder [Data_Type_Number] = 1;

                if(this->Shared_Memory_Header_Pointer[k].Header_File_Name != nullptr){

                   char * File_Name  = this->Shared_Memory_Header_Pointer[k].Header_File_Name;

                   int Header_File_Name_Size = strlen(File_Name);

                   this->Shared_Memory_Data_Type_Pointer[index_counter].Header_File_Name = new char [10*Header_File_Name_Size];

                   this->Place_String(&(this->Shared_Memory_Data_Type_Pointer[index_counter].Header_File_Name),File_Name);
                }
                else{

                     this->Shared_Memory_Data_Type_Pointer[index_counter].Header_File_Name = nullptr;
                }


                if(this->Shared_Memory_Header_Pointer[k].Include_Directory != nullptr){

                   char * Location = this->Shared_Memory_Header_Pointer[k].Include_Directory;

                   int Include_Directory_Name_Size = strlen(Location);

                   this->Shared_Memory_Data_Type_Pointer[index_counter].Include_Directory = new char [10*Include_Directory_Name_Size];

                   this->Place_String(&(this->Shared_Memory_Data_Type_Pointer[index_counter].Include_Directory),Location);
                }
             }
         }

         for(int k=0;k<this->Shared_Data_Types_Number;k++){

              if(Data_Type_Number == this->Shared_Memory_Pointer_Names_Holder[k].Data_Type_Number){

                 if(Pointer_Names_Number_Holder [Data_Type_Number] != 0){

                    this->Print_Read_Error_Information();

                    std::cerr << "\n     In \"Inter_Thread_Data_Type_Pointer_Names\" description,";

                    std::cerr << "\n\n     Some of the data type pointer name has the same data type number .";

                    std::cerr << "\n\n     Each pointer name must have different data type number ..";

                    std::cerr << "\n\n     Please check shared data type pointer names declerations";

                    std::cerr << "\n\n     The process will be interrupted ..";

                    this->Print_End_of_Program();

                    exit(1);
                 }

                 Pointer_Names_Number_Holder [Data_Type_Number] = 1;

                 char * Pointer_Name = this->Shared_Memory_Pointer_Names_Holder[k].Pointer_Names;

                 int Name_Size = strlen(Pointer_Name);

                 this->Shared_Memory_Data_Type_Pointer[index_counter].Pointer_Name = new char [10*Name_Size];

                 this->Place_String(&(this->Shared_Memory_Data_Type_Pointer[index_counter].Pointer_Name),Pointer_Name);
              }
         }

         index_counter++;
     }

     bool Empty_Header_Names_Number_Holder = true;

     for(int k=0;k<this->Shared_Data_Types_Number+1;k++){

         if(Header_Names_Number_Holder[k] != 0){

            Empty_Header_Names_Number_Holder = false;
         }
     }

     if(((this->Shared_Data_Types_Header_File_Names_Number > 0) && (Empty_Header_Names_Number_Holder))){

          this->Print_Read_Error_Information();

          std::cerr << "\n     In description of \"Inter_Thread_Data_Type_Header_File_Names\"";

          std::cerr << "\n\n     the data type number which indicates the header files identity can not -.";

          std::cerr << "\n\n     be readed correctly. Data type number is wrong. Please check description.";

          std::cerr << "\n\n     The process will be interrupted ..";

          this->Print_End_of_Program();

          exit(1);
     }

     if(this->Include_Directory_Pointer != nullptr){

        for(int i=0;i<this->Include_Directory_Number;i++){

            this->Clear_Pointer_Memory(&this->Include_Directory_Pointer[i].Include_Directory);
        }

        delete [] this->Include_Directory_Pointer;
     }

     if(this->Shared_Memory_Pointer_Names_Holder != nullptr){

        for(int i=0;i<this->Shared_Data_Types_Number;i++){

           this->Clear_Pointer_Memory(&(this->Shared_Memory_Pointer_Names_Holder[i].Pointer_Names));
        }

        delete [] this->Shared_Memory_Pointer_Names_Holder;

        this->Shared_Memory_Pointer_Names_Holder = nullptr;
     }

     if(this->Shared_Memory_Header_Pointer != nullptr){

         for(int i=0;i<this->Shared_Data_Types_Number;i++){

             this->Clear_Pointer_Memory(&(this->Shared_Memory_Header_Pointer[i].Header_File_Name));

             this->Clear_Pointer_Memory(&(this->Shared_Memory_Header_Pointer[i].Include_Directory));

             if(this->Shared_Memory_Header_Pointer[i].Data_Type_Number != nullptr){

                 delete this->Shared_Memory_Header_Pointer[i].Data_Type_Number;
             }
         }

         delete [] this->Shared_Memory_Header_Pointer;
     }

     delete [] Data_Type_Number_holder;

     delete [] Header_Names_Number_Holder;

     delete [] Pointer_Names_Number_Holder;
}

void Inter_Thread_Data_Type_Description_Reader::Place_String(char ** Pointer, char * String){

     int Start_Point = this->Number_Processor_Pointer->Get_Read_Operation_Start_Point(String);

     int String_Size = strlen(String);

     int index_counter = 0;

     for(int i=Start_Point;i<String_Size;i++){

         (*Pointer)[index_counter] = String[i];

         index_counter++;
     }

     (*Pointer)[index_counter] = '\0';
}

bool Inter_Thread_Data_Type_Description_Reader::Check_Empty_Decleration(char * String){

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

void Inter_Thread_Data_Type_Description_Reader::Print_Read_Error_Information(){

     std::cerr << "\n";

     std::cerr << "\n  # ERROR MESSAGE";

     std::cerr << "\n";

     std::cerr << "\n  # Error Type: Descriptor File Read Error";

     std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

     std::cerr << "\n\n  {";
}

void Inter_Thread_Data_Type_Description_Reader::Print_End_of_Program(){

     std::cerr << "\n  }";

     std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";
}

void Inter_Thread_Data_Type_Description_Reader::Clear_Pointer_Memory(char ** Pointer){

      if(*Pointer != nullptr){

          delete [] (*Pointer);

          *Pointer = nullptr;
      }
 }

 Shared_Memory_Data_Type * Inter_Thread_Data_Type_Description_Reader::Get_Shared_Data_Types() const
 {
         return this->Shared_Memory_Data_Type_Pointer;
 }

 int Inter_Thread_Data_Type_Description_Reader::Get_Shared_Data_Types_Number() const {

     return this->Shared_Data_Types_Number;
 }

 int Inter_Thread_Data_Type_Description_Reader::Get_Shared_Data_Types_Include_File_Names_Number() const {

     return this->Shared_Data_Types_Header_File_Names_Number;
 }
