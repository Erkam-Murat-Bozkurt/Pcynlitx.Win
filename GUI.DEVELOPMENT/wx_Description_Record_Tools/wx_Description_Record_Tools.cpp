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


#include "wx_Description_Record_Tools.h"

wx_Description_Record_Tools::wx_Description_Record_Tools(){

    this->Inequality_Point = 0;

    this->Descriptor_File_Path = wxT("");

    this->is_project_file_selected = false;

    this->Description_Recorder_Command = wxT("");

    this->Process_Pointer = nullptr;

    this->Pr_File_Select_Dialog = nullptr;
}

wx_Description_Record_Tools::~wx_Description_Record_Tools(){

}

void wx_Description_Record_Tools::Receive_NoteBook_Manager(Custom_Notebook * Pointer){

     this->NB_Manager_Pointer = Pointer;
}

void wx_Description_Record_Tools::Receive_Project_File_Selection_Status(bool status){

     this->is_project_file_selected = status;
}

void wx_Description_Record_Tools::Receive_Descriptor_File_Path(wxString File_Path){

     this->Descriptor_File_Path = File_Path;
}

void wx_Description_Record_Tools::Receive_Text_Control(wxStyledTextCtrl * Text_Ctrl){

     this->Text_Ctrl = Text_Ctrl;
}

void wx_Description_Record_Tools::Receive_Main_Frame_Address(wxFrame * address){

     this->Frame = address;
}

void wx_Description_Record_Tools::Enter_Header_File_Location(){

     wxString Data_Type = "Header_File_Locations";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
      }
      else{

            this->Show_Descriptor_File_Identification_Error();
      }
}

void wx_Description_Record_Tools::Enter_Source_File_Location(){

     wxString Data_Type = "Source_File_Locations";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
     }
     else{
                this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_Library_Location(){

     wxString Data_Type = "Library_Locations";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
     }
     else{

           this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_Header_File(){

     wxString Data_Type = "Header_File_Names";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
     }
     else{

           this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_Header_File_Automatically(wxString Header_File_Path){

     wxString Data_Type = "Header_File_Names";

     this->Determine_Description_Recorder_Command(Data_Type,Header_File_Path);

     this->Description_Record_Process(this->Description_Recorder_Command);

     this->Update_Lexer_Index();

     this->NB_Manager_Pointer->File_Save();
}

void wx_Description_Record_Tools::Enter_Source_File(){

     wxString Data_Type = "Source_File_Names";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
      }
      else{

            this->Show_Descriptor_File_Identification_Error();
      }
}

void wx_Description_Record_Tools::Enter_Library_Name(){

     wxString Data_Type = "Library_Names";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
     }
     else{

           this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_Construction_Point(){

     wxString Data_Type = "Construction_Point";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Enter_Main_File_Name();

           this->Enter_Server_Class_Name();

           this->NB_Manager_Pointer->File_Save();
        }
     }
     else{
            this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_Server_Class_Name(){

     wxString Data_Type = "Server_Class_Name";

     wxString Input_Command = "Thread_Server";

     this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

     this->Description_Record_Process(this->Description_Recorder_Command);

     this->Update_Lexer_Index();

     this->Scroll_To_Position();

     this->NB_Manager_Pointer->File_Save();
}

void wx_Description_Record_Tools::Enter_Main_File_Name(){

     wxString Data_Type = "Main_File_Name";

     wxString Input_Command = "main.cpp";

     this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

     this->Description_Record_Process(this->Description_Recorder_Command);

     this->Update_Lexer_Index();
}

void wx_Description_Record_Tools::Enter_Thread_Function_Name(){

     wxString Data_Type = "Thread_Function_Names";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        int line_counter = 1;

        Input_Command = wxGetTextFromUser(wxT("What will the name of the thread function be?"), wxT("   ENTER THREAD FUNCTION NAME   "));

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
     }
     else{
              this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_Thread_Number(){

     wxString Data_Type = "Thread_Number";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        int line_counter = 1;

        Input_Command = wxGetTextFromUser(wxT(" How many thread will be executed ? "),

                                          wxT("ENTER  THREAD NUMBER"));

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
     }
     else{

           this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_Exe_File_Name(){

     wxString Data_Type = "Project_Executable_File_Name";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        int line_counter = 1;

        Input_Command = wxGetTextFromUser(wxT("What will be the name of the executable file"),

                                          wxT("ENTER EXECUTABLE FILE NAME"));

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Scroll_To_Position();

           this->NB_Manager_Pointer->File_Save();
        }
      }
      else{
              this->Show_Descriptor_File_Identification_Error();
      }
}

void wx_Description_Record_Tools::Enter_ITC_Class_Header_File_Name(){

     wxString Data_Type = "Inter_Thread_Class_Header_File_Names";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->NB_Manager_Pointer->File_Save();

           this->Enter_Header_File_Automatically(Input_Command);

           int Path_Size = Input_Command.length();

           char * Header_File_Path = new char [10*Path_Size];

           for(int i=0;i<Path_Size;i++){

               Header_File_Path[i] = Input_Command[i];
           }

           Header_File_Path[Path_Size] = '\0';

           this->CN_Reader.ReadClassName(Header_File_Path);

           wxString Class_Name_String = wxT("");

           int Class_Name_Size = strlen(this->CN_Reader.getClassName());

           for(int i=0;i<Class_Name_Size;i++){

               Class_Name_String = Class_Name_String + this->CN_Reader.getClassName()[i];
           }

           delete [] Header_File_Path;

           this->Enter_ITC_Class_Name(Class_Name_String);

           this->Enter_ITC_Class_Instance_Name(Class_Name_String);

           this->CN_Reader.Clear_Dynamic_Memory();
        }
     }
     else{
              this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_ITC_Class_Name(wxString ClassName){

     wxString Data_Type = "Inter_Thread_Class_Names";

     this->Determine_Description_Recorder_Command(Data_Type,ClassName);

     this->Description_Record_Process(this->Description_Recorder_Command);

     this->Update_Lexer_Index();

     this->NB_Manager_Pointer->File_Save();
}

void wx_Description_Record_Tools::Enter_ITC_Class_Instance_Name(wxString ClassName){

     wxString Data_Type = "Inter_Thread_Class_Instance_Names";

     wxString Input_Command = ClassName + "_IT";

     int line_counter = 1;

     this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

     this->Description_Record_Process(this->Description_Recorder_Command);

     this->Update_Lexer_Index();

     this->Scroll_To_Position();

     this->NB_Manager_Pointer->File_Save();
}

void wx_Description_Record_Tools::Enter_IT_Data_Type_Header_File_Name(){

     wxString Data_Type = "Inter_Thread_Data_Type_Header_File_Names";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        this->Pr_File_Select_Dialog = new Project_File_Selection_Dialog(this->Frame);

        if(this->Pr_File_Select_Dialog->Get_Project_File_Selection_Dialog()->ShowModal() == wxID_OK){

           Input_Command = this->Pr_File_Select_Dialog->Get_File_Selection_Control()->GetPath();

           this->Pr_File_Select_Dialog->Get_File_Selection_Control()->Destroy();
        }

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->NB_Manager_Pointer->File_Save();

           this->Enter_Header_File_Automatically(Input_Command);

           int Path_Size = Input_Command.length();

           char * Header_File_Path = new char [10*Path_Size];

           for(int i=0;i<Path_Size;i++){

               Header_File_Path[i] = Input_Command[i];
           }

           Header_File_Path[Path_Size] = '\0';

           this->CN_Reader.ReadClassName(Header_File_Path);

           wxString Class_Name_String = wxT("");

           int Class_Name_Size = strlen(this->CN_Reader.getClassName());

           for(int i=0;i<Class_Name_Size;i++){

               Class_Name_String = Class_Name_String + this->CN_Reader.getClassName()[i];
           }

           delete [] Header_File_Path;

           this->Enter_IT_Data_Type_Name_Automaticly(Class_Name_String);

           this->Enter_IT_Data_Type_Pointer_Name(Class_Name_String);

           this->CN_Reader.Clear_Dynamic_Memory();
        }
      }
      else{
                this->Show_Descriptor_File_Identification_Error();
      }
}

void wx_Description_Record_Tools::Enter_IT_Data_Type_Name_Automaticly(wxString ClassName){

     wxString Data_Type = "Inter_Thread_Data_Types";

     this->Determine_Description_Recorder_Command(Data_Type,ClassName);

     this->Description_Record_Process(this->Description_Recorder_Command);

     this->Update_Lexer_Index();

     this->NB_Manager_Pointer->File_Save();
}

void wx_Description_Record_Tools::Enter_IT_Data_Type_Name(){

     wxString Data_Type = "Inter_Thread_Data_Types";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        int line_counter = 1;

        Input_Command = wxGetTextFromUser(wxT("What is the type of the data?"),wxT("   ENTER INTER-THREAD DATA TYPE   "));

        if(Input_Command != wxT("")){

           this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

           this->Description_Record_Process(this->Description_Recorder_Command);

           this->Update_Lexer_Index();

           this->Enter_IT_Data_Type_Pointer_Name(Input_Command);

           this->NB_Manager_Pointer->File_Save();

           this->Enter_IT_Data_Type_Pointer_Name(Input_Command);
        }
     }
     else{

           this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Enter_IT_Data_Type_Pointer_Name(wxString Class_Name){

     wxString Data_Type = "Inter_Thread_Data_Type_Pointer_Names";

     wxString Pointer_Name = Class_Name + wxT("_SPr");

     this->Determine_Description_Recorder_Command(Data_Type,Pointer_Name);

     this->Description_Record_Process(this->Description_Recorder_Command);

     this->Update_Lexer_Index();

     this->Scroll_To_Position();
}

void wx_Description_Record_Tools::Enter_Namespace(){

     wxString Data_Type = "Namespace";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        Input_Command = wxGetTextFromUser(wxT("What will the name of the namespace be?"), wxT("   ENTER NAMESPACE   "));

        if(Input_Command != wxT("")){

             this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

             this->Description_Record_Process(this->Description_Recorder_Command);

             this->Update_Lexer_Index();

             this->Scroll_To_Position();

             this->NB_Manager_Pointer->File_Save();
          }
       }
       else{
                this->Show_Descriptor_File_Identification_Error();
       }

}

void wx_Description_Record_Tools::Enter_OpenMP_Option(bool option){

     wxString Data_Type = "OpenMP_Support";

     wxString Input_Command = "";

     if(this->is_project_file_selected){

        if(option == true){

           Input_Command = "true";

        }
        else{

           Input_Command = "false";
        }

        this->Determine_Description_Recorder_Command(Data_Type,Input_Command);

        this->Description_Record_Process(this->Description_Recorder_Command);

        this->Update_Lexer_Index();

        this->Scroll_To_Position();

        this->NB_Manager_Pointer->File_Save();

     }
     else{

             this->Show_Descriptor_File_Identification_Error();
     }
}

void wx_Description_Record_Tools::Determine_Description_Recorder_Command(wxString Data_Type,wxString Input_Command){

     this->Description_Recorder_Command = wxT("");

     this->Description_Recorder_Command = "Description_Recorder ";

     this->Description_Recorder_Command = this->Description_Recorder_Command + this->Descriptor_File_Path + wxT(" ");

     this->Description_Recorder_Command = this->Description_Recorder_Command + Data_Type + wxT(" ");

     this->Description_Recorder_Command = this->Description_Recorder_Command + Input_Command;
}

void wx_Description_Record_Tools::Update_Lexer_Index(){

     this->Text_Ctrl->LoadFile(this->Descriptor_File_Path);

     this->Text_Ctrl->SaveFile(this->Descriptor_File_Path);
}

void wx_Description_Record_Tools::Scroll_To_Position(){

     this->Text_Ctrl->ScrollToLine(this->Inequality_Point-10);

     this->Text_Ctrl->EnsureVisible(this->Inequality_Point);
}

void wx_Description_Record_Tools::Description_Record_Process(wxString Input_Command){

     this->Inequality_Point = 0;

     int Number_of_Lines = this->Text_Ctrl->GetLineCount();

     this->Process_Pointer = new wxProcess(this->Frame,ID_DESCRIPTION_RECORD);

     this->Process_Pointer->Redirect();

     int exit_status = wxExecute(Input_Command,wxEXEC_SYNC,this->Process_Pointer);

     wxString Record_String;

     wxInputStream * Input_Stream = this->Process_Pointer->GetInputStream();

     wxTextInputStream tStream(*Input_Stream);

     Record_String = tStream.ReadLine();

     std::string Number_String = Record_String.ToStdString();

     std::string::size_type sz;

     if(exit_status >= 0){

        this->Inequality_Point = std::stoi(Number_String,&sz);;
     }
     else{
             this->Inequality_Point = Number_of_Lines;
     }

     if(this->Process_Pointer != nullptr){

        delete this->Process_Pointer;

        this->Process_Pointer = nullptr;
     }
}

void wx_Description_Record_Tools::Show_Descriptor_File_Identification_Error(){

     wxString Message_String = wxT(" Descriptor file can not be determined! \nAt first Descriptor file must be selected");

     wxMessageDialog * info_dial = new wxMessageDialog(NULL,Message_String, wxT(""), wxOK);

     if(info_dial->ShowModal() == wxOK){

        delete info_dial;
     };
}
