
#ifndef KERNEL_DATA_COLLECTOR_H
#define KERNEL_DATA_COLLECTOR_H

#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "DirectoryOperations.h"
#include "Descriptor_File_Reader.h"


class Kernel_Data_Collector
{
public:
  Kernel_Data_Collector();
  Kernel_Data_Collector(const Kernel_Data_Collector & orig);
  virtual ~Kernel_Data_Collector();
  void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
  void Clear_Dynamic_Memory();
  void Jump_To_Construction_Point();
  void Determine_Object_File_List();
  void Remove_Object_Files();
  void Construct_New_Library();
  void Construct_New_Include_Directory();
  char * Get_New_Include_Directory_Name();
private:
  void Clear_Pointer_Memory(char ** Pointer);
  void Place_String(char ** Pointer,char * String, int String_Size);
  void Place_Information(char ** Pointer, char * Information, int * index_counter);
  Descriptor_File_Reader * Reader_Pointer;
  DirectoryOperations DirectoryManager;
  bool Memory_Delete_Condition;
  char * New_Include_Directory_Name;
  char * Object_File_List;
  char * Library_Construction_Command;
};


#endif /* KERNEL_DATA_COLLECTOR_H */
