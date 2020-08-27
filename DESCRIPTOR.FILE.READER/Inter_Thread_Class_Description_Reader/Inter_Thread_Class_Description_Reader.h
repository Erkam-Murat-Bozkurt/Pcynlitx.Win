
#ifndef INTER_THREAD_CLASS_DESCRIPTION_READER_H
#define INTER_THREAD_CLASS_DESCRIPTION_READER_H

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Include_Directory_Description_Reader.h"
#include "Descriptor_File_Data_Collector.h"
#include "Descriptor_File_Reader_Initializer.h"
#include "Descriptor_File_Number_Processor.h"
#include "DirectoryOperations.h"

struct Header_File_Data_Type {

    char * Header_File_Name;
    char * File_Location;
    int    Class_Number;
};

struct Class_Data_Type {

    char * Class_Name;
    char * Class_Instance_Name;
    char * Header_File_Name;
    char * Header_File_Location;
    int    Class_Number;
    int    Total_Class_Number;
};

struct Class_Instance_Data_Type{

    char * Class_Instance_Name;
    int    Class_Number;
};

class Inter_Thread_Class_Description_Reader
{
public:
  Inter_Thread_Class_Description_Reader();
  Inter_Thread_Class_Description_Reader(const Inter_Thread_Class_Description_Reader & orig);
  virtual ~Inter_Thread_Class_Description_Reader();
  void Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer);
  void Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer);
  void Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer);
  void Receive_Include_Directory_Description_Reader(Include_Directory_Description_Reader * Pointer);
  void Read_Inter_Thread_Class_Descriptions();
  Class_Data_Type * Get_Class_Names() const;
  int  Get_Class_Number() const;
  void Clear_Dynamic_Memory();
private:
  void Receive_Inter_Thread_Class_Header_File_Names();
  void Receive_Inter_Thread_Class_Names();
  void Receive_Inter_Thread_Class_Instance_Names();
  void Set_Informations_Comes_From_Data_Collector();
  void Receive_Include_Directory();
  void Clear_Pointer_Memory(char ** Pointer);
  void Print_Read_Error_Information();
  void Print_End_of_Program();
  void Place_String(char ** Pointer, char * String);
  bool Check_Empty_Decleration(char * String);
  Descriptor_File_Data_Collector * Data_Collector_Pointer;
  Descriptor_File_Reader_Initializer * Initializer_Pointer;
  Descriptor_File_Number_Processor * Number_Processor_Pointer;
  Include_Directory_Description_Reader * ID_Description_Reader;
  DirectoryOperations Directory_Manager;
  Include_Directory_Type   * Include_Directory_Pointer;
  Header_File_Data_Type    * Header_File_Data_Type_Pointer;
  Class_Data_Type          * Class_Data_Type_Pointer;
  Class_Instance_Data_Type * Class_Instance_Data_Type_Pointer;
  int Inter_Thread_Class_Number;
  int Inter_Thread_Class_Header_File_Names_Number;
  int Include_Directory_Number;
  bool Memory_Delete_Condition;
  bool is_empty_decleration;
};

#endif /* INTER_THREAD_CLASS_DESCRIPTION_READER_H */
