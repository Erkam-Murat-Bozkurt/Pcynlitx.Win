
#include "Custom_wxTreeCtrl.h"



BEGIN_EVENT_TABLE(Custom_wxTreeCtrl,wxTreeCtrl)

  EVT_TREE_ITEM_ACTIVATED(wxID_ANY,Custom_wxTreeCtrl::FileSelect)

  EVT_TREE_BEGIN_LABEL_EDIT(wxID_ANY,Custom_wxTreeCtrl::FileNameEdit)

  EVT_TREE_ITEM_EXPANDED(wxID_ANY,Custom_wxTreeCtrl::Tree_Item_Expanded)

  EVT_TREE_ITEM_COLLAPSED(wxID_ANY,Custom_wxTreeCtrl::Tree_Item_Collapsed)

END_EVENT_TABLE()


Custom_wxTreeCtrl::Custom_wxTreeCtrl(wxWindow *parent, wxWindowID id,

  const wxPoint & pos,

  const wxSize & size, long style) : wxTreeCtrl(parent,id,pos,size,style)
  {
     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->Parent_Window_Pointer = parent;

     //this->GetEventHandler()->Bind(wxEVT_PAINT,&Custom_wxTreeCtrl::OnPaint,this,wxID_ANY);

     //this->GetEventHandler()->Bind(wxEVT_TREE_ITEM_EXPANDED,&Custom_wxTreeCtrl::Tree_Item_Expanded,this,wxID_ANY);

     this->SetBackgroundColour(wxColour(250,250,250));

     this->SetDoubleBuffered(true);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->SetExtraStyle(wxFULL_REPAINT_ON_RESIZE);

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

 void Custom_wxTreeCtrl::Tree_Item_Expanded(wxTreeEvent & event){

      event.Skip(false);

      //wxMessageOutput::Get()->Printf(" wxTreeItem has been expanded..");

      this->PaintNow();


 }

 void Custom_wxTreeCtrl::Tree_Item_Collapsed(wxTreeEvent & event){

      event.Skip(false);

      //wxMessageOutput::Get()->Printf(" wxTreeItem has been expanded..");

      this->PaintNow();

 }

 void Custom_wxTreeCtrl::FileSelect(wxTreeEvent& event)
 {
      event.Skip(false);

      this->PaintNow();

      //wxMessageOutput::Get()->Printf(" wxTreeItem has been activated..");

 }

 void Custom_wxTreeCtrl::FileNameEdit(wxTreeEvent& event)
 {
      event.Veto();

 }


 /*

 void Custom_wxTreeCtrl::OnPaint(wxPaintEvent& event)
 {
      event.Skip(false);

      wxPaintDC dc(this);

      wxSize current_size = this->GetSize();

      wxSize new_size = wxSize(current_size.x+5, current_size.y+5);

      wxRect rect(new_size);

      this->DrawBackground(dc,this,rect);
 };

 */

 void Custom_wxTreeCtrl::PaintNow(){

       wxClientDC dc(this);

       wxRect rect(this->GetSize());

       this->DrawBackground(dc,this,rect);
 }

void Custom_wxTreeCtrl::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect){

     dc.SetBrush(wxColour(255,255,255));

     dc.DrawRectangle(rect.GetX()-2, rect.GetY()-2, rect.GetWidth()+5,rect.GetHeight()+5);
}

void Custom_wxTreeCtrl::Receive_Position(wxPoint control_position){

     this->Position = control_position;
}

/*

void Custom_wxTreeCtrl::Size_Event(wxSizeEvent & event)
{
      event.Skip(true);

      wxWindow * parent = this->GetParent();

      this->SetSize(parent->GetClientSize());

      //this->PaintNow();
}

*/
