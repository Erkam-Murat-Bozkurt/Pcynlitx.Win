
#ifndef STRINGOPERATOR_H
#define STRINGOPERATOR_H

#include <cstring>
#include "Cpp_FileOperations.h"
#include "CharOperator.h"


class StringOperator
{
public:
 StringOperator();
 StringOperator(const StringOperator & orig);
 virtual ~StringOperator();
 void SetFilePath(const char * TargetFilePath);
 void SetFilePath(char * TargetFilePath);
 void ReceiveFileLine(char * readline);
 void LoadStringBuffer(char * readline);
 void ClearStringBuffer();
 void Clear_Dynamic_Memory();
 int  FindNextWordLine(char * search_word,int startPoint);
 bool CheckStringLine(char * readline);
 void ReadWordBetweenToPoint(char * StringLine,int startPoint, int endPoint);
 int  GetBufferLength();
 bool CheckStringInclusion(char * StringLine,char * search_word);
 bool Get_File_End_Condition();
 int  Get_Start_Position_of_an_included_String();
 int  Get_Word_Number_on_String(char * String,char * word);
 char * ReadFileLine(int lineNumber);
 char * GetStringBuffer();
private:
 CharOperator CharacterOperations;
 Cpp_FileOperations Cpp_File_Manager;
 int Word_Count;
 int wordPosition;
 int Included_Word_Start_Position;
 int BufferLength;
 bool File_End_Condition;
 bool isStringLine;
 bool includeCondition;
 bool isBufferEmpty;
 bool Included_Word_Start_Position_Set_Condition;
 bool Memory_Delete_Condition;
 char * StringBuffer;
};

#endif /* STRINGOPERATOR_H */


/* FindNextWordLine : This member function search a word from the start point to the end of file

                      It stops the searching when it find a word maches the search word

                      However, it returns true if the readed line includes only the search word   */

/* CheckStringLine : This member function determines that this line information includes a string

                     It returns false if the readed line only includes a null character or a new line character */
