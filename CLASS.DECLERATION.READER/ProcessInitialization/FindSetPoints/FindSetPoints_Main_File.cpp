

#include "FindSetPoints.h"
#include <iostream>
#include <cstring>

int main(int argc, char ** argv){

  FindSetPoints Fsp;

  const char * HeaderFileName = "AutoCodeGenerator.h";

  int Name_Size = strlen(HeaderFileName);

  char * Header_File_Name = new char [2*Name_Size];

  for(int i=0;i<Name_Size;i++){

      Header_File_Name[i] = HeaderFileName[i];
  }

  Header_File_Name[Name_Size] = '\0';

  Fsp.DetermineSetPoints(Header_File_Name);

  std::cout << "\n Public line number : " << Fsp.getPublicLineNumber();

  std::cout << "\n Private line number : " << Fsp.getPrivateLineNumber();

  std::cout << "\n Protected line number :" << Fsp.getProtectedLineNumber();

  std::cout << "\n Decleration end :"  << Fsp.getDeclerationEnd();

  std::cout << "\n PublicDeclerationArea :" << Fsp.getPublicDeclerationArea();

  std::cout << "\n PrivateDeclerationArea :" << Fsp.getPrivateDeclerationArea();

  std::cout << "\n ProtectedDeclerationArea :" << Fsp.getProtectedDeclerationArea();

  std::cout << "\n AcessTypesError :" << Fsp.getAcessTypesError();

  std::cout << "\n Is there public method :" << Fsp.isTherePublicMethod();

  std::cout << "\n Is there private method :" << Fsp.isTherePrivateMethod();

  std::cout << "\n Is there protected method :" << Fsp.isThereProtectedMethod();

  std::cout << "\n The end of the program ..\n";

  delete [] Header_File_Name;

  return 0;
}
