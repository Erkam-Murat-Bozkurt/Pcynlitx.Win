
#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/aui/auibook.h>
#include <wx/aui/dockart.h>
#include <wx/event.h>
#include <wx/fontdata.h>
#include <wx/fontdlg.h>
#include <wx/filedlg.h>
#include <wx/font.h>
#include <wx/process.h>
#include <wx/utils.h>
#include <wx/dialog.h>
#include <wx/dir.h>
#include <wx/toolbar.h>
#include <wx/richmsgdlg.h>
#include <wx/stc/stc.h>
#include <wx/textdlg.h>
#include <wx/colour.h>
#include <wx/string.h>
#include <wx/scrolwin.h>
#include <wx/dcbuffer.h>
#include <wx/display.h>
#include "wx_Description_Record_Tools.h"
#include "Project_File_Selection_Dialog.h"
#include "Menu_Bar_Options.h"
#include "Custom_Notebook.h"
#include "keyboard_event_controler.h"
#include "Custom_Tree_View_Panel.h"
#include "Event_ID_Numbers.h"
#include "ToolBar_Initializer.h"
#include "Process_Execution_Controller.h"
#include "Custom_DockArt.h"
#include "Intro_Page_Loader.h"
#include "Custom_wxPanel.h"
#include "Custom_TabArt.h"


class MainFrame : public wxFrame
{
public:
  MainFrame();
  virtual ~MainFrame();
  void OnPaint(wxPaintEvent & event);
  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& _rect);
  void PaintNow(wxWindow * wnd);
  void Receive_Interface_Manager_Adress(wxAuiManager * Interface_Manager);
  void OnSize(wxSizeEvent & event);
  void OnQuit(wxCommandEvent & event);
  void OnOpen(wxCommandEvent & event);
  void SelectProjectFile(wxCommandEvent & event);
  void OnOpenFontDialog(wxCommandEvent & event);
  void DirectoryOpen(wxCommandEvent & event);
  void RunLibraryBuilder(wxCommandEvent & event);
  void RunExeBuilder(wxCommandEvent & event);
  void OpenTerminal(wxCommandEvent & event);
  void FileSelect(wxDataViewEvent & event);
  void ShowProjectFile(wxCommandEvent & event);
  void OpenIntroPage(wxCommandEvent & event);
  void ShowAuthor(wxCommandEvent & event);
  void ShowProjectFileLocation(wxCommandEvent & event);
  void ShowProjectDirectoryLocation(wxCommandEvent & event);
  void Open_Project_Web_Page(wxCommandEvent & event);
  void Show_Descriptions(wxCommandEvent & event);
  void OnClose(wxCloseEvent & event);
  wxAuiPaneInfo Central_Pane_Info;
  bool is_custom_panel_constructed = false;
  void Update(){};
private:
  void FileNameEdit(wxDataViewEvent & event);
  void Process_End(wxProcessEvent & event);
  void File_Save(wxCommandEvent & event);
  void OpenEmptyProjectFile(wxCommandEvent & event);
  void Increase_Font_Size(wxCommandEvent & event);
  void Decrease_Font_Size(wxCommandEvent & event);
  void Use_Default_Font(wxCommandEvent & event);
  void Undo_Changes(wxCommandEvent & event);
  void Redo_Changes(wxCommandEvent & event);
  void Re_Open_Project_Directory(wxCommandEvent & event);
  void Enter_Header_File_Location(wxCommandEvent & event);
  void Enter_Source_File_Location(wxCommandEvent & event);
  void Enter_Library_Location(wxCommandEvent & event);
  void Enter_Header_File(wxCommandEvent & event);
  void Enter_Source_File(wxCommandEvent & event);
  void Enter_Library_Name(wxCommandEvent & event);
  void Enter_Namespace(wxCommandEvent & event);
  void Enter_OpenMP_Support(wxCommandEvent & event);
  void Enter_Construction_Point(wxCommandEvent & event);
  void Enter_Thread_Function_Name(wxCommandEvent & event);
  void Enter_Thread_Number(wxCommandEvent & event);
  void Enter_Exe_File_Name(wxCommandEvent & event);
  void Enter_ITC_Class_Header_File_Name(wxCommandEvent & event);
  void Enter_IT_Data_Type_Header_File_Name(wxCommandEvent & event);
  void Enter_IT_Data_Type_Name(wxCommandEvent & event);
  void Clear_Style(wxCommandEvent & event);
  void Reload_Default_Style(wxCommandEvent & event);
  void Save_File_As(wxCommandEvent & event);
  void Set_Caret_Line_Visible(wxCommandEvent & event);
  void Set_Caret_Line_InVisible(wxCommandEvent & event);
  void Use_Block_Caret(wxCommandEvent & event);
  void Use_Default_Caret(wxCommandEvent & event);
  void Clear_Text(wxCommandEvent & event);
  void Load_Default_Cursor(wxCommandEvent & event);
  void Change_Cursor_Type(wxCommandEvent & event);
  void New_File(wxCommandEvent & event);
  void Use_Bold_Styling(wxCommandEvent & event);
  void Close_Directory_Pane(wxAuiManagerEvent & event);
  void Description_Record_Data_Lose_Protection();
  void Auto_Indentation(wxStyledTextEvent & event);
  void KeyboardEvent(wxKeyEvent & event);
  bool Memory_Delete_Condition;
  bool is_bold_style_selected;
  bool is_project_file_selected;
  bool is_descriptor_file_ready_to_record;
  long Sub_Process_ID;
  wxProcess * Process_Pointer;
  wxString Descriptor_File_Path;
  wxString Run_Command;
  wxString Construction_Point;
  wxAuiDockArt * Dock_Art_Pointer;
  wxAuiManager Interface_Manager;
  Custom_wxPanel * Custom_Main_Panel;
  Custom_Notebook * Book_Manager;
  Menu_Bar_Options * MB_Options;
  Custom_Tree_View_Panel * Dir_List_Manager;
  ToolBar_Initializer * ToolBar_Widget;
  Project_File_Selection_Dialog * Pr_File_Select_Dialog;
  wx_Description_Record_Tools Description_Recorder;
  keyboard_event_controler key_events_ctrl;
  Process_Execution_Controller Process_Controller;
  Intro_Page_Loader * Intro_Page_Pointer;
  wxBoxSizer * Panel_Sizer;
  wxDir    * dir_control;
  wxFont   * Default_Font;
  wxFontDialog * Font_Dialog;
  Custom_wxDataViewTreeCtrl * tree_control;
  bool Close_Operation_Status;
  int Toolbar_ID;
  DECLARE_EVENT_TABLE()
};

#endif /* MAINFRAME_H */
