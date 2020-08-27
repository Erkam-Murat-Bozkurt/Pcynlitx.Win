
#ifndef DATA_RECORDER_H
#define DATA_RECORDER_H

#include <cstring>
#include <string>
#include <iostream>
#include "Data_Recorder_Types.h"
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"

class Data_Recorder
{
public:
  Data_Recorder();
  virtual ~Data_Recorder();
  void Receive_Data_Size(int size);
  void Receive_Writer_Thread_Number(int number);
  void Set_Record_Data(std::string string_line, int i);
  int  Get_Record_Data_Size() const;
  int  Get_Data_Position(int index);
  bool Get_Data_Record_Status(int index);
  std::string Get_String_Data(int index);
protected:
  Cpp_FileOperations FileManager;
  IntToCharTranslater Translater;
  void Allocate_Memory_For_Each_Line(int size);
  void Clear_Dynamic_Memory();
  bool Memory_Delete_Condition;
  int  Record_Data_Size;
  int  Thread_Data_Index;
  int  Record_Index;
  Record_Data * Record_Data_Pointer;
  Writer_Thread_Record_Data * Thread_Data_Pointer;
  int  acess_order_list_increment;
  int  thread_record_increment;
  int  writer_thread_number;
};

#endif /* DATA_RECORDER_H */
