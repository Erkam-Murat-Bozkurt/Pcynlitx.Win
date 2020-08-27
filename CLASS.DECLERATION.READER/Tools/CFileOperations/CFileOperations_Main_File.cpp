
#include "CFileOperations.h"
#include <cstring>
#include <iostream>

int main(int arc, char ** argv){

    CFileOperations FileManager;

    char File_Path [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile/IntToCharTranslater.h";

    FileManager.SetFilePath(File_Path);

    FileManager.FileOpen(R);

    char Buffer[200];

    std::cout << "\n Enter a character line:";

    std::cin.getline(Buffer,200);

    char  * pointer = Buffer;

    FileManager.WriteToFile(pointer);

    FileManager.FileClose();

    FileManager.FileOpen(R);

    std::cout << "\n\n The file index:";

    FileManager.PrintFileToConsole();

    FileManager.FileClose();

    char Target_Location [] = "/home/erkam/";

    char Base_Location [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile/";

    FileManager.Copy_File(Target_Location,Base_Location);

    std::cout << "\n\n Test file copied to the target location and the both of the files will be removed. \n\n";

    std::cout << "\n\n Press Enter ..";

    std::cin.get();

    std::cin.get();

    FileManager.DeleteFile(Target_Location);

    FileManager.Clear_Dynamic_Memory();

    std::cout << "\n\n The end of the program ..\n\n";

    return 0;
}
