
#ifndef SMART_POINTER_DATA_CONVEYOR_H
#define SMART_POINTER_DATA_CONVEYOR_H

#include <cstdlib>
#include <cstring>

class Smart_Pointer_Data_Conveyor
{
public:
  Smart_Pointer_Data_Conveyor();
  Smart_Pointer_Data_Conveyor(const Smart_Pointer_Data_Conveyor & orig);
  virtual ~Smart_Pointer_Data_Conveyor();
  void Receive_Data_Type_Count(int count); // How many data type has been declareted.
  void Receive_Data_Type(char * type, int type_number);
  void Receive_New_Class_Name(char * class_name, int type_number);
  void Receive_Data_Type_Instance_Name(char * Instance_Name, int type_number);
  void Receive_Data_Type_Include_Directory(char * Data_Type, int type_number);
  void Clear_Dynamic_Memory();
  char * Get_DataType(int type_number);
  char * Get_New_Class_Name(int type_number);
  char * Get_Shared_Data_Type_Instance_Name(int type_number);
  char * Get_Data_Type_Include_Directory(int type_number);
private:
  bool Memory_Delete_Status;
  char ** Instance_Name;
  char ** New_Class_Name;
  char ** Data_Type;
  char ** Data_Type_Include_Directory;
  int type_count;
};


#endif /* SMART_POINTER_DATA_CONVEYOR_H */
