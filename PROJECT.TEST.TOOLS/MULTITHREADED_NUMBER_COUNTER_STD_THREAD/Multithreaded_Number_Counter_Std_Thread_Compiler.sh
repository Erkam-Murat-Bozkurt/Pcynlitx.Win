
PROJECT_HEADER_FILES=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
PROJECT_LIBRARY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY
BASE_DIRECTORY=~/MULTITHREADED_NUMBER_COUNTER_STD_THREAD

g++ -std=c++14 -o std_thread_number_counter -I$PROJECT_HEADER_FILES -I$BASE_DIRECTORY \
    -L$PROJECT_LIBRARY -L$BASE_DIRECTORY Multithreaded_Number_Counter_Std_Thread.cpp \
     Data_Reader.cpp -include Data_Reader.h -include Cpp_FileOperations.h \
    -include StringOperator.h -include IntToCharTranslater.h -lmptools -lpthread
