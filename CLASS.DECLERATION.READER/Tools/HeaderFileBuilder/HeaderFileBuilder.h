
#ifndef HEADERFILEBUILDER_H
#define HEADERFILEBUILDER_H

#include <ctype.h>
#include <cstring>
#include "CFileOperations.h"
#include "CharOperator.h"


class HeaderFileBuilder
{
public:
  HeaderFileBuilder();
  HeaderFileBuilder(const HeaderFileBuilder & orig);
  virtual ~HeaderFileBuilder();
  char ConvertToUpper(char character);
  void ReceiveClassName(char * name);
  void ReceiveHeaderFileName(char * name);
  void DetermineInclusionWord();
  void BuildHeaderFile();
  void Clear_Dynamic_Memory();
  char * GetClassName();
  char * GetInclusionWord();
  char * GetHeaderFileName();
private:
  void Clear_Pointer_Memory(char ** Pointer);
  void Place_String(char ** Pointer, char * String);
  CFileOperations FileManager;
  CharOperator CharacterOperations;
  bool   Memory_Delete_Condition;
  char   character;
  char * ClassName;
  char * InclusionWord;
  char * HeaderFileName;
  bool ClassNameReceiveCondition;
};

#endif /* HEADERFILEBUILDER_H */
