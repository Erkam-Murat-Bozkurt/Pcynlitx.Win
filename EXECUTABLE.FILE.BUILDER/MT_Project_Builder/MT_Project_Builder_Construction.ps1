
Write-Output ""

Write-Output ""

Write-Host "   # The construction of the MT_Project_Builder started .."  -ForegroundColor Magenta

Write-Output ""

mingw32-make -f mt_project_builder.make > Compiler_Output.txt


$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\MT_Project_Builder.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\MT_Project_Builder.exe
}

mv MT_Project_Builder.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   MT_Project_Builder.exe has been constructed :-)"

Write-Output ""
