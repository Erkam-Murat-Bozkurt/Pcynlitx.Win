

#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <random>
#include <sstream>
#include <cstring>
#include <string>

void Multiply(int matrix_size);

void Clear_Heap_Memory(double *** pointer, int matrix_size);

void Construct_Random_Matrix(double *** pointer, int matrix_size);

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

std::mutex mtx;

int Elapsed_Time = 0;

double lower_bound = 0;

double upper_bound = 5;

std::uniform_real_distribution<double> unif(lower_bound,upper_bound);

std::default_random_engine re;

double ** result_matrix = nullptr;

double ** matrix_1 = nullptr;

double ** matrix_2 = nullptr;

int main(int argc, char** argv){

    if(argc != 3) {

       std::cout << "\n\n   Usage: " << argv[0] << " [Thread Number] [Matrix Size]" << std::endl;

       std::cout << "\n\n";

       exit(1);
    }

    std::string Dimention = "";

    std::string threadNumber = "";

    Convert_char_to_std_string(&threadNumber,argv[1]);

    Convert_char_to_std_string(&Dimention,argv[2]);


    std::stringstream sd(Dimention);

    std::stringstream sn(threadNumber);

    int matrix_size = 0, num_threads = 0;

    sd >> matrix_size;

    sn >> num_threads;

    Construct_Random_Matrix(&matrix_1,matrix_size);

    Construct_Random_Matrix(&matrix_2,matrix_size);

    Construct_Random_Matrix(&result_matrix,matrix_size);


    struct rusage usage;

    struct timeval start, end;

    int return_value = getrusage(RUSAGE_SELF,&usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    start = usage.ru_utime;

    std::thread thread_list[num_threads];

    for(int i=0;i<num_threads;i++){

       thread_list[i] = std::thread(Multiply,matrix_size);
    }

    for(int i=0;i<num_threads;i++){

        thread_list[i].join();
    }

    return_value = getrusage(RUSAGE_SELF, &usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    end = usage.ru_utime;

    Elapsed_Time = end.tv_sec - start.tv_sec;

    std::cout << Elapsed_Time << std::endl;

    Clear_Heap_Memory(&matrix_1,matrix_size);

    Clear_Heap_Memory(&matrix_2,matrix_size);

    Clear_Heap_Memory(&result_matrix,matrix_size);

    return 0;
}

void Multiply(int matrix_size){

     for(int i=0;i<matrix_size;i++){

         int sum = 0;

         for(int j=0;j<matrix_size;j++){

             for(int k=0;k<matrix_size;k++){

                 sum = sum + (matrix_1[i][k])*(matrix_2[k][j]);
             }

             result_matrix[i][j] = sum;
         }
     }
}

void Construct_Random_Matrix(double *** pointer, int matrix_size){

     *pointer = new double * [5*matrix_size];

     for(int i=0;i<matrix_size;i++){

         (*pointer)[i] = new double [5*matrix_size];

         for(int k=0;k<matrix_size;k++){

             (*pointer)[i][k] = unif(re);
         }
     }
}

void Clear_Heap_Memory(double *** pointer, int matrix_size){

     for(int i=0;i<matrix_size;i++){

         delete [] (*pointer)[i];
     }
}

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer){

    int string_length = strlen(cstring_pointer);

    for(int i=0;i<string_length;i++){

        *string_line = *string_line + cstring_pointer[i];
    }
}
