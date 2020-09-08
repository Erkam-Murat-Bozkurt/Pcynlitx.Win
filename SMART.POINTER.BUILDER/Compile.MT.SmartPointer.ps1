
$Builder_Initializer_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Builder_Initializer"

$ReportFileBuilder_HeaderWriterPATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\ReportFileBuilder_HeaderWriter"

$ReportFileBuilder_WriterPATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\ReportFileBuilder_Writer"

$Dynamic_Memory_Manager_Header_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Dynamic_Memory_Manager_Header_Builder"

$Dynamic_Memory_Manager_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Dynamic_Memory_Manager_Builder"

$Multi_Thread_Pointer_Compile_Data_Collector_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Multi_Thread_Pointer_Compile_Data_Collector"

$Multi_Thread_Pointer_Data_Collector_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Multi_Thread_Pointer_Data_Collector"

$Multi_Thread_Pointer_File_Cleaner_PATH="D:\PCYNLITX.PROJECT.WINDOWS/SMART.POINTER.BUILDER/Multi_Thread_Pointer_File_Cleaner"

$Multi_Thread_Pointer_File_Data_Collector_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Multi_Thread_Pointer_File_Data_Collector"

$Multi_Thread_Pointer_Header_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Multi_Thread_Pointer_Header_Builder"

$Multi_Thread_Pointer_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Multi_Thread_Pointer_Builder"

$Multi_Thread_Pointer_Client_Header_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Multi_Thread_Pointer_Client_Header_Builder"

$Multi_Thread_Pointer_Client_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SMART.POINTER.BUILDER\Multi_Thread_Pointer_Client_Builder"

Write-Output ""

Write-Output " SMART POINTER CONSTRUCTION PROJECT - UPDATE PROCESS STARTED"

Write-Output ""


cd $Builder_Initializer_PATH

Class_Compiler.exe

Write-Output "   # Builder_Initializer class has been compiled"


cd $ReportFileBuilder_HeaderWriterPATH

Class_Compiler.exe

Write-Output "   # ReportFileBuilder_HeaderWriter class has been compiled"


cd $ReportFileBuilder_WriterPATH

Class_Compiler.exe

Write-Output "   # ReportFileBuilder_Writer class has been compiled"


cd $Dynamic_Memory_Manager_Header_Builder_PATH

Class_Compiler.exe

Write-Output "   # Dynamic_Memory_Manager_Header_Builder class has been compiled"


cd $Dynamic_Memory_Manager_Builder_PATH

Class_Compiler.exe

Write-Output "   # Dynamic_Memory_Manager_Builder class has been compiled"


cd $Multi_Thread_Pointer_Header_Builder_PATH

Class_Compiler.exe

Write-Output "   # Multi_Thread_Pointer_Header_Builder class has been compiled"


cd $Multi_Thread_Pointer_Data_Collector_PATH

Class_Compiler.exe

Write-Output "   # Multi_Thread_Pointer_Data_Collector class has been compiled"


cd $Multi_Thread_Pointer_Compile_Data_Collector_PATH

Class_Compiler.exe

Write-Output "   # Multi_Thread_Pointer_Compile_Data_Collector class has been compiled"


cd $Multi_Thread_Pointer_File_Cleaner_PATH

Class_Compiler.exe

Write-Output "   # Multi_Thread_Pointer_File_Cleaner class has been compiled"


cd $Multi_Thread_Pointer_File_Data_Collector_PATH

Class_Compiler.exe

Write-Output "   # Multi_Thread_Pointer_File_Data_Collector class has been compiled"


cd $Multi_Thread_Pointer_Builder_PATH

Class_Compiler.exe

Write-Output "   # Multi_Thread_Pointer_Builder class has been compiled"


cd $Multi_Thread_Pointer_Client_Header_Builder_PATH

Class_Compiler.exe

Write-Output "   # Multi_Thread_Pointer_Client_Header_Builder class has been compiled"


cd $Multi_Thread_Pointer_Client_Builder_PATH

Class_Compiler.exe

Write-Output "   # Multi_Thread_Pointer_Client_Builder class has been compiled"


Write-Output "   # Sub-Project has been compiled \n\n"

Write-Output ""
