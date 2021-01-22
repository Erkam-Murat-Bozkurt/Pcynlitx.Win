

$Cpp_FileOperationsPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations"

$DirectoryOperationsPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations"

$CharOperatorPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator"

$IntToCharTranslaterPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\IntToCharTranslater"

$StringOperatorPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\StringOperator"

$Compiler_Descriptor_File_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler_Descriptor_File_Reader"

$CompilerPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler"

$HeaderFileBuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\HeaderFileBuilder"

$Custom_System_Interface_PATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Custom_System_Interface"

$Document_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Document_Builder"

$ToolsPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools"

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"



Write-Output ""

Write-Host "   Programmer tools library construction started" -ForegroundColor Cyan;

Write-Output ""

cd $Cpp_FileOperationsPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations\Cpp_FileOperations.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations\Cpp_FileOperations.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Cpp_FileOperations.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Cpp_FileOperations.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations\Cpp_FileOperations.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Cpp_FileOperations class has been compiled"


cd $CharOperatorPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator\CharOperator.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator\CharOperator.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\CharOperator.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\CharOperator.o'
  }

   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator\CharOperator.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # CharOperator class has been compiled"



cd $DirectoryOperationsPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations\DirectoryOperations.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations\DirectoryOperations.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\DirectoryOperations.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\DirectoryOperations.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations\DirectoryOperations.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # DirectoryOperations class has been compiled "



cd $IntToCharTranslaterPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\IntToCharTranslater\IntToCharTranslater.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\IntToCharTranslater\IntToCharTranslater.o'

if ($Condition)
{
   $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\IntToCharTranslater.o'

   if($Exists_On_Obj_Dir){

      rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\IntToCharTranslater.o'
   }

   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\IntToCharTranslater\IntToCharTranslater.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # IntToCharTranslater class has been compiled"


cd $StringOperatorPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\StringOperator\StringOperator.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\StringOperator\StringOperator.o'

if ($Condition)
{
   $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\StringOperator.o'

   if($Exists_On_Obj_Dir){

      rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\StringOperator.o'
   }

   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\StringOperator\StringOperator.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # StringOperator class has been compiled"


cd $Compiler_Descriptor_File_Reader_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler_Descriptor_File_Reader\Compiler_Descriptor_File_Reader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler_Descriptor_File_Reader\Compiler_Descriptor_File_Reader.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Compiler_Descriptor_File_Reader.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Compiler_Descriptor_File_Reader.o'
  }

   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler_Descriptor_File_Reader\Compiler_Descriptor_File_Reader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Compiler_Descriptor_File_Reader has been compiled "


cd $CompilerPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler\Compiler.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler\Compiler.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Compiler.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Compiler.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler\Compiler.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Compiler class has been compiled "


cd $HeaderFileBuilderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\HeaderFileBuilder\HeaderFileBuilder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\HeaderFileBuilder\HeaderFileBuilder.o'

if ($Condition)
{
   $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\HeaderFileBuilder.o'

   if($Exists_On_Obj_Dir){

      rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\HeaderFileBuilder.o'
   }

   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\HeaderFileBuilder\HeaderFileBuilder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # HeaderFileBuilder class has been compiled"




cd $Custom_System_Interface_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Custom_System_Interface\Custom_System_Interface.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Custom_System_Interface\Custom_System_Interface.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Custom_System_Interface.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Custom_System_Interface.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Custom_System_Interface\Custom_System_Interface.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Custom_System_Interface class has been compiled "




cd $Document_Builder_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Document_Builder\Document_Builder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Document_Builder\Document_Builder.o'

if ($Condition)
{
  $Exists_On_Obj_Dir = Test-Path -Path 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Document_Builder.o'

  if($Exists_On_Obj_Dir){

     rm 'D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES\Document_Builder.o'
  }

  Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Document_Builder\Document_Builder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output ""

Write-Output "   # Document_Builder class has been compiled "

Write-Output ""

Write-Host "   # The construction of the Document_Builder started .." -ForegroundColor Magenta

Write-Output ""

mingw32-make -f document_builder.make > Compiler_Output.txt


$Condition = Test-Path -Path 'D:\Pcynlitx_Binaries\Document_Builder.exe'

if ($Condition )
{
     rm D:\Pcynlitx_Binaries\Document_Builder.exe
}

mv Document_Builder.exe D:\Pcynlitx_Binaries

Write-Output ""

Write-Output "   Document_Builder has been constructed :-)"

Write-Output ""

Write-Output ""

Write-Output "   # Sub-Project has been compiled"

Write-Output ""
