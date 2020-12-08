
#include "Custom_wxTreeCtrl.h"


Custom_wxTreeCtrl::Custom_wxTreeCtrl(wxWindow *parent, wxWindowID id,

  const wxPoint & pos,

  const wxSize & size, long style) : wxTreeCtrl(parent,id,pos,size,style)
  {
     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->Parent_Window_Pointer = parent;

     this->GetEventHandler()->Bind(wxEVT_SIZE,&Custom_wxTreeCtrl::Size_Event,this,wxID_ANY);

     this->GetEventHandler()->Bind(wxEVT_KILL_FOCUS,&Custom_wxTreeCtrl::kill_focus_event,this,wxID_ANY);

     this->GetEventHandler()->Bind(wxEVT_SET_FOCUS,&Custom_wxTreeCtrl::set_focus_event,this,wxID_ANY);


     wxFont tree_font(9,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,

                          wxFONTWEIGHT_NORMAL,false,"Liberation Mono");

     this->SetFont(tree_font);

     this->SetBackgroundColour(wxColour(250,250,250));

     this->SetDoubleBuffered(true);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

     this->ClearBackground();

     this->SetMinSize(this->Parent_Window_Pointer->GetClientSize());

     this->SetSize(this->Parent_Window_Pointer->GetClientSize());

     this->Fit();

     this->SetAutoLayout(true);

     this->CentreOnParent(wxBOTH);

     this->Refresh();
 }

 Custom_wxTreeCtrl::~Custom_wxTreeCtrl()
 {

 }

void Custom_wxTreeCtrl::kill_focus_event(wxFocusEvent& event){

     event.Skip(true);

     this->PaintNow();
}

void Custom_wxTreeCtrl::set_focus_event(wxFocusEvent& event){

     event.Skip(true);

     this->PaintNow();
}

 void Custom_wxTreeCtrl::PaintNow(){

       wxClientDC dc(this);

       wxRect rect(this->GetSize());

       this->DrawBackground(dc,this,rect);
 }

void Custom_wxTreeCtrl::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(255,255,255));

     dc.DrawRectangle(rect.GetX()-2, rect.GetY()-2, rect.GetWidth()+5,rect.GetHeight()+5);
}

void Custom_wxTreeCtrl::Receive_Position(wxPoint control_position){

     this->Position = control_position;
}

void Custom_wxTreeCtrl::Size_Event(wxSizeEvent & event)
{
      event.Skip(true);

      wxWindow * parent = this->GetParent();

      this->SetSize(parent->GetClientSize());

      this->PaintNow();
}
