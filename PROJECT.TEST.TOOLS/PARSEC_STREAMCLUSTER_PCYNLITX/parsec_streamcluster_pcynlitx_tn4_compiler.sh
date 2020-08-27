
BASE_DIRECTORY=~/PARSEC_STREAMCLUSTER_PCYNLITX
INCLUDE_DIRECTORY=~/PARSEC_STREAMCLUSTER_PCYNLITX/Thread_Server_Include_Directory
PCYNLITX_PROJECT_HEADERS=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PCYNLITX_LIBRARY_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

Pcynlitx_Kernel ~/PARSEC_STREAMCLUSTER_PCYNLITX/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -I$BASE_DIRECTORY -I$INCLUDE_DIRECTORY -I$PCYNLITX_PROJECT_HEADERS \
    -L$BASE_DIRECTORY -L$PCYNLITX_LIBRARY_DIRECTORY -o parsec_streamcluster_pcynlitx_tn4 \
     parsec_streamcluster_pcynlitx_tn4.cpp \
     address_holder.cpp -include address_holder.h  -include thread_argument.h \
    -include $PCYNLITX_PROJECT_HEADERS/Cpp_FileOperations.h \
    -include $PCYNLITX_PROJECT_HEADERS/IntToCharTranslater.h \
    -include $INCLUDE_DIRECTORY/MT_Library_Headers.h \
    -include $INCLUDE_DIRECTORY/Thread_Server.h \
    -include $INCLUDE_DIRECTORY/itds.h -include $INCLUDE_DIRECTORY/TM_Client.h \
    -include $INCLUDE_DIRECTORY/Thread_Manager.h -include $INCLUDE_DIRECTORY/Thread_Locker.h \
    -lThread_Server -lpthread -lmptools

printf "\n   #\e[1;34m The binary file has been constructed  .. \e[0m\n\n"
