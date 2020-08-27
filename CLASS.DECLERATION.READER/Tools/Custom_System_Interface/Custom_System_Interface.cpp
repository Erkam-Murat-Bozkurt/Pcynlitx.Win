
#include "Custom_System_Interface.h"

Custom_System_Interface::Custom_System_Interface(){

    this->status = 0;

    this->return_status = -1; // The return status of the system call..
}

Custom_System_Interface::Custom_System_Interface(const Custom_System_Interface & arg){

}


Custom_System_Interface::~Custom_System_Interface(){


}

int Custom_System_Interface::System_Function(const char * cmd){

    this->status = 0;

    this->pid = fork();

    if(this->pid == -1){    // On failure, from fork(), -1 is returned in the parent, no child process is created

       this->return_status = -1; // The child process can not be created ..

       return this->return_status;
    }

    if(this->pid==0){

       int exec_return = 0;

       exec_return = execlp("/bin/sh","sh","-c",cmd,NULL);

       if(exec_return != 0){

          this->return_status = -1;  // The command can not be executed by the child process..

          return this->return_status;
       }
    }
    else{

          pid_t process_return = waitpid(this->pid,&(this->status),0);

          if(process_return == -1){

             this->return_status = -1; // The child process can not be ended successfully ..

             return this->return_status;
          }

          if(WIFEXITED(this->status)){

             return WEXITSTATUS(this->status);
          }
    }


    this->return_status = -1; // The system call is uncessesfull..

    return this->return_status;
}
