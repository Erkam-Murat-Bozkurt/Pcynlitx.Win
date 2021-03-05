
#ifndef DESCRIPTOR_FILE_READER_INITIALIZER_H
#define DESCRIPTOR_FILE_READER_INITIALIZER_H

#include "Descriptor_File_Data_Collector.h"
#include "IntToCharTranslater.h"

class Descriptor_File_Reader_Initializer
{
public:
  Descriptor_File_Reader_Initializer();
  Descriptor_File_Reader_Initializer(const Descriptor_File_Reader_Initializer & orig);
  virtual ~Descriptor_File_Reader_Initializer();
  void Receve_Data_Collector(Descriptor_File_Data_Collector * Data_Collector);
  void Read_File_Lists();
  void Clear_Dynamic_Memory();
  int     Get_Thread_Number() const;
  int     Get_Source_File_Number() const;
  char *  Get_Main_File_Name() const;
  char *  Get_Namespace() const;
  char *  Get_Executable_File_Name() const;
  char *  Get_Server_Class_Name() const;
  char *  Get_Server_Class_Header_File_Name() const;
  char *  Get_Construction_Directory() const;
  char ** Get_Include_Directory_List() const;
  char ** Get_Library_Directory_List() const;
  char ** Get_Source_File_Location_List() const;
  char ** Get_Library_Name_List() const;
  char ** Get_Source_File_List() const;
  char ** Get_Header_File_List() const;
  char ** Get_Inter_Thread_Class_Header_File_List() const;
  char ** Get_Inter_Thread_Class_Names_List() const;
  char ** Get_Inter_Thread_Class_Instance_Name_List() const;
  char ** Get_Shared_Data_Type_List() const;
  char ** Get_Shared_Memory_Pointer_Name_List() const;
  char ** Get_Shared_Data_Type_Header_File_List() const;
  char ** Get_Thread_Names_List() const;
  bool *  Get_Thread_Attributes_List() const;
private:
  void Clear_Pointer_Memory(char ** Pointer);
  void Receive_Include_Directory_List();
  void Receive_Library_Directory_List();
  void Receive_Source_File_Location_List();
  void Receive_Library_Name_List();
  void Receive_Header_File_Names();
  void Receive_Source_File_Name_List();
  void Receive_Main_File_Name();
  void Receive_Executable_File_Name();
  void Receive_Inter_Thread_Class_Header_File_Names();
  void Receive_Inter_Thread_Class_Names();
  void Receive_Inter_Thread_Class_Instance_Names();
  void Receive_Shared_Memory_Data_Types();
  void Receive_Shared_Memory_Pointer_Names();
  void Receive_Shared_Memory_Data_Types_Header_File_Names();
  void Receive_Construction_Point();
  void Receive_Supervisor_Class_Name();
  void Receive_Thread_Function_Names();
  void Receive_Thread_Number();
  void Receive_Namespace();
  Descriptor_File_Data_Collector * File_Data_Collector;
  IntToCharTranslater Translater;
  bool Memory_Delete_Condition;
  int     Thread_Number;
  char *  Main_File_Name;
  char *  Namespace;
  char *  Executable_File_Name;
  char *  Supervisor_Class_Name;
  char *  Supervisor_Class_Header_File_Name;
  char *  Construction_Directory;
  char ** Include_Directory_List;
  char ** Source_File_Location_List;
  char ** Source_File_Name_List;
  char ** Library_Directory_List;
  char ** Library_Name_List;
  char ** Header_File_List;
  char ** Inter_Thread_Class_Header_File_List;
  char ** Inter_Thread_Class_Name_List;
  char ** Inter_Thread_Class_Instance_Name_List;
  char ** Shared_Data_Type_List;
  char ** Shared_Memory_Pointer_Name_List;
  char ** Shared_Data_Type_Header_File_List;
  char ** Thread_Name_List;
};

#endif /* DESCRIPTOR_FILE_READER_INITIALIZER_H */
