
#ifndef PROCESS_DESCRIPTIONS_RECORDER_H
#define PROCESS_DESCRIPTIONS_RECORDER_H

#include "Cpp_FileOperations.h"
#include "DataRecorder.h"
#include "DataRecord_Tools.h"
#include <cstdlib>


class Process_Descriptions_Recorder
{
public:
  Process_Descriptions_Recorder();
  virtual ~Process_Descriptions_Recorder();
  void Set_Descriptor_File_Path(char * Descriptor_File_Path);
  int Record_Header_File_Location_Data(char * Include_Directory_Data);
  int Record_Source_File_Location_Data(char * Source_File_Locations_Data);
  int Record_Library_Locations_Data(char * Library_Locations_Data);
  int Record_Library_Names_Data(char * Library_Names_Data);
  int Record_Main_File_Name(char * Main_File_Name_Data);
  int Record_Thread_Function_Name(char * Function_Name_Data);
  int Record_Namespace(char * Namespace);
  int Record_OpenMP_Option(char * option);
  int Record_Construction_Point(char * Construction_Point_Data);
  int Record_Server_Class_Name(char * Server_Class_Name_Data);
  int Record_Executable_File_Name(char * Executable_File_Name);
  int Record_Thread_Number(char * Thread_Number_Data);
  int Record_Header_File_Name(char * Header_File_Name);
  int Record_Source_File_Name(char * Source_File_PATH);
  int Record_Inter_Thread_Class_Name(char * IT_Class_Name);
  int Record_Inter_Thread_Class_Instance_Name(char * IT_Class_Instance_Name);
  int Record_Inter_Thread_Data_Type(char * IT_Data_Type);
  int Record_Inter_Thread_Data_Type_Pointer_Name(char * IT_Data_Type_Pointer_Name);
  int Record_Inter_Thread_Class_Header_File_Name(char * IT_Class_Header_File_Name);
  int Record_Inter_Thread_Data_Type_Header_File_Name(char * IT_Data_Type_Header_File_Name);
  bool Compare_Strings(char * First_String, char * Second_String);
  void Clear_Dynamic_Memory();
private:
  void Record_Data_To_File(char * Data_Type, char * Data);
  DataRecord_Tools Record_Tools;
  DataRecorder Recorder;
  Cpp_FileOperations File_Manager;
  bool Memory_Delete_Condition;
  int Header_File_Location_Number;
};

#endif /* PROCESS_DESCRIPTIONS_RECORDER_H */
