

 #include "Cpp_FileOperations.h"


 int main(int argc, char** argv){

     Cpp_FileOperations FileManager;

     int integer = 12345;

     std::string numbers = std::to_string(integer);

     std::cout << "\n numbers:" << numbers;

     char PATH [] = "Sample.txt";

     char TARGET_PATH [] = "Target.txt";

     FileManager.SetFilePath(PATH);

     std::cout << "\n File Path:" << FileManager.GetFilePath();

     std::cin.get();

     FileManager.FileOpen(RWCf);

     FileManager.WriteToFile(" Hello world ..!\n");

     FileManager.WriteToFile(" This is an example file operation ..!\n");

     FileManager.FileClose();

     FileManager.CpFile(PATH,TARGET_PATH);

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
