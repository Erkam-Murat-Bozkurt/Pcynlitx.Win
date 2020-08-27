

#ifndef HELP_PAGE_LOADER
#define HELP_PAGE_LOADER

#include <wx/wx.h>
#include <wx/event.h>
#include <wx/panel.h>
#include <wx/stc/stc.h>
#include <wx/arrstr.h>
#include <wx/stattext.h>
#include <wx/bitmap.h>
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/imaglist.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/layout.h>
#include <wx/hyperlink.h>
#include <wx/stattext.h>
#include <iostream>

class Help_Page_Loader : public wxWindow
{
public:
  Help_Page_Loader(wxWindow * parent, wxSize page_size);

  Help_Page_Loader(const Help_Page_Loader & orig);

  virtual ~Help_Page_Loader();

  void OnPaint(wxPaintEvent& event);

  void Initialize_Help_Page_Text(wxWindow * Help_page_window);

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& _rect);

  wxPoint Determine_Hyperlink_Position(wxStaticText * text);

  void Set_Text_Font_Style(wxStaticText * text, int Font_Size, bool is_bold);

  wxPoint Determine_Static_Text_Position(wxPoint position);

  void Receive_Help_Page_Open_Status(bool * is_Intro_Page_Open);

  wxWindow * Parent_Window_Pointer;

  void Close_Intro_Page();

  void Clear_Dynamic_Memory();

  wxPoint hyperlink_position;

  wxPoint text_position;

  wxStaticText ** text_list;

  wxHyperlinkCtrl ** link_list;

  bool * Help_Page_Open_Status_Pointer;
private:
  bool Memory_Delete_Condition;
  wxStaticText * Help_Document_Title;
  wxStaticText * Project_Web_Page;
};

#endif /* INTRO_PAGE_LOADER */
