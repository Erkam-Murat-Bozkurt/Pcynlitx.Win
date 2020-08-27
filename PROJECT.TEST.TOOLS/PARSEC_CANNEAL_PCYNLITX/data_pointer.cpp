#include "data_pointer.h"

data_pointer::data_pointer(){

}

data_pointer::~data_pointer(){

}

void data_pointer::receive_address(annealer_thread * ptr){

   this->ptr = ptr;
}

annealer_thread * data_pointer::get_address(){

   return this->ptr;
}
