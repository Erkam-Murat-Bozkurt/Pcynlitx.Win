
#include <iostream>
#include <cstring>
#include "ClassNameReader.h"
#include "MethodReceiver.h"
#include "ReturnTypeReader.h"
#include "MethodListReader.h"
#include "NameReader.h"
#include "DirectoryOperations.h"
#include "MethodReader.h"


void PrintMethodName(NameReader * NrObject);

int main(int argc, char ** argv){

    DirectoryOperations DirectoryManager;

    MethodListReader Reader; // This class reads method lists which constructed by MethodReader type object From ProcessInitialization segment

    MethodReceiver * Receiver;

    NameReader * NrObject;

    char Header_File_Name [] = "CFileOperations.h";

    char Class_Name [] = "CFileOperations";

    char Include_Directory_Path [] = "/home/erkam/META.PROGRAMMING.PROJECT/CLASS.DECLERATION.READER/ClassReader";

    char Construction_Point [] = "/home/erkam/META.PROGRAMMING.PROJECT/CLASS.DECLERATION.READER/ClassReader/NameReader";

    MethodReader Class_Method_Reader;

    Class_Method_Reader.ReceiveIncludeDirectoryPATH(Include_Directory_Path);

    Class_Method_Reader.ReceiveDataBaseConstructionPoint(Construction_Point);

    Class_Method_Reader.Receive_Header_File_Name(Header_File_Name);

    Class_Method_Reader.ReadFunctionDeclerations();

    // Method List Read process

    DirectoryManager.ChangeDirectory(Construction_Point);

    Reader.SetMethodListPath("CFileOperations_MFDL");

    Reader.SetMetaFilePath("CFileOperations_MFDL_MF");

    Reader.ReadMethodList();

    for(int i=0;i< Reader.GetPublicMethodNumber();i++){

        Receiver  = new MethodReceiver;

        NrObject =  new NameReader;

        Receiver->SetClassName(Class_Name);

        Receiver->ReceiveMethodLine(Reader.GetPublicMethods()[i]);

        NrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

        NrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

        NrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

        NrObject->SetMethodLine(Reader.GetPublicMethods()[i]);

        NrObject->DetermineMethodName();

        PrintMethodName(NrObject);

        delete Receiver;

        delete NrObject;
    }

    for(int i=0;i<Reader.GetPrivateMethodNumber();i++){

        Receiver  = new MethodReceiver;

        NrObject  = new NameReader;

        Receiver->SetClassName(Class_Name);

        Receiver->ReceiveMethodLine(Reader.GetPrivateMethods()[i]);

        NrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

        NrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

        NrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

        NrObject->SetMethodLine(Reader.GetPrivateMethods()[i]);

        NrObject->DetermineMethodName();

        PrintMethodName(NrObject);

        delete Receiver;

        delete NrObject;
    }

    for(int i=0;i<Reader.GetProtectedMethodNumber();i++){

        Receiver = new MethodReceiver;

        NrObject = new NameReader;

        Receiver->SetClassName(Class_Name);

        Receiver->ReceiveMethodLine(Reader.GetProtectedMethods()[i]);

        NrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

        NrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

        NrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

        NrObject->SetMethodLine(Reader.GetProtectedMethods()[i]);

        NrObject->DetermineMethodName();

        PrintMethodName(NrObject);

        delete Receiver;

        delete NrObject;
    }

    return 0;
}

void PrintMethodName(NameReader * NrObject){

     std::cout << "\n  Method Name :" << NrObject->GetMethodName();

     std::cout << "\n\n ";
}
