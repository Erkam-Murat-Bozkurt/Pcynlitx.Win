
Write-Output ""

Write-Output ""

Write-Host "   # The construction of the library updater started .." -ForegroundColor Magenta

Write-Output ""

mingw32-make -f library_updater.make  > Compiler_Output.txt

$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Library_Updater.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Library_Updater.exe
}

mv Library_Updater.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Automatic library updater program is ready :-)"

Write-Output ""
