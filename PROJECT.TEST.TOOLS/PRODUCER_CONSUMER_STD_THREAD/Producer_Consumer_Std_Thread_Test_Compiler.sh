
PCYNLITX_HEADERS=/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PCYNLITX_LIBRARY=/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

g++ -std=c++14 -o std_thread_producer_consumer_test -I$PCYNLITX_HEADERS \
    -L$PCYNLITX_LIBRARY Producer_Consumer_Std_Thread_Test.cpp  -include Cpp_FileOperations.h -lmptools
