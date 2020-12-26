
#ifndef PROJECT_FILE_SELECTION_DIALOG_H
#define PROJECT_FILE_SELECTION_DIALOG_H

#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filectrl.h>
#include <wx/button.h>
#include <wx/dirctrl.h>
#include <wx/utils.h>
#include <wx/filedlg.h>
#include <wx/filepicker.h>


class Project_File_Selection_Dialog
{
public:
  Project_File_Selection_Dialog(wxFrame * Frame);
  virtual ~Project_File_Selection_Dialog();
  wxDialog * Get_Project_File_Selection_Dialog();
  wxFileCtrl * Get_File_Selection_Control();
private:
  wxDialog * File_Selection_Dialog;
  wxPanel * File_Selection_Panel;
  wxFileCtrl * File_Selection_Control;
  wxButton * SelectButton;
  wxButton * closeButton;
  wxBoxSizer * vbox;
  wxBoxSizer * hbox;
  wxBoxSizer * file_selection_sizer;
};

#endif /* PROJECT_FILE_SELECTION_DIALOG_H */
