
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

     this->SetBackgroundColour(wxColour(235,235,235));

     this->SetDoubleBuffered(true);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);


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
     this->panel_sizer->Add(this->book_manager,1,wxEXPAND | wxALIGN_CENTER_HORIZONTAL,0);

     this->SetSizer(this->panel_sizer);

     this->panel_sizer->SetSizeHints(this);

     this->panel_sizer->ShowItems(true);

     this->Fit();

     this->SetAutoLayout(true);
}

void Custom_wxPanel::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(235,235,235));

     dc.DrawRectangle(rect.GetX()-5, rect.GetY()-5, rect.GetWidth()+5,rect.GetHeight()+5);
}

void Custom_wxPanel::PaintNow(wxWindow * wnd)
{
     wxClientDC dc(wnd);

     wxSize Rect_Size = wxSize(wnd->GetSize().x+5,wnd->GetSize().y+5);

     wxRect rect(Rect_Size);

     this->DrawBackground(dc,wnd,rect);
}
