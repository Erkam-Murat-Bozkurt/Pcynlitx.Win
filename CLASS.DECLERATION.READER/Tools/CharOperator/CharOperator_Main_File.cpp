
#include <iostream>
#include <cstring>
#include "CharOperator.h"
#include "CFileOperations.h"


int main(){

    const char * method = "int IntegerSum(int integers);";

    char * pointer = new char[strlen(method)];

    for(int i=0;i<strlen(method);i++){

        pointer[i]=method[i];
    }

    CharOperator CPr;

    CPr.SetFilePath("MethodReaderMetaData");

    char name[] = {'\0'};

    int NextCharacterPosition = CPr.FindNextCharacterPositon(pointer,0,'g');

    std::cout << "\n NextCharacterPosition :" << NextCharacterPosition;

    bool condition = CPr.CharacterCheck(name,'k');

    std::cout << "\n The condition :" << condition;

    std::cout << name;

    int position = CPr.FindFirstCharacterPosition(name);

    std::cout << "\n The first character position of the list:" << position;

    int lineNumber = 0;

    lineNumber = CPr.FindTheSpecificWordLine("END");

    std::cout << "\n The line number:" << lineNumber;
    std::cin.get();
    std::cin.get();

    int TotalMethodNumber = CPr.DetermineTotalMethodNumber( );

    std::cout << "\n TotalMethodNumber :" <<  TotalMethodNumber;

    char line[100];

    std::cout << "\n Enter a line :";

    std::cin.getline(line,100);

    std::cout << "\n The legth of the line: " << CPr.CharListLength(line);

    std::cout << "\n The length of the char name[]:" << CPr.CharListLength(name);

    char sample;

    std::cout << "\n Enter a character for that line for reputation :";
    std::cin  >> sample;

    std::cout << "\n The reputation:" << CPr.DetermineCharacterRepitation(line,sample);

    std::cout << "\n";

    return 0;

}
