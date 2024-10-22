

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


#include "Project_Descriptions_Printer.hpp"


BEGIN_EVENT_TABLE(Project_Descriptions_Printer,wxFrame)
    EVT_BUTTON(ID_CLOSE_DESCRIPTION_WINDOW,Project_Descriptions_Printer::closeWindow)
END_EVENT_TABLE()

Project_Descriptions_Printer::Project_Descriptions_Printer(wxFrame *parent, wxWindowID id, 

   const wxString & title, 

   const wxPoint &pos, const wxSize &size, 
   
   long style) : wxFrame(parent,id,title,pos,size,
   
   wxDEFAULT_FRAME_STYLE | wxSYSTEM_MENU | wxRESIZE_BORDER | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxSTAY_ON_TOP)
{

     DestroyCaret(); 

     
     this->log_num =0;

     this->Default_Font = new wxFont(10,wxFONTFAMILY_MODERN ,wxFONTSTYLE_NORMAL,

                     wxFONTWEIGHT_NORMAL,false,"Segoe UI");

     this->SetFont(*(this->Default_Font));

     this->Memory_Delete_Condition = false;

     wxIcon Frame_Icon(wxT("C:\\Program Files\\Pcynlitx\\icons\\icon.png"),wxBITMAP_TYPE_PNG,-1,-1);

     this->SetIcon(Frame_Icon);

     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->SetExtraStyle(wxFULL_REPAINT_ON_RESIZE);

     this->GetEventHandler()->Bind(wxEVT_SIZE,&Project_Descriptions_Printer::OnSize,this,wxID_ANY);

     this->GetEventHandler()->Bind(wxEVT_PAINT,&Project_Descriptions_Printer::OnPaint,this,wxID_ANY);

     this->SetThemeEnabled(true);

     this->SetDoubleBuffered(true);

     this->ClearBackground();



     this->Construct_Text_Panel();

     this->Construct_Close_Panel();

     this->setSizers();

     this->PaintNow(this);

     this->PostSizeEvent();

     this->invalid_descriptor_file_status = false;

     this->syntax_error_status = false;

     this->window_open_status = true;

     this->descriptor_file_read_success = false;

     this->SetCanFocus(false);

     DestroyCaret(); 

}



Project_Descriptions_Printer::~Project_Descriptions_Printer(){


}


/*
void Project_Descriptions_Printer::Receive_Descriptor_File_Directory(char * DescriptorFileDirectory){

     this->Des_Reader.Receive_Descriptor_File_Directory(DescriptorFileDirectory);
}




void Project_Descriptions_Printer::Receive_Descriptor_File_Name(char * DescriptorFileName){

     this->Des_Reader.Receive_Descriptor_File_Name(DescriptorFileName);

}

*/


void Project_Descriptions_Printer::Receive_Descriptor_File_Path(wxString DesPATH){

     this->Descriptor_File_Path = DesPATH; 
}



bool Project_Descriptions_Printer::Read_Descriptions(){

     char Project_Descriptor_File_Name [] = "Project_Descriptor_File.txt";


     size_t Descriptor_File_Name_Size = 0;

     for(size_t k=this->Descriptor_File_Path.length();k>0;k--){

         if(this->Descriptor_File_Path[k] == '\\'){

            break;
         }

         Descriptor_File_Name_Size++;
     }

     size_t Directory_Name_Size = this->Descriptor_File_Path.length() - Descriptor_File_Name_Size;

     std::string Directory_Name;

     for(size_t k=0;k<Directory_Name_Size;k++){

         Directory_Name.push_back(this->Descriptor_File_Path[k]);
     }

     Directory_Name.shrink_to_fit();

     this->Des_Reader.Receive_Descriptor_File_Directory(Directory_Name.c_str());

     this->Des_Reader.Receive_Descriptor_File_Name(Project_Descriptor_File_Name);

     return !this->Des_Reader.Receive_Descriptor_File_Infomations();
}

void Project_Descriptions_Printer::Construct_Text_Panel(){


     this->scroll_win = new wxScrolledWindow(this,wxID_ANY,wxDefaultPosition,wxSize(950,680));

     this->scroll_win->SetBackgroundColour(wxColour(240, 240, 240));



     this->textctrl = new wxTextCtrl(this->scroll_win,wxID_ANY, wxT(""), 
     
                      wxDefaultPosition, wxSize(950,680), wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY);



     this->scroll_win->SetAutoLayout(true);

     this->textctrl->SetSize(this->scroll_win->GetClientSize());

     this->textctrl->SetAutoLayout(true);


     this->PostSizeEvent();

     this->Centre(wxBOTH);

     this->SetExtraStyle(wxCLIP_CHILDREN);

     this->SetBackgroundStyle(wxBG_STYLE_PAINT);

     this->Centre(wxBOTH);

     this->CentreOnParent(wxBOTH);

     this->Fit();

     this->SetAutoLayout(true);

     this->SetCanFocus(false);

     this->Update();

     this->PostSizeEvent();

     this->textctrl->ShowNativeCaret(false);


     DestroyCaret();
}


void Project_Descriptions_Printer::Construct_Close_Panel(){
     
     this->close_panel = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(this->GetClientSize().GetX(),80));

     this->close_panel->SetMinSize(wxSize(this->GetClientSize().GetX(),80));

     this->CloseButton = new wxButton(this->close_panel,ID_CLOSE_DESCRIPTION_WINDOW,
      
           wxT("CLOSE"),wxDefaultPosition, wxSize(110, 50));

     this->CloseButton->Centre(wxBOTH);

}

void Project_Descriptions_Printer::OnPaint(wxPaintEvent & event)
{
     event.Skip(false);

     wxPaintDC dc(this);

     wxRect rect(this->GetSize());

     this->DrawBackground(dc,this,rect);
}



void Project_Descriptions_Printer::closeWindow(wxCommandEvent & event){

     if(event.GetId() == ID_CLOSE_DESCRIPTION_WINDOW){

        this->Destroy();
     }
}

void Project_Descriptions_Printer::setSizers(){

     this->frame_sizer = new wxBoxSizer(wxVERTICAL);

     this->close_panel_sizer = new wxBoxSizer(wxVERTICAL);

     this->text_panel_sizer = new wxBoxSizer(wxVERTICAL);



     this->text_panel_sizer->Add(this->scroll_win,1,wxEXPAND | wxALL,0);

     this->close_panel_sizer->Add(this->close_panel,1,wxEXPAND| wxALL,0);


     this->scroll_win->SetVirtualSize(wxSize(-1,3500));

     this->scroll_win->FitInside();

     this->scroll_win->SetScrollRate(1,1);

     this->text_panel_sizer->SetSizeHints(this->scroll_win);
     


     this->frame_sizer->Add(this->text_panel_sizer,1,wxEXPAND | wxTOP | wxALL,10);

     this->frame_sizer->Add(this->close_panel_sizer,0,wxALIGN_CENTER_HORIZONTAL | wxFIXED_MINSIZE | wxBOTTOM | wxALL,10);

     this->frame_sizer->Layout();


     this->FitInside();

     this->SetSizer(this->frame_sizer);

     this->frame_sizer->SetSizeHints(this);

     
     this->PostSizeEvent();



     this->scroll_win->SetSize(this->scroll_win->GetClientSize());


     this->close_panel->SetSize(this->close_panel->GetClientSize());


     this->PostSizeEvent();

     this->Centre(wxBOTH);

     this->Update();
}


void Project_Descriptions_Printer::Print_Descriptions(){

     this->textctrl->Clear();     

     wxTextAttr AttrBold(wxColor(100, 100, 110));

     AttrBold.SetFontWeight(wxFONTWEIGHT_BOLD);

     AttrBold.SetFontSize(12);

     AttrBold.SetFontFaceName(wxT("Calibri"));


     wxTextAttr AttrLigth(wxColor(70,70,70));

     AttrLigth.SetFontWeight(wxFONTWEIGHT_LIGHT);

     AttrLigth.SetFontSize(12);

     AttrLigth.SetFontFaceName(wxT("Calibri"));

     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    LIBRARY CONSTRUCTION POINT:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n   "));

     std::string construction_point = this->ConvertStdString(this->Des_Reader.Get_Construction_Point());


     if(!construction_point.empty()){

        construction_point.push_back('\n');

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(construction_point));
     }

     this->textctrl->AppendText(wxT("\n"));



     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    SERVER CLASS NAME:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n   "));

     std::string server_class_name = this->ConvertStdString(this->Des_Reader.Get_Server_Class_Name());

     if(!server_class_name.empty()){

        server_class_name.push_back('\n');

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(server_class_name));
     }

     this->textctrl->AppendText(wxT("\n"));

     this->textctrl->Show(true);


     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    THREAD NUMBER:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n   "));



     std::string thread_number = std::to_string(this->Des_Reader.Get_Thread_Number());

     if(!server_class_name.empty()){

        server_class_name.push_back('\n');

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(thread_number));
     }

     this->textctrl->AppendText(wxT("\n"));

     this->textctrl->Show(true);





     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    THREAD FUNCTION NAMES:"));

     this->textctrl->SetDefaultStyle(AttrLigth);


     int function_num = this->Des_Reader.Get_Thread_Function_Number();

     for(int i=0;i<function_num;i++){

         std::string function_name = this->ConvertStdString(this->Des_Reader.Get_Thread_Function_Names()[i]);

         this->Delete_Spaces_on_String(&function_name);

         if(!function_name.empty()){

             this->textctrl->AppendText(wxT("\n\n    "));

             this->textctrl->AppendText(wxString(function_name));
         }
     }

     this->textctrl->AppendText(wxT("\n\n   "));





     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    SOURCE FILE LOCATIONS:"));

     this->textctrl->SetDefaultStyle(AttrLigth);


     int src_loc_number = this->Des_Reader.Get_Source_File_Location_Number();

     for(int i=0;i<src_loc_number;i++){

         std::string src_location = this->ConvertStdString(this->Des_Reader.Get_Source_File_Locations()[i]);

         this->Delete_Spaces_on_String(&src_location);

         if(!src_location.empty()){

             this->textctrl->AppendText(wxT("\n\n    "));

             this->textctrl->AppendText(wxString(src_location));
         }
     }

     this->textctrl->AppendText(wxT("\n\n   "));


     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    SOURCE FILE NAMES:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     int names_number = this->Des_Reader.Get_Source_File_Names_Number();

     for(int i=0;i<names_number;i++){

         std::string src_name = this->ConvertStdString(this->Des_Reader.Get_Source_File_Names()[i]);

         this->Delete_Spaces_on_String(&src_name);

         if(!src_name.empty()){

             this->textctrl->AppendText(wxT("\n\n    "));

             this->textctrl->AppendText(wxString(src_name));
         }
     }

     this->textctrl->AppendText(wxT("\n\n   "));




     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    INCLUDED DIRECTORIES:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     int inc_dirs_num = this->Des_Reader.Get_Include_Directory_Number();

     for(int i=0;i<inc_dirs_num;i++){

         std::string src_name = this->ConvertStdString(this->Des_Reader.Get_Source_File_Names()[i]);

         this->Delete_Spaces_on_String(&src_name);

         if(!src_name.empty()){

             this->textctrl->AppendText(wxT("\n\n    "));

             this->textctrl->AppendText(wxString(src_name));
         }
     }

     this->textctrl->AppendText(wxT("\n\n   "));




     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    LIBRARY DIRECTORIES:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     int lib_dir_num = this->Des_Reader.Get_Library_Directory_Number();

     for(int i=0;i<lib_dir_num;i++){

         std::string lib_dir_name = this->ConvertStdString(this->Des_Reader.Get_Library_Directories()[i]);

         this->Delete_Spaces_on_String(&lib_dir_name);

         if(!lib_dir_name.empty()){

             this->textctrl->AppendText(wxT("\n\n    "));

             this->textctrl->AppendText(wxString(lib_dir_name));
         }
     }

     this->textctrl->AppendText(wxT("\n\n   "));




     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    LIBRARY NAMES:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     int lib_name_num = this->Des_Reader.Get_Library_Names_Number();

     for(int i=0;i<lib_name_num;i++){

         std::string lib_name = this->ConvertStdString(this->Des_Reader.Get_Library_Names()[i]);

         this->Delete_Spaces_on_String(&lib_name);

         if(!lib_name.empty()){

             this->textctrl->AppendText(wxT("\n\n    "));

             this->textctrl->AppendText(wxString(lib_name));
         }
     }

     this->textctrl->AppendText(wxT("\n\n   "));




     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    HEADER FILE NAMES:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     int header_num = this->Des_Reader.Get_Header_Files_Number();

     for(int i=0;i<header_num;i++){

         std::string header_name = this->ConvertStdString(this->Des_Reader.Get_Header_File_Names()[i]);

         this->Delete_Spaces_on_String(&header_name);

         if(!header_name.empty()){

             this->textctrl->AppendText(wxT("\n\n    "));

             this->textctrl->AppendText(wxString(header_name));
         }
     }

     this->textctrl->AppendText(wxT("\n\n   "));



     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    HEADER FILE PATHS:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     for(int i=0;i<header_num;i++){

         std::string header_path = this->ConvertStdString(this->Des_Reader.Get_Header_File_Paths()[i]);

         this->Delete_Spaces_on_String(&header_path);

         if(!header_path.empty()){

             this->textctrl->AppendText(wxT("\n\n    "));

             this->textctrl->AppendText(wxString(header_path));
         }
     }

     this->textctrl->AppendText(wxT("\n\n   "));







     Class_Data_Type *  Inter_Thread_Classes = this->Des_Reader.Get_Class_Names();

     Shared_Memory_Data_Type  * Inter_Thread_Data_Types = this->Des_Reader.Get_Shared_Data_Types();


     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    INTER-THREAD CLASS DESCRIPTIONS:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n"));


     if(Inter_Thread_Classes != nullptr){

        for(int i=0;i<Inter_Thread_Classes[0].Total_Class_Number;i++){

            this->textctrl->SetDefaultStyle(AttrBold);

            this->textctrl->AppendText(wxT("\n\n\tClass Name : "));

            this->textctrl->SetDefaultStyle(AttrLigth);


            std::string class_name = this->ConvertStdString(Inter_Thread_Classes[i].Class_Name);

            this->Delete_Spaces_on_String(&class_name);


            if(!class_name.empty()){

               this->textctrl->AppendText(wxString(class_name));
            }




            this->textctrl->SetDefaultStyle(AttrBold);

            this->textctrl->AppendText(wxT("\n\n\tHeader File Name :"));

            this->textctrl->SetDefaultStyle(AttrLigth);

            
            std::string header_file_name = this->ConvertStdString(Inter_Thread_Classes[i].Header_File_Name);

            this->Delete_Spaces_on_String(&header_file_name);

            if(!header_file_name.empty()){

               this->textctrl->AppendText(wxString(header_file_name));
            }



            this->textctrl->SetDefaultStyle(AttrBold);

            this->textctrl->AppendText(wxT("\n\n\tClass Instance Name : "));

            this->textctrl->SetDefaultStyle(AttrLigth);


            std::string class_instance_name =  this->ConvertStdString(Inter_Thread_Classes[i].Class_Instance_Name);

            this->Delete_Spaces_on_String(&class_instance_name);

            if(!class_instance_name.empty()){

               this->textctrl->AppendText(wxString(class_instance_name));
            }




            this->textctrl->SetDefaultStyle(AttrBold);

            this->textctrl->AppendText(wxT("\n\n\tHeader File Location : "));

            this->textctrl->SetDefaultStyle(AttrLigth);


            size_t Directory_Size = strlen(Inter_Thread_Classes[i].Header_File_Location);

            int dir_counter = 0;

            std::string hdr_location;

            for(int k=0;k<Directory_Size;k++){

                if( Inter_Thread_Classes[i].Header_File_Location[k] == '\\'){

                    dir_counter++;
                }


                if(dir_counter >= 4){

                     hdr_location += " +\n\n\t+ ";

                     dir_counter = 0;
                }

                hdr_location += Inter_Thread_Classes[i].Header_File_Location[k];
            }

            
            this->Delete_Spaces_on_String(&hdr_location);

            if(!hdr_location.empty()){

               this->textctrl->AppendText(wxString(hdr_location));
            }
        }
     }

     

     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    SMART POINTER DESCRIPTIONS"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n"));


     if(Inter_Thread_Data_Types != nullptr){

        for(int i=0;i<Inter_Thread_Data_Types[0].Total_Data_Type_Number;i++){

            this->textctrl->SetDefaultStyle(AttrBold);

            this->textctrl->AppendText(wxT("\n\n\tData Type : "));

            this->textctrl->SetDefaultStyle(AttrLigth);


            std::string data_type_name = this->ConvertStdString(Inter_Thread_Data_Types[i].Data_Type);

            this->Delete_Spaces_on_String(&data_type_name);

            if(!data_type_name.empty()){

               this->textctrl->AppendText(wxString(data_type_name));
            }



            if(Inter_Thread_Data_Types[i].Header_File_Name == nullptr){

                std::string basic_type_decleration = "  -  < Basic C++ Type >";

               this->textctrl->AppendText(wxString(basic_type_decleration));
            }



            this->textctrl->SetDefaultStyle(AttrBold);

            this->textctrl->AppendText(wxT("\n\n\tPointer Name: "));

            this->textctrl->SetDefaultStyle(AttrLigth);


            
            std::string pointer_name = this->ConvertStdString(Inter_Thread_Data_Types[i].Pointer_Name);

            this->Delete_Spaces_on_String(&pointer_name);

            if(!pointer_name.empty()){

               this->textctrl->AppendText(wxString(pointer_name));
            }

            if(Inter_Thread_Data_Types[i].Header_File_Name != nullptr){

               std::string header_name = Inter_Thread_Data_Types[i].Header_File_Name;

               this->textctrl->SetDefaultStyle(AttrBold);

               this->textctrl->AppendText(wxT("\n\n\tHeader File Name: "));

               this->textctrl->SetDefaultStyle(AttrLigth);

               this->Delete_Spaces_on_String(&header_name);

               if(!header_name.empty()){

                  this->textctrl->AppendText(wxString(header_name));
               }


               this->textctrl->SetDefaultStyle(AttrBold);

               this->textctrl->AppendText(wxT("\n\n\tHeader File Location :"));

               this->textctrl->SetDefaultStyle(AttrLigth);

               size_t dir_counter = 0;

               size_t Directory_Size = strlen(Inter_Thread_Data_Types[i].Include_Directory);

               std::string hdr_location;

               for(size_t k=0;k<Directory_Size;k++){

                   if( Inter_Thread_Data_Types[i].Include_Directory[k] == '\\'){

                       dir_counter++;
                   }

                   if(dir_counter >= 4){

                      hdr_location += " +\n\n\t+ ";

                      dir_counter = 0;
                   }

                   hdr_location += Inter_Thread_Data_Types[i].Include_Directory[k];
               }


               this->Delete_Spaces_on_String(&hdr_location);

               if(!hdr_location.empty()){

                  this->textctrl->AppendText(wxString(hdr_location));
               }
            }
        }
     }

     


     /*

     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    PROJECT WAREHOUSE LOCATION:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n  "));


     std::string warehouse_location;

     if(!this->Des_Reader->Get_Warehouse_Location().empty()){

        warehouse_location =  this->Des_Reader->Get_Warehouse_Location();

        warehouse_location.push_back('\n');

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(warehouse_location));
     }
 
     this->textctrl->AppendText(wxT("\n"));



     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    C++ STANDARD:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n"));



     std::string standard;

     if(!this->Des_Reader->Get_Standard().empty()){

        standard =  this->Des_Reader->Get_Standard();

        standard.push_back('\n');

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(standard));
     }

     this->textctrl->AppendText(wxT("\n"));



     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    BUILD SYSTEM:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n"));



     std::string build_system_type;

     if(!this->Des_Reader->Get_Build_System_Type().empty()){

        build_system_type =  this->Des_Reader->Get_Build_System_Type();

        build_system_type.push_back('\n');

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(build_system_type));
     }

     this->textctrl->AppendText(wxT("\n"));



     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    PROJECT NAME:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n"));



     std::string project_name;

     if(!this->Des_Reader->Get_Project_Name().empty()){

        project_name =  this->Des_Reader->Get_Project_Name();

        project_name.push_back('\n');

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(project_name));
     }

     this->textctrl->AppendText(wxT("\n"));



     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    VERSION NUMBER:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n"));



     std::string version_number;

     if(!this->Des_Reader->Get_Version_Number().empty()){

        version_number =  this->Des_Reader->Get_Version_Number();

        version_number.push_back('\n');

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(version_number));
     }

     this->textctrl->AppendText(wxT("\n"));



     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    INCLUDE DIRECTORY RECORD:"));

     this->textctrl->SetDefaultStyle(AttrLigth);
 
     this->textctrl->AppendText(wxT("\n\n"));


     int include_dir_num = this->Des_Reader->Get_Include_Directory_Number();

     std::vector<std::string> include_dirs;

     if(include_dir_num > 0){

       for(int i=0;i<include_dir_num;i++){

          std::string number = std::to_string(i+1);

          std::string inc_dir;
          
          inc_dir.push_back('[');

          for(size_t i=0;i<number.length();i++){

              inc_dir.push_back(number[i]);
          }

          inc_dir.push_back(']');

          inc_dir.push_back(' ');

          
          inc_dir += this->Des_Reader->Get_Include_Directory(i);

          inc_dir.push_back('\n');

          include_dirs.push_back(inc_dir);
       }
     }

     for(int i=0;i<include_dir_num;i++){

         this->textctrl->AppendText(" ");

         this->textctrl->AppendText(" ");

         this->textctrl->AppendText(" ");

         this->textctrl->AppendText(" ");

         this->textctrl->AppendText(wxString(include_dirs.at(i)));
     }

     this->textctrl->AppendText(wxT("\n\n  "));


     this->textctrl->SetDefaultStyle(AttrBold);

     this->textctrl->AppendText(wxT("\n\n    SOURCE FILE DIRECTORIES RECORD:"));

     this->textctrl->SetDefaultStyle(AttrLigth);

     this->textctrl->AppendText(wxT("\n\n"));


     int source_dir_num = this->Des_Reader->Get_Source_File_Directory_Number();

     std::vector<std::string> source_dirs;

     if(source_dir_num > 0){

       for(int i=0;i<source_dir_num;i++){


          std::string number = std::to_string(i+1);

          std::string source_directory;
          
          source_directory.push_back('[');

          for(size_t i=0;i<number.length();i++){

              source_directory.push_back(number[i]);
          }

          source_directory.push_back(']');

          source_directory.push_back(' ');



          source_directory += this->Des_Reader->Get_Source_File_Directory(i);

          source_directory.push_back('\n');

          source_dirs.push_back(source_directory);
       }
     }

     for(int i=0;i<source_dir_num;i++){

         this->textctrl->AppendText(" ");

         this->textctrl->AppendText(" ");

         this->textctrl->AppendText(" ");

         this->textctrl->AppendText(" ");

         this->textctrl->AppendText(wxString(source_dirs.at(i)));
     }

    this->textctrl->AppendText(wxT("\n\n  "));



    this->textctrl->SetDefaultStyle(AttrBold);

    this->textctrl->AppendText(wxT("\n\n    LIBRARY DIRECTORIES RECORD:"));

    this->textctrl->SetDefaultStyle(AttrLigth);

    this->textctrl->AppendText(wxT("\n\n"));


    int lib_dir_num = this->Des_Reader->Get_Library_Directory_Number();

    std::vector<std::string> library_dirs;

    if(lib_dir_num > 0){

       for(int i=0;i<lib_dir_num;i++){

           std::string number = std::to_string(i+1);

           std::string library_directory;
           
           library_directory.push_back('[');

           for(size_t i=0;i<number.length();i++){

               library_directory.push_back(number[i]);
           }

           library_directory.push_back(number[0]);

           library_directory.push_back(']');

           library_directory.push_back(' ');


           library_directory += this->Des_Reader->Get_Library_Directory(i);

           library_directory.push_back('\n');

           library_dirs.push_back(library_directory);           
       }
    }

    for(int i=0;i<lib_dir_num;i++){

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(library_dirs.at(i)));
    }

    this->textctrl->AppendText(wxT("\n\n "));



    this->textctrl->SetDefaultStyle(AttrBold);

    this->textctrl->AppendText(wxT("\n\n    LIBRARY-FILES RECORD:"));

    this->textctrl->SetDefaultStyle(AttrLigth);

    this->textctrl->AppendText(wxT("\n\n"));




    int lib_files_num = this->Des_Reader->Get_Library_Files_Number();

    std::vector<std::string> library_files;


    if(lib_files_num > 0){

       for(int i=0;i<lib_files_num;i++){


           std::string number = std::to_string(i+1);

           std::string library_file;
           
           library_file.push_back('[');

          for(size_t i=0;i<number.length();i++){

              library_file.push_back(number[i]);
          }

           library_file.push_back(']');

           library_file.push_back(' ');


           library_file += this->Des_Reader->Get_Library_File(i);

           library_file.push_back('\n');

           library_files.push_back(library_file);
       }
    }

    for(int i=0;i<lib_files_num;i++){

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(" ");

        this->textctrl->AppendText(wxString(library_files.at(i)));
    }

    this->textctrl->AppendText(wxT("\n\n "));



    this->textctrl->SetDefaultStyle(AttrBold);

    this->textctrl->AppendText(wxT("\n\n   COMPILER OPTIONS RECORD:"));

    this->textctrl->SetDefaultStyle(AttrLigth);

    this->textctrl->AppendText(wxT("\n\n "));


    if(!this->Des_Reader->Get_Compiler_Options().empty()){

       const std::vector<std::string> & com_options = this->Des_Reader->Get_Compiler_Options();

       for(size_t i=0;i<com_options.size();i++){

           this->textctrl->AppendText(" ");           

           this->textctrl->AppendText(" ");           

           this->textctrl->AppendText(" ");           

           std::string str_line = com_options.at(i);

           this->textctrl->AppendText(wxString(str_line));
       }
    }

    this->textctrl->AppendText(wxT("\n\n "));

    this->textctrl->SetDefaultStyle(AttrBold);

    this->textctrl->AppendText(wxT("\n\n   LINKER OPTIONS RECORD:"));

    this->textctrl->SetDefaultStyle(AttrLigth);

    this->textctrl->AppendText(wxT("\n\n "));



    if(!this->Des_Reader->Get_Linker_Options().empty()){

       const std::vector<std::string> & link_options = this->Des_Reader->Get_Linker_Options();

       for(size_t i=0;i<link_options.size();i++){

           this->textctrl->AppendText(" ");

           this->textctrl->AppendText(" ");

           this->textctrl->AppendText(" ");

           std::string str_line = link_options.at(i);

           this->textctrl->AppendText(wxString(str_line));

           this->textctrl->AppendText(wxT("\n"));
       }
    }

    this->textctrl->AppendText(wxT("\n\n "));


    
    this->textctrl->AppendText(wxT("\n\n "));

    this->textctrl->SetDefaultStyle(AttrBold);

    this->textctrl->AppendText(wxT("\n\n   COMPILER PATHS RECORD:"));

    this->textctrl->SetDefaultStyle(AttrLigth);

    this->textctrl->AppendText(wxT("\n\n"));



    if(!this->Des_Reader->Get_Compiler_Paths().empty()){

       const std::vector<std::string> & compiler_paths = this->Des_Reader->Get_Compiler_Paths();

       for(size_t i=0;i<compiler_paths.size();i++){

           this->textctrl->AppendText(" ");

           this->textctrl->AppendText(" ");

           this->textctrl->AppendText(" ");

           std::string str_line = compiler_paths.at(i);

           this->textctrl->AppendText(wxString(str_line));

           this->textctrl->AppendText(wxT("\n"));
       }
    }

    this->textctrl->AppendText(wxT("\n\n "));

     */


    this->textctrl->SetCanFocus(false);

    this->textctrl->ShowPosition(0);

    this->textctrl->SetInsertionPoint(0);

    this->textctrl->SetScrollPos(wxVERTICAL,0,true);

    this->textctrl->Show(true);

    this->close_panel->Show(true);

    this->CloseButton->Show(true);

    this->Show(true);

    this->PostSizeEvent();

    this->Update();

    this->SetCanFocus(false);

    this->Update();

    DestroyCaret(); 
}



void Project_Descriptions_Printer::Delete_Spaces_on_String(std::string * str){

    size_t string_size = str->length();

    bool search_cond = true;

    do{

      search_cond = false;

      for(size_t i=0;i<str->length();i++){

          if((*str)[i] == ' '){

            search_cond = true;

            str->erase(i,1);
          }
        }

    }while(search_cond);
}

std::string Project_Descriptions_Printer::ConvertStdString(char * str){

     size_t str_size = strlen(str);

     std::string std_string;

     for(size_t i=0;i<str_size;i++){

          std_string.push_back(str[i]);
     }

     std_string.shrink_to_fit();

     return std_string;
}

void Project_Descriptions_Printer::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(240,240,240));

     dc.DrawRectangle(rect.GetX()-1, rect.GetY()-1, rect.GetWidth()+1,rect.GetHeight()+1);

     DestroyCaret(); 
}

void Project_Descriptions_Printer::PaintNow(wxWindow * wnd)
{
     wxClientDC dc(wnd);

     wxSize Rect_Size = wxSize(wnd->GetSize().x+1,wnd->GetSize().y+1);

     wxRect rect(Rect_Size);

     this->DrawBackground(dc,wnd,rect);

     DestroyCaret(); 
}


void Project_Descriptions_Printer::CloseWindow(wxCommandEvent & event){

     if(event.GetId() == ID_CLOSE_DESCRIPTION_WINDOW){

        this->Destroy();
     }
}


void Project_Descriptions_Printer::OnSize(wxSizeEvent & event){

     event.Skip(true);
     
     wxSize frame_size = this->GetClientSize();

     this->scroll_win->SetSize(wxSize(frame_size.x-25,frame_size.y-120));

     this->textctrl->SetSize(this->scroll_win->GetClientSize());

     this->PaintNow(this);
     

     DestroyCaret(); 
}


wxTextCtrl * Project_Descriptions_Printer::GetTextControl() const {

     return this->textctrl;
}

int Project_Descriptions_Printer::GetLogNumber(){

     return this->log_num;
}

bool Project_Descriptions_Printer::GetWindowsOpenStatus(){

     return this->window_open_status;
}


bool Project_Descriptions_Printer::Get_Syntax_Error_Status(){

     return this->syntax_error_status;
}

bool Project_Descriptions_Printer::Get_Invalid_Descriptor_File_Status(){

     return this->invalid_descriptor_file_status;
}

bool Project_Descriptions_Printer::Get_Gui_Read_Success_Status(){

     return this->descriptor_file_read_success;
}
