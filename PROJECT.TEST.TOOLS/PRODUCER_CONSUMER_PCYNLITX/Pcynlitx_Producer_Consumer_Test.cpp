
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <sstream>
#include "Cpp_FileOperations.h"

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Determine_Test_Command(char ** test_command, char * test_binary, char * input_file, char * workload);

int main(int argc, char ** argv){

    if(argc < 5){

       std::cout << "\n\n";

       std::cout << "\n usage:" << argv[0] << " <repitation> <test binary> <input file> <workload: data size>";

       std::cout << "\n\n";

       exit(0);
    }


    std::cout << "\n\n THE PRODUCER-CONSUMER TEST";

    std::cout << "\n";

    char * test_command = nullptr;

    Determine_Test_Command(&test_command,argv[2],argv[3],argv[4]);

    std::cout << "\n\n Test_command:" << test_command;


    std::string test_repitation = "";

    Convert_char_to_std_string(&test_repitation,argv[1]);

    std::stringstream s(test_repitation);

    Cpp_FileOperations FileManager;

    FileManager.SetFilePath("Test_Record_File");

    FileManager.FileOpen(RWCf);

    FileManager.FileClose();



    int repitation = 0;

    s >> repitation;

    std::cout << "\n The repitation of the test:" << repitation;

    std::cout << "\n\n";

    std::cout << "\n Press enter..";

    std::cin.get();



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


    FileManager.FileOpen(Rf);

    std::string test_result = "";

    int sum = 0;

    while(!FileManager.Control_End_of_File()){

           test_result = FileManager.ReadLine();

           if(test_result[0] != '\n'){

              std::stringstream str(test_result);

              int test_output = 0;

              str >> test_output;

              sum = sum + test_output;

              if(test_output != 0){

                 std::cout << "\n sum:" << sum;
              }
           }
    }

    FileManager.FileClose();


    int average = ((double)sum)/succeeded_test;

    std::cout << "\n\n -------------------------------------";

    std::cout << "\n the average:" << average << std::endl;

    std::cout << "\n\n";

    return 0;
}


void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer){

    int string_length = strlen(cstring_pointer);

    for(int i=0;i<string_length;i++){

        *string_line = *string_line + cstring_pointer[i];
    }
}


void Determine_Test_Command(char ** test_command, char * test_binary, char * input_file, char * workload){

     char record_file [] = ">> Test_Record_File";

     char execute_command [] = "./";

     int input_file_name_size = strlen(input_file);

     int binary_name_size = strlen(test_binary);

     int record_file_name_size = strlen(record_file);

     int workload_name_size = strlen(workload);

     int execute_command_length = strlen(execute_command);

     int command_lenght = input_file_name_size + binary_name_size

                         + record_file_name_size + workload_name_size;

     *test_command = new char [5*command_lenght];

     int increment = 0;

     for(int i=0;i<execute_command_length;i++){

        (*test_command)[increment] = execute_command[i];

        increment++;
     }

     for(int i=0;i<binary_name_size;i++){

         (*test_command)[increment] = test_binary[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<input_file_name_size;i++){

         (*test_command)[increment] = input_file[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<workload_name_size;i++){

        (*test_command)[increment] = workload[i];

        increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<record_file_name_size;i++){

         (*test_command)[increment] = record_file[i];

         increment++;
     }

     (*test_command)[increment] = '\0';
}
