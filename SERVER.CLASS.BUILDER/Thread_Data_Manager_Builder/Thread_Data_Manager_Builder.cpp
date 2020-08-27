

/*

Copyright ©  2019,  Erkam Murat Bozkurt

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

#include "Thread_Data_Manager_Builder.h"

Thread_Data_Manager_Builder::Thread_Data_Manager_Builder(){

    this->Memory_Delete_Condition = false;

    this->Compiler_Command = nullptr;

    this->Constructed_Include_Directory = nullptr;
};

Thread_Data_Manager_Builder::Thread_Data_Manager_Builder(const Thread_Data_Manager_Builder & orig){

};

Thread_Data_Manager_Builder::~Thread_Data_Manager_Builder(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
};

void Thread_Data_Manager_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

        this->Memory_Delete_Condition = true;

        if(this->Compiler_Command != nullptr){

           delete [] this->Compiler_Command;

           this->Compiler_Command = nullptr;
        }
     }
}

void Thread_Data_Manager_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;

     this->HeaderFileBuilder.Receive_Descriptor_File_Reader(this->Reader_Pointer);

}

void Thread_Data_Manager_Builder::Receive_Constructed_Include_Directory(char * Directory){

     this->Constructed_Include_Directory = Directory;
}

void Thread_Data_Manager_Builder::Build_Thread_Data_Manager(){

     this->Memory_Delete_Condition = false;

     this->Directory_Manager.DetermineCurrentDirectory();

     this->Determine_Compiler_Command();

     this->HeaderFileBuilder.Build_Thread_Data_Manager_Header_File();

     char * name_space = this->Reader_Pointer->Get_Namespace();

     this->FileManager.SetFilePath("Thread_Data_Manager.cpp");

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #include \"Thread_Data_Manager.h\"");

     this->FileManager.WriteToFile("\n");


     // CONSTRUCTOR IMPLEMENTATION   ---------------------------------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Thread_Data_Manager(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Caller_Thread_Number = -1;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Total_Thread_Number = ");

     int Total_Thread_Number = this->Reader_Pointer->Get_Thread_Number();

     char * Thread_Number = this->Translater.Translate(Total_Thread_Number);

     this->FileManager.WriteToFile(Thread_Number);

     this->FileManager.WriteToFile(";");

     this->FileManager.WriteToFile("\n");

     int Thread_Function_Number = this->Reader_Pointer->Get_Thread_Function_Number();

     this->FileManager.WriteToFile("\n      this->Thread_Function_Number = ");

     this->FileManager.WriteToFile(this->Translater.Translate(Thread_Function_Number));

     this->FileManager.WriteToFile(";");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Operational_Thread_Number = this->Total_Thread_Number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // COPY CONSTRUCTOR IMPLEMENTATION   ------------------------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Thread_Data_Manager(const Thread_Data_Manager & orig){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // DESTRUCTOR IMPLEMENTATION --------------------------------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::~Thread_Data_Manager(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // INITIALIZE THREAD DATA IMPLEMENTATION ( Initialize_Thread_Data )  ----------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Initialize_Thread_Data(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      for(int i=0;i<this->Total_Thread_Number;i++){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          this->Thread_Data_List[i].Thread_Number = -1;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          this->Thread_Data_List[i].wait_untill_exit_thread_number = -1;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          this->Thread_Data_List[i].wait_enter_counter = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          this->Thread_Data_List[i].Rescue_Permission = false;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          this->Thread_Data_List[i].Thread_Block_Status = false;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          this->Thread_Data_List[i].ref_wait_status = false;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          this->Thread_Data_List[i].wait_termination = -1;");   // Holds the number of the thread which its termination will be waited..

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      };");

     this->FileManager.WriteToFile("\n");

     for(int i=0;i<Thread_Function_Number;i++){

         this->FileManager.WriteToFile("\n");

         this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[");

         this->FileManager.WriteToFile(this->Translater.Translate(i));

         this->FileManager.WriteToFile("].Thread_Function_Name = \"");

         this->FileManager.WriteToFile(this->Reader_Pointer->Get_Thread_Function_Names()[i]);

         this->FileManager.WriteToFile("\";");

         this->FileManager.WriteToFile("\n");

         this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[");

         this->FileManager.WriteToFile(this->Translater.Translate(i));

         this->FileManager.WriteToFile("].Function_Number = ");

         this->FileManager.WriteToFile(this->Translater.Translate(i));

         this->FileManager.WriteToFile(";");

         this->FileManager.WriteToFile("\n");

         this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[");

         this->FileManager.WriteToFile(this->Translater.Translate(i));

         this->FileManager.WriteToFile("].Member_Counter = 0;");

         this->FileManager.WriteToFile("\n");

         this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[");

         this->FileManager.WriteToFile(this->Translater.Translate(i));

         this->FileManager.WriteToFile("].Enter_Counter = 0;");

         this->FileManager.WriteToFile("\n");


         this->FileManager.WriteToFile("\n");

         this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[");

         this->FileManager.WriteToFile(this->Translater.Translate(i));

         this->FileManager.WriteToFile("].Two_Prm_Function_Enter_Counter = 0;");

         this->FileManager.WriteToFile("\n");


         this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[");

         this->FileManager.WriteToFile(this->Translater.Translate(i));

         this->FileManager.WriteToFile("].Rescue_Permission = false;");
     }

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // RECEIVE THREAD ID IMPLEMENTATION " Receive_Thread_ID(std::string Function_Name, int Thread_Number) " -------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Receive_Thread_ID(std::string Function_Name, int Thread_Number){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Inside_Locker.lock();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      std::thread::id this_id = std::this_thread::get_id();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].Thread_ID_Number = this_id;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].Thread_Number = Thread_Number;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].Thread_Function_Name = Function_Name;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].Thread_Operational_Status = true;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[Function_Name_Number].Member_Counter++;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Inside_Locker.unlock();");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // GET THREAD NUMBER IMPLEMENTATION ( Get_Thread_Number() const )  --------------------------------------------------------------------

     this->FileManager.WriteToFile("\n int ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Thread_Number(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      std::thread::id this_id = std::this_thread::get_id();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      for(int i=0;i<this->Total_Thread_Number;i++){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          if(this->Thread_Data_List[i].Thread_ID_Number == this_id ){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n             this->Caller_Thread_Number = i;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n             break;");

     this->FileManager.WriteToFile("\n          };");

     this->FileManager.WriteToFile("\n      };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Caller_Thread_Number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // GET THREAD FUNCTION NAME NUMBER IMPLEMENTATION  --------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Thread_Function_Name_Number(std::string Function_Name, int * Function_Name_Number){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      *Function_Name_Number = -1;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      for(int i=0;i<this->Thread_Function_Number;i++){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          if(this->Function_Names_Data_List[i].Thread_Function_Name == Function_Name){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n             *Function_Name_Number = this->Function_Names_Data_List[i].Function_Number;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n              break;");

     this->FileManager.WriteToFile("\n          }");

     this->FileManager.WriteToFile("\n      }");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      if(*Function_Name_Number == -1){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n         std::cout << \"\\n\\n [Error] - The synchronizer object  can not determine the thread function names! \";");

     this->FileManager.WriteToFile("\n         std::cout << \"\\n\\n           Most probably, the synchronizer object recives a wrong name ! \";");

     this->FileManager.WriteToFile("\n         std::cout << \"\\n\\n           Please check the initialization of the synchronizer object.  \";");

     this->FileManager.WriteToFile("\n         std::cout << \"\\n\\n \";");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n         exit(EXIT_FAILURE);");

     this->FileManager.WriteToFile("\n      }");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // EXIT MEMBER FUNCTION IMPLEMENTATION  ------------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Exit(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Exit_Locker.lock();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Operational_Thread_Number--;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Thread_Number = this->Get_Thread_Number();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].Thread_Operational_Status = false;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      std::string Function_Name = this->Get_Function_Name(Thread_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[Function_Name_Number].Member_Counter--;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Exit_Locker.unlock();");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // GET DEAD LOCK RISK IMPLEMENTATION ---------------------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n bool ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Dead_Lock_Risk(){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     this->Dead_Lock_Risk = false;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     int blocked_thread_number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     for(int i=0;i<this->Operational_Thread_Number;i++){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n        if(this->Get_Thread_Block_Status(i) == true){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n          blocked_thread_number++;");

     this->FileManager.WriteToFile("\n        };");

     this->FileManager.WriteToFile("\n     };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     if((this->Operational_Thread_Number - blocked_thread_number) < 2){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n         this->Dead_Lock_Risk = true;");

     this->FileManager.WriteToFile("\n     }");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     return this->Dead_Lock_Risk;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");




     // GET OPERATIONAL THREAD NUMBER IMPLEMENTATION ---------------------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n int ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Operational_Thread_Number() const {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     return this->Operational_Thread_Number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // INCREASE WAIT ENTER COUNTER --------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Increase_Wait_Enter_Counter(int Thread_Number){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].wait_enter_counter++;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n };");




     // GET WAIT ENTER COUNTER ------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n int ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Wait_Enter_Counter(int Thread_Number) const {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     return this->Thread_Data_List[Thread_Number].wait_enter_counter;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // INCREASE FUNCTION WAIT ENTER COUNTER --------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Increase_Function_Wait_Enter_Counter(std::string Function_Name){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[Function_Name_Number].Enter_Counter++;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n };");




     // GET FUNCTION WAIT ENTER COUNTER ------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n int ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Function_Wait_Enter_Counter(std::string Function_Name){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Function_Names_Data_List[Function_Name_Number].Enter_Counter;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");




     // INCREASE TWO FUNCTION WAIT ENTER COUNTER --------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Increase_Two_Prm_Function_Wait_Enter_Counter(std::string Function_Name){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[Function_Name_Number].Two_Prm_Function_Enter_Counter++;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n };");



     // GET TWO PARAMETER FUNCTION WAIT ENTER COUNTER ------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n int ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Two_Prm_Function_Wait_Enter_Counter(std::string Function_Name){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Function_Names_Data_List[Function_Name_Number].Two_Prm_Function_Enter_Counter;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // SET FUNCTION WAIT ENTER COUNTER ------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Set_Function_Wait_Enter_Counter(std::string Function_Name, int Number){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[Function_Name_Number].Enter_Counter = Number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");




     // SET TWO PARAMETER FUNCTION WAIT ENTER COUNTER ------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Set_Two_Prm_Function_Wait_Enter_Counter(std::string Function_Name, int Number){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[Function_Name_Number].Two_Prm_Function_Enter_Counter = Number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // STOP THREAD  ----------------------------------------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Stop_Thread(std::unique_lock<std::mutex> * mtx, int thread_number){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Set_Thread_Block_Status(thread_number,true);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[thread_number].Condition_Variable.wait(*mtx);");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // ACTIVATE THREAD NUMBER -----------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Activate_Thread(int thread_number){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Set_Thread_Block_Status(thread_number,false);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     this->Thread_Data_List[thread_number].Condition_Variable.notify_one();");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // SET FUNCTION NAME ---------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Set_Function_Name(int Thread_Number, std::string Function_Name){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].Thread_Function_Name = Function_Name;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // SET WAIT ENTER COUNTER ---------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Set_Wait_Enter_Counter(int Thread_Number, int number){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].wait_enter_counter = number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     //  GET FUNCTION NAME ---------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n std::string ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Function_Name(int Thread_Number) const {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Thread_Data_List[Thread_Number].Thread_Function_Name;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     //  GET FUNCTION MEMBER NUMBER  ---------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n int ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Function_Member_Number(std::string Function_Name){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Function_Names_Data_List[Function_Name_Number].Member_Counter;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // SET RESCUE PERMISSION -------------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Set_Rescue_Permission(int Thread_Number, bool permission){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Thread_Data_List[Thread_Number].Rescue_Permission = permission;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // GET RESCUE PERMISSION -----------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n bool ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Rescue_Permission(int Thread_Number) const {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Thread_Data_List[Thread_Number].Rescue_Permission;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // SET FUNCTION RESCUE PERMISSION -----------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Set_Function_Rescue_Permission(std::string Function_Name,bool permission){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Function_Names_Data_List[Function_Name_Number].Rescue_Permission = permission;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // GET FUNCTION RESCUE PERMISSION --------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n bool ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Function_Rescue_Permission(std::string Function_Name){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      int Function_Name_Number = 0;");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      this->Get_Thread_Function_Name_Number(Function_Name,&Function_Name_Number);");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Function_Names_Data_List[Function_Name_Number].Rescue_Permission;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // GET THREAD OPERATIONAL STATUS  -----------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n bool ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Thread_Operational_Status(int thread_number) const {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Thread_Data_List[thread_number].Thread_Operational_Status;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // WAIT THREAD TERMINATION  -----------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Wait_Thread_Termination(int Number, int Rescuer_Thread){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     this->Thread_Data_List[Rescuer_Thread].wait_untill_exit_thread_number = Number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // IS THREAD WAIT THIS THREAD TERMINATION -----------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n int ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Thread_Waits_This_Thread_Termination(int Number) const {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n     return this->Thread_Data_List[Number].wait_untill_exit_thread_number;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // RESCUE FUNCTION MEMBERS -----------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Rescue_Function_Members(std::string Function_Name) {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n       int Thread_Number = this->Get_Thread_Number();");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n       for(int i=0;i<this->Total_Thread_Number;i++){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n           if(((this->Get_Function_Name(i) == Function_Name) && (i != Thread_Number))){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n                if(this->Get_Thread_Operational_Status(i)){");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n                   this->Activate_Thread(i);");

     this->FileManager.WriteToFile("\n                }");

     this->FileManager.WriteToFile("\n           }");

     this->FileManager.WriteToFile("\n       }");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     // SET THREAD BLOCK STATUS -----------------------------------------------------------------------------------------------

     this->FileManager.WriteToFile("\n void ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Set_Thread_Block_Status(int Thread_Number, bool status) {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n       this->Thread_Data_List[Thread_Number].Thread_Block_Status = status;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");



     // GET THREAD BLOCK STATUS IMPLEMENTATION ( Get_Block_Status(int Thread_Number)  ) ----------------------------------------------------

     this->FileManager.WriteToFile("\n bool ");

     this->FileManager.WriteToFile(name_space);

     this->FileManager.WriteToFile("::Thread_Data_Manager::Get_Thread_Block_Status(int Thread_Number) const{");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n      return this->Thread_Data_List[Thread_Number].Thread_Block_Status;");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");


     this->FileManager.FileClose();

     this->FileManager.Clear_Dynamic_Memory();

     this->Directory_Manager.Clear_Dynamic_Memory();
}

void Thread_Data_Manager_Builder::Determine_Compiler_Command(){

     char Process_Command [] = {'g','+','+',' ','-','c',' ','-','s','t','d','=','c','+','+','1','4',' ','\0'};

     char Source_File_Name [] = "Thread_Data_Manager.cpp";

     char Header_File_Name [] = "Thread_Data_Manager.h";

     char Locker_Class_Header_File_Name [] = "Thread_Locker.h";

     char Include_Word [] = "-include";

     char Include_Directory_Determiner [] = {'-','I','\0'};

     char Thread_Library_Name [] = {'-','l','p','t','h','r','e','a','d','\0'};

     char Space_Character [] = {' ','\0'};

     char Output_Redirection_Command [] = {'2','>','\0'};

     char Error_Message_File_Name [] = {'/','C','o','m','p','i','l','e','r','_','O','u','t','p','u','t','\0'};

     int Source_File_Name_Size = strlen(Source_File_Name);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int Locker_Class_Header_File_Name_Size = strlen(Locker_Class_Header_File_Name);

     int Process_Command_Name_Size = strlen(Process_Command);

     int Thread_Library_Name_Size = strlen(Thread_Library_Name);

     int Include_Word_Name_Size = strlen(Include_Word);

     int Include_Directory_Determiner_Size = strlen(Include_Directory_Determiner);

     int Current_Directory_Name_Size = strlen(this->Directory_Manager.GetCurrentlyWorkingDirectory());

     int Compiler_Command_Size = Source_File_Name_Size + Header_File_Name_Size

                                + Process_Command_Name_Size + Thread_Library_Name_Size

                                + Current_Directory_Name_Size + Locker_Class_Header_File_Name_Size

                                + Include_Word_Name_Size + Include_Directory_Determiner_Size;

     this->Compiler_Command = new char [10*Compiler_Command_Size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_Command,Process_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Directory_Determiner,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Directory_Manager.GetCurrentlyWorkingDirectory(),&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Source_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Header_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Include_Word,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Locker_Class_Header_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Thread_Library_Name,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,Output_Redirection_Command,&index_counter);

     this->Place_Information(&this->Compiler_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_Command,this->Reader_Pointer->Get_Construction_Point(),&index_counter);

     this->Place_Information(&this->Compiler_Command,Error_Message_File_Name,&index_counter);

     this->Compiler_Command[index_counter] = '\0';
}

void Thread_Data_Manager_Builder::Remove_Source_File(){

     char Source_File_Name [] = "Thread_Data_Manager.cpp";

     char Directory_Character [] = {'/','\0'};

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     int Construction_Point_Size = strlen(Construction_Point);

     int Source_File_Name_Size = strlen(Source_File_Name);

     int Source_File_Path_Size = Source_File_Name_Size + Construction_Point_Size;

     char * Source_File_Path = new char [10*Source_File_Path_Size];

     int index_counter = 0;

     this->Place_Information(&Source_File_Path,Construction_Point,&index_counter);

     this->Place_Information(&Source_File_Path,Directory_Character,&index_counter);

     this->Place_Information(&Source_File_Path,Source_File_Name,&index_counter);

     Source_File_Path[index_counter] = '\0';

     this->FileManager.DeleteFile(Source_File_Path);

     delete [] Source_File_Path;
}

void Thread_Data_Manager_Builder::Remove_Header_Extra_File(){

     char Header_Extra_File [] = "Thread_Data_Manager.h.gch";

     char Directory_Character [] = {'/','\0'};

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     int Construction_Point_Size = strlen(Construction_Point);

     int Header_File_Name_Size = strlen(Header_Extra_File);

     int File_Path_Size = Construction_Point_Size  + Header_File_Name_Size;

     char * File_Path = new char [10*File_Path_Size];

     int index_counter = 0;

     this->Place_Information(&File_Path,Construction_Point,&index_counter);

     this->Place_Information(&File_Path,Directory_Character,&index_counter);

     this->Place_Information(&File_Path,Header_Extra_File,&index_counter);

     File_Path[index_counter] = '\0';

     this->FileManager.DeleteFile(File_Path);

     delete [] File_Path;
}


void Thread_Data_Manager_Builder::Move_Header_File(){

     char Header_File_Name [] = "Thread_Data_Manager.h";

     char Directory_Character [] = {'/','\0'};

     char * Construction_Point = this->Reader_Pointer->Get_Construction_Point();

     int Target_Directory_Size = strlen(this->Constructed_Include_Directory);

     int Header_File_Name_Size = strlen(Header_File_Name);

     int Construction_Point_Size = strlen(Construction_Point);

     int Current_Path_Size = Construction_Point_Size + Header_File_Name_Size;

     int Target_Path_Size = Target_Directory_Size + Header_File_Name_Size;

     char * Current_Path = new char [10*Current_Path_Size];

     int index_counter = 0;

     this->Place_Information(&Current_Path,Construction_Point,&index_counter);

     this->Place_Information(&Current_Path,Directory_Character,&index_counter);

     this->Place_Information(&Current_Path,Header_File_Name,&index_counter);

     Current_Path[index_counter] = '\0';

     char * Target_Path  = new char [10*Target_Path_Size];

     index_counter = 0;

     this->Place_Information(&Target_Path,this->Constructed_Include_Directory,&index_counter);

     this->Place_Information(&Target_Path,Directory_Character,&index_counter);

     this->Place_Information(&Target_Path,Header_File_Name,&index_counter);

     Target_Path[index_counter] = '\0';

     this->FileManager.Move_File(Target_Path,Current_Path);

     delete [] Current_Path;

     delete [] Target_Path;
}


void Thread_Data_Manager_Builder::Run_System_Commands(){

     int system_return_value = this->System_Interface.System_Function(this->Compiler_Command);

     if(system_return_value != 0){

         std::cout << "\n\n";

         std::cerr << "        An error occured in Thread_Data_Manager_Builder class compiling.." << std::endl;

         std::cout << "\n\n";

         exit(1);
     }

     this->Remove_Source_File();

     this->Remove_Header_Extra_File();

     this->Move_Header_File();
}

void Thread_Data_Manager_Builder::Place_Information(char ** Pointer, char * Information, int * Counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

        (*Pointer)[(*Counter)] = Information[i];

        (*Counter)++;
     }
}
