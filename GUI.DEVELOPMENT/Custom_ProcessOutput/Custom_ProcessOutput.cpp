
/*

 * Copyright (C) { Erkam Murat Bozkurt } - All Rights Reserved
 * 
 * This source code is protected under international copyright law.  All rights
 * reserved and protected by the copyright holders.
 * 
 * This file is confidential and only available to authorized individuals with the
 * permission of the copyright holders.  If you encounter this file and do not have
 * permission, please contact the copyright holders and delete this file.

*/



#include "Custom_ProcessOutput.hpp"


BEGIN_EVENT_TABLE(Custom_ProcessOutput,wxFrame)
    EVT_BUTTON(ID_CLOSE_WINDOW,Custom_ProcessOutput::CloseWindow)
END_EVENT_TABLE()

Custom_ProcessOutput::Custom_ProcessOutput(wxFrame *parent, wxWindowID id, const wxString & title, 

   const wxPoint &pos, const wxSize &size, 
   
   long style) : wxFrame(parent,id,title,pos,size,
   
   wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxSTAY_ON_TOP)
{

     this->Default_Font = new wxFont(12,wxFONTFAMILY_MODERN ,wxFONTSTYLE_NORMAL,

                     wxFONTWEIGHT_NORMAL,false,"Calibri");

     this->SetFont(*(this->Default_Font));

     this->Memory_Delete_Condition = false;

     wxIcon Frame_Icon(wxT("C:\\Program Files\\Pcynlitx\\icons\\icon.png"),wxBITMAP_TYPE_PNG,-1,-1);

     this->SetIcon(Frame_Icon);

     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->SetExtraStyle(wxFULL_REPAINT_ON_RESIZE);

     this->GetEventHandler()->Bind(wxEVT_SIZE,&Custom_ProcessOutput::OnSize,this,wxID_ANY);

     this->GetEventHandler()->Bind(wxEVT_CLOSE_WINDOW,&Custom_ProcessOutput::OnClose,this,wxID_ANY);


     this->SetThemeEnabled(true);

     this->SetDoubleBuffered(true);

     this->SetExtraStyle(wxCLIP_CHILDREN);


     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->Centre(wxBOTH);

     this->CentreOnParent(wxBOTH);

     this->Fit();


     this->SetAutoLayout(true);

     this->ClearBackground();

     this->PaintNow(this);

     this->Construct_Output_Window();

     this->Show(true);
}


void Custom_ProcessOutput::Construct_Output_Window(){

     this->text_ctrl_panel = new wxPanel(this,wxID_ANY,wxDefaultPosition,this->FromDIP(wxSize(750,530)));

     this->CloseButton     = new wxButton(this,ID_CLOSE_WINDOW,wxT("CLOSE"),
     
                             wxDefaultPosition,this->FromDIP( wxSize(100, 50)));


     this->textctrl = new wxTextCtrl(this->text_ctrl_panel,wxID_ANY, wxT(""), 
     
                      wxDefaultPosition, this->FromDIP(wxSize(750,530)), wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY);



     this->ctrl_box = new wxBoxSizer(wxHORIZONTAL);

     this->ctrl_box->Add(this->text_ctrl_panel,1,wxEXPAND,2);

     this->ctrl_box->Layout();


     this->close_button_sizer = new wxBoxSizer(wxVERTICAL);

     this->close_button_sizer->AddStretchSpacer();

     this->close_button_sizer->Add(this->CloseButton,0, wxALIGN_CENTER_HORIZONTAL | wxFIXED_MINSIZE  | wxALL,15);

     this->close_button_sizer->AddStretchSpacer();

     this->close_button_sizer->Layout();

     

     this->frame_box = new wxBoxSizer(wxVERTICAL);

     this->frame_box->Add(this->ctrl_box,1,    wxEXPAND | wxTOP    |  wxALL,5);

     this->frame_box->Add(this->close_button_sizer,0,   wxEXPAND | wxBOTTOM  | wxALL,5);

     this->frame_box->Layout();




     this->SetSizer(this->frame_box);

     this->frame_box->SetSizeHints(this);

     this->frame_box->Fit(this);



     this->text_ctrl_panel->SetSize(this->textctrl->GetSize());

     this->text_ctrl_panel->Update();

     this->textctrl->Update();


     this->SetSize(this->GetClientSize());

     this->PostSizeEvent();

     this->Centre(wxBOTH);

     this->Update();

}

void Custom_ProcessOutput::PrintProcessOutput(wxString text){

     this->textctrl->AppendText(text);  
}


void Custom_ProcessOutput::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(240,240,240));

     dc.DrawRectangle(rect.GetX()-5, rect.GetY()-5, rect.GetWidth()+5,rect.GetHeight()+5);
}

void Custom_ProcessOutput::PaintNow(wxWindow * wnd)
{
     wxClientDC dc(wnd);

     wxSize Rect_Size = wxSize(wnd->GetSize().x+5,wnd->GetSize().y+5);

     wxRect rect(Rect_Size);

     this->DrawBackground(dc,wnd,rect);
}


void Custom_ProcessOutput::OnSize(wxSizeEvent & event){

     event.Skip(true);

     this->PaintNow(this);
}


void Custom_ProcessOutput::CloseWindow(wxCommandEvent & event){

     if(event.GetId() == ID_CLOSE_WINDOW){

        event.Skip(false);

        this->Destroy();

        if(!this->Dir_List_Manager->Get_Panel_Open_Status()){

            this->Dir_List_Manager->Load_Project_Directory(this->Construction_Point);
        }
     }
}


void Custom_ProcessOutput::OnClose(wxCloseEvent & event){

     event.Veto();

     this->Destroy();
}


void Custom_ProcessOutput::SetBoldFont(){

     wxTextAttr AttrBold(wxColor(100, 100, 120));

     AttrBold.SetFontWeight(wxFONTWEIGHT_BOLD);

     AttrBold.SetFontSize(12);

     AttrBold.SetFontFaceName(wxT("Calibri"));

     this->GetTextControl()->SetDefaultStyle(AttrBold);

}

void Custom_ProcessOutput::SetLightFont(){

     wxTextAttr AttrLigth(wxColor(50,50,50));

     AttrLigth.SetFontWeight(wxFONTWEIGHT_LIGHT);

     AttrLigth.SetFontSize(12);

     AttrLigth.SetFontFaceName(wxT("Calibri")); 

     this->GetTextControl()->SetDefaultStyle(AttrLigth);
}



wxTextCtrl * Custom_ProcessOutput::GetTextControl() const {

     return this->textctrl;
}
