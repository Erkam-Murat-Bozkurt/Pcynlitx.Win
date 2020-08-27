

#include <iostream>
#include "MethodReader.h"

int main(int argc, char** argv){

    MethodReader Reader;

    Reader.ReceiveIncludeDirectoryPATH(argv[1]);

    Reader.ReceiveDataBaseConstructionPoint(argv[2]);

    Reader.Receive_Header_File_Path(argv[3]);

    Reader.ReadFunctionDeclerations();

    std::cout << "\n\n PUBLIC METHODS:";

    if(Reader.GetPublicMethodNumber() != 0){

       for(int i=0;i< Reader.GetPublicMethodNumber();i++){

           std::cout << "\n\n     " << Reader.GetPublicMethods()[i];
       }
    }
    else{

         std::cout << "\n\n     There is no public method";
    }

    std::cout << "\n\n\n PRIVATE METHODS:";

    if(Reader.GetPrivateMethodNumber() != 0){

       for(int i=0;i<Reader.GetPrivateMethodNumber();i++){

           std::cout << "\n\n     " << Reader.GetPrivateMethods()[i];
       }
    }
    else{

        std::cout << "\n\n     There is no private method..";
    }

    std::cout << "\n\n\n PROTECTED METHODS:";

    if(Reader.GetProtectedMethodNumber() != 0){

       for(int i=0;i<Reader.GetProtectedMethodNumber();i++){

           std::cout << "\n\n     " << Reader.GetProtectedMethods()[i];
       }
    }
    else{

        std::cout << "\n\n     There is no protected method..";
    }

    std::cout << "\n\n\n RECORD FILE INFORMATIONS:";

    std::cout << "\n\n     Class Name                 :" << Reader.GetClassName();

    std::cout << "\n\n     Method List File Name      :" << Reader.GetRecordFilePath();

    std::cout << "\n\n     Method List Meta File Path :" << Reader.GetMetaDataFilePath();

    std::cout << "\n\n     Data Record Directory      :" << Reader.GetDataRecordDirectory();

    Reader.Clear_Dynamic_Memory();

    std::cout << "\n\n\n The end of the program ..\n\n";

    return 0;
}
