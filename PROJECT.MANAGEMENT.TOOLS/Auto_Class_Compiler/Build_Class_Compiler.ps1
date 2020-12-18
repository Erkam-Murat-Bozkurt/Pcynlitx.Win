
Write-Output ""

Write-Output ""

Write-Host "   # The construction of the Test_Program_Builder started .."  -ForegroundColor Magenta

Write-Output ""

mingw32-make -f auto_class_compiler.make > Compiler_Output.txt


$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Class_Compiler.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Class_Compiler.exe
}

mv Class_Compiler.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Test_Program_Builder has been constructed :-)"

Write-Output ""
