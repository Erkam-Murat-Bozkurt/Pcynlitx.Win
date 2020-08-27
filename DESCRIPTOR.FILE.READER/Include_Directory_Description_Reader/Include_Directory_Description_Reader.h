
#ifndef INCLUDE_DIRECTORY_DESCRIPTION_READER_H
#define INCLUDE_DIRECTORY_DESCRIPTION_READER_H

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Descriptor_File_Data_Collector.h"
#include "Descriptor_File_Reader_Initializer.h"
#include "Descriptor_File_Number_Processor.h"

struct Include_Directory_Type {

    char * Include_Directory;
    int    Directory_Number;
    int    Total_Include_Directory_Number;
};

class Include_Directory_Description_Reader
{
public:
  Include_Directory_Description_Reader();
  Include_Directory_Description_Reader(const Include_Directory_Description_Reader & orig);
  virtual ~Include_Directory_Description_Reader();
  void Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer);
  void Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer);
  void Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer);
  void Read_Include_Directory_Descriptions();
  Include_Directory_Type * Get_Include_Directory() const;
  int  Get_Include_Directory_Number() const;
  void Clear_Dynamic_Memory();
private:
  void Receive_Include_Directory();
  void Set_Informations_Comes_From_Data_Collector();
  void Clear_Pointer_Memory(char ** Pointer);
  void Print_Read_Error_Information();
  void Print_End_of_Program();
  void Place_String(char ** Pointer, char * String);
  bool Check_Empty_Decleration(char * String);
  Descriptor_File_Data_Collector * Data_Collector_Pointer;
  Descriptor_File_Reader_Initializer * Initializer_Pointer;
  Descriptor_File_Number_Processor * Number_Processor_Pointer;
  Include_Directory_Type   * Include_Directory_Pointer;
  int Include_Directory_Number;
  bool Memory_Delete_Condition;
  bool is_empty_decleration;
};

#endif /* INCLUDE_DIRECTORY_DESCRIPTION_READER_H */
