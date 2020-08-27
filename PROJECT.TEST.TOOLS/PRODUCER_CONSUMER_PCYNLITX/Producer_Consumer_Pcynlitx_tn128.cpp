

#include "MT_Library_Headers.h"
#include "Producer_Consumer_Pcynlitx.h"
#include <string>
#include <random>
#include <sstream>
#include <cstring>
#include "Cpp_FileOperations.h"
#include "IntToCharTranslater.h"

double ** data_pointer = nullptr;

void Construct_Random_Data(double *** pointer, int data_size);

void Compute_Mean_Value(int Thread_Number);

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Clear_Heap_Memory(double *** pointer, int data_size);

double lower_bound = 0;

double upper_bound = 10;

std::uniform_real_distribution<double> unif(lower_bound,upper_bound);

std::default_random_engine re;

bool data_mismatch = false;

int Elapsed_Time = 0;

int num_threads = 128;

int Read_Line_Index = 0;

int Record_Line_Index = 0;

int Data_Size = 0;

int work_load_data_size = 0;

int exited_reader_thread_number_in_end = 0;

int exited_writer_thread_number_in_end = 0;

bool writer_threads_break_condition = false;

std::string string_buffer = "";

std::string string_data = "";

#define READER_LOOP_BREAK_CONDITION (Read_Line_Index >= Reader.Get_Data_Size())

#define WRITER_LOOP_BREAK_CONDITION writer_threads_break_condition

#define READER_THREAD_NUMBER num_threads/2

#define WRITER_THREAD_NUMBER (num_threads - (num_threads/2))

#define THREAD_SEARCH_CONDITION (exited_reader_thread_number_in_end < READER_THREAD_NUMBER) || (exited_writer_thread_number_in_end < WRITER_THREAD_NUMBER)

int main(int argc, char ** argv){

    if(argc < 3){

       std::cout << "\n\n usage: " << argv[0] << " <input file> <workload: data size>";

       std::cout << "\n\n";

       exit(0);
    }



    // THE CONSTRUCTION OF ARTIFICIAL WORKLOAD

    std::string dataLength = "";

    Convert_char_to_std_string(&dataLength,argv[2]);

    std::stringstream sd(dataLength);

    sd >> work_load_data_size;

    Construct_Random_Data(&data_pointer,work_load_data_size);

    // --------------------------------------------



    pcynlitx::Thread_Server Server;

    Server.Data_Reader_IT.SetFilePath(argv[1]);

    Server.Data_Reader_IT.Receive_Reader_Thread_Number(READER_THREAD_NUMBER);

    Server.Data_Recorder_IT.Receive_Writer_Thread_Number(WRITER_THREAD_NUMBER);

    Server.Data_Reader_IT.Receive_Data();

    Server.Data_Recorder_IT.Receive_Data_Size(Server.Data_Reader_IT.Get_Data_Size());

    Data_Size =  Server.Data_Reader_IT.Get_Data_Size();

    struct rusage usage;

    struct timeval start, end;

    int return_value = getrusage(RUSAGE_SELF,&usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    start = usage.ru_utime;

    for(int i=0;i<READER_THREAD_NUMBER;i++){

        Server.Activate(i,Readers_Function);
    }

    for(int i=READER_THREAD_NUMBER;i<num_threads;i++){

        Server.Activate(i,Writers_Function);
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

    Clear_Heap_Memory(&data_pointer,work_load_data_size);

    int remaining_data = 0;

    for(int i=0;i<Server.Data_Reader_IT.Get_Data_Size();i++){

        remaining_data = Server.Data_Reader_IT.Get_Data_Size() -i;

        if(remaining_data < num_threads){

           break;
        }

        if(Data_Checking(Server.Data_Reader_IT.Get_String_Data(i),Server.Data_Recorder_IT.Get_String_Data(i))){

           return 1;
        }
    }


    bool readers_acess_order_violation = Server.Data_Reader_IT.Check_Readers_Acess_Order_Violation();

    bool writers_acess_order_violation = Server.Data_Recorder_IT.Check_Writers_Acess_Order_Violation();


    if(readers_acess_order_violation){

       return 1;
    }

    if(writers_acess_order_violation){

       return 1;
    }


    std::cout << Elapsed_Time << std::endl;

    return 0;
}


 void Readers_Function(pcynlitx::thds * thread_data){

      pcynlitx::TM_Client Manager(thread_data,"Readers_Function");

      pcynlitx::Data_Reader_Client Reader(thread_data);


      Manager.lock();

      int thread_number = Manager.Get_Thread_Number();

      Manager.unlock();


      // START OF THE ENTRANCE BARRIER

      Manager.wait("Readers_Function");


      // THE END OF THE ENTRANCE BARRIER

      int index = 0;


      do {

           // STARTING OF THE PARALLEL EXECUTION REGION

           if(READER_LOOP_BREAK_CONDITION){

              break;
           }

           Compute_Mean_Value(thread_number); // Artificial workload

           // The end of the parallel execution region



           Manager.start_serial(0,READER_THREAD_NUMBER,thread_number);


           if(READER_LOOP_BREAK_CONDITION){

              break;
           }

           // THE END OF THE PARALLEL EXECUTION


           // START OF THE SERIAL EXECUTION  ------------------------------------------------

           // The critical section


           Reader.Set_Acess_Order(thread_number);


           Manager.lock();

           if(Read_Line_Index > Record_Line_Index){

              Manager.unlock();
           }
           else{

                string_data = Reader.Get_String_Data(Read_Line_Index);

                Load_Data_To_Buffer(string_data);

                Read_Line_Index++;

                Manager.unlock();
           }



            // The end of critical section

            // THE END OF SERIAL EXECUTION -------------------------------------------------



            if(READER_LOOP_BREAK_CONDITION){

              break;
            }


            Manager.end_serial(0,READER_THREAD_NUMBER,thread_number);


     }while(!READER_LOOP_BREAK_CONDITION);


     Manager.lock();

     writer_threads_break_condition = true;

     exited_reader_thread_number_in_end++;

     Manager.unlock();

     do {

          if(THREAD_SEARCH_CONDITION){

             for(int i=0;i<num_threads;i++){

                 if(i!=thread_number){

                    Manager.rescue(i);
                 }
             }
          }

          Manager.yield();

     } while(THREAD_SEARCH_CONDITION);


    Manager.Exit();
 }


// --------------------------------------------------------------------------------

//  Writer threads function


void Writers_Function(pcynlitx::thds * thread_data){

     pcynlitx::TM_Client Manager(thread_data,"Writers_Function");

     pcynlitx::Data_Recorder_Client Recorder(thread_data);


     Manager.lock();

     int thread_number = Manager.Get_Thread_Number();

     Manager.unlock();


     Manager.wait("Writers_Function");


     int index = 0;

     std::string string_data = "";

     do {

          if(WRITER_LOOP_BREAK_CONDITION){

             break;
          }


          // THE END OF THE PARALLEL EXECUTION


          Manager.start_serial(READER_THREAD_NUMBER,num_threads,thread_number);


          if(WRITER_LOOP_BREAK_CONDITION){

             break;
          }


          // START OF THE SERIAL EXECUTION  ------------------------------------------------

          // The critical section


          Recorder.Set_Acess_Order(thread_number);


          Manager.lock();

          if(Read_Line_Index <= Record_Line_Index){

             Manager.unlock();
          }
          else{
                  string_data = Get_Data_From_Buffer();

                  Recorder.Set_Record_Data(string_data,Record_Line_Index);

                  Record_Line_Index++;

                  Manager.unlock();
          }



          if(WRITER_LOOP_BREAK_CONDITION){

             break;
          }


          Manager.end_serial(READER_THREAD_NUMBER,num_threads,thread_number);


          // THE END OF SERIAL EXECUTION -------------------------------------------------

     }while(!WRITER_LOOP_BREAK_CONDITION);


     Manager.lock();

     exited_writer_thread_number_in_end++;

     Manager.unlock();

     do{

       if(THREAD_SEARCH_CONDITION){

          for(int i=0;i<num_threads;i++){

              if(i!=thread_number){

                 Manager.rescue(i);
              }
          }

          Manager.yield();

       }

    }while(THREAD_SEARCH_CONDITION);

    Manager.Exit();
 }

 void Load_Data_To_Buffer(std::string data){

      string_buffer = "";

      string_buffer = data;
 }

 std::string Get_Data_From_Buffer()
 {
      return string_buffer;
 }


 bool Data_Checking(std::string reader_data, std::string recorder_data){

      data_mismatch = false;

      if(reader_data != recorder_data){

         data_mismatch = true;
      }

      return data_mismatch;
 }


void Compute_Mean_Value(int thread_number){

     int sum = 0, average = 0;

     for(int i=0;i<work_load_data_size;i++){

         sum = sum + data_pointer[thread_number][i];
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

void Clear_Heap_Memory(double *** pointer, int work_load_data_size){

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
