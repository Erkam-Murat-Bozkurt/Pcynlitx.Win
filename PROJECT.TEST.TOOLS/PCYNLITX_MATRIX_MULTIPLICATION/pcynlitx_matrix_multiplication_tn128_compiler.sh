
Pcynlitx_Kernel ~/PCYNLITX_MATRIX_MULTIPLICATION/Project_Descriptor_File

printf "\n   #\e[1;34m The App-Specific library has been constructed  .. \e[0m\n\n"

g++ -I/home/erkam/PCYNLITX_MATRIX_MULTIPLICATION/Thread_Server_Include_Directory \
    -I/home/erkam/PCYNLITX_MATRIX_MULTIPLICATION \
    -L/home/erkam/PCYNLITX_MATRIX_MULTIPLICATION \
    -o pcynlitx_matrix_multiplication_tn128 pcynlitx_matrix_multiplication_tn128.cpp Matrix_Data.cpp \
    -include MT_Library_Headers.h -include Matrix_Data.h \
    -include TM_Client.h -include Thread_Manager.h \
    -include Thread_Server.h -include itds.h -include Thread_Locker.h \
    -lThread_Server -lm -lpthread

printf "\n   #\e[1;34m The binar file has been constructed  .. \e[0m\n\n"
