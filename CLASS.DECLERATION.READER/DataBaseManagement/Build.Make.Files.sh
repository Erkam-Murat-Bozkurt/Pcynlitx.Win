
MemberFunctionReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/DataBaseManagement/MemberFunctionReader

MetaDataTranslaterPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/DataBaseManagement/MetaDataTranslater

printf "\n \e[3;37;42m DATABASE MANAGEMENT LIBRARY MAKE FILE CONTRUCTION STARTED \e[0m \n\n"

cd $MemberFunctionReaderPATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for MemberFunctionReader class .. \e[0m\n\n"


cd $MetaDataTranslaterPATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for MetaDataTranslater class .. \e[0m\n\n"

printf "   # \e[1;7;36m The make files for the Sub-Project has been derived .. \e[0m\n\n"
