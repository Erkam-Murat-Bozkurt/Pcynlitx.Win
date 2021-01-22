
#include "MethodProcessor.h"
#include <iostream>

int main(){

    // constructıon a random method for test

    const char * method = "   float & ~IntegerSum( );;";

    char * pointer = new char[strlen(method)];

    for(int i=0;i<strlen(method);i++){

        pointer[i]=method[i];
    }


    // Testing MethodProcessor class

    MethodProcessor MPr;

    char name[] = {'I','n','t','e','g','e','r','S','u','m','\0'};

    MPr.setClassContructorName(name);

    MPr.ReceiveMethod(pointer);

    MPr.CollectInformation();


    // Printing operations

    std::cout << "\n\n MethodName:"

              << MPr.getMethodName();

    std::cout << "\n\n MPr.getMethodLine():"

              << MPr.getMethodLine();

    std::cout << "\n\n Class Constructor Status:"

              << MPr.getClassConstructorStatus();

    std::cout << "\n\n Class Destructor Status :"

              << MPr.getClassDestructorStatus();

    delete [] pointer;


    std::cout << "\n\n The end of the program ..\n\n";

    return 0;
}
