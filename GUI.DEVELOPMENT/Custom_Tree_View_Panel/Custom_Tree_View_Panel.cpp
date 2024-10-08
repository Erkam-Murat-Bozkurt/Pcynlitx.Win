
/*

 * Copyright (C) { Erkam Murat Bozkurt } - All Rights Reserved
 * 
 * This source code is protected under international copyright law.  All rights
 * reserved and protected by the copyright holders.
 * 
 * This file is confidential and only available to authorized individuals with the
 * permission of the copyright holders. If you encounter this file and do not have
 * permission, please contact the copyright holders and delete this file.

*/

#include "Custom_Tree_View_Panel.h"


BEGIN_EVENT_TABLE(Custom_Tree_View_Panel,wxPanel)
   EVT_DATAVIEW_ITEM_ACTIVATED(wxID_ANY,Custom_Tree_View_Panel::FileSelect)
   EVT_DATAVIEW_ITEM_START_EDITING(wxID_ANY,Custom_Tree_View_Panel::FileNameEdit)
END_EVENT_TABLE()

Custom_Tree_View_Panel::Custom_Tree_View_Panel(wxFrame * frame,

     wxWindowID id, const wxPoint &pos, const wxSize &size,

     wxAuiManager * Interface_Manager,

     wxFont Default_Font, int tabctrl_hight, wxColor theme_clr)

  : wxPanel(frame,id,pos,size)

{
     this->background = wxColour(240,240,240);

     this->Interface_Manager_Pointer = Interface_Manager;

     this->windows_detach_condition = true;

     this->tab_ctrl_hight = tabctrl_hight;

     this->close_button_construction_status = false;

     this->Topbar_MinSize = wxSize(500,this->tab_ctrl_hight);

     this->SetDoubleBuffered(true);

     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

     this->GetEventHandler()->Bind(wxEVT_PAINT,&Custom_Tree_View_Panel::OnPaint,this,wxID_ANY);

     this->GetEventHandler()->Bind(wxEVT_LEFT_UP,&Custom_Tree_View_Panel::mouseReleased,this,wxID_ANY);

     this->GetEventHandler()->Bind(wxEVT_SIZE,&Custom_Tree_View_Panel::Size_Event,this,wxID_ANY);

     this->SetSize(size);

     this->Centre(wxBOTH);

     this->CentreOnParent(wxBOTH);

     this->Fit();

     this->Refresh();

     this->Show(false);


     this->dir_ctrl = new wxDir;


     this->tab_ctrl_hight = tabctrl_hight +1;

     this->Frame_Pointer = frame;

     this->Memory_Delete_Condition = false;

     this->panel_open_status = false;


     //this->Interface_Manager_Pointer->SetDockSizeConstraint(0.35,1);

     this->File_List_Widget_Shape.TopDockable(false);

     this->File_List_Widget_Shape.LeftDockable(false);

     this->File_List_Widget_Shape.Right();

     this->File_List_Widget_Shape.Resizable(true);

     this->File_List_Widget_Shape.MinSize(size);

     this->File_List_Widget_Shape.Show(true);

     this->File_List_Widget_Shape.CloseButton(false);

     this->File_List_Widget_Shape.Dock();

     this->File_List_Widget_Shape.dock_proportion = 0.4;

     this->SetMinSize(size);


     int tree_size_y = size.y - 2*this->tab_ctrl_hight -60;

     this->Tree_Control_Size = wxSize(size.x,tree_size_y);


     this->tree_control = new wxDataViewTreeCtrl(this, wxID_ANY,wxDefaultPosition,

                             this->Tree_Control_Size,wxDV_NO_HEADER | wxDV_VARIABLE_LINE_HEIGHT  );


     std::string face_name = "Calibri"; 


     this->Directory_List_Font = new wxFont(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,

                     wxFONTWEIGHT_NORMAL,false,wxString(face_name));

     this->tree_control->SetFont(*this->Directory_List_Font);


     wxPoint tree_control_current_position = this->tree_control->GetPosition();

     this->Tree_Control_Position = wxPoint(tree_control_current_position.x,

                                   tree_control_current_position.y + this->tab_ctrl_hight );


     this->tree_control->SetPosition(this->Tree_Control_Position);

     this->tree_control->SetBackgroundColour(wxColour(250,250,250));


     wxSize Tab_Bar_size = wxSize(this->GetSize().x,this->tab_ctrl_hight);

     this->Top_Bar_Window = new Custom_Window(this,wxPoint(0,0),Tab_Bar_size,wxColour(240,240,240));

     this->Top_Bar_Window->Receive_Tab_ctrl_Hight(this->tab_ctrl_hight);

     this->Top_Bar_Window->Show(false);



     // TITLE WINDOW SETTINGS START


     this->Title_Window =  new Custom_Window(this,wxPoint(0,this->tab_ctrl_hight),
     
                           wxSize(Tab_Bar_size.x,Tab_Bar_size.y-5),wxColour(80,80,90,0xff));

     this->Title_Window->Receive_Tab_ctrl_Hight(this->tab_ctrl_hight);

     this->Title_Window->Show(false);



     wxStaticText * text = new wxStaticText(this->Title_Window ,wxID_ANY,wxT("FILE EXPLORER   "));

     wxPoint title_pos =text->GetPosition();

     wxSize text_size = text->GetSize();

     int text_y_pos = title_pos.y + (this->tab_ctrl_hight - text_size.GetY())/2;

     text->SetPosition(wxPoint(title_pos.x+25,text_y_pos));




     wxFont textFont = text->GetFont();

     textFont.SetPointSize(9);

     textFont.SetFaceName(wxT("Segoe UI Semibold"));

     text->SetFont(textFont);

     text->SetForegroundColour(wxColour(250,250,250));

     // TITLE WINDOW SETTINGS END



     /*

     int bottom_win_y = this->Tree_Control_Position.y + this->tree_control->GetSize().GetY();




     this->Bottom_Window =  new Custom_Window(this,wxPoint(0,bottom_win_y+3),
     
                           wxSize(Tab_Bar_size.x,55),wxColour(240,240,240,0xff));

     */






     // Default wxPanel position is TopLeft corner of the panel

     wxPoint Panel_Top_Right_Position = this->GetRect().GetTopRight();

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

     this->Folder_Lister = new Project_Folder_Lister(this->tree_control);

     this->Initialize_Sizer();

     this->windows_detach_condition = false;



     this->Top_Bar_Window->Show(true);

     this->Title_Window->Show(true);

     this->close_button->Show(true);

     this->tree_control->Show(true);

     //this->Bottom_Window->Show(true);

     this->Show(false);


     this->PostSizeEvent();
}

Custom_Tree_View_Panel::~Custom_Tree_View_Panel()
{
    if(!this->windows_detach_condition)
    {
        this->windows_detach_condition = true;

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

     this->PaintNow();
}

void Custom_Tree_View_Panel::mouseReleased(wxMouseEvent & event)
{
     event.Skip(false);

     event.StopPropagation();

     if(this->close_button->pressedCloseButton){

        this->Close_Directory_Pane();

        this->close_button->pressedCloseButton = false;
     }
}

void Custom_Tree_View_Panel::Initialize_Sizer()
{
     this->panel_sizer = new wxBoxSizer(wxVERTICAL);

     this->panel_sizer->Add(this->Top_Bar_Window,0, wxEXPAND | wxALL,0);

     this->panel_sizer->Add(this->Title_Window,0,  wxEXPAND  | wxRIGHT,15);

     this->panel_sizer->Add(this->tree_control,1,  wxEXPAND | wxRIGHT | wxBOTTOM,16);

     //this->panel_sizer->Add(this->Bottom_Window,0, wxEXPAND | wxALL,0);


     this->panel_sizer->Layout();

     this->windows_detach_condition = false;

     this->SetSizer(this->panel_sizer);

     this->panel_sizer->SetSizeHints(this);

     this->Fit();

     this->SetAutoLayout(true);

}

void Custom_Tree_View_Panel::Detach_Windows_From_Sizer()
{
     this->panel_sizer->Detach(this->Top_Bar_Window);

     this->panel_sizer->Detach(this->Title_Window);

     this->panel_sizer->Detach(this->tree_control);

     this->windows_detach_condition = true;
}

void Custom_Tree_View_Panel::Receive_Topbar_MinSize(wxSize size)
{
     this->Topbar_MinSize = size;
}

void Custom_Tree_View_Panel::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(240,240,240));

     dc.DrawRectangle(rect.GetX()-1, rect.GetY()-1, rect.GetWidth()+10,rect.GetHeight()+10);
}


void Custom_Tree_View_Panel::FileSelect(wxDataViewEvent & event)
{
     event.Skip(true);

     event.StopPropagation();

     wxDataViewItem Item = this->tree_control->GetSelection();

     wxString Path = this->GetItemPath(Item);

     if(this->dir_ctrl->Exists(Path)){

        if(this->GetTreeCtrl()->IsExpanded(Item)){

           this->GetTreeCtrl()->Collapse(Item);
        }
        else{

             this->GetTreeCtrl()->Expand(Item);
        }
     }
     else{

            this->Notebook_Ptr->Open_File(Path);
     }
}



void Custom_Tree_View_Panel::FileNameEdit(wxDataViewEvent & event)
{
     event.Veto();

}




void Custom_Tree_View_Panel::PaintNow()
{
     wxClientDC dc(this);

     wxRect rect(this->GetSize());

     this->DrawBackground(dc,this,rect);
}

void Custom_Tree_View_Panel::OnPaint(wxPaintEvent & event)
{
     event.Skip(true);

     wxPaintDC dc(this);

     wxRect rect(this->GetSize());

     this->DrawBackground(dc,this,rect);

     if(this->close_button_construction_status){

        this->close_button->paintNow();
     }

     if(this->Get_Panel_Open_Status()){

        this->Top_Bar_Window->paintNow();

        this->Title_Window->paintNow();

        //this->Bottom_Window->paintNow();
     }
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

     this->Folder_Lister->Load_Project_Directory(Folder);

     this->Folder_Lister->Expand_Root();


     this->Top_Bar_Window->Update();

     this->Title_Window->Update();

     this->close_button->Update();

     //this->Bottom_Window->Update();


     this->Interface_Manager_Pointer->AddPane(this,this->File_List_Widget_Shape);


     for(int i=0;i<5;i++){

         wxYield();

         this->Top_Bar_Window->Update();

         this->Title_Window->Update();

         this->close_button->Update();

         //this->Bottom_Window->Update();

         this->PostSizeEvent();

     }


     this->Show(true);

     this->close_button->pressedCloseButton = false;

     if(!this->panel_open_status)
     {
        this->panel_open_status = true;
     }

     this->Interface_Manager_Pointer->Update();

}


void Custom_Tree_View_Panel::Expand_Path(wxString path){

     this->Folder_Lister->Expand_Path(path);
}



void Custom_Tree_View_Panel::Close_Directory_Pane()
{
     this->Folder_Lister->RemoveProjectDirectory();

     if(this->panel_open_status)
     {
        this->tree_control->DeleteAllItems();

        this->Show(false);  // Directory_List_Panel

        this->Interface_Manager_Pointer->DetachPane(this);

        this->Interface_Manager_Pointer->Update();

        this->panel_open_status = false;
    }
}


void Custom_Tree_View_Panel::Expand_Selected_Item(){

     this->Folder_Lister->Expand_Selected_Item();
}

int Custom_Tree_View_Panel::GetTotalItemNum(wxString Folder){

    return this->Folder_Lister->GetTotalItemNum(Folder);
}


void Custom_Tree_View_Panel::Set_Font(wxFont Font){

      this->tree_control->SetFont(Font);
}

wxDataViewTreeCtrl * Custom_Tree_View_Panel::GetTreeCtrl(){

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
