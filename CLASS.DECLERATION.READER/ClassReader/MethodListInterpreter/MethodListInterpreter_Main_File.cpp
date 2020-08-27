
#include "MethodListInterpreter.h"
#include <cstdlib>

int main(int argc, char** argv){

   MethodListInterpreter Interpreter;

   Interpreter.SetFilePath("AutoCodeGenerator_MFDL_MF");

   Interpreter.ReadMetaData();

   if(Interpreter.GetPublicDeclerationExistance()){

       std::cout << "\n Public Method Number :" << Interpreter.GetPublicMethodNumber();

       std::cout << "\n Public methods start line :" << Interpreter.GetPublicRecordsStartLine();
   }

   if(Interpreter.GetPrivateDeclerationExistance()){

      std::cout << "\n Private Method Number :" << Interpreter.GetPrivateMethodNumber();

      std::cout << "\n Private methods start line :" << Interpreter.GetPrivateRecordsStartLine();
   }

   if( Interpreter.GetProtectedDeclerationExistance()){

      std::cout << "\n Protected Method Number :" << Interpreter.GetProtectedMethodNumber();

      std::cout << "\n Protected methods start line :" << Interpreter.GetProtectedRecordsStartLine();
   }

   Interpreter.Clear_Dynamic_Memory();

   std::cout << "\n\n The end of the program ..\n\n";

   return 0;
}
