
#ifndef INTER_THREAD_DATA_TYPE_DESCRIPTION_READER_H
#define INTER_THREAD_DATA_TYPE_DESCRIPTION_READER_H

#include <cstring>
#include <cstdlib>
#include "Include_Directory_Description_Reader.h"
#include "Descriptor_File_Data_Collector.h"
#include "Descriptor_File_Reader_Initializer.h"
#include "Descriptor_File_Number_Processor.h"
#include "DirectoryOperations.h"


struct Shared_Memory_Data_Type {

    char * Data_Type;
    char * Header_File_Name;
    char * Include_Directory;
    char * Pointer_Name;
    int    Data_Number;
    int    Total_Data_Type_Number;
};

struct Shared_Memory_Pointer {

    char * Pointer_Names;
    int    Data_Type_Number;
};

struct Shared_Memory_Header {

    char * Header_File_Name;
    char * Include_Directory;
    int  * Data_Type_Number;
};

class Inter_Thread_Data_Type_Description_Reader
{
public:
  Inter_Thread_Data_Type_Description_Reader();
  Inter_Thread_Data_Type_Description_Reader(const Inter_Thread_Data_Type_Description_Reader & orig);
  virtual ~Inter_Thread_Data_Type_Description_Reader();
  void Receive_Data_Collector(Descriptor_File_Data_Collector * Pointer);
  void Receive_Initializer(Descriptor_File_Reader_Initializer * Pointer);
  void Receive_Number_Processor(Descriptor_File_Number_Processor * Pointer);
  void Receive_Include_Directory_Description_Reader(Include_Directory_Description_Reader * Ponter);
  void Read_Inter_Thread_Data_Type_Descriptions();
  Shared_Memory_Data_Type  * Get_Shared_Data_Types() const;
  int  Get_Shared_Data_Types_Number() const;
  int  Get_Shared_Data_Types_Include_File_Names_Number() const;
  void Clear_Dynamic_Memory();
private:
  void Receive_Shared_Memory_Data_Types_Header_File_Names();
  void Receive_Shared_Memory_Pointer_Names();
  void Receive_Shared_Memory_Data_Types();
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
  Shared_Memory_Data_Type  * Shared_Memory_Data_Type_Pointer;
  Shared_Memory_Header * Shared_Memory_Header_Pointer;
  Include_Directory_Type * Include_Directory_Pointer;
  Shared_Memory_Pointer * Shared_Memory_Pointer_Names_Holder;
  int Shared_Data_Types_Header_File_Names_Number;
  int Shared_Data_Types_Number;
  int Include_Directory_Number;
  bool Memory_Delete_Condition;
  bool is_empty_decleration;
};

#endif /* INTER_THREAD_DATA_TYPE_DESCRIPTION_READER_H */
