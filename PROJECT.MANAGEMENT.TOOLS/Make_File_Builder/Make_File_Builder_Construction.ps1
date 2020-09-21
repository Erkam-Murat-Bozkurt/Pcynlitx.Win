
Write-Output ""

Write-Output ""

Write-Output " # The construction of the make file builder started .."

Write-Output ""

mingw32-make -f make_file_builder.make > Compiler_Output.txt


$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Make_File_Builder.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Make_File_Builder.exe
}

mv Make_File_Builder.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Make_File_Builder has been constructed :-)"

Write-Output ""
