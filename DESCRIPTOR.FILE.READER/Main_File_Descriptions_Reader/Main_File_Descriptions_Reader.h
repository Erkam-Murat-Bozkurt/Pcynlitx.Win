
#ifndef MAIN_FILE_DESCRIPTIONS_READER_H
#define MAIN_FILE_DESCRIPTIONS_READER_H

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Descriptor_File_Data_Collector.h"
#include "Descriptor_File_Reader_Initializer.h"
#include "Descriptor_File_Number_Processor.h"

class Main_File_Descriptions_Reader
{
public:
  Main_File_Descriptions_Reader();
  Main_File_Descriptions_Reader(const Main_File_Descriptions_Reader & orig);
  virtual ~Main_File_Descriptions_Reader();
  void Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer);
  void Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer);
  void Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer);
  void Read_Main_File_Descriptions();
  void Clear_Dynamic_Memory();
  char *  Get_Server_Class_Name() const;
  char *  Get_Server_Class_Header_File_Name() const;
  char *  Get_Main_File_Name() const;
  char *  Get_Namespace() const;
  char *  Get_Executable_File_Name() const;
  char *  Get_Construction_Point() const;
  char ** Get_Thread_Function_Names() const;
  int     Get_Thread_Number() const;
  int     Get_Thread_Function_Number() const;
private:
  void Set_Informations_Comes_From_Data_Collector();
  void Receive_Construction_Point();
  void Receive_Main_File_Name();
  void Receive_Namespace();
  void Receive_OpenMP_Support_Condition();
  void Receive_Executable_File_Name();
  void Receive_Server_Class_Name();
  void Receive_Thread_Function_Names();
  void Place_String(char ** Pointer, char * String);
  void Clear_Pointer_Memory(char ** Pointer);
  void Print_Read_Error_Information();
  void Print_End_of_Program();
  Descriptor_File_Data_Collector * Data_Collector_Pointer;
  Descriptor_File_Reader_Initializer * Initializer_Pointer;
  Descriptor_File_Number_Processor * Number_Processor_Pointer;
  char *  Construction_Point;
  char *  Executable_File_Name;
  char *  Main_File_Name;
  char *  Namespace;
  char *  OpenMP_Support_Condition;
  char *  Server_Class_Name;
  char *  Server_Class_Header_File_Name;
  char ** Thread_Function_Names;
  bool Memory_Delete_Condition;
  int Thread_Function_Number;
  int Thread_Number;
};

#endif /* MAIN_FILE_DESCRIPTIONS_READER_H */
