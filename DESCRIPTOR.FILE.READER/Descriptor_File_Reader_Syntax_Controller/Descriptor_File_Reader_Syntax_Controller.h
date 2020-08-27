
#ifndef DESCRIPTOR_FILE_READER_SYNTAX_CONTROLER_H
#define DESCRIPTOR_FILE_READER_SYNTAX_CONTROLER_H

#include "MemberFunctionReader.h"
#include "Inter_Thread_Class_Description_Reader.h"
#include "Inter_Thread_Data_Type_Description_Reader.h"

class Descriptor_File_Reader_Syntax_Controler
{
public:
  Descriptor_File_Reader_Syntax_Controler();
  Descriptor_File_Reader_Syntax_Controler(const Descriptor_File_Reader_Syntax_Controler & orig);
  virtual ~Descriptor_File_Reader_Syntax_Controler();
  void Determine_Class_Data_Type_Receive_Condition(bool condition);
  void Determine_Shared_Data_Type_Receive_Condition(bool condition);
  void Receive_Inter_Thread_Class_Data(Class_Data_Type * Data);
  void Receive_Inter_Thread_Data_Type_Data(Shared_Memory_Data_Type * Data);
  void Receive_Construction_Point(char * Construction_Point);
  void Control_Process_Syntax();
  void Clear_Dynamic_Memory();
private:
  void Place_String(char ** Pointer, char * String, int String_Size);
  void Place_Information(char ** Pointer, char * Information, int * index_counter);
  void Determine_Inter_Thread_Class_Informations(Class_Data_Type Class_Data_Holder);
  void Determine_Shared_Data_Type_Informations(Shared_Memory_Data_Type Data_Holder);
  MemberFunctionReader FunctionReader;
  bool Memory_Delete_Condition;
  bool Class_Data_Type_Receive_Condition;
  bool Shared_Data_Type_Receive_Condition;
  Class_Data_Type * Class_Data_Type_Holder;
  Shared_Memory_Data_Type * Shared_Memory_Data_Type_Holder;
  char * Construction_Point;
  char * Header_File_Path;
  char * Header_File_Location;
};


#endif /* PROCESS_SUPERVISOR_DESCRIPTOR_FILE_READER_SYNTAX_CONTROLLER_H */
