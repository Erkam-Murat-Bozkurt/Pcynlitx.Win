
$Inter_Thread_Data_Structure_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Inter_Thread_Data_Structure_Builder"

$Thread_Locker_Header_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Header_File_Builder"

$Thread_Locker_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Builder"

$Thread_Data_Manager_Header_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Header_Builder"

$Thread_Data_Manager_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Builder"

$Thread_Manager_Header_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Header_File_Builder"

$Thread_Manager_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Builder"

$TM_Client_Header_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Header_Builder"

$TM_Client_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Builder"

$Server_Header_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Header_File_Builder"

$Server_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Builder"

$Main_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Main_File_Builder"

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"



Write-Output ""

Write-Output "  SERVER CLASS BUILDER PROJECT COMPILE PROCESS HAS BEEN STARTED"

Write-Output ""

cd $Inter_Thread_Data_Structure_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Inter_Thread_Data_Structure_Builder\Inter_Thread_Data_Structure_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Inter_Thread_Data_Structure_Builder\Inter_Thread_Data_Structure_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Inter_Thread_Data_Structure_Builder\Inter_Thread_Data_Structure_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Inter_Thread_Data_Structure_Builder class has been compiled"


cd $Thread_Locker_Header_File_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Header_File_Builder\Thread_Locker_Header_File_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Header_File_Builder\Thread_Locker_Header_File_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Header_File_Builder\Thread_Locker_Header_File_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Thread_Locker_Header_File_Builder class has been compiled"


cd $Thread_Locker_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Builder\Thread_Locker_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Builder\Thread_Locker_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Builder\Thread_Locker_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Thread_Locker_Builder class has been compiled"


cd $Thread_Data_Manager_Header_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Header_Builder\Thread_Data_Manager_Header_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Header_Builder\Thread_Data_Manager_Header_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Header_Builder\Thread_Data_Manager_Header_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Thread_Data_Manager_Header_Builder class has been compiled"



cd $Thread_Data_Manager_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Builder\Thread_Data_Manager_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Builder\Thread_Data_Manager_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Builder\Thread_Data_Manager_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Thread_Data_Manager_Builder class has been compiled"


cd $Thread_Manager_Header_File_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Header_File_Builder\Thread_Manager_Header_File_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Header_File_Builder\Thread_Manager_Header_File_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Header_File_Builder\Thread_Manager_Header_File_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Thread_Manager_Header_File_Builder class has been compiled"



cd $Thread_Manager_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Builder\Thread_Manager_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Builder\Thread_Manager_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Builder\Thread_Manager_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Thread_Manager_Builder class has been compiled"


cd $TM_Client_Header_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Header_Builder\TM_Client_Header_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Header_Builder\TM_Client_Header_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Header_Builder\TM_Client_Header_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # TM_Client_Header_Builder class has been compiled"


cd $TM_Client_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Builder\TM_Client_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Builder\TM_Client_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Builder\TM_Client_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # TM_Client_Builder class has been compiled"


cd $Server_Header_File_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Header_File_Builder\Server_Header_File_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Header_File_Builder\Server_Header_File_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Header_File_Builder\Server_Header_File_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Server_Header_File_Builder class has been compiled"


cd $Server_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Builder\Server_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Builder\Server_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Builder\Server_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Server_Builder class has been compiled"


cd $Main_File_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Main_File_Builder\Main_File_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Main_File_Builder\Main_File_Builder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Main_File_Builder\Main_File_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Main_File_Builder class has been compiled"

Write-Output ""
