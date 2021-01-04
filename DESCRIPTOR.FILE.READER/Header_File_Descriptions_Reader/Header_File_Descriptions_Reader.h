
#ifndef HEADER_FILE_DESCRIPTIONS_READER_H
#define HEADER_FILE_DESCRIPTIONS_READER_H

#include "Include_Directory_Description_Reader.h"
#include "Descriptor_File_Data_Collector.h"
#include "Descriptor_File_Reader_Initializer.h"
#include "Descriptor_File_Number_Processor.h"
#include "DirectoryOperations.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

class Header_File_Descriptions_Reader
{
public:
  Header_File_Descriptions_Reader();
  Header_File_Descriptions_Reader(const Header_File_Descriptions_Reader & orig);
  virtual ~Header_File_Descriptions_Reader();
  void Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer);
  void Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer);
  void Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer);
  void Receive_Include_Directory_Description_Reader(Include_Directory_Description_Reader * Pointer);
  void Receive_Header_File_Names();
  void Clear_Dynamic_Memory();
  int  Get_Header_Files_Number() const;
  char ** Get_Header_File_Names() const;
  char ** Get_Header_File_Paths() const;
private:
  void Set_Informations_Comes_From_Data_Collector();
  void Place_String(char ** Pointer, char * String);
  void Place_Information(char ** Pointer, char * Information, int * index_counter, int Start_Point);
  void Clear_Pointer_Memory(char ** Pointer);
  void Print_End_of_Program();
  void Print_Read_Error_Information();
  void Print_Brace_Data_Read_Error(int Readed_Data, char * Data_Type);
  bool Check_Empty_Decleration(char * String);
  void Place_Null(char ** Pointer, size_t size);
  Descriptor_File_Data_Collector * Data_Collector_Pointer;
  Descriptor_File_Reader_Initializer * Initializer_Pointer;
  Descriptor_File_Number_Processor * Number_Processor_Pointer;
  Include_Directory_Description_Reader * ID_Description_Reader;
  DirectoryOperations Directory_Manager;
  char ** Header_File_Names;
  char ** Header_File_Paths;
  bool Memory_Delete_Condition;
  int Header_File_Names_Number;
  int Include_Directory_Number;
  bool is_empty_decleration;
};

#endif /* HEADER_FILE_DESCRIPTION_READER_H */
