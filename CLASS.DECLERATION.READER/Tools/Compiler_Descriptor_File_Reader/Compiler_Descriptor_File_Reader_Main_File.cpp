
#include <iostream>
#include "Compiler_Descriptor_File_Reader.h"

int main(int argc, char** argv){

    Compiler_Descriptor_File_Reader Descriptor_File_Reader;

    Descriptor_File_Reader.Receive_Descriptor_File_Directory(argv[1]);

    Descriptor_File_Reader.Receive_Descriptor_File_Name(argv[2]);

    Descriptor_File_Reader.Receive_Descriptor_File_Infomations();

    std::cout << "\n\n \e[1;3;37;42m INCLUDE DIRECTORY LIST: \e[0m \n";

    for(int i=0;i< Descriptor_File_Reader.Include_Directory_Number;i++){

        std::cout << "\n " << Descriptor_File_Reader.Include_Directory_List[i] << "#";
    }

    std::cout << "\n\n \e[1;3;37;42m LIBRARY DIRECTORY LIST: \e[0m \n";

    for(int i=0;i<Descriptor_File_Reader.Library_Directory_Number;i++){

        std::cout << "\n " << Descriptor_File_Reader.Library_Directory_List[i] << "#";
    }

    std::cout << "\n\n \e[1;3;37;42m SOURCE FILE DIRECTORY LIST \e[0m \n";

    for(int i=0;i<Descriptor_File_Reader.Source_File_Directory_Number;i++){

        std::cout << "\n " << Descriptor_File_Reader.Source_File_Directory_List[i] << "#";
    }

    std::cout << "\n\n \e[1;3;37;42m SOURCE FILE NAMES LIST: \e[0m \n";

    for(int i=0;i<Descriptor_File_Reader.Source_File_Names_Number;i++){

        std::cout << "\n " << Descriptor_File_Reader.Source_File_Name_List[i] << "#";
    }

    std::cout << "\n\n \e[1;3;37;42m HEADER FILE NAMES LIST \e[0m \n";

    for(int i=0;i<Descriptor_File_Reader.Header_File_Names_Number;i++){

        std::cout << "\n " << Descriptor_File_Reader.Header_File_Name_List[i] << "#";
    }

    std::cout << "\n\n \e[1;3;37;42m LIBRARY NAMES LIST: \e[0m \n";

    for(int i=0;i<Descriptor_File_Reader.Library_Names_Number;i++){

        std::cout << "\n " << Descriptor_File_Reader.Library_Name_List[i] << "#";
    }

    std::cout << "\n\n \e[1;3;37;42m OPTION LIST: \e[0m \n";

    for(int i=0;i<Descriptor_File_Reader.Option_Number;i++){

        std::cout << "\n " << Descriptor_File_Reader.Option_List[i] << "#";
    }

    std::cout << "\n\n \e[1;3;37;42m MAIN FILE NAME: \e[0m \n";

    if(Descriptor_File_Reader.Is_There_Main_File_Decleration){

       std::cout << "\n " << Descriptor_File_Reader.Main_File_Name << "#";
    }
    else{

       std::cout << "\n There is no main file decleraton ..";
    }

    std::cout << "\n \e[1;3;37;42m EXECUTABLE FILE NAME: \e[0m \n";

    if(Descriptor_File_Reader.Executable_File_Name != nullptr){

       std::cout << "\n " << Descriptor_File_Reader.Executable_File_Name << "#";
    }
    else{

         std::cout << "\n There is no executable file name decleraton ..";
    }

    Descriptor_File_Reader.Clear_Dynamic_Memory();

    std::cout << "\n\n \e[3m # THE END OF THE PROGRAM # \e[0m \n\n";

    return 0;
}
