
#include <iostream>
#include "IntToCharTranslater.h"

int main(){

    IntToCharTranslater Translater;

    char numbers[ ] ={'1','\0'};

    int number = Translater.TranslateFromCharToInt(numbers);

    int power = Translater.Power(10,3);

    std::cout << "\n number:" << number;

    std::cout << "\n Power(10,3): " << power;

    std::cout << "\n";

    return 0;
}
