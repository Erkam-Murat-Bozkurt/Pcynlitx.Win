
#include "MethodInitializer.h"
#include <iostream>
#include <cstring>

int main(){

    // A METHOD DEFINITION FOR TEST

    const char * method = "   float &   operator&( );";

    int listSize = strlen(method);

    char * pointer = new char [5*listSize];

    for(int i=0;i<listSize;i++){

        pointer[i]= method[i];
    }

    pointer[listSize] = '\0';


    // Testing the MethodInitializer class

    MethodInitializer MPr;

    MPr.ReceiveMethod(pointer);

    MPr.ProcessMethodInformation();

    std::cout << "\n\n MPr.getMethodLine():"

              << MPr.getMethodLine();

    std::cout << "\n\n MPr.getMethodInitializerErrorCondition():"

              << MPr.getMethodInitializerErrorCondition();

    delete [] pointer;

    std::cout << "\n\n The end of the program ..\n\n";

    return 0;
}
