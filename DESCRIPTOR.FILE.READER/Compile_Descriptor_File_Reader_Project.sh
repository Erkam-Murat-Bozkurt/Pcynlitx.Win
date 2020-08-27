
Descriptor_File_Data_Collector_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Descriptor_File_Data_Collector

Descriptor_File_Reader_Initializer_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Descriptor_File_Reader_Initializer

Descriptor_File_Number_Processor_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Descriptor_File_Number_Processor

Include_Directory_Description_Reader_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Include_Directory_Description_Reader

Inter_Thread_Class_Description_Reader_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Inter_Thread_Class_Description_Reader

Inter_Thread_Data_Type_Description_Reader_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Inter_Thread_Data_Type_Description_Reader

Source_File_Descriptions_Reader_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Source_File_Descriptions_Reader

Header_File_Descriptions_Reader_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Header_File_Descriptions_Reader

Library_Descriptions_Reader_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Library_Descriptions_Reader

Main_File_Descriptions_Reader_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Main_File_Descriptions_Reader

Descriptor_File_Reader_Syntax_Controller_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Descriptor_File_Reader_Syntax_Controller

Descriptor_File_Reader_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Descriptor_File_Reader


printf "\n  DESCRIPTOR FILE READER COMPILE PROCESS STARTED \n\n"


cd $Descriptor_File_Data_Collector_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Descriptor_File_Data_Collector class has been compiled \n\n"


cd $Descriptor_File_Reader_Initializer_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Descriptor_File_Reader_Initializer class has been compiled \n\n"


cd $Descriptor_File_Number_Processor_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Descriptor_File_Number_Processor class has been compiled \n\n"


cd $Include_Directory_Description_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Include_Directory_Description_Reader class has been compiled \n\n"


cd $Inter_Thread_Class_Description_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Inter_Thread_Class_Description_Reader class has been compiled \n\n"


cd $Inter_Thread_Data_Type_Description_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Inter_Thread_Data_Type_Description_Reader class has been compiled \n\n"


cd $Source_File_Descriptions_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Source_File_Descriptions_Reader class has been compiled \n\n"


cd $Header_File_Descriptions_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Header_File_Descriptions_Reader class has been compiled \n\n"


cd $Library_Descriptions_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Library_Descriptions_Reader class has been compiled \n\n"


cd $Main_File_Descriptions_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Main_File_Descriptions_Reader class has been compiled \n\n"


cd $Descriptor_File_Reader_Syntax_Controller_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Descriptor_File_Reader_Syntax_Controler class has been compiled \n\n"


cd $Descriptor_File_Reader_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Descriptor_File_Reader class has been compiled \n\n"


printf "   # Sub-Project has been compiled \n\n"
