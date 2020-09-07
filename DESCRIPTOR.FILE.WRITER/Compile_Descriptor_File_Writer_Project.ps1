
$DataRecorder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecorder"

$DataRecord_Tools_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\DataRecord_Tools"

$Process_Descriptions_Recorder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder"

$Description_Printer_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Description_Printer"

$Empty_Process_Descriptor_Descriptor_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Empty_Process_Descriptor_File_Builder"


Write-Output ""

Write-Output " DESCRIPTOR FILE WRITER PROJECT LIBRARY CONTRUCTION STARTED"

Write-Output ""


cd $DataRecorder_PATH

Class_Compiler.exe

Write-Output "   # DataRecorder class has been compiled"


cd $DataRecord_Tools_PATH

Class_Compiler.exe

Write-Output "   # DataRecord_Tools class has been compiled"


cd $Process_Descriptions_Recorder_PATH

Class_Compiler.exe

Write-Output "   # Process_Descriptions_Recorder class has been compiled"


cd $Description_Printer_PATH

Class_Compiler.exe

Write-Output "   # Description_Printer class has been compiled"


cd $Empty_Process_Descriptor_Descriptor_File_Builder_PATH

Class_Compiler.exe

Write-Output "   # Empty_Process_Descriptor_Descriptor_File_Builder class has been compiled"

Write-Output ""
