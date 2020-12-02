
Write-Output ""

Write-Output ""

Write-Output " # The construction of the Kernel.exe started .."

Write-Output ""

mingw32-make -f kernel.make > Compiler_Output.txt


$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Kernel.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Kernel.exe
}

mv Kernel.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Kernel.exe has been constructed :-)"

Write-Output ""

Write-Output ""
