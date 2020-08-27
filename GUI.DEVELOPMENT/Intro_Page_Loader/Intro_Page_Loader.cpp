
#include "Intro_Page_Loader.h"

Intro_Page_Loader::Intro_Page_Loader(wxWindow * parent,wxSize page_size, int tab_ctrl_hgt):

                   wxWindow(parent,-1,wxDefaultPosition,page_size,wxBORDER_NONE)
{
     this->Connect(this->GetId(),wxEVT_PAINT,wxPaintEventHandler(Intro_Page_Loader::OnPaint));

     this->Intro_Page_Open_Status_Pointer = nullptr;

     this->tab_ctrl_height = tab_ctrl_hgt;

     this->Parent_Window_Pointer = parent;

     this->Memory_Delete_Condition = false;

     this->intro_page_bitmap  = new wxBitmap(wxT("/usr/share/Pcynlitx/Intro_File.png"), wxBITMAP_TYPE_PNG);

     this->intro_page_image = this->intro_page_bitmap->ConvertToImage();

     this->SetDoubleBuffered(true);

     this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->Layout();

     this->Fit();

     wxSize Parent_Size = this->Parent_Window_Pointer->GetClientSize();

     int new_size_y = Parent_Size.y - this->tab_ctrl_height;

     wxSize new_size = wxSize(Parent_Size.x+1,new_size_y+1);

     this->SetSize(new_size);

     this->SetMinSize(this->intro_page_image.GetSize());

     this->CenterOnParent(wxHORIZONTAL);

     this->Fit();

     this->SetAutoLayout(true);

     this->Show(true);
}

Intro_Page_Loader::~Intro_Page_Loader(){

    if(!this->Memory_Delete_Condition){

        this->DeletePendingEvents();

        this->Clear_Dynamic_Memory();

        *this->Intro_Page_Open_Status_Pointer = false;

        this->Intro_Page_Open_Status_Pointer = nullptr;
    }
}

void Intro_Page_Loader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         delete this->intro_page_bitmap;
     }
}

void Intro_Page_Loader::Receive_Intro_Page_Open_Status(bool * status)
{
     this->Intro_Page_Open_Status_Pointer = status;
}

void Intro_Page_Loader::Close_Intro_Page()
{
     this->~Intro_Page_Loader();
}


void Intro_Page_Loader::OnPaint(wxPaintEvent& event)
{
     event.Skip(false);

     event.StopPropagation();

     wxPaintDC dc(this);

     wxSize Rect_Size = this->GetSize();

     wxRect rect(Rect_Size);

     this->DrawBackground(dc,this,rect);
}

void Intro_Page_Loader::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect & rect)
{
     dc.SetPen(wxPen(wxColour(245,245,245)));

     dc.SetBrush(wxColour(245,245,245));

     wxPoint position = rect.GetPosition();

     dc.DrawRectangle(rect.GetX()-1, rect.GetY()-1, rect.GetWidth()+5,rect.GetHeight()+5);


     wxSize Bitmap_Size = this->intro_page_bitmap->GetSize();

     wxSize Panel_Size = rect.GetSize();

     int x_extend = Panel_Size.x - Bitmap_Size.x;

     int y_extend = Panel_Size.y - Bitmap_Size.y;

     dc.DrawBitmap(*this->intro_page_bitmap,wxPoint(rect.GetX()+x_extend/2,rect.GetY()+y_extend/2));
}
