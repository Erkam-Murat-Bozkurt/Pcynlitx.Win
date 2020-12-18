
Write-Output ""

Write-Output "   # GUI icon files will be updated"

Write-Output ""


$INTRO_FILE_LOCATION="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Intro_Page_Loader\Intro_Page_Design"

$PNG_ICONS_LOCATION="D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Icon_Designs\Png_Files"

cd $INTRO_FILE_LOCATION

cp .\Intro_File.png D:\Pcynlitx

cd $PNG_ICONS_LOCATION

cp .\folder.png D:\Pcynlitx\icons

cp .\file.png D:\Pcynlitx\icons

cp .\file_save.png D:\Pcynlitx\icons

cp .\build_executable.png D:\Pcynlitx\icons

cp .\empty_project_file.png D:\Pcynlitx\icons

cp .\select_project_file.png D:\Pcynlitx\icons

cp .\help_documents.png D:\Pcynlitx\icons

cp .\open_terminal.png D:\Pcynlitx\icons

cp .\close.png D:\Pcynlitx\icons

cp .\close_tab.png D:\Pcynlitx\icons

cp .\pane_close_icon.png D:\Pcynlitx\icons

cp .\open_tree_view.png D:\Pcynlitx\icons

cp .\archive.png D:\Pcynlitx\icons

cp .\print_descriptions.png D:\Pcynlitx\icons

cp .\pcynlitx.png D:\Pcynlitx\icons


Write-Output "   # Pcynlitx icon files has been updated "

Write-Output ""
