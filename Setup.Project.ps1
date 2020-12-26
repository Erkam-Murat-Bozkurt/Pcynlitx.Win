$BASE_DIRECTORY="D:\PCYNLITX.PROJECT.WINDOWS"

$PROJECT_MANAGEMENT_TOOLS="D:\PCYNLITX.PROJECT.WINDOWS\PROJECT.MANAGEMENT.TOOLS"

cd $PROJECT_MANAGEMENT_TOOLS


Write-Output ""

Write-Output ""

Write-Host "   PCYNLITX PROJECT SETUP SCRIPT FOR DEVELOPMENT TOOLS INITIALIZATION   " -ForegroundColor Green

Write-Output ""

Write-Host "   " -ForegroundColor Gray -NoNewline

Get-Date -Format "dddd MM/dd/yyyy HH:mm K"

Write-Output ""



PowerShell .\build_project_directories.ps1

PowerShell .\build_project_management_tools.ps1

cd $BASE_DIRECTORY

PowerShell .\Run.Make.File.Builder.sh

PowerShell .\ReFactorProjectLibrary.ps1

PowerShell .\Update_Project_Binaries.ps1
