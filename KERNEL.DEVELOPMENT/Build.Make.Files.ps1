
$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

$Kernel_Data_Collector_PATH="D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel_Data_Collector"

$Kernel_PATH="D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel"

Write-Output ""

Write-Output "  KERNEL DEVELOPMENT PROJECT COMPILE PROCESS HAS BEEN STARTED"

Write-Output ""


cd $Kernel_Data_Collector_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Kernel_Data_Collector"



cd $Kernel_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Kernel"

Write-Output ""