
#ifndef CUSTOM_WXDATAVIEWTREECTRL_H
#define CUSTOM_WXDATAVIEWTREECTRL_H

#include <wx/wx.h>
#include <wx/dataview.h>
#include <wx/font.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/dc.h>
#include <wx/dcclient.h>
#include <iostream>


class Custom_wxDataViewTreeCtrl : public wxDataViewTreeCtrl
{
public:
  Custom_wxDataViewTreeCtrl(wxWindow *parent, wxWindowID id,

        const wxPoint & pos,

        const wxSize & size, long style);

  virtual ~Custom_wxDataViewTreeCtrl();

  wxBackgroundStyle GetBackgroundStyle( )	const
  {
     return wxBG_STYLE_CUSTOM;
  }

  void Size_Event(wxSizeEvent & event);

  void Update(){};

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect);

  void PaintNow();

  void Receive_Position(wxPoint control_position);

  wxWindow * Parent_Window_Pointer;

  wxPoint Position;
};

#endif /* CUSTOM_WXDATAVIEWTREECTRL_H */
