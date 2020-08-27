
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <string>
#include <sstream>
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"

void Determine_Test_Command(char ** test_command, char * test_binary, char * input_file, char * workload);

int main(int argc, char ** argv){

    if(argc < 5){

       std::cout << "\n\n usage: " << argv[0] << " <test reputation> <test command> <input file> <workload: data size>";

       std::cout << "\n\n";

       exit(0);
    }

    std::cout << "\n\n THE NUMBER COUNTER TEST FOR PCYNLITX";

    std::cout << "\n";


    IntToCharTranslater Translater;

    int repitation = Translater.TranslateFromCharToInt(argv[1]);

    std::cout << "\n The repitation of the test:" << repitation;

    std::cout << "\n\n";


    char * test_command = nullptr;

    Determine_Test_Command(&test_command,argv[2],argv[3],argv[4]);

    std::cout << "\n The test command:" << test_command << std::endl;

    std::cout << "\n\n Press Enter..";

    std::cin.get();

    Cpp_FileOperations FileManager;

    FileManager.SetFilePath("Test_Record_File");

    FileManager.FileOpen(RWCf);

    FileManager.FileClose();


    int succeeded_test = 0;

    for(int i=0;i<repitation;i++){

        int return_value = system(test_command);

        std::cout << "\n\n";

        std::cout << "\n The return_value of the process[" << i << "]:" << return_value;

        if(return_value == 0){

           succeeded_test++;

           std::cout << "\n";

           std::cout << "\n The test[" << i << "] has been complated.. ";
        }
        else{

           repitation++;
        }
     }

     FileManager.SetFilePath("Test_Record_File");

     FileManager.FileOpen(Rf);

     int sum = 0;

     std::string test_result = "";

     while(!FileManager.Control_End_of_File()){

           test_result = FileManager.ReadLine();

           if(test_result[0] != '\n'){

              std::stringstream s(test_result);

              int test_output = 0;

              s >> test_output;

              sum = sum + test_output;

              if(test_output != 0){

                 std::cout << "\n sum:" << sum;
              }
           }
     }

    FileManager.FileClose();

    int average = ((double)sum)/repitation;

    std::cout << "\n\n -------------------------------------";

    std::cout << "\n the average:" << average << std::endl;

    std::cout << "\n\n";

    delete [] test_command;

    return 0;
}


void Determine_Test_Command(char ** test_command, char * test_binary, char * input_file, char * workload){

     char directory_command [] = "./";

     int directory_command_string_length = strlen(directory_command);

     int input_file_string_length = strlen(input_file);

     int test_binary_string_lenght = strlen(test_binary);

     int workload_string_length = strlen(workload);

     int command_lenght = input_file_string_length + test_binary_string_lenght +

                          directory_command_string_length + workload_string_length;

     *test_command = new char [5*command_lenght];

     int increment = 0;

     for(int i=0;i<directory_command_string_length;i++){

         (*test_command)[increment] = directory_command[i];

         increment++;
     }

     for(int i=0;i<test_binary_string_lenght;i++){

         (*test_command)[increment] = test_binary[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;


     for(int i=0;i<input_file_string_length;i++){

         (*test_command)[increment] = input_file[i];

         increment++;
     }


     (*test_command)[increment] = ' ';

     increment++;


     for(int i=0;i<workload_string_length;i++){

        (*test_command)[increment] = workload[i];

        increment++;
     }

     (*test_command)[increment] = '\0';
}
