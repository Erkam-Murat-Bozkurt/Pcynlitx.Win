
BASE_DIRECTORY=~/MULTITHREADED_NUMBER_COUNTER_PCYNLITX
APP_SPEC_LIBRARY_HEADERS=$BASE_DIRECTORY/Thread_Server_Include_Directory
PROJECT_HEADERS=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PROJECT_LIBRARY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

Pcynlitx_Kernel ~/MULTITHREADED_NUMBER_COUNTER_PCYNLITX/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -I$BASE_DIRECTORY -I$APP_SPEC_LIBRARY_HEADERS -I$PROJECT_HEADERS \
    -L$BASE_DIRECTORY -L$PROJECT_LIBRARY \
    -o mt_number_counter_pcynlitx_tn_64 Multithreaded_Number_Counter_Pcynlitx_tn64.cpp \
     Data_Reader.cpp -include Data_Reader.h -include Data_Types.h -include Data_Reader_Client.h \
    -include MT_Library_Headers.h -include TM_Client.h -include Thread_Manager.h \
    -include Thread_Server.h -include itds.h -include Thread_Locker.h \
    -lThread_Server -lmptools -lm -lpthread

printf "\n   #\e[1;34m The binary file has been constructed  .. \e[0m\n\n"
