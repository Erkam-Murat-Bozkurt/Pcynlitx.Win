
#ifndef INCLUDED_HEADER_FILE_NAMES_READER_H
#define INCLUDED_HEADER_FILE_NAMES_READER_H

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "ClassNameReader.h"

class Included_Header_File_Names_Reader
{
public:
  Included_Header_File_Names_Reader();
  Included_Header_File_Names_Reader(const Included_Header_File_Names_Reader & orig);
  virtual ~Included_Header_File_Names_Reader();
  void Determine_Included_Header_File_Names(char * Header_File_Name);
  void Clear_Dynamic_Memory();
  std::string Get_Class_Name();
  std::string Get_Class_Source_File_Name();
  std::string Get_Class_Object_File_Name();
  std::string * Get_Included_Header_File_Names();
  std::string * Get_Included_Object_File_Names();
  std::string * Get_Header_File_Declarations();
  char ** Get_Header_File_Declarations_C_String();
  char ** Get_Header_File_Names_C_String();
  int Get_Included_Header_File_Number();
private:
  void Determine_Class_Name(char * Header_File_Name);
  void Determine_C_String_Declarations(); // Converts Header File Declarations from std::string to C string
  void Determine_C_String_Header_File_Names();
  void Determine_Included_Header_Files_Number();
  void Determine_Object_File_Names();
  void Read_Include_File_Names();
  bool Include_Line_Determiner(std::string String_Line);
  ClassNameReader CNR;
  char ** Header_File_Declarations_C_String;
  char ** Header_File_Names_C_String;
  std::string * Included_Header_Files;
  std::string * Header_File_Declarations;
  std::string * Included_Object_Files;
  std::string   Class_Name;
  std::string   Class_Source_File_Name;
  std::string   Class_Header_File_Name;
  std::string   Class_Object_File_Name;
  int  Included_Header_Files_Number;
  bool Include_Line_Condition;
  bool Memory_Delete_Condition;
  std::fstream DataFile;
  std::string String_Line;
};


#endif /* INCLUDED_HEADER_FILE_NAMES_READER_H */
