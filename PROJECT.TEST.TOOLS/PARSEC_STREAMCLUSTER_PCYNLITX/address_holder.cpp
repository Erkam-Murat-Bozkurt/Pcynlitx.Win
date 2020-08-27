
#include "address_holder.h"

address_holder::address_holder(){

     this->parameter_address = nullptr;

     this->thread_number = 0;
}

address_holder::~address_holder(){

    delete [] this->parameter_address;

}

void address_holder::receive_thread_number(int number){

     this->thread_number = number;

     this->parameter_address = new pkmedian_arg_t * [2*this->thread_number];
}

void address_holder::receive_paramter_address(int thread_number,pkmedian_arg_t * address){

     this->parameter_address[thread_number] = address;
}


pkmedian_arg_t * address_holder::get_parameter_address(int thread_number) const {

      return this->parameter_address[thread_number];
};
