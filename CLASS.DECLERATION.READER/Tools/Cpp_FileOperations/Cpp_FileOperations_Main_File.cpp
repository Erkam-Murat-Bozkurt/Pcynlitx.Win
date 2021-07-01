

 #include "Cpp_FileOperations.h"


 int main(int argc, char** argv){

     Cpp_FileOperations FileManager;

     char PATH [] = "Sample.txt";

     FileManager.SetFilePath(PATH);

     FileManager.FileOpen(RWCf);

     FileManager.FileClose();

    if( FileManager.Is_This_File_Empty(PATH)){

       std::cout << "\n\n The file is empty..";
    }
    else{

        std::cout << "\n The file is not empty..";
    }

    std::cin.get();

    FileManager.SetFilePath(PATH);

    FileManager.FileOpen(Wf);

    FileManager.WriteToFile(" Hello world ..!\n");

    FileManager.WriteToFile(" This is an example file operation ..!\n");

    FileManager.FileClose();

    if( FileManager.Is_This_File_Empty(PATH)){

         std::cout << "\n\n The file is empty..";
    }
    else{

         std::cout << "\n The file is not empty..";

       }


     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
