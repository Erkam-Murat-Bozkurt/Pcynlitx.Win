




#ifndef PROJECT_DESCRIPTIONS_PRINTER_HPP
#define PROJECT_DESCRIPTIONS_PRINTER_HPP

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
#include <wx/caret.h>
#include <winuser.h>
#include <wx/msgdlg.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Custom_DockArt.h"
#include "Custom_System_Interface.h"
#include "Custom_Tree_View_Panel.h"
#include "Descriptor_File_Reader.h"

enum
{
  ID_CLOSE_DESCRIPTION_WINDOW = 80
};

class Project_Descriptions_Printer : public wxFrame
{
public:

Project_Descriptions_Printer(wxFrame *parent, wxWindowID id=wxID_ANY, const wxString & title=wxT(""), 

   const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxSize(1000,800), 
   
   long style=wxDEFAULT_FRAME_STYLE | wxSTAY_ON_TOP);

  virtual ~Project_Descriptions_Printer();

  wxTextCtrl * GetTextControl() const;

  void Receive_Descriptor_File_Directory(char * DescriptorFileDirectory);

  void Receive_Descriptor_File_Name(char * DescriptorFileName);

  void Receive_Descriptor_File_Path(wxString DesPATH);

  bool Read_Descriptions();

  void Print_Descriptions();

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect);

  void PaintNow(wxWindow * wnd);

  void Construct_Text_Panel();

  void OnSize(wxSizeEvent & event);

  void Construct_Close_Panel();

  void closeWindow(wxCommandEvent & event);

  void setSizers();

  int  GetLogNumber();

  bool GetWindowsOpenStatus();

  bool Get_Syntax_Error_Status();

  bool Get_Invalid_Descriptor_File_Status();

  bool Get_Gui_Read_Success_Status();

private:

  void CloseWindow(wxCommandEvent & event);

  void OnPaint(wxPaintEvent & event);

  std::string ConvertStdString(char * str);

  void Delete_Spaces_on_String(std::string * str);

  Descriptor_File_Reader Des_Reader;

  wxString Descriptor_File_Path;

  wxScrolledWindow * scroll_win;

  wxPanel * text_ctrl_panel;

  wxPanel * close_panel;

  wxTextCtrl * textctrl;

  wxBoxSizer * ctrl_box;

  wxBoxSizer * close_box;

  wxBoxSizer * close_panel_sizer;

  wxBoxSizer * text_panel_sizer;

  wxBoxSizer * frame_sizer;

  wxButton * CloseButton;

  wxFont   * Default_Font;

  bool Memory_Delete_Condition;

  bool window_open_status;

  bool read_success;

  bool read_error_status;

  bool invalid_descriptor_file_status;

  bool descriptor_file_read_success;

  bool syntax_error_status;

  int log_num;

  DECLARE_EVENT_TABLE()
};

#endif /* PROJECT_DESCRIPTIONS_PRINTER_HPP */
