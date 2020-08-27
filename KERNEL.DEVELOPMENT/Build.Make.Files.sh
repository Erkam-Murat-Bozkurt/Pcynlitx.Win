

Kernel_Data_Collector_PATH=~/PCYNLITX.PROJECT/KERNEL.DEVELOPMENT/Kernel_Data_Collector

Kernel_PATH=~/PCYNLITX.PROJECT/KERNEL.DEVELOPMENT/Kernel

printf "\n \e[3;37;42m KERNEL DEVELOPMENT PROJECT MAKE FILE CONSTRUCTION HAS BEEN STARTED \e[0m \n\n"

cd $Kernel_Data_Collector_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for Kernel_Data_Collector class .. \e[0m\n\n"

cd $Kernel_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for Kernel class .. \e[0m\n\n"

printf "   # \e[1;7;36m The make files for the Sub-Project has been derived .. \e[0m\n\n"
