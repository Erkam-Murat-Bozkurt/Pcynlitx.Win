
#ifndef DATA_READER_H
#define DATA_READER_H

#include <cstring>
#include <string>
#include <iostream>
#include "Cpp_FileOperations.h"
#include "Data_Reader_Types.h"
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"

class Data_Reader
{
public:
  Data_Reader();
  virtual ~Data_Reader();
  void SetFilePath(std::string FilePATH);
  void SetFilePath(char * String);
  void SetFilePath(const char * String);
  void Receive_Reader_Thread_Number(int number);
  void Receive_Data();
  int  Get_Data_Size() const;
  int  Get_Data_Position(int index);
  bool Get_Data_Read_Status(int index);
  bool Get_Data_Record_Status(int index);
  void Set_Data_Read_Status(int index, bool status);
  void Set_Thread_Data_Record_Status(int index, bool status);
  void Set_Acess_Order(int thread_number);
  void Print_Acess_Order();
  bool Check_Readers_Acess_Order_Violation();
  char * Get_String_Data(int index);
protected:
  void Set_Data(std::string string_line, int i);
  void Determine_File_Length();
  void Allocate_Memory_For_Each_Line();
  void Initialize_Acess_Order_Holders();
  void Clear_Dynamic_Memory();
  Cpp_FileOperations FileManager;
  IntToCharTranslater Translater;
  bool Memory_Delete_Condition;
  int File_Lenght;
  int Record_List_Length;
  Read_Data * Read_Data_Pointer;
  readers_acess_order_data * acess_order_data_list;
  int  acess_order_list_increment;
  int  thread_record_increment;
  int  reader_thread_number;
  bool acess_order_violation;
};

#endif /* DATA_READER_H */
