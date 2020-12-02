
#ifndef CUSTOM_WXTREECTRL_H
#define CUSTOM_WXTREECTRL_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/event.h>
#include <wx/sizer.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/treectrl.h>
#include <wx/treebase.h>

class Custom_wxTreeCtrl : public wxTreeCtrl
{
public:
  Custom_wxTreeCtrl(wxWindow *parent, wxWindowID id,

        const wxPoint & pos,

        const wxSize & size, long style);

  virtual ~Custom_wxTreeCtrl();

  wxBackgroundStyle GetBackgroundStyle( )	const
  {
     return wxBG_STYLE_CUSTOM;
  }

  void Size_Event(wxSizeEvent & event);

  //void Update(){};

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect);

  void PaintNow();

  void Receive_Position(wxPoint control_position);

  wxWindow * Parent_Window_Pointer;

  wxPoint Position;

  DECLARE_EVENT_TABLE()
};

#endif /* CUSTOM_WXTREECTRL_H */
