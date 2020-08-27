
#ifndef SYNTAXCONTROLLER_H
#define SYNTAXCONTROLLER_H

#include <cstring>
#include <cstdlib>
#include "MethodProcessor.h"
#include "CharOperator.h"

class SyntaxController
{
public:
   SyntaxController();
   SyntaxController(const SyntaxController & orig);
   virtual ~SyntaxController();
   void ReceiveClassContructorName(char *);
   void ReceiveMethod(char *);
   void CheckMethodSyntax();
   void setSyntaxErrorCondition(bool);
   bool getSyntaxErrorCondition();
   bool getClassDestructorStatus();
   bool getClassConstructorStatus();
   void setClassDestructorStatus(bool);    // Is this method the class destructor (This information is come from MethodProcessor class)
   void setClassConstructorStatus(bool);   // Is this method the class contructor (This information is come from MethodProcessor class)
   void setFirstBraceExistance(bool);      // Exist or not exist (This information is come from MethodProcessor class)
   void setLastBraceExistance(bool);       // Exist or not exist (This information is come from MethodProcessor class)
   void setFirstBracePosition(int);        // This member function set the method's first brace position and this information received from MethodProcessor class
   void setLastBracePosition(int);         // This member function set the method's last brace position and this information received from MethodProcessor class
   void setMethodParameterNumber(int);     // This member function set the method's parameter number and this information received from MethodProcessor class
   bool getEndCommaExistance();
   int  getFirstBracePosition();
   int  getLastBracePosition();
   bool getFirstBraceExistance();
   bool getLastBraceExistance();
   int  getMethodParameterNumber();
   void Clear_Dynamic_Memory();
   char * getClassConstructorName();
   char * getClassDestructorName();
   char * getMethodLine();
private:
   void checkParameterSyntax();
   void checkFirstSpace();
   void checkMethodName();
   void checkEndComma();
   bool isThereFirstBrace();
   bool isThereLastBrace();
   void Place_String(char ** Pointer, char * String, int String_Size);
   void Place_Null(char ** Pointer,int String_Size);
   void Clear_Pointer_Memory(char ** Pointer);
   CharOperator CharacterOperations;
   MethodProcessor MethodInitializer;
   char * MethodLine;                    // This pointer holds the information about method line after setup operations. This information received from MethodProcessor
   char * ClassContructorName;
   char * ClassDestructorName;
   int  FirstBracePosition;
   int  LastBracePosition;
   bool isFirstBraceExist;
   bool isLastBraceExist;
   bool isEndCommaExist;
   bool SyntaxErrorCondition;
   int  MethodParameterNumber;
   bool isThisClassConstructor;
   bool isThisClassDestructor;
   bool Memory_Delete_Condition;
};
#endif
