
#include "MethodProcessor.h"
#include <iostream>

int main(){

    const char * method = "   float & ~IntegerSum( );;";

    char * pointer = new char[strlen(method)];

    for(int i=0;i<strlen(method);i++){

        pointer[i]=method[i];
    }

    MethodProcessor MPr;

    char name[] = {'I','n','t','e','g','e','r','S','u','m','\0'};

    MPr.setClassContructorName(name);

    MPr.ReceiveMethod(pointer);

    MPr.CollectInformation();

    std::cout << "MethodName:" << MPr.getMethodName();

    std::cout << "\n\n MPr.getMethodLine():" << MPr.getMethodLine();

    std::cout << "\n Class Constructor Status:" << MPr.getClassConstructorStatus();

    std::cout << "\n Class Destructor Status :" << MPr.getClassDestructorStatus();

    delete [] pointer;

    std::cout << "\n\n The end of the program ..\n\n";

    return 0;
}
