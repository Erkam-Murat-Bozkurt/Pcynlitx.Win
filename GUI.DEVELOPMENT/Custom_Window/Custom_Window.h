
#ifndef CUSTOM_WINDOW_H
#define CUSTOM_WINDOW_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/event.h>
#include <wx/gdicmn.h>

class Custom_Window : public wxWindow
{
public:
    Custom_Window(wxPanel * parent, wxPoint position, wxSize window_size);
    virtual ~Custom_Window();
    void paintEvent(wxPaintEvent & evt);
    void Size_Event_Handler(wxSizeEvent & event);
    void Receive_Button_Position(wxPoint button_position);
    void Receive_Button_ID(int Button_ID);
    void Receive_Tab_ctrl_Hight(int hight);
    void paintNow();
    void render(wxDC& dc);
    wxPoint Position;
    wxPoint Button_Position;
    int Button_ID;
    wxBitmap * page_close_icon;
    int tab_ctrl_hight;
    bool Memory_Delete_Condition;
};


#endif /* CUSTOM_WINDOW_H */
