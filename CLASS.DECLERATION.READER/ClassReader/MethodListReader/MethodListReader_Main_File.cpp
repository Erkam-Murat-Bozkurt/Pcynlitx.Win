

#include <iostream>
#include <cstring>
#include "MethodListReader.h"
#include "DirectoryOperations.h"

void PrintMethods(MethodListReader * MLrObject);

int main(int argc, char ** argv){

   DirectoryOperations DirectoryManager;

   MethodListReader MLrObject;

   MLrObject.SetMethodListPath("AutoCodeGenerator_MFDL");

   MLrObject.SetMetaFilePath("AutoCodeGenerator_MFDL_MF");

   MLrObject.ReadMethodList();

   PrintMethods(&MLrObject);

   std::cout << "\n\n The end of the program ..\n\n";

   return 0;
}

void PrintMethods(MethodListReader * MLrObject){

     for(int i=0; i< MLrObject->GetPublicMethodNumber();i++){

         if(MLrObject->GetPublicMethods()[i][0] == '\0'){

              std::cout << "\n Public Method [" << i << "]: Syntax Error ..";
         }
         else{

              std::cout << "\n Public Method [" << i << "]: " << MLrObject->GetPublicMethods()[i];
         }
     }

     std::cout << "\n";

     for(int i=0; i< MLrObject->GetPrivateMethodNumber();i++){

         if(MLrObject->GetPrivateMethods()[i][0] == '\0'){

              std::cout << "\n Private Method [" << i << "]: Syntax Error ..";
         }
         else{

              std::cout << "\n Private Method [" << i << "]: " << MLrObject->GetPrivateMethods()[i];
         }
     }

     std::cout << "\n";

     for(int i=0; i< MLrObject->GetProtectedMethodNumber();i++){


         if(MLrObject->GetProtectedMethods()[i][0] == '\0'){

              std::cout << "\n Protected Method [" << i << "]: Syntax Error ..";
         }
         else{

              std::cout << "\n Protected Method [" << i << "]: " << MLrObject->GetProtectedMethods()[i];
         }
     }
}
