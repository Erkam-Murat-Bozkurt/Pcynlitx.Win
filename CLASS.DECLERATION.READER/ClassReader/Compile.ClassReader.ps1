

$MethodListInterpreterPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodListInterpreter"

$MethodListReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodListReader"

$ParenthesReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ParenthesReader"

$MethodReceiverPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodReceiver"

$ReturnTypeReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ReturnTypeReader"

$NameReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\NameReader"

$ParameterReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ParameterReader"

$MethodInterpreterPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodInterpreter"

$DataBaseBuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\DataBaseBuilder"

$ClassReaderProjectPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader"

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"



Write-Output ""

Write-Output  " CLASS READER LIBRARY CONTRUCTION STARTED"

Write-Output ""

cd $MethodListInterpreterPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodListInterpreter\MethodListInterpreter.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodListInterpreter\MethodListInterpreter.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodListInterpreter\MethodListInterpreter.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # MethodListInterpreter class has been compiled"


cd $MethodListReaderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodListReader\MethodListReader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodListReader\MethodListReader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodListReader\MethodListReader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # MethodListReader class has been compiled"


cd $ParenthesReaderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ParenthesReader\ParenthesReader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ParenthesReader\ParenthesReader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ParenthesReader\ParenthesReader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ParenthesReader class has been compiled"


cd $MethodReceiverPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodReceiver\MethodReceiver.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodReceiver\MethodReceiver.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodReceiver\MethodReceiver.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # MethodReceiver class has been compiled"


cd $ReturnTypeReaderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ReturnTypeReader\ReturnTypeReader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ReturnTypeReader\ReturnTypeReader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ReturnTypeReader\ReturnTypeReader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ReturnTypeReader class has been compiled"


cd $NameReaderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\NameReader\NameReader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\NameReader\NameReader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\NameReader\NameReader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # NameReader class has been compiled"


cd $ParameterReaderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ParameterReader\ParameterReader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ParameterReader\ParameterReader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\ParameterReader\ParameterReader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # ParameterReader class has been compiled"


cd $MethodInterpreterPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodInterpreter\MethodInterpreter.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodInterpreter\MethodInterpreter.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\MethodInterpreter\MethodInterpreter.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # MethodInterpreter class has been compiled"


cd $DataBaseBuilderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\DataBaseBuilder\DataBaseBuilder.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\DataBaseBuilder\DataBaseBuilder.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\ClassReader\DataBaseBuilder\DataBaseBuilder.o -Destination $OBJECTS_DIRECTORY
}

Write-Output "   # DataBaseBuilder class has been compiled"


Write-Output "   # Sub-Project has been compiled"

Write-Output ""
