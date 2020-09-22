
$DataRecorder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecorder"

$DataRecord_Tools_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecord_Tools"

$Process_Descriptions_Recorder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder"

$Description_Printer_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Description_Printer"

$Empty_Process_Descriptor_Descriptor_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Empty_Process_Descriptor_File_Builder"

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"



Write-Output ""

Write-Output " DESCRIPTOR FILE WRITER PROJECT LIBRARY CONSTRUCTION STARTED"

Write-Output ""


cd $DataRecorder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecorder\DataRecorder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecorder\DataRecorder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecorder\DataRecorder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # DataRecorder class has been compiled"


cd $DataRecord_Tools_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecord_Tools\DataRecord_Tools.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecord_Tools\DataRecord_Tools.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecord_Tools\DataRecord_Tools.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # DataRecord_Tools class has been compiled"




cd $Process_Descriptions_Recorder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder\Process_Descriptions_Recorder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder\Process_Descriptions_Recorder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder\Process_Descriptions_Recorder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Process_Descriptions_Recorder class has been compiled"


cd $Description_Printer_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Description_Printer\Description_Printer.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Description_Printer\Description_Printer.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Description_Printer\Description_Printer.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Description_Printer class has been compiled"




cd $Empty_Process_Descriptor_Descriptor_File_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Empty_Process_Descriptor_File_Builder\Empty_Process_Descriptor_File_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Empty_Process_Descriptor_File_Builder\Empty_Process_Descriptor_File_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Empty_Process_Descriptor_File_Builder\Empty_Process_Descriptor_File_Builder.o -Destination $OBJECTS_DIRECTORY
}
Write-Output "   # Empty_Process_Descriptor_File_Builder class has been compiled"

Write-Output ""
