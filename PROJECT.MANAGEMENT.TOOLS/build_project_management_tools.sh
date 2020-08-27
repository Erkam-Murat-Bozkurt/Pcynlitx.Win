
LIBRARY_BASE_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY
HEADER_FILES_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
LIBRARY_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY
OBJECT_FILES_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY/OBJECT.FILES


if [ ! -e "$LIBRARY_BASE_DIRECTORY" ]
then
  mkdir $LIBRARY_BASE_DIRECTORY
fi

if [ ! -e "$HEADER_FILES_DIRECTORY" ]
then
  mkdir $HEADER_FILES_DIRECTORY
fi

if [ ! -e "$LIBRARY_DIRECTORY" ]
then
  mkdir $LIBRARY_DIRECTORY
fi

if [ ! -e "$OBJECT_FILES_DIRECTORY" ]
then
  mkdir $OBJECT_FILES_DIRECTORY
fi

cd ~/PCYNLITX.PROJECT/PACKAGE.BUILD.TOOLS

bash Build_Package_Management_Tools.sh

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS

./Build_GUI_Make_File_Header

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS/Auto_Class_Compiler

bash Build_Class_Compiler.sh

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS/Test_Program_Builder

bash Build_Test_Program_Builder.sh

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS

sudo cp Exe_Builder /usr/bin

sudo chmod 0777 /usr/bin/Exe_Builder

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS/Library_Updater

bash Build_Library_Updater.sh

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS/Make_File_Builder

bash Build_Make_File_Builder.sh

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS/Modification_Control_Script_Builder

bash Build_Modification_Control_Script_Builder.sh

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS

sudo cp Setup_Project /usr/bin

sudo chmod 0777 /usr/bin/Setup_Project

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS

sudo cp Setup_GUI_Project /usr/bin

sudo chmod 0777 /usr/bin/Setup_GUI_Project

cd ~/PCYNLITX.PROJECT

bash Run.Make.File.Builder.sh

bash Update_Project.sh

cd ~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS

bash Set_Ignoring_Files.sh

./Build_GUI_Make_File_Header
