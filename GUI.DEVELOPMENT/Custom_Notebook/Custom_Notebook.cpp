
#include "Custom_Notebook.h"


Custom_Notebook::Custom_Notebook( wxPanel * parent, wxAuiManager * Interface_Manager,

       wxFont Default_Font,wxSize size)

      : wxAuiNotebook(parent,wxID_ANY,wxDefaultPosition,size,wxAUI_NB_DEFAULT_STYLE)
{

   this->Is_Intro_Page_Open = false;

   this->Is_Help_Page_Open = false;

   this->Interface_Manager_Pointer = Interface_Manager;

   this->SetThemeEnabled(false);


   this->Custom_Notebook_TabArt = new Custom_TabArt();

   this->SetArtProvider(this->Custom_Notebook_TabArt);


   this->SetBackgroundStyle(wxBG_STYLE_PAINT);

   this->SetBackgroundColour(wxColour(235,235,235));

   this->SetDoubleBuffered(true);

   this->SetExtraStyle(wxCLIP_CHILDREN);

   this->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

   this->SetEvtHandlerEnabled(true);


   this->GetEventHandler()->Bind(wxEVT_SIZE,&Custom_Notebook::Size_Event,this,wxID_ANY);

   this->GetEventHandler()->Bind(wxEVT_PAINT,&Custom_Notebook::OnPaint,this,wxID_ANY);

   wxAuiNotebookEvent File_Closed(wxEVT_AUINOTEBOOK_PAGE_CLOSE,this->GetId());

   this->GetEventHandler()->Bind(wxEVT_AUINOTEBOOK_PAGE_CLOSE,&Custom_Notebook::NoteBook_Page_Closed,this,wxID_ANY);

   wxAuiNotebookEvent File_Selection_Change(wxEVT_AUINOTEBOOK_PAGE_CLOSE,this->GetId());

   this->GetEventHandler()->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED,&Custom_Notebook::Determine_Current_Page,this,wxID_ANY);

   wxStyledTextEvent File_Change(wxEVT_STC_CHANGE,this->GetId());

   this->GetEventHandler()->Bind(wxEVT_STC_CHANGE,&Custom_Notebook::Document_Change,this,wxID_ANY);

   wxAuiNotebookEvent File_Selection_Changing(wxEVT_AUINOTEBOOK_PAGE_CHANGING,this->GetId());

   this->GetEventHandler()->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGING,&Custom_Notebook::Selection_Changing,this,wxID_ANY);


   this->Fit();

   this->SetAutoLayout(true);

   this->Initialization();

   this->OpenIntroPage();

   this->Refresh();

   this->SetTabCtrlHeight(35);

   this->Default_Font = Default_Font;

   this->Show(true);

   this->ClearBackground();

   this->Centre();

   this->CentreOnParent(wxBOTH);

   this->Refresh();

   this->Update();

   this->PaintNow(this);
};

void Custom_Notebook::Size_Event(wxSizeEvent & event)
{
     event.Skip(true);

     this->PaintNow(this);
}

void Custom_Notebook::Initialization(){

     this->Memory_Delete_Condition = false;

     this->Style_Change_Operation = false;

     this->Current_Page_Record_Index = 0;

     for(int i=0;i<20;i++){

         this->NoteBook_Page_Data[i].Is_Pointer_Free = true;

         this->NoteBook_Page_Data[i].File_Path = wxT("");

         this->NoteBook_Page_Data[i].Document_Change_Condition = false;

         this->NoteBook_Page_Data[i].Window_ID = 0;

         this->NoteBook_Page_Data[i].Text_Ctrl = nullptr;

         this->NoteBook_Page_Data[i].Is_This_Text_File = false;

         this->NoteBook_Page_Data[i].Intro_Page_Pointer = nullptr;

         this->NoteBook_Page_Data[i].Help_Page_Pointer = nullptr;

         this->NoteBook_Page_Data[i].Document_Change_In_File_Open = false;

         this->NoteBook_Page_Data[i].Is_Page_Open = false;
     }
}

Custom_Notebook::~Custom_Notebook(){

    if(!this->Memory_Delete_Condition){

        this->Memory_Delete_Condition = true;

        this->DeleteAllPages();

        this->OnClose();
    }
};

void Custom_Notebook::OpenIntroPage()
{
     // Intro page initialization

     if(!this->Is_Intro_Page_Open)
     {
         this->Is_Intro_Page_Open = true;

         int Index_Number = this->Get_Empty_Pointer_Index_Number();

         this->NoteBook_Page_Data[Index_Number].Intro_Page_Pointer =

                      new Intro_Page_Loader(this,this->GetClientSize(),

                      this->GetTabCtrlHeight());

         this->NoteBook_Page_Data[Index_Number].Intro_Page_Pointer->Receive_Intro_Page_Open_Status(&this->Is_Intro_Page_Open);

         this->NoteBook_Page_Data[Index_Number].Intro_Page_Pointer->FitInside();

         this->NoteBook_Page_Data[Index_Number].Window_ID = this->NoteBook_Page_Data[Index_Number].Intro_Page_Pointer->GetId();

         this->Introduction_Page_Id = this->NoteBook_Page_Data[Index_Number].Window_ID;

         this->NoteBook_Page_Data[Index_Number].Document_Change_In_File_Open = false;

         // Load Intro Page

         bool is_loaded = this->AddPage(this->NoteBook_Page_Data[Index_Number].Intro_Page_Pointer,wxT(" Introduction  "),true);

         this->NoteBook_Page_Data[Index_Number].Intro_Page_Pointer->Show(true);

         this->NoteBook_Page_Data[Index_Number].Intro_Page_Pointer->Refresh();

         this->NoteBook_Page_Data[Index_Number].Document_Change_Condition = false;

         this->NoteBook_Page_Data[Index_Number].Is_Pointer_Free = false;

         this->NoteBook_Page_Data[Index_Number].Is_Page_Open = true;

         this->NoteBook_Page_Data[Index_Number].File_Path = wxT("");

         this->NoteBook_Page_Data[Index_Number].Is_This_Text_File = false;

     }

     this->Refresh();
}

void Custom_Notebook::Load_Help_Page()
{
     // Load Help Page

     if(!this->Is_Help_Page_Open)
     {
        this->Is_Help_Page_Open = true;

        int Index_Number = this->Get_Empty_Pointer_Index_Number();

        this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer =

                           new Help_Page_Loader(this,this->GetClientSize());

        this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer->Receive_Help_Page_Open_Status(&this->Is_Help_Page_Open);

        this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer->FitInside();

        this->NoteBook_Page_Data[Index_Number].Window_ID = this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer->GetId();

        this->Introduction_Page_Id = this->NoteBook_Page_Data[Index_Number].Window_ID;

        this->NoteBook_Page_Data[Index_Number].Document_Change_In_File_Open = false;

        this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer->Initialize_Help_Page_Text(this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer);

        bool is_loaded = this->AddPage(this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer,wxT(" Help Page  "),true);

        this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer->Show(true);

        this->NoteBook_Page_Data[Index_Number].Help_Page_Pointer->Refresh();

        this->NoteBook_Page_Data[Index_Number].Document_Change_Condition = false;

        this->NoteBook_Page_Data[Index_Number].Is_Pointer_Free = false;

        this->NoteBook_Page_Data[Index_Number].Is_Page_Open = true;

        this->NoteBook_Page_Data[Index_Number].File_Path = wxT("");

        this->NoteBook_Page_Data[Index_Number].Is_This_Text_File = false;
     }

     this->Refresh();
}

void Custom_Notebook::OnClose()
{
     this->GetEventHandler()->Unbind(wxEVT_AUINOTEBOOK_PAGE_CLOSE,&Custom_Notebook::NoteBook_Page_Closed,this,wxID_ANY);

     this->GetEventHandler()->Unbind(wxEVT_AUINOTEBOOK_PAGE_CHANGED,&Custom_Notebook::Determine_Current_Page,this,wxID_ANY);

     this->GetEventHandler()->Unbind(wxEVT_STC_CHANGE,&Custom_Notebook::Document_Change,this,wxID_ANY);

     this->GetEventHandler()->Unbind(wxEVT_AUINOTEBOOK_PAGE_CHANGING,&Custom_Notebook::Selection_Changing,this,wxID_ANY);

     this->GetEventHandler()->Unbind(wxEVT_PAINT,&Custom_Notebook::OnPaint,this,wxID_ANY);

     this->GetEventHandler()->Unbind(wxEVT_SIZE,&Custom_Notebook::Size_Event,this,wxID_ANY);
}

void Custom_Notebook::PaintNow(wxWindow * wnd)
{
     wxClientDC dc(wnd);

     wxSize Rect_Size = wxSize(wnd->GetSize().x+5,wnd->GetSize().y+5);

     wxRect rect(Rect_Size);

     this->DrawBackground(dc,wnd,rect);
}

void Custom_Notebook::OnPaint(wxPaintEvent & event)
{
     event.Skip(false);  // The custom paint event must not be skipped ..

     event.StopPropagation();

     wxPaintDC dc(this);

     wxRect rect(this->GetSize());

     this->DrawBackground(dc,this,rect);
};

void Custom_Notebook::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& rect)
{
     dc.SetBrush(wxColour(235,235,235));

     dc.DrawRectangle(rect.GetX()-1,rect.GetY()-1,rect.GetWidth()+5,rect.GetHeight()+5);
};

void Custom_Notebook::Change_Cursor_Type()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file){

            this->NoteBook_Page_Data[i].Text_Ctrl->SetSTCCursor(2);
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Load_Default_Cursor()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file){

            this->NoteBook_Page_Data[i].Text_Ctrl->SetSTCCursor(-1);
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Set_Caret_Line_InVisible()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file){

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretLineVisible(false);
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Set_Caret_Line_Visible()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file){

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretLineVisible(true);

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretLineBackground(wxColour(220,220,220));
        }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Use_Default_Caret()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file){

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretStyle(1);

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretWidth(1);

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretForeground(wxColour(50,50,50));
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Use_Block_Caret()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file){

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretStyle(2);

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretWidth(1);

            this->NoteBook_Page_Data[i].Text_Ctrl->SetCaretForeground(wxColour(150,150,150));
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::File_Save()
{
     wxString Current_Page_Text_Path = this->NoteBook_Page_Data[this->Current_Page_Record_Index].File_Path;

     this->NoteBook_Page_Data[this->Current_Page_Record_Index].Text_Ctrl->SaveFile(Current_Page_Text_Path,wxTEXT_TYPE_ANY);

     this->NoteBook_Page_Data[this->Current_Page_Record_Index].Document_Change_Condition = false;
}

void Custom_Notebook::Add_New_File(wxString File_Path)
{
     bool Is_File_Open = this->Is_File_Open(File_Path);

     if(!Is_File_Open){

         int Index_Number = this->Get_Empty_Pointer_Index_Number();

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl = new Custom_TextCtrl(this,wxID_ANY,wxDefaultPosition,

                                                      this->GetClientSize(),File_Path);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetVirtualSize(this->GetClientSize());

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetMinSize(this->GetClientSize());

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->FitInside();

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetExtraStyle(wxCLIP_CHILDREN);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetAutoLayout(true);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetDoubleBuffered(true);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetUseHorizontalScrollBar(true);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetUseVerticalScrollBar(true);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->FitInside();

         this->NoteBook_Page_Data[Index_Number].Window_ID = this->NoteBook_Page_Data[Index_Number].Text_Ctrl->GetId();

         this->NoteBook_Page_Data[Index_Number].File_Path = File_Path;

         this->NoteBook_Page_Data[Index_Number].Document_Change_Condition = false;

         this->NoteBook_Page_Data[Index_Number].Document_Change_In_File_Open = true;

         this->NoteBook_Page_Data[Index_Number].Is_Pointer_Free = false;

         this->NoteBook_Page_Data[Index_Number].Is_This_Text_File = true;

         this->Text_Style_Loader.Set_Lexer_Style(this->Default_Font,this->NoteBook_Page_Data[Index_Number].Text_Ctrl);

         this->Determine_File_Short_Name(File_Path);

         this->AddPage(this->NoteBook_Page_Data[Index_Number].Text_Ctrl,this->File_Short_Name);

         this->Update();

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetReadOnly(false);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->LoadFile(File_Path);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->ClearAll();

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SaveFile(File_Path);

         this->Select_File(File_Path);

         this->Refresh();
     }
     else{

          this->Select_File(File_Path);

          this->Refresh();
     }
}

void Custom_Notebook::Open_File(wxString File_Path)
{
     bool Is_File_Open = this->Is_File_Open(File_Path);

     if(!Is_File_Open){

         int Index_Number = this->Get_Empty_Pointer_Index_Number();

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl = new Custom_TextCtrl(this,wxID_ANY,wxDefaultPosition,

                                                      this->GetClientSize(),File_Path);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetVirtualSize(this->GetClientSize());

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetMinSize(this->GetClientSize());

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetExtraStyle(wxNO_FULL_REPAINT_ON_RESIZE);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetExtraStyle(wxCLIP_CHILDREN);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetExtraStyle(wxWS_EX_BLOCK_EVENTS);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetUseHorizontalScrollBar(true);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetUseVerticalScrollBar(true);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetAutoLayout(true);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetDoubleBuffered(true);

         this->NoteBook_Page_Data[Index_Number].Window_ID = this->NoteBook_Page_Data[Index_Number].Text_Ctrl->GetId();

         this->Text_Style_Loader.Set_Lexer_Style(this->Default_Font,this->NoteBook_Page_Data[Index_Number].Text_Ctrl);

         this->Determine_File_Short_Name(File_Path);

         this->NoteBook_Page_Data[Index_Number].File_Path = File_Path;

         this->NoteBook_Page_Data[Index_Number].Document_Change_Condition = false;

         this->NoteBook_Page_Data[Index_Number].Document_Change_In_File_Open = true;

         this->NoteBook_Page_Data[Index_Number].Is_Pointer_Free = false;

         this->NoteBook_Page_Data[Index_Number].Is_This_Text_File = true;

         this->AddPage(this->NoteBook_Page_Data[Index_Number].Text_Ctrl,this->File_Short_Name);

         this->SetSelection(Index_Number);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->SetReadOnly(false);

         this->NoteBook_Page_Data[Index_Number].Text_Ctrl->LoadFile(File_Path);

         this->NoteBook_Page_Data[Index_Number].Is_Page_Open = true;

         this->Select_File(File_Path);

         this->Refresh();
     }
     else{

           this->Select_File(File_Path);

           this->Refresh();
     }
}

void Custom_Notebook::Set_Font(wxFont Font)
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file){

            if( this->NoteBook_Page_Data[i].Window_ID != this->Introduction_Page_Id ){

                this->Text_Style_Loader.Set_Lexer_Style(Font,this->NoteBook_Page_Data[i].Text_Ctrl);
            }
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Set_Lexer_Style(wxFont Default_Font)
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file)
         {
            if( this->NoteBook_Page_Data[i].Window_ID != this->Introduction_Page_Id )
            {
                this->Text_Style_Loader.Set_Lexer_Style(Default_Font,

                      this->NoteBook_Page_Data[i].Text_Ctrl);
            }
          }
     }

    this->SetSelection(Selection);

    this->Style_Change_Operation = false;
}

void Custom_Notebook::Set_Style_Font(wxFont Font)
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file)
         {
            if( this->NoteBook_Page_Data[i].Window_ID != this->Introduction_Page_Id )
            {
                this->Text_Style_Loader.Set_Style_Font(Font,this->NoteBook_Page_Data[i].Text_Ctrl);
            }
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Use_Bold_Styling()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file)
         {
            if( this->NoteBook_Page_Data[i].Window_ID != this->Introduction_Page_Id ){

                this->Text_Style_Loader.Use_Bold_Styling(this->NoteBook_Page_Data[i].Text_Ctrl);
            }
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Clear_Style()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

         wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

         bool is_this_file_open = this->Is_File_Open(File_Path);

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_file_open && is_this_text_file)
         {
            if( this->NoteBook_Page_Data[i].Window_ID != this->Introduction_Page_Id )
            {
                this->Text_Style_Loader.Clear_Text_Control_Style(this->NoteBook_Page_Data[i].Text_Ctrl,

                  this->Default_Font);
            }
         }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

void Custom_Notebook::Reload_Style()
{
     this->Style_Change_Operation = true;

     int Selection = this->GetSelection();

     for(int i=0;i<20;i++){

        wxString File_Path = this->NoteBook_Page_Data[i].File_Path;

        bool is_this_file_open = this->Is_File_Open(File_Path);

        bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

        if(is_this_file_open && is_this_text_file)
        {
           if( this->NoteBook_Page_Data[i].Window_ID != this->Introduction_Page_Id ){

              this->Text_Style_Loader.Reload_Text_Control_Style(this->NoteBook_Page_Data[i].Text_Ctrl,

                this->Default_Font);
           }
        }
     }

     this->SetSelection(Selection);

     this->Style_Change_Operation = false;
}

Custom_TextCtrl * Custom_Notebook::Get_Selected_Text_Ctrl()
{
      return this->NoteBook_Page_Data[this->Current_Page_Record_Index].Text_Ctrl;
}

void Custom_Notebook::Document_Change(wxStyledTextEvent & event)
{
     event.Skip(true);

     int event_id = event.GetId();

     for(int i=0;i<20;i++){

         bool is_this_text_file = this->NoteBook_Page_Data[i].Is_This_Text_File;

         if(is_this_text_file)
         {
            if(this->NoteBook_Page_Data[i].Window_ID == event_id)
            {
               if(this->NoteBook_Page_Data[i].Document_Change_In_File_Open)
               {
                  this->NoteBook_Page_Data[i].Document_Change_In_File_Open = false;
               }
               else{
                      this->NoteBook_Page_Data[i].Document_Change_Condition = true;
               }

               break;
            }
         }
     }
}

void Custom_Notebook::Determine_Current_Page(wxAuiNotebookEvent & event)
{
     event.Skip(true);

     this->PaintNow(this);

     wxWindow * window_pointer = this->GetCurrentPage();

     int page_id = window_pointer->GetId();

     for(int i=0;i<20;i++){

         if(this->NoteBook_Page_Data[i].Window_ID == page_id){

            this->Current_Page_Record_Index = i;

            break;
         }
     }
}

void Custom_Notebook::NoteBook_Page_Closed(wxAuiNotebookEvent & event)
{
     event.Skip(true);

     event.ResumePropagation(2);

     wxWindow * window_pointer = this->GetCurrentPage();

     int closed_page_id = window_pointer->GetId();

     int index_number = 0;

     for(int i=0;i<20;i++){

         if(this->NoteBook_Page_Data[i].Window_ID == closed_page_id){

            index_number = i;

            break;
         }
     }

     bool is_this_text_file = this->NoteBook_Page_Data[index_number].Is_This_Text_File;

     if(is_this_text_file){

        bool Selected_File_Change_Condition = this->NoteBook_Page_Data[index_number].Document_Change_Condition;

        if(Selected_File_Change_Condition){

           wxString Message_Text = wxT(" File has changes\n Do you want to save!");

           wxMessageDialog * info_dial = new wxMessageDialog(NULL,Message_Text,wxT("Information"),wxYES_NO);

           if(info_dial->ShowModal() == wxID_YES){

              this->NoteBook_Page_Data[index_number].Text_Ctrl->SaveFile(this->NoteBook_Page_Data[index_number].File_Path,wxTEXT_TYPE_ANY);

              delete info_dial;
           }
        }
     }

     this->NoteBook_Page_Data[index_number].Is_Pointer_Free = true;

     this->NoteBook_Page_Data[index_number].File_Path = wxT("");

     this->NoteBook_Page_Data[index_number].Document_Change_Condition = false;

     this->NoteBook_Page_Data[index_number].Document_Change_In_File_Open = false;

     this->NoteBook_Page_Data[index_number].Window_ID = 0;

     this->NoteBook_Page_Data[index_number].Is_Page_Open = false;

     this->NoteBook_Page_Data[index_number].Intro_Page_Pointer = nullptr;

     this->NoteBook_Page_Data[index_number].Help_Page_Pointer = nullptr;

     this->NoteBook_Page_Data[index_number].Text_Ctrl = nullptr;

     this->NoteBook_Page_Data[index_number].Is_This_Text_File = false;
}

Custom_Notebook * Custom_Notebook::Get_NoteBook_Pointer()
{
    return this;
}

int Custom_Notebook::Get_Empty_Pointer_Index_Number()
{
    this->Empty_Pointer_Index_Number = 0;

    for(int i=0;i<20;i++){

        bool is_pointer_free = this->NoteBook_Page_Data[i].Is_Pointer_Free;

        if(is_pointer_free){

           this->Empty_Pointer_Index_Number = i;

           break;
        }
    }

    return this->Empty_Pointer_Index_Number;
}

void Custom_Notebook::Determine_File_Short_Name(wxString File_Long_Name)
{
     int Name_Size = 0;

     for(int k=File_Long_Name.length();k>0;k--){

         if(File_Long_Name[k] == '/'){

            break;
         }

         Name_Size++;
     }

     this->File_Short_Name = wxT(" ");

     for(int k=File_Long_Name.length() - Name_Size +1; k<File_Long_Name.length();k++){

         this->File_Short_Name = this->File_Short_Name + File_Long_Name[k];
     }

     this->File_Short_Name = this->File_Short_Name + wxT(" ");
}

bool Custom_Notebook::Is_File_Open(wxString File_Path)
{
     this->File_Open_Status = false;

     for(int i=0;i<20;i++){

         if(File_Path != wxT("")){

            if(File_Path == this->NoteBook_Page_Data[i].File_Path){

               this->File_Open_Status = true;

               break;
            }
         }
     }

     return this->File_Open_Status;
}

wxString Custom_Notebook::Get_Selected_Text_Ctrl_File_Path()
{
         return this->NoteBook_Page_Data[this->Current_Page_Record_Index].File_Path;
}

void Custom_Notebook::Select_File(wxString File_Path)
{
     int File_Index_Number = 0;

     for(int i=0;i<20;i++){

        if(this->NoteBook_Page_Data[i].File_Path == File_Path){

           File_Index_Number = i;
        }
     }

     int Page_Number = 0;

     size_t page_count = this->GetPageCount();

     for(int i=0;i<page_count;i++){

         wxWindow * page_window = this->GetPage(i);

         int page_id = page_window->GetId();

         if(this->NoteBook_Page_Data[File_Index_Number].Window_ID == page_id){

             Page_Number = i;
         }
     }

     this->SetSelection(Page_Number);
}

void Custom_Notebook::Selection_Changing(wxAuiNotebookEvent & event)
{
     if(this->Style_Change_Operation){

         event.Veto();
     }
     else{
            event.Skip(true);
     }
}

bool Custom_Notebook::Get_Intro_Page_Close_Condition(){

     return  this->NoteBook_Page_Data[0].Is_Page_Open;
}

int Custom_Notebook::Get_Intro_Page_Id(){

    return this->Introduction_Page_Id;
}

bool Custom_Notebook::Get_Style_Change_Condition() const
{
     return this->Style_Change_Operation;
}

int Custom_Notebook::Get_Current_Page_Index() const
{
    return this->Current_Page_Record_Index;
}

bool Custom_Notebook::Is_Current_Page_Text_File() const
{
     return this->NoteBook_Page_Data[this->Get_Current_Page_Index()].Is_This_Text_File;
}


wxString Custom_Notebook::Get_Notebook_Page_File_Path(int index)
{
    return this->NoteBook_Page_Data[index].File_Path;
}
