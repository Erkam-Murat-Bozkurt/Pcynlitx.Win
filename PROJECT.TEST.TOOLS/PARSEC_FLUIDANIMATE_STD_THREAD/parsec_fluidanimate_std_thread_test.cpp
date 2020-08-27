
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <sstream>
#include "Cpp_FileOperations.h"
#include <string.h>


void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Determine_Test_Command(char ** test_command, char * thread_number, char * frame_number, char * input_file);

int main(int argc, char ** argv){

    if(argc != 5) {

       std::cout << "\n\n   Usage: " << argv[0]

       << " [Repitation] [Thread Number] [Frame Number] [Input File]"

       << std::endl;

       std::cout << "\n\n";

       exit(1);
    }

    std::cout << "\n\n THE PARSEC FLUIDANIMATE TEST";

    std::cout << "\n";

    int sum = 0;

    std::string test_repitation = "";

    Convert_char_to_std_string(&test_repitation,argv[1]);

    std::stringstream s(test_repitation);

    int repitation = 0;

    s >> repitation;

    std::cout << "\n The repitation of the test:" << repitation;

    std::cout << "\n\n";

    char * test_command = nullptr;

    Determine_Test_Command(&test_command,argv[2],argv[3],argv[4]);

    std::cout << "\n\n Test Command:" << test_command;

    std::cin.get();

    Cpp_FileOperations FileManager;

    FileManager.SetFilePath("Test_Record_File");

    FileManager.FileOpen(RWCf);

    FileManager.FileClose();

    for(int i=0;i<repitation;i++){

        system(test_command);

        std::cout << "\n\n";
    }

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

    int average = ((double)sum)/repitation;

    std::cout << "\n\n -------------------------------------";

    std::cout << "\n the average:" << average << std::endl;

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


void Determine_Test_Command(char ** test_command, char * thread_number,

                            char * frame_number,char * input_file)
{

     char space = ' ';

     char directory_operator []= "./";

     char exe_file [] = "parsec_fluidanimate_std_thread";

     int exe_file_string_lenght = strlen(exe_file);

     int input_file_string_length = strlen(input_file);

     int thread_number_string_lenght = strlen(thread_number);

     int frame_number_string_length = strlen(frame_number);

     int directory_operator_string_length = strlen(directory_operator);

     int command_lenght = input_file_string_length + thread_number_string_lenght +

                          frame_number_string_length + directory_operator_string_length;

     *test_command = new char [5*command_lenght];

     int increment = 0;

     for(int i=0;i<directory_operator_string_length;i++){

         (*test_command)[increment] = directory_operator[i];

         increment++;
     }

     for(int i=0;i<exe_file_string_lenght;i++){

         (*test_command)[increment] = exe_file[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<thread_number_string_lenght;i++){

         (*test_command)[increment] = thread_number[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<frame_number_string_length;i++){

         (*test_command)[increment] = frame_number[i];

         increment++;
     }

     (*test_command)[increment] = ' ';

     increment++;

     for(int i=0;i<input_file_string_length;i++){

         (*test_command)[increment] = input_file[i];

         increment++;
     }

     (*test_command)[increment] = '\0';
}
