
#include <cstring>
#include "DataBaseBuilder.h"
#include "MethodReader.h"

int main(int argc, char** argv){

    MethodReader  Reader;

    DataBaseBuilder DB_Builder;

    char Include_Directory_PATH [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile";

    Reader.ReceiveIncludeDirectoryPATH(Include_Directory_PATH);

    char Construction_Point [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory";

    Reader.ReceiveDataBaseConstructionPoint(Construction_Point);

    char File_Name [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile/IntToCharTranslater.h";

    Reader.Receive_Header_File_Path(File_Name);

    Reader.ReadFunctionDeclerations();

    std::cout << "\n DataBase has been Constructed ..";

    std::cout << "\n Press enter ..!";

    std::cin.get();

    DB_Builder.Build_DataBase(&Reader);

    std::cout << "\n Class Name :"  << DB_Builder.Get_Class_Name();

    std::cout << "\n Public Method Number:" << DB_Builder.Get_Public_Method_Number();

    for(int i=0;i<DB_Builder.Get_Public_Method_Number();i++){

       std::cout << "\n\n METHOD ID NUMBER: " << DB_Builder.Get_Public_Method_Datas()[i].Method_ID_Number;

       std::cout << "\n";

       std::cout << "\n        Syntax_Error_Status: " <<  DB_Builder.Get_Public_Method_Datas()[i].Syntax_Error_Status;

       std::cout << "\n        Parameter_Number   : " <<  DB_Builder.Get_Public_Method_Datas()[i].Parameter_Number;

       std::cout << "\n        Method_Name        : " <<  DB_Builder.Get_Public_Method_Datas()[i].Method_Name;

       std::cout << "\n        Return_Type        : " <<  DB_Builder.Get_Public_Method_Datas()[i].Return_Type;

       std::cout << "\n        Acess_Type         : " <<  DB_Builder.Get_Public_Method_Datas()[i].Acess_Type;

       std::cout << "\n        Parameter_Types    : ";

       for(int k=0;k<DB_Builder.Get_Public_Method_Datas()[i].Parameter_Number;k++){

           std::cout << "\n                             " << DB_Builder.Get_Public_Method_Datas()[i].Parameter_Types[k];
       }

       std::cout << "\n        Parameter_Names    : ";

       for(int k=0;k<DB_Builder.Get_Public_Method_Datas()[i].Parameter_Number;k++){

           std::cout << "\n                             " << DB_Builder.Get_Public_Method_Datas()[i].Parameter_Names[k];
       }

       std::cout << "\n";
    }

    std::cout << "\n The end of the program..!\n\n";

    DB_Builder.Clear_Dynamic_Memory();

    Reader.Clear_Dynamic_Memory();

    return 0;
}
