
INCLUDE_DIRECTORY=/home/erkam/PARSEC_FLUIDANIMATE_PCYNLITX/Thread_Server_Include_Directory
PCYNLITX_LIB_HEADERS=/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
BASE_DIRECTORY=/home/erkam/PARSEC_FLUIDANIMATE_PCYNLITX
PCYNLITX_LIB_DIRECTORY=/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

Pcynlitx_Kernel ~/PARSEC_FLUIDANIMATE_PCYNLITX/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -std=c++14 -I$INCLUDE_DIRECTORY -I$BASE_DIRECTORY -I$PCYNLITX_LIB_HEADERS \
       -L$BASE_DIRECTORY -L$PCYNLITX_LIB_DIRECTORY \
       -o parsec_fluidanimate_pcynlitx_tn32 cellpool.cpp cellpool.hpp fluid.hpp fluidview.hpp \
       parsec_barrier.cpp parsec_barrier.hpp parsec_fluidanimate_pcynlitx_tn32.cpp data_holder.cpp \
      -include data_holder.h -include MT_Library_Headers.h \
      -include Thread_Server.h -include itds.h \
     	-include TM_Client.h -include Thread_Manager.h \
     	-include Thread_Locker.h -include data_holder_Client.h \
      -include Cpp_FileOperations.h -include IntToCharTranslater.h \
     	-lThread_Server -lpthread -lglut -lmptools

printf "\n   #\e[1;34m The binary file has been constructed  .. \e[0m\n\n"
