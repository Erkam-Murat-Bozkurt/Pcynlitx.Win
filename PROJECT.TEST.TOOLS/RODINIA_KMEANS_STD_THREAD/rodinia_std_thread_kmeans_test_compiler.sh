

PROJECT_HEADER_FILES=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PROJECT_LIBRARY_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

g++ -std=c++14 -I$PROJECT_HEADER_FILES -L$PROJECT_LIBRARY_DIRECTORY \
    -o rodinia_std_thread_kmeans_test rodinia_std_thread_kmeans_test.cpp \
    -include Cpp_FileOperations.h -lmptools
