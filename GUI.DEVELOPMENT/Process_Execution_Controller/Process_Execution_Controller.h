
#ifndef PROCESS_EXECUTION_CONTROLLER_H
#define PROCESS_EXECUTION_CONTROLLER_H

#include "Event_ID_Numbers.h"
#include "Custom_Tree_View_Panel.h"
#include <wx/frame.h>
#include <wx/richmsgdlg.h>
#include <wx/string.h>
#include <wx/process.h>
#include <wx/utils.h>
#include <wx/stream.h>
#include <wx/txtstrm.h>
#include <wx/textfile.h>
#include <wx/progdlg.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>

class Process_Execution_Controller
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
  void Process_End(int Process_Exit_Status);
  void Set_Project_File_Select_Condition(bool Condition);
  void Show_Descriptions(wxString Descriptor_File_Path);
  void Clear_Inter_Process_Files();
  void Construct_Inter_Process_Files();
  wxString Get_Construction_Point();
private:
  wxFrame * MainFrame_Pointer;
  Custom_Tree_View_Panel * Dir_List_Manager;
  wxProcess * Process_Pointer;
  wxString Descriptor_File_Path;
  wxString Construction_Point;
  wxString Run_Command;
  wxString Output_File_Path;
  bool is_library_constructed;
  bool is_construction_point_determined;
  bool Process_Exit_Status;
  bool is_executable_file_name_determined;
  bool is_project_file_selected;
  bool process_end_condition;
  long Sub_Process_ID;
  int  Process_Event_Counter;
};

#endif /* PROCESS_EXECUTION_CONTROLLER_H */
