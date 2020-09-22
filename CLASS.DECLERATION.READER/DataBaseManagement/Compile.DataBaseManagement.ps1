

$Project_Headers_Files="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$MemberFunctionReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MemberFunctionReader"

$MetaDataTranslaterPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MetaDataTranslater"

Write-Output ""

Write-Output  " DATABASE MANAGEMENT LIBRARY CONTRUCTION STARTED"

Write-Output ""


cd $MemberFunctionReaderPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MemberFunctionReader\MemberFunctionReader.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MemberFunctionReader\MemberFunctionReader.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MemberFunctionReader\MemberFunctionReader.o -Destination $OBJECTS_DIRECTORY
}

Write-Output  "   # MemberFunctionReader class has been updated"

cd $MetaDataTranslaterPATH

mingw32-make -f auto_make_file.make > ..\Compiler_Output.txt

Copy-Item D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MetaDataTranslater\MetaDataTranslater.h -Destination $Project_Headers_Files

$Condition = Test-Path -Path 'D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MetaDataTranslater\MetaDataTranslater.o'

if ($Condition)
{
   Move-Item -Path D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MetaDataTranslater\MetaDataTranslater.o -Destination $OBJECTS_DIRECTORY
}

Write-Output  "   # MetaDataTranslater class has been updated"

Write-Output ""

Write-Output  "   # Sub-Project has been compiled"

Write-Output ""
