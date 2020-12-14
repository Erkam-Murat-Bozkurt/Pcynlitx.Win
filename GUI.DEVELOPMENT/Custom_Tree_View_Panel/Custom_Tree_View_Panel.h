
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
#include "Custom_wxTreeCtrl.h"
#include "Project_Folder_Lister.h"
#include "Custom_DockArt.h"
#include "Custom_Window.h"
#include "Custom_Close_Button.h"


class Custom_Tree_View_Panel : public wxPanel
{
public:
  Custom_Tree_View_Panel(wxFrame * parent, wxWindowID id,

       const wxPoint &pos, const wxSize &size,wxAuiManager * Interface_Manager,

       wxFont Default_Font, int tabctrl_hight);

  Custom_Tree_View_Panel(const Custom_Tree_View_Panel & orig);

  virtual ~Custom_Tree_View_Panel();

  void Clear_Dynamic_Memory();

  void Set_Font(wxFont Default_Font);

  void Load_Project_Directory(wxString Folder);

  void RemoveProjectDirectory();

  Custom_wxTreeCtrl * GetTreeCtrl();

  wxString GetItemPath(wxTreeItemId item_number);

  bool Get_Panel_Open_Status();

  Custom_Close_Button * close_button;

  Custom_Window * Top_Bar_Window;

  wxFrame * Frame_Pointer;

  wxAuiPaneInfo File_List_Widget_Shape;

  wxSize Tree_Control_Size;

  wxPoint Tree_Control_Position;

  wxPoint Top_Bar_Position;

  wxPoint close_button_position;

  wxBoxSizer * Tree_Control_Sizer;

  bool panel_open_status;

  int tab_ctrl_hight;

  void Receive_Topbar_MinSize(wxSize topbar_size);

  void mouseReleased(wxMouseEvent& event);

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect);

  void OnPaint(wxPaintEvent& event);

  void Close_Directory_Pane();

  void PaintNow();

  void Initialize_Sizer();

  void Detach_Windows_From_Sizer();

  void Size_Event(wxSizeEvent & event);

  wxBoxSizer * panel_sizer;

  wxBoxSizer * tree_control_sizer;

  wxBoxSizer * close_button_window_sizer;

  wxColour background;

  wxSize Topbar_MinSize;

  wxWindow * close_button_window;

  bool close_button_construction_status;

  bool windows_detach_condition;

protected:
  bool Memory_Delete_Condition;

  wxAuiDockArt * File_List_Dock_Art_Pointer;

  Project_Folder_Lister * Folder_Lister;

  Custom_wxTreeCtrl * tree_control;

  wxAuiManager * Interface_Manager_Pointer;

  wxFont Directory_List_Font;
};

#endif /* CUSTOM_PANEL */
