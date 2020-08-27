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

#include "keyboard_event_controler.h"

keyboard_event_controler::keyboard_event_controler(){

      this->Ctrl_Key_Press = false;

      this->S_Key_Press = false;

      this->Y_Key_Press = false;

      this->Z_Key_Press = false;
}

keyboard_event_controler::~keyboard_event_controler(){

}

void keyboard_event_controler::Receive_Book_Manager(Custom_Notebook * Pointer){

     this->NB_Manager_Pointer = Pointer;
}

void keyboard_event_controler::Undo_Redo_Actions(wxStyledTextCtrl * text_ctrl, wxKeyEvent & event){

       if(event.GetKeyCode() ==  32){

           text_ctrl->EndUndoAction();

           text_ctrl->BeginUndoAction();
       }

       if(event.GetKeyCode() ==  13){

           text_ctrl->EndUndoAction();

           text_ctrl->BeginUndoAction();
       }

       if(event.GetKeyCode() ==  8){

           text_ctrl->EndUndoAction();

           text_ctrl->BeginUndoAction();
       }

       if(event.GetKeyCode() ==  9){

           text_ctrl->EndUndoAction();

           text_ctrl->BeginUndoAction();
       }

       if(event.GetKeyCode() ==  46){

           text_ctrl->EndUndoAction();

           text_ctrl->BeginUndoAction();
       }

       if(((!this->Ctrl_Key_Press) && (event.GetUnicodeKey() != 0))){

              text_ctrl->AddUndoAction(event.GetUnicodeKey(),wxSTC_PERFORMED_UNDO);
       }

       if(event.GetKeyCode() == 308){

          this->Ctrl_Key_Press = true;
       }

       if(((this->Ctrl_Key_Press) && (event.GetKeyCode() != 308))){

          if(event.GetUnicodeKey() == 83){

             this->S_Key_Press = true;
          }
          else{

                if(event.GetUnicodeKey() == 90){

                    this->Z_Key_Press = true;
                }
                else{

                      if(event.GetUnicodeKey() == 89){

                         this->Y_Key_Press = true;
                      }
                      else{

                           this->Ctrl_Key_Press = false;
                      }
                }
           }
       }

       if(this->Ctrl_Key_Press && this->S_Key_Press){

          this->NB_Manager_Pointer->File_Save();

          text_ctrl->SetSavePoint();

          text_ctrl->EmptyUndoBuffer();

          text_ctrl->BeginUndoAction();

          this->Ctrl_Key_Press = false;

          this->S_Key_Press = false;

          this->Y_Key_Press = false;

          this->Z_Key_Press = false;
       }

       if(this->Ctrl_Key_Press && this->Z_Key_Press){

          text_ctrl->Undo();

          this->Ctrl_Key_Press = false;

          this->Z_Key_Press = false;

          this->S_Key_Press = false;

          this->Y_Key_Press = false;
       }

       if(this->Ctrl_Key_Press && this->Y_Key_Press){

          text_ctrl->Redo();

          this->Ctrl_Key_Press = false;

          this->S_Key_Press = false;

          this->Y_Key_Press = false;

          this->Z_Key_Press = false;
       }
}

void keyboard_event_controler::Tab_Indentation(wxStyledTextCtrl * text_ctrl, wxKeyEvent & event){

     if(event.GetKeyCode() == 9){

       event.Skip(false);

       int line_number = text_ctrl->GetCurrentLine();

       wxString line_string = text_ctrl->GetLine(line_number);

       bool is_line_empty = this->Check_Is_Line_Empty(line_string);

       bool is_caret_at_start = this->Check_Is_Caret_At_Start(text_ctrl,line_number);

       if(is_line_empty && is_caret_at_start){

           int space_counter = this->Get_Line_Indentation(text_ctrl,line_number-1);

           for(int i=0;i<space_counter;i++){

               text_ctrl->AddText(" ");
           }
       }
       else{

            int Tab_Width = text_ctrl->GetTabWidth();

            for(int i=0;i<Tab_Width;i++){

                text_ctrl->AddText(" ");
            }
       }
     }

      event.StopPropagation();
}

void keyboard_event_controler::Auto_Indentation(wxStyledTextEvent & event, wxStyledTextCtrl * text_ctrl){

     if(event.GetKey() == 10){

        event.Skip(false);

        int line_number = text_ctrl->GetCurrentLine();

        int current_position = text_ctrl->GetCurrentPos();

        if(line_number > 0){

           int space_counter = this->Get_Line_Indentation(text_ctrl,line_number-1);

           text_ctrl->AddText("\n");

           current_position =  text_ctrl->GetCurrentPos();

           int next_position = current_position + space_counter;

           for(int i=0;i<space_counter;i++){

               text_ctrl->AddText(" ");
           }

           text_ctrl->GotoPos(next_position);
        }
     }
}

bool keyboard_event_controler::Check_Is_Line_Empty(wxString line_string){

     this->is_line_empty = true;

     for(int i=0;i<line_string.length();i++){

         if(((line_string[i] != '\n') && (line_string[i] != ' ') && (line_string[i] != '\t'))){

              this->is_line_empty = false;

              break;
         }
     }

     return this->is_line_empty;
}

bool keyboard_event_controler::Check_Is_Caret_At_Start(wxStyledTextCtrl * text_ctrl, int line_number){

     this->Is_Caret_At_Start = false;

     int line_start = text_ctrl->PositionFromLine(line_number);

     int current_position = text_ctrl->GetCurrentPos();

     if(line_start == current_position){

        this->Is_Caret_At_Start = true;
     }

     return this->Is_Caret_At_Start;
}

int keyboard_event_controler::Get_Line_Indentation(wxStyledTextCtrl * text_ctrl, int line_number){

    wxString line_string = text_ctrl->GetLine(line_number);

    bool is_line_empty = this->Check_Is_Line_Empty(line_string);

    bool is_caret_at_start = this->Check_Is_Caret_At_Start(text_ctrl,line_number);

    int line_counter = line_number;

    while(((is_line_empty) && (line_counter > 0))){

           line_counter--;

           line_string = "";

           line_string = text_ctrl->GetLine(line_counter);

           is_line_empty = this->Check_Is_Line_Empty(line_string);
    }

    line_string = text_ctrl->GetLine(line_counter);

    int line_start_position = text_ctrl->PositionFromLine(line_counter);

    int next_line_start_position = text_ctrl->PositionFromLine(line_counter+1);

    int line_range = next_line_start_position - line_start_position;

    this->space_counter = 0;

    for(int i=0;i<line_range;i++){

        if(((line_string[i] != ' ') && (line_string[i] != '\t'))){

            break;
        }

        this->space_counter++;
    }

    return this->space_counter;
}
