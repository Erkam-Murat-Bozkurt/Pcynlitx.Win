
#include "Producer_Consumer_Std_Thread.h"
#include <random>
#include <sstream>
#include <cstring>

double ** data_pointer = nullptr;

void Construct_Random_Data(double *** pointer, int data_size);

void Compute_Mean_Value(int Thread_Number);

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

void Clear_Heap_Memory(double *** pointer, int data_size);

double lower_bound = 0;

double upper_bound = 10;

std::uniform_real_distribution<double> unif(lower_bound,upper_bound);

std::default_random_engine re;

int work_load_data_size = 0;



bool is_buffer_empty = true;

bool data_mismatch = false;

int Elapsed_Time = 0;

int num_threads = 0;

int Read_Line_Index = 0;

int Record_Line_Index = 0;

int buffer_index = 0;

std::mutex mtx_rd_serial;
std::mutex mtx_rd_parallel;
std::mutex mtx_wr_serial;
std::mutex mtx_wr_parallel;
std::mutex mtx_common;

std::condition_variable cv_rd;
std::condition_variable cv_wr;
std::condition_variable cv_br;


#define READER_LOOP_BREAK_CONDITION (Read_Line_Index >= Reader->Get_Data_Size())

#define WRITER_LOOP_BREAK_CONDITION (Record_Line_Index >= Recorder->Get_Record_Data_Size())

#define RECORDER_INDEX_INCREMENT_STATUS (Recorder->Get_Data_Record_Status(index)) && (Record_Line_Index < Recorder->Get_Record_Data_Size())

#define READER_THREAD_NUMBER num_threads/2

#define WRITER_THREAD_NUMBER (num_threads - (num_threads/2))

int entered_thread_number_in_barrier = 0;

int exited_reader_thread_number_in_end = 0;

int exited_writer_thread_number_in_end = 0;


int reader_thread_number_on_buffer = 0;

int writer_thread_number_on_buffer = 0;

bool writer_threads_break_condition = false;


int reader_thread_wait_number = 0;

int writer_thread_wait_number = 0;

std::string string_buffer = "";

int main(int argc, char ** argv){

    if(argc < 4){

       std::cout << "\n\n usage: " << argv[0] << " <thread number> <input file> <workload: data size>";

       std::cout << "\n\n";

       exit(0);
    }

    IntToCharTranslater Translater;

    num_threads = Translater.TranslateFromCharToInt(argv[1]);

    if((num_threads%2)!=0){

        std::cout << "\n\n The number of the threads must be selected as multiple of two..";

        std::cout << "\n\n";
    }


    Data_Reader Reader;

    Reader.SetFilePath(argv[2]);

    Reader.Receive_Reader_Thread_Number(READER_THREAD_NUMBER);

    Reader.Receive_Data();


    Data_Recorder Recorder;

    Recorder.Receive_Writer_Thread_Number(WRITER_THREAD_NUMBER);

    Recorder.Receive_Data_Size(Reader.Get_Data_Size());




    // THE CONSTRUCTION OF ARTIFICIAL WORKLOAD

    std::string dataLength = "";

    Convert_char_to_std_string(&dataLength,argv[3]);

    std::stringstream sd(dataLength);

    sd >> work_load_data_size;

    Construct_Random_Data(&data_pointer,work_load_data_size);

    // --------------------------------------------





    std::thread threads[num_threads];

    struct rusage usage;

    struct timeval start, end;

    int return_value = getrusage(RUSAGE_SELF,&usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    start = usage.ru_utime;


    for(int i=0;i<READER_THREAD_NUMBER;i++){

        threads[i] = std::thread(Readers_Function,&Reader,i,num_threads);
    }

    for(int i=READER_THREAD_NUMBER;i<num_threads;i++){

        threads[i] = std::thread(Writers_Function,&Recorder,i,num_threads);
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

    std::cout << Elapsed_Time << std::endl;

    for(int i=0;i<Reader.Get_Data_Size();i++){

        if(Data_Checking(Reader.Get_String_Data(i),Recorder.Get_String_Data(i))){

           std::cout << "\n There is data mismatch at index [" << i << "]..";

           break;
        }
    }

    return 0;
}

void Readers_Function(Data_Reader * Reader, int thread_number, int num_threads){

     std::unique_lock<std::mutex> serial_lck(mtx_rd_serial);

     serial_lck.unlock();

     std::unique_lock<std::mutex> parallel_lck(mtx_rd_parallel);

     parallel_lck.unlock();

     std::unique_lock<std::mutex> common_lck(mtx_common);

     common_lck.unlock();


     // START OF THE ENTRANCE BARRIER

     serial_lck.lock();

     entered_thread_number_in_barrier++;

     if(entered_thread_number_in_barrier < num_threads ){

        cv_br.wait(serial_lck);

        serial_lck.unlock();
     }
     else{

           serial_lck.unlock();
     }

     serial_lck.lock();

     entered_thread_number_in_barrier--;

     serial_lck.unlock();


     serial_lck.lock();

     if(entered_thread_number_in_barrier > 0){

         cv_br.notify_all();
     }

     serial_lck.unlock();


     // THE END OF THE ENTRANCE BARRIER

     int index = 0;

     std::string string_data = "";

     do {
            // STARTING OF THE PARALLEL EXECUTION REGION

            Compute_Mean_Value(thread_number); // Artificial workload

            // THE END OF THE PARALLEL EXECUTION


            serial_lck.lock();

            reader_thread_wait_number++;

            if(reader_thread_wait_number < ( READER_THREAD_NUMBER - exited_reader_thread_number_in_end)){

               // SERIAL EXECUTION BARRIER

               cv_rd.wait(serial_lck);

               serial_lck.unlock();


               serial_lck.lock();

               reader_thread_wait_number--;

               serial_lck.unlock();

            }
            else{

                  serial_lck.unlock();

                  // START OF THE SERIAL EXECUTION  ------------------------------------------------

                  // The critical section

                  common_lck.lock();

                  if(Read_Line_Index > Record_Line_Index){

                     reader_thread_number_on_buffer++;

                     if(writer_thread_number_on_buffer > 0){

                       cv_wr.notify_one();
                     }

                     cv_rd.wait(common_lck);

                     reader_thread_number_on_buffer--;

                     common_lck.unlock();
                  }
                  else{

                       common_lck.unlock();
                  }


                  common_lck.lock();

                  if(is_buffer_empty){

                     is_buffer_empty = false;

                     common_lck.unlock();


                     common_lck.lock();

                     string_data = Reader->Get_String_Data(Read_Line_Index);

                     Load_Data_To_Buffer(string_data);

                     Read_Line_Index++;

                     cv_wr.notify_one();

                     cv_rd.wait(common_lck);

                     common_lck.unlock();
                  }
                  else{

                         if(Read_Line_Index >= 1){

                            Read_Line_Index--;
                         }


                         cv_wr.notify_one();

                         cv_rd.wait(common_lck);

                         common_lck.unlock();

                  }

                  // The end of critical section

                  // THE END OF SERIAL EXECUTION -------------------------------------------------


                  serial_lck.lock();

                  cv_rd.notify_one();   // Notifies a thread waiting

                  cv_rd.wait(serial_lck);

                  serial_lck.unlock();



                  serial_lck.lock();

                  reader_thread_wait_number--;

                  serial_lck.unlock();
           }


           parallel_lck.lock();

           index = Read_Line_Index;

           parallel_lck.unlock();


    }while(!READER_LOOP_BREAK_CONDITION);


    parallel_lck.lock();

    exited_reader_thread_number_in_end++;

    parallel_lck.unlock();


    do {

         if(exited_reader_thread_number_in_end < READER_THREAD_NUMBER ){

            cv_rd.notify_one();
         }

    } while(exited_reader_thread_number_in_end < READER_THREAD_NUMBER );


    do {

         if(exited_writer_thread_number_in_end < WRITER_THREAD_NUMBER ){

            cv_wr.notify_one();
         }

    } while(exited_writer_thread_number_in_end < WRITER_THREAD_NUMBER );

}



// --------------------------------------------------------------------------------

//  Writer threads function

void Writers_Function(Data_Recorder * Recorder, int thread_number, int num_threads){

     std::unique_lock<std::mutex> serial_lck(mtx_wr_serial);

     serial_lck.unlock();


     std::unique_lock<std::mutex> parallel_lck(mtx_wr_parallel);

     parallel_lck.unlock();


     std::unique_lock<std::mutex> common_lck(mtx_common);

     common_lck.unlock();

     // START OF THE ENTRANCE BARRIER


     serial_lck.lock();

     entered_thread_number_in_barrier++;

     if(entered_thread_number_in_barrier < num_threads){

        cv_br.wait(serial_lck);

        serial_lck.unlock();
     }
     else{

            serial_lck.unlock();
     }


     serial_lck.lock();

     entered_thread_number_in_barrier--;

     serial_lck.unlock();



     serial_lck.lock();

     if(entered_thread_number_in_barrier > 0){

        cv_br.notify_all();
     }

     serial_lck.unlock();


     // THE END OF THE ENTRANCE BARRIER

     int index = 0;

     std::string string_data = "";

     do {
            // STARTING OF THE PARALLEL EXECUTION REGION

            Compute_Mean_Value(thread_number); // Artificial workload

            // THE END OF THE PARALLEL EXECUTION


            serial_lck.lock();

            writer_thread_wait_number++;

            if(writer_thread_wait_number < ( WRITER_THREAD_NUMBER - exited_writer_thread_number_in_end )){

              // SERIAL EXECUTION BARRIER

               cv_wr.wait(serial_lck);

               serial_lck.unlock();


               serial_lck.lock();

               writer_thread_wait_number--;

               serial_lck.unlock();

             }
             else{

                    serial_lck.unlock();

                    // START OF THE SERIAL EXECUTION  ------------------------------------------------

                    // The critical section


                    common_lck.lock();

                    if(Record_Line_Index >= Read_Line_Index){

                       writer_thread_number_on_buffer++;

                       if(reader_thread_number_on_buffer > 0){

                          cv_rd.notify_one();
                       }

                       cv_wr.wait(common_lck);

                       writer_thread_number_on_buffer--;

                       common_lck.unlock();
                    }
                    else{

                         common_lck.unlock();
                    }



                    if(WRITER_LOOP_BREAK_CONDITION){

                       break;
                    }


                    common_lck.lock();

                    if(is_buffer_empty){

                       Record_Line_Index--;

                       cv_rd.notify_one();

                       cv_wr.wait(common_lck);

                       common_lck.unlock();

                    }
                    else{

                            string_data = Get_Data_From_Buffer();

                            Recorder->Set_Record_Data(string_data,Record_Line_Index);

                            Record_Line_Index++;

                            is_buffer_empty = true;

                            cv_rd.notify_one();

                            cv_wr.wait(common_lck);

                            common_lck.unlock();
                    }



                    // THE END OF SERIAL EXECUTION -------------------------------------------------


                    serial_lck.lock();

                    cv_wr.notify_one();   // Notifies a thread waiting

                    cv_wr.wait(serial_lck);

                    serial_lck.unlock();


                    serial_lck.lock();

                    writer_thread_wait_number--;

                    serial_lck.unlock();
            }


            parallel_lck.lock();

            index = Record_Line_Index;

            parallel_lck.unlock();


     }while(!WRITER_LOOP_BREAK_CONDITION);



     parallel_lck.lock();

     exited_writer_thread_number_in_end++;

     parallel_lck.unlock();


     do {

         if(exited_reader_thread_number_in_end < READER_THREAD_NUMBER ){

            cv_rd.notify_one();
         }

     } while(exited_reader_thread_number_in_end < READER_THREAD_NUMBER );

     do {

          if(exited_writer_thread_number_in_end < WRITER_THREAD_NUMBER ){

             cv_wr.notify_one();
          }

     } while(exited_writer_thread_number_in_end < WRITER_THREAD_NUMBER );
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
