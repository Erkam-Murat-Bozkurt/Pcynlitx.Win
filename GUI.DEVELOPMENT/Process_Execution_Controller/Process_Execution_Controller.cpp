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

     this->Output_Print_Number = 0;

     this->error_stream_status = false;

     this->Sub_Process_ID_Received = 0;

     this->Sub_Process_ID = 0;

     this->library_construction_process_start = false;

     this->exe_file_construction_process_start = false;
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

         if(this->Descriptor_File_Path[k] == '\\'){

            break;
         }

         Descriptor_File_Name_Size++;
     }

     int Directory_Name_Size = this->Descriptor_File_Path.length() - Descriptor_File_Name_Size;

     wxString Directory_Name = wxT("");

     for(int k=0;k<Directory_Name_Size;k++){

         Directory_Name = Directory_Name + this->Descriptor_File_Path[k];
     }

     wxString shell_command = "C:\\Program Files (x86)\\Pcynlitx\\bin\\Descriptor_File_Reader.exe " + Directory_Name;

     this->Process_Exit_Status = 0;

     this->Process_Event_Counter = 0;

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

           wxRichMessageDialog * dial = new wxRichMessageDialog(this->MainFrame_Pointer,

                        log_string, wxT("Error in construction"), wxOK|wxCENTRE);

           dial->ShowModal();

           return;
        }
        else{
                wxMessageDialog * dial = new wxMessageDialog(NULL,

                wxT("Descriptor file can not be readed successfuly! \nPlease cotrol declerations"),

                      wxT("Info"), wxOK);

                dial->ShowModal();

                return;
          }
       }
       else{

            delete this->Process_Pointer;
       }

       if(this->Process_Exit_Status == 0){

          wxString Info_File = Directory_Name + wxT("\\Construction_Point_Holder");

          wxTextFile File_Manager(Info_File);

          File_Manager.Create();

          if(File_Manager.Exists()){

             File_Manager.Open();

             if(File_Manager.IsOpened()){

                this->Construction_Point = File_Manager.GetFirstLine();

                this->is_construction_point_determined = true;

                wxString remove_command = wxT("PowerShell Remove-Item -Path  ") + Info_File;

                wxExecute(remove_command,wxEXEC_SYNC | wxEXEC_MAKE_GROUP_LEADER | wxEXEC_HIDE_CONSOLE ,NULL);

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

     size_t Descriptor_File_Name_Size = 0;

     for(int k=this->Descriptor_File_Path.length();k>0;k--){

         if(this->Descriptor_File_Path[k] == '\\'){

            break;
         }

        Descriptor_File_Name_Size++;
     }

     size_t Directory_Name_Size = this->Descriptor_File_Path.length() - Descriptor_File_Name_Size;

     wxString Directory_Name = wxT("");

     for(size_t k=0;k<Directory_Name_Size;k++){

         Directory_Name = Directory_Name + this->Descriptor_File_Path[k];
     }

     wxString shell_command = "C:\\Program Files (x86)\\Pcynlitx\\bin\\Descriptor_File_Reader.exe " + Directory_Name;

     this->Process_Exit_Status = 0;

     this->Process_Event_Counter = 0;

     this->Process_Pointer = new wxProcess(this->MainFrame_Pointer,wxID_ANY);

     this->Process_Pointer->Redirect();

     this->Sub_Process_ID_Received = wxExecute(shell_command,wxEXEC_SYNC,this->Process_Pointer);

     this->Sub_Process_ID = this->Process_Pointer->GetPid();


     wxString log_string = wxT("");

     if(this->Process_Exit_Status != 0){

         wxInputStream * Error_Stream =  this->Process_Pointer->GetErrorStream( );

         wxTextInputStream tStream(*Error_Stream);

         while(!Error_Stream->Eof())
         {
              log_string = log_string + tStream.ReadLine() + wxT("\n");
         }

        delete this->Process_Pointer;

        wxRichMessageDialog * dial = new wxRichMessageDialog(this->MainFrame_Pointer,

              log_string, wxT("Error in construction"), wxOK|wxCENTRE);


        dial->ShowModal();
      }
      else{
               wxString Record_String;

               wxInputStream * Input_Stream = this->Process_Pointer->GetInputStream();

               wxTextInputStream tStream(*Input_Stream);

               Record_String = tStream.ReadLine();

               std::string Name_String = Record_String.ToStdString();

               for(size_t i=0;i<Name_String.length();i++){

                   if(((Name_String[i] != ' ') && (Name_String[i] != '\0') &&

                      (Name_String[i] != '\t') && (Name_String[i] != '\n'))){

                       this->is_executable_file_name_determined = true;
                   }
               }

               delete this->Process_Pointer;
      }
}

void Process_Execution_Controller::RunLibraryBuilder(Custom_Tree_View_Panel ** Dir_List_Manager){

     if(this->is_library_constructed){

        wxMessageDialog * dial = new wxMessageDialog(NULL,

        wxT("The meta lirary has been already constructed ..\nDou you want to continue!"),

            wxT("Info"), wxYES_NO);

        if(dial->ShowModal()== wxID_NO){

           return;
        }
     }

     this->library_construction_process_start = true;

     this->Dir_List_Manager = *Dir_List_Manager;

     if(this->is_project_file_selected){

        this->Construction_Point_Determination();

        if(this->is_construction_point_determined){

           this->Process_Exit_Status = 0;

           this->Process_Event_Counter = 0;

           this->Output_Print_Number = 0;

           this->error_stream_status = false;

           this->Process_Pointer = new wxProcess(this->MainFrame_Pointer,wxID_ANY);

           this->Process_Pointer->Redirect();

           this->Run_Command = wxT("");

           this->Run_Command = wxT("C:\\Program Files (x86)\\Pcynlitx\\bin\\Pcynlitx_Kernel.exe ")

                            + this->Descriptor_File_Path;


           this->Sub_Process_ID_Received = wxExecute( this->Run_Command,

                                    wxEXEC_ASYNC | wxEXEC_MAKE_GROUP_LEADER

                                    | wxEXEC_HIDE_CONSOLE, this->Process_Pointer);


           this->Sub_Process_ID = this->Process_Pointer->GetPid();

           this->ShowProgress();



           this->Process_Pointer->OnTerminate(this->Sub_Process_ID,this->Process_Exit_Status);


           if(((this->Process_Event_Counter>=2) && (this->Process_Exit_Status == 0))){

              if(!this->Dir_List_Manager->Get_Panel_Open_Status()){

                 this->Dir_List_Manager->Load_Project_Directory(this->Construction_Point);
              }

              this->is_library_constructed = true;
           }

        }
        else{
                  return;
        }
      }
      else{
              wxMessageDialog * dial = new wxMessageDialog(NULL,

                    wxT("Project file was not selected ..\nPlease select a project file"),

                    wxT("Info"), wxOK);

              dial->ShowModal();
      }

      this->library_construction_process_start = false;
}

void Process_Execution_Controller::RunExeBuilder(Custom_Tree_View_Panel ** Dir_List_Manager){

     this->exe_file_construction_process_start = true;

     this->Dir_List_Manager = *Dir_List_Manager;

     if(this->is_library_constructed){

        this->Control_Executable_File_Name();

        if(this->is_executable_file_name_determined){

           this->Process_Event_Counter = 0;

           this->Process_Exit_Status = 0;

           this->error_stream_status = false;

           this->Output_Print_Number = 0;

           this->Process_Pointer = new wxProcess(this->MainFrame_Pointer,wxID_ANY);

           this->Process_Pointer->Redirect();


           this->Run_Command = wxT("");

           this->Run_Command = wxT("C:\\Program Files (x86)\\Pcynlitx\\bin\\MT_Project_Builder.exe ") + this->Construction_Point;


           this->Sub_Process_ID_Received = wxExecute(this->Run_Command,wxEXEC_ASYNC | wxEXEC_MAKE_GROUP_LEADER

                                    | wxEXEC_HIDE_CONSOLE ,this->Process_Pointer);

           this->Sub_Process_ID = this->Process_Pointer->GetPid();

           this->Process_Pointer->Redirect();


           this->ShowProgress();

           this->Process_Pointer->OnTerminate(this->Sub_Process_ID,this->Process_Exit_Status);

           if(((this->Process_Event_Counter>=2) && (this->Process_Exit_Status == 0))){

              if(!this->Dir_List_Manager->Get_Panel_Open_Status()){

                  this->Dir_List_Manager->Load_Project_Directory(this->Construction_Point);
              }
           }
        }
        else{

              wxMessageDialog * dial = new wxMessageDialog(NULL,

              wxT("There is no executable file name description ..\nPlease enter executable file name first"),

                   wxT("Info"), wxOK);

              dial->ShowModal();
        }
     }
     else{
              wxMessageDialog * dial = new wxMessageDialog(NULL,

              wxT("Meta library was not builded ..\nPlease build meta library first"), wxT("Info"), wxOK);

              dial->ShowModal();
     }

     this->exe_file_construction_process_start = false;
}

void Process_Execution_Controller::ShowProgress(){

     if(this->Process_Event_Counter < 1){

        int max = 10;

        wxString Process_Label;

        if(this->is_library_constructed){

            Process_Label = wxT("EXECUTABLE BINARY CONSTRUCTION PROCESS");
        }
        else{

                Process_Label = wxT("LIBRARY CONSTRUCTION PROCESS");
        }

        wxProgressDialog dialog(wxT(""),Process_Label,max,this->MainFrame_Pointer,

                      wxPD_APP_MODAL | wxPD_SMOOTH  );


        for(int i=0;i<=max;i++){

            bool construction_continue = false;

            if( this->library_construction_process_start || this->exe_file_construction_process_start ){

               construction_continue = true;
            }

            if(!construction_continue){

                break;
            }

            if(this->error_stream_status){

               break;
            }

            if(this->Process_Event_Counter >= 1){

                  break;
            }

            if(this->Process_Event_Counter < 1){

                if(i>= max -1){

                   i--;
                }
            }

            wxSleep(1);

            dialog.Update(i);
        }

        dialog.Resume();
    }
}

void Process_Execution_Controller::Process_End(int exit_status){

     this->Process_Exit_Status = exit_status;

     this->Process_Event_Counter++;

     if( this->library_construction_process_start || this->exe_file_construction_process_start){

         if(this->Output_Print_Number<1){

            this->Output_Print_Number++;

           this->Print_Construction_Process_Output();

         }
     }
}

void Process_Execution_Controller::Print_Construction_Process_Output(){

     wxString title = wxT("");

     if(this->is_library_constructed){

        title = wxT("EXECUTABLE BINARY CONSTRUCTION REPORT");
     }
     else{

          title = wxT("  THREAD MANAGEMENT LIBRARY CONSTRUCTION REPORT  ");
     }

     if(this->Process_Exit_Status == 0){

        if(this->Sub_Process_ID == this->Sub_Process_ID_Received){

           this->Print_Output_Stream(title);
        }
        else{

              this->error_stream_status = true;

              this->Print_Error_Stream(title);
        }
     }
     else{

          this->error_stream_status = true;

          this->Print_Error_Stream(title);
     }
}

void Process_Execution_Controller::Show_Descriptions(wxString Descriptor_File_Path){

     size_t Descriptor_File_Name_Size = 0;

     for(size_t k=Descriptor_File_Path.length();k>0;k--){

         if(Descriptor_File_Path[k] == '\\'){

            break;
         }

         Descriptor_File_Name_Size++;
     }

     size_t Directory_Name_Size = Descriptor_File_Path.length() - Descriptor_File_Name_Size;

     wxString Directory_Name = wxT("");

     for(size_t k=0;k<Directory_Name_Size;k++){

         Directory_Name = Directory_Name + Descriptor_File_Path[k];
     }

     this->Process_Pointer = new wxProcess(wxPROCESS_DEFAULT);

     this->Process_Pointer->Redirect();

     wxString Description_Print_Command = wxT("C:\\Program Files (x86)\\Pcynlitx\\bin\\Description_Printer.exe ");

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

                        wxDefaultPosition, wxSize(1000,850),wxDEFAULT_DIALOG_STYLE |

                        wxMAXIMIZE_BOX | wxRESIZE_BORDER);


            Succes_Dialog->SetVirtualSize(wxSize(2000,2000));

            Succes_Dialog->Centre(wxBOTH);


            wxTextCtrl * text_ctrl = new wxTextCtrl(Succes_Dialog,wxID_ANY,wxEmptyString,

                        wxDefaultPosition, wxSize(900,650),wxTE_MULTILINE | wxTE_LEFT | wxTE_READONLY);

	          text_ctrl->SetVirtualSize(wxSize(2000,2000));

	          text_ctrl->SetDefaultStyle(wxTextAttr(wxTE_READONLY));

	          text_ctrl->SetDefaultStyle(wxTextAttr(wxColour(100,100,100)));

            for(size_t i=0;i<log_string.length();i++){

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


void Process_Execution_Controller::Print_Text(wxString std_out, wxString title){

     wxDialog * Succes_Dialog = new wxDialog(this->MainFrame_Pointer,

                             -1,title,wxDefaultPosition,wxSize(950,650));

     Succes_Dialog->Centre(wxBOTH);


     wxTextCtrl * Succes_Text = new wxTextCtrl(Succes_Dialog,wxID_ANY,std_out,

                                 wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE | wxTE_LEFT);

     Succes_Text->Centre(wxBOTH);

     Succes_Dialog->ShowModal();

     delete Succes_Text;
}

void Process_Execution_Controller::Print_Error_Stream(wxString title){

     wxInputStream * Error_Stream = this->Process_Pointer->GetErrorStream( );

     wxChar buffer = '\0';

     wxString std_error = wxT("ERROR REPORTS:\n\n");

     if(Error_Stream->CanRead()){

        do{

            Error_Stream->Read(&buffer,1);

            std_error.Append(buffer,1);

        }while(!Error_Stream->Eof());
     }

     this->Print_Text(std_error,wxT("ERROR IN CONSTRUCTION"));
}

void Process_Execution_Controller::Print_Output_Stream(wxString title){

     wxInputStream * stream = this->Process_Pointer->GetInputStream();

     wxChar buffer = '\0';

     wxString std_out = "";

     if(stream->CanRead()){

        do{

            stream->Read(&buffer,1);

            std_out.Append(buffer,1);

        }while(!stream->Eof());

        this->Print_Text(std_out,title);
     }

     this->Process_Pointer->CloseOutput();
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
