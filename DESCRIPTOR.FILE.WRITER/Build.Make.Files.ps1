

$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

$DataRecorder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecorder"

$DataRecord_Tools_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecord_Tools"

$Process_Descriptions_Recorder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder"

$Description_Printer_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Description_Printer"

$Empty_Process_Descriptor_Descriptor_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Empty_Process_Descriptor_File_Builder"


Write-Output ""

Write-Output "  DESCRIPTOR FILE WRITER PROJECT AUTO-MAKE FILE CONSTRUCTION STARTED"

Write-Output ""


cd $DataRecorder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for DataRecorder class"



cd $DataRecord_Tools_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for DataRecorder class"




cd $Process_Descriptions_Recorder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Process_Descriptions_Recorder class"


cd $Description_Printer_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Description_Printer class"


cd $Empty_Process_Descriptor_Descriptor_File_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Empty_Process_Descriptor_Descriptor_File_Builder class"

Write-Output ""
