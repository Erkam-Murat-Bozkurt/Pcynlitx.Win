

#include "Help_Page_Loader.h"

Help_Page_Loader::Help_Page_Loader(wxWindow * parent,wxSize page_size):

                   wxWindow(parent,-1,wxDefaultPosition,page_size,wxBORDER_NONE)
{
     this->Connect(this->GetId(),wxEVT_PAINT,wxPaintEventHandler(Help_Page_Loader::OnPaint));

     this->Help_Page_Open_Status_Pointer = nullptr;

     this->text_list = new wxStaticText * [20];

     this->link_list = new wxHyperlinkCtrl * [20];

     for(int i=0;i<20;i++){

        this->text_list[i] = nullptr;

        this->link_list[i] = nullptr;
     }

     this->Parent_Window_Pointer = parent;

     this->Memory_Delete_Condition = false;

     this->SetDoubleBuffered(true);

     this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->Layout();

     this->Fit();

     wxSize Parent_Size = this->Parent_Window_Pointer->GetClientSize();

     this->SetSize(Parent_Size);

     this->SetMinSize(Parent_Size);

     this->CenterOnParent(wxHORIZONTAL);

     this->Fit();

     this->SetAutoLayout(true);

     this->Show(false);

     this->hyperlink_position = wxPoint(0,0);
}

Help_Page_Loader::~Help_Page_Loader(){

    if(!this->Memory_Delete_Condition){

        this->DeletePendingEvents();

        this->Clear_Dynamic_Memory();

        *this->Help_Page_Open_Status_Pointer = false;

        this->Help_Page_Open_Status_Pointer = nullptr;
    }
}

void Help_Page_Loader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         for(int i=0;i<20;i++){

             if(this->text_list[i] != nullptr){

                delete this->text_list[i];
             }
         }

         for(int i=0;i<20;i++){

             if(this->link_list[i] != nullptr)
             {
                delete this->link_list[i];
             }
         }
     }
}

void Help_Page_Loader::Close_Intro_Page()
{
     this->~Help_Page_Loader();
}

void Help_Page_Loader::Receive_Help_Page_Open_Status(bool * status)
{
     this->Help_Page_Open_Status_Pointer = status;
}

void Help_Page_Loader::Initialize_Help_Page_Text(wxWindow * Help_page_window)
{
     wxPoint link_position = wxPoint(0,0);

     wxPoint text_position = wxPoint(80,95);


     // HELP PAGE TITLE INITIALIZATION

     this->text_list[0] = new wxStaticText(Help_page_window,wxID_ANY,

                               wxString("PCYNLITX DOCUMENTS"),

                               text_position,wxDefaultSize,wxALIGN_LEFT);

     this->Set_Text_Font_Style(this->text_list[0],16,true);

     // wxColour(188,145,145)

     // wxColour(128,139,150)

     this->text_list[0]->SetForegroundColour(wxColour(128,139,150));


     text_position = wxPoint(80,145);

     wxString introductory_text = wxString("You can connect directly to the documentation");

     introductory_text = introductory_text + wxString(" web sites from the links given in below");

     this->text_list[1] = new wxStaticText(Help_page_window,wxID_ANY,

                               introductory_text,

                               text_position,wxDefaultSize,wxALIGN_LEFT);

     this->Set_Text_Font_Style(this->text_list[1],12,false);

     this->text_list[1]->SetForegroundColour(wxColour(120,120,120));


     text_position = this->Determine_Static_Text_Position(text_position);

     this->text_list[2] = new wxStaticText(Help_page_window,wxID_ANY,

                               wxString("When you click the link, the related web page opens directly."),

                               text_position,wxDefaultSize,wxALIGN_LEFT);

     this->Set_Text_Font_Style(this->text_list[2],12,false);

     this->text_list[2]->SetForegroundColour(wxColour(120,120,120));


     // HOME PAGE LINK INITIALIATION ----------------------------------

     text_position = this->Determine_Static_Text_Position(text_position);

     text_position.y = text_position.y + 10;

     this->text_list[3] = new wxStaticText(Help_page_window,wxID_ANY,

                               wxString("Project Home Page:"),text_position,

                               wxDefaultSize,wxALIGN_LEFT);

     this->Set_Text_Font_Style(this->text_list[3],12,true);

     this->text_list[3]->SetForegroundColour(wxColour(140,140,140));


     link_position = this->Determine_Hyperlink_Position(this->text_list[3]);

     this->link_list[0] = new wxHyperlinkCtrl(Help_page_window,

                               wxID_ANY,wxString("www.pcynlitx.tech"),

                               wxString("https://www.pcynlitx.tech/"),link_position);

     this->link_list[0]->SetNormalColour(wxColour(176,196,222));

     this->link_list[0]->SetHoverColour(wxColour(95,158,160));


     // PDF DOCUMENTS LINK ESTABLISH ----------------------------------------

     text_position = this->Determine_Static_Text_Position(text_position);

     this->text_list[4] = new wxStaticText(Help_page_window,wxID_ANY,

                               wxString("Introduction to technology:"),text_position,wxDefaultSize,wxALIGN_LEFT);

     this->Set_Text_Font_Style(this->text_list[4],12,true);

     this->text_list[4]->SetForegroundColour(wxColour(140,140,140));


     link_position = this->Determine_Hyperlink_Position(this->text_list[4]);

     this->link_list[1] = new wxHyperlinkCtrl(Help_page_window,

                               wxID_ANY,wxString("Introduction"),

                               wxString("http://www.pcynlitx.tech/a-brief-introduction"),link_position);

     this->link_list[1]->SetNormalColour(wxColour(150,150,150));


     // CODE REPOSITORY LINK ESTABLISH --------------------------------------------

     text_position = this->Determine_Static_Text_Position(text_position);

     this->text_list[5] = new wxStaticText(Help_page_window,wxID_ANY,

                          wxString("Source Code Repository:"),text_position,wxDefaultSize,wxALIGN_LEFT);

     this->Set_Text_Font_Style(this->text_list[5],12,true);

     this->text_list[5]->SetForegroundColour(wxColour(140,140,140));


     link_position = this->Determine_Hyperlink_Position(this->text_list[5]);

     this->link_list[2] = new wxHyperlinkCtrl(Help_page_window,

                              wxID_ANY,wxString("Code Repository"),

                              wxString("https://github.com/Erkam-Murat-Bozkurt/Pcynlitx"),link_position);

     this->link_list[2]->SetNormalColour(wxColour(150,150,150));



      // WEB TUTORIALS LINK ESTABLISH --------------------------------------------

      text_position = this->Determine_Static_Text_Position(text_position);

      this->text_list[6] = new wxStaticText(Help_page_window,wxID_ANY,

                           wxString("Web Tutorials:"),text_position,wxDefaultSize,wxALIGN_LEFT);

      this->Set_Text_Font_Style(this->text_list[6],12,true);

      this->text_list[6]->SetForegroundColour(wxColour(140,140,140));


      link_position = this->Determine_Hyperlink_Position(this->text_list[6]);

      this->link_list[3] = new wxHyperlinkCtrl(Help_page_window,

                               wxID_ANY,wxString("The Programming Tutorial"),

                               wxString("https://www.pcynlitx.tech/programming-tutorial-1/"),link_position);

       this->link_list[3]->SetNormalColour(wxColour(150,150,150));




       // PDF DOCUMENTS ESTABLISH --------------------------------------------

       text_position = this->Determine_Static_Text_Position(text_position);

       this->text_list[7] = new wxStaticText(Help_page_window,wxID_ANY,

                            wxString("Pdf Documents:"),text_position,wxDefaultSize,wxALIGN_LEFT);

       this->Set_Text_Font_Style(this->text_list[7],12,true);

       this->text_list[7]->SetForegroundColour(wxColour(140,140,140));


       link_position = this->Determine_Hyperlink_Position(this->text_list[7]);

       this->link_list[4] = new wxHyperlinkCtrl(Help_page_window,

                                      wxID_ANY,wxString("Pdf documents"),

                                      wxString("https://www.pcynlitx.tech/documents"),link_position);

       this->link_list[4]->SetNormalColour(wxColour(150,150,150));



       // GUI TUTORIALS --------------------------------------------

       // After that, the position is wxPoint(470,220)

       text_position = wxPoint(475,235);

       this->text_list[8] = new wxStaticText(Help_page_window,wxID_ANY,

                                   wxString("GUI Tutorials:"),text_position,wxDefaultSize,wxALIGN_LEFT);

       this->Set_Text_Font_Style(this->text_list[8],12,true);

       this->text_list[8]->SetForegroundColour(wxColour(140,140,140));


       link_position = this->Determine_Hyperlink_Position(this->text_list[8]);

       this->link_list[5] = new wxHyperlinkCtrl(Help_page_window,

                            wxID_ANY,wxString("The link for GUI Tutorials"),

                            wxString("https://www.pcynlitx.tech/gui-tutorial/"),link_position);

       this->link_list[5]->SetNormalColour(wxColour(150,150,150));




       // THE ESTABLISHMENT FOR CODE EXAMPLES --------------------------------------------

       text_position = this->Determine_Static_Text_Position(text_position);

       this->text_list[9] = new wxStaticText(Help_page_window,wxID_ANY,

                            wxString("Code Examples:"),text_position,wxDefaultSize,wxALIGN_LEFT);

       this->Set_Text_Font_Style(this->text_list[9],12,true);

       this->text_list[9]->SetForegroundColour(wxColour(140,140,140));


       link_position = this->Determine_Hyperlink_Position(this->text_list[9]);

       this->link_list[6] = new wxHyperlinkCtrl(Help_page_window,

                                wxID_ANY,wxString("A link for code examples"),

                                wxString("http://www.pcynlitx.tech/documents/"),link_position);

       this->link_list[6]->SetNormalColour(wxColour(150,150,150));



       // LISENCE INFORMATION --------------------------------------------

       text_position = this->Determine_Static_Text_Position(text_position);

       this->text_list[10] = new wxStaticText(Help_page_window,wxID_ANY,

                                   wxString("License information:"),text_position,wxDefaultSize,wxALIGN_LEFT);

       this->Set_Text_Font_Style(this->text_list[10],12,true);

       this->text_list[10]->SetForegroundColour(wxColour(140,140,140));


       link_position = this->Determine_Hyperlink_Position(this->text_list[10]);

       this->link_list[7] = new wxHyperlinkCtrl(Help_page_window,

                            wxID_ANY,wxString("License"),

                            wxString("https://github.com/Erkam-Murat-Bozkurt/Pcynlitx/blob/master/LICENSE"),link_position);

       this->link_list[7]->SetNormalColour(wxColour(150,150,150));



       // LISENCE INFORMATION --------------------------------------------

       text_position = this->Determine_Static_Text_Position(text_position);

       this->text_list[11] = new wxStaticText(Help_page_window,wxID_ANY,

                            wxString("Copyright:"),text_position,wxDefaultSize,wxALIGN_LEFT);

       this->Set_Text_Font_Style(this->text_list[11],12,true);

       this->text_list[11]->SetForegroundColour(wxColour(140,140,140));


       link_position = this->Determine_Hyperlink_Position(this->text_list[11]);

       this->link_list[8] = new wxHyperlinkCtrl(Help_page_window,

                            wxID_ANY,wxString("Copyright Information"),

                            wxString("https://github.com/Erkam-Murat-Bozkurt/Pcynlitx/blob/master/Copyright"),link_position);

       this->link_list[8]->SetNormalColour(wxColour(150,150,150));

       text_position = this->Determine_Static_Text_Position(text_position);

       this->text_list[12] = new wxStaticText(Help_page_window,wxID_ANY,

                            wxString("Version 1.0"),text_position,wxDefaultSize,wxALIGN_LEFT);

       this->Set_Text_Font_Style(this->text_list[12],12,true);

       this->text_list[12]->SetForegroundColour(wxColour(140,140,140));
}

wxPoint Help_Page_Loader::Determine_Static_Text_Position(wxPoint position)
{
        this->text_position.x = position.x;

        this->text_position.y = position.y +40;

        return this->text_position;
}

wxPoint Help_Page_Loader::Determine_Hyperlink_Position(wxStaticText * text)
{
       wxFont text_font = text->GetFont();

       wxPoint text_position = text->GetPosition();

       int x_size = text->GetSize().GetWidth();

       int y_size = text->GetSize().GetHeight();

       int point_size = text_font.GetPointSize();

       int y_position = text_position.y - (y_size-point_size)/2 -3;

       this->hyperlink_position = wxPoint(text_position.x+x_size + 3, y_position);

       return this->hyperlink_position;
}

void Help_Page_Loader::Set_Text_Font_Style(wxStaticText * text, int Font_Size, bool is_bold)
{
      wxFont  text_font = text->GetFont();

      text_font.SetPointSize(Font_Size);

      text->SetFont(text_font);

      if(is_bold)
      {
         text_font = text->GetFont();

         text->SetFont(text_font.Bold());
      }
}

void Help_Page_Loader::OnPaint(wxPaintEvent& event)
{
     event.Skip(false);

     event.StopPropagation();

     wxPaintDC dc(this);

     wxSize Rect_Size = this->GetSize();

     wxRect rect(Rect_Size);

     this->DrawBackground(dc,this,rect);
}

void Help_Page_Loader::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect & rect)
{
     dc.SetPen(wxPen(wxColour(250,250,250)));

     dc.SetBrush(wxColour(250,250,250));

     wxPoint position = rect.GetPosition();

     dc.DrawRectangle(rect.GetX()-1, rect.GetY()-1, rect.GetWidth()+5,rect.GetHeight()+5);

     dc.SetPen(wxPen(wxColour(180,180,180)));

     dc.SetBrush(wxColour(180,180,180));

     for(int i=0;i<5;i++){

       dc.DrawLine(wxPoint(50,60+i),wxPoint(800,60+i));
     }

     for(int i=0;i<5;i++){

       dc.DrawLine(wxPoint(50,455+i),wxPoint(800,455+i));
     }

     for(int i=0;i<5;i++){

       dc.DrawLine(wxPoint(50+i,60),wxPoint(50+i,455));
     }

     for(int i=0;i<5;i++){

       dc.DrawLine(wxPoint(800+i,60),wxPoint(800+i,460));
     }
}
