
#ifndef CLASSNAMEREADER_H
#define CLASSNAMEREADER_H

#include <cstring>
#include "ClassSyntaxControl.h"

class ClassNameReader
{
public:
  ClassNameReader();
  ClassNameReader(const ClassNameReader & orig);
  virtual ~ClassNameReader();
  void ReadClassName(char * Header_File_Name);
  bool GetClassSyntaxErrorStatus();
  void Clear_Dynamic_Memory();
  char * getClassName();
private:
  void Place_Null(char ** Pointer, int List_Size);
  void Clear_Pointer_Memory(char ** Pointer);
  ClassSyntaxControl ClsSynCntr;
  char * ClassName;
  bool Memory_Delete_Condition;
  bool Class_Syntax_Error_Status;
};

#endif /* CLASSNAMEREADER_H */
