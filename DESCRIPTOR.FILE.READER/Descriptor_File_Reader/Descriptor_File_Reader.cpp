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

 #include "Descriptor_File_Reader.h"

 Descriptor_File_Reader::Descriptor_File_Reader(){

       this->Memory_Delete_Condition = false;

       this->Memory_Allocation_Started = false;

       this->error_status = false;

       this->Constructed_Include_Directory = nullptr;
 }

 Descriptor_File_Reader::Descriptor_File_Reader(const Descriptor_File_Reader & orig){

 }

 Descriptor_File_Reader::~Descriptor_File_Reader(){

       if(((!this->Memory_Delete_Condition) && (this->Memory_Allocation_Started))){

           this->Clear_Dynamic_Memory();
       }
 }

 void Descriptor_File_Reader::Clear_Dynamic_Memory(){

      if(((!this->Memory_Delete_Condition) && (this->Memory_Allocation_Started))){

          this->Memory_Delete_Condition = true;

          if(this->Constructed_Include_Directory != nullptr){

             delete [] this->Constructed_Include_Directory;
          }

          this->MF_Descriptions_Reader.Clear_Dynamic_Memory();

          this->IT_Class_Reader.Clear_Dynamic_Memory();

          this->IT_Data_Type_Reader.Clear_Dynamic_Memory();

          this->ID_Description_Reader.Clear_Dynamic_Memory();

          this->SF_Descriptions_Reader.Clear_Dynamic_Memory();

          this->Lib_Descriptions_Reader.Clear_Dynamic_Memory();

          this->HF_Descriptions_Reader.Clear_Dynamic_Memory();
       }
 }

 void Descriptor_File_Reader::Receive_Gui_Read_Status(bool status){

      this->gui_read_status = status;

      this->File_Data_Collector.Receive_Gui_Read_Status(&this->gui_read_status);

      this->Reader_Initializer.Receive_Gui_Read_Status(&this->gui_read_status);

      this->Number_Processor.Receive_Gui_Read_Status(&this->gui_read_status);

      this->IT_Class_Reader.Receive_Gui_Read_Status(&this->gui_read_status);

      this->IT_Data_Type_Reader.Receive_Gui_Read_Status(&this->gui_read_status);

      this->ID_Description_Reader.Receive_Gui_Read_Status(&this->gui_read_status);

      this->SF_Descriptions_Reader.Receive_Gui_Read_Status(&this->gui_read_status);

      this->HF_Descriptions_Reader.Receive_Gui_Read_Status(&this->gui_read_status);
      
      this->Lib_Descriptions_Reader.Receive_Gui_Read_Status(&this->gui_read_status);
 
      this->MF_Descriptions_Reader.Receive_Gui_Read_Status(&this->gui_read_status);
 
      this->Syntax_Controler.Receive_Gui_Read_Status(&this->gui_read_status);
 }


 void Descriptor_File_Reader::Receive_Descriptor_File_Directory(const char * DescriptorFileDirectory){

      this->Memory_Allocation_Started = true;

      this->File_Data_Collector.Receive_Descriptor_File_Directory(DescriptorFileDirectory);
 }

 void Descriptor_File_Reader::Receive_Descriptor_File_Directory(char * DescriptorFileDirectory){

      this->Memory_Allocation_Started = true;

      this->File_Data_Collector.Receive_Descriptor_File_Directory(DescriptorFileDirectory);
 }

 void Descriptor_File_Reader::Receive_Descriptor_File_Name(const char * DescriptorFileName){

      this->Memory_Allocation_Started = true;

      this->File_Data_Collector.Receive_Descriptor_File_Name(DescriptorFileName);
 }

 void Descriptor_File_Reader::Receive_Descriptor_File_Name(char * DescriptorFileName){

      this->Memory_Allocation_Started = true;

      this->File_Data_Collector.Receive_Descriptor_File_Name(DescriptorFileName);
 }

 bool Descriptor_File_Reader::Receive_Descriptor_File_Infomations(){

      bool rt_value = false;

      this->Memory_Allocation_Started = true;

      this->File_Data_Collector.Receive_Read_Error_Status(&this->error_status);
      
      this->Reader_Initializer.Receive_Read_Error_Status(&this->error_status);
 
      this->Number_Processor.Receive_Read_Error_Status(&this->error_status);

      this->IT_Class_Reader.Receive_Read_Error_Status(&this->error_status);
    
      this->IT_Data_Type_Reader.Receive_Read_Error_Status(&this->error_status);
 
      this->ID_Description_Reader.Receive_Read_Error_Status(&this->error_status);
    
      this->SF_Descriptions_Reader.Receive_Read_Error_Status(&this->error_status);
    
      this->HF_Descriptions_Reader.Receive_Read_Error_Status(&this->error_status);
    
      this->Lib_Descriptions_Reader.Receive_Read_Error_Status(&this->error_status);
 
      this->MF_Descriptions_Reader.Receive_Read_Error_Status(&this->error_status);
 
      this->Syntax_Controler.Receive_Read_Error_Status(&this->error_status);

      if(!this->error_status){

          if(this->File_Data_Collector.Collect_Descriptor_File_Datas()){

             bool rt_value = true;

             return rt_value;
          }
      }
      else{

            bool rt_value = true;

            return rt_value;
      }

      if(!this->error_status){

          this->Reader_Initializer.Receve_Data_Collector(&this->File_Data_Collector);
      }
      else{

            bool rt_value = true;

            return rt_value;
      }

      if(!this->error_status){

         if(this->Reader_Initializer.Read_File_Lists()){

            bool rt_value = true;

            return rt_value;
         }
      }
      else{

            bool rt_value = true;

            return rt_value;
      }


      if(!this->error_status){

          this->Receive_Include_Directory_Descriptions();
      }
      else{

            bool rt_value = true;

            return rt_value;
      }

      if(!this->error_status){

          this->Receive_Source_File_Descriptions();
      }
      else{

            bool rt_value = true;

            return rt_value;
      }

      if(!this->error_status){

         this->Receive_Header_File_Descriptions();
      }
      else{

           bool rt_value = true;

           return rt_value;
      }

      if(!this->error_status){

        this->Receive_Library_Descriptions();
      }
      else{

           bool rt_value = true;

           return rt_value;
      }

      if(!this->error_status){

         this->Receive_Inter_Thread_Class_Names();
      }
      else{

           bool rt_value = true;

           return rt_value;
      }

      if(!this->error_status){

          this->Receive_Shared_Memory_Data_Types();
      }
      else{

           bool rt_value = true;

           return rt_value;
      }

      if(!this->error_status){

         this->Receive_Main_File_Descriptions();      
      }
      else{

           bool rt_value = true;

           return rt_value;
      }


      if(!this->error_status){

         this->Control_Process_Header_Files_Syntax();
      }
      else{

           bool rt_value = true;

           return rt_value;
      }

      if(!this->error_status){

         this->Determine_Newly_Constructed_Include_Directory();
      }
      else{

           bool rt_value = true;

           return rt_value;
      }

      this->File_Data_Collector.Clear_Dynamic_Memory();

      this->Reader_Initializer.Clear_Dynamic_Memory();

      if(!this->error_status){

          this->Remove_Compiler_Output_File();
      }
      else{

           bool rt_value = true;

           return rt_value;
      }

      return rt_value;
 }

 bool Descriptor_File_Reader::Receive_Include_Directory_Descriptions(){

      this->Memory_Allocation_Started = true;

      this->ID_Description_Reader.Receive_Data_Collector(&this->File_Data_Collector);

      this->ID_Description_Reader.Receive_Initializer(&this->Reader_Initializer);

      this->ID_Description_Reader.Receive_Number_Processor(&this->Number_Processor);

      return this->ID_Description_Reader.Read_Include_Directory_Descriptions();
 }

 bool Descriptor_File_Reader::Receive_Inter_Thread_Class_Names(){

      this->IT_Class_Reader.Receive_Data_Collector(&this->File_Data_Collector);

      this->IT_Class_Reader.Receive_Initializer(&this->Reader_Initializer);

      this->IT_Class_Reader.Receive_Number_Processor(&this->Number_Processor);

      this->IT_Class_Reader.Receive_Include_Directory_Description_Reader(&this->ID_Description_Reader);

      return this->IT_Class_Reader.Read_Inter_Thread_Class_Descriptions();
}

bool Descriptor_File_Reader::Receive_Shared_Memory_Data_Types(){

     this->IT_Data_Type_Reader.Receive_Data_Collector(&this->File_Data_Collector);

     this->IT_Data_Type_Reader.Receive_Initializer(&this->Reader_Initializer);

     this->IT_Data_Type_Reader.Receive_Number_Processor(&this->Number_Processor);

     this->IT_Data_Type_Reader.Receive_Include_Directory_Description_Reader(&this->ID_Description_Reader);

     return this->IT_Data_Type_Reader.Read_Inter_Thread_Data_Type_Descriptions();
}

bool Descriptor_File_Reader::Receive_Source_File_Descriptions(){

     this->SF_Descriptions_Reader.Receive_Data_Collector(&this->File_Data_Collector);

     this->SF_Descriptions_Reader.Receive_Initializer(&this->Reader_Initializer);

     this->SF_Descriptions_Reader.Receive_Number_Processor(&this->Number_Processor);

     return this->SF_Descriptions_Reader.Read_Source_File_Descriptions();
}

bool Descriptor_File_Reader::Receive_Header_File_Descriptions(){

     this->HF_Descriptions_Reader.Receive_Data_Collector(&this->File_Data_Collector);

     this->HF_Descriptions_Reader.Receive_Initializer(&this->Reader_Initializer);

     this->HF_Descriptions_Reader.Receive_Number_Processor(&this->Number_Processor);

     this->HF_Descriptions_Reader.Receive_Include_Directory_Description_Reader(&this->ID_Description_Reader);

     return this->HF_Descriptions_Reader.Receive_Header_File_Names();
}

bool Descriptor_File_Reader::Receive_Library_Descriptions(){

     this->Lib_Descriptions_Reader.Receive_Data_Collector(&this->File_Data_Collector);

     this->Lib_Descriptions_Reader.Receive_Initializer(&this->Reader_Initializer);

     this->Lib_Descriptions_Reader.Receive_Number_Processor(&this->Number_Processor);

     return this->Lib_Descriptions_Reader.Read_Library_Descriptions();
}

bool Descriptor_File_Reader::Receive_Main_File_Descriptions(){

     this->MF_Descriptions_Reader.Receive_Data_Collector(&this->File_Data_Collector);

     this->MF_Descriptions_Reader.Receive_Initializer(&this->Reader_Initializer);

     this->MF_Descriptions_Reader.Receive_Number_Processor(&this->Number_Processor);

     return this->MF_Descriptions_Reader.Read_Main_File_Descriptions();
}

bool Descriptor_File_Reader::Control_Process_Header_Files_Syntax(){

      if(this->Get_Class_Number() > 0){

          this->Syntax_Controler.Determine_Class_Data_Type_Receive_Condition(true);

          this->Syntax_Controler.Receive_Inter_Thread_Class_Data(this->Get_Class_Names());
      }
      else{

          this->Syntax_Controler.Determine_Class_Data_Type_Receive_Condition(false);
      }

      if(this->Get_Shared_Data_Types_Number() > 0){

          this->Syntax_Controler.Determine_Shared_Data_Type_Receive_Condition(true);

          this->Syntax_Controler.Receive_Inter_Thread_Data_Type_Data(this->Get_Shared_Data_Types());
      }
      else{

          this->Syntax_Controler.Determine_Shared_Data_Type_Receive_Condition(false);
      }

      if(((this->Get_Class_Number() > 0) || (this->Get_Shared_Data_Types_Number() > 0))){

           this->Syntax_Controler.Receive_Construction_Point(this->Get_Construction_Point());

           this->Syntax_Controler.Control_Process_Syntax();

           this->Syntax_Controler.Clear_Dynamic_Memory();
      }
}

bool Descriptor_File_Reader::Remove_Compiler_Output_File(){

     char Compiler_Output_File_Name [] = "Compiler_Output.txt";

     int Compiler_Output_File_Name_Size = strlen(Compiler_Output_File_Name);

     int Construction_Point_Name_Size = strlen(this->Get_Construction_Point());

     bool is_directory_operator_exist = false;

     for(int i=Construction_Point_Name_Size-10;i<Construction_Point_Name_Size;i++){

         if(this->Get_Construction_Point()[i] == '\\'){

            is_directory_operator_exist = true;
         }
     }

     this->Compiler_Output_File_Path = new char [10*Construction_Point_Name_Size];

     int index_counter = 0;

     for(int i=0;i<Construction_Point_Name_Size;i++){

         this->Compiler_Output_File_Path[index_counter] = this->Get_Construction_Point()[i];

         index_counter++;
     }

     if(!is_directory_operator_exist){

         this->Compiler_Output_File_Path[index_counter] = '\\';

         index_counter++;
     }

     for(int i=0;i<Compiler_Output_File_Name_Size;i++){

         this->Compiler_Output_File_Path[index_counter] = Compiler_Output_File_Name[i];

         index_counter++;
     }

     this->Compiler_Output_File_Path[index_counter] = '\0';

     int Is_Compiler_Output_File_Exist = access(this->Compiler_Output_File_Path,F_OK);

     if(Is_Compiler_Output_File_Exist == 0){

        unlink(this->Compiler_Output_File_Path);
     }

     delete [] this->Compiler_Output_File_Path;
}


bool Descriptor_File_Reader::Determine_Newly_Constructed_Include_Directory(){

     char Include_Directory_Add_Word [] = {'_','I','n','c','l','u','d','e','_','D','i','r','e','c','t','o','r','y','\0'};

     int Construction_Point_Name_Size = strlen(this->Get_Construction_Point());

     int Server_Class_Name_Size = strlen(this->Get_Server_Class_Name());

     int Include_Directory_Add_Word_Name_Size = strlen(Include_Directory_Add_Word);

     int Newly_Constructed_Include_Directory_Name_Size = Construction_Point_Name_Size + Server_Class_Name_Size +

                                                         Include_Directory_Add_Word_Name_Size;

     this->Constructed_Include_Directory = new char [10*Newly_Constructed_Include_Directory_Name_Size];

     int index_counter = 0;

     for(int i=0;i<Construction_Point_Name_Size;i++){

         this->Constructed_Include_Directory[index_counter] = this->Get_Construction_Point()[i];

         index_counter++;
     }

     this->Constructed_Include_Directory[index_counter] = '\\';

     index_counter++;

     for(int i=0;i<Server_Class_Name_Size;i++){

         this->Constructed_Include_Directory[index_counter] = this->Get_Server_Class_Name()[i];

         index_counter++;
     }

     for(int i=0;i<Include_Directory_Add_Word_Name_Size;i++){

         this->Constructed_Include_Directory[index_counter] = Include_Directory_Add_Word[i];

         index_counter++;
     }

     this->Constructed_Include_Directory[index_counter] = '\0';
}

Class_Data_Type * Descriptor_File_Reader::Get_Class_Names() const {

        return this->IT_Class_Reader.Get_Class_Names();
}

Include_Directory_Type * Descriptor_File_Reader::Get_Include_Directory() const{

       return this->ID_Description_Reader.Get_Include_Directory();
}

Shared_Memory_Data_Type * Descriptor_File_Reader::Get_Shared_Data_Types() const{

       return this->IT_Data_Type_Reader.Get_Shared_Data_Types();
}

char * Descriptor_File_Reader::Get_Main_File_Name() const {

       return this->MF_Descriptions_Reader.Get_Main_File_Name();
}

char * Descriptor_File_Reader::Get_Namespace() const {

       return this->MF_Descriptions_Reader.Get_Namespace();
}

char * Descriptor_File_Reader::Get_Executable_File_Name() const {

       return this->MF_Descriptions_Reader.Get_Executable_File_Name();
}

char * Descriptor_File_Reader::Get_Server_Class_Name() const {

       return this->MF_Descriptions_Reader.Get_Server_Class_Name();
}

char * Descriptor_File_Reader::Get_Server_Class_Header_File_Name() const {

       return this->MF_Descriptions_Reader.Get_Server_Class_Header_File_Name();
}

char * Descriptor_File_Reader::Get_Construction_Point() const {

       return this->MF_Descriptions_Reader.Get_Construction_Point();
}

char * Descriptor_File_Reader::Get_Constructed_Include_Directory() const {

       return this->Constructed_Include_Directory;
}

char ** Descriptor_File_Reader::Get_Source_File_Locations() const {

        return this->SF_Descriptions_Reader.Get_Source_File_Locations();
}

char ** Descriptor_File_Reader::Get_Source_File_Names() const {

        return this->SF_Descriptions_Reader.Get_Source_File_Names();
}

char ** Descriptor_File_Reader::Get_Header_File_Names() const {

        return this->HF_Descriptions_Reader.Get_Header_File_Names();
}

char ** Descriptor_File_Reader::Get_Header_File_Paths() const {

        return this->HF_Descriptions_Reader.Get_Header_File_Paths();
}

char ** Descriptor_File_Reader::Get_Thread_Function_Names() const {

        return this->MF_Descriptions_Reader.Get_Thread_Function_Names();
}

char ** Descriptor_File_Reader::Get_Library_Directories() const {

        return this->Lib_Descriptions_Reader.Get_Library_Directories();
}

char ** Descriptor_File_Reader::Get_Library_Names() const {

        return this->Lib_Descriptions_Reader.Get_Library_Names();
}

int Descriptor_File_Reader::Get_Thread_Number() const {

    return this->MF_Descriptions_Reader.Get_Thread_Number();
}

int Descriptor_File_Reader::Get_Class_Number() const {

     return this->IT_Class_Reader.Get_Class_Number();
}

int Descriptor_File_Reader::Get_Thread_Function_Number() const {

    return this->MF_Descriptions_Reader.Get_Thread_Function_Number();
}

int Descriptor_File_Reader::Get_Header_Files_Number() const {

    return this->HF_Descriptions_Reader.Get_Header_Files_Number();
}

int Descriptor_File_Reader::Get_Shared_Data_Types_Number() const {

    return this->IT_Data_Type_Reader.Get_Shared_Data_Types_Number();
}

int Descriptor_File_Reader::Get_Source_File_Location_Number() const {

    return this->SF_Descriptions_Reader.Get_Source_File_Location_Number();
}

int Descriptor_File_Reader::Get_Source_File_Names_Number() const {

    return this->SF_Descriptions_Reader.Get_Source_File_Names_Number();
}

int Descriptor_File_Reader::Get_Shared_Data_Types_Include_File_Names_Number() const {

    return this->IT_Data_Type_Reader.Get_Shared_Data_Types_Include_File_Names_Number();
}

int Descriptor_File_Reader::Get_Include_Directory_Number() const {

    return this->ID_Description_Reader.Get_Include_Directory_Number();
}

int Descriptor_File_Reader::Get_Library_Directory_Number() const {

    return this->Lib_Descriptions_Reader.Get_Library_Directory_Number();
}

int Descriptor_File_Reader::Get_Library_Names_Number() const {

    return this->Lib_Descriptions_Reader.Get_Library_Names_Number();
}
