
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

#include "Custom_Window.h"

Custom_Window::Custom_Window(wxPanel * parent, wxPoint position, wxSize window_size) :

     wxWindow(parent, wxID_ANY,position,window_size)
{
    this->Memory_Delete_Condition = false;

    this->SetBackgroundStyle(wxBG_STYLE_PAINT);

    this->SetExtraStyle(wxFULL_REPAINT_ON_RESIZE);

    this->SetDoubleBuffered(true);

    this->SetSize(window_size);

    this->SetMinSize(window_size);

    this->page_close_icon = new wxBitmap(wxT("C:\\Program Files\\Pcynlitx\\icons\\pane_close_icon.png"), wxBITMAP_TYPE_ANY);

    this->Position = position;

    this->tab_ctrl_hight = 0;

    this->SetBackgroundColour(wxColour(240,240,240));

    this->SetPosition(this->Position);

    this->paintNow();
}

Custom_Window::~Custom_Window()
{
     if(!this->Memory_Delete_Condition)
     {
         this->Memory_Delete_Condition = true;

         this->page_close_icon->~wxBitmap();
     }
}

void Custom_Window::paintEvent(wxPaintEvent & event)
{
     event.Skip(true);

     wxPaintDC dc(this);

     this->render(dc);

     wxWindowList & children = this->GetChildren();

     for( wxWindowList::compatibility_iterator it = children.GetFirst(); it; it = it->GetNext())
     {
          wxWindow * current = (wxWindow *)it->GetData();

          int id = current->GetId();

          if(id == this->Button_ID){

             current->Refresh();

             current->Update();
          }
     }
}

void Custom_Window::paintNow()
{
    wxClientDC dc(this);

    this->render(dc);
}

void Custom_Window::render(wxDC & dc)
{
    wxRect rect(this->GetSize());

    dc.SetBrush(wxColour(240,240,240));

    dc.DrawRectangle(rect.GetX()-1, rect.GetY()-1, rect.GetWidth()+5,rect.GetHeight()+15);
}

void Custom_Window::Receive_Button_ID(int button_id){

     this->Button_ID = button_id;
}

void Custom_Window::Receive_Tab_ctrl_Hight(int hight){

     this->tab_ctrl_hight = hight;
}
