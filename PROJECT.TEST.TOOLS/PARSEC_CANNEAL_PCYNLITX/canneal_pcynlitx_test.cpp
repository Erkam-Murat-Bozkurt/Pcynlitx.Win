

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <sstream>
#include "Cpp_FileOperations.h"

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Determination_of_test_command(char ** test_command, char * exe_file, char * inputFile);

int main(int argc, char ** argv){

    if(argc != 4) {

      std::cout << "\n\n   Usage: " << argv[0] << " [Repitation] [Test program] [Input File]" << std::endl;

      std::cout << "\n\n";

      exit(1);
    }

    std::cout << "\n\n PARSEC CANNEAL PCYNLITX TEST";

    std::cout << "\n";

    int sum = 0;

    std::string test_repitation = "";

    Convert_char_to_std_string(&test_repitation,argv[1]);

    std::stringstream s(test_repitation);

    int repitation = 0;

    s >> repitation;


    std::cout << "\n The number of repitation:" << repitation;

    std::cout << "\n";

    char * test_command = nullptr;

    Determination_of_test_command(&test_command,argv[2],argv[3]);

    std::cout << "\n The test command:" << test_command;

    std::cout << "\n\n Press Enter ..";

    std::cin.get();

    Cpp_FileOperations FileManager;

    FileManager.SetFilePath("Test_Record_File");

    FileManager.FileOpen(RWCf);

    FileManager.FileClose();

    for(int i=0;i<repitation;i++){

       system(test_command);

       std::cout << "\n #\e[1;33m The test [" << i << "] has been complated ..\e[0m\n\n";

       system("echo \"\n\" >> Test_Record_File");
    }

    FileManager.SetFilePath("Test_Record_File");

    FileManager.FileOpen(Rf);

    std::string test_result = "";

    int tr_counter = 0;

    while(!FileManager.Control_End_of_File()){

          test_result = FileManager.ReadLine();

          if(test_result[0] != '\n'){

             std::stringstream s(test_result);

             int test_output = 0;

             s >> test_output;

             sum = sum + test_output;

             if(test_output != 0){

                std::cout << "\n The test output[" << tr_counter

                << "] " << test_output;

                tr_counter++;
             }
          }
    }

    FileManager.FileClose();

    std::cout << "\n\n -------------------------------------";

    std::cout << "\n the average:" << ((double)sum)/repitation << std::endl;

    std::cout << "\n\n";

    delete [] test_command;

    return 0;
}

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer){

    int string_length = strlen(cstring_pointer);

    for(int i=0;i<string_length;i++){

        *string_line = *string_line + cstring_pointer[i];
    }
}

void Determination_of_test_command(char ** test_command, char * exe_file, char * inputFile){

     char space = ' ';

     char directory_operator []= "./";

     int exe_file_character_size = strlen(exe_file);

     int inputFile_character_size = strlen(inputFile);

     int Directory_Operator_Size = strlen(directory_operator);

     int command_size = exe_file_character_size + inputFile_character_size;

     *test_command = new char [5*command_size];

     int index_number = 0;

     for(int i=0;i<Directory_Operator_Size;i++){

         (*test_command)[index_number] = directory_operator[i];

         index_number++;
     }

     for(int i=0;i<exe_file_character_size;i++)
     {
         (*test_command)[index_number] = exe_file[i];

         index_number++;
     }

     (*test_command)[index_number] = space;

     index_number++;

     for(int i=0;i<inputFile_character_size;i++){

        (*test_command)[index_number] = inputFile[i];

        index_number++;
     }

     (*test_command)[index_number] = '\0';
}
