
$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

$Cpp_FileOperationsPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations"

$DirectoryOperationsPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations"

$CharOperatorPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator"

$IntToCharTranslaterPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\IntToCharTranslater"

$StringOperatorPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\StringOperator"

$Compiler_Descriptor_File_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler_Descriptor_File_Reader"

$CompilerPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Compiler"

$HeaderFileBuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\HeaderFileBuilder"

$Custom_System_Interface_PATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Custom_System_Interface"

$ToolsPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools"

Write-Output ""

Write-Output "  PROGRAMMING TOOLS AUTO-MAKE FILE CONSTRUCTION STARTED"

Write-Output ""

cd $Cpp_FileOperationsPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Cpp_FileOperations class .."


cd $CharOperatorPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for CharOperator class .."


cd $DirectoryOperationsPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for DirectoryOperations class .."




cd $IntToCharTranslaterPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for IntToCharTranslater class .."


cd $StringOperatorPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for StringOperator class .."



cd $Compiler_Descriptor_File_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Compiler_Descriptor_File_Reader class .."


cd $CompilerPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Compiler class .."



cd $HeaderFileBuilderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for HeaderFileBuilder class .."


cd $Custom_System_Interface_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Custom_System_Interface class .."

Write-Output ""
