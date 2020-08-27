
BASE_DIRECTORY=~/PCYNLITX_DATA_CLUSTERING
APP_SPEC_LIBRARY_HEADERS=$BASE_DIRECTORY/Thread_Server_Include_Directory
PROJECT_HEADERS=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PROJECT_LIBRARY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

Pcynlitx_Kernel ~/PCYNLITX_DATA_CLUSTERING/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"


g++ -I$BASE_DIRECTORY -I$APP_SPEC_LIBRARY_HEADERS -I$PROJECT_HEADERS \
    -L$BASE_DIRECTORY -L$PROJECT_LIBRARY \
    -o Pcynlitx_Data_Clustering_tn32 Pcynlitx_Data_Clustering_tn32.cpp \
     First_Thread_Pool_Acess_Holder.cpp Second_Thread_Pool_Acess_Holder.cpp -include Pcynlitx_Data_Clustering.h \
    -include First_Thread_Pool_Acess_Holder_Client.h -include Second_Thread_Pool_Acess_Holder_Client.h \
    -include First_Thread_Pool_Acess_Holder.h -include Second_Thread_Pool_Acess_Holder.h \
    -include Thread_Pools_Data_Types.h \
    -include MT_Library_Headers.h -include TM_Client.h -include Thread_Manager.h \
    -include Thread_Server.h -include itds.h -include Thread_Locker.h \
    -include Cpp_FileOperations.h -include IntToCharTranslater.h \
    -lThread_Server -lmptools -lm -lpthread

printf "\n   #\e[1;34m The binar file has been constructed  .. \e[0m\n\n"
