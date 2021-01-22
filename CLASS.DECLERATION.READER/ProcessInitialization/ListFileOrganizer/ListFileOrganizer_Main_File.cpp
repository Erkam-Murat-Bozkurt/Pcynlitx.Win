
 #include "ListFileOrganizer.h"

 int main(int argc, char** argv){

     // TEST OPERATIONS

     ListFileOrganizer FileOrganizer;

     char IncludeDirectoryPATH [] = "D:\\TestHeaderFile";

     FileOrganizer.ReceiveIncludeDirectoryPATH(IncludeDirectoryPATH);

     char DataBaseConstructionPoint [] = "D:\\TestDirectory";

     FileOrganizer.ReceiveDataBaseConstructionPoint(DataBaseConstructionPoint);

     char HeaderFileName [] = "D:\\TestHeaderFile\\IntToCharTranslater.h";

     FileOrganizer.Set_Target_Header_File_Path(HeaderFileName);

     FileOrganizer.CollectInformations();


     // PRINTING OPERATIONS

     std::cout << "\n IncludeDirectoryPATH:"

               << FileOrganizer.GetIncludeDirectoryPATH();

     std::cout << "\n RecordFilePath      :"

               << FileOrganizer.GetRecordFilePath();

     std::cout << "\n MetaDataFilePath    :"

               << FileOrganizer.GetMetaDataFilePath();

     std::cout << "\n HeaderFilePath      :"

               << FileOrganizer.GetHeaderFilePath();

     std::cout << "\n DataBase Construction Point:"

               << FileOrganizer.GetDataBaseConstructionPoint();

     std::cout <<  "\n\n The end of the program ..\n\n";

     return 0;
 };
