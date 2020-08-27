
#include "Data_Reader.h"
#include "Data_Recorder.h"
#include "IntToCharTranslater.h"
#include <string>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>

void Readers_Function(Data_Reader * Reader, int thread_number, int num_threads);
void Writers_Function(Data_Recorder * Recorder, int thread_number, int num_threads);
bool Data_Checking(std::string reader_data, std::string recorder_data);
void Load_Data_To_Buffer(std::string data);
std::string Get_Data_From_Buffer();
