/*
 * =====================================================================================
 *
 *       Filename:  suite.c
 *
 *    Description:  The main wrapper for the suite
 *
 *        Version:  1.0
 *        Created:  10/22/2009 08:40:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Liang Wang (lw2aw), lw2aw@virginia.edu
 *        Company:  CS@UVa
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include "common.h"
#include "MT_Library_Headers.h"

#define NTHREAD 32

// A typical command input : ./rodinia_lud_pcynlitx_tn4 -n 32 -i 512.dat

static int do_verify = 0;

int omp_num_threads = NTHREAD;

static struct option long_options[] = {
  /* name, has_arg, flag, val */
  {"input", 1, NULL, 'i'},
  {"size", 1, NULL, 's'},
  {"verify", 0, NULL, 'v'},
  {0,0,0,0}
};

extern void lud_pcynlitx_function(pcynlitx::thds * thread_data);

int Elapsed_Time = 0;

int main ( int argc, char *argv[] ){

    int matrix_dim = 32; /* default size */

    int opt, option_index=0;

    func_ret_t ret;

    const char *input_file = NULL;

    float ** m  = new float * [5*NTHREAD];

    stopwatch sw;


    while ((opt = getopt_long(argc, argv, "::vs:n:i:",
                            long_options, &option_index)) != -1 ) {
    switch(opt){
    case 'i':
      input_file = optarg;
      break;
    case 'v':
      do_verify = 1;
      break;
    case 'n':
      omp_num_threads = atoi(optarg);
      break;
    case 's':
      matrix_dim = atoi(optarg);
      printf("Generate input matrix internally, size =%d\n", matrix_dim);
      // fprintf(stderr, "Currently not supported, use -i instead\n");
      // fprintf(stderr, "Usage: %s [-v] [-s matrix_size|-i input_file]\n", argv[0]);
      // exit(EXIT_FAILURE);
      break;
    case '?':
      fprintf(stderr, "invalid option\n");
      break;
    case ':':
      fprintf(stderr, "missing argument\n");
      break;
    default:
      fprintf(stderr,"\n\n  Usage: %s [-v] [-s matrix_size|-i input_file]\n",argv[0]);
      exit(EXIT_FAILURE);
    }
    }

  if ( (optind < argc) || (optind == 1)) {
    fprintf(stderr, "Usage: %s [-v] [-n no. of threads] [-s matrix_size|-i input_file]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (input_file) {
    ret = create_matrix_from_file(&m[0], input_file, &matrix_dim);
    if (ret != RET_SUCCESS) {
      m[0] = NULL;
      fprintf(stderr, "error create matrix from file %s\n", input_file);
      exit(EXIT_FAILURE);
    }
  }

  else if (matrix_dim) {
    printf("Creating matrix internally size=%d\n", matrix_dim);
    ret = create_matrix(&m[0], matrix_dim);
    if (ret != RET_SUCCESS) {
      m[0] = NULL;
      fprintf(stderr, "error create matrix internally size=%d\n", matrix_dim);
      exit(EXIT_FAILURE);
    }
  }

  else {
    printf("No input file specified!\n");
    exit(EXIT_FAILURE);
  }

  if (true){

    for(int i=1;i<NTHREAD+1;i++){

        matrix_duplicate(m[0], &m[i],matrix_dim);
    }
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

  Server.data_holder_IT.receive_total_thread_number(NTHREAD);

  for(int i=0;i<NTHREAD+1;i++){

      Server.data_holder_IT.set_Thread_Matrix(i,m[i]);
  }

  Server.data_holder_IT.set_Matrix_Size(matrix_dim);

  Server.data_holder_IT.set_duplicated_matrix(m[NTHREAD]);

  for(int i=0;i<NTHREAD;i++){

      Server.Activate(i,lud_pcynlitx_function);
  }

  for(int i=0;i<NTHREAD;i++){

      Server.Join(i);
  }

  return_value = getrusage(RUSAGE_SELF, &usage);

  if(return_value!= 0){

     std::cout << "\n The usage data can not be obtain..\n";

     return 0;
  }

  end = usage.ru_utime;

  Elapsed_Time = end.tv_sec - start.tv_sec;

  for(int i=0;i<NTHREAD+1;i++){

      free(m[i]);
  }

  delete [] m;

  std::cout << Elapsed_Time << std::endl;

  return EXIT_SUCCESS;
}
