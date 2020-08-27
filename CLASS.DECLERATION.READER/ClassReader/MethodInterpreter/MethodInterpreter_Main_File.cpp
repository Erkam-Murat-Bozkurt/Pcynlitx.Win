
#include <iostream>
#include <cstring>
#include "DirectoryOperations.h"
#include "MethodListReader.h"
#include "MethodInterpreter.h"
#include "MethodReader.h"


void PrintMethod(MethodInterpreter * MhObject);

int main(){

    MethodReader Reader;

    MethodListReader ListReader;

    MethodInterpreter Interpreter;

    char Header_File_Name [] = "CFileOperations.h";

    char Class_Name [] = "CFileOperations";

    char Include_Directory_Path [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile";

    char Construction_Point [] = "/home/erkam/META.PROGRAMMING.PROJECT/CLASS.DECLERATION.READER/ClassReader/MethodInterpreter";

    Reader.ReceiveIncludeDirectoryPATH(Include_Directory_Path);

    Reader.ReceiveDataBaseConstructionPoint(Construction_Point);

    Reader.Receive_Header_File_Name(Header_File_Name);

    Reader.ReadFunctionDeclerations();

    char PublicAccesType[] = {'p','u','b','l','i','c','\0'};

    char PrivateAccesType[] = {'p','r','i','v','a','t','e','\0'};

    char ProtectedAcessType[] = {'p','r','o','t','e','c','t','e','d','\0'};

    ListReader.SetMethodListPath("CFileOperations_MFDL");

    ListReader.SetMetaFilePath("CFileOperations_MFDL_MF");

    ListReader.ReadMethodList();

    int TotalMethodNumber = ListReader.GetTotalMethodNumber();

    int counter = 0;

    for(int i=0;i<ListReader.GetPublicMethodNumber();i++){

        Interpreter.SetClassName(Class_Name);

        Interpreter.ReceiveMethodLine(ListReader.GetPublicMethods()[i]);

        Interpreter.setMethodIDNumber(counter);

        Interpreter.setMethodAccessType(PublicAccesType);

        Interpreter.ReadMethod();

        PrintMethod(&Interpreter);

        Interpreter.Clear_Dynamic_Memory();

        counter++;
    }

    for(int i=0;i<ListReader.GetPrivateMethodNumber();i++){

        Interpreter.SetClassName(Class_Name);

        Interpreter.ReceiveMethodLine(ListReader.GetPrivateMethods()[i]);

        Interpreter.setMethodIDNumber(counter);

        Interpreter.setMethodAccessType(PrivateAccesType);

        Interpreter.ReadMethod();

        PrintMethod(&Interpreter);

        Interpreter.Clear_Dynamic_Memory();

        counter++;
    }

    for(int i=0;i<ListReader.GetProtectedMethodNumber();i++){

        Interpreter.SetClassName(Class_Name);

        Interpreter.ReceiveMethodLine(ListReader.GetProtectedMethods()[i]);

        Interpreter.setMethodIDNumber(counter);

        Interpreter.setMethodAccessType(ProtectedAcessType);

        Interpreter.ReadMethod();

        PrintMethod(&Interpreter);

        Interpreter.Clear_Dynamic_Memory();

        counter++;
    }

    ListReader.Clear_Dynamic_Memory();

    Reader.Clear_Dynamic_Memory();

    std::cout << "\n The end of the program ..\n\n";

    return 0;
}

void PrintMethod(MethodInterpreter * MhObject){

     if(MhObject->getMethodSyntaxErrorStatus()){

        std::cout << "\n\n ";
        std::cout << "\n RN:" << MhObject->GetClassName() << "-M" << MhObject->getMethodIDNumber() << "-START";
        std::cout << "\n";

        std::cout << "\n    [SYNTAX ERROR]";

        std::cout << "\n\n M" << MhObject->getMethodIDNumber() << "-END";
        std::cout << "\n";
     }
     else{
            std::cout << "\n\n ";
            std::cout << "\n RN:" << MhObject->GetClassName() << "-M" << MhObject->getMethodIDNumber() << "-START";
            std::cout << "\n";

            std::cout << "\n Method Error Status     : false";

            std::cout << "\n Method Name             : " << MhObject->getMethodName();

            std::cout << "\n Method Return Type      : ";

            if(MhObject->getMethodReturnType()[0] == '\0'){

                  std::cout << "There is no return type..";
            }
            else{

                  std::cout << MhObject->getMethodReturnType();
            }

            std::cout << "\n Method Parameter Number : " << MhObject->getMethodParameterNumber();
            std::cout << "\n Method ID Number        : " << MhObject->getMethodIDNumber();
            std::cout << "\n Method Acess Type       : " << MhObject->getMethodAccessType();

            std::cout << "\n Method Parameter Types    ";

            if(MhObject->getMethodParameterNumber() == 0){

               if(MhObject->getMethodParameterTypes()[0][0] == '\0'){

                   std::cout << "There is no parameter types.";
               }
            }

            for(int i=0;i<MhObject->getMethodParameterNumber();i++){

                  std::cout << "\n                         : ";
                  std::cout <<  MhObject->getMethodParameterTypes()[i];
            }

            std::cout << "\n Method Parameter Names    ";

            if(MhObject->getMethodParameterNumber() == 0){

                 if((MhObject->getMethodParameterNames())[0][0] == '\0'){

                      std::cout << "There is no parameter names.";
                 }
            }

            for(int i=0;i<MhObject->getMethodParameterNumber();i++){

                  std::cout << "\n                         : ";

                  if(MhObject->getMethodParameterNames()[i][0] == '\0'){

                       std::cout << "There is no parameter names.";
                  }
                  else{

                       std::cout << MhObject->getMethodParameterNames()[i];
                  }

            }

            std::cout << "\n\n M" << MhObject->getMethodIDNumber() << "-END";

            std::cout << "\n";
      }
}
