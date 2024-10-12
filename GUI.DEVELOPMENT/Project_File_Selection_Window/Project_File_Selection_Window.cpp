

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


#include "Project_File_Selection_Window.hpp"


BEGIN_EVENT_TABLE(Project_File_Selection_Window,wxDialog )

    EVT_BUTTON(ID_CONSTRUCT_EMPTY_PROJECT_FILE,Project_File_Selection_Window::Construct_Empty_Project_File)

    EVT_BUTTON(ID_SELECT_AN_EXISTING_PROJECT_FILE,Project_File_Selection_Window::Select_Project_File)

    EVT_PAINT(Project_File_Selection_Window::OnPaint)

END_EVENT_TABLE()



Project_File_Selection_Window::Project_File_Selection_Window( wxWindow * parent, wxWindowID id, 

    const wxString & title, 
    
    const wxPoint & pos, const wxSize & size) : 
   
    wxDialog(parent,id,title,pos,size, wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxSTAY_ON_TOP)
{
     this->Parent_Window = parent;

     this->Descriptor_File_Selection_Status = nullptr;

     wxIcon Frame_Icon(wxT("C:\\Program Files\\Pcynlitx\\icons\\icon.png"),wxBITMAP_TYPE_PNG,-1,-1);

     this->SetIcon(Frame_Icon);


     this->exclamation_mark_bmp 
  
      = new wxBitmap(wxT("C:\\Program Files\\Pcynlitx\\icons\\exclamation_icon.png"),wxBITMAP_TYPE_ANY);


     this->SetTitle(wxT("PROJECT FILE SELECTION PANEL"));


     this->new_empty_file 
  
      = new wxBitmap(wxT("C:\\Program Files\\Pcynlitx\\icons\\open_new_project_file.png"),wxBITMAP_TYPE_ANY);


     this->open_existing_file 
  
      = new wxBitmap(wxT("C:\\Program Files\\Pcynlitx\\icons\\select_project_file_icon.png"),wxBITMAP_TYPE_ANY);

     this->SetBackgroundColour(wxColour(225,225,225));

     
     this->Project_File_Selection_Panel  = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(350,175));

     this->Project_File_Selection_Panel->SetMinSize(wxSize(350,175));

     this->Project_File_Selection_Panel->SetBackgroundColour(wxColour(225,225,225));






     this->Empty_Project_File_Panel  = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(350,175));

     this->Empty_Project_File_Panel->SetMinSize(wxSize(350,175));

     this->Empty_Project_File_Panel->SetBackgroundColour(wxColour(225,225,225));


     wxStaticBitmap * select_project_file_figure 
     
     = new wxStaticBitmap(this->Project_File_Selection_Panel,wxID_ANY,*this->open_existing_file);

     select_project_file_figure->CentreOnParent(wxBOTH);

     
     wxStaticBitmap * new_project_file_figure 
     
     = new wxStaticBitmap(this->Empty_Project_File_Panel,wxID_ANY,*this->new_empty_file);

     new_project_file_figure->CentreOnParent(wxBOTH);



     this->EMPF_Cons_Panel_Sizer = new wxBoxSizer(wxHORIZONTAL);

     this->EMPF_Cons_Panel_Sizer->Add(this->Empty_Project_File_Panel,1,wxEXPAND | wxTOP | wxLEFT | wxRIGHT ,0);



     this->PRFS_Panel_Sizer = new wxBoxSizer(wxHORIZONTAL);

     this->PRFS_Panel_Sizer->Add(this->Project_File_Selection_Panel,1,wxEXPAND | wxTOP | wxLEFT | wxRIGHT ,0);








     this->Empty_Project_File_Button_Panel     = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(350,135));

     this->Project_File_Selection_Button_Panel = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(350,135));

     this->Empty_Project_File_Button_Panel->SetMinSize(wxSize(350,135));

     this->Project_File_Selection_Button_Panel->SetMinSize(wxSize(350,135));

     this->Empty_Project_File_Button_Panel->SetBackgroundColour(wxColour(225,225,225));

     this->Project_File_Selection_Button_Panel->SetBackgroundColour(wxColour(225,225,225));



     this->Empty_Project_File_Button     = new wxButton(this->Empty_Project_File_Button_Panel,ID_CONSTRUCT_EMPTY_PROJECT_FILE,
     
                                         wxT("CREATE FILE"), wxDefaultPosition,   wxSize(150,70));

     this->Project_File_Selection_Button = new wxButton(this->Project_File_Selection_Button_Panel,ID_SELECT_AN_EXISTING_PROJECT_FILE,
     
                                         wxT("SELECT FILE"),wxDefaultPosition, wxSize(150,70));



     wxFont buton_font = this->Empty_Project_File_Button->GetFont();

     buton_font.SetFaceName(wxT("Segoe UI"));

     buton_font.SetPointSize(11);

     //bld_font.SetFaceName(wxT("Noto Sans"));


     this->Empty_Project_File_Button->SetFont(buton_font);

     this->Project_File_Selection_Button->SetFont(buton_font);



     this->Empty_Project_File_Button->SetMinSize(wxSize(150,70));

     //this->Empty_Project_File_Button->SetForegroundColour(wxColour(150,150,150));


     this->Project_File_Selection_Button->SetMinSize(wxSize(150,70));

     //this->Project_File_Selection_Button->SetForegroundColour(wxColour(150,150,150));





     this->Empty_Project_File_Text_Panel  = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(350,80));

     this->Empty_Project_File_Text_Panel->SetMinSize(wxSize(350,80));

     this->Empty_Project_File_Text_Panel->SetBackgroundColour(wxColour(200,200,210));

     //this->Empty_Project_File_Text_Panel->SetBackgroundColour(wxColour(200,100,100));



     this->Project_File_Selection_Text_Panel  = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(350,80));

     this->Project_File_Selection_Text_Panel->SetMinSize(wxSize(350,80));

     this->Project_File_Selection_Text_Panel->SetBackgroundColour(wxColour(200,200,210,0xff));

     //this->Project_File_Selection_Text_Panel->SetBackgroundColour(wxColour(68,158,157));

     //this->Project_File_Selection_Text_Panel->SetBackgroundColour(wxColour(110,110,120));

     //this->Project_File_Selection_Text_Panel->SetBackgroundColour(wxColour(100,100,115));


     //wxString new_file_text_string = wxT("Construct a new project file");
     
     wxString new_file_text_string = wxT("START A NEW PROJECT");

     wxStaticText * new_file_text  
     
      = new wxStaticText(this->Empty_Project_File_Text_Panel,wxID_ANY,new_file_text_string);

     wxFont Text_Font = new_file_text->GetFont();

     Text_Font.SetPointSize(11);

     Text_Font.SetFaceName(wxT("Segoe UI"));

     //Text_Font.SetFaceName(wxT("Noto Sans"));

     new_file_text->SetFont(Text_Font);

     new_file_text->SetForegroundColour(wxColour(55,55,55));

     //new_file_text->SetForegroundColour(wxColour(250,250,250));
     
     new_file_text->CentreOnParent(wxBOTH);



     //wxString existing_file_text_string = wxT("Use a ready project file");

     wxString existing_file_text_string = wxT("CONTINUE A CURRENT PROJECT");
     
     wxStaticText * project_file_text  
     
       = new wxStaticText(this->Project_File_Selection_Text_Panel,wxID_ANY,existing_file_text_string);

     project_file_text->SetFont(Text_Font);

     project_file_text->SetForegroundColour(wxColour(55,55,55));

     //project_file_text->SetForegroundColour(wxColour(250,250,250));

     project_file_text->CentreOnParent(wxBOTH);



     this->EMPF_Cons_Text_Panel_Sizer = new wxBoxSizer(wxHORIZONTAL);

     this->PRFS_Text_Panel_Sizer = new wxBoxSizer(wxHORIZONTAL);


     this->EMPF_Cons_Text_Panel_Sizer->Add(this->Empty_Project_File_Text_Panel,0,  wxEXPAND  |  wxALL,0);

     this->PRFS_Text_Panel_Sizer->Add(this->Project_File_Selection_Text_Panel, 0,  wxEXPAND  | wxALL,0);






     this->EMPF_Cons_Button_Panel_Sizer = new wxBoxSizer(wxHORIZONTAL);

     this->PRFS_Button_Panel_Sizer      = new wxBoxSizer(wxHORIZONTAL);



     this->EMPF_Cons_Button_Panel_Sizer->Add(this->Empty_Project_File_Button_Panel,0,  wxEXPAND  | wxLEFT | wxRIGHT | wxBOTTOM,20);

     this->PRFS_Button_Panel_Sizer->Add(this->Project_File_Selection_Button_Panel, 0,  wxEXPAND  | wxLEFT | wxRIGHT | wxBOTTOM,20);


     this->Empty_Project_File_Button->CentreOnParent(wxBOTH);

     this->Project_File_Selection_Button->CentreOnParent(wxBOTH);






     this->Left_Panel_Sizer = new wxBoxSizer(wxVERTICAL);

     this->Left_Panel_Sizer->Add(this->EMPF_Cons_Panel_Sizer,1, wxALIGN_CENTER_HORIZONTAL  | wxALL ,0);

     this->Left_Panel_Sizer->Add(this->EMPF_Cons_Text_Panel_Sizer,0, wxALIGN_CENTER_HORIZONTAL  | wxALL ,0);

     this->Left_Panel_Sizer->Add(this->EMPF_Cons_Button_Panel_Sizer,0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM ,0);


     this->Right_Panel_Sizer = new wxBoxSizer(wxVERTICAL);

     this->Right_Panel_Sizer->Add(this->PRFS_Panel_Sizer,1, wxALIGN_CENTER_HORIZONTAL | wxALL ,0);

     this->Right_Panel_Sizer->Add(this->PRFS_Text_Panel_Sizer,0, wxALIGN_CENTER_HORIZONTAL | wxALL ,0);

     this->Right_Panel_Sizer->Add(this->PRFS_Button_Panel_Sizer,0,  wxALIGN_CENTER_HORIZONTAL | wxALL ,0);

     




     this->Frame_Sizer = new wxBoxSizer(wxHORIZONTAL);

     this->Frame_Sizer->Add(this->Left_Panel_Sizer, 1,wxEXPAND | wxALL,20);

     this->Frame_Sizer->Add(this->Right_Panel_Sizer,1,wxEXPAND | wxALL,20);

     this->SetSizer(this->Frame_Sizer);

     this->Frame_Sizer->SetSizeHints(this);

     this->Fit();

     this->Empty_Project_File_Panel->Show(true);

     this->Project_File_Selection_Panel->Show(true);

     this->Empty_Project_File_Panel->SetAutoLayout(true);

     this->Project_File_Selection_Panel->SetAutoLayout(true);

     this->Centre();

     this->CentreOnParent(wxBOTH);

     this->SetAutoLayout(true);

     this->Refresh();

     this->Update();

     this->Show(true);
}


Project_File_Selection_Window::~Project_File_Selection_Window(){

}

void Project_File_Selection_Window::Receive_Descriptor_File_Path(wxString * DesPATH){

     this->Descriptor_File_Path_Pointer = DesPATH;
}


void Project_File_Selection_Window::Receive_Project_File_Selection_Status(bool * status){

     this->Descriptor_File_Selection_Status = status;
}

void Project_File_Selection_Window::DrawBackground(wxDC & dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(240,240,240));

     dc.DrawRectangle(rect.GetX()-5, rect.GetY()-5, rect.GetWidth()+5,rect.GetHeight()+5);
}

void Project_File_Selection_Window::OnPaint(wxPaintEvent & event)
{
     event.Skip(false);

     wxPaintDC dc(this);

     wxRect rect(this->GetSize());

     this->DrawBackground(dc,this,rect);
}



void Project_File_Selection_Window::Construct_Empty_Project_File(wxCommandEvent & event){

     if(event.GetId() == ID_CONSTRUCT_EMPTY_PROJECT_FILE ){

        event.Skip(true);

        wxDirDialog dlg(NULL, "Select Descriptor File Location", "",

           wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

        dlg.CenterOnScreen(wxBOTH);


        if(dlg.ShowModal() == wxID_OK){

           wxString construction_dir =dlg.GetPath();

           wxString DesPATH = construction_dir + wxT("\\Pcb_Descriptor.txt");

           wxString shell_command = "C:\\Program Files\\Pcynlitx\\bin\\Empty_Process_Descriptor_File_Builder.exe " 
        
           + construction_dir;

           this->SysInt.Create_Process(shell_command.ToStdString());

           
           if(this->FileManager.Is_Path_Exist(DesPATH.ToStdString())){

               *this->Descriptor_File_Path_Pointer = DesPATH;

               *this->Descriptor_File_Selection_Status = true;

               this->Destroy();
           }
           else{


               this->Descriptor_File_Path_Pointer->clear();

               this->Descriptor_File_Path_Pointer->shrink_to_fit();
 
               *this->Descriptor_File_Selection_Status = false;

               wxString Message = "\nThere is an error on empty ";

               Message += "\ndescriptor file construction process";

               Custom_Message_Dialog * dial = new Custom_Message_Dialog(this,Message,
            
                         wxT("ERROR REPORT:"),wxID_ANY,
                         
                         wxT("NWINIX PLATFORM OPERATION REPORT"),*this->exclamation_mark_bmp);

               dial->ShowModal();

               this->Destroy();

           }
        }
        else{

             this->Descriptor_File_Path_Pointer->clear();

             this->Descriptor_File_Path_Pointer->shrink_to_fit();

             *this->Descriptor_File_Selection_Status = false;

                           wxString Message = "\nThere is an error on empty ";

              Message += "\ndescriptor file construction process";

              Custom_Message_Dialog * dial = new Custom_Message_Dialog(this,Message,
            
                         wxT("ERROR REPORT:"),wxID_ANY,
                         
                         wxT("NWINIX PLATFORM OPERATION REPORT"),*this->exclamation_mark_bmp);

              dial->SetSize(this->FromDIP(wxSize(620,400)));

              dial->ShowModal();

              this->Destroy();
        }
     }
}

void Project_File_Selection_Window::Select_Project_File(wxCommandEvent & event){

     if(event.GetId() == ID_SELECT_AN_EXISTING_PROJECT_FILE ){

        event.Skip(true);

        this->Select_File();
     }
}



void Project_File_Selection_Window::Select_File(){

     wxFileDialog * openFileDialog

              = new wxFileDialog(this,wxT("Select Project File"));

     openFileDialog->Centre(wxBOTH);

     openFileDialog->CenterOnScreen(wxBOTH);

     int return_mode = openFileDialog->ShowModal();

     if (return_mode == wxID_OK){

         *this->Descriptor_File_Path_Pointer = openFileDialog->GetPath();

         *this->Descriptor_File_Selection_Status = true;

         this->Destroy();          
     }
     else{

          if(return_mode == wxID_CANCEL){

            this->Destroy();
          }
     }

     delete openFileDialog;
}


bool Project_File_Selection_Window::get_Descriptor_File_Selection_Status() const 
{
     return this->Descriptor_File_Selection_Status;
}
