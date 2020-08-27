
Pcynlitx_Kernel ~/PARSEC_CANNEAL_PCYNLITX/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -I/home/erkam/PARSEC_CANNEAL_PCYNLITX/Thread_Server_Include_Directory \
    -I/home/erkam/PARSEC_CANNEAL_PCYNLITX \
    -L/home/erkam/PARSEC_CANNEAL_PCYNLITX -L/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY \
    -o canneal_pcynlitx_tn8 canneal_pcynlitx_tn8.cpp data_pointer.cpp  \
     annealer_thread.cpp netlist.cpp netlist_elem.cpp rng.cpp \
    -include annealer_thread.h -include annealer_types.h \
    -include AtomicPtr.h -include netlist.h -include netlist_elem.h -include rng.h \
    -include location_t.h -include MersenneTwister.h -include MT_Library_Headers.h \
    -include data_pointer.h -include TM_Client.h -include Thread_Manager.h \
    -include Thread_Server.h -include itds.h -include Thread_Locker.h \
    -lThread_Server -lmptools -lm -lpthread

printf "\n   #\e[1;34m The binary file has been constructed  .. \e[0m\n\n"
