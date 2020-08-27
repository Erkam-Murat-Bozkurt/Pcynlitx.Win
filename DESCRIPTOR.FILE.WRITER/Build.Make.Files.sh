
DataRecorder_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/DataRecorder

DataRecord_Tools_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/DataRecord_Tools

Process_Descriptions_Recorder_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Process_Descriptions_Recorder

Description_Printer_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Description_Printer

Empty_Process_Descriptor_Descriptor_File_Builder_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Empty_Process_Descriptor_File_Builder

printf "\n \e[3;37;42m DESCRIPTOR FILE WRITER PROJECT LIBRARY MAKE FILE CONTRUCTION STARTED \e[0m \n\n"

cd $DataRecorder_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for DataRecorder class has been compiled .. \e[0m\n\n"


cd $DataRecord_Tools_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for DataRecord_Tools class .. \e[0m\n\n"


cd $Process_Descriptions_Recorder_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for Process_Descriptions_Recorder class \e[0m\n\n"


cd $Description_Printer_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for Description_Printer class \e[0m\n\n"


cd $Empty_Process_Descriptor_Descriptor_File_Builder_PATH

Setup_Project

printf "   #\e[3;36m A make file has been derived for Empty_Process_Descriptor_Descriptor_File_Builder class \e[0m\n\n"

printf "   # \e[1;7;36m The make files for the Sub-Project has been derived .. \e[0m\n\n"
