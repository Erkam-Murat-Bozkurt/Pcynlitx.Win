
#include <iostream>
#include <SyntaxController.h>
#include <MethodProcessor.h>
#include <cstring>

int main(){

    const char * method = "void SetFilePath(const char * );;";

    int Method_Size = strlen(method);

    char * Pointer = new char [5*Method_Size];

    for(int i=0;i<Method_Size;i++){

        Pointer[i] = method[i];
    }

    Pointer[Method_Size] = '\0';

    std::cout << "\n\n Pointer:" << Pointer;

    SyntaxController SynCntr;

    char Name[] = {'I','n','t','e','g','e','r','S','u','m','\0'};

    SynCntr.ReceiveClassContructorName(Name);

    SynCntr.ReceiveMethod(Pointer);

    std::cout << "\n SynCntr.getClassConstructorName():" << SynCntr.getClassConstructorName();

    SynCntr.CheckMethodSyntax();

    if(SynCntr.getSyntaxErrorCondition()){

       std::cout << "\n There is a syntax error ..";

    }
    else
    {
      std::cout << "\n There is no syntax error ..";

      std::cout << "\n The MethodLine :" << SynCntr.getMethodLine();
    }

    std::cout << "\n Is There a comma at the end of the method ? " << SynCntr.getEndCommaExistance();

    delete [] Pointer;

    std::cout << "\n The end of the program ..\n\n";

    return 0;
}
