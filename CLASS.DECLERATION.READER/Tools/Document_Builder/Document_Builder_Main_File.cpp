


#include <iostream>
#include "Document_Builder.h"

int main(int argc, char** argv){

    char Document_Name [] = "D:\\PCYNLITX.PROJECT.WINDOWS\\Pcyn.Win.SCode.txt";

    if(argv[1] == NULL){

       std::cout << "\n";
       std::cout << "\n The file name can not be received ..";
       std::cout << "\n";
       std::cout << "\n Please enter the file name!\n\n";
       std::cout << "\n";

       return 0;
    }
    else{

         Document_Builder Builder;

         Builder.Receive_Document_Name(Document_Name);

         Builder.Receive_File_Path(argv[1]);

         Builder.Add_File_To_Document();
    }

    return 0;
}
