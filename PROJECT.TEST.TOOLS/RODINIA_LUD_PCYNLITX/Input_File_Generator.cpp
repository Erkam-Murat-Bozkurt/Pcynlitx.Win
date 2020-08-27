


#include <iostream>
#include <random>
#include <sstream>
#include <cstring>
#include <string>
#include <Cpp_FileOperations.h>


void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

int Elapsed_Time = 0;

double lower_bound = 0;

double upper_bound = 2;

std::uniform_real_distribution<double> unif(lower_bound,upper_bound);

std::default_random_engine re;


double ** data_matrix = nullptr;

int main(int argc, char** argv){

    if(argc != 2) {

       std::cout << "\n\n   Usage: " << argv[0] << " [Matrix Size]" << std::endl;

       std::cout << "\n\n";

       exit(1);
    }

    std::string Dimention = "";

    Convert_char_to_std_string(&Dimention,argv[1]);

    std::stringstream sd(Dimention);

    int matrix_size = 0;

    sd >> matrix_size;

    std::cout << "\n";

    std::cout << "\n\n RODINIA LUD DATA FILE GENERATOR";

    std::cout << "\n";

    std::cout << "\n\n The data matrix size must be 64 256 512 1024 2048";

    std::cout << "\n\n Current data matrix size:" << matrix_size;

    std::cout << "\n\n Please check the data size entered and press enter;";

    std::cout << "\n\n Do you want to continue: Y/N :";

    char preference = ' ';

    std::cin.get(preference);

    if(preference == 'Y'){

       Cpp_FileOperations FileManager;

       FileManager.SetFilePath("Lud_Input");

       FileManager.FileOpen(RWCf);

       FileManager.WriteToFile(Dimention);

       for(int i=0;i<matrix_size;i++){

           FileManager.WriteToFile("\n");

           for(int k=0;k<matrix_size;k++){

               FileManager.WriteToFile(std::to_string(unif(re)));

               FileManager.WriteToFile(" ");
           }
       }

       FileManager.FileClose();
    }

    std::cout << "\n The end of the program .." << std::endl;

    std::cout << "\n";

    return 0;
}

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer){

    int string_length = strlen(cstring_pointer);

    for(int i=0;i<string_length;i++){

        *string_line = *string_line + cstring_pointer[i];
    }
}
