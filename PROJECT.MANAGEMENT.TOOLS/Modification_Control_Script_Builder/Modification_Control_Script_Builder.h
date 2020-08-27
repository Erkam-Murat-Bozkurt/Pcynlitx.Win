
#ifndef MODIFICATION_CONTROL_SCRIPT_BUILDER_H
#define MODIFICATION_CONTROL_SCRIPT_BUILDER_H

#include <unistd.h>
#include <cstring>
#include "Cpp_FileOperations.h"

class Modification_Control_Script_Builder
{
public:
  Modification_Control_Script_Builder();
  Modification_Control_Script_Builder(const Modification_Control_Script_Builder & orig);
  virtual ~Modification_Control_Script_Builder();
  void Build_Script(char * Header_Files_Directory, char * Object_Files_Directory);
  void Find_Class_Name();
  void Clear_Dynamic_Memory();
private:
  Cpp_FileOperations FileManager;
  char * Class_Name;
  char * Class_Header_File_Name;
  char * Class_Object_File_Name;
  char * Current_Directory;
  bool Memory_Delete_Condition;
};

#endif /* MODIFICATION_CONTROL_SCRIPT_BUILDER_H */
