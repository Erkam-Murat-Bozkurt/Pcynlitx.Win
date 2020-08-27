
#ifndef MULTI_THREAD_POINTER_DATA_COLLECTOR_H
#define MULTI_THREAD_POINTER_DATA_COLLECTOR_H

#include "Builder_Initializer.h"

class Multi_Thread_Pointer_Data_Collector
{
public:
  Multi_Thread_Pointer_Data_Collector();
  Multi_Thread_Pointer_Data_Collector(const Multi_Thread_Pointer_Data_Collector & orig);
  virtual ~Multi_Thread_Pointer_Data_Collector();
  void Receive_Data_Type(const char * DataType);
  void Receive_Data_Type(char * DataType);
  void Receive_Construction_Point(const char * Construction_Point);
  void Receive_Construction_Point(char * Construction_Point);
  void Receive_Data_Type_Include_File_Name(const char * Include_File_Name);
  void Receive_Data_Type_Include_File_Name(char * Include_File_Name);
  void Set_Class_Name(const char * Class_Name);
  void Set_Class_Name(char * Class_Name);
  void Collect_Informations();
  void Clear_Dynamic_Memory();
  Builder_Initializer Pointer_Initializer;
  Builder_Initializer Manager_Initializer;
  Builder_Initializer Reporter_Initializer;
  char *  Get_Source_File_Name_List();
  char *  Get_Header_File_Name_List();
  char *  Get_Object_File_List();
  char ** Get_Object_File_Name_Matrix();
  char ** Get_Header_File_Name_Matrix();
  char ** Get_Source_File_Name_Matrix();
private:
  void Place_Information(char ** Pointer, char * Information, int * counter);
  void Place_String(char ** Pointer, char * String, int String_Size);
  void Add_Space(char ** Pointer,int * counter);
  void Clear_Pointer_Memory(char ** Pointer);
  char * Header_File_List;
  char * Source_File_List;
  char * Object_File_List;
  char ** Object_File_Name_Matrix;
  char ** Header_File_Name_Matrix;
  char ** Source_File_Name_Matrix;
  bool Memory_Delete_Condition;
};


#endif /* SMART_POINTER_DATA_COLLECTOR_H */
