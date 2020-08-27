
#ifndef INTTOCHARTRANSLATER_H
#define INTTOCHARTRANSLATER_H

#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>

class IntToCharTranslater
{
public:
  IntToCharTranslater();
  IntToCharTranslater(const IntToCharTranslater & orig);
  virtual ~IntToCharTranslater();
  char * Translate(int integer);
  int TranslateFromCharToInt(char * ch);
protected:
  void Fill_Character_Memory(std::string string_number);
  void Clear_Character_Memory();
  bool Memory_Empty_Status;
  int int_number;
  char * char_number;
  std::string temp_str;
};

#endif /* INTTOCHARTRANSLATER_H */
