
#include <iostream>
#include <cstring>
#include "DirectoryOperations.h"
#include "ClassNameReader.h"
#include "CharOperator.h"

int main(int argc, char** argv){

    ClassNameReader Reader;

    DirectoryOperations Dir_Control;

    char target_dir []

      = "D:\\PCYNLITX.PROJECT.WINDOWS\\CLASS.DECLERATION.READER\\Tools\\IntToCharTranslater";

    Dir_Control.ChangeDirectory(target_dir);

    char Header_Path [] = "IntToCharTranslater.h";

    Reader.ReadClassName(Header_Path);

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
