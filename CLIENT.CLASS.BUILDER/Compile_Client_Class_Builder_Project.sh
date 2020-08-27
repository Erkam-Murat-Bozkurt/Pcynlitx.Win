

ClassRebuilder_InitializerPATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER/ClassRebuilder_Initializer

ClassRebuilder_Data_CollectorPATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER/ClassRebuilder_Data_Collector

HeaderRebuilderPATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER/HeaderRebuilder

ClassRebuilderPATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER/ClassRebuilder


printf "\n CLIENT.CLASS.BUILDER COMPILE PROCESS HAS BEEN STARTED \n\n"

cd $ClassRebuilder_InitializerPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # ClassRebuilder_Initializer class has been compiled \n\n"


cd $ClassRebuilder_Data_CollectorPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # ClassRebuilder_Data_Collector class has been compiled \n\n"


cd $HeaderRebuilderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # HeaderRebuilder class has been compiled \n\n"


cd $ClassRebuilderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # ClassRebuilder class has been compiled \n\n"


printf "   # Sub-Project has been compiled \n\n"
