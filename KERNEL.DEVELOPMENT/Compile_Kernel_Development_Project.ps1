
$Kernel_Data_Collector_PATH="D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel_Data_Collector"

$Kernel_PATH="D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel"

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"




Write-Output ""

Write-Host "   Kernel development project compile process has been started" -ForegroundColor Cyan;

Write-Output ""

cd $Kernel_Data_Collector_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel_Data_Collector\Kernel_Data_Collector.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel_Data_Collector\Kernel_Data_Collector.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Kernel_Data_Collector.o'

  if ($Exists_On_Obj_Dir){

      rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Kernel_Data_Collector.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel_Data_Collector\Kernel_Data_Collector.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Kernel_Data_Collector class has been compiled"


cd $Kernel_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel\Kernel.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel\Kernel.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Kernel.o'

  if ($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Kernel.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel\Kernel.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Kernel class has been compiled"

Write-Output ""
