
#include "Data_Recorder.h"

Data_Recorder::Data_Recorder(){

     this->Memory_Delete_Condition = true;

     this->Record_Data_Pointer = nullptr;

     this->acess_order_data_list = nullptr;

     this->Record_Data_Size = 0;

     this->writer_thread_number = 0;

     this->acess_order_list_increment = 0;

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

         if(this->acess_order_data_list != nullptr){

            for(int i=0;i<this->Record_Data_Size;i++){

                delete [] this->acess_order_data_list[i].acess_data_holder;

                delete [] this->acess_order_data_list[i].empty_status;
            }

            delete [] this->acess_order_data_list;
         }
     }
}

void Data_Recorder::Receive_Writer_Thread_Number(int number){

     this->writer_thread_number = number;
}

void Data_Recorder::Receive_Data_Size(int size){

     this->Allocate_Memory_For_Each_Line(size);

     this->Initialize_Acess_Order_Holders();
}

void Data_Recorder::Allocate_Memory_For_Each_Line(int Size){

     this->Record_Data_Size = Size;

     this->Memory_Delete_Condition = false;

     this->Record_Data_Pointer = new Record_Data [2*this->Record_Data_Size];

     for(int i=0;i<this->Record_Data_Size;i++){

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


void Data_Recorder::Initialize_Acess_Order_Holders(){

     this->acess_order_data_list  = new writers_acess_order_data [2*this->Record_Data_Size];

     for(int i=0;i<this->Record_Data_Size;i++){

         this->acess_order_data_list[i].acess_data_holder = new int [2*this->writer_thread_number];

         this->acess_order_data_list[i].empty_status = new bool [2*this->writer_thread_number];

         for(int k=0;k<this->writer_thread_number;k++){

            this->acess_order_data_list[i].acess_data_holder[k] = -1;

            this->acess_order_data_list[i].empty_status[k] = true;
         }
     }
}

void Data_Recorder::Set_Acess_Order(int thread_number)
{
     int Record_Index = this->thread_record_increment; // Record index for thread numbers

     int Data_List_Index = this->acess_order_list_increment; // Record index for data structures

     if(this->acess_order_data_list[Data_List_Index].empty_status[Record_Index]){

        this->acess_order_data_list[Data_List_Index].acess_data_holder[Record_Index] = thread_number;

        this->acess_order_data_list[Data_List_Index].empty_status[Record_Index] = false;
     }

     this->thread_record_increment++;

     if(this->thread_record_increment >= this->writer_thread_number){

        this->acess_order_list_increment++;

        this->thread_record_increment = 0;
     }
}

void Data_Recorder::Print_Acess_Order()
{
     this->FileManager.SetFilePath("Writers_Acess_Orders");

     this->FileManager.FileOpen(RWCf);

     for(int i=0;i<this->Record_Data_Size;i++){

        this->FileManager.WriteToFile("\n ");

        for(int k=0;k<this->writer_thread_number;k++){

           if(!(this->acess_order_data_list[i].empty_status[k])){

               int order = this->acess_order_data_list[i].acess_data_holder[k];

               char * value = this->Translater.Translate(order);

               this->FileManager.WriteToFile("\n ");

               this->FileManager.WriteToFile(value);

               this->FileManager.WriteToFile(" ");
           }
        }
     }

    this->FileManager.FileClose( );
}


bool Data_Recorder::Check_Writers_Acess_Order_Violation()
{
     this->acess_order_violation = false;

     for(int i=0;i<this->Record_Data_Size;i++){

         int remaining_operation = this->Record_Data_Size - i;

         for(int k=0;k<this->writer_thread_number;k++){

             if(this->writer_thread_number > remaining_operation){

                  break;
             }

             if(!(this->acess_order_data_list[i].empty_status[k])){

                  int order = this->acess_order_data_list[i].acess_data_holder[k];

                  if(order != (this->writer_thread_number+k)){

                     this->acess_order_violation = true;

                     return this->acess_order_violation;
                  }
             }
         }
     }

     return this->acess_order_violation;
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
