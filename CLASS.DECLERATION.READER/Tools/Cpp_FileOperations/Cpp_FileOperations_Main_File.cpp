

 #include "Cpp_FileOperations.h"


 int main(int argc, char** argv){

     Cpp_FileOperations FileManager;

     int integer = 12345;

     std::string numbers = std::to_string(integer);

     std::cout << "\n numbers:" << numbers;

     char PATH [] = "Sample";

     FileManager.SetFilePath(PATH);

     FileManager.FileOpen(RWC);

     FileManager.WriteToFile(" Hello world ..!\n");

     FileManager.WriteToFile(" This is an example file operation ..!\n");

     FileManager.FileClose();

     FileManager.FileOpen(R);

     std::cout << "\n The File index :\n";

     while(!FileManager.Control_End_of_File()){

           std::cout  << FileManager.ReadLine();
     }

     FileManager.FileClose();

     FileManager.FileOpen(R);

     while(!FileManager.Control_End_of_File()){

           std::cout  << FileManager.Read();

           std::cout << " ";
     }

     FileManager.FileClose();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
