
Write-Output ""

Write-Output ""

Write-Host "   # The construction of the Convert_Repo_To_Source.exe started .."  -ForegroundColor Magenta

Write-Output ""

mingw32-make -f Convert_Repo_To_Source.make > Compiler_Output.txt


$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Convert_Repo_To_Source.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Convert_Repo_To_Source.exe
}

mv Convert_Repo_To_Source.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Convert_Repo_To_Source has been constructed :-)"

Write-Output ""
