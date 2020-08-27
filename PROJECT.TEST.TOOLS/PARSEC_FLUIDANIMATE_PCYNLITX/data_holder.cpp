
#include "data_holder.h"

data_holder::data_holder()
{

}

data_holder::~data_holder()
{
     for(int i=0;i<this->total_thread_number;i++)
     {
         delete this->data_pointer[i];
     }

     delete [] this->data_pointer;
}

void data_holder::receive_total_thread_number(int number)
{
     this->total_thread_number = number;

     this->data_pointer = new int * [2*this->total_thread_number];

     for(int i=0;i<this->total_thread_number;i++)
     {
         this->data_pointer[i] = new int [10];
     }
}

void data_holder::receive_tid(int thread_number,int tid)
{
     this->data_pointer[thread_number][0] = tid;
}

void data_holder::receive_framenum(int thread_number,int framenum)
{
     this->data_pointer[thread_number][1] = framenum;
}

int data_holder::get_tid(int thread_number) const
{
    return this->data_pointer[thread_number][0];
}

int data_holder::get_framenum(int thread_number) const
{
    return this->data_pointer[thread_number][1];
}
