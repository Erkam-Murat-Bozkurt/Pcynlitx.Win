
Home_Directory=~;

g++ -std=c++14 -o Modification_Control_Script_Builder \
     -I$Home_Directory/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations \
     -L$Home_Directory/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations \
     Modification_Control_Script_Builder_Main_File.cpp \
     Modification_Control_Script_Builder.cpp \
     ~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations/Cpp_FileOperations.cpp \
     Modification_Control_Script_Builder.h \
     -include ~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations/Cpp_FileOperations.h

printf "\n\n  Modification_Control_Script_Builder is ready :-)"

printf "\n\n  The Executing command: \"sudo cp Modification_Control_Script_Builder /usr/bin\""

printf "\n\n"

sudo mv Modification_Control_Script_Builder /usr/bin
