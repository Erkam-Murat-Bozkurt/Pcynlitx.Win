
$Descriptor_File_Data_Collector_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Data_Collector"

$Descriptor_File_Reader_Initializer_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Reader_Initializer"

$Descriptor_File_Number_Processor_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Number_Processor"

$Include_Directory_Description_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Include_Directory_Description_Reader"

$Inter_Thread_Class_Description_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Inter_Thread_Class_Description_Reader"

$Inter_Thread_Data_Type_Description_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Inter_Thread_Data_Type_Description_Reader"

$Source_File_Descriptions_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Source_File_Descriptions_Reader"

$Header_File_Descriptions_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Header_File_Descriptions_Reader"

$Library_Descriptions_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Library_Descriptions_Reader"

$Main_File_Descriptions_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Main_File_Descriptions_Reader"

$Descriptor_File_Reader_Syntax_Controller_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Reader_Syntax_Controller"

$Descriptor_File_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Reader"


Write-Output ""

Write-Output "  DESCRIPTOR FILE READER COMPILE PROCESS STARTED"


cd $Descriptor_File_Data_Collector_PATH

Class_Compiler.exe

Write-Output "   # Descriptor_File_Data_Collector class has been compiled"


cd $Descriptor_File_Reader_Initializer_PATH

Class_Compiler.exe

Write-Output "   # Descriptor_File_Reader_Initializer class has been compiled"


cd $Descriptor_File_Number_Processor_PATH

Class_Compiler.exe

Write-Output "   # Descriptor_File_Number_Processor class has been compiled"


cd $Include_Directory_Description_Reader_PATH

Class_Compiler.exe

Write-Output "   # Include_Directory_Description_Reader class has been compiled"


cd $Inter_Thread_Class_Description_Reader_PATH

Class_Compiler.exe

Write-Output "   # Inter_Thread_Class_Description_Reader class has been compiled"


cd $Inter_Thread_Data_Type_Description_Reader_PATH

Class_Compiler.exe

Write-Output "   # Inter_Thread_Data_Type_Description_Reader class has been compiled"


cd $Source_File_Descriptions_Reader_PATH

Class_Compiler.exe

Write-Output "   # Source_File_Descriptions_Reader class has been compiled"


cd $Header_File_Descriptions_Reader_PATH

Class_Compiler.exe

Write-Output "   # Header_File_Descriptions_Reader class has been compiled"


cd $Library_Descriptions_Reader_PATH

Class_Compiler.exe

Write-Output "   # Library_Descriptions_Reader class has been compiled"


cd $Main_File_Descriptions_Reader_PATH

Class_Compiler.exe

Write-Output "   # Main_File_Descriptions_Reader class has been compiled"


cd $Descriptor_File_Reader_Syntax_Controller_PATH

Class_Compiler.exe

Write-Output "   # Descriptor_File_Reader_Syntax_Controler class has been compiled"


cd $Descriptor_File_Reader_PATH

Class_Compiler.exe

Write-Output "   # Descriptor_File_Reader class has been compiled"

Write-Output "   # Sub-Project has been compiled"

Write-Output ""
