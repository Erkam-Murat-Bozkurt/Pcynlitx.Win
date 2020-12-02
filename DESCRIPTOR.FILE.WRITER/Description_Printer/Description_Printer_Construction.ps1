
Write-Output ""

Write-Output ""

Write-Output " # The construction of Description_Printer.exe started .."

Write-Output ""

mingw32-make -f description_printer.make > Compiler_Output.txt

$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Description_Printer.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Description_Printer.exe
}

mv Description_Printer.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Description_Printer.exe has been constructed :-)"

Write-Output ""

Write-Output ""
