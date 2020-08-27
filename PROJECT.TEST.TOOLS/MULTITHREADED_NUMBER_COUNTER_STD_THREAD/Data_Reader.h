
#ifndef DATA_READER_H
#define DATA_READER_H

#include <cstring>
#include <iostream>
#include "Cpp_FileOperations.h"
#include "StringOperator.h"

struct data_list {

    bool read_status;

    bool record_status;

    char * number_string;

    int position;
};

struct record_list {

    int record_number;

    int thread_number;

    int reputation;
};

class Data_Reader
{
public:
  Data_Reader();
  virtual ~Data_Reader();
  void SetFilePath(std::string FilePATH);
  void SetFilePath(char * String);
  void SetFilePath(const char * String);
  void Receive_Data();
  void Print_Data();
  void Increase_Line_Index();
  void Set_Line_Index(int index);
  int  Get_Line_Index() const;
  int  Get_Data_length() const;
  void Set_Data_Record_Ready_Status(bool condition);
  bool Get_Data_Record_Ready_Status();
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
protected:
  void Set_Data(std::string string_line, char ** pointer);
  void Determine_File_Length();
  void Allocate_Memory_For_Each_Line();
  void Clear_Dynamic_Memory();
  Cpp_FileOperations FileManager;
  bool Memory_Delete_Condition;
  bool Data_Record_Condition;
  int File_Lenght;
  int Line_index;
  int Record_List_Length;
  data_list ** data_list_pointer;
  record_list * data_records;
};

#endif /* DATA_READER_H */
