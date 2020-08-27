

#include "Data_Reader.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <cstring>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <string>
#include <sstream>
#include <random>
#include <sstream>
#include <cstring>
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"
#include "Data_Types.h"


double ** data_pointer = nullptr;

void Construct_Random_Data(double *** pointer, int data_size);

void Compute_Mean_Value(int Thread_Number);

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Clear_Heap_Memory(double *** pointer, int data_size);


#define LOOP_BREAK_CONDITION (Line_index >= Reader.Get_Data_length())

#define INDEX_INCREMENT_STATUS (Reader.Get_Data_List_Member_Record_Status(index))


double lower_bound = 0;

double upper_bound = 10;

std::uniform_real_distribution<double> unif(lower_bound,upper_bound);

std::default_random_engine re;


int total_reputation = 0;

int num_threads = 32;

int Elapsed_Time = 0;

int Line_index = 0;

int exit_thread_number = 0;

int data_size  = 0;

char search_word [] = "100.00";

int main(int argc, char ** argv){

    if(argc < 3){

       std::cout << "\n\n usage: " << argv[0] << " <input file> <workload:data size>";

       std::cout << "\n\n";

       exit(0);
    }


    // THE CONSTRUCTING OF ARTIFICIAL WORKLOAD

    std::string dataLength = "";

    Convert_char_to_std_string(&dataLength,argv[2]);

    std::stringstream sd(dataLength);

    sd >> data_size;

    Construct_Random_Data(&data_pointer,data_size);

    // --------------------------------------------


    pcynlitx::Thread_Server Server;

    Server.Data_Reader_IT.SetFilePath(argv[1]);

    Server.Data_Reader_IT.Receive_Total_Thread_Number(num_threads);

    Server.Data_Reader_IT.Receive_Data();

    struct rusage usage;

    struct timeval start, end;

    int return_value = getrusage(RUSAGE_SELF,&usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    start = usage.ru_utime;

    for(int i=0;i<num_threads;i++){

        Server.Activate(i,Function);
    }

    for(int i=0;i<num_threads;i++){

        Server.Join(i);
    };

    return_value = getrusage(RUSAGE_SELF, &usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    end = usage.ru_utime;

    Elapsed_Time = end.tv_sec - start.tv_sec;

    std::cout << "\n\n Elapsed_Time:" << Elapsed_Time;

    std::cout << "\n\n";

    int number = 0;

    for(int i=0;i<Server.Data_Reader_IT.Get_Record_List_Length();i++){

        if(Server.Data_Reader_IT.Get_Record_Number(i) <= 1){

           number = number + Server.Data_Reader_IT.Get_Reputation(i);
        }
    }

    std::cout << "\n\n number:" << number << std::endl;

    std::cout << "\n\n total_reputation:" << total_reputation << std::endl;


    for(int i=0;i< Server.Data_Reader_IT.Get_Data_length();i++){

        if(Server.Data_Reader_IT.Get_Record_Number(i) > 1){

           std::cout << "\n There is overrite ..";
        }
    }

    bool acess_order_violation = Server.Data_Reader_IT.Check_Acess_Order_Violation();

    if(acess_order_violation){

       std::cout << "\n There is acess order violation.." << std::endl;

       std::cout << "\n\n";
    }
    else{

        std::cout << "\n There is no acess order violation..";

        std::cout << "\n\n";
    }


    Server.Data_Reader_IT.Print_Acess_Order();

    Cpp_FileOperations FileManager;

    IntToCharTranslater Translater;

    FileManager.SetFilePath("Test_Record_File");

    FileManager.FileOpen(Af);

    FileManager.WriteToFile(Translater.Translate(Elapsed_Time));

    FileManager.WriteToFile("\n");

    FileManager.FileClose();

    Clear_Heap_Memory(&data_pointer,data_size);

    return 0;
}

void Function(pcynlitx::thds * thread_data){

     pcynlitx::TM_Client Manager(thread_data,"Function");

     pcynlitx::Data_Reader_Client Reader(thread_data);

     Manager.lock();

     int thread_number = Manager.Get_Thread_Number();

     Manager.unlock();

     // THE END OF THE ENTRANCE BARRIER

     int index = 0;

     do {
             // STARTING OF THE PARALLEL EXECUTION REGION

             if(LOOP_BREAK_CONDITION){

                break;
             }

             Compute_Mean_Value(thread_number);  // Artificial workload

             StringOperator StringManager;

             Manager.lock();

             index = Line_index;

             Line_index++;

             Manager.unlock();


             Manager.lock();

             while(Reader.Get_Data_List_Member_Record_Status(index)){

                   Line_index++;

                   index = Line_index;
             }

             Manager.unlock();


             // THE END OF THE PARALLEL EXECUTION


             Manager.start_serial(0,num_threads,thread_number);


             if(LOOP_BREAK_CONDITION){

                break;
             }


             // START OF THE SERIAL EXECUTION  ------------------------------------------------

             // The critical section


             char * string_line = Reader.Get_Data_List_Member_String(index);

             int reputation = StringManager.Get_Word_Number_on_String(string_line,search_word);

             total_reputation = total_reputation + reputation;


             if((!Reader.Get_Data_List_Member_Record_Status(index))){

                  Reader.Set_Record_Data(index,thread_number,reputation);
             };

             Reader.Set_Acess_Order(thread_number);



             // THE END OF SERIAL EXECUTION -------------------------------------------------

             Manager.end_serial(0,num_threads,thread_number);


     }while(!LOOP_BREAK_CONDITION);


     Manager.lock();

     exit_thread_number++;

     Manager.unlock();

     do {

         if(exit_thread_number<num_threads){

            int block_number = 0;

            for(int i=0;i<num_threads;i++){

                Manager.rescue(i);
            }
         }

     } while(exit_thread_number<num_threads);


     Manager.Exit();
}


void Compute_Mean_Value(int thread_number){

     int sum = 0, average = 0;

     for(int i=0;i<data_size;i++){

         sum = sum + data_pointer[thread_number][i];
     }

     average = sum / data_size;
}


void Construct_Random_Data(double *** pointer, int data_size){

     *pointer = new double * [5*num_threads];

     for(int i=0;i<num_threads;i++){

         (*pointer)[i] = new double [5*data_size];

         for(int k=0;k<data_size;k++){

             (*pointer)[i][k] = unif(re);
         }
     }
}

void Clear_Heap_Memory(double *** pointer, int data_size){

     for(int i=0;i<num_threads;i++){

         delete [] (*pointer)[i];
     }

     delete [] (*pointer);
}

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer){

    int string_length = strlen(cstring_pointer);

    for(int i=0;i<string_length;i++){

        *string_line = *string_line + cstring_pointer[i];
    }
}
