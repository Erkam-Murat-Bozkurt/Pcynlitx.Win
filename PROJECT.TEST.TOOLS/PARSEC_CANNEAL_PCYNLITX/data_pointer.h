
#include "annealer_thread.h"

#ifndef DATA_POINTER_H
#define DATA_POINTER_H

class data_pointer
{
public:
 data_pointer();
 virtual ~data_pointer();
 void receive_address(annealer_thread * ptr);
 annealer_thread * get_address();
private:
 annealer_thread * ptr;
};

#endif /* DATA_POINTER_H */
