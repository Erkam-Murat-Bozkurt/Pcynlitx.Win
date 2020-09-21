
Write-Output ""

Write-Output ""

Write-Output " # The construction of the library updater started .."

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

Write-Output ""
