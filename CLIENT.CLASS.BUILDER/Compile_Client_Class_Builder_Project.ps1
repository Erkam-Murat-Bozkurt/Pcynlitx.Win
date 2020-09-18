

$ClassRebuilder_InitializerPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Initializer"

$ClassRebuilder_Data_CollectorPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Data_Collector"

$HeaderRebuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\HeaderRebuilder"

$ClassRebuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder"

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"


Write-Output ""

Write-Output " CLIENT.CLASS.BUILDER COMPILE PROCESS HAS BEEN STARTED"

Write-Output ""



cd $ClassRebuilder_InitializerPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Initializer\ClassRebuilder_Initializer.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Initializer\ClassRebuilder_Initializer.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Initializer\ClassRebuilder_Initializer.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ClassRebuilder_Initializer class has been compiled"


cd $ClassRebuilder_Data_CollectorPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Data_Collector\ClassRebuilder_Data_Collector.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Data_Collector\ClassRebuilder_Data_Collector.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Data_Collector\ClassRebuilder_Data_Collector.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ClassRebuilder_Data_Collector class has been compiled"


cd $HeaderRebuilderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\HeaderRebuilder\HeaderRebuilder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\HeaderRebuilder\HeaderRebuilder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\HeaderRebuilder\HeaderRebuilder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # HeaderRebuilder class has been compiled"


cd $ClassRebuilderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder\ClassRebuilder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder\ClassRebuilder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder\ClassRebuilder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ClassRebuilder class has been compiled"

Write-Output "   # Sub-Project has been compiled"

Write-Output ""
