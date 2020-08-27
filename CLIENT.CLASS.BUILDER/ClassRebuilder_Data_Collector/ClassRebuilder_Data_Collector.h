
#ifndef CLASSREBUILDER_DATA_COLLECTOR_H
#define CLASSREBUILDER_DATA_COLLECTOR_H

#include "DirectoryOperations.h"
#include "ClassRebuilder_Initializer.h"
#include "Descriptor_File_Reader.h"
#include "DirectoryOperations.h"
#include "CFileOperations.h"
#include "Custom_System_Interface.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

class ClassRebuilder_Data_Collector
{
public:
  ClassRebuilder_Data_Collector();
  ClassRebuilder_Data_Collector(const ClassRebuilder_Data_Collector & orig);
  virtual ~ClassRebuilder_Data_Collector();
  void Clear_Dynamic_Memory();
  void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
  void Receive_ClassRebuilder_Initializer(ClassRebuilder_Initializer * Pointer);
  void Reiceve_Directory_Manager(DirectoryOperations * Pointer);
  void Collect_System_Command_Informations();
  void Run_System_Commands();
  void Print_System_Commands();
  char * Get_Object_File_Name() const;
private:
  void Determine_Compiler_Command();
  void Remove_Class_Implementation_File();
  void Remove_Header_Extra();
  void Place_Information(char ** Pointer, char * Information, int * counter);
  void Place_String(char ** Pointer, char * String, int String_Size);
  bool Memory_Delete_Condition;
  DirectoryOperations * Directory_Manager_Pointer;
  Descriptor_File_Reader * Reader_Pointer;
  ClassRebuilder_Initializer * Initializer;
  CFileOperations File_Manager;
  DirectoryOperations Directory_Manager;
  Custom_System_Interface System_Interface;
  char * Compiler_Command;
  char * Object_File_Name;
  char * Constructed_Include_Directory;
};

#endif /* CLASSREBUILDER_DATA_COLLECTOR_H */
