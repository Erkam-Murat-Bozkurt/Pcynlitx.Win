//HJM_Securities.cpp
//Routines to compute various security prices using HJM framework (via Simulation).
//Authors: Mark Broadie, Jatin Dewanwala
//Collaborator: Mikhail Smelyanskiy, Jike Chong, Intel
//Modified by Christian Bienia for the PARSEC Benchmark Suite

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "MT_Library_Headers.h"
#include "nr_routines.h"
#include "HJM.h"
#include "swaptions_pcynlitx.h"
#include "HJM_type.h"
#include <thread>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_THREAD 1024

#define NTHREAD 4

int NUM_TRIALS = DEFAULT_NUM_TRIALS;
int nThreads = NTHREAD;
int nSwaptions = 1;
int iN = 11;
//FTYPE dYears = 5.5;
int iFactors = 3;
parm *swaptions;

long seed = 1979; //arbitrary (but constant) default value (birth year of Christian Bienia)
long swaption_seed;

// =================================================
FTYPE *dSumSimSwaptionPrice_global_ptr;
FTYPE *dSumSquareSimSwaptionPrice_global_ptr;
int chunksize;

void worker_last(int tid){

  FTYPE pdSwaptionPrice[2];

  int beg, end, chunksize;
  if (tid < (nSwaptions % nThreads)) {
    chunksize = nSwaptions/nThreads + 1;
    beg = tid * chunksize;
    end = (tid+1)*chunksize;
  } else {
    chunksize = nSwaptions/nThreads;
    int offsetThread = nSwaptions % nThreads;
    int offset = offsetThread * (chunksize + 1);
    beg = offset + (tid - offsetThread) * chunksize;
    end = offset + (tid - offsetThread + 1) * chunksize;
  }

  if(tid == nThreads -1 )
    end = nSwaptions;

  for(int i=beg; i < end; i++) {
     int iSuccess = HJM_Swaption_Blocking(pdSwaptionPrice,  swaptions[i].dStrike,
                                       swaptions[i].dCompounding, swaptions[i].dMaturity,
                                       swaptions[i].dTenor, swaptions[i].dPaymentInterval,
                                       swaptions[i].iN, swaptions[i].iFactors, swaptions[i].dYears,
                                       swaptions[i].pdYield, swaptions[i].ppdFactors,
                                       swaption_seed+i, NUM_TRIALS, BLOCK_SIZE, 0);
     assert(iSuccess == 1);
     swaptions[i].dSimSwaptionMeanPrice = pdSwaptionPrice[0];
     swaptions[i].dSimSwaptionStdError = pdSwaptionPrice[1];
   }
}

int Elapsed_Time = 0;

int main(int argc, char *argv[])
{
	  int iSuccess = 0;

    int i,j;

	  FTYPE **factors=NULL;

    if(argc != 3)
    {
        std::cout << "\n\n   Usage: " << argv[0] << "  [Number of swaptions] [Number of simulations]" << std::endl;

        std::cout << "\n\n";

        exit(1);
    }

    nSwaptions = atoi(argv[1]); // Number of swaptions

    NUM_TRIALS = atoi(argv[2]); // Number of simulations


    if(nSwaptions < nThreads) {

       std::cout << "\n\n Error: Fewer swaptions than threads.";

       std::cout << "\n\n        The current thread number  : " << nThreads;

       std::cout << "\n\n        The current swaption number: " << nSwaptions;

       std::cout << "\n\n        The number of swaptions should be > number of threads" << std::endl;

       std::cout << "\n\n";

       exit(1);
    }

    swaption_seed = (long)(2147483647L * RanUnif(&seed));

	  if ((nThreads < 1) || (nThreads > MAX_THREAD))
	  {
		    fprintf(stderr,"Number of threads must be between 1 and %d.\n", MAX_THREAD);

        exit(1);
	  }

    // initialize input dataset
	  factors = dmatrix(0, iFactors-1, 0, iN-2);

    //the three rows store vol data for the three factors

    factors[0][0]= .01;

	  factors[0][1]= .01;

    factors[0][2]= .01;

    factors[0][3]= .01;

    factors[0][4]= .01;

    factors[0][5]= .01;

    factors[0][6]= .01;

    factors[0][7]= .01;

    factors[0][8]= .01;

    factors[0][9]= .01;

	  factors[1][0]= .009048;

    factors[1][1]= .008187;

    factors[1][2]= .007408;

    factors[1][3]= .006703;

    factors[1][4]= .006065;

    factors[1][5]= .005488;

    factors[1][6]= .004966;

    factors[1][7]= .004493;

    factors[1][8]= .004066;

    factors[1][9]= .003679;


    factors[2][0]= .001000;

    factors[2][1]= .000750;

    factors[2][2]= .000500;

    factors[2][3]= .000250;

    factors[2][4]= .000000;

    factors[2][5]= -.000250;

    factors[2][6]= -.000500;

    factors[2][7]= -.000750;

    factors[2][8]= -.001000;

    factors[2][9]= -.001250;

     // setting up multiple swaptions

     swaptions = (parm *)malloc(sizeof(parm)*nSwaptions);


     int k;

     for (i = 0; i < nSwaptions; i++) {

          swaptions[i].Id = i;

          swaptions[i].iN = iN;

          swaptions[i].iFactors = iFactors;

          swaptions[i].dYears = 5.0 + ((int)(60*RanUnif(&seed)))*0.25; //5 to 20 years in 3 month intervals

          swaptions[i].dStrike = 0.1 + ((int)(49*RanUnif(&seed)))*0.1; //strikes ranging from 0.1 to 5.0 in steps of 0.1

          swaptions[i].dCompounding = 0;

          swaptions[i].dMaturity = 1.0;

          swaptions[i].dTenor = 2.0;

          swaptions[i].dPaymentInterval = 1.0;

          swaptions[i].pdYield = dvector(0,iN-1);;
          swaptions[i].pdYield[0] = .1;
          for(j=1;j<=swaptions[i].iN-1;++j)
            swaptions[i].pdYield[j] = swaptions[i].pdYield[j-1]+.005;

          swaptions[i].ppdFactors = dmatrix(0, swaptions[i].iFactors-1, 0, swaptions[i].iN-2);
          for(k=0;k<=swaptions[i].iFactors-1;++k)
                 for(j=0;j<=swaptions[i].iN-2;++j)
                        swaptions[i].ppdFactors[k][j] = factors[k][j];
        }


	int threadIDs[nThreads];

  struct rusage usage;

  struct timeval start, end;

  int return_value = getrusage(RUSAGE_SELF,&usage);

  if(return_value!= 0){

     std::cout << "\n The usage data can not be obtain..\n";

     return 0;
  }

  start = usage.ru_utime;

  pcynlitx::Thread_Server Server;

  for (i = 0; i < nThreads; i++) {

       Server.Activate(i,worker);
  }

  for (i = 0; i < nThreads; i++) {

       Server.Join(i);
  }

  return_value = getrusage(RUSAGE_SELF, &usage);

  if(return_value!= 0){

     std::cout << "\n The usage data can not be obtain..\n";

     return 0;
  }

  end = usage.ru_utime;

  Elapsed_Time = end.tv_sec - start.tv_sec;

  std::cout << Elapsed_Time << std::endl;

	int threadID=0;

	worker_last(threadID);

  for (i = 0; i < nSwaptions; i++) {

      free_dvector(swaptions[i].pdYield, 0, swaptions[i].iN-1);

      free_dmatrix(swaptions[i].ppdFactors, 0, swaptions[i].iFactors-1, 0, swaptions[i].iN-2);
   }


   free(swaptions);

	return iSuccess;
}

void worker(pcynlitx::thds * thread_data){

     pcynlitx::TM_Client Manager(thread_data,"worker");

     int tid = Manager.Get_Thread_Number();

     FTYPE pdSwaptionPrice[2];

     int beg, end, chunksize;

     if (tid < (nSwaptions % nThreads)) {

         chunksize = nSwaptions/nThreads + 1;

         beg = tid * chunksize;

         end = (tid+1)*chunksize;

     }
     else {

        chunksize = nSwaptions/nThreads;

        int offsetThread = nSwaptions % nThreads;

        int offset = offsetThread * (chunksize + 1);

        beg = offset + (tid - offsetThread) * chunksize;

        end = offset + (tid - offsetThread + 1) * chunksize;
    }

    if(tid == nThreads -1 ){

       end = nSwaptions;
    }


   for(int i=beg; i < end; i++) {

      int iSuccess = HJM_Swaption_Blocking(pdSwaptionPrice,  swaptions[i].dStrike,
                                       swaptions[i].dCompounding, swaptions[i].dMaturity,
                                       swaptions[i].dTenor, swaptions[i].dPaymentInterval,
                                       swaptions[i].iN, swaptions[i].iFactors, swaptions[i].dYears,
                                       swaptions[i].pdYield, swaptions[i].ppdFactors,
                                       swaption_seed+i, NUM_TRIALS, BLOCK_SIZE, 0);
     assert(iSuccess == 1);
     swaptions[i].dSimSwaptionMeanPrice = pdSwaptionPrice[0];
     swaptions[i].dSimSwaptionStdError = pdSwaptionPrice[1];
   }
}
