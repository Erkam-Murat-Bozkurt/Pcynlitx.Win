
Inter_Thread_Data_Structure_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Inter_Thread_Data_Structure_Builder

Thread_Locker_Header_File_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Thread_Locker_Header_File_Builder

Thread_Locker_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Thread_Locker_Builder

Thread_Data_Manager_Header_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Thread_Data_Manager_Header_Builder

Thread_Data_Manager_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Thread_Data_Manager_Builder

Thread_Manager_Header_File_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Thread_Manager_Header_File_Builder

Thread_Manager_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Thread_Manager_Builder

TM_Client_Header_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/TM_Client_Header_Builder

TM_Client_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/TM_Client_Builder

Server_Header_File_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Server_Header_File_Builder

Server_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Server_Builder

Main_File_Builder_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER/Main_File_Builder

printf "\n  SERVER CLASS BUILDER PROJECT COMPILE PROCESS HAS BEEN STARTED  \n\n"

cd $Inter_Thread_Data_Structure_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Inter_Thread_Data_Structure_Builder class has been compiled \n\n"


cd $Thread_Locker_Header_File_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Thread_Locker_Header_File_Builder class has been compiled \n\n"


cd $Thread_Locker_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Thread_Locker_Builder class has been compiled \n\n"


cd $Thread_Data_Manager_Header_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Thread_Manager_Header_File_Builder class has been compiled \n\n"


cd $Thread_Data_Manager_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Thread_Manager_Header_File_Builder class has been compiled \n\n"


cd $Thread_Manager_Header_File_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Thread_Manager_Header_File_Builder class has been compiled \n\n"



cd $Thread_Manager_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Thread_Manager_Builder class has been compiled \n\n"


cd $TM_Client_Header_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # TM_Client_Header_Builder class has been compiled \n\n"


cd $TM_Client_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # TM_Client_Builder class has been compiled \n\n"


cd $Server_Header_File_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Process_Supervisor_Header_File_Builder class has been compiled \n\n"


cd $Server_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Process_Supervisor_Builder class has been compiled \n\n"


cd $Main_File_Builder_PATH

make -f auto_make_file.make

bash Modification_Control_Script.sh

printf "   # Main_File_Builder class has been compiled \n\n"


printf "   # Sub-Project has been compiled \n\n"
