
#ifndef KEYBOARD_EVENT_CONTROLER_H
#define KEYBOARD_EVENT_CONTROLER_H

#include <wx/event.h>
#include <wx/stc/stc.h>
#include "Custom_Notebook.h"

class keyboard_event_controler
{
public:
  keyboard_event_controler();
  virtual ~keyboard_event_controler();
  void Receive_Book_Manager(Custom_Notebook * NB_Manager);
  void Undo_Redo_Actions(wxStyledTextCtrl * text_ctrl, wxKeyEvent & event);
  void Auto_Indentation(wxStyledTextEvent & event, wxStyledTextCtrl * text_ctrl);
  void Tab_Indentation(wxStyledTextCtrl * text_ctrl, wxKeyEvent & event);
private:
  bool Check_Is_Line_Empty(wxString line);
  bool Check_Is_Caret_At_Start(wxStyledTextCtrl * text_ctrl, int line_number);
  int  Get_Line_Indentation(wxStyledTextCtrl * text_ctrl, int line_number);
  Custom_Notebook * NB_Manager_Pointer;
  int space_counter;
  bool Is_Caret_At_Start;
  bool is_line_empty;
  bool Ctrl_Key_Press;
  bool S_Key_Press;
  bool Z_Key_Press;
  bool Y_Key_Press;
};

#endif /* KEYBOARD_EVENT_CONTROLER_H */
