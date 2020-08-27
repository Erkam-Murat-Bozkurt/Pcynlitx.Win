
 #include <iostream>
 #include "MemberFunctionReader.h"
 #include "MetaDataTranslater.h"


 int main(int argc, char** argv){

     MemberFunctionReader FunctionReader;

     FunctionReader.Receive_Include_Directory_PATH("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile");

     FunctionReader.Receive_Base_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     FunctionReader.Receive_Header_File_Name("CFileOperations.h");

     FunctionReader.Read_Member_Functions();

     int PublicMethodNumber = FunctionReader.Get_Public_Method_Number();

     int PrivateMethodNumber = FunctionReader.Get_Private_Method_Number();

     int ProtectedMethodNumber = FunctionReader.Get_Protected_Method_Number();

     std::cout << "\n Public Method Number:" << PublicMethodNumber;

     std::cout << "\n Private Method Number:" << PrivateMethodNumber;

     std::cout << "\n Protected Method Number:" << ProtectedMethodNumber;

     std::cout << "\n";

     char ObjectName [] = {'S','a','m','p','l','e','\0'};

     MetaDataTranslater DataTranslater;

     DataTranslater.ReceiveClassName(FunctionReader.Get_Class_Name());

     DataTranslater.ReceiveObjectName(ObjectName);

     for(int i=0;i<PublicMethodNumber;i++){

         std::cout << "\n\n";

         DataTranslater.ReceiveMethodInformations(&(FunctionReader.GetPublicMethods()[i]));

         DataTranslater.Collect_Informations();

         std::cout << "\n\n Method Line :" << DataTranslater.GetFunctionImplementationCodeLine();

         std::cout << "\n\n In class FunctionCall:" << DataTranslater.GetInClassFunctionCallLine();

         std::cout << "\n\n FunctionCall:" << DataTranslater.Get_Function_Call_Line();
     }

     for(int i=0;i<PrivateMethodNumber;i++){

         std::cout << "\n\n";

         DataTranslater.ReceiveMethodInformations(&(FunctionReader.GetPrivateMethods()[i]));

         DataTranslater.Collect_Informations();

         std::cout << "\n\n Method Line :" << DataTranslater.GetFunctionImplementationCodeLine();

         std::cout << "\n\n In class  FunctionCall:" << DataTranslater.GetInClassFunctionCallLine();

         std::cout << "\n\n FunctionCall:" << DataTranslater.Get_Function_Call_Line();
     }

     for(int i=0;i<ProtectedMethodNumber;i++){

         std::cout << "\n\n";

         DataTranslater.ReceiveMethodInformations(&(FunctionReader.GetProtectedMethods()[i]));

         DataTranslater.Collect_Informations();

         std::cout << "\n\n Method Line :" << DataTranslater.GetFunctionImplementationCodeLine();

         std::cout << "\n\n In class FunctionCall:" << DataTranslater.GetInClassFunctionCallLine();

         std::cout << "\n\n FunctionCall:" << DataTranslater.Get_Function_Call_Line();
     }

     FunctionReader.Clear_Dynamic_Memory();

     DataTranslater.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
