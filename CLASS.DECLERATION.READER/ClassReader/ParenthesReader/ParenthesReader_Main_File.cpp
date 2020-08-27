
#include <iostream>
#include "SyntaxController.h"
#include "ParenthesReader.h"


int main( ){

   const char * method = "int Sum(int x, int y);";

   int String_Size = strlen(method);

   char * pointer = new char [5*String_Size];

   for(int i=0;i< String_Size;i++){

       pointer[i] = method[i];
   }

   pointer[String_Size] = '\0';

   std::cout << "\n\n MethodLine:" << pointer << "#";

   SyntaxController SynCntr;

   char Name[] = {'I','n','t','e','g','e','r','S','u','m','\0'};

   SynCntr.ReceiveClassContructorName(Name);

   SynCntr.ReceiveMethod(pointer);

   SynCntr.CheckMethodSyntax();

   std::cout << "\n Syntax Error Condition:" << SynCntr.getSyntaxErrorCondition();

   if(SynCntr.getClassConstructorName()[0] == '\0'){

      std::cout << "\n There is an error ..";
   }
   else{

        std::cout << "\n SynCntr.getClassConstructorName():" << SynCntr.getClassConstructorName();
   }

   ParenthesReader PhObject;

   PhObject.SetSyntaxErrorStatus(SynCntr.getSyntaxErrorCondition());

   PhObject.ReadMethodParenthes(pointer);

   std::cout << "\n Method Parameter Number: " << PhObject.getMethodParameterNumber();

   std::cout << "\n";

   std::cout << "\n The MethodParenthes :";

   if(PhObject.getMethodParenthes() == '\0'){

      std::cout << " EMPTY ..";
   }
   else{

       std::cout << PhObject.getMethodParenthes() << "#";
   }

   PhObject.Clear_Dynamic_Memory();

   std::cout << "\n\n The end o the program..\n\n";

   delete [] pointer;

   return 0;
}
