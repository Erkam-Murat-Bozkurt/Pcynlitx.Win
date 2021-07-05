
#ifndef PROCESS_EXECUTION_CONTROLLER_H
#define PROCESS_EXECUTION_CONTROLLER_H

#include "Event_ID_Numbers.h"
#include "Custom_Tree_View_Panel.h"
#include "Descriptor_File_Reader.h"
#include <wx\wx.h>
#include <wx\frame.h>
#include <wx\panel.h>
#include <wx\process.h>
#include <wx\richmsgdlg.h>
#include <wx\string.h>
#include <wx\process.h>
#include <wx\utils.h>
#include <wx\stream.h>
#include <wx\txtstrm.h>
#include <wx\textfile.h>
#include <wx\progdlg.h>
#include <wx\textctrl.h>
#include <wx\stc/stc.h>
#include <wx\msgdlg.h>

class Process_Execution_Controller : public wxProcess
{
public:
  Process_Execution_Controller();
  virtual ~Process_Execution_Controller();
  void Receive_Main_Frame_Address(wxFrame * Frame);
  void Receive_Descriptor_File_Path(wxString Descriptor_File_Path);
  void Construction_Point_Determination();
  void Control_Executable_File_Name();
  void RunLibraryBuilder(Custom_Tree_View_Panel ** Dir_List_Manager);
  void RunExeBuilder(Custom_Tree_View_Panel ** Dir_List_Manager);
  void ShowProgress();
  void Process_End(int exit_status);
  void Set_Project_File_Select_Condition(bool Condition);
  void Show_Descriptions(wxString Descriptor_File_Path);
  void Print_Construction_Process_Output();
  wxString Get_Construction_Point();
  void Print_Text(wxString std_out, wxString title);
  void Print_Error_Stream(wxString title);
  void Print_Output_Stream(wxString title);
private:
  Descriptor_File_Reader Descriptor_Reader;
  void Remove_Construction_Point_Holder_File();
  void sleep_time_determination();
  wxFrame * MainFrame_Pointer;
  Custom_Tree_View_Panel * Dir_List_Manager;
  wxProcess * Process_Pointer;
  wxString Descriptor_File_Path;
  wxString Construction_Point;
  wxString Run_Command;
  wxString Construction_Point_Holder_Path;
  bool is_library_constructed;
  bool is_construction_point_determined;
  int Process_Exit_Status;
  bool is_executable_file_name_determined;
  bool is_project_file_selected;
  bool error_stream_status;
  bool library_construction_process_start;
  bool exe_file_construction_process_start;
  long Sub_Process_ID;
  long Sub_Process_ID_Received;
  int  Process_Event_Counter;
  int Output_Print_Number;
  int sleep_time;
};

#endif /* PROCESS_EXECUTION_CONTROLLER_H */
