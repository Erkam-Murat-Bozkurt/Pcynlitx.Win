
#include <cstring>
#include "ClassNameReader.h"
#include "MethodReceiver.h"


int main(){

    const char * Method = "    ~AutoCodeGenerator(int number, char character);";

    int startPoint = 0;

    while(Method[startPoint] == ' '){

        startPoint++;
    }

    int Read_Line_Size = strlen(Method);

    int Method_Size = Read_Line_Size - startPoint;

    char * MethodLine = new char [5*Method_Size];

    int index_counter = 0;

    for(int i=startPoint;i<Read_Line_Size;i++){

        MethodLine[index_counter] = Method[i];

        index_counter++;
    }

    MethodLine[index_counter] = '\0';

    std::cout << "\n Received Method Line:" << MethodLine;

    MethodReceiver Receiver;

    ClassNameReader ClassName;

    const char * Class_Header_File = "AutoCodeGenerator.h";

    int Name_Size = strlen(Class_Header_File);

    char * Header_File = new char [5*Name_Size];

    for(int i=0;i<Name_Size;i++){

        Header_File[i] = Class_Header_File[i];
    }

    Header_File[Name_Size] = '\0';

    ClassName.ReadClassName(Header_File);

    Receiver.SetClassName(ClassName.getClassName());

    Receiver.ReceiveMethodLine(MethodLine);

    std::cout << "\n Method Line syntax error status :" << Receiver.getMethodSyntaxErrorStatus();

    std::cout << "\n Method Line :" << Receiver.getMethodLine();

    std::cout << "\n Class name  :" << Receiver.getClassName();

    std::cout << "\n Method Parenthes :" << Receiver.getMethodParenthes();

    std::cout << "\n Method parameter number  :" << Receiver.getMethodParameterNumber();

    std::cout << "\n Class constructor status :" << Receiver.getClassConstructorStatus();

    std::cout << "\n Class destructor status  :" << Receiver.getClassDestructorStatus();

    std::cout << "\n Class Constructor Name   :" << Receiver.getClassConstructorName();

    std::cout << "\n Class Destructor Name    :" << Receiver.getClassDestructorName();

    std::cout << "\n The end of the file ..\n\n";

    delete [] MethodLine;

    delete [] Header_File;

    return 0;
}
