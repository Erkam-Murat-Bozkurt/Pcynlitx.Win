
Pcynlitx_Kernel ~/PARSEC_BLACKSCHOLES_PCYNLITX/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -I/home/erkam/PARSEC_BLACKSCHOLES_PCYNLITX/Thread_Server_Include_Directory \
    -L/home/erkam/PARSEC_BLACKSCHOLES_PCYNLITX \
    -o blackscholes_pcynlitx_tn_256 blackscholes_pcynlitx_tn_256.cpp \
    -include MT_Library_Headers.h -include TM_Client.h -include Thread_Manager.h \
    -include Thread_Server.h -include itds.h -include Thread_Locker.h \
    -lThread_Server -lm -lpthread

printf "\n   #\e[1;34m The binary file has been constructed  .. \e[0m\n\n"
