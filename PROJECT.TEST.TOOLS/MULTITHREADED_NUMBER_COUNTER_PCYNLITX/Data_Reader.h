
#ifndef DATA_READER_H
#define DATA_READER_H

#include <cstring>
#include <iostream>
#include "Cpp_FileOperations.h"
#include "StringOperator.h"
#include "IntToCharTranslater.h"
#include "Data_Types.h"


class Data_Reader
{
public:
  Data_Reader();
  virtual ~Data_Reader();
  void SetFilePath(std::string FilePATH);
  void SetFilePath(char * String);
  void SetFilePath(const char * String);
  void Receive_Total_Thread_Number(int number);
  void Receive_Data();
  void Print_Data();
  void Increase_Line_Index();
  void Set_Line_Index(int index);
  int  Get_Line_Index() const;
  int  Get_Data_length() const;
  int  Get_Data_List_Member_Position(int index);
  bool Get_Data_List_Member_Read_Status(int index);
  bool Get_Data_List_Member_Record_Status(int index);
  void Set_Data_List_Member_Read_Status(int index, bool status);
  void Set_Data_List_Member_Record_Status(int index, bool status);
  char * Get_Data_List_Member_String(int index);
  void Set_Record_Data(int index, int thread_number, int reputation);
  int  Get_Reputation(int index) const;
  int  Get_Thread_Number(int index) const;
  int  Get_Record_Number(int index) const;
  void Increase_Record_List_Length();
  int  Get_Record_List_Length();
  void Clear_Record_Data(int index);
  void Set_Record_List_Length(int length);
  void Initialize_Acess_Order_Holders();
  void Set_Acess_Order(int thread_number);
  void Print_Acess_Order();
  bool Check_Acess_Order_Violation();
private:
  void Set_Data(std::string string_line, char ** pointer);
  void Determine_File_Length();
  void Allocate_Memory_For_Each_Line();
  void Clear_Dynamic_Memory();
  Cpp_FileOperations FileManager;
  IntToCharTranslater Translater;
  bool Memory_Delete_Condition;
  bool Data_Record_Condition;
  int File_Lenght;
  int Line_index;
  int Record_List_Length;
  int total_thread_number;  // Indicates the total number of the threads to be executed ..
  data_list ** data_list_pointer;
  record_list * data_records;
  acess_order_data * acess_order_data_list;
  int  acess_order_list_increment;
  int  thread_record_increment;
  bool acess_order_violation;
};

#endif /* DATA_READER_H */
