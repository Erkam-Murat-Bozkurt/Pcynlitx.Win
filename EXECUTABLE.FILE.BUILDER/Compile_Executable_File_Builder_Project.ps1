

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$Compiler_Descriptor_File_Constructor_PATH="D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\Compiler_Descriptor_File_Constructor"

$MT_Project_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\MT_Project_Builder"


Write-Output ""

Write-Host "   Executable file builder compile process has been started" -ForegroundColor Cyan;

Write-Output ""

cd $Compiler_Descriptor_File_Constructor_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\Compiler_Descriptor_File_Constructor\Compiler_Descriptor_File_Constructor.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\Compiler_Descriptor_File_Constructor\Compiler_Descriptor_File_Constructor.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Compiler_Descriptor_File_Constructor.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Compiler_Descriptor_File_Constructor.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\Compiler_Descriptor_File_Constructor\Compiler_Descriptor_File_Constructor.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Compiler_Descriptor_File_Constructor class has been compiled"


cd $MT_Project_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\MT_Project_Builder\MT_Project_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\MT_Project_Builder\MT_Project_Builder.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\MT_Project_Builder.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\MT_Project_Builder.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\MT_Project_Builder\MT_Project_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # MT_Project_Builder class has been compiled"

Write-Output "   # Sub-Project has been compiled"

Write-Output ""
