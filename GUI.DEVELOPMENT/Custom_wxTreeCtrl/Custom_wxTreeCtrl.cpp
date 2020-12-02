
#include "Custom_wxTreeCtrl.h"

BEGIN_EVENT_TABLE(Custom_wxTreeCtrl,wxWindow)

    EVT_SIZE(Custom_wxTreeCtrl::Size_Event)

END_EVENT_TABLE()


Custom_wxTreeCtrl::Custom_wxTreeCtrl(wxWindow *parent, wxWindowID id,

  const wxPoint & pos,

  const wxSize & size, long style) : wxTreeCtrl(parent,id,pos,size,style)
  {
     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->Parent_Window_Pointer = parent;

     this->SetBackgroundColour(wxColour(250,250,250));

     this->SetDoubleBuffered(true);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

     this->ClearBackground();

     this->SetMinSize(this->Parent_Window_Pointer->GetClientSize());

     this->SetSize(this->Parent_Window_Pointer->GetClientSize());

     this->Fit();

     this->Layout();

     this->CentreOnParent(wxBOTH);

     this->Refresh();
 }

 Custom_wxTreeCtrl::~Custom_wxTreeCtrl()
 {

 }

 void Custom_wxTreeCtrl::PaintNow(){

       wxClientDC dc(this);

       wxRect rect(this->GetSize());

       this->DrawBackground(dc,this,rect);
 }

void Custom_wxTreeCtrl::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect){

     dc.SetBrush(wxColour(230,230,230));

     dc.DrawRectangle(rect.GetX(), rect.GetY(), rect.GetWidth(),rect.GetHeight());
}

void Custom_wxTreeCtrl::Receive_Position(wxPoint control_position){

     this->Position = control_position;
}

void Custom_wxTreeCtrl::Size_Event(wxSizeEvent & event)
{
      event.Skip(true);

      wxWindow * parent = this->GetParent();

      this->SetSize(parent->GetClientSize());
}
