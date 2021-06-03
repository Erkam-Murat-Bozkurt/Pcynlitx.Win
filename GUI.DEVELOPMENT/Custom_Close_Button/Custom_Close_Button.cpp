
/*

Copyright ©  2021,  Erkam Murat Bozkurt

This file is part of the research project which is carried by Erkam Murat Bozkurt.

This is a free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation
either version 3 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include "Custom_Close_Button.h"

BEGIN_EVENT_TABLE(Custom_Close_Button,wxPanel)

    EVT_MOTION(Custom_Close_Button::mouseMoved)

    EVT_LEFT_DOWN(Custom_Close_Button::mouseDown)

    EVT_LEFT_UP(Custom_Close_Button::mouseReleased)

    EVT_RIGHT_DOWN(Custom_Close_Button::rightClick)

    EVT_LEAVE_WINDOW(Custom_Close_Button::mouseLeftWindow)

    EVT_KEY_DOWN(Custom_Close_Button::keyPressed)

    EVT_KEY_UP(Custom_Close_Button::keyReleased)

    EVT_MOUSEWHEEL(Custom_Close_Button::mouseWheelMoved)

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

                wxBitmap(wxT("C:\\Program Files\\Pcynlitx\\icons\\pane_close_icon.png"),

                wxBITMAP_TYPE_ANY);

    this->SetMinSize(this->page_close_icon->GetSize());

    this->text = wxT("x");

    this->Parent_Position = parent->GetPosition();

    this->Position = position;

    this->pressedDown = false;

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

    dc.SetBrush(wxColour(235,235,235));

    dc.DrawRectangle(rect.GetX()-1, rect.GetY()-1, rect.GetWidth()+2,rect.GetHeight()+2);

    wxSize Bitmap_Size = this->page_close_icon->GetSize();

    wxSize Panel_Size = rect.GetSize();

    int x_extend = Panel_Size.x - Bitmap_Size.x;

    int y_extend = Panel_Size.y - Bitmap_Size.y;

    dc.DrawBitmap(*this->page_close_icon,wxPoint(2+x_extend/2,2+y_extend/2));
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

// currently unused events
void Custom_Close_Button::mouseMoved(wxMouseEvent& event) {}
void Custom_Close_Button::mouseWheelMoved(wxMouseEvent& event) {}
void Custom_Close_Button::rightClick(wxMouseEvent& event) {}
void Custom_Close_Button::keyPressed(wxKeyEvent& event) {}
void Custom_Close_Button::keyReleased(wxKeyEvent& event) {}
