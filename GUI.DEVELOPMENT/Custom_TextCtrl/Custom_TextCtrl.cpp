

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

#include "Custom_TextCtrl.h"

Custom_TextCtrl::Custom_TextCtrl(wxAuiNotebook * parent, wxWindowID id,

                  const wxPoint &pos, const wxSize &size, wxString path)

  : wxStyledTextCtrl(parent,id,pos,size)
{
    this->SetDoubleBuffered(true);

    this->SetBackgroundStyle(wxBG_STYLE_PAINT);

    this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

    this->SetExtraStyle(wxCLIP_CHILDREN);

    this->file_path = path;

    this->SetSize(parent->GetClientSize());

    this->Centre();
}

Custom_TextCtrl::~Custom_TextCtrl(){

}

void Custom_TextCtrl::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(230,230,230));

     dc.DrawRectangle(rect.GetX()-5, rect.GetY()-5, rect.GetWidth()+5, rect.GetHeight()+5);
};
