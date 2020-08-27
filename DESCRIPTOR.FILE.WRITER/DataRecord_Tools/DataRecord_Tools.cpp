
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

#include "DataRecord_Tools.h"

DataRecord_Tools::DataRecord_Tools(){

     this->Memory_Delete_Condition = false;

     this->isStringsEqual = false;

     this->File_Name = nullptr;

     this->File_Directory = nullptr;

     this->Integer_Data = nullptr;

     this->Input_String = nullptr;

     this->Record_String = nullptr;

     this->Header_File_Names_Record_Data = nullptr;

     this->Source_File_Names_Record_Data = nullptr;

     this->ITC_Header_File_Name_Record_Data = nullptr;

     this->ITD_Header_File_Name_Record_Data = nullptr;

     this->Data_Number = nullptr;

     this->Location_Number = nullptr;

     this->Record_Data = nullptr;

     this->is_record_exist = false;

     this->Directory_Number = 0;
}

DataRecord_Tools::~DataRecord_Tools(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
}


void DataRecord_Tools::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->File_Name);

         this->Clear_Pointer_Memory(&this->File_Directory);

         this->Clear_Pointer_Memory(&this->Integer_Data);

         this->Clear_Pointer_Memory(&this->Input_String);

         this->Clear_Pointer_Memory(&this->Record_String);

         this->Clear_Pointer_Memory(&this->Header_File_Names_Record_Data);

         this->Clear_Pointer_Memory(&this->Source_File_Names_Record_Data);

         this->Clear_Pointer_Memory(&this->Location_Number);

         this->Clear_Pointer_Memory(&this->Data_Number);

         this->Clear_Pointer_Memory(&this->ITC_Header_File_Name_Record_Data);

         this->Clear_Pointer_Memory(&this->ITD_Header_File_Name_Record_Data);

         this->Clear_Pointer_Memory(&this->Record_Data);

         this->Recorder.Clear_Dynamic_Memory();
     }
}

void DataRecord_Tools::SetFilePath(char * Descriptor_File_Path){

     this->Recorder.SetFilePath(Descriptor_File_Path);
}

void DataRecord_Tools::Determine_File_Informations(char * File_PATH){

     this->Clear_Pointer_Memory(&this->File_Name);

     this->Clear_Pointer_Memory(&this->File_Directory);

     int String_Size = strlen(File_PATH);

     int Read_Start_Point = 0;

     for(int i=String_Size;i>0;i--){

         if(File_PATH[i] == '/'){

            Read_Start_Point = i+1;

            break;
         }
     }

     int File_Name_Size = String_Size - Read_Start_Point;

     this->File_Name = new char [10*File_Name_Size];

     int index_counter = 0;

     for(int i=Read_Start_Point;i<String_Size;i++){

         this->File_Name[index_counter] = File_PATH[i];

         index_counter++;
     }

     this->File_Name[index_counter] = '\0';

     index_counter = 0;

     int File_Directory_Name_Size = String_Size - File_Name_Size -1;

     this->File_Directory = new char [10*File_Directory_Name_Size];

     for(int i=0;i<File_Directory_Name_Size;i++){

         this->File_Directory[index_counter] = File_PATH[i];

         index_counter++;
     }

     this->File_Directory[index_counter] = '\0';
}

void DataRecord_Tools::Determine_Library_Name_Informations(char * Library_PATH){

     this->Clear_Pointer_Memory(&this->File_Name);

     this->Clear_Pointer_Memory(&this->File_Directory);

     int String_Size = strlen(Library_PATH);

     int Read_Start_Point = 0;

     for(int i=String_Size;i>0;i--){

         if(Library_PATH[i] == '/'){

            Read_Start_Point = i+1;

            break;
         }
     }

     int Name_Read_Start_Point = Read_Start_Point + 3;

     int File_Name_Size = String_Size - Read_Start_Point;

     this->File_Name = new char [10*File_Name_Size];

     int index_counter = 0;

     for(int i=Name_Read_Start_Point;i<String_Size-2;i++){

         this->File_Name[index_counter] = Library_PATH[i];

         index_counter++;
     }

     this->File_Name[index_counter] = '\0';

     index_counter = 0;

     int File_Directory_Name_Size = String_Size - File_Name_Size -1;

     this->File_Directory = new char [10*File_Directory_Name_Size];

     for(int i=0;i<File_Directory_Name_Size;i++){

         this->File_Directory[index_counter] = Library_PATH[i];

         index_counter++;
     }

     this->File_Directory[index_counter] = '\0';
}

char * DataRecord_Tools::Convert_to_char(int x){

       this->Clear_Pointer_Memory(&this->Integer_Data);

       std::stringstream str;

       str << x;

       std::string Integer_Value_String = str.str();

       int String_Size = Integer_Value_String.length();

       this->Integer_Data = new char [10*String_Size];

       for(int i=0;i<String_Size;i++){

           this->Integer_Data[i] = Integer_Value_String[i];
       }

       this->Integer_Data[String_Size] = '\0';

       return this->Integer_Data;
}


bool DataRecord_Tools::Is_Record_Exist(char * Data_Type,char * Input_Data){

     this->Recorder.Read_Data_Records(Data_Type);

     int Data_Type_Record_Number = this->Recorder.Get_Data_Type_Record_Number();

     this->Directory_Number = 0;

     this->is_record_exist = false;

     if(Data_Type_Record_Number == 0){

        return this->is_record_exist;
     }

     this->Isolate_Input_Data(Input_Data);

     for(int i=0;i<Data_Type_Record_Number;i++){

         this->Isolate_Record_Data(this->Recorder.Get_Data_Type_Records()[i]);

         this->is_record_exist = this->Compare_Strings(this->Record_String,this->Input_String);

         if(this->is_record_exist){

            this->Directory_Number = i+1;

            return this->is_record_exist;
         }
     }

     this->is_record_exist = false;

     return this->is_record_exist;
}

void DataRecord_Tools::Isolate_Input_Data(char * Input_Data){

     this->Clear_Pointer_Memory(&this->Input_String);

     int Data_Size = strlen(Input_Data);

     int Data_End_Point = Data_Size;

     if(Input_Data[Data_Size-1] == '/'){

        Data_End_Point = Data_Size - 1;
     }

     this->Input_String = new char [10*Data_End_Point];

     for(int i=0;i<Data_End_Point;i++){

         this->Input_String[i] = Input_Data[i];
     }

     this->Input_String[Data_End_Point] = '\0';
}

void DataRecord_Tools::Isolate_Record_Data(char * Record_Data){

     this->Clear_Pointer_Memory(&this->Record_String);

     int Data_Size = strlen(Record_Data);

     int Data_End_Point = Data_Size;

     if(Record_Data[Data_Size-1] == '/'){

        Data_End_Point = Data_Size - 1;
     }

     this->Record_String = new char [10*Data_End_Point];

     int start_point = 0;

     while(Record_Data[start_point] == ' '){

           start_point++;
     }

     int index_counter = 0;

     for(int i=start_point;i<Data_End_Point;i++){

         this->Record_String[index_counter] = Record_Data[i];

         index_counter++;
     }

     this->Record_String[index_counter] = '\0';
}

void DataRecord_Tools::Determine_Header_File_Name_Record_Data(char * File_Name, int Location_Number, int Data_Number){

     this->Receive_Data_Number(Data_Number);

     this->Receive_Location_Number(Location_Number);

     char Record_Prefix [] = "Header File Number [";

     char Record_Subfix [] = "] - File Location [";

     char Last_Brace [] = {']','\0'};

     char Space [] = {' ','-',' ','\0'};

     int File_Size   = strlen(File_Name);

     int Prefix_Size = strlen(Record_Prefix);

     int Subfix_Size = strlen(Record_Subfix);

     int Record_Size = File_Size + Prefix_Size + Subfix_Size + 2;

     this->Clear_Pointer_Memory(&this->Header_File_Names_Record_Data);

     this->Header_File_Names_Record_Data = new char [10*Record_Size];

     int index_counter = 0;

     this->Place_Information(&this->Header_File_Names_Record_Data,Record_Prefix,&index_counter);

     this->Place_Information(&this->Header_File_Names_Record_Data,this->Data_Number,&index_counter);

     this->Place_Information(&this->Header_File_Names_Record_Data,Record_Subfix,&index_counter);

     this->Place_Information(&this->Header_File_Names_Record_Data,this->Location_Number,&index_counter);

     this->Place_Information(&this->Header_File_Names_Record_Data,Last_Brace,&index_counter);

     this->Place_Information(&this->Header_File_Names_Record_Data,Space,&index_counter);

     this->Place_Information(&this->Header_File_Names_Record_Data,File_Name,&index_counter);

     this->Header_File_Names_Record_Data[index_counter] = '\0';
}

void DataRecord_Tools::Determine_Source_File_Name_Record_Data(char * File_Name, int Location_Number, int Data_Number){

     this->Receive_Data_Number(Data_Number);

     this->Receive_Location_Number(Location_Number);

     char Record_Prefix [] = "Source File Number [";

     char Record_Subfix [] = "] - File Location [";

     char Last_Brace [] = {']','\0'};

     char Space [] = {' ','-',' ','\0'};

     int File_Size   = strlen(File_Name);

     int Prefix_Size = strlen(Record_Prefix);

     int Subfix_Size = strlen(Record_Subfix);

     int Record_Size = File_Size + Prefix_Size + Subfix_Size + 2;

     this->Clear_Pointer_Memory(&this->Source_File_Names_Record_Data);

     this->Source_File_Names_Record_Data = new char [10*Record_Size];

     int index_counter = 0;

     this->Place_Information(&this->Source_File_Names_Record_Data,Record_Prefix,&index_counter);

     this->Place_Information(&this->Source_File_Names_Record_Data,this->Data_Number,&index_counter);

     this->Place_Information(&this->Source_File_Names_Record_Data,Record_Subfix,&index_counter);

     this->Place_Information(&this->Source_File_Names_Record_Data,this->Location_Number,&index_counter);

     this->Place_Information(&this->Source_File_Names_Record_Data,Last_Brace,&index_counter);

     this->Place_Information(&this->Source_File_Names_Record_Data,Space,&index_counter);

     this->Place_Information(&this->Source_File_Names_Record_Data,File_Name,&index_counter);

     this->Source_File_Names_Record_Data[index_counter] = '\0';
}

void DataRecord_Tools::Determine_ITC_Header_File_Name_Record_Data(char * File_Name, int Location_Number, int Data_Number){

     this->Receive_Data_Number(Data_Number);

     this->Receive_Location_Number(Location_Number);

     char Record_Prefix [] = "Class Number [";;

     char Record_Subfix [] = "] - File Location [";

     char Last_Brace [] = {']','\0'};

     char Space [] = {' ','-',' ','\0'};

     int File_Size   = strlen(File_Name);

     int Prefix_Size = strlen(Record_Prefix);

     int Subfix_Size = strlen(Record_Subfix);

     int Record_Size = File_Size + Prefix_Size + Subfix_Size;

     this->Clear_Pointer_Memory(&this->ITC_Header_File_Name_Record_Data);

     this->ITC_Header_File_Name_Record_Data  = new char [10*Record_Size];

     int index_counter = 0;

     this->Place_Information(&this->ITC_Header_File_Name_Record_Data,Record_Prefix,&index_counter);

     this->Place_Information(&this->ITC_Header_File_Name_Record_Data,this->Data_Number,&index_counter);

     this->Place_Information(&this->ITC_Header_File_Name_Record_Data,Record_Subfix,&index_counter);

     this->Place_Information(&this->ITC_Header_File_Name_Record_Data,this->Location_Number,&index_counter);

     this->Place_Information(&this->ITC_Header_File_Name_Record_Data,Last_Brace,&index_counter);

     this->Place_Information(&this->ITC_Header_File_Name_Record_Data,Space,&index_counter);

     this->Place_Information(&this->ITC_Header_File_Name_Record_Data,File_Name,&index_counter);

     this->ITC_Header_File_Name_Record_Data[index_counter] = '\0';
}


void DataRecord_Tools::Determine_ITD_Header_File_Name_Record_Data(char * File_Name, int Location_Number, int Data_Number){

     this->Receive_Data_Number(Data_Number);

     this->Receive_Location_Number(Location_Number);

     char Record_Prefix [] = "Data Number [";;

     char Record_Subfix [] = "] - File Location [";

     char Last_Brace [] = {']','\0'};

     char Space [] = {' ','-',' ','\0'};

     int File_Size   = strlen(File_Name);

     int Prefix_Size = strlen(Record_Prefix);

     int Subfix_Size = strlen(Record_Subfix);

     int Record_Size = File_Size + Prefix_Size + Subfix_Size + 2;

     this->Clear_Pointer_Memory(&this->ITD_Header_File_Name_Record_Data);

     this->ITD_Header_File_Name_Record_Data  = new char [10*Record_Size];

     int index_counter = 0;

     this->Place_Information(&this->ITD_Header_File_Name_Record_Data,Record_Prefix,&index_counter);

     this->Place_Information(&this->ITD_Header_File_Name_Record_Data,this->Data_Number,&index_counter);

     this->Place_Information(&this->ITD_Header_File_Name_Record_Data,Record_Subfix,&index_counter);

     this->Place_Information(&this->ITD_Header_File_Name_Record_Data,this->Location_Number,&index_counter);

     this->Place_Information(&this->ITD_Header_File_Name_Record_Data,Last_Brace,&index_counter);

     this->Place_Information(&this->ITD_Header_File_Name_Record_Data,Space,&index_counter);

     this->Place_Information(&this->ITD_Header_File_Name_Record_Data,File_Name,&index_counter);

     this->ITD_Header_File_Name_Record_Data[index_counter] = '\0';
}

void DataRecord_Tools::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

void DataRecord_Tools::Place_String(char ** Pointer, char * String){

     int String_Size = strlen(String);

     for(int i=0;i<String_Size;i++){

        (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void DataRecord_Tools::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

void DataRecord_Tools::Receive_Data_Number(int Integer_Data){

     this->Clear_Pointer_Memory(&this->Data_Number);

     char * Data = this->Convert_to_char(Integer_Data);

     int String_Size = strlen(Data);

     this->Data_Number = new char [10*String_Size];

     this->Place_String(&this->Data_Number,Data);
}

void DataRecord_Tools::Receive_Location_Number(int Integer_Data){

     this->Clear_Pointer_Memory(&this->Location_Number);

     char * Data = this->Convert_to_char(Integer_Data);

     int String_Size = strlen(Data);

     this->Location_Number = new char [10*String_Size];

     this->Place_String(&this->Location_Number,Data);
}


bool DataRecord_Tools::Compare_Strings(char * First_String, char * Second_String){

     int First_String_Length  = strlen(First_String);

     int Second_String_Length = strlen(Second_String);

     this->isStringsEqual = true;

     if(First_String_Length == Second_String_Length){

        for(int i=0;i<First_String_Length;i++){

            if(First_String[i]!=Second_String[i]){

               this->isStringsEqual = false;

               return this->isStringsEqual;
            }
        }
     }
     else{

          this->isStringsEqual = false;
     }

     return this->isStringsEqual;
}

void DataRecord_Tools::Determine_Standart_Record_Data(char * Input_Data, int Record_Number){

     this->Clear_Pointer_Memory(&this->Record_Data);

     Record_Number = Record_Number + 1;

     this->Receive_Data_Number(Record_Number);

     char First_Brace [] = {'[','\0'};

     char Last_Brace  [] = {']','\0'};

     char Space [] = {' ','\0'};

     int Number_Size = strlen(this->Data_Number);

     int Data_Size = strlen(Input_Data);

     int Record_Size = Number_Size + Data_Size + 2;

     this->Record_Data = new char [10*Record_Size];

     int index_counter = 0;

     this->Place_Information(&this->Record_Data,First_Brace,&index_counter);

     this->Place_Information(&this->Record_Data,this->Data_Number,&index_counter);

     this->Place_Information(&this->Record_Data,Last_Brace,&index_counter);

     this->Place_Information(&this->Record_Data,Space,&index_counter);

     this->Place_Information(&this->Record_Data,Input_Data,&index_counter);

     this->Record_Data[index_counter] = '\0';

     if(this->Record_Data[index_counter -1] == '/'){

        this->Record_Data[index_counter-1] = '\0';
     }
}

char * DataRecord_Tools::Get_File_Name(){

       return this->File_Name;
}

char * DataRecord_Tools::Get_File_Directory(){

       return this->File_Directory;
}

char * DataRecord_Tools::Get_Header_File_Name_Record_Data(){

       return this->Header_File_Names_Record_Data;
}

char * DataRecord_Tools::Get_Source_File_Name_Record_Data(){

       return this->Source_File_Names_Record_Data;
}

char * DataRecord_Tools::Get_ITC_Header_File_Name_Record_Data(){

       return this->ITC_Header_File_Name_Record_Data;
}

char * DataRecord_Tools::Get_ITD_Header_File_Name_Record_Data(){

       return this->ITD_Header_File_Name_Record_Data;
}

char * DataRecord_Tools::Get_Standart_Record_Data(){

       return this->Record_Data;
}

int DataRecord_Tools::Get_Directory_Number(){

       return this->Directory_Number;
}
