
 #include "ListFileOrganizer.h"

 int main(int argc, char** argv){

     ListFileOrganizer FileOrganizer;

     char IncludeDirectoryPATH [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile";

     FileOrganizer.ReceiveIncludeDirectoryPATH(IncludeDirectoryPATH);

     char DataBaseConstructionPoint [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory";

     FileOrganizer.ReceiveDataBaseConstructionPoint(DataBaseConstructionPoint);

     char HeaderFileName [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile/IntToCharTranslater.h";

     FileOrganizer.Set_Target_Header_File_Path(HeaderFileName);

     FileOrganizer.CollectInformations();

     std::cout << "\n IncludeDirectoryPATH:" << FileOrganizer.GetIncludeDirectoryPATH();

     std::cout << "\n RecordFilePath      :" << FileOrganizer.GetRecordFilePath();

     std::cout << "\n MetaDataFilePath    :" << FileOrganizer.GetMetaDataFilePath();

     std::cout << "\n HeaderFilePath      :" << FileOrganizer.GetHeaderFilePath();

     std::cout << "\n DataBase Construction Point:" << FileOrganizer.GetDataBaseConstructionPoint();

     std::cout <<  "\n\n The end of the program ..\n\n";

     return 0;
 };
