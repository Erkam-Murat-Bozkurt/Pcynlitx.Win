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

#include "ToolBar_Initializer.h"

ToolBar_Initializer::ToolBar_Initializer(){

}

ToolBar_Initializer::~ToolBar_Initializer(){

      delete this->close;

      delete this->build_library;

      delete this->build_executable;

      delete this->Select_Project_File;

      delete this->Empty_Project_File;

      delete this->Show_Help_Document;

      delete this->open_terminal;

      delete this->file_save;

      delete this->open_tree_view;

      delete this->print_descriptions;

      delete this->WinDc;

      this->toolBar->Clear();

      this->toolBar->ClearTools();

      this->toolBar->Destroy();
}

void ToolBar_Initializer::Initialize_ToolBar(wxFrame * Frame_Pointer, wxAuiDockArt * Dock_Art_Pointer, wxAuiManager * Interface_Manager){

     this->close = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/close.png"), wxBITMAP_TYPE_ANY);

     this->build_library = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/archive.png"),wxBITMAP_TYPE_ANY);

     this->build_executable = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/build_executable.png"),wxBITMAP_TYPE_ANY);

     this->Select_Project_File = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/select_project_file.png"),wxBITMAP_TYPE_ANY);

     this->Empty_Project_File = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/empty_project_file.png"),wxBITMAP_TYPE_ANY);

     this->Show_Help_Document = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/help_documents.png"),wxBITMAP_TYPE_ANY);

     this->open_terminal = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/open_terminal.png"),wxBITMAP_TYPE_ANY);

     this->file_save = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/file_save.png"),wxBITMAP_TYPE_ANY);

     this->open_tree_view = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/open_tree_view.png"),wxBITMAP_TYPE_ANY);

     this->print_descriptions = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/print_descriptions.png"),wxBITMAP_TYPE_ANY);

     this->toolBar = new wxAuiToolBar(Frame_Pointer,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxAUI_TB_PLAIN_BACKGROUND);

     this->Art_Pointer = new MyAuiTBArt();

     this->toolBar->SetBackgroundColour(wxColour(160,160,160,0xff));

     this->toolBar->SetArtProvider(this->Art_Pointer);

     wxAuiPaneInfo ToolBar_Widget_Shape;

     ToolBar_Widget_Shape.CloseButton(false);

     ToolBar_Widget_Shape.LeftDockable(true);

     ToolBar_Widget_Shape.RightDockable(false);

     ToolBar_Widget_Shape.BottomDockable(false);

     ToolBar_Widget_Shape.TopDockable(false);

     ToolBar_Widget_Shape.Movable(false);

     ToolBar_Widget_Shape.Floatable(false);

     ToolBar_Widget_Shape.Left();

     ToolBar_Widget_Shape.Dock();

     ToolBar_Widget_Shape.PaneBorder(true);

     ToolBar_Widget_Shape.DockFixed(true);

     ToolBar_Widget_Shape.Show(true);

     this->WinDc = new wxWindowDC(this->toolBar);

     this->Art_Pointer->DrawPlainBackground(*this->WinDc,this->toolBar,this->toolBar->GetRect());

     this->toolBar->AddTool(wxID_EXIT, wxT(""),*this->close,wxT(""));

     this->toolBar->AddTool(ID_RUN_EXECUTABLE,wxT(""),*this->build_library,wxT(""));

     this->toolBar->AddTool(ID_RUN_EXECUTABLE_BINARY_BUILDER,wxT(""),*this->build_executable,wxT(""));

     this->toolBar->AddTool(ID_OPEN_TREE_WIEW,wxT(""),*this->open_tree_view,wxT(""));

     this->toolBar->AddTool(ID_SELECT_PROJECT_FILE,wxT(""),*this->Select_Project_File,wxT(""));

     this->toolBar->AddTool(ID_OPEN_EMPTY_PROJECT_FILE,wxT(""),*this->Empty_Project_File,wxT(""));

     this->toolBar->AddTool(ID_OPEN_TERMINAL,wxT(""),*this->open_terminal,wxT(""));

     this->toolBar->AddTool(ID_FILE_SAVE,wxT(""),*this->file_save,wxT(""));

     this->toolBar->AddTool(ID_SHOW_DESCRIPTIONS,wxT(""),*this->print_descriptions,wxT(""));

     this->toolBar->SetMargins(-1,-1,3,3);

     this->toolBar->SetOverflowVisible(false);

     this->toolBar->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

     this->toolBar->SetThemeEnabled(false);

     this->toolBar->RefreshRect(this->toolBar->GetRect(),true);

     this->toolBar->Realize();

     this->toolBar->Show(true);

     Interface_Manager->AddPane(this->toolBar,ToolBar_Widget_Shape);
}

wxAuiToolBar * ToolBar_Initializer::Get_ToolBar_Pointer(){

     return this->toolBar;
}
