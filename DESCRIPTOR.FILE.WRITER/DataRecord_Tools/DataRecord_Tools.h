
#ifndef DATARECORD_TOOLS_H
#define DATARECORD_TOOLS_H

#include "DataRecorder.h"
#include <cstdlib>
#include <string>
#include <sstream>

class DataRecord_Tools
{
public:
  DataRecord_Tools();
  virtual ~DataRecord_Tools();
  void Clear_Dynamic_Memory();
  void Clear_Pointer_Memory(char ** Pointer);
  void SetFilePath(char * Descriptor_File_Path);
  void Determine_File_Informations(char * File_PATH);
  void Determine_Library_Name_Informations(char * Library_PATH);
  bool Is_Record_Exist(char * Data_Type,char * Input_Data);
  void Determine_Header_File_Name_Record_Data(char * File_Name, int Location_Number, int Data_Number);
  void Determine_Source_File_Name_Record_Data(char * File_Name, int Location_Number, int Data_Number);
  void Determine_ITC_Header_File_Name_Record_Data(char * File_Name, int Location_Number, int Data_Number);
  void Determine_ITD_Header_File_Name_Record_Data(char * File_Name, int Location_Number, int Data_Number);
  void Determine_Standart_Record_Data(char * Input_Data, int Record_Number);
  bool Compare_Strings(char * First_String, char * Second_String);
  char * Convert_to_char(int x);
  int    Get_Directory_Number();
  char * Get_File_Directory();
  char * Get_File_Name();
  char * Get_Standart_Record_Data();
  char * Get_Header_File_Name_Record_Data();
  char * Get_Source_File_Name_Record_Data();
  char * Get_ITC_Header_File_Name_Record_Data();
  char * Get_ITD_Header_File_Name_Record_Data();
private:
  void Place_Information(char ** Pointer, char * Information, int * counter);
  void Place_String(char ** Pointer, char * String);
  void Isolate_Input_Data(char * Input_Data);
  void Isolate_Record_Data(char * Record_Data);
  void Receive_Location_Number(int Location_Number);
  void Receive_Data_Number(int File_Number);
  bool is_record_exist;
  bool Memory_Delete_Condition;
  bool isStringsEqual;
  DataRecorder Recorder;
  int Directory_Number;
  char * Header_File_Names_Record_Data;
  char * Source_File_Names_Record_Data;
  char * ITC_Header_File_Name_Record_Data;
  char * ITD_Header_File_Name_Record_Data;
  char * File_Name;
  char * File_Directory;
  char * Integer_Data;
  char * Input_String;
  char * Record_String;
  char * Data_Number;
  char * Location_Number;
  char * Record_Data;
};


#endif /* DATARECORD_TOOLS_H */
