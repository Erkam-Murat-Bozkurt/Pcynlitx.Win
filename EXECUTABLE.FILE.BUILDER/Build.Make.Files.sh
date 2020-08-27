
Compiler_Descriptor_File_Constructor_PATH=~/PCYNLITX.PROJECT/EXECUTABLE.FILE.BUILDER/Compiler_Descriptor_File_Constructor

MT_Project_Builder_PATH=~/PCYNLITX.PROJECT/EXECUTABLE.FILE.BUILDER/MT_Project_Builder

printf "\n \e[3;37;42m EXECUTABLE FILE BULDER MAKE FILE CONSTRUCTION HAS BEEN STARTED \e[0m \n\n"

cd $Compiler_Descriptor_File_Constructor_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for Compiler_Descriptor_File_Constructor class .. \e[0m\n\n"


cd $MT_Project_Builder_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for MT_Project_Builder class has been compiled .. \e[0m\n\n"

printf "   # \e[1;7;36m The make files for the Sub-Project has been derived .. \e[0m\n\n"
