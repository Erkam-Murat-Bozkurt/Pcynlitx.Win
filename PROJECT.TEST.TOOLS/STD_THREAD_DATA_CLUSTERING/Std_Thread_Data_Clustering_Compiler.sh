
BASE_DIRECTORY=~/STD_THREAD_DATA_CLUSTERING
PROJECT_HEADERS=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PROJECT_LIBRARY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

g++ -I$BASE_DIRECTORY -I$PROJECT_HEADERS \
    -L$BASE_DIRECTORY -L$PROJECT_LIBRARY \
    -o Std_Thread_Data_Clustering Std_Thread_Data_Clustering.cpp \
    -include Std_Thread_Data_Clustering.h -include IntToCharTranslater.h \
    -include Cpp_FileOperations.h -lmptools -lm -lpthread

printf "\n   #\e[1;34m The binar file has been constructed  .. \e[0m\n\n"
