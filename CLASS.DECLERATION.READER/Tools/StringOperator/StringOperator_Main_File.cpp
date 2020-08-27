
#include "StringOperator.h"

int main(){

    StringOperator S_OPR;

    char File_Path [] = "TestFile";

    char search_word [] = "50.00";

    S_OPR.SetFilePath(File_Path);

    char * String = S_OPR.ReadFileLine(7);

    int Word_Count = S_OPR.Get_Word_Number_on_String(String,search_word);

    std::cout << "\n Word_Count:"  << Word_Count;

    std::cout << "\n Line :" << S_OPR.GetStringBuffer();

    std::cout << "\n The end of the program..\n\n";

    return 0;
}
