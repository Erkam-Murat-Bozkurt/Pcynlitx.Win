
#include "Custom_System_Interface.h"

Custom_System_Interface::Custom_System_Interface(){

    this->status = 0;

    this->return_status = -1; // The return status of the system call..
}

Custom_System_Interface::Custom_System_Interface(const Custom_System_Interface & arg){

}


Custom_System_Interface::~Custom_System_Interface(){


}

bool Custom_System_Interface::System_Function(char * cmd){

     this->return_status = false;

     STARTUPINFO startupInfo;

     PROCESS_INFORMATION processInformation;

     this->return_status = CreateProcess(NULL,cmd,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startupInfo,&processInformation);

     WaitForSingleObject( processInformation.hProcess, INFINITE );

     DWORD exit_code = 0;

     GetExitCodeProcess( processInformation.hProcess, &exit_code );

     CloseHandle( processInformation.hProcess );

     if(exit_code != 0){

        std::cout << "\n The system function executing a command (an exacutable binary)";

        std::cout << "\n in a seperate process can not ended sucessfully.";

        std::cout << "\n the process has been ended with exit code:" << exit_code;

        std::cout << "\n\n";
     }

     return this->return_status;
}
