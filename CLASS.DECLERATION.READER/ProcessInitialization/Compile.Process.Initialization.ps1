
$ClassSyntaxControlPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ClassSyntaxControl"

$ClassNameReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ClassNameReader"

$MethodInitializerPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodInitializer"

$FindSetPointsPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\FindSetPoints"

$MethodProcessorPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodProcessor"

$SyntaxControllerPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\SyntaxController"

$ListFileOrganizerPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ListFileOrganizer"

$MethodReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodReader"

$ProcessInitializationPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization"

$Included_Header_File_Names_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\PROJECT.MANAGEMENT.TOOLS\Included_Header_File_Names_Reader"

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"



Write-Output ""

Write-Output " CLASS READER INITIALIZATION LIBRARY CONTRUCTION STARTED "

Write-Output ""


cd $ClassSyntaxControlPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ClassSyntaxControl\ClassSyntaxControl.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ClassSyntaxControl\ClassSyntaxControl.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ClassSyntaxControl\ClassSyntaxControl.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ClassSyntaxControl class has been updated"

Write-Output ""




cd $ClassNameReaderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ClassNameReader\ClassNameReader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ClassNameReader\ClassNameReader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ClassNameReader\ClassNameReader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ClassNameReader class has been updated"

Write-Output ""



cd $MethodInitializerPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodInitializer\MethodInitializer.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodInitializer\MethodInitializer.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodInitializer\MethodInitializer.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # MethodInitializer class has been updated"

Write-Output ""



cd $FindSetPointsPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\FindSetPoints\FindSetPoints.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\FindSetPoints\FindSetPoints.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\FindSetPoints\FindSetPoints.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # FindSetPoints class has been updated"

Write-Output ""


cd $MethodProcessorPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodProcessor\MethodProcessor.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodProcessor\MethodProcessor.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodProcessor\MethodProcessor.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # MethodProcessor class has been updated"

Write-Output ""


cd $SyntaxControllerPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\SyntaxController\SyntaxController.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\SyntaxController\SyntaxController.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\SyntaxController\SyntaxController.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # SyntaxController class has been updated"

Write-Output ""



cd $ListFileOrganizerPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ListFileOrganizer\ListFileOrganizer.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ListFileOrganizer\ListFileOrganizer.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\ListFileOrganizer\ListFileOrganizer.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ListFileOrganizer class has been updated"

Write-Output ""


cd $MethodReaderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodReader\MethodReader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodReader\MethodReader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ProcessInitialization\MethodReader\MethodReader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # MethodReader class has been updated"

Write-Output ""



cd $Included_Header_File_Names_Reader_PATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\PROJECT.MANAGEMENT.TOOLS\Included_Header_File_Names_Reader\Included_Header_File_Names_Reader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\PROJECT.MANAGEMENT.TOOLS\Included_Header_File_Names_Reader\Included_Header_File_Names_Reader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\PROJECT.MANAGEMENT.TOOLS\Included_Header_File_Names_Reader\Included_Header_File_Names_Reader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # Included_Header_File_Names_Reader class has been updated"

Write-Output ""


Write-Output "   # Sub-Project has been compiled"

Write-Output ""
