
#include "MT_Library_Headers.h"
#include "Pcynlitx_Data_Clustering.h"
#include <iomanip>


int work_load_data_size  = 0;

int Elapsed_Time = 0;

int num_threads = 8;

int data_matrix_size = 1000;

int First_Pool_Start_Index = 0;

int Second_Pool_Start_Index = data_matrix_size/2;

int first_pool_thread_number_in_end = 0;

int second_pool_thread_number_in_end = 0;

int first_pool_arrange_index = 0;

int second_pool_arrange_index = Second_Pool_Start_Index;

#define FIRST_POOL_END_POINT data_matrix_size/2

#define SECOND_POOL_END_POINT data_matrix_size

#define FIRST_POOL_THREAD_NUMBER num_threads/2

#define SECOND_POOL_THREAD_NUMBER (num_threads - (num_threads/2))

#define FIRST_POOL_THREAD_SEARCH_CONDITION (first_pool_thread_number_in_end < FIRST_POOL_THREAD_NUMBER)

#define SECOND_POOL_THREAD_SEARCH_CONDITION (second_pool_thread_number_in_end < SECOND_POOL_THREAD_NUMBER)

#define THREAD_SEARCH_CONDITION (first_pool_thread_number_in_end < FIRST_POOL_THREAD_NUMBER) || (second_pool_thread_number_in_end < SECOND_POOL_THREAD_NUMBER)

double ** data_matrix = nullptr;

double ** result_matrix = nullptr;

double lower_bound = 0;

double upper_bound = 500;

std::uniform_real_distribution<double> unif(lower_bound,upper_bound);

std::default_random_engine re;

double ** workload_data_pointer = nullptr;

void Construct_Random_Data(double *** pointer, int data_size);

void Compute_Mean_Value(int Thread_Number);

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Clear_Data_Memory(double *** pointer, int data_size);

void Construct_Random_Matrix(double *** pointer, int matrix_size);

void Rearrange_The_Row(int row_number);

void Rearrange_The_Column(int column_number);

void Clear_Heap_Memory(double *** pointer, int matrix_size);

void Print_Data();


int main(int argc, char ** argv){

    if(argc < 3){

       std::cout << "\n\n usage: " << argv[0] << " <data matrix size> <workload: data size>";

       std::cout << "\n\n";

       exit(0);
    }


    std::string data_matrix_input = "";

    Convert_char_to_std_string(&data_matrix_input,argv[1]);

    std::stringstream sd_matrix(data_matrix_input);

    sd_matrix >> data_matrix_size;

    Construct_Random_Matrix(&data_matrix,data_matrix_size);


    // THE CONSTRUCTION OF ARTIFICIAL WORKLOAD

    std::string dataLength = "";

    Convert_char_to_std_string(&dataLength,argv[2]);

    std::stringstream sd(dataLength);

    sd >> work_load_data_size;

    Construct_Random_Data(&workload_data_pointer,work_load_data_size);

    // --------------------------------------------



    pcynlitx::Thread_Server Server;

    Server.First_Thread_Pool_Acess_Holder_IT.Receive_First_Pool_Thread_Number(FIRST_POOL_THREAD_NUMBER);

    Server.Second_Thread_Pool_Acess_Holder_IT.Receive_Second_Pool_Thread_Number(SECOND_POOL_THREAD_NUMBER);

    Server.First_Thread_Pool_Acess_Holder_IT.Receive_Data_Size(data_matrix_size);

    Server.First_Thread_Pool_Acess_Holder_IT.Receive_Data_Size(data_matrix_size);

    struct rusage usage;

    struct timeval start, end;

    int return_value = getrusage(RUSAGE_SELF,&usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    start = usage.ru_utime;

    for(int i=0;i<FIRST_POOL_THREAD_NUMBER;i++){

        Server.Activate(i,First_Pool_Function);
    }

    for(int i=SECOND_POOL_THREAD_NUMBER;i<num_threads;i++){

        Server.Activate(i,Second_Pool_Function);
    }

    for(int i=0;i<num_threads;i++){

        Server.Join(i);
    }

    return_value = getrusage(RUSAGE_SELF, &usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    end = usage.ru_utime;

    Elapsed_Time = end.tv_sec - start.tv_sec;

    Clear_Heap_Memory(&data_matrix,data_matrix_size);

    Clear_Data_Memory(&workload_data_pointer,work_load_data_size);

    bool first_pool_acess_order_violation = Server.First_Thread_Pool_Acess_Holder_IT.Check_First_Pool_Acess_Order_Violation();

    bool second_pool_acess_order_violation = Server.Second_Thread_Pool_Acess_Holder_IT.Check_Second_Pool_Acess_Order_Violation();


    if(first_pool_acess_order_violation){

       return 1;
    }

    if(second_pool_acess_order_violation){

       return 1;
    }

    std::cout << Elapsed_Time << std::endl;

    return 0;
}


 void First_Pool_Function(pcynlitx::thds * thread_data){

      pcynlitx::TM_Client Manager(thread_data,"First_Pool_Function");

      pcynlitx::First_Thread_Pool_Acess_Holder_Client Holder(thread_data);


      Manager.lock();

      int thread_number = Manager.Get_Thread_Number();

      Manager.unlock();


      // START OF THE ENTRANCE BARRIER

      Manager.barrier_wait();


      // THE END OF THE ENTRANCE BARRIER


      do{

        // Parrallel region

        Compute_Mean_Value(thread_number); // Artificial workload

        // The end of parallel region

        Manager.start_serial(0,FIRST_POOL_THREAD_NUMBER,thread_number);

        if(first_pool_arrange_index < FIRST_POOL_END_POINT){

           Rearrange_The_Row(first_pool_arrange_index);

           first_pool_arrange_index++;
        }

        Manager.end_serial(0,FIRST_POOL_THREAD_NUMBER,thread_number);

      }while(first_pool_arrange_index < FIRST_POOL_END_POINT);


     Manager.lock();

     first_pool_thread_number_in_end++;

     Manager.unlock();

     do {

          if(FIRST_POOL_THREAD_SEARCH_CONDITION){

             for(int i=0;i<FIRST_POOL_THREAD_NUMBER;i++){

                if(i!=thread_number){

                  Manager.rescue(i);
                }
             }
           }

           Manager.yield();

     } while(FIRST_POOL_THREAD_SEARCH_CONDITION);



     if(thread_number == 0){

        first_pool_arrange_index = 0;
     }


     Manager.barrier_wait();


     if(thread_number == 0){

        first_pool_thread_number_in_end = 0;
     }


     do{

       // Parrallel region

       Compute_Mean_Value(thread_number); // Artificial workload

       // The end of parallel region

       Manager.start_serial(0,FIRST_POOL_THREAD_NUMBER,thread_number);

       if(first_pool_arrange_index < FIRST_POOL_END_POINT){

          Rearrange_The_Column(first_pool_arrange_index);

          first_pool_arrange_index++;
       }

       Manager.end_serial(0,FIRST_POOL_THREAD_NUMBER,thread_number);

     }while(first_pool_arrange_index < FIRST_POOL_END_POINT);


     Manager.lock();

     first_pool_thread_number_in_end++;

     Manager.unlock();

     do {

          if(FIRST_POOL_THREAD_SEARCH_CONDITION){

             for(int i=0;i<num_threads;i++){

                 if(i!=thread_number){

                    Manager.rescue(i);
                 }
             }
          }

          Manager.yield();

     } while(FIRST_POOL_THREAD_SEARCH_CONDITION);


    Manager.Exit();
 }



void Second_Pool_Function(pcynlitx::thds * thread_data){

     pcynlitx::TM_Client Manager(thread_data,"Second_Pool_Function");

     pcynlitx::First_Thread_Pool_Acess_Holder_Client Placer(thread_data);


     Manager.lock();

     int thread_number = Manager.Get_Thread_Number();

     Manager.unlock();


     Manager.barrier_wait();


     do{

         // Parrallel region

         Compute_Mean_Value(thread_number); // Artificial workload

         // The end of parallel region

         Manager.start_serial(FIRST_POOL_THREAD_NUMBER,num_threads,thread_number);

         if(second_pool_arrange_index < SECOND_POOL_END_POINT){

            Rearrange_The_Row(second_pool_arrange_index);

            second_pool_arrange_index++;
         }

         Manager.end_serial(FIRST_POOL_THREAD_NUMBER,num_threads,thread_number);

     }while(second_pool_arrange_index < SECOND_POOL_END_POINT);


     Manager.lock();

     second_pool_thread_number_in_end++;

     Manager.unlock();


     do{

       if(SECOND_POOL_THREAD_SEARCH_CONDITION){

          for(int i=FIRST_POOL_THREAD_NUMBER;i<num_threads;i++){

              if(i!=thread_number){

                 Manager.rescue(i);
              }
          }
       }

       Manager.yield();

     }while(SECOND_POOL_THREAD_SEARCH_CONDITION);



     if(thread_number == num_threads-1){

        second_pool_arrange_index = 0;
     }


     Manager.barrier_wait();


     if(thread_number == num_threads-1){

       second_pool_thread_number_in_end = 0;
     }


     do{

       // Parrallel region

       Compute_Mean_Value(thread_number); // Artificial workload

       // The end of parallel region

       Manager.start_serial(FIRST_POOL_THREAD_NUMBER,num_threads,thread_number);

       if(second_pool_arrange_index < SECOND_POOL_END_POINT){

          Rearrange_The_Column(second_pool_arrange_index);

          second_pool_arrange_index++;
       }

       Manager.end_serial(FIRST_POOL_THREAD_NUMBER,num_threads,thread_number);

     }while(second_pool_arrange_index < SECOND_POOL_END_POINT);


     Manager.lock();

     second_pool_thread_number_in_end++;

     Manager.unlock();

     do{

       if(SECOND_POOL_THREAD_SEARCH_CONDITION){

          for(int i=FIRST_POOL_THREAD_NUMBER;i<num_threads;i++){

              if(i!=thread_number){

                 Manager.rescue(i);
              }
          }
       }

       Manager.yield();

    }while(SECOND_POOL_THREAD_SEARCH_CONDITION);

    Manager.Exit();
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

 void Rearrange_The_Row(int row_number){

      for(int i=0;i<data_matrix_size;i++){

         for(int k=data_matrix_size-1;k>0;k--){

            if(data_matrix[k][row_number] > data_matrix[k-1][row_number]){

               double temp = 0.0;

               temp = data_matrix[k-1][row_number];

               data_matrix[k-1][row_number] = data_matrix[k][row_number];

               data_matrix[k][row_number] = temp;
            }
         }
      }
 }

 void Rearrange_The_Column(int column_number){

      for(int i=0;i<data_matrix_size;i++){

         for(int k=data_matrix_size-1;k>0;k--){

            if(data_matrix[column_number][k] > data_matrix[column_number][k-1]){

               double temp = 0.0;

               temp = data_matrix[column_number][k-1];

               data_matrix[column_number][k-1] = data_matrix[column_number][k];

               data_matrix[column_number][k] = temp;
            }
         }
      }
 }

void Print_Data(){

     std::cout << "\n\n";

     for(int i=0;i<data_matrix_size;i++){

         std::cout << "\n";

         for(int k=0;k<data_matrix_size;k++){

             std::cout << std::setw(8) << data_matrix[k][i];
         }
     }

     std::cout << "\n\n";
}


 void Compute_Mean_Value(int thread_number){

      int sum = 0, average = 0;

      for(int i=0;i<work_load_data_size;i++){

          sum = sum + workload_data_pointer[thread_number][i];
      }

      average = sum / work_load_data_size;
 }


 void Construct_Random_Data(double *** pointer, int work_load_data_size){

      *pointer = new double * [5*num_threads];

      for(int i=0;i<num_threads;i++){

          (*pointer)[i] = new double [5*work_load_data_size];

          for(int k=0;k<work_load_data_size;k++){

              (*pointer)[i][k] = unif(re);
          }
      }
 }

 void Clear_Data_Memory(double *** pointer, int work_load_data_size){

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
