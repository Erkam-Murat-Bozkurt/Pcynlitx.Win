
Builder_Initializer_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Builder_Initializer

ReportFileBuilder_HeaderWriterPATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/ReportFileBuilder_HeaderWriter

ReportFileBuilder_WriterPATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/ReportFileBuilder_Writer

Dynamic_Memory_Manager_Header_Builder_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Dynamic_Memory_Manager_Header_Builder

Dynamic_Memory_Manager_Builder_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Dynamic_Memory_Manager_Builder

Multi_Thread_Pointer_Compile_Data_Collector_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Compile_Data_Collector

Multi_Thread_Pointer_Data_Collector_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Data_Collector

Multi_Thread_Pointer_File_Cleaner_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Multi_Thread_Pointer_File_Cleaner

Multi_Thread_Pointer_File_Data_Collector_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Multi_Thread_Pointer_File_Data_Collector

Multi_Thread_Pointer_Header_Builder_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Header_Builder

Multi_Thread_Pointer_Builder_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Builder

Multi_Thread_Pointer_Client_Header_Builder_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Client_Header_Builder

Multi_Thread_Pointer_Client_Builder_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Client_Builder



printf "\n SMART POINTER CONSTRUCTION PROJECT - UPDATE PROCESS STARTED \n\n"


cd $Builder_Initializer_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Builder_Initializer class has been compiled \n\n"


cd $ReportFileBuilder_HeaderWriterPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # ReportFileBuilder_HeaderWriter class has been compiled \n\n"


cd $ReportFileBuilder_WriterPATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # ReportFileBuilder_Writer class has been compiled \n\n"


cd $Dynamic_Memory_Manager_Header_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Dynamic_Memory_Manager_Header_Builder class has been compiled \n\n"


cd $Dynamic_Memory_Manager_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Dynamic_Memory_Manager_Builder class has been compiled \n\n"


cd $Multi_Thread_Pointer_Header_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Multi_Thread_Pointer_Header_Builder class has been compiled \n\n"


cd $Multi_Thread_Pointer_Data_Collector_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Multi_Thread_Pointer_Data_Collector class has been compiled \n\n"


cd $Multi_Thread_Pointer_Compile_Data_Collector_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Multi_Thread_Pointer_Compile_Data_Collector class has been compiled \n\n"


cd $Multi_Thread_Pointer_File_Cleaner_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Multi_Thread_Pointer_File_Cleaner class has been compiled \n\n"


cd $Multi_Thread_Pointer_File_Data_Collector_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Multi_Thread_Pointer_File_Data_Collector class has been compiled \n\n"


cd $Multi_Thread_Pointer_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Multi_Thread_Pointer_Builder class has been compiled \n\n"


cd $Multi_Thread_Pointer_Client_Header_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Multi_Thread_Pointer_Client_Header_Builder class has been compiled \n\n"


cd $Multi_Thread_Pointer_Client_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Multi_Thread_Pointer_Client_Builder class has been compiled \n\n"


printf "   # Sub-Project has been compiled \n\n"
