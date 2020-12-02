

Write-Output ""

Write-Output ""

Write-Output " # The construction of the Descriptor_File_Reader.exe started .."

Write-Output ""

mingw32-make -f descriptor_file_reader.make > Compiler_Output.txt


$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Descriptor_File_Reader.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Descriptor_File_Reader.exe
}

mv Descriptor_File_Reader.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Descriptor_File_Reader.exe has been constructed :-)"

Write-Output ""

Write-Output ""
