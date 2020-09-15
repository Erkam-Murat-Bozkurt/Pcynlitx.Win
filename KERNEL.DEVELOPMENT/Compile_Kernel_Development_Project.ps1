
$Kernel_Data_Collector_PATH="D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel_Data_Collector"

$Kernel_PATH="D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel"

Write-Output ""

Write-Output "  KERNEL DEVELOPMENT PROJECT COMPILE PROCESS HAS BEEN STARTED"

Write-Output ""

cd $Kernel_Data_Collector_PATH

Class_Compiler.exe

Write-Output "   # Kernel_Data_Collector class has been compiled"


cd $Kernel_PATH

Class_Compiler.exe


Write-Output "   # Kernel class has been compiled"

Write-Output "   # Sub-Project has been compiled"

Write-Output ""
