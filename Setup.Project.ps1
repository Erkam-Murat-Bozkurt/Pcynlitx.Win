$BASE_DIRECTORY="D:\PCYNLITX.PROJECT.WINDOWS"

$PROJECT_MANAGEMENT_TOOLS="D:\PCYNLITX.PROJECT.WINDOWS\PROJECT.MANAGEMENT.TOOLS"

cd $PROJECT_MANAGEMENT_TOOLS


Write-Output ""

Write-Output ""

Write-Output " ------------------------------------------------------------------"

Write-Output ""

Write-Output "    PCYNLITX WINDOWS PROJECT SETUP SCRIPT STARTED ITS EXECUTIONS   "

Write-Output ""

Write-Output " ------------------------------------------------------------------"

Write-Output ""


PowerShell .\build_project_directories.ps1

PowerShell .\build_project_management_tools.ps1

cd $BASE_DIRECTORY

PowerShell .\ReFactorProjectLibrary.ps1

PowerShell .\Update_Project_Binaries.ps1
