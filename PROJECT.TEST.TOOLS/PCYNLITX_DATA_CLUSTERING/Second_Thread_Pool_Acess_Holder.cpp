

#include "Second_Thread_Pool_Acess_Holder.h"

Second_Thread_Pool_Acess_Holder::Second_Thread_Pool_Acess_Holder(){

     this->Data_Size = 0;

     this->Memory_Delete_Condition = false;

     this->acess_order_violation = false;

     this->acess_order_list_increment = 0;

     this->acess_order_data_list  = nullptr;

     this->second_pool_thread_number = 0;

     this->thread_record_increment = 0;
}

Second_Thread_Pool_Acess_Holder::~Second_Thread_Pool_Acess_Holder(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
}

void Second_Thread_Pool_Acess_Holder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->acess_order_data_list != nullptr){

            for(int i=0;i<this->Data_Size;i++){

                delete [] this->acess_order_data_list[i].acess_data_holder;

                delete [] this->acess_order_data_list[i].empty_status;
            }

            delete [] this->acess_order_data_list;
         }
     }
}

void Second_Thread_Pool_Acess_Holder::Receive_Second_Pool_Thread_Number(int number){

     this->second_pool_thread_number = number;
}

void Second_Thread_Pool_Acess_Holder::Receive_Data_Size(int data_size){

     this->Data_Size = data_size;

     this->Initialize_Acess_Order_Holders();

}

void Second_Thread_Pool_Acess_Holder::Initialize_Acess_Order_Holders(){

     this->acess_order_data_list  = new thread_pools_data_types [3*this->Data_Size];

     for(int i=0;i<2*this->Data_Size;i++){

         this->acess_order_data_list[i].acess_data_holder = new int [2*this->second_pool_thread_number];

         this->acess_order_data_list[i].empty_status = new bool [2*this->second_pool_thread_number];

         for(int k=0;k<this->second_pool_thread_number;k++){

            this->acess_order_data_list[i].acess_data_holder[k] = -1;

            this->acess_order_data_list[i].empty_status[k] = true;
         }
     }
}

void Second_Thread_Pool_Acess_Holder::Set_Acess_Order(int thread_number)
{
     int Record_Index = this->thread_record_increment; // Record index for thread numbers

     int Data_List_Index = this->acess_order_list_increment; // Record index for data structures

     if(this->acess_order_data_list[Data_List_Index].empty_status[Record_Index]){

        this->acess_order_data_list[Data_List_Index].acess_data_holder[Record_Index] = thread_number;

        this->acess_order_data_list[Data_List_Index].empty_status[Record_Index] = false;
     }

     this->thread_record_increment++;

     if(this->thread_record_increment >= this->second_pool_thread_number){

        this->acess_order_list_increment++;

        this->thread_record_increment = 0;
     }
}

bool Second_Thread_Pool_Acess_Holder::Check_Second_Pool_Acess_Order_Violation()
{
     this->acess_order_violation = false;

     for(int i=0;i<this->Data_Size;i++){

         int remaining_operation = this->Data_Size - i;

         for(int k=0;k<this->second_pool_thread_number;k++){

             if(k>remaining_operation){

                  break;
             }

             if(!(this->acess_order_data_list[i].empty_status[k])){

                  int order = this->acess_order_data_list[i].acess_data_holder[k];

                  if(order != k){

                     this->acess_order_violation = true;

                     return this->acess_order_violation;
                  }
             }
         }
     }

     return this->acess_order_violation;
}
