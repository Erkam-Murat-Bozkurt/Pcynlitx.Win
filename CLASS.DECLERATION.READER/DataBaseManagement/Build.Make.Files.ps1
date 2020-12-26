

$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

$MemberFunctionReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MemberFunctionReader"

$MetaDataTranslaterPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MetaDataTranslater"

Write-Output ""

Write-Output  "  DATABASE MANAGEMENT LIBRARY CONSTRUCTION STARTED"

Write-Output ""


cd $MemberFunctionReaderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MemberFunctionReader class"


cd $MetaDataTranslaterPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MetaDataTranslater class"

Write-Output ""
