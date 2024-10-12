






#ifndef PROJECT_FILE_SELECTION_WINDOW_HPP
#define PROJECT_FILE_SELECTION_WINDOW_HPP

#include <wx/wx.h>
#include <wx\sizer.h>
#include <wx\event.h>
#include <wx\aui\aui.h>
#include <wx\aui\framemanager.h>
#include <wx\sizer.h>
#include <wx\dataview.h>
#include <wx\textdlg.h>
#include <wx\msgdlg.h>
#include <wx\dir.h>
#include <wx/dialog.h>
#include "Custom_Message_Dialog.hpp"
#include "Custom_System_Interface.h"
#include "Cpp_FileOperations.h"



enum
{
  ID_CONSTRUCT_EMPTY_PROJECT_FILE = 200,
  ID_SELECT_AN_EXISTING_PROJECT_FILE = 201
};


class Project_File_Selection_Window : public wxDialog 
{
public:
    Project_File_Selection_Window(wxWindow * parent, wxWindowID id, 
    
    const wxString & title=wxT("PROJECT FILE SELECTION PANEL"), 
    
    const wxPoint & pos=wxDefaultPosition, const wxSize & size=wxSize(700,500));

    virtual ~Project_File_Selection_Window();

    void Receive_Descriptor_File_Path(wxString * DesPATH);

    void Receive_Project_File_Selection_Status(bool * status);

    bool get_Descriptor_File_Selection_Status() const;

    wxString ExeFileName;

    wxString FilePath;

protected:

    void DrawBackground(wxDC & dc, wxWindow *  wnd, const wxRect& rect);

    void OnPaint(wxPaintEvent & event);

    void Construct_Empty_Project_File(wxCommandEvent & event);

    void Select_Project_File(wxCommandEvent & event);

    void Select_File();

    Cpp_FileOperations FileManager;

    Custom_System_Interface SysInt;

    wxString * Descriptor_File_Path_Pointer;

    wxString DataType;

    wxBitmap * new_empty_file;

    wxBitmap * open_existing_file;

    wxBitmap * exclamation_mark_bmp;


    char opr_sis;

    bool * Descriptor_File_Selection_Status;


    wxWindow * Parent_Window;

    wxBoxSizer * Frame_Sizer;

    wxBoxSizer * EMPF_Cons_Panel_Sizer;

    wxBoxSizer * PRFS_Panel_Sizer;

    wxBoxSizer * EMPF_Cons_Button_Panel_Sizer;

    wxBoxSizer * PRFS_Button_Panel_Sizer;


    wxBoxSizer * EMPF_Cons_Text_Panel_Sizer;

    wxBoxSizer * PRFS_Text_Panel_Sizer;


    wxBoxSizer * Left_Panel_Sizer;

    wxBoxSizer * Right_Panel_Sizer;


    wxButton * Empty_Project_File_Button;

    wxButton * Project_File_Selection_Button;

    
    wxPanel  * Empty_Project_File_Panel;

    wxPanel  * Project_File_Selection_Panel;

    wxPanel  * Empty_Project_File_Button_Panel;

    wxPanel  * Project_File_Selection_Button_Panel;

    wxPanel  * Empty_Project_File_Text_Panel;

    wxPanel  * Project_File_Selection_Text_Panel;

    DECLARE_EVENT_TABLE()
};


#endif /* PROJECT_FILE_SELECTION_WINDOW_HPP */
