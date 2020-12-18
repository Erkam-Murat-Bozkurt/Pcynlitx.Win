
Write-Output ""

Write-Output ""

Write-Host "   # The construction of Empty_Process_Descriptor_File_Builder.exe started .."  -ForegroundColor Magenta

Write-Output ""

mingw32-make -f empty_process_descriptor_file_builder.make > Compiler_Output.txt

$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Empty_Process_Descriptor_File_Builder.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Empty_Process_Descriptor_File_Builder.exe
}

mv Empty_Process_Descriptor_File_Builder.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Empty_Process_Descriptor_File_Builder.exe has been constructed :-)"

Write-Output ""
