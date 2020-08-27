#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "MT_Library_Headers.h"

#define THREAD_NUMBER 16

int Elapsed_Time = 0;

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

cv::Mat * image_list_pointer = nullptr;

cv::Mat * noisy_image_list_pointer = nullptr;

int main(int argc, char ** argv){

    if(argc != 3) {

       std::cout << "\n\n   Usage: " << argv[0] << " [Image File Path]  [Image Number] " << std::endl;

       std::cout << "\n\n";

       exit(1);
    }

    std::string img_number = "";

    Convert_char_to_std_string(&img_number,argv[2]);

    std::stringstream s(img_number);

    int image_number = 0;

    s >> image_number;

    cv::Mat kernel;

    image_list_pointer = new cv::Mat [image_number];

    noisy_image_list_pointer = new cv::Mat [image_number];

    image_list_pointer[0] = cv::imread(argv[1]);

    cv::Mat noise(image_list_pointer[0].size(),image_list_pointer[0].type());

    float m = (15,15,15);

    float sigma = (25,25,25);

    cv::randn(noise, m, sigma); //mean and variance

    for(int i=1;i<image_number;i++){

        image_list_pointer[i] = image_list_pointer[0];
    }

    for(int i=0;i<image_number;i++){

        image_list_pointer[i] = image_list_pointer[i] + noise;
    }

    for(int i=0;i<image_number;i++){

        noisy_image_list_pointer[i] = image_list_pointer[i].clone();
    }

    struct rusage usage;

    struct timeval start, end;

    int return_value = getrusage(RUSAGE_SELF,&usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    start = usage.ru_utime;


    pcynlitx::Thread_Server Server;

    Server.Loop_Interval_IT.set_loop_interval(image_number);

    for(int i=0;i<THREAD_NUMBER;i++){

        Server.Activate(i,Filter_Images);
    }

    for(int i=0;i<THREAD_NUMBER;i++){

        Server.Join(i);
    };

    return_value = getrusage(RUSAGE_SELF, &usage);

    if(return_value!= 0){

       std::cout << "\n The usage data can not be obtain..\n";

       return 0;
    }

    end = usage.ru_utime;

    Elapsed_Time = end.tv_sec - start.tv_sec;

    std::cout << Elapsed_Time << std::endl;

    delete [] image_list_pointer;

    delete [] noisy_image_list_pointer;

    return 0;
}


void Filter_Images(pcynlitx::thds * thread_data){

     pcynlitx::TM_Client Manager(thread_data,"Filter_Images");

     pcynlitx::Loop_Interval_Client Loop_Interval_IT(thread_data);

     int thread_number = Manager.Get_Thread_Number();

     int loop_interval = Loop_Interval_IT.get_loop_interval();

     for(int i=0;i<loop_interval;i++){

         int kernel_size = 5;

         cv::Mat kernel = cv::Mat::ones( kernel_size, kernel_size, CV_32F )

                                / (float)(kernel_size*kernel_size);

         cv::filter2D(image_list_pointer[i], noisy_image_list_pointer[i],image_list_pointer[i].depth(),

         kernel,cv::Point(-1,-1));
      }

      Manager.Exit();
}

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer){

    int string_length = strlen(cstring_pointer);

    for(int i=0;i<string_length;i++){

        *string_line = *string_line + cstring_pointer[i];
    }
}
