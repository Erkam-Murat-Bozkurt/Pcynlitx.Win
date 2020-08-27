
BASE_DIRECTORY=~/RODINIA_PATHFINDER_PCYNLITX
APP_SPEC_LIBRARY_HEADERS=$BASE_DIRECTORY/Thread_Server_Include_Directory
PROJECT_HEADERS=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PROJECT_LIBRARY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

Pcynlitx_Kernel ~/RODINIA_PATHFINDER_PCYNLITX/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -I$BASE_DIRECTORY -I$APP_SPEC_LIBRARY_HEADERS -I$PROJECT_HEADERS \
    -L$BASE_DIRECTORY -L$PROJECT_LIBRARY \
    -o Rodinia_Pathfinder_Pcynlitx_tn8 Rodinia_Pathfinder_Pcynlitx_tn8.cpp \
    -include MT_Library_Headers.h -include TM_Client.h -include Thread_Manager.h \
    -include Thread_Server.h -include itds.h -include Thread_Locker.h -include timer.h \
    -lThread_Server -lmptools -lpthread

printf "\n   #\e[1;34m The binar file has been constructed  .. \e[0m\n\n"
