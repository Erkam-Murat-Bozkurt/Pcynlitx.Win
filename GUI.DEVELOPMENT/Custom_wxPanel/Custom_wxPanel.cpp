

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

#include "Custom_wxPanel.h"

Custom_wxPanel::Custom_wxPanel(wxWindow * parent, wxWindowID id,

              const wxPoint &pos, const wxSize &size,

              wxColour background_colour, wxAuiPaneInfo * Pane,

              wxAuiToolBar * toolBar)

  : wxPanel(parent,id,pos,size)
{
     this->background = background_colour;

     this->Pane_Pointer = Pane;

     this->toolBar_pointer = toolBar;

     this->ToolBar_ID = this->toolBar_pointer->GetId();

     this->Memory_Delete_Condition = false;

     this->SetThemeEnabled(false);

     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->SetBackgroundColour(wxColour(240,240,240));

     this->SetDoubleBuffered(true);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

     //this->SetSize(wxSize(800,750));

     this->SetMinSize(wxSize(800,750));


     this->panel_sizer = new wxBoxSizer(wxHORIZONTAL);

     this->Centre(wxBOTH);

     this->CentreOnParent(wxBOTH);

     this->Fit();

     this->SetAutoLayout(true);

     this->ClearBackground();

     this->PaintNow(this);

     this->Show(true);
}

Custom_wxPanel::~Custom_wxPanel()
{
    if(!this->Memory_Delete_Condition)
    {
        this->Memory_Delete_Condition = true;

        this->panel_sizer->Detach(this->book_manager);
    }
}

void Custom_wxPanel::Initialize_Sizer()
{
     this->panel_sizer->Add(this->book_manager,1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM,15);

     this->SetSizer(this->panel_sizer);

     this->panel_sizer->SetSizeHints(this);

     this->panel_sizer->ShowItems(true);

     this->Fit();

     this->SetAutoLayout(true);
}

void Custom_wxPanel::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(240,240,240));

     dc.DrawRectangle(rect.GetX()-5, rect.GetY()-5, rect.GetWidth()+5,rect.GetHeight()+5);
}

void Custom_wxPanel::PaintNow(wxWindow * wnd)
{
     wxClientDC dc(wnd);

     wxSize Rect_Size = wxSize(wnd->GetSize().x+5,wnd->GetSize().y+5);

     wxRect rect(Rect_Size);

     this->DrawBackground(dc,wnd,rect);
}
