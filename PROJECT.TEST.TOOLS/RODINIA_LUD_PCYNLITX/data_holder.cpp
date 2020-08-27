
#include "data_holder.h"

data_holder::data_holder(){

    this->matrix_size = 0;

    this->chunks_per_inter = 0;

    this->chunks_in_inter_row = 0;

    this->offset = 0;

    this->matrix_list = nullptr;

    this->duplicated_matrix = nullptr;
}

data_holder::~data_holder(){

     delete [] this->matrix_list;

};

void data_holder::receive_total_thread_number(int number){

     this->matrix_list =  new float * [5*number];
}

int data_holder::get_chunks_per_inter(){

    return this->chunks_per_inter;
}

int data_holder::get_chunks_in_inter_row(){

    return this->chunks_in_inter_row;
}

int data_holder::get_offset(){

    return this->offset;
}

float * data_holder::get_Matrix(int threadNumber){

      return this->matrix_list[threadNumber];
};


float * data_holder::get_duplicated_matrix(){

       return this->duplicated_matrix;
}

int data_holder::get_Matrix_Size(){

     return this->matrix_size;
}

void data_holder::set_Thread_Matrix(int Thread_Number,float * matrix){

     this->matrix_list[Thread_Number] = matrix;
}

void data_holder::set_duplicated_matrix(float * matrix){

     this->duplicated_matrix = matrix;
}

void data_holder::set_Matrix_Size(int size){

     this->matrix_size = size;
}

void data_holder::set_chunks_per_inter(int arg){

      this->chunks_per_inter = arg;
}

void data_holder::set_chunks_in_inter_row(int arg){

     this->chunks_in_inter_row;
}

void data_holder::set_offset(int arg){

     this->offset = arg;
}
