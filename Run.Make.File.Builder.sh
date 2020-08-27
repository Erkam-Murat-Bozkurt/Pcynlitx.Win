
ToolsPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/Tools

ProcessInitializationPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ProcessInitialization

ClassReaderPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/ClassReader

DataBaseManagementPATH=~/PCYNLITX.PROJECT/CLASS.DECLERATION.READER/DataBaseManagement

Descriptor_File_Reader_Project_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER

Descriptor_File_Writer_Project_PATH=~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER

Client_Class_Builder_Project_PATH=~/PCYNLITX.PROJECT/CLIENT.CLASS.BUILDER

Executable_File_Builder_Project_PATH=~/PCYNLITX.PROJECT/EXECUTABLE.FILE.BUILDER

Smart_Pointer_Builder_Project_PATH=~/PCYNLITX.PROJECT/SMART.POINTER.BUILDER

Server_Class_Builder_Project_PATH=~/PCYNLITX.PROJECT/SERVER.CLASS.BUILDER

Kernel_Development_Project_PATH=~/PCYNLITX.PROJECT/KERNEL.DEVELOPMENT

GUI_DEVELOPMENT_PATH=~/PCYNLITX.PROJECT/GUI.DEVELOPMENT

cd $ToolsPATH

bash Build.Make.Files.sh

cd $ProcessInitializationPATH

bash Build.Make.Files.sh

cd $ClassReaderPATH

bash Build.Make.Files.sh

cd $DataBaseManagementPATH

bash Build.Make.Files.sh

cd $Descriptor_File_Reader_Project_PATH

bash Build.Make.Files.sh

cd $Descriptor_File_Writer_Project_PATH

bash Build.Make.Files.sh

cd $Executable_File_Builder_Project_PATH

bash Build.Make.Files.sh

cd $Client_Class_Builder_Project_PATH

bash Build.Make.Files.sh

cd $Smart_Pointer_Builder_Project_PATH

bash Build.Make.Files.sh

cd $Server_Class_Builder_Project_PATH

bash Build.Make.Files.sh

cd $Kernel_Development_Project_PATH

bash Build.Make.Files.sh

cd $GUI_DEVELOPMENT_PATH

bash Build.Make.Files.sh

printf "   #\e[1;34m Make Files for PROJECT has been derived .. \e[0m\n\n"
