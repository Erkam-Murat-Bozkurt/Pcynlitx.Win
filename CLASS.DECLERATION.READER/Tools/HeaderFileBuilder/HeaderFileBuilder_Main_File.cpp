
#include <iostream>
#include "HeaderFileBuilder.h"

int main(int argc, char** argv){

    HeaderFileBuilder * Builder;

    if(argv[1] == '\0'){

       std::cout << "\n Class name can not be received ..\n";
       std::cout << "\n Please enter a class name after the executable file name!\n\n";

       return 0;
    }
    else{

         Builder = new HeaderFileBuilder;

         Builder->ReceiveClassName(argv[1]);

         Builder->ReceiveHeaderFileName(argv[2]);

         Builder->BuildHeaderFile();

         delete Builder;
    }

    std::cout << "\n The end of the program..\n";

    return 0;
}
