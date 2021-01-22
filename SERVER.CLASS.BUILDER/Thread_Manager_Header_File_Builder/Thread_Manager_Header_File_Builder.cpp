
/*

Copyright ©  2021,  Erkam Murat Bozkurt

This file is part of the research project which is carried by Erkam Murat Bozkurt.

This is a free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation
either version 3 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include "Thread_Manager_Header_File_Builder.h"

Thread_Manager_Header_File_Builder::Thread_Manager_Header_File_Builder(){

};

Thread_Manager_Header_File_Builder::Thread_Manager_Header_File_Builder(const Thread_Manager_Header_File_Builder & orig){

};

Thread_Manager_Header_File_Builder::~Thread_Manager_Header_File_Builder(){

};

void Thread_Manager_Header_File_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->Data_Manager_Header_Builder.Receive_Descriptor_File_Reader(Pointer);
}

void Thread_Manager_Header_File_Builder::Build_Thread_Manager_Header_File(){

     this->Data_Manager_Header_Builder.Build_Thread_Data_Manager_Header_File();

     int Thread_Function_Number = this->Reader_Pointer->Get_Thread_Function_Number();

     int Thread_Number = this->Reader_Pointer->Get_Thread_Number();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.SetFilePath("Thread_Manager.h");

     this->FileManager.FileOpen(RWCf);

     this->FileManager.WriteToFile("\n #ifndef THREAD_MANAGER_H");

     this->FileManager.WriteToFile("\n #define THREAD_MANAGER_H");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #include \"Thread_Data_Manager.h\"");

     this->FileManager.WriteToFile("\n #include \"Thread_Locker.h\"");

     this->FileManager.WriteToFile("\n #include <thread>");

     this->FileManager.WriteToFile("\n #include <mutex>");

     this->FileManager.WriteToFile("\n #include <iostream>");

     this->FileManager.WriteToFile("\n #include <string>");

     this->FileManager.WriteToFile("\n #include <cstdlib>");

     this->FileManager.WriteToFile("\n #include <chrono>");

     this->FileManager.WriteToFile("\n #include <condition_variable>");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n namespace ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("{");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n   class Thread_Manager");

     this->FileManager.WriteToFile("\n   {");

     this->FileManager.WriteToFile("\n   public:");

     this->FileManager.WriteToFile("\n    Thread_Manager();");

     this->FileManager.WriteToFile("\n    Thread_Manager(const Thread_Manager & orig);");

     this->FileManager.WriteToFile("\n    virtual ~Thread_Manager();");

     this->FileManager.WriteToFile("\n    void lock();");

     this->FileManager.WriteToFile("\n    void unlock();");

     this->FileManager.WriteToFile("\n    void barrier_wait();");

     this->FileManager.WriteToFile("\n    void wait(int Number);");

     this->FileManager.WriteToFile("\n    void switch_wait(int Number);");

     this->FileManager.WriteToFile("\n    void start_serial(int start_number, int end_number, int thread_number);");

     this->FileManager.WriteToFile("\n    void end_serial(int start_number, int end_number, int thread_number);");

     this->FileManager.WriteToFile("\n    void wait(int Number, int Rescuer_Thread);");

     this->FileManager.WriteToFile("\n    void wait_until_exit(int Number, int Rescuer_Thread);");

     this->FileManager.WriteToFile("\n    void wait(std::string Function_Name, int Rescuer_Thread_Number);");

     this->FileManager.WriteToFile("\n    void wait(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    void Exit();");

     this->FileManager.WriteToFile("\n    void rescue(int Number);");

     this->FileManager.WriteToFile("\n    void rescue(int Number, int Rescuer_Thread_Number);");

     this->FileManager.WriteToFile("\n    void rescue(std::string Function_Name, int Rescuer_Thread_Number);");

     this->FileManager.WriteToFile("\n    void Receive_Thread_ID(std::string Function_Name, int Thread_Number);");

     this->FileManager.WriteToFile("\n    int Get_Thread_Number();");

     this->FileManager.WriteToFile("\n    int Get_Operational_Thread_Number() const;");

     this->FileManager.WriteToFile("\n    bool Get_Thread_Block_Status(int Thread_Number) const;");

     this->FileManager.WriteToFile("\n    void yield();");

     this->FileManager.WriteToFile("\n   private:");

     this->FileManager.WriteToFile("\n    void Clear_Send_Rescue_Signal_Conditions();");

     this->FileManager.WriteToFile("\n    void Check_Is_There_Waiting_Until_Exit();");

     this->FileManager.WriteToFile("\n    std::condition_variable cv;");

     this->FileManager.WriteToFile("\n    std::mutex mtx_barrier_wait;");

     this->FileManager.WriteToFile("\n    std::mutex mtx_switch_wait;");

     this->FileManager.WriteToFile("\n    std::mutex mtx_two_parameter_wait;");

     this->FileManager.WriteToFile("\n    Thread_Locker Outside_Locker;");

     this->FileManager.WriteToFile("\n    Thread_Data_Manager Data_Manager;");

     this->FileManager.WriteToFile("\n    Thread_Locker Inside_Locker;");

     this->FileManager.WriteToFile("\n    int Total_Thread_Number;");

     this->FileManager.WriteToFile("\n    int Operational_Thread_Number;");

     this->FileManager.WriteToFile("\n    int Thread_Function_Number;");

     this->FileManager.WriteToFile("\n    int Thread_On_Point_Wait;");

     this->FileManager.WriteToFile("\n    int waiting_thread_number_in_barrier;");

     this->FileManager.WriteToFile("\n    int Function_enter_counter_with_rescuer_thread;");

     this->FileManager.WriteToFile("\n    int Function_enter_counter;");

     this->FileManager.WriteToFile("\n    std::mutex Function_Mutex[");

     this->FileManager.WriteToFile(this->Translater.Translate(Thread_Function_Number));

     this->FileManager.WriteToFile("];");

     this->FileManager.WriteToFile("\n    std::mutex Two_Pr_Function_Mutex[");

     this->FileManager.WriteToFile(this->Translater.Translate(Thread_Function_Number));

     this->FileManager.WriteToFile("];");

     this->FileManager.WriteToFile("\n    std::mutex Thread_Mutex[");

     this->FileManager.WriteToFile(this->Translater.Translate(Thread_Number));

     this->FileManager.WriteToFile("];");

     this->FileManager.WriteToFile("\n   };");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #endif");

     this->FileManager.FileClose();

     this->FileManager.Clear_Dynamic_Memory();
}
