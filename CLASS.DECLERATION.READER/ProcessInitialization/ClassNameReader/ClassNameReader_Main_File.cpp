
#include <iostream>
#include <cstring>
#include "ClassNameReader.h"
#include "CharOperator.h"


int main(int argc, char** argv){

   ClassNameReader Reader;

   char Class_Name [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile/IntToCharTranslater.h";

   Reader.ReadClassName(Class_Name);

   if(Reader.GetClassSyntaxErrorStatus()){

       std::cout << "\n There is a syntax error in class decleration ..!";

       std::cout << "\n The name of the given class :" << Reader.getClassName();

       std::cout << "#";
   }
   else{

        std::cout << "\n The name of the given class :" << Reader.getClassName();

        std::cout << "#";
   }

   std::cout << "\n The end of the program..\n\n";

   return 0;
}
