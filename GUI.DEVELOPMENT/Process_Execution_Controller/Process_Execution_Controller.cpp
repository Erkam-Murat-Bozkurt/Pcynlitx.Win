/*

Copyright ©  2019,  Erkam Murat Bozkurt

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

#include "Process_Execution_Controller.h"

Process_Execution_Controller::Process_Execution_Controller(){

     this->Descriptor_File_Path = wxT("");

     this->is_project_file_selected = false;

     this->is_library_constructed = false;

     this->Process_Pointer = nullptr;

     this->Process_Event_Counter = 0;
}

Process_Execution_Controller::~Process_Execution_Controller(){

}

void Process_Execution_Controller::Receive_Main_Frame_Address(wxFrame * Frame){

     this->MainFrame_Pointer = Frame;
}

void Process_Execution_Controller::Construction_Point_Determination(){

     this->is_construction_point_determined = false;

     int Descriptor_File_Name_Size = 0;

     for(int k=this->Descriptor_File_Path.length();k>0;k--){

         if(this->Descriptor_File_Path[k] == '/'){

            break;
         }

         Descriptor_File_Name_Size++;
     }

     int Directory_Name_Size = this->Descriptor_File_Path.length() - Descriptor_File_Name_Size;

     wxString Directory_Name = wxT("");

     for(int k=0;k<this->Descriptor_File_Path.length() - Descriptor_File_Name_Size;k++){

         Directory_Name = Directory_Name + this->Descriptor_File_Path[k];
     }

     wxString shell_command = "Descriptor_File_Reader " + Directory_Name;

     this->Process_Exit_Status = 0;

     this->Process_Event_Counter = 0;

     this->process_end_condition = false;

     this->Process_Pointer = new wxProcess(this->MainFrame_Pointer,wxID_ANY);

     this->Process_Pointer->Redirect();

     this->Process_Exit_Status = wxExecute(shell_command,wxEXEC_SYNC,this->Process_Pointer);

     wxString log_string = wxT("");

     if(this->Process_Exit_Status != 0){

        wxInputStream * Error_Stream =  this->Process_Pointer->GetErrorStream( );

        wxTextInputStream tStream(*Error_Stream);

        while(!Error_Stream->Eof())
        {
            log_string = log_string + tStream.ReadLine() + wxT("\n");
        }

        delete this->Process_Pointer;

        if(log_string != wxT("")){

           wxRichMessageDialog * dial = new wxRichMessageDialog(this->MainFrame_Pointer,log_string,

                                        wxT("Error in construction"), wxOK|wxCENTRE);

           dial->ShowModal();

           return;
        }
        else{
                wxMessageDialog * dial = new wxMessageDialog(NULL,

                wxT("Descriptor file can not be readed successfuly! \nPlease cotrol declerations"), wxT("Info"), wxOK);

                dial->ShowModal();

                return;
          }
       }
       else{

            delete this->Process_Pointer;
       }

       if(this->Process_Exit_Status == 0){

          wxString Info_File = Directory_Name + wxT("/Construction_Point_Holder");

          wxTextFile File_Manager(Info_File);

          File_Manager.Create();

          if(File_Manager.Exists()){

             File_Manager.Open();

             if(File_Manager.IsOpened()){

                this->Construction_Point = File_Manager.GetFirstLine();

                this->is_construction_point_determined = true;

                wxString remove_command = wxT("rm ") + Info_File;

                wxShell(remove_command);
             }
             else{

                  this->is_construction_point_determined = false;
             }
          }
          else{

                  this->is_construction_point_determined = false;
          }
       }
       else{

            this->is_construction_point_determined = false;
       }
}

void Process_Execution_Controller::Control_Executable_File_Name(){

     this->is_executable_file_name_determined = false;

     int Descriptor_File_Name_Size = 0;

       for(int k=this->Descriptor_File_Path.length();k>0;k--){

           if(this->Descriptor_File_Path[k] == '/'){

              break;
           }

           Descriptor_File_Name_Size++;
       }

       int Directory_Name_Size = this->Descriptor_File_Path.length() - Descriptor_File_Name_Size;

       wxString Directory_Name = wxT("");

       for(int k=0;k<this->Descriptor_File_Path.length() - Descriptor_File_Name_Size;k++){

           Directory_Name = Directory_Name + this->Descriptor_File_Path[k];
       }

       wxString shell_command = "Descriptor_File_Reader " + Directory_Name;

       this->Process_Exit_Status = 0;

       this->Process_Event_Counter = 0;

       this->process_end_condition = false;

       this->Process_Pointer = new wxProcess(this->MainFrame_Pointer,wxID_ANY);

       this->Process_Pointer->Redirect();

       this->Process_Exit_Status = wxExecute(shell_command,wxEXEC_SYNC,this->Process_Pointer);

       wxString log_string = wxT("");

       if(this->Process_Exit_Status != 0){

          wxInputStream * Error_Stream =  this->Process_Pointer->GetErrorStream( );

          wxTextInputStream tStream(*Error_Stream);

          while(!Error_Stream->Eof())
          {
              log_string = log_string + tStream.ReadLine() + wxT("\n");
          }

          delete this->Process_Pointer;

          wxRichMessageDialog * dial = new wxRichMessageDialog(this->MainFrame_Pointer,log_string,

                                           wxT("Error in construction"), wxOK|wxCENTRE);

          dial->ShowModal();
       }
       else{
               wxString Record_String;

               wxInputStream * Input_Stream = this->Process_Pointer->GetInputStream();

               wxTextInputStream tStream(*Input_Stream);

               Record_String = tStream.ReadLine();

               std::string Name_String = Record_String.ToStdString();

               for(int i=0;i<Name_String.length();i++){

                   if(((Name_String[i] != ' ') && (Name_String[i] != '\0') && (Name_String[i] != '\t') && (Name_String[i] != '\n'))){

                       this->is_executable_file_name_determined = true;
                   }
               }

               delete this->Process_Pointer;
        }
}

void Process_Execution_Controller::RunLibraryBuilder(Custom_Tree_View_Panel ** Dir_List_Manager){

     if(this->is_library_constructed){

        wxMessageDialog * dial = new wxMessageDialog(NULL,

        wxT("The meta lirary has been already constructed ..\nDou you want to continue!"), wxT("Info"), wxYES_NO);

        if(dial->ShowModal()== wxID_NO){

           return;
        }
     }

     this->Dir_List_Manager = *Dir_List_Manager;

     if(this->is_project_file_selected){

        this->Construction_Point_Determination();

        if(this->is_construction_point_determined){

           this->Construct_Inter_Process_Files();

           this->Process_Exit_Status = 0;

           this->Process_Event_Counter = 0;

           this->process_end_condition = false;

           this->Process_Pointer = new wxProcess(this->MainFrame_Pointer,wxID_ANY);

           this->Process_Pointer->Redirect();

           this->Output_File_Path = this->Construction_Point + wxT("/Output.txt");

           this->Run_Command = wxT("");

           this->Run_Command = wxT("/usr/bin/Pcynlitx_Kernel ") + this->Descriptor_File_Path;

           wxString shell_command = "printf \"" + this->Run_Command + " >> " + this->Output_File_Path +

                                    "\"" + " >> " + this->Construction_Point + "/build_script.sh";

           wxShell(shell_command);

           shell_command = wxT("");

           shell_command = "bash " + this->Construction_Point + "/build_script.sh";

           this->Sub_Process_ID = wxExecute(shell_command,wxEXEC_ASYNC | wxEXEC_MAKE_GROUP_LEADER,this->Process_Pointer);

           int exit_status = 0;

           this->Process_Pointer->OnTerminate(this->Sub_Process_ID,exit_status);

           this->Process_Exit_Status = exit_status;

           this->ShowProgress();

           if(((this->Process_Event_Counter>=2) && (this->Process_Exit_Status == 0))){

                wxDialog * Succes_Dialog = new wxDialog(this->MainFrame_Pointer,

                                           -1,"THREAD MANAGEMENT LIBRARY CONSTRUCTION REPORT",wxDefaultPosition, wxSize(750,500));

                Succes_Dialog->Centre(wxBOTH);

                wxTextCtrl * Succes_Text = new wxTextCtrl(Succes_Dialog,wxID_ANY,wxEmptyString,

                                               wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE | wxTE_LEFT);

                Succes_Text->Centre(wxBOTH);

                Succes_Text->LoadFile(this->Output_File_Path);

                Succes_Dialog->ShowModal();

                delete Succes_Text;

                this->Clear_Inter_Process_Files();

                this->Dir_List_Manager->Load_Project_Directory(this->Construction_Point);

                this->is_library_constructed = true;
             }
             else{

                  this->Clear_Inter_Process_Files();
             }

             delete this->Process_Pointer;
          }
          else{
                  return;
          }
       }
       else{
              wxMessageDialog * dial = new wxMessageDialog(NULL,

              wxT("Project file was not selected ..\nPlease select a project file"), wxT("Info"), wxOK);

              dial->ShowModal();
       }
}

void Process_Execution_Controller::RunExeBuilder(Custom_Tree_View_Panel ** Dir_List_Manager){

     this->Dir_List_Manager = *Dir_List_Manager;

       if(this->is_library_constructed){

          this->Control_Executable_File_Name();

          if(this->is_executable_file_name_determined){

             this->Construct_Inter_Process_Files();

             this->Process_Event_Counter = 0;

             this->Process_Exit_Status = 0;

             this->process_end_condition = false;

             this->Process_Pointer = new wxProcess(this->MainFrame_Pointer,wxID_ANY);

             this->Output_File_Path = wxT("");

             this->Output_File_Path = this->Construction_Point + wxT("/Output.txt");

             this->Run_Command = wxT("");

             this->Run_Command = wxT("/usr/bin/MT_Project_Builder ") + this->Construction_Point;

             wxString shell_command = "printf \"" + this->Run_Command + " >> " + this->Output_File_Path +

                                      "\"" + " >> " + this->Construction_Point + "/build_script.sh";

             wxShell(shell_command);

             shell_command = wxT("");

             shell_command = "bash " + this->Construction_Point + "/build_script.sh";

             this->Sub_Process_ID = wxExecute(shell_command,wxEXEC_ASYNC | wxEXEC_MAKE_GROUP_LEADER,this->Process_Pointer);

             this->Process_Pointer->Redirect();

             int exit_status = 0;

             this->Process_Pointer->OnTerminate(this->Sub_Process_ID,exit_status);

             this->Process_Exit_Status = exit_status;

             this->ShowProgress();

             if(((this->Process_Event_Counter>=2) && (this->Process_Exit_Status == 0))){

                  wxDialog * Succes_Dialog = new wxDialog(this->MainFrame_Pointer,-1,

                                             "EXECUTABLE BINARY CONSTRUCTION REPORT", wxDefaultPosition, wxSize(600,500));

                  Succes_Dialog->Centre(wxBOTH);

                  wxTextCtrl * Succes_Text = new wxTextCtrl(Succes_Dialog,wxID_ANY,wxEmptyString,

                                             wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE | wxTE_LEFT);

                  Succes_Text->Centre(wxBOTH);

                  Succes_Text->LoadFile(this->Output_File_Path);

                  Succes_Dialog->ShowModal();

                  delete Succes_Text;

                  this->Clear_Inter_Process_Files();

                  this->Dir_List_Manager->Load_Project_Directory(this->Construction_Point);
            }
            else{

                  this->Clear_Inter_Process_Files();
            }

             delete this->Process_Pointer;
          }
          else{

                wxMessageDialog * dial = new wxMessageDialog(NULL,

                wxT("There is no executable file name description ..\nPlease enter executable file name first"), wxT("Info"), wxOK);

                dial->ShowModal();
          }
       }
       else{
              wxMessageDialog * dial = new wxMessageDialog(NULL,

              wxT("Meta library was not builded ..\nPlease build meta library first"), wxT("Info"), wxOK);

              dial->ShowModal();
       }
}

void Process_Execution_Controller::ShowProgress(){

     if(this->Process_Event_Counter < 2){

        int max = 10;

        wxString Process_Label;

        if(this->is_library_constructed){

            Process_Label = wxT("EXECUTABLE BINARY CONSTRUCTION PROCESS");
        }
        else{

                Process_Label = wxT("LIBRARY CONSTRUCTION PROCESS");
        }

        wxProgressDialog dialog(wxT("Progress Dialog"),Process_Label,max,this->MainFrame_Pointer,wxPD_CAN_ABORT | wxPD_APP_MODAL);

        bool cont = true;

        for(int i=0;i<=max;i++){

            if(this->Process_Exit_Status != 0){

               break;
            }

            if(((this->Process_Event_Counter >= 2)&& (i >= (max -1)))){

                  break;
            }

            if(this->Process_Event_Counter < 2){

                if(i>= max -1){

                   i--;
                }
            }

            wxSleep(1);

            cont = dialog.Update(i);

            if(!cont)
            {
                 if(wxMessageBox(wxT("Do you really want to cancel?"),wxT("Progress dialog question"),

                                 wxYES_NO | wxICON_QUESTION) == wxYES);

                    break;
            }
        }

        dialog.Resume();

        if(!cont)

            wxLogStatus(wxT("Progress dialog aborted!"));
        else

            wxLogStatus(wxT("Countdown from %d finished"),max);
    }
}

void Process_Execution_Controller::Process_End(int Process_Exit_Status){

     this->Process_Exit_Status = Process_Exit_Status;

     this->process_end_condition = true;

     wxString Compiler_Output_File =  this->Construction_Point + wxT("/Compiler_Output");

     wxTextFile Compiler_Output_File_Control(Compiler_Output_File);

     bool Is_Compiler_Output_File_Empty = false;

     this->Process_Event_Counter++;

     if(this->Process_Event_Counter >= 2){

        if(this->Process_Exit_Status != 0){

           Compiler_Output_File_Control.Open();

           if(Compiler_Output_File_Control.Exists()){

              wxString First_Line = Compiler_Output_File_Control.GetFirstLine();

              if(First_Line == wxT("")){

                 Is_Compiler_Output_File_Empty = true;
              }
          }
        }
      }

      wxString log_string = wxT("");

      if(((this->Process_Event_Counter>=2) && (this->Process_Exit_Status != 0) && (Is_Compiler_Output_File_Empty))){

           this->Process_Event_Counter = 0;

           wxInputStream * Error_Stream = this->Process_Pointer->GetErrorStream( );

           wxTextInputStream tStream(*Error_Stream);

           while(!Error_Stream->Eof())
           {
              log_string = log_string + tStream.ReadLine() + wxT("\n");
           }

           wxRichMessageDialog * dial = new wxRichMessageDialog(this->MainFrame_Pointer,

                                        log_string,wxT("Error in construction"), wxOK|wxCENTRE);

           dial->ShowModal();
       }
       else{

             if(((this->Process_Event_Counter>=2) && (this->Process_Exit_Status != 0))){

                  if(Compiler_Output_File_Control.Exists()){

                     this->Process_Event_Counter = 0;

                     wxDialog * Error_Dialog = new wxDialog(this->MainFrame_Pointer,

                              -1,"ERROR IN CONSTRUCTION! [COMPILER OUTPUT]", wxDefaultPosition, wxSize(600,500));

                     wxTextCtrl * Error_Text = new wxTextCtrl(Error_Dialog,

                              wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE | wxTE_LEFT);

                     Error_Text->LoadFile(Compiler_Output_File);

                     Error_Dialog->ShowModal();

                     delete Error_Text;
                }
            }
       }
}

void Process_Execution_Controller::Construct_Inter_Process_Files(){

     this->Clear_Inter_Process_Files();

     wxString shell_command = "printf \"#!/bin/bash\" >> " + this->Construction_Point + "/build_script.sh";

     wxShell(shell_command);

     shell_command = wxT("");

     shell_command = "printf \"\n\" >> " + this->Construction_Point + "/build_script.sh";

     wxShell(shell_command);

     shell_command = wxT("");

     wxString Output_File_Path = this->Construction_Point + wxT("/Output.txt");

     shell_command = "printf \"\" >> " + Output_File_Path;

     wxShell(shell_command);
}

void Process_Execution_Controller::Clear_Inter_Process_Files(){

     wxString Compiler_Output_File =  this->Construction_Point + wxT("/Compiler_Output");

     wxTextFile Compiler_Output_File_Control(Compiler_Output_File);

     if(Compiler_Output_File_Control.Exists()){

        wxString Remove_Command = wxT("rm ") + Compiler_Output_File;

        wxShell(Remove_Command);
     }

     wxString Build_Script_File_Path = this->Construction_Point + "/build_script.sh";

     wxTextFile Build_Script_File_Control(Build_Script_File_Path);

     if(Build_Script_File_Control.Exists()){

        wxString Remove_Command = wxT("rm ") + Build_Script_File_Path;

        wxShell(Remove_Command);
     }

     wxString Output_File_Path = this->Construction_Point + wxT("/Output.txt");

     wxTextFile Output_File_Control(Output_File_Path);

     if(Output_File_Control.Exists()){

        wxString Remove_Command = wxT("rm ") + Output_File_Path;

        wxShell(Remove_Command);
     }

     wxString Construction_Point_Holder_Path = this->Construction_Point+ wxT("/Construction_Point_Holder");

     wxTextFile Holder_File_Control(Construction_Point_Holder_Path);

     if(Holder_File_Control.Exists()){

        wxString Remove_Command = wxT("rm ") + Construction_Point_Holder_Path;

        wxShell(Remove_Command);
     }
}

void Process_Execution_Controller::Show_Descriptions(wxString Descriptor_File_Path){

     int Descriptor_File_Name_Size = 0;

     for(int k=Descriptor_File_Path.length();k>0;k--){

         if(Descriptor_File_Path[k] == '/'){

            break;
         }

         Descriptor_File_Name_Size++;
     }

     int Directory_Name_Size = Descriptor_File_Path.length() - Descriptor_File_Name_Size;

     wxString Directory_Name = wxT("");

     for(int k=0;k<Descriptor_File_Path.length() - Descriptor_File_Name_Size;k++){

         Directory_Name = Directory_Name + Descriptor_File_Path[k];
     }

     this->Process_Pointer = new wxProcess(wxPROCESS_DEFAULT);

     this->Process_Pointer->Redirect();

     wxString Description_Print_Command = wxT("/usr/bin/Description_Printer ");

     Description_Print_Command = Description_Print_Command + Directory_Name;

     int Process_Exit_Status = 0;

     Process_Exit_Status = wxExecute(Description_Print_Command,wxEXEC_SYNC,this->Process_Pointer);

     wxString log_string = wxT("");

     if(Process_Exit_Status != 0){

        wxInputStream * Error_Stream =  this->Process_Pointer->GetErrorStream( );

        wxTextInputStream tStream(*Error_Stream);

        while(!Error_Stream->Eof())
        {
            log_string = log_string + tStream.ReadLine() + wxT("\n");
        }

        delete this->Process_Pointer;

        if(log_string != wxT("")){

           wxRichMessageDialog * dial = new wxRichMessageDialog(this->MainFrame_Pointer,

                                            log_string,wxT("Error in Descriptor File Reading"), wxOK|wxCENTRE);

           dial->ShowModal();

           delete dial;

           return;
        }
     }
     else{
            wxInputStream * Output_Stream =  this->Process_Pointer->GetInputStream( );

            wxTextInputStream tStream(*Output_Stream);

            while(!Output_Stream->Eof())
            {
                log_string = log_string + tStream.ReadLine() + wxT("\n");
            }

            delete this->Process_Pointer;

            wxDialog * Succes_Dialog = new wxDialog(this->MainFrame_Pointer,-1,

                                           "YOUR DESCRIPTIONS",

                                           wxDefaultPosition, wxSize(900,650),wxDEFAULT_DIALOG_STYLE | wxMAXIMIZE_BOX | wxRESIZE_BORDER);

            Succes_Dialog->SetVirtualSize(wxSize(2000,2000));

            Succes_Dialog->Centre(wxBOTH);


            wxTextCtrl * text_ctrl = new wxTextCtrl(Succes_Dialog,wxID_ANY,wxEmptyString,

                                                    wxDefaultPosition, wxSize(900,650),wxTE_MULTILINE | wxTE_LEFT | wxTE_READONLY);

	          text_ctrl->SetVirtualSize(wxSize(2000,2000));

	          text_ctrl->SetDefaultStyle(wxTextAttr(wxTE_READONLY));

	          text_ctrl->SetDefaultStyle(wxTextAttr(wxColour(100,100,100)));

            for(int i=0;i<log_string.length();i++){

                if(log_string[i+1] == '['){

                   text_ctrl->SetDefaultStyle(wxTextAttr(wxColour(217,136,128)));
                }

                text_ctrl->AppendText(log_string[i]);


	              if(log_string[i] == ']'){

                  text_ctrl->SetDefaultStyle(wxTextAttr(wxColour(100,100,100)));
		            }

                if(log_string[i] == '{'){

                   text_ctrl->SetDefaultStyle(wxTextAttr(wxColour(100,100,100)));
                }

                if(log_string[i+1] == '}'){

                   text_ctrl->SetDefaultStyle(wxTextAttr(wxColour(100,100,100)));
                }
            }

            text_ctrl->Centre(wxBOTH);

            Succes_Dialog->ShowModal();

            delete text_ctrl;

            delete Succes_Dialog;
     }
}


void Process_Execution_Controller::Set_Project_File_Select_Condition(bool condition){

    this->is_project_file_selected = true;
}

wxString Process_Execution_Controller::Get_Construction_Point(){

    return this->Construction_Point;
}

void Process_Execution_Controller::Receive_Descriptor_File_Path(wxString File_Path){

     this->Descriptor_File_Path = File_Path;
}
