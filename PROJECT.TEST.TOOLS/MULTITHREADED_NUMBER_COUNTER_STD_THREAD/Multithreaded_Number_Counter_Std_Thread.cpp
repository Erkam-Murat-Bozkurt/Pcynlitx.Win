
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
#include <cstring>
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"


int data_size  = 0;

double ** data_pointer = nullptr;

void Construct_Random_Data(double *** pointer, int data_size);

void Compute_Mean_Value(int Thread_Number);

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Clear_Heap_Memory(double *** pointer, int data_size);

double lower_bound = 0;

double upper_bound = 10;

std::uniform_real_distribution<double> unif(lower_bound,upper_bound);

std::default_random_engine re;


#define LOOP_BREAK_CONDITION (Line_index >= Reader->Get_Data_length())

#define INDEX_INCREMENT_STATUS (Reader->Get_Data_List_Member_Record_Status(index))

void Counter_Function(Data_Reader * Reader,int thread_number);

int thread_wait_number = 0;

int exit_thread_number = 0;

int entered_thread_number = 0;


int total_reputation = 0;

int num_threads = 0;

int Elapsed_Time = 0;

int Line_index = 0;

std::mutex mtx_serial;
std::mutex mtx_parallel;


std::condition_variable cv;

char search_word [] = "100.00";

int main(int argc, char ** argv){

    if(argc < 4){

       std::cout << "\n\n usage: " << argv[0] << " <thread number> <input file> <workload:data size>";

       std::cout << "\n\n";

       exit(0);
    }


    IntToCharTranslater Translater;

    num_threads = Translater.TranslateFromCharToInt(argv[1]);

    if((num_threads%2)!=0){

       std::cout << "\n\n The number of the threads must be selected as multiple of two..";

       std::cout << "\n\n";
    }


    // THE CONSTRUCTION OF ARTIFICIAL WORKLOAD

    std::string dataLength = "";

    Convert_char_to_std_string(&dataLength,argv[3]);

    std::stringstream sd(dataLength);

    sd >> data_size;

    Construct_Random_Data(&data_pointer,data_size);

    // --------------------------------------------


    Data_Reader Reader;

    Reader.SetFilePath(argv[2]);

    Reader.Receive_Data();

    struct rusage usage;

    struct timeval start, end;

    int return_value = getrusage(RUSAGE_SELF,&usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    start = usage.ru_utime;

    std::thread threads[num_threads];

    for(int i=0;i<num_threads;i++){

        threads[i] = std::thread(Counter_Function,&Reader,i);
    }


    for(int i=0;i<num_threads;i++){

        threads[i].join();
    }


    return_value = getrusage(RUSAGE_SELF, &usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    end = usage.ru_utime;

    Elapsed_Time = end.tv_sec - start.tv_sec;

    int number = 0;

    for(int i=0;i<Reader.Get_Record_List_Length();i++){

        if(Reader.Get_Record_Number(i) <= 1){

           number = number + Reader.Get_Reputation(i);
        }
    }

    for(int i=0;i<Reader.Get_Data_length();i++){

        if(Reader.Get_Record_Number(i) > 1){

           std::cout << "\n There is overrite ..";
        }
    }

    std::cout << "\n Elapsed_Time:" << Elapsed_Time << std::endl;

    std::cout << "\n";

    Cpp_FileOperations FileManager;

    FileManager.SetFilePath("Test_Record_File");

    FileManager.FileOpen(Af);

    FileManager.WriteToFile(Translater.Translate(Elapsed_Time));

    FileManager.WriteToFile("\n");

    FileManager.FileClose();

    Clear_Heap_Memory(&data_pointer,data_size);

    return 0;
}

void Counter_Function(Data_Reader * Reader,int thread_number){

     std::unique_lock<std::mutex> serial_lck(mtx_serial);

     serial_lck.unlock();


     std::unique_lock<std::mutex> parallel_lck(mtx_parallel);

     parallel_lck.unlock();



     // START OF THE ENTRANCE BARRIER

     serial_lck.lock();

     entered_thread_number++;

     if(entered_thread_number < num_threads ){

        cv.wait(serial_lck);

        serial_lck.unlock();
     }
     else{

          serial_lck.unlock();
     }

     cv.notify_one();


     // THE END OF THE ENTRANCE BARRIER

     int index = 0;

     do {
             // STARTING OF THE PARALLEL EXECUTION REGION

             StringOperator StringManager;

             parallel_lck.lock();

             index = Line_index;

             Line_index++;

             parallel_lck.unlock();


             parallel_lck.lock();

             while(Reader->Get_Data_List_Member_Record_Status(index)){

                   Line_index++;

                   index = Line_index;
             }

             parallel_lck.unlock();


             Compute_Mean_Value(thread_number);

             // THE END OF THE PARALLEL EXECUTION



             serial_lck.lock();

             thread_wait_number++;

             if(thread_wait_number < (num_threads - exit_thread_number)){  // SERIAL EXECUTION BARRIER

                cv.wait(serial_lck);

                serial_lck.unlock();


                serial_lck.lock();

                thread_wait_number--;

                serial_lck.unlock();

             }
             else{

                   serial_lck.unlock();


                   // START OF THE SERIAL EXECUTION  ------------------------------------------------

                   // The critical section

                   serial_lck.lock();

                   char * string_line = Reader->Get_Data_List_Member_String(index);

                   int reputation = StringManager.Get_Word_Number_on_String(string_line,search_word);

                   total_reputation = total_reputation + reputation;

                   serial_lck.unlock();


                   serial_lck.lock();

                   if((!Reader->Get_Data_List_Member_Record_Status(index))){

                        Reader->Set_Record_Data(index,thread_number,reputation);
                   };

                   serial_lck.unlock();


                   // THE END OF SERIAL EXECUTION -------------------------------------------------



                   cv.notify_one();   // Notifies all threads waiting


                   serial_lck.lock();

                   cv.wait(serial_lck);

                   serial_lck.unlock();


                   serial_lck.lock();

                   thread_wait_number--;

                   serial_lck.unlock();
             }


     }while(!LOOP_BREAK_CONDITION);


     parallel_lck.lock();

     exit_thread_number++;

     parallel_lck.unlock();


     do {

          if(exit_thread_number<num_threads){

             cv.notify_all();

          }

     } while(exit_thread_number<num_threads);
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
