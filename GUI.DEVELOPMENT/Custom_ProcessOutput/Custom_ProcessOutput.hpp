


#ifndef CUSTOM_PROCESSOUTPUT_HPP
#define CUSTOM_PROCESSOUTPUT_HPP

#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/dc.h>
#include <wx/event.h>
#include <wx/dcclient.h>
#include <wx/aui/aui.h>
#include <wx/aui/framemanager.h>
#include <wx/sizer.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include "Custom_DockArt.h"
#include "Custom_Tree_View_Panel.h"
#include "Custom_Message_Dialog.hpp"


enum
{
  ID_CLOSE_WINDOW = 70
};

class Custom_ProcessOutput : public wxFrame
{
public:

Custom_ProcessOutput(wxFrame *parent, wxWindowID id=wxID_ANY, const wxString & title=wxT(""), 

   const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxSize(750,600), 
   
   long style=wxDEFAULT_FRAME_STYLE | wxSTAY_ON_TOP);

  virtual ~Custom_ProcessOutput(){};

  wxTextCtrl * GetTextControl() const;

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect);

  void SetBoldFont();

  void SetLightFont();

  void PaintNow(wxWindow * wnd);

  void Construct_Output_Window();

  void OnSize(wxSizeEvent & event);

  void PrintProcessOutput(wxString text);

  bool * library_construction_status;

  Custom_Tree_View_Panel * Dir_List_Manager;

  wxString Construction_Point;

  int progress_point;

  char * cmd;

private:
  
  void OnClose(wxCloseEvent & ent);

  void CloseWindow(wxCommandEvent & event);


  wxPanel * text_ctrl_panel;

  wxPanel * close_panel;

  wxPanel * dialog_panel;

  wxGauge * dialog;

  wxTextCtrl * textctrl;

  wxBoxSizer * ctrl_box;

  wxBoxSizer * close_box;

  wxBoxSizer * dialog_box;

  wxBoxSizer * close_panel_sizer;

  wxBoxSizer * close_button_sizer;

  wxBoxSizer * frame_box;

  wxButton * CloseButton;

  wxFont   * Default_Font;

  wxString directory_open_location;

  bool Memory_Delete_Condition;

  bool progress_cond;

  bool window_open_status;

  DECLARE_EVENT_TABLE()
};

#endif /* CUSTOM_PROCESSOUTPUT_HPP */
