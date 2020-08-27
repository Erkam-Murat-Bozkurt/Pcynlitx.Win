
DataRecorder_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/DataRecorder

DataRecord_Tools_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/DataRecord_Tools

Process_Descriptions_Recorder_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Process_Descriptions_Recorder

Description_Printer_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Description_Printer

Empty_Process_Descriptor_Descriptor_File_Builder_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Empty_Process_Descriptor_File_Builder

printf "\n DESCRIPTOR FILE WRITER PROJECT LIBRARY CONTRUCTION STARTED \n\n"


cd $DataRecorder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # DataRecorder class has been compiled \n\n"


cd $DataRecord_Tools_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # DataRecord_Tools class has been compiled \n\n"


cd $Process_Descriptions_Recorder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Process_Descriptions_Recorder class has been compiled \n\n"


cd $Description_Printer_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Description_Printer class has been compiled \n\n"


cd $Empty_Process_Descriptor_Descriptor_File_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Empty_Process_Descriptor_Descriptor_File_Builder class has been compiled \n\n"
