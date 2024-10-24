
#ifndef DESCRIPTOR_FILE_DATA_COLLECTOR_H
#define DESCRIPTOR_FILE_DATA_COLLECTOR_H

#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include "CharOperator.h"
#include "StringOperator.h"
#include "DirectoryOperations.h"

class Descriptor_File_Data_Collector
{
public:
  Descriptor_File_Data_Collector();
  Descriptor_File_Data_Collector(const Descriptor_File_Data_Collector & orig);
  virtual ~Descriptor_File_Data_Collector();
  void Receive_Descriptor_File_Directory(const char * DescriptorFileDirectory);
  void Receive_Descriptor_File_Directory(char * DescriptorFileDirectory);
  void Receive_Descriptor_File_Name(const char * DescriptorFileName);
  void Receive_Descriptor_File_Name(char * DescriptorFileName);
  void Receive_Read_Error_Status(bool * status);
  void Receive_Gui_Read_Status(bool * status);
  bool Collect_Descriptor_File_Datas();
  void Place_String(char ** Pointer, const char * String, size_t String_Size);
  void Place_String(char ** Pointer, char * String, size_t String_Size);
  void Clear_Dynamic_Memory();
  char * Get_DescriptorFileName() const ;
  char * Get_DescriptorFileDirectory() const;
  StringOperator StringOperations;
  DirectoryOperations DirectoryManager;
  CharOperator CharacterOperations;
  int Include_Directory_Numbers;
  int Source_File_Location_Number;
  int Source_File_Number;
  int Library_Directory_Number;
  int Library_Names_Number;
  int Header_File_Names_Number;
  int Executable_File_Name_Record_Number;
  int Main_File_Name_Record_Number;
  int Inter_Thread_Class_Header_File_Names_Number;
  int Class_Number;
  int Class_Instance_Number;
  int Shared_Data_Types_Number;
  int Shared_Data_Types_Include_File_Names_Number;
  int Shared_Data_Type_Pointer_Names_Number;
  int Construction_Point_Record_Number;
  int Supervisor_Class_Name_Record_Number;
  int Record_Line_Number_for_Total_Thread_Number;
  int Thread_Function_Number;
  int Namespace_Record_Number;
  int Include_Directory_Record_Area[2];
  int Library_Directories_Record_Area[2];
  int Source_File_Locations_Record_Area[2];
  int Source_File_Names_Record_Area[2];
  int Main_File_Name_Record_Area[2];
  int Executable_File_Name_Record_Area[2];
  int Library_Names_Record_Area[2];
  int Header_File_Names_Record_Area[2];
  int Inter_Thread_Class_Header_File_Names_Record_Area[2];
  int Class_Names_Record_Area[2];
  int Class_Instance_Record_Area[2];
  int Shared_Data_Types_Include_Files_Record_Area[2];
  int Shared_Data_Types_Record_Area[2];
  int Shared_Data_Type_Pointer_Names_Record_Area[2];
  int Supervisor_Class_Construction_Point_Record_Area[2];
  int Supervisor_Class_Name_Record_Area[2];
  int Thread_Numbers_Record_Area[2];
  int Thread_Names_Record_Area[2];
  int Namespace_Record_Area[2];
private:
  void ReadConstString(const char * ConstString);
  char * GetConstString() const;
  void Clear_Pointer_Memory(char ** Pointer);
  bool Determine_Data_Record_Area(const char * Start_Point, const char * End_Point);
  int  Determine_Record_Number(int Start_Point, int End_Point);
  bool Determine_Record_Lines();
  void Determine_Data_Record_Numbers();
  void Print_End_of_Program();
  void Print_Read_Error_Information();
  bool Check_Descriptor_File_Name(const char * FileName);
  bool Check_Descriptor_File_Name(char * FileName);
  bool * gui_read_status;
  bool * error_status;
  char * DescriptorFileName;
  char * DescriptorFileDirectory;
  char * ConstString;
  int  Data_Record_StartLine;
  int  Data_Record_EndLine;
  int  Record_Number;
  bool Memory_Delete_Condition;
  bool Memory_Allocation_Started;
  bool DescriptorFileName_Receive_Condition;
  bool DescriptorFileDirectory_Receive_Condition;
  bool is_descriptor_file_name_true;
};

#endif /* DESCRIPTOR_FILE_DATA_COLLECTOR_H */
