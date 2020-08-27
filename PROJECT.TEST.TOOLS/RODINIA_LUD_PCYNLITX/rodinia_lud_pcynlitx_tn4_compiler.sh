
Pcynlitx_Kernel ~/RODINIA_LUD_PCYNLITX/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -I/home/erkam/RODINIA_LUD_PCYNLITX/Thread_Server_Include_Directory \
    -I/home/erkam/RODINIA_LUD_PCYNLITX \
    -L/home/erkam/RODINIA_LUD_PCYNLITX \
    -o rodinia_lud_pcynlitx_tn4 rodinia_lud_pcynlitx_tn4.cpp lud_pcynlitx.cpp data_holder.cpp common.c \
    -include common.h -include MT_Library_Headers.h \
    -include data_holder.h -include TM_Client.h -include Thread_Manager.h \
    -include Thread_Server.h -include itds.h -include Thread_Locker.h \
    -lThread_Server -lm -lpthread

printf "\n   #\e[1;34m The binar file has been constructed  .. \e[0m\n\n"
