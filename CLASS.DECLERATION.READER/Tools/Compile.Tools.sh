
CFileOperationsPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/CFileOperations

Cpp_FileOperationsPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations

DirectoryOperationsPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/DirectoryOperations

CharOperatorPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/CharOperator

IntToCharTranslaterPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/IntToCharTranslater

StringOperatorPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/StringOperator

Compiler_Descriptor_File_Reader_PATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Compiler_Descriptor_File_Reader

CompilerPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Compiler

HeaderFileBuilderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/HeaderFileBuilder

Custom_System_Interface_PATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools/Custom_System_Interface

ToolsPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools

printf "\n  PROGRAMMING TOOLS LIBRARY CONTRUCTION STARTED  \n\n"

cd $CFileOperationsPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # CFileOperations class has been compiled \n\n"


cd $Cpp_FileOperationsPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Cpp_FileOperations class has been compiled .. \e[0m\n\n"


cd $DirectoryOperationsPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # DirectoryOperations class has been compiled \n\n"


cd $CharOperatorPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # CharOperator class has been compiled \n\n"


cd $IntToCharTranslaterPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # IntToCharTranslater class has been compiled \n\n"


cd $StringOperatorPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # StringOperator class has been compiled \n\n"


cd $Compiler_Descriptor_File_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Compiler_Descriptor_File_Reader has been compiled \n\n"


cd $CompilerPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Compiler class has been compiled \n\n"


cd $HeaderFileBuilderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # HeaderFileBuilder class has been compiled \n\n"


cd $Custom_System_Interface_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Custom_System_Interface class has been compiled \n\n"

printf "   # Sub-Project has been compiled \n\n"
