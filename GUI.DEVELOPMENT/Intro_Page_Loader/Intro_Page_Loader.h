
#ifndef INTRO_PAGE_LOADER
#define INTRO_PAGE_LOADER

#include <wx/wx.h>
#include <wx/event.h>
#include <wx/panel.h>
#include <wx/stc/stc.h>
#include <wx/arrstr.h>
#include <wx/bitmap.h>
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/imaglist.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/layout.h>
#include <iostream>
#include "Event_ID_Numbers.h"

class Intro_Page_Loader : public wxWindow
{
public:
  Intro_Page_Loader(wxWindow * parent, wxSize page_size, int tab_ctrl_height);

  Intro_Page_Loader(const Intro_Page_Loader & orig);

  virtual ~Intro_Page_Loader();

  void OnPaint(wxPaintEvent& event);

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& _rect);

  void Receive_Intro_Page_Open_Status(bool * is_Intro_Page_Open);

  wxWindow * Parent_Window_Pointer;
  int tab_ctrl_height;
  void Close_Intro_Page();
  void Clear_Dynamic_Memory();
  bool * Intro_Page_Open_Status_Pointer;
private:
  bool Memory_Delete_Condition;
  wxBitmap * intro_page_bitmap;
  wxImage intro_page_image;
};

#endif /* INTRO_PAGE_LOADER */
