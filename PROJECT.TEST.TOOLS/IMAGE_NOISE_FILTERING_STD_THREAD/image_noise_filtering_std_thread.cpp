
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include <sstream>

int Elapsed_Time = 0;

cv::Mat * image_list_pointer = nullptr;

cv::Mat * noisy_image_list_pointer = nullptr;

void Filter_Images(int image_number);

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer);

int main(int argc, char** argv)
{

  if(argc != 4) {

     std::cout << "\n\n   Usage: " << argv[0] << " [Thread Number] [Image File Path]  [Image Number] " << std::endl;

     std::cout << "\n\n";

     exit(1);
  }

  std::string th_number = "";

  Convert_char_to_std_string(&th_number,argv[1]);

  std::stringstream tn_s(th_number);

  int threadNumber = 0;

  tn_s >> threadNumber;


  std::string img_number = "";

  Convert_char_to_std_string(&img_number,argv[3]);

  std::stringstream img_s(img_number);

  int image_number = 0;

  img_s >> image_number;


  image_list_pointer = new cv::Mat [image_number];

  noisy_image_list_pointer = new cv::Mat [image_number];

  image_list_pointer[0] = cv::imread(argv[2]);

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

  std::thread threads[threadNumber];

  struct rusage usage;

  struct timeval start, end;

  int return_value = getrusage(RUSAGE_SELF,&usage);

  if(return_value!= 0){

     std::cout << "\n The usage data can not be obtain..\n";

     return 0;
  }

  start = usage.ru_utime;

  for(int i=0;i<threadNumber;i++){

      threads[i] = std::thread(Filter_Images,image_number);
  }

  for(int i=0;i<threadNumber;i++){

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

  delete [] image_list_pointer;

  delete [] noisy_image_list_pointer;

  return 0;
}

void Filter_Images(int image_number)
{
     for(int i=0;i<image_number;i++){

         int kernel_size = 5;

         cv::Mat kernel = cv::Mat::ones( kernel_size, kernel_size, CV_32F )

                                / (float)(kernel_size*kernel_size);

         cv::filter2D(image_list_pointer[i], noisy_image_list_pointer[i],image_list_pointer[i].depth(),

         kernel,cv::Point(-1,-1));
     }
}

void Convert_char_to_std_string(std::string * string_line, char * cstring_pointer){

    int string_length = strlen(cstring_pointer);

    for(int i=0;i<string_length;i++){

        *string_line = *string_line + cstring_pointer[i];
    }
}
