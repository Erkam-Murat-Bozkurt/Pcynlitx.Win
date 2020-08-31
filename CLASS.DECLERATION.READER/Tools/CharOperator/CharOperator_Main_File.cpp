
#include <iostream>
#include <cstring>
#include "CharOperator.h"


int main(){

    const char * method = "int IntegerSum(int integers);";

    int string_size = strlen(method);

    char * pointer = new char[5*string_size];

    for(int i=0;i<string_size;i++){

        pointer[i]=method[i];
    }

    pointer[string_size] = '\0';

    CharOperator CPr;

    CPr.SetFilePath("CharOperator_Test.txt");

    char name[] = {'\0'};

    int NextCharacterPosition = CPr.FindNextCharacterPositon(pointer,0,'g');

    std::cout << "\n NextCharacterPosition :" << NextCharacterPosition;

    bool condition = CPr.CharacterCheck(name,'k');

    std::cout << "\n The condition :" << condition;

    std::cout << name;

    int position = CPr.FindFirstCharacterPosition(name);

    std::cout << "\n The first character position of the list:" << position;

    int lineNumber = 0;

    lineNumber = CPr.FindTheSpecificWordLine("[END]");

    std::cout << "\n The line number:" << lineNumber;

    std::cin.get();

    int TotalMethodNumber = CPr.DetermineTotalMethodNumber( );

    std::cout << "\n TotalMethodNumber :" <<  TotalMethodNumber;

    char line[200];

    std::cout << "\n Enter a line :";

    std::cin.getline(line,200);

    std::cout << "\n The legth of the line: " << CPr.CharListLength(line);

    std::cout << "\n The length of the char name[]:" << CPr.CharListLength(name);

    char sample;

    std::cout << "\n Enter a character for that line for reputation :";

    std::cin  >> sample;

    std::cout << "\n The reputation:" << CPr.DetermineCharacterRepitation(line,sample);

    std::cout << "\n";

    return 0;

}
