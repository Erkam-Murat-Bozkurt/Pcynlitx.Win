
include INCLUDE_PATHS_FOR_GUI_MAKE_FILE

wxWidgets_Include_Directories=$(shell echo `wx-config --cxxflags`)
wxWidgets_Libraries=$(shell echo `wx-config --libs std stc core base aui`)
Project_Library=-lmptools

Pcynlitx : wxLauncher.cpp MainFrame.o Process_Execution_Controller.o keyboard_event_controler.o \
							Custom_Notebook.o Custom_TabArt.o Custom_Tree_View_Panel.o Custom_Close_Button.o \
							wx_Description_Record_Tools.o \
							Menu_Bar_Options.o ToolBar_Initializer.o Project_File_Selection_Dialog.o \
	            Project_Folder_Lister.o Style_Loader.o ClassSyntaxControl.o ClassNameReader.o \
							Intro_Page_Loader.o Help_Page_Loader.o Custom_TextCtrl.o Custom_Window.o Custom_wxPanel.o  \
							Custom_wxDataViewTreeCtrl.o MainFrame.h Event_ID_Numbers.h  \
	            Process_Execution_Controller.h keyboard_event_controler.h  \
	            Custom_Tree_View_Panel.h Custom_Close_Button.h Intro_Page_Loader.h Help_Page_Loader.h Custom_TextCtrl.h \
							wx_Description_Record_Tools.h Menu_Bar_Options.h ToolBar_Initializer.h \
							Project_File_Selection_Dialog.h Custom_Notebook.h Custom_TabArt.h \
							Project_Folder_Lister.h Style_Loader.h Custom_DockArt.h \
              Custom_wxPanel.h Custom_wxDataViewTreeCtrl.h Custom_Window.h
	g++ -std=c++14 -o Pcynlitx $(wxWidgets_Include_Directories) -I$(ID) \
	     -L$(LD) wxLauncher.cpp $(OD)/MainFrame.o $(OD)/Process_Execution_Controller.o \
			   $(OD)/Custom_Tree_View_Panel.o $(OD)/Custom_Close_Button.o \
				 $(OD)/Style_Loader.o $(OD)/wx_Description_Record_Tools.o \
			   $(OD)/keyboard_event_controler.o $(OD)/Custom_Notebook.o $(OD)/Custom_TabArt.o $(OD)/Menu_Bar_Options.o \
			   $(OD)/ToolBar_Initializer.o $(OD)/Project_File_Selection_Dialog.o \
				 $(OD)/Project_Folder_Lister.o $(OD)/Intro_Page_Loader.o $(OD)/Help_Page_Loader.o $(OD)/Custom_TextCtrl.o \
				 $(OD)/Custom_Window.o $(OD)/Custom_wxPanel.o $(OD)/Custom_wxDataViewTreeCtrl.o  \
 			   -include MainFrame.h -include Process_Execution_Controller.h  \
       -include keyboard_event_controler.h -include Custom_Notebook.h \
			 -include Custom_Tree_View_Panel.h -include Custom_Close_Button.h \
			 -include Style_Loader.h -include wx_Description_Record_Tools.h \
	     -include Menu_Bar_Options.h -include ToolBar_Initializer.h \
	     -include Project_File_Selection_Dialog.h -include Project_Folder_Lister.h \
	     -include Custom_TabArt.h -include Custom_TextCtrl.h -include Custom_DockArt.h  \
			 -include Intro_Page_Loader.h -include Help_Page_Loader.h -include Custom_Window.h -include Custom_wxPanel.h \
			 -include Event_ID_Numbers.h -include Custom_wxDataViewTreeCtrl.h \
			  $(wxWidgets_Libraries) $(Project_Library)
