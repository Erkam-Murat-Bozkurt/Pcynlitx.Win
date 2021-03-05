
#ifndef SOURCE_FILE_DESCRIPTIONS_READER_H
#define SOURCE_FILE_DESCRIPTIONS_READER_H

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Include_Directory_Description_Reader.h"
#include "Descriptor_File_Data_Collector.h"
#include "Descriptor_File_Reader_Initializer.h"
#include "Descriptor_File_Number_Processor.h"
#include "DirectoryOperations.h"


struct Source_File_Location_Data_Type
{
    char * Source_File_Location;
    int    Location_Number;
};

class Source_File_Descriptions_Reader
{
public:
  Source_File_Descriptions_Reader();
  Source_File_Descriptions_Reader(const Source_File_Descriptions_Reader & orig);
  virtual ~Source_File_Descriptions_Reader();
  void Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer);
  void Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer);
  void Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer);
  void Read_Source_File_Descriptions();
  int  Get_Header_Files_Number() const;
  int  Get_Source_File_Location_Number() const;
  int  Get_Source_File_Names_Number() const;
  char ** Get_Source_File_Locations() const;
  char ** Get_Source_File_Names() const;
  char ** Get_Header_File_Names() const;
  char ** Get_Header_File_Paths() const;
  void Clear_Dynamic_Memory();
private:
  void Set_Informations_Comes_From_Data_Collector();
  void Receive_Header_File_Names();
  void Receive_Source_File_Locations();
  void Receive_Source_File_Names();
  void Place_String(char ** Pointer, char * String);
  void Place_Information(char ** Pointer, char * Information, int * index_counter, size_t Start_Point);
  void Clear_Pointer_Memory(char ** Pointer);
  void Print_End_of_Program();
  void Print_Read_Error_Information();
  void Print_Brace_Data_Read_Error(int Readed_Data, char * Data_Type);
  bool Check_Empty_Decleration(char * String);
  Descriptor_File_Data_Collector * Data_Collector_Pointer;
  Descriptor_File_Reader_Initializer * Initializer_Pointer;
  Descriptor_File_Number_Processor * Number_Processor_Pointer;
  Source_File_Location_Data_Type * Source_File_Locations_Pointer;
  DirectoryOperations Directory_Manager;
  int Header_File_Names_Number;
  int Source_File_Number;
  int Source_File_Location_Number;
  int Include_Directory_Number;
  bool Memory_Delete_Condition;
  bool is_empty_decleration;
  char ** Source_File_Locations;
  char ** Source_File_Names;
  char ** Header_File_Names;
  char ** Header_File_Paths;
};

#endif /* SOURCE_FILE_DESCRIPTIONS_READER_H */
