
Home_Directory=~;

g++ -std=c++14 -o Make_File_Builder \
     -I$Home_Directory/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations \
     -L$Home_Directory/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations \
      Make_File_Builder_Main_File.cpp Make_File_Builder.cpp \
     ~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations/Cpp_FileOperations.cpp \
      Make_File_Builder.h \
     -include ~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations/Cpp_FileOperations.h

printf "\n\n  Make_File_Builder is ready :-)"

printf "\n\n  The Executing command: \"sudo cp Make_File_Builder /usr/bin\""

printf "\n\n"

sudo mv Make_File_Builder /usr/bin
