
#ifndef CUSTOM_WXPANEL_H
#define CUSTOM_WXPANEL_H

#include <wx/panel.h>
#include <wx/dc.h>
#include <wx/event.h>
#include <wx/dcclient.h>
#include <wx/aui/aui.h>
#include <wx/aui/framemanager.h>
#include <wx/sizer.h>
#include "Custom_Tree_View_Panel.h"

class Custom_wxPanel : public wxPanel
{
public:
  Custom_wxPanel(wxWindow * parent, wxWindowID id, const wxPoint &pos,

                 const wxSize &size, wxColour background,

                 wxAuiPaneInfo * Pane, wxAuiToolBar * toolBar);

  Custom_wxPanel(const Custom_wxPanel & orig);

  virtual ~Custom_wxPanel();

  void Receive_Book_Manager_Window(wxWindow * wnd){

       this->book_manager = wnd;
  }

  void Update(){};

  void Initialize_Sizer();

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect);

  void PaintNow(wxWindow * wnd);

  int ToolBar_ID = 0;

  wxAuiToolBar * toolBar_pointer;

  wxAuiPaneInfo * Pane_Pointer;

  wxColour background;

  wxWindow * book_manager;

  wxBoxSizer * panel_sizer;

  wxEvtHandler Event_Handler;

  bool Memory_Delete_Condition;
};

#endif /* CUSTOM_PANEL */
