
#ifndef CUSTOM_SYSTEM_INTERFACE_H
#define CUSTOM_SYSTEM_INTERFACE_H

#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <strings.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

class Custom_System_Interface
{
public:
  Custom_System_Interface();
  Custom_System_Interface(const Custom_System_Interface & arg);
  virtual ~Custom_System_Interface();
  bool Create_Process(char * cmd);
  int System_Function(char * cmd);
protected:
  pid_t pid;
  int status;
  bool return_status;
  int return_value;
};

#endif /* CUSTOM_SYSTEM_INTERFACE_H */
