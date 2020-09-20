
Write-Output ""

Write-Output " The construction of the make file builder started .."

Write-Output ""

mingw32-make -f library_updater.make

$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Library_Updater.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Library_Updater.exe
}

mv Library_Updater.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "  Automatic library updater program is ready :-)"

Write-Output ""
