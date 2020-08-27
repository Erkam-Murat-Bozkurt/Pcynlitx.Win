PCYNLITX_LIB_HEADERS=/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
BASE_DIRECTORY=/home/erkam/PARSEC_FLUIDANIMATE_STD_THREAD
PCYNLITX_LIB_DIRECTORY=/home/erkam/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

g++ -std=c++14 -I$BASE_DIRECTORY -I$PCYNLITX_LIB_HEADERS \
       -L$BASE_DIRECTORY -L$PCYNLITX_LIB_DIRECTORY \
       -o parsec_fluidanimate_std_thread cellpool.cpp cellpool.hpp fluid.hpp \
       fluidview.hpp parsec_barrier.cpp parsec_barrier.hpp parsec_fluidanimate_std_thread.cpp \
       -include Cpp_FileOperations.h -include IntToCharTranslater.h -lpthread -lglut -lmptools
