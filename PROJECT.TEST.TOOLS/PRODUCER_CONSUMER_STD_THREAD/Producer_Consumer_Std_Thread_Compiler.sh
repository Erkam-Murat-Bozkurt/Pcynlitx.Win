
PCYNLITX_HEADERS=/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PCYNLITX_LIBRARY=/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

g++ -std=c++14 -o std_thread_producer_consumer -I$PCYNLITX_HEADERS \
    -L$PCYNLITX_LIBRARY Producer_Consumer_Std_Thread.cpp Data_Reader.cpp Data_Recorder.cpp \
    -include Producer_Consumer_Std_Thread.h -include Data_Reader.h -include Data_Recorder.h \
    -include IntToCharTranslater.h -lmptools -lpthread
