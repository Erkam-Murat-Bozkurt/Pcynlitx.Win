
#ifndef CUSTOM_SYSTEM_INTERFACE_H
#define CUSTOM_SYSTEM_INTERFACE_H

#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include <stdlib.h>
#include <strings.h>

class Custom_System_Interface
{
public:
  Custom_System_Interface();
  Custom_System_Interface(const Custom_System_Interface & arg);
  virtual ~Custom_System_Interface();
  int System_Function(const char * cmd);
protected:
  pid_t pid;
  int status;
  int return_status;
};

#endif /* CUSTOM_SYSTEM_INTERFACE_H */
