
MemberFunctionReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/DataBaseManagement/MemberFunctionReader

MetaDataTranslaterPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/DataBaseManagement/MetaDataTranslater

printf "\n DATABASE MANAGEMENT LIBRARY CONTRUCTION STARTED \n\n"

cd $MemberFunctionReaderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # MemberFunctionReader class has been updated \n\n"

cd $MetaDataTranslaterPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # MetaDataTranslater class has been updated \n\n"

printf "   # Sub-Project has been compiled \n\n"
