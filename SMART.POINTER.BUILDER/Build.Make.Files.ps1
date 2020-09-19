
$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

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

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"


Write-Output ""

Write-Output " SMART POINTER AUTO-MAKE FILE CONSTRUCTION PROJECT STARTED"

Write-Output ""


cd $Builder_Initializer_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Builder_Initializer"


cd $ReportFileBuilder_HeaderWriterPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ReportFileBuilder_HeaderWriter"


cd $ReportFileBuilder_WriterPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ReportFileBuilder_Writer"



cd $Dynamic_Memory_Manager_Header_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Dynamic_Memory_Manager_Header_Builder"



cd $Dynamic_Memory_Manager_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Dynamic_Memory_Manager_Builder"


cd $Multi_Thread_Pointer_Header_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Multi_Thread_Pointer_Header_Builder"



cd $Multi_Thread_Pointer_Data_Collector_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Multi_Thread_Pointer_Data_Collector"




cd $Multi_Thread_Pointer_Compile_Data_Collector_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Multi_Thread_Pointer_Compile_Data_Collector"


cd $Multi_Thread_Pointer_File_Cleaner_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Multi_Thread_Pointer_File_Cleaner"


cd $Multi_Thread_Pointer_File_Data_Collector_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Multi_Thread_Pointer_File_Cleaner"



cd $Multi_Thread_Pointer_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Multi_Thread_Pointer_Builder"


cd $Multi_Thread_Pointer_Client_Header_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Multi_Thread_Pointer_Builder"



cd $Multi_Thread_Pointer_Client_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Multi_Thread_Pointer_Client_Builder"

Write-Output ""
