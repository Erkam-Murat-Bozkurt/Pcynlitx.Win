
#ifndef METHODPROCESSOR_H
#define METHODPROCESSOR_H

#include "CharOperator.h"
#include "MethodInitializer.h"

class MethodProcessor
{
public:
  MethodProcessor();
  MethodProcessor(const MethodProcessor & orig);
  virtual ~MethodProcessor();
  void ReceiveMethod(char *);
  void CollectInformation();
  void setClassContructorName(char *);
  bool getMethodProcessorErrorCondition();
  int  getMethodParameterNumber();
  bool getClassConstructorStatus();
  bool getClassDestructorStatus();
  bool getFirstBraceExistance();
  bool getLastBraceExistance();
  int  getFirstBracePosition();
  int  getLastBracePosition();
  void CheckMethodSyntax();
  void setMethodProcessorErrorCondition(bool);
  void Clear_Dynamic_Memory();
  char * getClassContructorName();
  char * getClassDestructorName();
  char * getMethodLine();
  char * getMethodName();
private:
  CharOperator CharacterOperations;
  MethodInitializer Initializer;
  void Clear_Pointer_Memory(char ** Pointer);
  void FindFirstBracePosition();
  void FindLastBracePosition();
  void DetermineMethodParameterNumber();
  void checkClassContructorMatching();
  void checkClassDestructorMatching();
  void DetermineMethodName();
  char * MethodLine;
  char * ClassConstructorName;
  char * ClassDestructorName;
  char * MethodName;
  char * ReturnType;
  bool isClassConstructor;
  bool isClassDestructor;
  bool isThereReturnType;
  bool First_Brace_Existance;
  bool Last_Brace_Existance;
  bool MethodProcessorErrorCondition;
  int  FirstBracePosition;
  int  LastBracePosition;
  int  MethodParameterNumber;
  bool Memory_Delete_Condition;
};

#endif  /* METHODPROCESSOR_H */
