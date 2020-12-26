
Write-Output ""

Write-Output ""

Write-Host "   # The construction of Description_Recorder.exe started .." -ForegroundColor Magenta

Write-Output ""

mingw32-make -f process_descriptions_recorder.make > Compiler_Output.txt

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder\Description_Recorder.exe'

if ($Condition)
{
     rm D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder\Description_Recorder.exe
}

Rename-Item -Path "Process_Descriptions_Recorder.exe" -NewName "Description_Recorder.exe"

$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Description_Recorder.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Description_Recorder.exe
}

mv Description_Recorder.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Description_Recorder.exe has been constructed :-)"

Write-Output ""
