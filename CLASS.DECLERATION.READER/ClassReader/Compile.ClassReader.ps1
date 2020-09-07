

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

Write-Output ""

Write-Output  " CLASS READER LIBRARY CONTRUCTION STARTED"

Write-Output ""

cd $MethodListInterpreterPATH

Class_Compiler.exe

Write-Output "   # MethodListInterpreter class has been compiled"


cd $MethodListReaderPATH

Class_Compiler.exe

Write-Output "   # MethodListReader class has been compiled"


cd $ParenthesReaderPATH

Class_Compiler.exe

Write-Output "   # ParenthesReader class has been compiled"


cd $MethodReceiverPATH

Class_Compiler.exe

Write-Output "   # MethodReceiver class has been compiled"


cd $ReturnTypeReaderPATH

Class_Compiler.exe

Write-Output "   # ReturnTypeReader class has been compiled"


cd $NameReaderPATH

Class_Compiler.exe

Write-Output "   # NameReader class has been compiled"


cd $ParameterReaderPATH

Class_Compiler.exe

Write-Output "   # ParameterReader class has been compiled"


cd $MethodInterpreterPATH

Class_Compiler.exe

Write-Output "   # MethodInterpreter class has been compiled"


cd $DataBaseBuilderPATH

Class_Compiler.exe

Write-Output "   # DataBaseBuilder class has been compiled"



Write-Output "   # Sub-Project has been compiled"

Write-Output ""
