
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
