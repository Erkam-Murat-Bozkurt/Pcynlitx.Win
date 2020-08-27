
INCLUDE_DIRECTORY=/home/erkam/PARSEC_SWAPTIONS_PCYNLITX/Thread_Server_Include_Directory
BASE_DIRECTORY=/home/erkam/PARSEC_SWAPTIONS_PCYNLITX

Pcynlitx_Kernel ~/PARSEC_SWAPTIONS_PCYNLITX/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -std=c++14 -I$INCLUDE_DIRECTORY -I$BASE_DIRECTORY -L/$BASE_DIRECTORY -o parsec_swaptions_pcynlitx_tn256 \
   CumNormalInv.cpp MaxFunction.cpp RanUnif.cpp nr_routines.c icdf.cpp \
   HJM_SimPath_Forward_Blocking.cpp HJM.cpp HJM_Swaption_Blocking.cpp \
	 parsec_swaptions_pcynlitx_tn256.cpp -include $BASE_DIRECTORY/HJM_type.h \
	-include $BASE_DIRECTORY/HJM.h -include $BASE_DIRECTORY/resource.h \
	-include $BASE_DIRECTORY/nr_routines.h -include $INCLUDE_DIRECTORY/MT_Library_Headers.h \
	-include $INCLUDE_DIRECTORY/Thread_Server.h \
	-include $INCLUDE_DIRECTORY/itds.h -include $INCLUDE_DIRECTORY/TM_Client.h \
	-include $INCLUDE_DIRECTORY/Thread_Manager.h -include $INCLUDE_DIRECTORY/Thread_Locker.h \
	-include $BASE_DIRECTORY/swaptions_pcynlitx.h \
	-lThread_Server -lpthread

printf "\n   #\e[1;34m The binar file has been constructed  .. \e[0m\n\n"
