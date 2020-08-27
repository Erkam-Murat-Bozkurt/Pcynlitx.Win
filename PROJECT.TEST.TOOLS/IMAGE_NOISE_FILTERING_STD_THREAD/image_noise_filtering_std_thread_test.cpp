
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <sstream>
#include "Cpp_FileOperations.h"

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Determine_Test_Command(char ** test_command, char * threadNumber, char * input_file, char * image_number);

int main(int argc, char ** argv){

    std::cout << "\n\n THE MULTITHREAD IMAGE NOISE FILTERING STD-THREAD TEST";

    std::cout << "\n";

    if(argc != 5) {

         std::cout << "\n\n   Usage: " << argv[0] << " [Repitation] [Thread Number] [Image Path] [Total Image Number]" << std::endl;

         std::cout << "\n\n";

         exit(1);
    }

    int sum = 0;

    std::string test_repitation = "";

    Convert_char_to_std_string(&test_repitation,argv[1]);

    std::stringstream s(test_repitation);

    int repitation = 0;

    s >> repitation;


    char * test_command = nullptr;

    Determine_Test_Command(&test_command,argv[2],argv[3],argv[4]);

    std::cout << "\n\n Test Command:";

    std::cout << "\n\n ";

    std::cout << test_command;

    std::cout << "\n\n Press Enter .. ";

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

           system("echo \"\n\" >> Test_Record_File");
        }
        else{

              repitation++;
        }
    }

    FileManager.SetFilePath("Test_Record_File");

    FileManager.FileOpen(Rf);

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

    delete [] test_command;

    std::cout << "\n\n -------------------------------------";

    std::cout << "\n the average:" << ((double)sum)/repitation << std::endl;

    std::cout << "\n\n";

    return 0;
}


void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer){

    int string_length = strlen(cstring_pointer);

    for(int i=0;i<string_length;i++){

        *string_line = *string_line + cstring_pointer[i];
    }
}

void Determine_Test_Command(char ** test_command, char * threadNumber, char * input_file, char * image_number){

     char test_binary [] = "./image_noise_filtering_std_thread";

     char record_file [] = ">> Test_Record_File";

     int input_file_string_length = strlen(input_file);

     int binary_lenght = strlen(test_binary);

     int record_file_lenght = strlen(record_file);

     int thread_number_string_length = strlen(threadNumber);

     int image_number_string_length = strlen(image_number);

     int command_lenght = input_file_string_length + binary_lenght + record_file_lenght

                          + thread_number_string_length + image_number_string_length;

     *test_command = new char [5*command_lenght];

     int increment = 0;

     for(int i=0;i<binary_lenght;i++){

         (*test_command)[increment] = test_binary[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<thread_number_string_length;i++){

         (*test_command)[increment] = threadNumber[i];

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

     for(int i=0;i<image_number_string_length;i++){

         (*test_command)[increment] = image_number[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<record_file_lenght;i++){

        (*test_command)[increment] = record_file[i];

        increment++;
     }

     (*test_command)[increment] = '\0';
}
