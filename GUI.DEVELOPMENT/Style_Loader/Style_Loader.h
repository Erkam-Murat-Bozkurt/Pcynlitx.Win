#ifndef STYLE_LOADER_H
#define STYLE_LOADER_H

#include <wx/wx.h>
#include <wx/stc/stc.h>
#include <wx/font.h>
#include <wx/colour.h>

enum
{
    MARGIN_LINE_NUMBERS,
    MARGIN_FOLD
};

class Style_Loader
{
public:
  Style_Loader();
  virtual ~Style_Loader();
  void Set_Lexer_Style(wxFont Default_Font, wxStyledTextCtrl * text_ctrl);
  void Set_Style_Font(wxFont Font, wxStyledTextCtrl * text_ctrl);
  void Set_Margin_Style(wxStyledTextCtrl * text_ctrl);
  void Clear_Text_Control_Style(wxStyledTextCtrl * text_ctrl, wxFont Default_Font);
  void Reload_Text_Control_Style(wxStyledTextCtrl * text_ctrl, wxFont Default_Font);
  void Use_Bold_Styling(wxStyledTextCtrl * text_ctrl);
};

#endif /* STYLE_LOADER_H */
