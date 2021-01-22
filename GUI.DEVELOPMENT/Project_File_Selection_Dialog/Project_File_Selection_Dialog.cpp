/*

Copyright ©  2021,  Erkam Murat Bozkurt

This file is part of the research project which is carried by Erkam Murat Bozkurt.

This is a free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation
either version 3 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include "Project_File_Selection_Dialog.h"

Project_File_Selection_Dialog::Project_File_Selection_Dialog(wxFrame * Frame){

    this->File_Selection_Dialog = new wxDialog(Frame,-1,"MAKE SELECTION",wxDefaultPosition,

            wxSize(650,500),wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);


    this->File_Selection_Panel = new wxPanel(this->File_Selection_Dialog,-1,

           wxDefaultPosition,wxSize(650,500));


    this->vbox = new wxBoxSizer(wxVERTICAL);

    this->hbox = new wxBoxSizer(wxHORIZONTAL);

    this->file_selection_sizer = new wxBoxSizer(wxVERTICAL);

    this->File_Selection_Control = new wxFileCtrl(this->File_Selection_Panel,

                        wxID_ANY,wxEmptyString,wxEmptyString,wxFileSelectorDefaultWildcardStr,

                        wxFC_DEFAULT_STYLE | wxFC_NOSHOWHIDDEN ,wxDefaultPosition,wxSize(650,500));


    this->File_Selection_Control->Centre();


    this->SelectButton = new wxButton(this->File_Selection_Dialog,wxID_OK,wxT(" Select "),

                        wxDefaultPosition, wxSize(90, 45));

    this->closeButton = new wxButton(this->File_Selection_Dialog,wxID_CANCEL,wxT(" Close "),

                        wxDefaultPosition, wxSize(90, 45));



    this->hbox->Add(this->SelectButton,0,wxALL,5);

    this->hbox->Add(this->closeButton,0,wxALL,5);

    this->hbox->Layout();



    this->file_selection_sizer->Add(this->File_Selection_Control,0, wxALL);

    this->File_Selection_Panel->SetSizer(this->file_selection_sizer);

    this->file_selection_sizer->SetSizeHints(this->File_Selection_Panel);


    this->vbox->Add(this->File_Selection_Panel,0, wxEXPAND | wxALL,20);

    this->vbox->Add(this->hbox,0, wxFIXED_MINSIZE | wxALL,10);

    this->File_Selection_Dialog->SetSizer(this->vbox);

    this->vbox->SetSizeHints(this->File_Selection_Dialog);


    this->File_Selection_Dialog->Centre();

    this->File_Selection_Dialog->SetAutoLayout(true);
}

Project_File_Selection_Dialog::~Project_File_Selection_Dialog(){

    if(this->File_Selection_Control != nullptr){

       delete this->File_Selection_Control;

       this->File_Selection_Control = nullptr;
    }

    if(this->SelectButton != nullptr){

       delete this->SelectButton;

       this->SelectButton = nullptr;
    }

    if(this->closeButton != nullptr){

        delete this->closeButton;

        this->closeButton = nullptr;
    }

    if(this->hbox != nullptr){

       delete this->hbox;

       this->hbox = nullptr;
    }

    if(this->vbox != nullptr){

       delete this->vbox;

       this->vbox = nullptr;
    }

    if(this->File_Selection_Panel != nullptr){

        delete this->File_Selection_Panel;

        this->File_Selection_Panel = nullptr;
    }

    if(this->file_selection_sizer != nullptr){

       delete this->file_selection_sizer;

       this->file_selection_sizer = nullptr;
    }

    if(this->File_Selection_Dialog != nullptr){

       delete this->File_Selection_Dialog;

       this->File_Selection_Dialog = nullptr;
    }
}

wxDialog * Project_File_Selection_Dialog::Get_Project_File_Selection_Dialog(){

    return this->File_Selection_Dialog;
}

wxFileCtrl * Project_File_Selection_Dialog::Get_File_Selection_Control(){

    return this->File_Selection_Control;
}
