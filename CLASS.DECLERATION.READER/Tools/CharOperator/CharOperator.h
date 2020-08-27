
/* This class is a character processor for a file or documents */

#ifndef CHAROPERATOR_H
#define CHAROPERATOR_H

#include "CFileOperations.h"
#include "Cpp_FileOperations.h"
#include <string>
#include <iostream>
#include <cstring>

class CharOperator
{
public:
  CharOperator();
  CharOperator(const CharOperator & orig);
  virtual ~CharOperator();
  void SetFilePath(const char * path);                                // Set the file path
  int  DetermineTotalMethodNumber();                                  // The return value is that how many method exist in the file
  int  DetermineCharacterRepitation(char * list, char c);             // The function determines that how many character is there in a list
  int  FindNextCharacterPositon(char * list, int start ,char c);      // Search a character in a list starting from a given point..
  int  FindTheSpecificWordLine(std::string line);                     // The return value is the line number includes a specific word..
  void ForwardFilePointer(CFileOperations * pointer, int start);      // Move File Pointer
  void ForwardFilePointer(Cpp_FileOperations * pointer, int start);   // Move File Pointer
  int  CharListLength(char * list);                                   // The return value is the length of a character list..
  int  FindFirstCharacterPosition(char * list);                       // Finds first character position in a list
  bool CharacterCheck(char * list, char c);                           // Does exist character which selected in the list
  bool CompareString(char * firstString,char * secondString);         // Compares two string
  void Clear_Dynamic_Memory();
private:
  CFileOperations FileManager;
  bool Memory_Delete_Condition;
  int  TotalMethodNumber;
  int  CharacterPosition;
  int  CharacterRepitation;
  int  WordPosition;
  int  ListLength;
  int  FileEnd;
  int  FirstCharacterPosition;
  bool isStringsEqual;
};

#endif /* CHAROPERATOR_H */
