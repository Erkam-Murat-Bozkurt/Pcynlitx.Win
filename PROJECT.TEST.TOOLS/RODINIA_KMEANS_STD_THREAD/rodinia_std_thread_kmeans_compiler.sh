

BASE_DIRECTORY=~/RODINIA_KMEANS_STD_THREAD
PROJECT_HEADERS=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PROJECT_LIBRARY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

g++ -I$BASE_DIRECTORY -I$PROJECT_HEADERS \
    -L$BASE_DIRECTORY -L$PROJECT_LIBRARY \
    -o rodinia_std_thread_kmeans rodinia_std_thread_kmeans.cpp kmeans_clustering.c cluster.c \
    -include kmeans.h -include getopt.h -include IntToCharTranslater.h \
    -lmptools -lpthread

printf "\n   #\e[1;34m The binar file has been constructed  .. \e[0m\n\n"
