

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
#include <shlwapi.h>
#include <cwchar>
#include <sstream>  // std::stringstream
#include "Cpp_FileOperations.h"

#define BUFFER_SIZE 4092

class Custom_System_Interface
{
public:
  Custom_System_Interface();
  virtual ~Custom_System_Interface();
  void SetCpuRate();
  bool Create_Process(std::string cmd);
  bool Create_Process(char * cmd);
  int  System_Function(char * cmd);
  bool Create_Process_With_Redirected_Stdout(char * cmd);
  void CreateProcessWith_NamedPipe_From_Parent(char * argv);
  void WriteTo_NamedPipe_FromChild(char * string);
  bool IsChildProcessStillAlive(); 
  bool IsPipeReadytoRead();
  std::string ReadNamedPipe_From_Parent();
  void Connect_NamedPipe_From_Child_Process();
  void SetChildProcess_For_StdOut_Redirection();
  void WriteChildProcess_StdOutput();
  void WriteChildProcess_StdError();
  bool TerminateChildProcess();
  void WaitForChildProcess();
  TCHAR * GetPipePath();
  std::string GetPipePath_StdStr();
  std::string GetAnonymousPipe_String();
  void ReadFromPipe(void);
  void Close_Parent_Handles_For_Named_Pipe_Connection();
  void Close_Child_Handles_For_Named_Pipe_Connection();
  int  Get_Anonymously_PipedProcess_ExitCode();
  PROCESS_INFORMATION piProcInfo; 
  STARTUPINFO siStartInfo;
  SECURITY_ATTRIBUTES saAttr; 
  UINT uExitCode;
  DWORD64 Child_PID; 
protected:
  void DeterminePipePath(); 
  TCHAR * Convert_CString_To_TCHAR(char * cmd);  
  void Clear_Dynamic_Memory();
  Cpp_FileOperations FileManager;
  bool Memory_Delete_Condition;
  bool Is_Child_Process_Ended;
  TCHAR * TCHAR_string;
  TCHAR * StdOutPipe;
  std::string std_str_pipe_path;
  DWORD bufsize;
  CHAR chBuf[4096]; 
  DWORD  dwRead;
  DWORD  dwWritten; 
  HANDLE hStdin;
  HANDLE hStdout; 
  HANDLE hStdError;
  HANDLE g_hChildStd_OUT_Rd;
  HANDLE g_hChildStd_OUT_Wr;
  HANDLE g_hInputFile;
  HANDLE hNamedPipe;
  HANDLE hNamedPipe_Client_Connection;
  std::string anonymous_pipe_string;
  bool process_handle_close_status;
  bool pipe_handle_close_status;
  bool return_status;
  int anonymous_piped_process_exit_code;
  int return_value;
  char * cmd;
};

#endif /* CUSTOM_SYSTEM_INTERFACE_H */
