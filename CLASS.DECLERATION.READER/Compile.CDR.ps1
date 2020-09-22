
$ToolsPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools"

$ProcessInitializationPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization"

$ClassReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader"

$DataBaseManagementPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement"

cd $ToolsPATH

PowerShell .\Compile.Tools.ps1

cd $ProcessInitializationPATH

PowerShell .\Compile.Process.Initialization.ps1

cd $ClassReaderPATH

PowerShell .\Compile.ClassReader.ps1

cd $DataBaseManagementPATH

PowerShell .\Compile.DataBaseManagement.ps1
