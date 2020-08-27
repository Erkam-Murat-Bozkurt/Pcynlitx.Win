

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <string>
#include <sstream>
#include "Cpp_FileOperations.h"

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Determination_of_test_command(char ** test_command, char * thread_number, char * exe_file, char * inputFile);

int main(int argc, char ** argv){

    if(argc != 5) {

       std::cout << "\n\n   Usage: " << argv[0] << " [Repitation] [Thread Number] [Test program] [Input File]" << std::endl;

       std::cout << "\n\n";

       exit(1);
    }

    std::cout << "\n\n RODINIA LU DECOMPOSITION PCYNLITX TEST";

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

    Determination_of_test_command(&test_command,argv[2],argv[3],argv[4]);

    std::cout << "\n Test command:" << test_command;

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


void Determination_of_test_command(char ** test_command, char * thread_number, char * exe_file, char * inputFile){

     char space = ' ';

     char directory_operator []= "./";

     char send_command [] = ">>";

     char thread_number_indicator [] = "-n";

     char input_file_indicator [] = "-i";

     char Test_Record_File [] = "Test_Record_File";

     int exe_file_character_size = strlen(exe_file);

     int inputFile_character_size = strlen(inputFile);

     int Send_Command_Name_Size = strlen(send_command);

     int Directory_Operator_Size = strlen(directory_operator);

     int Test_Record_File_Character_Size = strlen(Test_Record_File);

     int thread_number_character_size = strlen(thread_number);

     int tn_indicator_character_size = strlen(thread_number_indicator);

     int inf_idicator_character_size = strlen(input_file_indicator);

     int command_size = exe_file_character_size + inputFile_character_size

                        + Test_Record_File_Character_Size + Send_Command_Name_Size +

                        thread_number_character_size + tn_indicator_character_size

                        + inf_idicator_character_size;

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

     for(int i=0;i<tn_indicator_character_size;i++){

         (*test_command)[index_number] = thread_number_indicator[i];

         index_number++;
     }

     (*test_command)[index_number] = space;

     index_number++;

     for(int i=0;i<thread_number_character_size;i++){

         (*test_command)[index_number] = thread_number[i];

         index_number++;
     }

     (*test_command)[index_number] = space;

     index_number++;

     for(int i=0;i<inf_idicator_character_size;i++){

         (*test_command)[index_number] = input_file_indicator[i];

         index_number++;
     }

     (*test_command)[index_number] = space;

     index_number++;

     for(int i=0;i<inputFile_character_size;i++){

        (*test_command)[index_number] = inputFile[i];

        index_number++;
     }

     (*test_command)[index_number] = space;

     index_number++;

     for(int i=0;i<Send_Command_Name_Size;i++){

         (*test_command)[index_number] = send_command[i];

         index_number++;
     }

     (*test_command)[index_number] = space;

     index_number++;

     for(int i=0;i<Test_Record_File_Character_Size;i++){

         (*test_command)[index_number] = Test_Record_File[i];

         index_number++;
     }

     (*test_command)[index_number] = '\0';
}
