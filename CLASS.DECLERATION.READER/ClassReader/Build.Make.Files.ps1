
$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

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

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MethodListInterpreter class"




cd $MethodListReaderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MethodListReader class"




cd $ParenthesReaderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ParenthesReader class"


cd $MethodReceiverPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ParenthesReader class"



cd $ReturnTypeReaderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ReturnTypeReader class"


cd $NameReaderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for NameReader class"


cd $ParameterReaderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ParameterReader class"


cd $MethodInterpreterPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MethodInterpreter class"


cd $DataBaseBuilderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for DataBaseBuilder class"



Write-Output "   # Sub-Project has been compiled"

Write-Output ""
