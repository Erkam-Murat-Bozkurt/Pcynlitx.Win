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


#include "Menu_Bar_Options.h"

Menu_Bar_Options::Menu_Bar_Options(){

  this->File_Menu = new wxMenu();

  this->Launch_Menu = new wxMenu();

  this->Help_Menu = new wxMenu();

  this->View_Menu = new wxMenu();

  this->Edit = new wxMenu();

  this->Library_Description_Menu = new wxMenu();

  this->Compiler_Description_Menu = new wxMenu();


  this->View_Menu->Append(ID_SELECT_PROJECT_FOLDER,"&Open Directory List"," ",wxITEM_NORMAL);

  this->View_Menu->Append(ID_INCREASE_FONT_SIZE,"&Increase Font Size"," ",wxITEM_NORMAL);

  this->View_Menu->Append(ID_DECREASE_FONT_SIZE,"&Decrease Font Size"," ",wxITEM_NORMAL);

  this->View_Menu->Append(ID_FONT_DIALOG,"&Change Font"," ",wxITEM_NORMAL);

  this->View_Menu->Append(ID_USE_DEFAULT_FONT,"&Use Default Font"," ",wxITEM_NORMAL);

  this->View_Menu->Append(ID_CLEAR_STYLE,"&Clear Styling"," ",wxITEM_NORMAL);

  this->View_Menu->Append(ID_RELOAD_STYLE,"&Reload Default Style"," ",wxITEM_NORMAL);

  this->View_Menu->Append(ID_BOLD_STYLE,"&Use Bold Styling"," ",wxITEM_NORMAL);


  this->File_Menu->Append(wxID_OPEN,"&Open"," ",wxITEM_NORMAL);

  this->File_Menu->Append(wxID_EXIT,"&Exit"," ",wxITEM_NORMAL);

  this->File_Menu->Append(ID_NEW_FILE,"&New file as"," ",wxITEM_NORMAL);

  this->File_Menu->Append(ID_FILE_SAVE,"&Save"," ",wxITEM_NORMAL);

  this->File_Menu->Append(ID_SAVE_AS,"&Save as"," ",wxITEM_NORMAL);


  this->Edit->Append(ID_UNDO_CHANGES,"&Undo   Ctrl+Z"," ",wxITEM_NORMAL);

  this->Edit->Append(ID_REDO_CHANGES,"&Redo   Ctrl+Y"," ",wxITEM_NORMAL);

  this->Edit->Append(ID_CLEAR_TEXT,"&Clear Text"," ",wxITEM_NORMAL);

  this->Edit->Append(ID_SET_CURSOR_TYPE_DEFAULT,"&Use Default Cursor"," ",wxITEM_NORMAL);

  this->Edit->Append(ID_CHANGE_CURSOR_TYPE,"&Use System Cursor"," ",wxITEM_NORMAL);

  this->Edit->Append(ID_SET_CARET_LINE_VISIBLE,"&Set Caret Line Visible"," ",wxITEM_NORMAL);

  this->Edit->Append(ID_SET_CARET_LINE_INVISIBLE,"&Set Caret Line Invisible"," ",wxITEM_NORMAL);

  this->Edit->Append(ID_USE_BLOCK_CARET,"&Use Block Caret"," ",wxITEM_NORMAL);

  this->Edit->Append(ID_USE_DEFAULT_CARET,"&Use Default Caret"," ",wxITEM_NORMAL);


  this->Launch_Menu->Append(ID_RUN_EXECUTABLE,"&Build Library"," ",wxITEM_NORMAL);

  this->Launch_Menu->Append(ID_RUN_EXECUTABLE_BINARY_BUILDER,"&Build Binary"," ",wxITEM_NORMAL);

  this->Launch_Menu->Append(ID_OPEN_TERMINAL,"&Open Terminal"," ",wxITEM_NORMAL);

  this->Launch_Menu->Append(ID_SELECT_PROJECT_FILE,"&Select Descriptor File"," ",wxITEM_NORMAL);

  this->Launch_Menu->Append(ID_OPEN_EMPTY_PROJECT_FILE,"&New Empty Descriptor File"," ",wxITEM_NORMAL);

  this->Launch_Menu->Append(ID_SHOW_PROJECT_FILE,"&Show Descriptor File"," ",wxITEM_NORMAL);

  this->Launch_Menu->Append(ID_SHOW_PROJECT_DESCRIPTOR_FILE_LOCATION,"&Show Descriptor File Location"," ",wxITEM_NORMAL);


  this->Launch_Menu->Append(ID_SHOW_PROJECT_DIRECTORY_LOCATION,"&Show Construction Point"," ",wxITEM_NORMAL);

  this->Launch_Menu->Append(ID_RE_OPEN_PROJECT_DIRECTORY,"&Project Directory Tree View"," ",wxITEM_NORMAL);

  this->Launch_Menu->Append(ID_SHOW_DESCRIPTIONS,"&Print Your Descriptions"," ",wxITEM_NORMAL);


  this->Help_Menu->Append(ID_OPEN_PROJECT_WEB_PAGE,"&Project Documentation"," ",wxITEM_NORMAL);

  this->Help_Menu->Append(ID_OPEN_INTROPAGE,"&Intro Page"," ",wxITEM_NORMAL);

  this->Help_Menu->Append(ID_SHOW_AUTOR_INFO,"&Developer"," ",wxITEM_NORMAL);

  this->Help_Menu->Append(wxID_ABOUT,"&Version 1.0"," ",wxITEM_NORMAL);


  this->Library_Description_Menu->Append(wxID_NONE,                    "&# MAIN DESCRIPTIONS"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_CONSTRUCTION_POINT,  "&    Enter Construction Point"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_THREAD_FUNCTION_NAME,"&    Enter Thread Function Name"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_THREAD_NUMBER,       "&    Enter Thread Number"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(wxID_NONE,"&                        "," ",wxITEM_SEPARATOR);

  this->Library_Description_Menu->Append(wxID_NONE,                    "&# INTER-THREAD CLASS DESCRIPTIONS"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_ITC_HEADER_FILE_NAME,"&    Enter Class Header File"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_SOURCE_FILE_NAME,    "&    Enter Class Source File"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(wxID_NONE,"&                        "," ",wxITEM_SEPARATOR);

  this->Library_Description_Menu->Append(wxID_NONE,                    "&# SMART POINTER DESCRIPTIONS"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_ITD_DATA_NAME,       "&    [ Basic C++ Types ] - Enter Type"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_ITD_HEADER_FILE_NAME,"&    Enter Class Header File"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_SOURCE_FILE_NAME,    "&    Enter Class Source File"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(wxID_NONE,"&                        "," ",wxITEM_SEPARATOR);

  this->Library_Description_Menu->Append(wxID_NONE,                    "&# LIBRARIES FOR LINKING"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_LIBRARY_NAME,        "&    Enter Library For Linking"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(wxID_NONE,"&                        "," ",wxITEM_SEPARATOR);

  this->Library_Description_Menu->Append(wxID_NONE,                    "&# NAMESPACE"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_INPUT_NAMESPACE,           "&    Enter Namespace Information"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(wxID_NONE,                    "&# OPENMP SELECTION"," ",wxITEM_NORMAL);

  this->Library_Description_Menu->Append(ID_OPENMP_SUPPORT,           "&    Is OpenMp support necessary?"," ",wxITEM_NORMAL);



  this->Compiler_Description_Menu->Append(ID_INPUT_HEADER_FILE,     "&Enter Header File"," ",wxITEM_NORMAL);

  this->Compiler_Description_Menu->Append(ID_INPUT_SOURCE_FILE_NAME,"&Enter Source File"," ",wxITEM_NORMAL);

  this->Compiler_Description_Menu->Append(ID_INPUT_EXE_FILE_NAME,   "&Enter Executable File Name"," ",wxITEM_NORMAL);

  this->Compiler_Description_Menu->Append(ID_INPUT_LIBRARY_NAME,    "&Enter Library For Linking"," ",wxITEM_NORMAL);


  this->Menu_Bar = new wxMenuBar();

  this->Menu_Bar->Append(this->File_Menu, wxT("&File"));

  this->Menu_Bar->Append(this->Launch_Menu,wxT("&Meta Programing"));

  this->Menu_Bar->Append(this->Help_Menu,wxT("&Help"));

  this->Menu_Bar->Append(this->Edit,wxT("&Edit"));

  this->Menu_Bar->Append(this->View_Menu,wxT("&View"));

  this->Menu_Bar->Append(this->Library_Description_Menu,wxT("&Meta Libray Descriptions"));

  this->Menu_Bar->Append(this->Compiler_Description_Menu,wxT("&Compiler Descriptions"));
}

Menu_Bar_Options::~Menu_Bar_Options(){

        delete this->Library_Description_Menu;

        delete this->Compiler_Description_Menu;

        delete this->File_Menu;

        delete this->Launch_Menu;

        delete this->Help_Menu;

        delete this->View_Menu;

        delete this->Edit;

        delete this->Menu_Bar;
}

wxMenuBar * Menu_Bar_Options::Get_MenuBar(){

    return this->Menu_Bar;
}
