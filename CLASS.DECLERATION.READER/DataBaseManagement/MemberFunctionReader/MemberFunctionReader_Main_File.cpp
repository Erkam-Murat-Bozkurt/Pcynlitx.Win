;
 #include "MemberFunctionReader.h"


 void Print_Method_Datas(Method_Datas * Data_List, const char * Acess_Type, int Record_Number);

 int main(int argc, char** argv){

     MemberFunctionReader FunctionReader;

     FunctionReader.Receive_Include_Directory_PATH(argv[2]);

     FunctionReader.Receive_Construction_Point(argv[1]);

     FunctionReader.Receive_Header_File_Path(argv[3]);

     FunctionReader.Read_Member_Functions();

     if(FunctionReader.Get_Public_Method_Number() > 0){

         Print_Method_Datas(FunctionReader.GetPublicMethods(),"PUBLIC METHODS",FunctionReader.Get_Public_Method_Number());
     }

     if(FunctionReader.Get_Private_Method_Number() > 0){

        Print_Method_Datas(FunctionReader.GetPrivateMethods(),"PRIVATE METHODS",FunctionReader.Get_Private_Method_Number());
     }


     if(FunctionReader.Get_Protected_Method_Number() > 0){

        Print_Method_Datas(FunctionReader.GetProtectedMethods(),"PROTECTED METHODS",FunctionReader.Get_Protected_Method_Number());
     }


     std::cout << "\n The class name:" << FunctionReader.Get_Class_Name();

     FunctionReader.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };

 void Print_Method_Datas(Method_Datas * Data_List, const char * Acess_Type, int Record_Number){

      std::cout << "\n\n ";

      std::cout << Acess_Type;

      std::cout << "\n";

      for(int i=0;i<Record_Number;i++){

          std::cout << "\n\n METHOD ID NUMBER: " << Data_List[i].Method_ID_Number;

          std::cout << "\n";

          std::cout << "\n        Syntax_Error_Status: " <<  Data_List[i].Syntax_Error_Status;

          std::cout << "\n        Parameter_Number   : " <<  Data_List[i].Parameter_Number;

          std::cout << "\n        Method_Name        : " <<  Data_List[i].Method_Name;

          std::cout << "\n        Return_Type        : " <<  Data_List[i].Return_Type;

          std::cout << "\n        Acess_Type         : " <<  Data_List[i].Acess_Type;

          std::cout << "\n        Parameter_Types    : ";

          for(int k=0;k< Data_List[i].Parameter_Number;k++){

              std::cout << "\n                             " << Data_List[i].Parameter_Types[k];
          }

          std::cout << "\n        Parameter_Names    : ";

          for(int k=0;k< Data_List[i].Parameter_Number;k++){

              std::cout << "\n                             " << Data_List[i].Parameter_Names[k];
          }

          std::cout << "\n";
      }
 }
