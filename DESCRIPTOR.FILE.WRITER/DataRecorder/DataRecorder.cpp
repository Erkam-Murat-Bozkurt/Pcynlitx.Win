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

#include "DataRecorder.h"

DataRecorder::DataRecorder(){

    this->Up_Record = nullptr;

    this->Down_Record = nullptr;

    this->Data_Records = nullptr;

    this->Memory_Delete_Condition = false;

    this->is_this_a_record_line = false;

    this->is_this_a_brace_line = false;

    this->is_this_on_the_inside_of_record_area = false;

    this->Enter_Record_Area = false;

    this->Record_Point = 0;

    this->Up_Record_Number = 0;

    this->Down_Record_Number = 0;

    this->End_of_File = 0;

    this->Data_Type_Record_Number = 0;

    this->Data_Records_Number = 0;
}

DataRecorder::~DataRecorder(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
}

void DataRecorder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Up_Record != nullptr){

            for(int i=0;i<this->Up_Record_Number;i++){

               delete [] this->Up_Record[i];
            }

            delete [] this->Up_Record;

            this->Up_Record = nullptr;
         }

         if(this->Down_Record != nullptr){

            for(int i=0;i<this->Down_Record_Number;i++){

               delete [] this->Down_Record[i];
            }

            delete [] this->Down_Record;

            this->Down_Record = nullptr;
         }

         if(this->Data_Records != nullptr){

            for(int i=0;i<this->Data_Records_Number;i++){

                delete [] this->Data_Records[i];
            }

            delete [] this->Data_Records;

            this->Data_Records = nullptr;
         }

         this->StringOperations.Clear_Dynamic_Memory();
     }
}

void DataRecorder::SetFilePath(char * TargetFilePath){

     this->StringOperations.SetFilePath(TargetFilePath);

     this->File_Manager.SetFilePath(TargetFilePath);
}

void DataRecorder::Add_Data_Record(char * Data_Record){

     this->Memory_Delete_Condition = false;

     this->File_Manager.FileOpen(RWCf);

     for(int i=0;i<this->Get_Up_Record_Number();i++){

         if(this->Get_Up_Record()[i][0] == '\0'){

            this->File_Manager.WriteToFile("\n");
         }
         else{

              if(this->Is_This_Inside_of_Record_Area(this->Get_Up_Record()[i])){

                 this->File_Manager.WriteToFile("   ");
              }

              this->File_Manager.WriteToFile(" ");

              this->File_Manager.WriteToFile(this->Get_Up_Record()[i]);

              this->File_Manager.WriteToFile("\n");
         }
     }

     if(this->Get_Data_Type_Record_Number() > 0){

        this->File_Manager.WriteToFile("\n");
     }

     this->File_Manager.WriteToFile("    ");

     this->File_Manager.WriteToFile(Data_Record);

     this->File_Manager.WriteToFile("\n");

     for(int i=0;i<this->Get_Down_Record_Number();i++){

         if(this->Get_Down_Record()[i][0] == '\0'){

            if(i < (this->Get_Down_Record_Number()-1)){

               this->File_Manager.WriteToFile("\n");
            }
         }
         else{

              if(this->Is_This_Inside_of_Record_Area(this->Get_Down_Record()[i])){

                 this->File_Manager.WriteToFile("   ");
              }

              this->File_Manager.WriteToFile(" ");

              this->File_Manager.WriteToFile(this->Get_Down_Record()[i]);

              if(i < (this->Get_Down_Record_Number())){

                 this->File_Manager.WriteToFile("\n");
              }
         }
     }

     this->File_Manager.FileClose();
}

void DataRecorder::Replace_Data_Record(char * Data_Record){

     this->Memory_Delete_Condition = false;

     this->File_Manager.FileOpen(RWCf);

     for(int i=0;i<this->Get_Up_Record_Number()-1;i++){

         if(this->Get_Up_Record()[i][0] == '\0'){

            this->File_Manager.WriteToFile("\n");
         }
         else{

               if(this->Is_This_Inside_of_Record_Area(this->Get_Up_Record()[i])){

                  this->File_Manager.WriteToFile("   ");
               }

               this->File_Manager.WriteToFile(" ");

               this->File_Manager.WriteToFile(this->Get_Up_Record()[i]);

               this->File_Manager.WriteToFile("\n");
        }
     }

     if(this->Get_Data_Type_Record_Number() > 1){

        this->File_Manager.WriteToFile("\n");
     }

     this->File_Manager.WriteToFile("    ");

     this->File_Manager.WriteToFile(Data_Record);

     this->File_Manager.WriteToFile("\n");

     for(int i=0;i<this->Get_Down_Record_Number();i++){

         if(this->Get_Down_Record()[i][0] == '\0'){

            this->File_Manager.WriteToFile("\n");
         }
         else{

               if(this->Is_This_Inside_of_Record_Area(this->Get_Down_Record()[i])){

                  this->File_Manager.WriteToFile("   ");
               }

               this->File_Manager.WriteToFile(" ");

               this->File_Manager.WriteToFile(this->Get_Down_Record()[i]);

               if(i < (this->Get_Down_Record_Number()-2)){

                  this->File_Manager.WriteToFile("\n");
               }
         }
     }

     this->File_Manager.FileClose();
}

void DataRecorder::Collect_Information_For_Data_Recording(char * Record_Type){

     this->Clear_Dynamic_Memory();

     this->Memory_Delete_Condition = false;

     this->Determine_Record_Point(Record_Type);

     this->Read_Before_Record_Point();

     this->Read_After_Record_Point();

     this->Determine_Data_Type_Record_Number(Record_Type);
}

void DataRecorder::Determine_Record_Point(char * Data_Type){

     this->Record_Point = 0;

     int Start_Point = 0, End_Point = 0, Read_Point = 0;

     Start_Point = this->StringOperations.FindNextWordLine(Data_Type,0);

     char First_Brace_Line [] = {'{','\0'};

     char Last_Brace_Line [] = {'}','\0'};

     Start_Point = this->StringOperations.FindNextWordLine(First_Brace_Line,Start_Point);

     End_Point  = this->StringOperations.FindNextWordLine(Last_Brace_Line,Start_Point);

     Read_Point = End_Point -1;

     char * File_Line = this->StringOperations.ReadFileLine(Read_Point);

     while(!this->Determine_Is_This_Line_A_Record_Line(File_Line)){

           if(Read_Point == Start_Point){

              break;
           }
           else{

                Read_Point--;
           }

           File_Line = this->StringOperations.ReadFileLine(Read_Point);
     }

     this->Record_Point = Read_Point+1;
}

void DataRecorder::Read_Data_Records(char * Data_Type){

     this->Clear_Dynamic_Memory();

     this->Memory_Delete_Condition = false;

     this->Determine_Data_Type_Record_Number(Data_Type);

     if(this->Data_Records != nullptr){

        for(int i=0;i<this->Data_Records_Number;i++){

            delete [] this->Data_Records[i];
        }

        delete [] this->Data_Records;

        this->Data_Records = nullptr;

        this->Data_Records_Number = 0;
     }

     if(this->Get_Data_Type_Record_Number() > 0){

        this->Data_Records = new char * [10*this->Get_Data_Type_Record_Number()];

        char First_Brace_Line [] = {'{','\0'};

        char Last_Brace_Line [] = {'}','\0'};

        int Start_Point = this->StringOperations.FindNextWordLine(Data_Type,0);

        Start_Point = this->StringOperations.FindNextWordLine(First_Brace_Line,Start_Point) +1;

        int End_Point = this->StringOperations.FindNextWordLine(Last_Brace_Line,Start_Point);

        int index_counter = 0;

        for(int i=Start_Point;i<End_Point;i++){

            char * File_Line = this->StringOperations.ReadFileLine(i);

            int String_Size = strlen(File_Line);

            if(this->Determine_Is_This_Line_A_Record_Line(File_Line)){

               this->Data_Records[index_counter] = new char [10*String_Size];

               int Read_Start_Point = 0;

               for(int k=0;k<String_Size;k++){

                   if(File_Line[k] == ']'){

                      Read_Start_Point = k+1;
                   }
               }

               for(int k=Read_Start_Point;k<String_Size;k++){

                   if(File_Line[k] == ' '){

                      Read_Start_Point++;
                   }
               }

               int record_index = 0;

               for(int k = Read_Start_Point;k<String_Size;k++){

                   this->Data_Records[index_counter][record_index] = File_Line[k];

                   record_index++;
               }

               this->Data_Records[index_counter][record_index] = '\0';

               if(this->Data_Records[index_counter][record_index-1] == '/'){

                  this->Data_Records[index_counter][record_index-1] = '\0';
               }

               index_counter++;

               this->Data_Records_Number = index_counter;
            }
         }
      }
}

void DataRecorder::Read_Before_Record_Point(){

     this->Up_Record_Number = this->Record_Point-1;

     this->Up_Record = new char * [10*this->Up_Record_Number];

     for(int i=0;i<this->Up_Record_Number;i++){

         char * File_Line = this->StringOperations.ReadFileLine(i+1);

         int File_Line_Size = strlen(File_Line);

         if(File_Line_Size == 0){

            this->Up_Record[i] = new char [10];

            for(int k=0;k<5;k++){

               this->Up_Record[i][k] = '\0';
            }
         }
         else{

              this->Up_Record[i] = new char [10*File_Line_Size];

              int index_counter = 0;

              for(int k=0;k<File_Line_Size;k++){

                  this->Up_Record[i][index_counter] = File_Line[k];

                  index_counter++;
               }

               this->Up_Record[i][index_counter] = '\0';
         }
     }
}

void DataRecorder::Read_After_Record_Point(){

     this->File_Manager.FileOpen(Rf);

     this->End_of_File = 0;

     while(!this->File_Manager.Control_End_of_File()){

           this->File_Manager.ReadLine();

           this->End_of_File++;
     }

     this->File_Manager.FileClose();

     this->Down_Record_Number = this->End_of_File - this->Up_Record_Number;

     this->Down_Record = new char * [10*this->Down_Record_Number];

     int index_counter = 0;

     for(int i=this->Up_Record_Number;i<this->End_of_File;i++){

         char * File_Line = this->StringOperations.ReadFileLine(i+1);

         int File_Line_Size = strlen(File_Line);

         if(File_Line_Size == 0){

            this->Down_Record[index_counter] = new char [10];

            for(int k=0;k<5;k++){

                this->Down_Record[index_counter][k] = '\0';
            }
         }
         else{

              this->Down_Record[index_counter] = new char [10*File_Line_Size];

              int string_index_counter = 0;

              for(int k=0;k<File_Line_Size;k++){

                  this->Down_Record[index_counter][string_index_counter] = File_Line[k];

                  string_index_counter++;
              }

              this->Down_Record[index_counter][string_index_counter] = '\0';
         }

         index_counter++;
     }
}

void DataRecorder::Determine_Data_Type_Record_Number(char * Data_Type){

     this->Data_Type_Record_Number = 0;

     char First_Brace_Line [] = {'{','\0'};

     char Last_Brace_Line [] = {'}','\0'};

     int Start_Point = this->StringOperations.FindNextWordLine(Data_Type,0);

     Start_Point = this->StringOperations.FindNextWordLine(First_Brace_Line,Start_Point) +1;

     int End_Point = this->StringOperations.FindNextWordLine(Last_Brace_Line,Start_Point);

     for(int i=Start_Point;i<End_Point;i++){

         char * File_Line = this->StringOperations.ReadFileLine(i);

         if(this->Determine_Is_This_Line_A_Record_Line(File_Line)){

            this->Data_Type_Record_Number++;
         }
     }
}

bool DataRecorder::Determine_Is_This_Line_A_Record_Line(char * File_Line){

     this->is_this_a_record_line = false;

     int Line_Size = strlen(File_Line);

     for(int i=0;i<Line_Size;i++){

         if(((File_Line[i]!= '\0') && (File_Line[i]!= ' ') && (File_Line[i]!= '\n') && (File_Line[i] != '\t'))){

              this->is_this_a_record_line = true;
         }
     }

     return this->is_this_a_record_line;
}

bool DataRecorder::Is_This_First_Brace(char * string){

     this->is_this_a_brace_line = false;

     int String_Size = strlen(string);

     for(int i=0;i<String_Size;i++){

        if((string[i] == '{')){

           this->is_this_a_brace_line = true;
        }
     }

     return this->is_this_a_brace_line;
}

bool DataRecorder::Is_This_Last_Brace(char * string){

     this->is_this_a_brace_line = false;

     int String_Size = strlen(string);

     for(int i=0;i<String_Size;i++){

        if((string[i] == '}')){

           this->is_this_a_brace_line = true;
        }
     }

     return this->is_this_a_brace_line;
}

bool DataRecorder::Is_This_Inside_of_Record_Area(char * string){

     this->is_this_on_the_inside_of_record_area = false;

     if(this->Is_This_First_Brace(string)){

         this->Enter_Record_Area = true;
     }

     if(this->Is_This_Last_Brace(string)){

        this->Enter_Record_Area = false;
     }

     if(((!this->Is_This_First_Brace(string)) && this->Enter_Record_Area)){

         this->is_this_on_the_inside_of_record_area = true;
     }

     return this->is_this_on_the_inside_of_record_area;
}

char ** DataRecorder::Get_Up_Record(){

        return this->Up_Record;
}

char ** DataRecorder::Get_Down_Record(){

        return this->Down_Record;
}

char ** DataRecorder::Get_Data_Type_Records(){

        return this->Data_Records;
}

int DataRecorder::Get_Up_Record_Number(){

    return this->Up_Record_Number;
}

int DataRecorder::Get_Down_Record_Number(){

    return this->Down_Record_Number;
}

int DataRecorder::Get_Data_Type_Record_Number(){

    return this->Data_Type_Record_Number;
}

int DataRecorder::Get_Record_Point(){

    return this->Record_Point;
}
