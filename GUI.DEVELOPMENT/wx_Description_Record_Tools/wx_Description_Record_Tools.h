
#ifndef WX_DESCRIPTION_RECORD_TOOLS_H
#define WX_DESCRIPTION_RECORD_TOOLS_H

#include <wx/frame.h>
#include <wx/process.h>
#include <wx/utils.h>
#include <wx/stc/stc.h>
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
#include <wx/txtstrm.h>
#include <string>
#include <cstring>
#include "Custom_Notebook.h"
#include "Project_File_Selection_Dialog.h"
#include "Event_ID_Numbers.h"
#include "ClassNameReader.h"
#include "ClassSyntaxControl.h"

class wx_Description_Record_Tools
{
public:
  wx_Description_Record_Tools();
  virtual ~wx_Description_Record_Tools();
  void Receive_NoteBook_Manager(Custom_Notebook * Pointer);
  void Receive_Descriptor_File_Path(wxString Path);
  void Receive_Text_Control(wxStyledTextCtrl * Text);
  void Receive_Project_File_Selection_Status(bool selection);
  void Receive_Main_Frame_Address(wxFrame * Frame_Address);
  void Enter_Header_File_Location();
  void Enter_Source_File_Location();
  void Enter_Library_Location();
  void Enter_Header_File();
  void Enter_Header_File_Automatically(wxString Header_File_Path);
  void Enter_Source_File();
  void Enter_Library_Name();
  void Enter_Construction_Point();
  void Enter_Server_Class_Name();
  void Enter_Main_File_Name();
  void Enter_Thread_Function_Name();
  void Enter_Thread_Number();
  void Enter_Exe_File_Name();
  void Enter_Namespace();
  void Enter_OpenMP_Option(bool option);
  void Enter_ITC_Class_Header_File_Name();
  void Enter_ITC_Class_Name(wxString ClassName);
  void Enter_ITC_Class_Instance_Name(wxString ClassName);
  void Enter_IT_Data_Type_Header_File_Name();
  void Enter_IT_Data_Type_Name_Automaticly(wxString ClassName);
  void Enter_IT_Data_Type_Name();
  void Enter_IT_Data_Type_Pointer_Name(wxString Data_Type);
  void Determine_Description_Recorder_Command(wxString Data_Type,wxString Input_Command);
  void Update_Lexer_Index();
  void Description_Record_Process(wxString Input_String);
  void Show_Descriptor_File_Identification_Error();
  void Scroll_To_Position();
private:
  bool dialog_memory_delete_condition;
  ClassNameReader CN_Reader;
  Custom_Notebook * NB_Manager_Pointer;
  wxProcess * Process_Pointer;
  wxString Descriptor_File_Path;
  wxString Description_Recorder_Command;
  wxStyledTextCtrl * Text_Ctrl;
  Project_File_Selection_Dialog * Pr_File_Select_Dialog;
  int Inequality_Point;
  bool is_project_file_selected;
  wxFrame * Frame;
};

#endif /* WX_DESCRIPTION_RECORD_TOOLS_H */
