
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

#include "Thread_Data_Manager_Header_Builder.h"

Thread_Data_Manager_Header_Builder::Thread_Data_Manager_Header_Builder(){

};

Thread_Data_Manager_Header_Builder::Thread_Data_Manager_Header_Builder(const Thread_Data_Manager_Header_Builder & orig){

};

Thread_Data_Manager_Header_Builder::~Thread_Data_Manager_Header_Builder(){

};

void Thread_Data_Manager_Header_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;
}

void Thread_Data_Manager_Header_Builder::Build_Thread_Data_Manager_Header_File(){

     int Thread_Function_Number = this->Reader_Pointer->Get_Thread_Function_Number();

     int Thread_Number = this->Reader_Pointer->Get_Thread_Number();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.SetFilePath("Thread_Data_Manager.h");

     this->FileManager.FileOpen(RWCf);

     this->FileManager.WriteToFile("\n #ifndef THREAD_DATA_MANAGER_H");

     this->FileManager.WriteToFile("\n #define THREAD_DATA_MANAGER_H");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #include \"Thread_Locker.h\"");

     this->FileManager.WriteToFile("\n #include <thread>");

     this->FileManager.WriteToFile("\n #include <mutex>");

     this->FileManager.WriteToFile("\n #include <iostream>");

     this->FileManager.WriteToFile("\n #include <string>");

     this->FileManager.WriteToFile("\n #include <cstdlib>");

     this->FileManager.WriteToFile("\n #include <chrono>");

     this->FileManager.WriteToFile("\n #include <semaphore.h>");

     this->FileManager.WriteToFile("\n #include <condition_variable>");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n struct Thread_Data");

     this->FileManager.WriteToFile("\n {");

     this->FileManager.WriteToFile("\n    std::thread::id Thread_ID_Number;");

     this->FileManager.WriteToFile("\n    int  Thread_Number;");

     this->FileManager.WriteToFile("\n    int  wait_enter_counter;");

     this->FileManager.WriteToFile("\n    int  wait_termination;");  // The number of the thread which its termination will be waited

     this->FileManager.WriteToFile("\n    std::string Thread_Function_Name;");

     this->FileManager.WriteToFile("\n    std::condition_variable Condition_Variable;");

     this->FileManager.WriteToFile("\n    bool Thread_Operational_Status;");

     this->FileManager.WriteToFile("\n    bool ref_wait_status;");

     this->FileManager.WriteToFile("\n    bool Rescue_Permission;");

     this->FileManager.WriteToFile("\n    bool Thread_Block_Status;");   // it shows whether The thread is blocked or not

     this->FileManager.WriteToFile("\n    int  wait_untill_exit_thread_number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n struct Function_Names_Data");

     this->FileManager.WriteToFile("\n {");

     this->FileManager.WriteToFile("\n    int Function_Number;");

     this->FileManager.WriteToFile("\n    int Member_Counter;");

     this->FileManager.WriteToFile("\n    bool Rescue_Permission;");

     this->FileManager.WriteToFile("\n    int  Enter_Counter;");

     this->FileManager.WriteToFile("\n    int  function_block_wait_status;");

     this->FileManager.WriteToFile("\n    int  Two_Prm_Function_Enter_Counter;");

     this->FileManager.WriteToFile("\n    std::string Thread_Function_Name;");

     this->FileManager.WriteToFile("\n    std::condition_variable Condition_Variable;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n namespace ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("{");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n   class Thread_Data_Manager");

     this->FileManager.WriteToFile("\n   {");

     this->FileManager.WriteToFile("\n   public:");

     this->FileManager.WriteToFile("\n    Thread_Data_Manager();");

     this->FileManager.WriteToFile("\n    Thread_Data_Manager(const Thread_Data_Manager & orig);");

     this->FileManager.WriteToFile("\n    virtual ~Thread_Data_Manager();");

     this->FileManager.WriteToFile("\n    void Receive_Total_Thread_Number(int Total_Thread_Number);");

     this->FileManager.WriteToFile("\n    void Receive_Total_Function_Number(int Total_Function_Number);");

     this->FileManager.WriteToFile("\n    void Receive_Thread_ID(std::string Function_Name, int Thread_Number);");

     this->FileManager.WriteToFile("\n    void Initialize_Thread_Data();");

     this->FileManager.WriteToFile("\n    void Increase_Wait_Enter_Counter(int Thread_Number);");

     this->FileManager.WriteToFile("\n    void Increase_Function_Wait_Enter_Counter(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    void Increase_Two_Prm_Function_Wait_Enter_Counter(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    void Rescue_Function_Members(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    void Wait_Thread_Termination(int Number, int Rescuer_Thread);");

     this->FileManager.WriteToFile("\n    int  Get_Thread_Waits_This_Thread_Termination(int Number) const;");

     this->FileManager.WriteToFile("\n    int  Get_Function_Wait_Enter_Counter(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    int  Get_Two_Prm_Function_Wait_Enter_Counter(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    void Set_Rescue_Permission(int Thread_Number, bool permission);");

     this->FileManager.WriteToFile("\n    void Set_Thread_Block_Status(int Thread_Number, bool status);");

     this->FileManager.WriteToFile("\n    void Set_Wait_Enter_Counter(int Thread_Number, int Number);");

     this->FileManager.WriteToFile("\n    void Set_Function_Wait_Enter_Counter(std::string Function_Name, int Number);");

     this->FileManager.WriteToFile("\n    void Set_Two_Prm_Function_Wait_Enter_Counter(std::string Function_Name, int Number);");

     this->FileManager.WriteToFile("\n    void Set_Function_Rescue_Permission(std::string Function_Name, bool permission);");

     this->FileManager.WriteToFile("\n    void Set_Function_Name(int Thread_Number, std::string Function_Name);");

     this->FileManager.WriteToFile("\n    bool Get_Function_Rescue_Permission(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    int  Get_Wait_Enter_Counter(int Thread_Number) const;");

     this->FileManager.WriteToFile("\n    bool Get_Rescue_Permission(int Thread_Number) const;");

     this->FileManager.WriteToFile("\n    bool Get_Thread_Block_Status(int Thread_Number) const;");

     this->FileManager.WriteToFile("\n    bool Get_Dead_Lock_Risk();");

     this->FileManager.WriteToFile("\n    int  Get_Thread_Number();");

     this->FileManager.WriteToFile("\n    int  Get_Function_Member_Number(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    std::string Get_Function_Name(int Thread_Number) const;");

     this->FileManager.WriteToFile("\n    int  Get_Operational_Thread_Number() const;");

     this->FileManager.WriteToFile("\n    bool Get_Thread_Operational_Status(int Thread_Number) const;");

     this->FileManager.WriteToFile("\n    int  GetFirstThreadExecutingFunction(std::string Function_Name);");

     this->FileManager.WriteToFile("\n    void Get_Thread_Function_Name_Number(std::string Function_Name, int * Function_Name_Number);");

     this->FileManager.WriteToFile("\n    void Stop_Thread(std::unique_lock<std::mutex> * mtx, int thread_number);");

     this->FileManager.WriteToFile("\n    void Activate_Thread(int thread_number);");

     this->FileManager.WriteToFile("\n    void Set_Block_Function_Wait_Status(std::string function, int status);");

     this->FileManager.WriteToFile("\n    int Get_Block_Function_Wait_Status(std::string function);");

     this->FileManager.WriteToFile("\n    void Exit();");

     this->FileManager.WriteToFile("\n   private:");

     this->FileManager.WriteToFile("\n    Thread_Locker Inside_Locker;");

     this->FileManager.WriteToFile("\n    Thread_Locker Thread_Exit_Locker;");

     this->FileManager.WriteToFile("\n    int Total_Thread_Number;");

     this->FileManager.WriteToFile("\n    int Operational_Thread_Number;");

     this->FileManager.WriteToFile("\n    int Thread_Function_Number;");

     this->FileManager.WriteToFile("\n    int Caller_Thread_Number;");

     this->FileManager.WriteToFile("\n    int The_First_Thread_Execution_Function;");

     this->FileManager.WriteToFile("\n    bool Dead_Lock_Risk;");

     this->FileManager.WriteToFile("\n    Thread_Data Thread_Data_List[");

     this->FileManager.WriteToFile(this->Translater.Translate(Thread_Number));

     this->FileManager.WriteToFile("];");

     this->FileManager.WriteToFile("\n    Function_Names_Data Function_Names_Data_List[");

     this->FileManager.WriteToFile(this->Translater.Translate(Thread_Function_Number));

     this->FileManager.WriteToFile("];");

     this->FileManager.WriteToFile("\n   };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #endif");

     this->FileManager.FileClose();

     this->FileManager.Clear_Dynamic_Memory();
}
