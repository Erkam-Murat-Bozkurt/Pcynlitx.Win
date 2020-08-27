
#ifndef SECOND_THREAD_POOL_ACESS_HOLDER_H
#define SECOND_THREAD_POOL_ACESS_HOLDER_H

#include <cstring>
#include <string>
#include <iostream>
#include "IntToCharTranslater.h"
#include "Thread_Pools_Data_Types.h"

class Second_Thread_Pool_Acess_Holder
{
public:
  Second_Thread_Pool_Acess_Holder();
  virtual ~Second_Thread_Pool_Acess_Holder();
  void Receive_Second_Pool_Thread_Number(int number);
  void Receive_Data_Size(int data_size);
  void Set_Acess_Order(int thread_number);
  bool Check_Second_Pool_Acess_Order_Violation();
protected:
  void Initialize_Acess_Order_Holders();
  void Clear_Dynamic_Memory();
  IntToCharTranslater Translater;
  thread_pools_data_types * acess_order_data_list;
  bool Memory_Delete_Condition;
  int  Data_Size;
  int  acess_order_list_increment;
  int  thread_record_increment;
  int  second_pool_thread_number;
  bool acess_order_violation;
};

#endif /* SECOND_THREAD_POOL_ACESS_HOLDER_H */
