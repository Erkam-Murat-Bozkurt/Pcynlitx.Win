
#ifndef CUSTOM_TREE_VIEW_PANEL_H
#define CUSTOM_TREE_VIEW_PANEL_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/dc.h>
#include <wx/event.h>
#include <wx/dcclient.h>
#include <wx/aui/aui.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/aui.h>
#include <wx/aui/framemanager.h>
#include <wx/font.h>
#include <wx/sizer.h>
#include <wx/msgdlg.h>
#include <wx\dataview.h>
#include <Windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Custom_Notebook.h"
#include "Project_Folder_Lister.h"
#include "Custom_DockArt.h"
#include "Custom_Window.h"
#include "Custom_Close_Button.h"



class Custom_Tree_View_Panel : public wxPanel
{
public:
  Custom_Tree_View_Panel(wxFrame * parent, wxWindowID id,

       const wxPoint &pos, const wxSize &size,wxAuiManager * Interface_Manager,

       wxFont Default_Font, int tabctrl_hight, wxColour theme_clr);

  virtual ~Custom_Tree_View_Panel();

  void Clear_Dynamic_Memory();

  void Set_Font(wxFont Default_Font);

  void Load_Project_Directory(wxString Folder);

  void RemoveProjectDirectory();

  wxDataViewTreeCtrl * GetTreeCtrl();

  int GetTotalItemNum(wxString Folder);

  wxString GetItemPath(wxDataViewItem item_number);

  void FileNameEdit(wxDataViewEvent & event);

  bool Get_Panel_Open_Status();

  Custom_Close_Button * close_button;

  Custom_Window * Top_Bar_Window;

  Custom_Window * Title_Window;

  Custom_Window * Bottom_Window;


  wxFrame * Frame_Pointer;

  wxAuiPaneInfo File_List_Widget_Shape;

  wxSize Tree_Control_Size;

  wxPoint Tree_Control_Position;

  wxPoint Top_Bar_Position;

  wxPoint close_button_position;

  wxBoxSizer * Tree_Control_Sizer;

  wxDir * dir_ctrl;

  bool panel_open_status;

  int tab_ctrl_hight;

  void Receive_Topbar_MinSize(wxSize topbar_size);

  void mouseReleased(wxMouseEvent& event);

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect & rect);

  void OnPaint(wxPaintEvent& event);

  void FileSelect(wxDataViewEvent & event);

  void Close_Directory_Pane();

  void PaintNow();

  void Initialize_Sizer();

  void Detach_Windows_From_Sizer();

  void Size_Event(wxSizeEvent & event);

  void Expand_Selected_Item();

  void Expand_Path(wxString path);

  Custom_Notebook * Notebook_Ptr;

  wxBoxSizer * topBar_Sizer;

  wxBoxSizer * title_win_Sizer; 

  wxBoxSizer * tree_Sizer;

  wxBoxSizer * panel_sizer;

  wxBoxSizer * tree_control_sizer;

  wxBoxSizer * close_button_window_sizer;

  wxColour background;

  wxSize Topbar_MinSize;

  wxWindow * close_button_window;

  bool close_button_construction_status;

  bool windows_detach_condition;

  wxSize start_menu_window_size;

protected:
  bool Memory_Delete_Condition;

  wxAuiDockArt * File_List_Dock_Art_Pointer;

  Project_Folder_Lister * Folder_Lister;

  wxDataViewTreeCtrl * tree_control;

  wxAuiManager * Interface_Manager_Pointer;

  wxFont * Directory_List_Font;

  DECLARE_EVENT_TABLE()

};

#endif /* CUSTOM_TREE_VIEW_PANEL_H */
