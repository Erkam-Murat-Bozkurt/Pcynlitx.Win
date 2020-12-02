
Write-Output ""

Write-Output ""

Write-Output " # Project binary files will be updated "

cd D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\MT_Project_Builder

PowerShell .\MT_Project_Builder_Construction.ps1

cd D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Reader

PowerShell .\Descriptor_File_Reader_Construction.ps1

cd D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Empty_Process_Descriptor_File_Builder

PowerShell .\Empty_Process_Descriptor_File_Builder_Construction.ps1

cd D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder

PowerShell .\Process_Descriptions_Recorder_Construction.ps1

cd D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel

PowerShell .\Kernel_Construction.ps1

cd D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Description_Printer

PowerShell .\Description_Printer_Construction.ps1

Write-Output "   Project binary files has been updated"

Write-Output ""
