
ClassRebuilder_InitializerPATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER/ClassRebuilder_Initializer

ClassRebuilder_Data_CollectorPATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER/ClassRebuilder_Data_Collector

HeaderRebuilderPATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER/HeaderRebuilder

ClassRebuilderPATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER/ClassRebuilder

printf "\n \e[3;37;42m CLIENT CLASS BUILDER LIBRARY MAKE FILE CONTRUCTION STARTED \e[0m \n\n"

cd $ClassRebuilder_InitializerPATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for ClassRebuilder_Initializer class has been compiled .. \e[0m\n\n"


cd $ClassRebuilder_Data_CollectorPATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for ClassRebuilder_Data_Collector class .. \e[0m\n\n"


cd $HeaderRebuilderPATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for HeaderRebuilder class .. \e[0m\n\n"


cd $ClassRebuilderPATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for ClassRebuilder class has been compiled .. \e[0m\n\n"

printf "   # \e[1;7;36m The make files for the Sub-Project has been derived .. \e[0m\n\n"
