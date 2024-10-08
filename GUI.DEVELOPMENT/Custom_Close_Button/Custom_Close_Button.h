
#ifndef CUSTOM_CLOSE_BUTTON_H
#define CUSTOM_CLOSE_BUTTON_H

#include <wx\wx.h>
#include <wx\sizer.h>
#include <wx\event.h>
#include <wx\aui\aui.h>
#include <wx\aui\framemanager.h>
#include <wx\sizer.h>
#include "Custom_Window.h"
#include "Project_Folder_Lister.h"

class Custom_Close_Button : public wxWindow
{
public:
    Custom_Close_Button(Custom_Window * parent, wxPoint position,

      wxSize button_size);

    virtual ~Custom_Close_Button();
    void Size_Event(wxSizeEvent & event);
    void Update_Window_Data();
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void render(wxDC& dc);
    void mouseMoved(wxMouseEvent& event);
    void mouseDown(wxMouseEvent& event);
    void mouseWheelMoved(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);
    void rightClick(wxMouseEvent& event);
    void mouseLeftWindow(wxMouseEvent& event);
    void keyPressed(wxKeyEvent& event);
    void keyReleased(wxKeyEvent& event);
    bool pressedDown;
    bool pressedCloseButton;
    wxString text;
    wxPoint Position;
    wxPoint Parent_Position;
    wxBitmap * page_close_icon;
    wxImage page_close_image;
    bool Memory_Delete_Condition;
    wxSize bt_size;
    DECLARE_EVENT_TABLE()
};


#endif /* CUSTOM_CLOSE_BUTTON_H */
