

MethodListInterpreterPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/MethodListInterpreter

MethodListReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/MethodListReader

ParenthesReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/ParenthesReader

MethodReceiverPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/MethodReceiver

ReturnTypeReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/ReturnTypeReader

NameReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/NameReader

ParameterReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/ParameterReader

MethodInterpreterPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/MethodInterpreter

DataBaseBuilderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader/DataBaseBuilder

ClassReaderProjectPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader

printf "\n CLASS READER LIBRARY CONTRUCTION STARTED \n\n"

cd $MethodListInterpreterPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # MethodListInterpreter class has been compiled \n\n"

cd $MethodListReaderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # MethodListReader class has been compiled \n\n"

cd $ParenthesReaderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # ParenthesReader class has been compiled \n\n"

cd $MethodReceiverPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # MethodReceiver class has been compiled \n\n"

cd $ReturnTypeReaderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # ReturnTypeReader class has been compiled \n\n"

cd $NameReaderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # NameReader class has been compiled \n\n"

cd $ParameterReaderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # ParameterReader class has been compiled \n\n"

cd $MethodInterpreterPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # MethodInterpreter class has been compiled \n\n"

cd $DataBaseBuilderPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh


printf "   # DataBaseBuilder class has been compiled \n\n"

printf "   # Sub-Project has been compiled \n\n"
