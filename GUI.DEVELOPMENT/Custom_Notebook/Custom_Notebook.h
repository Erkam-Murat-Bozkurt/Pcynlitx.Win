
#ifndef CUSTOM_NOTEBOOK_H
#define CUSTOM_NOTEBOOK_H

#include <wx/wx.h>
#include <wx\frame.h>
#include <wx/panel.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibook.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/dockart.h>
#include <wx/renderer.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/stc/stc.h>
#include <wx/font.h>
#include <wx/arrstr.h>
#include <wx/gdicmn.h>
#include <wx/bitmap.h>
#include <wx/imaglist.h>
#include <wx/scrolwin.h>
#include <wx/event.h>
#include <math.h>
#include <wx/stattext.h>
#include "Intro_Page_Loader.h"
#include "Style_Loader.h"
#include "Custom_TextCtrl.h"
#include "Custom_TabArt.h"
#include "Event_ID_Numbers.h"

struct Text_Ctrl_Data
{
  Custom_TextCtrl * Text_Ctrl;
  Intro_Page_Loader * Intro_Page_Pointer;
  int  Window_ID;
  bool Document_Change_Condition;
  bool Is_Pointer_Free;
  bool Document_Change_In_File_Open;
  bool Is_Page_Open;
  bool Is_This_Text_File;
  wxString File_Path;
};

class Custom_Notebook : public wxAuiNotebook
{
public:
  Custom_Notebook(wxFrame * frame,wxPanel * parent, wxAuiManager * Interface_Manager,

         wxFont Default_Font,wxSize size, wxColour theme_clr);

  virtual ~Custom_Notebook();
  void Size_Event(wxSizeEvent & event);
  void OnPaint(wxPaintEvent & event);
  void DrawBackground(wxDC & dc, wxWindow *  wnd, const wxRect& rect);
  void Initialization();
  void Selection_Changing(wxAuiNotebookEvent & event);
  void NoteBook_Page_Closed(wxAuiNotebookEvent & event);
  void Document_Change(wxStyledTextEvent & event);
  void Determine_Current_Page(wxAuiNotebookEvent & event);
  void OpenIntroPage();
  void PaintNow(wxWindow * wnd);
  void Change_Cursor_Type();
  void Load_Default_Cursor();
  void Set_Caret_Line_InVisible();
  void Set_Caret_Line_Visible();
  void Use_Default_Caret();
  void Use_Block_Caret();
  void Add_New_File(wxString File_Path);
  void Open_File(wxString File_Path);
  void Set_Font(wxFont Default_Font);
  void Set_Lexer_Style(wxFont Default_Font);
  void Clear_Text_Control_Style(Custom_TextCtrl * text_ctrl);
  void Set_Style_Font(wxFont Font);
  void OnClose();
  void Clear_Style();
  void Reload_Style();
  void Use_Bold_Styling();
  void SelectIntroPage();
  void Select_File(wxString File_Path);
  void File_Save();
  bool Is_File_Open(wxString File_Path);
  bool Get_Intro_Page_Close_Condition();
  int Get_Intro_Page_Id();
  wxString Get_Selected_Text_Ctrl_File_Path();
  Custom_TextCtrl * Get_Selected_Text_Ctrl();
  Custom_Notebook * Get_NoteBook_Pointer();
  size_t GetIndex_FromPath(wxString path);
  bool Get_Style_Change_Condition() const;
  int  Get_Current_Page_Index() const;
  int  Get_Open_File_Number() const;
  bool Is_Current_Page_Text_File() const;
  wxString Get_Notebook_Page_File_Path(int index);
  wxAuiManager * Interface_Manager_Pointer;
  Custom_TabArt * Custom_Notebook_TabArt;
  int  Current_Page_Record_Index;
  bool Style_Change_Operation;
  Text_Ctrl_Data NoteBook_Page_Data[20];
  bool Is_Intro_Page_Open;
  bool Is_Help_Page_Open;
private:
  int OpenFileNumber;
  void Determine_File_Short_Name(wxString File_Long_Name);
  int Get_Empty_Pointer_Index_Number();
  wxFont * Default_Font;
  wxString File_Short_Name;
  wxFrame * frame_ptr;
  Style_Loader Text_Style_Loader;
  int Selection;
  int Empty_Pointer_Index_Number;
  int Introduction_Page_Id;
  bool Memory_Delete_Condition;
  bool File_Open_Status;
};

#endif /* CUSTOM_NOTEBOOK_H */
