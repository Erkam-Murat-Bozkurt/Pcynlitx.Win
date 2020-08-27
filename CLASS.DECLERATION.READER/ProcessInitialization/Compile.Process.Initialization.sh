
ClassSyntaxControlPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization/ClassSyntaxControl

ClassNameReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization/ClassNameReader

MethodInitializerPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization/MethodInitializer

FindSetPointsPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization/FindSetPoints

MethodProcessorPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization/MethodProcessor

SyntaxControllerPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization/SyntaxController

ListFileOrganizerPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization/ListFileOrganizer

MethodReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER//ProcessInitialization/MethodReader

ProcessInitializationPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization

Included_Header_File_Names_Reader_PATH=~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS/Included_Header_File_Names_Reader

printf "\n CLASS READER INITIALIZATION LIBRARY CONTRUCTION STARTED \n\n"

cd $ClassSyntaxControlPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # ClassSyntaxControl class has been updated \n\n"

cd $ClassNameReaderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # ClassNameReader class has been updated \n\n"

cd $MethodInitializerPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # MethodInitializer class has been updated \n\n"

cd $FindSetPointsPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # FindSetPoints class has been updated \n\n"

cd $MethodProcessorPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # MethodProcessor class has been updated \n\n"

cd $SyntaxControllerPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # SyntaxController class has been updated \n\n"

cd $ListFileOrganizerPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # ListFileOrganizer class has been updated \n\n"

cd $MethodReaderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # MethodReader class has been updated \n\n"

printf "   # Sub-Project has been compiled \n\n"

cd $Included_Header_File_Names_Reader_PATH

bash Included_Header_File_Names_Reader_Updater.sh
