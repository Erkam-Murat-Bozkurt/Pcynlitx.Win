
BASE_DIRECTORY=~/RODINIA_PATHFINDER_STD_THREAD
PROJECT_HEADERS=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PROJECT_LIBRARY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

g++ -I$BASE_DIRECTORY -I$PROJECT_HEADERS \
    -L$BASE_DIRECTORY -L$PROJECT_LIBRARY \
    -o Rodinia_Pathfinder_Std_Thread Rodinia_Pathfinder_Std_Thread.cpp \
    -include IntToCharTranslater.h -include timer.h \
    -lmptools -lpthread

printf "\n   #\e[1;34m The binar file has been constructed  .. \e[0m\n\n"
