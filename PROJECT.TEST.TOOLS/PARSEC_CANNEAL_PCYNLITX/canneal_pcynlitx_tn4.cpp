// main.cpp
//
// Created by Daniel Schwartz-Narbonne on 13/04/07.
// Modified by Christian Bienia
//
// Copyright 2007-2008 Princeton University
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.


 #include <iostream>
 #include <math.h>
 #include <stdlib.h>
 #include <string.h>
 #include <string>
 #include <unistd.h>
 #include <vector>
 #include <thread>
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <unistd.h>
 #include "annealer_types.h"
 #include "annealer_thread.h"
 #include "netlist.h"
 #include "rng.h"
 #include "MT_Library_Headers.h"
 #include "Cpp_FileOperations.h"
 #include "IntToCharTranslater.h"

 #define NSWAPS 4

 #define TEMP 10

 #define NTHREADS 4;

 int Elapsed_Time = 0;

 int main(int argc, char ** argv){

	   struct rusage usage;

	   struct timeval start, end;

	   int return_value = getrusage(RUSAGE_SELF,&usage);

	   if(return_value!= 0){

		   std::cout << "\n The usage data can not be obtain..\n";

		   return 0;
	   }

	   start = usage.ru_utime;

	   srandom(3);

     if(argc != 2 && argc != 3) {

        std::cout << "\n";

        std::cout << "Usage: " << argv[0] << " [Netlist Input File]  [Optional :The number of temperature steps]" << std::endl;

        std::cout << "\n";

        exit(1);
     }

	   //argument 1 is numthreads
	   int num_threads = NTHREADS;

     std::cout << "\n";

	   std::cout << "Threadcount: " << num_threads << std::endl;

	   //argument 2 is the num moves / temp
	   int swaps_per_temp = NSWAPS;

     std::cout << swaps_per_temp << " swaps per temperature step" << std::endl;

	   //argument 3 is the start temp
	   int start_temp =  TEMP;
	   std::cout << "start temperature: " << start_temp << std::endl;

	   //argument 4 is the netlist filename
     std::string filename = "";

     for(int i=0;i<strlen(argv[1]);i++){

        filename.append(1,argv[1][i]);
     };

	   std::cout << "netlist filename: " << filename << std::endl;

	   //argument 5 (optional) is the number of temperature steps before termination
	   int number_temp_steps = -1;

     if(argc == 3) {

        number_temp_steps = atoi(argv[2]);

        std::cout << "number of temperature steps: " << number_temp_steps << std::endl;
     }

	   //now that we've read in the commandline, run the program
	   netlist my_netlist(filename);

	   annealer_thread a_thread(&my_netlist,num_threads,swaps_per_temp,start_temp,number_temp_steps);

     pcynlitx::Thread_Server Server;

     Server.data_pointer_IT.receive_address(&a_thread);

     for(int i=0;i<num_threads;i++){

        Server.Activate(i,entry_pt);
     }

     for(int i=0;i<num_threads;i++){

         Server.Join(i);
     };

     std::cout << "Final routing is: " << my_netlist.total_routing_cost() << std::endl;

     std::cout << "\n";

 		 return_value = getrusage(RUSAGE_SELF, &usage);

     if(return_value!= 0){

        std::cout << "\n The usage data can not be obtain..\n";

        return 0;
     }

     end = usage.ru_utime;

     Elapsed_Time = end.tv_sec - start.tv_sec;

     IntToCharTranslater Translater;

     Cpp_FileOperations FileManager;

     FileManager.SetFilePath("Test_Record_File");

     FileManager.FileOpen(Af);

     FileManager.WriteToFile(Translater.Translate(Elapsed_Time));

     FileManager.FileClose();

     return 0;
 }


 void entry_pt(pcynlitx::thds * thread_data){

      pcynlitx::TM_Client Manager(thread_data,"entry_pt");

      pcynlitx::data_pointer_Client Pointer(thread_data);

      Pointer.get_address()->Run();

      Manager.Exit();
 }
