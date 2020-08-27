
#include <iostream>
#include "ClassSyntaxControl.h"

void Place_String(char ** Pointer, const char * String){

     int Method_Line_Size = strlen(String);

     *Pointer = new char [5*Method_Line_Size];

     for(int i=0;i<Method_Line_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[Method_Line_Size] = '\0';
}


int main(int argc, char** argv){

    ClassSyntaxControl ClassSynCntr;

    const char * Header_Name = "AutoCodeGenerator.h";

    char * Header_File_Name = nullptr;

    Place_String(&Header_File_Name,Header_Name);

    ClassSynCntr.CheckClassSyntax(Header_File_Name);

    std::cout << "\n Class word line:" << ClassSynCntr.GetClassWordLineNumber();

    std::cout << "\n FirstBraceLine:"  << ClassSynCntr.GetFirstBraceLine();

    std::cout << "\n LastBraceLine :"  << ClassSynCntr.GetLastBraceLine();

    std::cout << "\n Is there a class word:" << ClassSynCntr.isThereClassWord();

    std::cout << "\n Is there a class name:" << ClassSynCntr.isThereClassName();

    std::cout << "\n Is there a public key word:" << ClassSynCntr.isTherePublicKeyWord();

    std::cout << "\n Is there a private key word:" << ClassSynCntr.isTherePrivateKeyWord();

    std::cout << "\n Is there a protected key word:" << ClassSynCntr.isThereProtectedKeyWord();

    std::cout << "\n Syntax Error status:" << ClassSynCntr.GetClassSyntaxErrorStatus();

    std::cout << "\n Class Word Line:" << ClassSynCntr.Get_Class_Word_Line() << "#";

    std::cout << "\n The end of program ..\n\n";

    delete [] Header_File_Name;

    return 0;
}
