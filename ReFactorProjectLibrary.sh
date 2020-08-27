
ToolsPATH=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools

ProcessInitializationPATH==D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER/ProcessInitialization

ClassReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader

DataBaseManagementPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/DataBaseManagement

Descriptor_File_Reader_Project_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER

Descriptor_File_Writer_Project_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER

Client_Class_Builder_Project_PATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER

Executable_File_Builder_Project_PATH=~/PCYNLITX.PROJECT/EXECUTABLE.FILE.BUILDER

Smart_Pointer_Builder_Project_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER

Server_Class_Builder_Project_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER

Kernel_Development_Project_PATH=~/PCYNLITX.PROJECT/KERNEL.DEVELOPMENT

cd D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools

PowerShell Run_Tools_Compiler.psm1

printf "\n"

printf "   # Sub-Project Tools has been updated \n\n"

cd D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization

bash Run_Reader_Init_Compiler.psm1

printf "   # Sub-Project ProcessInitialization has been updated \n\n"

cd $ClassReaderPATH

bash Run_Class_Reader_Project_Compiler.psm1

printf "   # Sub-Project ClassReader has been updated \n\n"

cd $DataBaseManagementPATH

bash Run_DB_Management_Project_Compiler.psm1

printf "   # Sub-Project DataBaseManagement has been updated \n\n"

cd $Descriptor_File_Reader_Project_PATH

bash Run_Descriptor_File_Reader_Project_Compiler.psm1

printf "   # Sub-Project Descriptor_File_Reader has been updated \n\n"

cd $Descriptor_File_Writer_Project_PATH

bash Run_Descriptor_File_Writer_Compiler.psm1

printf "   # Sub-Project Descriptor_File_Writer has been updated \n\n"

cd $Executable_File_Builder_Project_PATH

bash Run_Exe_Builder_Compiler.psm1

printf "   # Sub-Project Executable_File_Builder has been updated \n\n"

cd $Client_Class_Builder_Project_PATH

bash Run_Client_Class_Project_Compiler.psm1

printf "   # Sub-Project Client_Class_Builder has been updated \n\n"

cd $Smart_Pointer_Builder_Project_PATH

bash Run_Smart_Pointer_Project_Compiler.psm1

printf "   # Sub-Project Smart_Pointer_Builder has been updated \n\n"

cd $Server_Class_Builder_Project_PATH

bash Run_Server_Builder_Project_Compiler.psm1

printf "   # Sub-Project Server_Class_Builder has been updated \n\n"

cd $Kernel_Development_Project_PATH

bash Run_Kernel_Compiler.psm1

printf "   # Sub-Project Kernel_Development has been updated \n\n"

Library_Updater

printf "   # PROJECT library libmptoos.a has been updated \n\n"
