
#include "ClassNameReader.h"
#include "MethodListReader.h"
#include "MethodReceiver.h"
#include "ParameterReader.h"
#include "DirectoryOperations.h"
#include <iostream>
#include <cstring>

void PrintMethodParameters(ParameterReader * NrObject);

int main(){

    MethodReceiver Receiver;

    ParameterReader  PrObject;

    MethodListReader Reader;

    DirectoryOperations DirectoryManager;

    char Header_File_Name [] = "CFileOperations.h";

    char Class_Name [] = "CFileOperations";

    Reader.SetMethodListPath("CFileOperations_MFDL");

    Reader.SetMetaFilePath("CFileOperations_MFDL_MF");

    Reader.ReadMethodList();

    for(int i=0;i< Reader.GetPublicMethodNumber();i++){

        Receiver.SetClassName(Class_Name);

        Receiver.ReceiveMethodLine(Reader.GetPublicMethods()[i]);

        PrObject.SetSyntaxErrorStatus(Receiver.getMethodSyntaxErrorStatus());

        PrObject.SetMethodParameterNumber(Receiver.getMethodParameterNumber());

        PrObject.SetMethodParenthes(Receiver.getMethodParenthes());

        PrObject.Read_Parameter_Informations();

        PrintMethodParameters(&PrObject);

        Receiver.Clear_Dynamic_Memory();

        PrObject.Clear_Dynamic_Memory();
    }

    for(int i=0;i<Reader.GetPrivateMethodNumber();i++){

        Receiver.SetClassName(Class_Name);

        Receiver.ReceiveMethodLine(Reader.GetPrivateMethods()[i]);

        PrObject.SetSyntaxErrorStatus(Receiver.getMethodSyntaxErrorStatus());

        PrObject.SetMethodParameterNumber(Receiver.getMethodParameterNumber());

        PrObject.SetMethodParenthes(Receiver.getMethodParenthes());

        PrObject.Read_Parameter_Informations();

        PrintMethodParameters(&PrObject);

        Receiver.Clear_Dynamic_Memory();

        PrObject.Clear_Dynamic_Memory();
    }

    for(int i=0;i<Reader.GetProtectedMethodNumber();i++){

        Receiver.SetClassName(Class_Name);

        Receiver.ReceiveMethodLine(Reader.GetProtectedMethods()[i]);

        PrObject.SetSyntaxErrorStatus(Receiver.getMethodSyntaxErrorStatus());

        PrObject.SetMethodParameterNumber(Receiver.getMethodParameterNumber());

        PrObject.SetMethodParenthes(Receiver.getMethodParenthes());

        PrObject.Read_Parameter_Informations();

        PrintMethodParameters(&PrObject);

        Receiver.Clear_Dynamic_Memory();

        PrObject.Clear_Dynamic_Memory();
   }

   std::cout << "\n\n The end of the program .. \n\n";

   return 0;
}

void PrintMethodParameters(ParameterReader * PrObject){

     std::cout << "\n\n Method Parameter Types        :";

     if(PrObject->GetSyntaxErrorStatus()){

        std::cout << "There is a syntax error ..";
     }
     else{

            if(PrObject->getMethodParameterNumber() == 0){

               std::cout << "\n\n       There is no parameter \n\n";
            }

            for(int i=0; i< PrObject->getMethodParameterNumber();i++){

                std::cout << PrObject->GetMethodParameterTypes()[i];

                if(i<PrObject->getMethodParameterNumber() -1 ){

                   std::cout << ", ";
                }
            }
     }

     std::cout << "\n MethodParameterNames          :";

     if(PrObject->GetSyntaxErrorStatus()){

        std::cout << "There is a syntax error ..";
     }
     else{

            if(PrObject->getMethodParameterNumber() == 0){

               std::cout << "\n\n       There is no parameter \n\n";
            }

            for(int i= 0; i< PrObject->getMethodParameterNumber();i++){

                std::cout << PrObject->GetMethodParameterNames()[i];

                if(i<PrObject->getMethodParameterNumber() -1 ){

                      std::cout << ", ";
                }
            }
     }
}
