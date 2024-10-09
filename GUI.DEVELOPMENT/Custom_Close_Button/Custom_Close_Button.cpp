
/*

 * Copyright (C) { Erkam Murat Bozkurt } - All Rights Reserved
 * 
 * This source code is protected under international copyright law.  All rights
 * reserved and protected by the copyright holders.
 * 
 * This file is confidential and only available to authorized individuals with the
 * permission of the copyright holders.  If you encounter this file and do not have
 * permission, please contact the copyright holders and delete this file.

*/

#include "Custom_Close_Button.h"



BEGIN_EVENT_TABLE(Custom_Close_Button,wxPanel)

    EVT_LEFT_DOWN(Custom_Close_Button::mouseDown)

    EVT_LEFT_UP(Custom_Close_Button::mouseReleased)

    EVT_LEAVE_WINDOW(Custom_Close_Button::mouseLeftWindow)

    EVT_PAINT(Custom_Close_Button::paintEvent)

END_EVENT_TABLE()


Custom_Close_Button::Custom_Close_Button(Custom_Window * parent, wxPoint position,

  wxSize button_size) :

  wxWindow(parent, wxID_ANY,position,button_size)
{
    this->Memory_Delete_Condition = false;

    this->bt_size = button_size;

    this->SetSize(this->bt_size);

    this->SetThemeEnabled(false);

    this->SetBackgroundStyle(wxBG_STYLE_PAINT);

    this->SetExtraStyle(wxFULL_REPAINT_ON_RESIZE);

    this->GetEventHandler()->Bind(wxEVT_SIZE,&Custom_Close_Button::Size_Event,this,wxID_ANY);

    this->page_close_icon = new

                wxBitmap(wxT("C:\\Program Files\\Pcynlitx\\icons\\pane_close_icon.png"),wxBITMAP_TYPE_ANY);

    this->SetMinSize(this->page_close_icon->GetSize());

    this->text = wxT("x");

    this->Parent_Position = parent->GetPosition();

    this->Position = position;

    this->pressedDown = false;

    this->pressedCloseButton = false;

    this->SetPosition(this->Position);
}

Custom_Close_Button::~Custom_Close_Button()
{
    if(!this->Memory_Delete_Condition)
    {
       this->Memory_Delete_Condition = true;

       delete this->page_close_icon;
    }
}

void Custom_Close_Button::paintEvent(wxPaintEvent & evt)
{
    this->Update_Window_Data();

    wxPaintDC dc(this);

    render(dc);
}

void Custom_Close_Button::paintNow()
{
    this->Update_Window_Data();

    wxClientDC dc(this);
    
    this->render(dc);
}

void Custom_Close_Button::Size_Event(wxSizeEvent & event)
{
      event.Skip(true);

      this->SetSize(this->bt_size);

      this->paintNow();
}

void Custom_Close_Button::Update_Window_Data(){

     wxRect Parent_Rect = this->GetParent()->GetRect();

     wxSize Parent_Size = this->GetParent()->GetSize();

     wxSize Button_Size = this->GetSize();

     wxPoint Top_Right_Corner = Parent_Rect.GetTopRight();


     wxRect rect(this->GetSize());

     int new_point_x = Top_Right_Corner.x - Button_Size.x -10 ;

     int y_extend_for_button_window = (Parent_Size.y - Button_Size.y)/2;

     int new_point_y = Top_Right_Corner.y + y_extend_for_button_window;

     this->SetPosition(wxPoint(new_point_x,new_point_y));
}

void Custom_Close_Button::render(wxDC&  dc)
{
    wxRect rect(this->GetSize());

    dc.SetBrush(wxColour(240,240,240));

    dc.DrawRectangle(rect.GetX()-1, rect.GetY()-1, rect.GetWidth()+3,rect.GetHeight()+3);

    wxSize Bitmap_Size = this->page_close_icon->GetSize();

    wxSize Panel_Size = rect.GetSize();

    int x_extend = Panel_Size.x - Bitmap_Size.x;

    int y_extend = Panel_Size.y - Bitmap_Size.y;

    dc.DrawBitmap(*this->page_close_icon,wxPoint(x_extend/2,y_extend/2));
}

void Custom_Close_Button::mouseDown(wxMouseEvent& event)
{
    this->pressedDown = true;

    this->paintNow();
}
void Custom_Close_Button::mouseReleased(wxMouseEvent& event)
{
    event.Skip(true);

    event.ResumePropagation(5);

    this->pressedDown = false;

    this->pressedCloseButton = true;

    this->paintNow();
}

void Custom_Close_Button::mouseLeftWindow(wxMouseEvent& event)
{
    if (this->pressedDown)
    {
        this->pressedDown = false;

        this->paintNow();
    }
}
