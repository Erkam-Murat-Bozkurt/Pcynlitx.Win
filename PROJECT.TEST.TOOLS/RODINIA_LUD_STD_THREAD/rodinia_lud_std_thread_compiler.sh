
g++ -std=c++14 -o rodinia_lud_std_thread rodinia_lud_std_thread.cpp \
                  rodinia_lud_std_thread_function_imp.cpp common.c -include common.h -lpthread
