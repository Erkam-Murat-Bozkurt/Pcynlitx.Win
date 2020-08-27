
#ifndef DESCRIPTION_PRINTER_H
#define DESCRIPTION_PRINTER_H

#include "Descriptor_File_Reader.h"
#include "CharOperator.h"
#include <string>
#include <cstring>


class Description_Printer
{
public:
  Description_Printer();
  virtual ~Description_Printer();
  void Receive_Descriptor_File_Directory(char * Descriptor_File_Path);
  void Read_Descriptions();
  void Print_Descriptions();
  bool Is_This_Header_File_Already_Printed(char * Header_File_Name);
private:
  Descriptor_File_Reader Description_Reader;
  bool Is_This_Already_Printed;
  CharOperator CharacterOperations;
};

#endif /* DESCRIPTION_PRINTER_H */
