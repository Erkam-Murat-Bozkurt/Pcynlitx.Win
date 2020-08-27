
#ifndef ADDRESS_HOLDER_H
#define ADDRESS_HOLDER_H

#include "thread_argument.h"

class address_holder
{
public:
  address_holder();
  virtual ~address_holder();
  void receive_thread_number(int number);
  void receive_paramter_address(int thread_number,pkmedian_arg_t * parameter_address);
  pkmedian_arg_t * get_parameter_address(int thread_number) const;
private:
  pkmedian_arg_t ** parameter_address;
  int thread_number;
};

#endif /* ADDRESS_HOLDER_H */
