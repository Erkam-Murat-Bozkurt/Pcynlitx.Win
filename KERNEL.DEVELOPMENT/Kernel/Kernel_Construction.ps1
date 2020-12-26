
Write-Output ""

Write-Output ""

Write-Host "   # The construction of the Pcynlitx_Kernel.exe started .." -ForegroundColor Magenta

Write-Output ""

mingw32-make -f kernel.make > Compiler_Output.txt


$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Pcynlitx_Kernel.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Pcynlitx_Kernel.exe
}

Rename-Item -Path "Kernel.exe" -NewName "Pcynlitx_Kernel.exe"


mv Pcynlitx_Kernel.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Pcynlitx_Kernel.exe has been constructed :-)"

Write-Output ""

Write-Output ""
