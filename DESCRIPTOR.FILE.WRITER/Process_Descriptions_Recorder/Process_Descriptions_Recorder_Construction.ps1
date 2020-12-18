
Write-Output ""

Write-Output ""

Write-Host "   # The construction of Process_Descriptions_Recorder.exe started .." -ForegroundColor Magenta

Write-Output ""

mingw32-make -f process_descriptions_recorder.make > Compiler_Output.txt

$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Process_Descriptions_Recorder.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Process_Descriptions_Recorder.exe
}

mv Process_Descriptions_Recorder.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Process_Descriptions_Recorder.exe has been constructed :-)"

Write-Output ""
