
#include "Custom_Tree_View_Panel.h"


Custom_Tree_View_Panel::Custom_Tree_View_Panel(wxFrame * frame,

     wxWindowID id, const wxPoint &pos, const wxSize &size,

     wxAuiManager * Interface_Manager,

     wxFont Default_Font, int tabctrl_hight)

  : wxPanel(frame,id,pos,size)

{
     this->background = wxColour(200,200,200);

     this->Interface_Manager_Pointer = Interface_Manager;

     this->windows_detach_condition = true;

     this->tab_ctrl_hight = tabctrl_hight;

     this->close_button_construction_status = false;

     this->Topbar_MinSize = wxSize(270,-1);

     this->SetDoubleBuffered(true);

     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

     wxPaintEvent Custom_Paint_Event(wxEVT_PAINT);

     this->Connect(this->GetId(),wxEVT_PAINT,wxPaintEventHandler(Custom_Tree_View_Panel::OnPaint));

     this->GetEventHandler()->Bind(wxEVT_LEFT_UP,&Custom_Tree_View_Panel::mouseReleased,this,wxID_ANY);

     this->GetEventHandler()->Bind(wxEVT_SIZE,&Custom_Tree_View_Panel::Size_Event,this,wxID_ANY);

     this->SetSize(frame->GetClientSize());

     this->Centre(wxBOTH);

     this->CentreOnParent(wxBOTH);

     this->Fit();

     this->Refresh();

     this->Show(false);


     this->tab_ctrl_hight = tabctrl_hight;

     this->Frame_Pointer = frame;

     this->Memory_Delete_Condition = false;

     this->panel_open_status = false;


     this->Interface_Manager_Pointer->SetDockSizeConstraint(0.3,1);

     this->File_List_Widget_Shape.TopDockable(false);

     this->File_List_Widget_Shape.LeftDockable(false);

     this->File_List_Widget_Shape.Right();

     this->File_List_Widget_Shape.Resizable(true);

     this->File_List_Widget_Shape.MinSize(270,-1);

     this->File_List_Widget_Shape.Show(true);

     this->File_List_Widget_Shape.CloseButton(false);

     this->File_List_Widget_Shape.Dock();

     this->File_List_Widget_Shape.dock_proportion = 0.25;


     int tree_view_hegiht = this->GetClientSize().y - this->tab_ctrl_hight+10;

     this->Tree_Control_Size = this->GetClientSize();


     this->tree_control = new Custom_wxDataViewTreeCtrl(this, wxID_ANY,wxDefaultPosition,

                             this->Tree_Control_Size,wxDV_NO_HEADER);



     wxPoint tree_control_current_position = this->tree_control->GetPosition();

     this->Tree_Control_Position = wxPoint(tree_control_current_position.x,

                                   tree_control_current_position.y + this->tab_ctrl_hight );


     this->tree_control->Receive_Position(this->Tree_Control_Position);

     this->tree_control->SetPosition(this->Tree_Control_Position);



     wxSize Tab_Bar_size = wxSize(this->GetSize().x,this->tab_ctrl_hight);

     this->Top_Bar_Window = new Custom_Window(this,wxPoint(0,0),Tab_Bar_size);

     this->Top_Bar_Window->Receive_Tab_ctrl_Hight(this->tab_ctrl_hight);

     this->Top_Bar_Window->Show(false);


     wxPoint Panel_Position = this->GetRect().GetPosition();

     wxPoint Panel_Top_Right_Position = this->GetRect().GetTopRight();

     wxPoint Panel_Top_Left_Position = this->GetRect().GetTopLeft();


     // Default wxPanel position is TopLeft corner of the panel

     int close_button_x = Panel_Top_Right_Position.x -35;

     int close_button_y = (this->tab_ctrl_hight - 20) / 2 -3;

     this->close_button_position = wxPoint(close_button_x,close_button_y);

     this->close_button = new Custom_Close_Button(this->Top_Bar_Window,

                          this->close_button_position,wxSize(25,25));

     this->close_button->Show(false);

     this->close_button_construction_status = true;

     this->Top_Bar_Window->Receive_Button_ID(this->close_button->GetId());

     this->tree_control->Fit();

     this->tree_control->SetAutoLayout(true);

     this->tree_control->Show(false);


     this->Directory_List_Font = Default_Font;

     this->Directory_List_Font.SetPointSize(this->Directory_List_Font.GetPointSize()-1);

     this->Folder_Lister = new Project_Folder_Lister(this->tree_control);
}

Custom_Tree_View_Panel::~Custom_Tree_View_Panel()
{
    if(!this->windows_detach_condition)
    {
        this->Detach_Windows_From_Sizer();
    }

    if(!this->Memory_Delete_Condition)
    {
       this->Memory_Delete_Condition = true;

       delete this->Folder_Lister;
    }
}

void Custom_Tree_View_Panel::Size_Event(wxSizeEvent & event)
{
     event.Skip(true);

     if(this->close_button_construction_status){

        this->close_button->paintNow();
     }
}

void Custom_Tree_View_Panel::mouseReleased(wxMouseEvent& event)
{
     event.Skip(false);

     event.StopPropagation();

     this->Close_Directory_Pane();
}

void Custom_Tree_View_Panel::Initialize_Sizer()
{
     this->panel_sizer = new wxBoxSizer(wxVERTICAL);

     this->panel_sizer->Add(this->Top_Bar_Window,0,wxEXPAND | wxALIGN_CENTER,0);

     this->panel_sizer->Add(this->tree_control,0,wxEXPAND | wxALIGN_CENTER,0);

     this->windows_detach_condition = false;

     this->SetSizer(this->panel_sizer);

     this->panel_sizer->SetSizeHints(this);

     this->Fit();

     this->SetAutoLayout(true);
}

void Custom_Tree_View_Panel::Detach_Windows_From_Sizer()
{
     this->panel_sizer->Detach(this->tree_control);

     this->panel_sizer->Detach(this->Top_Bar_Window);

     this->windows_detach_condition = true;
}

void Custom_Tree_View_Panel::Receive_Topbar_MinSize(wxSize size)
{
     this->Topbar_MinSize = size;
}

void Custom_Tree_View_Panel::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(this->background);

     dc.DrawRectangle(rect.GetX()-2, rect.GetY()-2, rect.GetWidth()+5,rect.GetHeight()+5);
}

void Custom_Tree_View_Panel::PaintNow()
{
     wxClientDC dc(this);

     wxRect rect(this->GetSize());

     this->DrawBackground(dc,this,rect);
}

void Custom_Tree_View_Panel::OnPaint(wxPaintEvent& event)
{
     event.Skip(false);

     wxPaintDC dc(this);

     wxRect rect(this->GetSize());

     this->DrawBackground(dc,this,rect);
};

void Custom_Tree_View_Panel::Clear_Dynamic_Memory()
{
     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         delete this->Folder_Lister;

         delete this->Top_Bar_Window;

         this->tree_control->Destroy();
     }
}

void Custom_Tree_View_Panel::Load_Project_Directory(wxString Folder){

     this->Folder_Lister->RemoveProjectDirectory();

     if(!this->panel_open_status)
     {
        this->Interface_Manager_Pointer->AddPane(this,this->File_List_Widget_Shape);

        this->Show(true);

        this->panel_open_status = true;
     }

     this->Interface_Manager_Pointer->Update();

     this->Initialize_Sizer();

     this->Folder_Lister->Load_Project_Directory(Folder);

     this->Show(true);

     this->Top_Bar_Window->paintNow();

     this->tree_control->Show(true);

     this->Top_Bar_Window->Show(true);

     this->close_button->Show(true);

     this->Interface_Manager_Pointer->Update();
}

void Custom_Tree_View_Panel::Close_Directory_Pane()
{
     this->Folder_Lister->RemoveProjectDirectory();

     if(this->panel_open_status)
     {
        this->tree_control->Show(false);

        this->Top_Bar_Window->Show(false); // Top bar window

        this->Show(false);  // Directory_List_Panel

        if(!this->windows_detach_condition)
        {
            this->Detach_Windows_From_Sizer();
        }

        this->Interface_Manager_Pointer->DetachPane(this);

        this->Interface_Manager_Pointer->Update();

        this->panel_open_status = false;
    }
}

void Custom_Tree_View_Panel::Set_Font(wxFont Font){

      this->tree_control->SetFont(Font);
}

Custom_wxDataViewTreeCtrl * Custom_Tree_View_Panel::GetDataViewTreeCtrl(){

     return this->tree_control;
}

wxString Custom_Tree_View_Panel::GetItemPath(wxDataViewItem item_number){

         return this->Folder_Lister->GetItemPath(item_number);
}

void Custom_Tree_View_Panel::RemoveProjectDirectory(){

     this->Folder_Lister->RemoveProjectDirectory();
}

bool Custom_Tree_View_Panel::Get_Panel_Open_Status(){

     return this->panel_open_status;
}
