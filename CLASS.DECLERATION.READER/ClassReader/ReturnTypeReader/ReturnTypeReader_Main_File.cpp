
#include <iostream>
#include <cstring>
#include "ClassNameReader.h"
#include "MethodListReader.h"
#include "MethodReceiver.h"
#include "ReturnTypeReader.h"
#include "DirectoryOperations.h"
#include "NameReader.h"


void PrintReturnType(ReturnTypeReader * RtrObject);

int main(){

      ReturnTypeReader * RtrObject;

      MethodReceiver   * Receiver;

      NameReader * NrObject;

      DirectoryOperations DirectoryManager;

      // Reading class name

      ClassNameReader ClassName;

      const char * Header_File_Name = "Syncronizer_TestPointer.h";

      int Name_Size = strlen(Header_File_Name);

      char * ClassName_Pointer = new char [5*Name_Size];

      for(int i=0;i<Name_Size;i++){

          ClassName_Pointer[i] = Header_File_Name[i];
      }

      ClassName_Pointer[Name_Size] = '\0';

      ClassName.ReadClassName(ClassName_Pointer);

      MethodListReader Reader;

      // Method List Read process

      Reader.SetMethodListPath("Syncronizer_TestPointer_MFDL");

      Reader.SetMetaFilePath("Syncronizer_TestPointer_MFDL_MF");

      Reader.ReadMethodList();

      for(int i=0;i< Reader.GetPublicMethodNumber();i++){

          RtrObject = new ReturnTypeReader;

          Receiver  = new MethodReceiver;

          NrObject =  new NameReader;

          Receiver->SetClassName(ClassName.getClassName());

          Receiver->ReceiveMethodLine(Reader.GetPublicMethods()[i]);

          NrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

          NrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

          NrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

          NrObject->SetMethodLine(Reader.GetPublicMethods()[i]);

          NrObject->DetermineMethodName();

          RtrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

          RtrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

          RtrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

          RtrObject->SetMethodLine(Reader.GetPublicMethods()[i]);

          RtrObject->Receive_Method_Name(NrObject->GetMethodName());

          RtrObject->DetermineMethodReturnType();

          PrintReturnType(RtrObject);

          delete Receiver;

          delete RtrObject;

          delete NrObject;
      }

      for(int i=0;i<Reader.GetPrivateMethodNumber();i++){

          RtrObject = new ReturnTypeReader;

          Receiver  = new MethodReceiver;

          NrObject =  new NameReader;

          Receiver->SetClassName(ClassName.getClassName());

          Receiver->ReceiveMethodLine(Reader.GetPrivateMethods()[i]);

          NrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

          NrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

          NrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

          NrObject->SetMethodLine(Reader.GetPrivateMethods()[i]);

          NrObject->DetermineMethodName();

          RtrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

          RtrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

          RtrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

          RtrObject->SetMethodLine(Reader.GetPrivateMethods()[i]);

          RtrObject->Receive_Method_Name(NrObject->GetMethodName());

          RtrObject->DetermineMethodReturnType();

          PrintReturnType(RtrObject);

          delete Receiver;

          delete RtrObject;

          delete NrObject;
      }

      for(int i=0;i<Reader.GetProtectedMethodNumber();i++){

          RtrObject = new ReturnTypeReader;

          Receiver =  new MethodReceiver;

          NrObject =  new NameReader;

          Receiver->SetClassName(ClassName.getClassName());

          Receiver->ReceiveMethodLine(Reader.GetProtectedMethods()[i]);

          NrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

          NrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

          NrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

          NrObject->SetMethodLine(Reader.GetProtectedMethods()[i]);

          NrObject->DetermineMethodName();

          RtrObject->SetSyntaxErrorStatus(Receiver->getMethodSyntaxErrorStatus());

          RtrObject->SetClassConstructorStatus(Receiver->getClassConstructorStatus());

          RtrObject->SetClassDestructorStatus(Receiver->getClassDestructorStatus());

          RtrObject->SetMethodLine(Reader.GetProtectedMethods()[i]);

          RtrObject->Receive_Method_Name(NrObject->GetMethodName());

          RtrObject->DetermineMethodReturnType();

          PrintReturnType(RtrObject);

          delete Receiver;

          delete RtrObject;

          delete NrObject;
      }

      delete [] ClassName_Pointer;

      //ClassName.Clear_Dynamic_Memory();

      //Reader.Clear_Dynamic_Memory();

      return 0;
}

void PrintReturnType(ReturnTypeReader * RtrObject){

     if(RtrObject->GetMethodReturnType()[0] == '\0'){

         if(RtrObject->GetSyntaxErrorStatus()){

            std::cout << "\n There is Syntax Error..";
         }
         else{

            std::cout << "\n The method is Constructor or Destructor..";

            std::cout << "\n There is no return type";
         }
     }
     else{

         std::cout << "\n Method Return Type:" << RtrObject->GetMethodReturnType() << "#";
     }

     std::cout << "\n\n ";
}
