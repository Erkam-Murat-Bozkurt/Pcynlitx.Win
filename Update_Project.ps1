
cd D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY

rm libmptools.a


cd D:\PCYNLITX.PROJECT.WINDOWS

PowerShell .\ReFactorProjectLibrary.ps1

PowerShell .\Update_Project_Binaries.ps1

cd D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT

Write-Output ""

Write-Output "   # Project GUI compiling process has been started .."

Write-Output ""

Write-Output "   # In the case of the change on the files GUI.DEVELOPMENT\GUI.Header "

Write-Output ""

Write-Output "   # Please compile GUI.DEVELOPMENT Sub-project again"

Write-Output ""

mingw32-make.exe -f .\GUI_MakeFile.make

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Pcynlitx.exe'

if ($Condition)
{
   $Exists_On_Target = Test-Path -Path 'D:\Pcynlitx\Pcynlitx.exe'

   if ($Exists_On_Target ){

      rm 'D:\Pcynlitx\Pcynlitx.exe'
   }

   Move-Item -Path 'D:\PCYNLITX.PROJECT.WINDOWS\GUI.DEVELOPMENT\Pcynlitx.exe' -Destination "D:\Pcynlitx"
}

Write-Output ""

Write-Output "   # The GUI has been updated"

Write-Output ""

Write-Output "   # Project GUI compiling process has been complated .."

Write-Output ""
