
/* This class can be used to determine the locations of "public:" and "private:" words
   in the class decleration file */

#ifndef FINDSETPOINTS_H
#define FINDSETPOINTS_H

#include <cstring>
#include "Cpp_FileOperations.h"
#include "ClassSyntaxControl.h"
#include "StringOperator.h"


class FindSetPoints
{
public:
  FindSetPoints();
  FindSetPoints(const FindSetPoints & orig);
  virtual ~FindSetPoints();
  void DetermineSetPoints(char * TargetHeaderFile);
  int  getPublicLineNumber();
  int  getPrivateLineNumber();
  int  getProtectedLineNumber();
  int  getDeclerationEnd();
  int  getPublicDeclerationArea();
  int  getPrivateDeclerationArea();
  int  getProtectedDeclerationArea();
  bool getAcessTypesError();       // This Methods gets true if a method doesn't have an acess types..
  bool isTherePublicMethod();
  bool isTherePrivateMethod();
  bool isThereProtectedMethod();
  void Clear_Dynamic_Memory();
private:
  int  SearchIntegerListIndex(int * integerList,int integerValue);
  void findPublicWordLine();
  void findPrivateWordLine();
  void findProtectedWordLine();
  void findDeclerationEnd();
  void findPublicDeclerationArea();
  void findPrivateDeclerationArea();
  void findProtectedDeclerationArea();
  bool checkMethodLine(char * Readed_Line);
  void DetermineHowManyAccessTypesExist();
  void Control_Methods_Acess_Types_Error(); // This Methods control that each method has an acess types
  void Determine_Is_There_Any_Public_Method();
  void Determine_Is_There_Any_Private_Method();
  void Determine_Is_There_Any_Protected_Method();
  Cpp_FileOperations FileManager;
  ClassSyntaxControl ClsSynCntr;
  StringOperator StringOperations;
  int publicLineNumber;
  int privateLineNumber;
  int protectedLineNumber;
  int declerationEnd;
  int PublicDeclerationArea;
  int PrivateDeclerationArea;
  int ProtectedDeclerationArea;
  int indexNumber;
  int HowManyAcessTypesExist;
  int * AcessPointList;
  bool  AcessTypesError;
  bool  is_There_Public_Methods;
  bool  is_There_Private_Methods;
  bool  is_There_Protected_Methods;
  bool  is_This_MethodLine;
  bool  Memory_Delete_Condition;
};

#endif /* FINDSETPOINTS_H */
