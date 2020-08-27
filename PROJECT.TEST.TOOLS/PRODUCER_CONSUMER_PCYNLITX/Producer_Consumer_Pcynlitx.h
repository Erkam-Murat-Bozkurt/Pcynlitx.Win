
#include "Data_Reader.h"
#include "Data_Recorder.h"
#include "IntToCharTranslater.h"
#include <string>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <iostream>
#include <mutex>

bool Data_Checking(std::string reader_data, std::string recorder_data);
void Load_Data_To_Buffer(std::string data);
std::string Get_Data_From_Buffer();
