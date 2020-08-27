
Compiler_Descriptor_File_Constructor_PATH=~/PCYNLITX.PROJECT/EXECUTABLE.FILE.BUILDER/Compiler_Descriptor_File_Constructor

MT_Project_Builder_PATH=~/PCYNLITX.PROJECT/EXECUTABLE.FILE.BUILDER/MT_Project_Builder


printf "\n  EXECUTABLE FILE BULDER COMPILE PROCESS HAS BEEN STARTED \n\n"


cd $Compiler_Descriptor_File_Constructor_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Compiler_Descriptor_File_Constructor class has been compiled \n\n"


cd $MT_Project_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   #  MT_Project_Builder class has been compiled \n\n"


printf "   #  Sub-Project has been compiled \n\n"
