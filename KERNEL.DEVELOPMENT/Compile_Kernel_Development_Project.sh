
Kernel_Data_Collector_PATH=~/PCYNLITX.PROJECT/KERNEL.DEVELOPMENT/Kernel_Data_Collector

Kernel_PATH=~/PCYNLITX.PROJECT/KERNEL.DEVELOPMENT/Kernel

printf "\n KERNEL DEVELOPMENT PROJECT COMPILE PROCESS HAS BEEN STARTED \n\n"


cd $Kernel_Data_Collector_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Kernel_Data_Collector class has been compiled \n\n"


cd $Kernel_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Kernel class has been compiled \n\n"

printf "   # Sub-Project has been compiled \n\n"
