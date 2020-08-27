

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <sstream>
#include "Cpp_FileOperations.h"

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Determine_Test_Command(char ** test_command, char * thread_number, char * input_file);

int main(int argc, char ** argv){

    if(argc < 4){

       std::cout << "\n\n";

       std::cout << "\n usage:" << argv[0] << " <repitation> <thread_number> <input file>";

       std::cout << "\n\n";

       exit(0);
    }

    std::cout << "\n\n THE RODINIA KMEANS STD-THREAD TEST";

    std::cout << "\n";

    char * test_command = nullptr;

    Determine_Test_Command(&test_command,argv[2],argv[3]);

    std::cout << "\n\n Test_command:" << test_command;

    std::cin.get();

    int sum = 0;

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

    int succeeded_test = 0;

    for(int i=0;i<repitation;i++){

        int return_value = system(test_command);

        std::cout << "\n The return_value of the process:" << return_value;

        if(return_value == 0){

           succeeded_test++;
        }
        else{

              repitation++;
        }
    }

    FileManager.FileOpen(Rf);

    std::string test_result = "";

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


void Determine_Test_Command(char ** test_command, char * thread_number, char * input_file){

     char record_file [] = ">> Test_Record_File";

     char test_binary [] = "./rodinia_std_thread_kmeans";

     int binary_name_size = strlen(test_binary);

     int record_file_name_size = strlen(record_file);

     int thread_number_string_length = strlen(thread_number);

     int input_file_string_length = strlen(input_file);

     int command_lenght = binary_name_size + record_file_name_size +

                          thread_number_string_length + input_file_string_length;

     *test_command = new char [5*command_lenght];

     int increment = 0;

     for(int i=0;i<binary_name_size;i++){

         (*test_command)[increment] = test_binary[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<thread_number_string_length;i++){

         (*test_command)[increment] = thread_number[i];

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

     for(int i=0;i<record_file_name_size;i++){

         (*test_command)[increment] = record_file[i];

         increment++;
     }

     (*test_command)[increment] = '\0';
}
