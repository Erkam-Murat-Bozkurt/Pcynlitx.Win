
#include "Data_Recorder.h"

Data_Recorder::Data_Recorder(){

     this->Memory_Delete_Condition = true;

     this->Record_Data_Pointer = nullptr;

     this->Record_Data_Size = 0;

     this->writer_thread_number = 0;

     this->thread_record_increment = 0;
}

Data_Recorder::~Data_Recorder(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
}

void Data_Recorder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Record_Data_Pointer != nullptr){

             delete [] this->Record_Data_Pointer;
         }
     }
}

void Data_Recorder::Receive_Writer_Thread_Number(int number){

     this->writer_thread_number = number;
}

void Data_Recorder::Receive_Data_Size(int size){

     this->Allocate_Memory_For_Each_Line(size);
}

void Data_Recorder::Allocate_Memory_For_Each_Line(int Size){

     this->Record_Data_Size = Size;

     this->Memory_Delete_Condition = false;

     this->Record_Data_Pointer = new Record_Data [5*this->Record_Data_Size];

     for(int i=0;i<2*this->Record_Data_Size;i++){

         this->Record_Data_Pointer[i].string_line = "";

         this->Record_Data_Pointer[i].position = i;

         this->Record_Data_Pointer[i].record_status = false;
     }
}

void Data_Recorder::Set_Record_Data(std::string string_line, int i){

     this->Record_Data_Pointer[i].string_line = string_line;

     this->Record_Data_Pointer[i].position = i;

     this->Record_Data_Pointer[i].record_status = true;
}

std::string Data_Recorder::Get_String_Data(int index){

     return this->Record_Data_Pointer[index].string_line;
}

int Data_Recorder::Get_Data_Position(int index){

    return this->Record_Data_Pointer[index].position;
}

bool Data_Recorder::Get_Data_Record_Status(int index){

     return this->Record_Data_Pointer[index].record_status;
}

int Data_Recorder::Get_Record_Data_Size() const {

    return this->Record_Data_Size;
}
