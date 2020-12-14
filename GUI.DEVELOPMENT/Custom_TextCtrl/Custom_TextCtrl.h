
#ifndef CUSTOM_TEXTCTRL_H
#define CUSTOM_TEXTCTRL_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibook.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/stc/stc.h>
#include <wx/event.h>

class Custom_TextCtrl : public wxStyledTextCtrl
{
public:
  Custom_TextCtrl(wxAuiNotebook * parent, wxWindowID id, const wxPoint &pos,

                  const wxSize &size, wxString path);

  virtual ~Custom_TextCtrl();

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect);

  wxString file_path;
};

#endif /* CUSTOM_TEXTCTRL_H */
