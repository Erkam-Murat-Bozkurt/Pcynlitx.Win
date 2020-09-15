
$GUI_Headers_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\GUI.Headers"

$Intro_Page_Loader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Intro_Page_Loader"

$Help_Page_Loader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Help_Page_Loader"

$Custom_Tree_View_Panel_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Custom_Tree_View_Panel"

$Custom_wxPanel_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Custom_wxPanel"

$Custom_wxDataViewTreeCtrl_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Custom_wxDataViewTreeCtrl"

$Custom_Close_Button_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Custom_Close_Button"

$Custom_Window_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Custom_Window"

$Project_Folder_Lister_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Project_Folder_Lister"

$Project_File_Selection_Dialog_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Project_File_Selection_Dialog"

$ToolBar_Initializer_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\ToolBar_Initializer"

$Menu_Bar_Options_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Menu_Bar_Options"

$Style_Loader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Style_Loader"

$Custom_Notebook_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Custom_Notebook"

$Custom_TextCtrl_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Custom_TextCtrl"

$Custom_TabArt_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Custom_TabArt"

$wx_Description_Record_Tools_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\wx_Description_Record_Tools"

$keyboard_event_controler_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\keyboard_event_controler"

$Process_Execution_Controller_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Process_Execution_Controller"

$MainFrame_PATH="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\MainFrame"

$Custom_DockArt="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\GUI.Headers\Custom_DockArt.h"

$Event_ID_Numbers="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\GUI.Headers\Event_ID_Numbers.h"

$Event_Table_Header="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\GUI.Headers\Event_Table_Header.h"

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

Write-Output ""

Write-Output " GUI COMPILE PROCESS HAS BEEN STARTED"

Write-Output ""


cp $Custom_DockArt $Project_Headers_Files

cp $Event_ID_Numbers $Project_Headers_Files

cp $Event_Table_Header $Project_Headers_Files



cd $Intro_Page_Loader_PATH

Class_Compiler.exe

Write-Output "   # Intro_Page_Loader class has been compiled \n\n"


cd $Help_Page_Loader_PATH

Class_Compiler.exe

Write-Output "   # Help_Page_Loader class has been compiled \n\n"


cd $Custom_wxDataViewTreeCtrl_PATH

Class_Compiler.exe

Write-Output "   # Custom_wxDataViewTreeCtrl class has been compiled \n\n"


cd $Project_Folder_Lister_PATH

Class_Compiler.exe

Write-Output "   # Project_Folder_Lister class has been compiled \n\n"


cd $Custom_Window_PATH

Class_Compiler.exe

Write-Output "   # Custom_Window class has been compiled \n\n"



cd $Custom_Close_Button_PATH

Class_Compiler.exe

Write-Output "   # Custom_Close_Button class has been compiled \n\n"


cd $Custom_Tree_View_Panel_PATH

Class_Compiler.exe

Write-Output "   # Custom_Tree_View_Panel class has been compiled \n\n"


cd $Custom_wxPanel_PATH

Class_Compiler.exe

Write-Output "   # Custom_wxPanel class has been compiled \n\n"



cd $Project_File_Selection_Dialog_PATH

Class_Compiler.exe

Write-Output "   # Project_File_Selection_Dialog class has been compiled \n\n"


cd $ToolBar_Initializer_PATH

Class_Compiler.exe

Write-Output "   # ToolBar_Initializer class has been compiled \n\n"



cd $Menu_Bar_Options_PATH

Class_Compiler.exe

Write-Output "   # Menu_Bar_Options class has been compiled \n\n"


cd $Style_Loader_PATH

Class_Compiler.exe

Write-Output "   # Style_Loader class has been compiled \n\n"

cd $Custom_TextCtrl_PATH

Class_Compiler.exe

Write-Output "   # Custom_TextCtrl class has been compiled \n\n"


cd $Custom_TabArt_PATH

Class_Compiler.exe

Write-Output "   # Custom_TextCtrl class has been compiled \n\n"


cd $Custom_Notebook_PATH

Class_Compiler.exe

Write-Output "   # Custom_NoteBook class has been compiled \n\n"


cd $wx_Description_Record_Tools_PATH

Class_Compiler.exe

Write-Output "   # wx_Description_Record_Tools class has been compiled \n\n"


cd $keyboard_event_controler_PATH

Class_Compiler.exe

Write-Output "   # keyboard_event_controler class has been compiled \n\n"


cd $Process_Execution_Controller_PATH

Class_Compiler.exe

Write-Output "   # Process_Execution_Controller class has been compiled \n\n"


cd $MainFrame_PATH

Class_Compiler.exe

Write-Output "   # MainFrame class has been compiled \n\n"

Write-Output "   # PROJECT library libmptoos.a has been updated \n\n"
