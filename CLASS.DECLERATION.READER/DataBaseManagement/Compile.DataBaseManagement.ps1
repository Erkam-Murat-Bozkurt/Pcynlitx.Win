
$MemberFunctionReaderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MemberFunctionReader"

$MetaDataTranslaterPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\DataBaseManagement\MetaDataTranslater"

Write-Output ""

Write-Output  " DATABASE MANAGEMENT LIBRARY CONTRUCTION STARTED"

Write-Output ""


cd $MemberFunctionReaderPATH

Class_Compiler.exe

Write-Output  "   # MemberFunctionReader class has been updated"

cd $MetaDataTranslaterPATH

Class_Compiler.exe

Write-Output  "   # MetaDataTranslater class has been updated"

Write-Output  "   # Sub-Project has been compiled"

Write-Output ""
