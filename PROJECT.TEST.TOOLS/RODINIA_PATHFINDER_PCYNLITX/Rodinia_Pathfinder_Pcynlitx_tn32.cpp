
 #include "MT_Library_Headers.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <assert.h>
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <unistd.h>
 #include "timer.h"


 #define M_SEED 9

 #define IN_RANGE(x, min, max)   ((x)>=(min) && (x)<=(max))
 #define CLAMP_RANGE(x, min, max) x = (x<(min)) ? min : ((x>(max)) ? max : x )
 #define MIN(a, b) ((a)<=(b) ? (a) : (b))


 int num_threads = 32;

 int Elapsed_Time = 0;

 int rows = 0, cols = 0;

 void fatal(char *s){

     fprintf(stderr, "error: %s\n", s);
 }

 int main(int argc, char ** argv){

     if(argc < 3){

        std::cout << "\n\n usage: " << argv[0] << " <Number of Columns> <Number of rows>";

        std::cout << "\n\n";

        exit(0);
     }

     cols = atoi(argv[1]);
     rows = atoi(argv[2]);

     pcynlitx::Thread_Server Server;

     struct rusage usage;

     struct timeval start, end;

     int return_value = getrusage(RUSAGE_SELF,&usage);

     if(return_value!= 0){

        std::cout << "\n The usage data can not be obtain..\n";

        return 0;
     }

     start = usage.ru_utime;

     for(int i=0;i<num_threads;i++){

         Server.Activate(i,run);
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

    std::cout << Elapsed_Time << std::endl;

    return 0;
 }


 void run(pcynlitx::thds * thread_data){

      pcynlitx::TM_Client Manager(thread_data,"run");

      int * data;
      int ** wall;
      int * result;

      data = new int [rows*cols];
      wall = new int * [rows];

      for(int n=0; n<rows; n++){

         wall[n]=data+cols*n;
      }

      result = new int [cols];

      int seed = M_SEED;

      srand(seed);

      for(int i = 0; i < rows; i++){

         for(int j = 0; j < cols; j++){

             wall[i][j] = rand() % 10;
         }
      }

      for(int j = 0; j < cols; j++){

          result[j] = wall[0][j];
      }

      unsigned long long cycles;

      int *src, *dst, *temp;
      int min;

      dst = result;
      src = new int [cols];

      for (int t = 0; t < rows-1; t++) {
          temp = src;
          src = dst;
          dst = temp;

          for(int n = 0; n < cols; n++){
            min = src[n];
            if (n > 0)
              min = MIN(min, src[n-1]);
            if (n < cols-1)
              min = MIN(min, src[n+1]);
            dst[n] = wall[t+1][n]+min;
          }
      }

      delete [] data;
      delete [] wall;
      delete [] dst;
      delete [] src;

      Manager.Exit();
 }
