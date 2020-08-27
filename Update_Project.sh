
cd ~/PCYNLITX.PROJECT

bash ReFactorProjectLibrary.sh

printf "\n   #\e[1;34m Project GUI compiling process has been started .. \e[0m\n\n"

printf "\n   #\e[1;34m In the case of the change on the files GUI.DEVELOPMENT/GUI.Header \e[0m\n\n"

printf "\n   #\e[1;34m Please compile GUI.DEVELOPMENT Sub-project again \e[0m\n\n"

cd ~/PCYNLITX.PROJECT/GUI.DEVELOPMENT

bash Run_Project_Binary_Files_Compiler.sh

bash Run_Project_File_Updater.sh

bash Run_GUI_Compiler.sh

printf "\n   #\e[1;34m Project GUI compiling process has been complated .. \e[0m\n\n"
