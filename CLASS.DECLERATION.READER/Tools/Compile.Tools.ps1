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

Write-Output "  PROGRAMMING TOOLS LIBRARY CONTRUCTION STARTED"

Write-Output ""

cd $Cpp_FileOperationsPATH

Class_Compiler.exe

Write-Output "   # Cpp_FileOperations class has been compiled .. "


cd $CharOperatorPATH

Class_Compiler.exe

Write-Output "   # CharOperator class has been compiled .."



cd $DirectoryOperationsPATH

Class_Compiler.exe

Write-Output "   # DirectoryOperations class has been compiled "



cd $IntToCharTranslaterPATH

Class_Compiler.exe

Write-Output "   # IntToCharTranslater class has been compiled"


cd $StringOperatorPATH

Class_Compiler.exe

Write-Output "   # StringOperator class has been compiled"


cd $Compiler_Descriptor_File_Reader_PATH

Class_Compiler.exe

Write-Output "   # Compiler_Descriptor_File_Reader has been compiled "


cd $CompilerPATH

Class_Compiler.exe

Write-Output "   # Compiler class has been compiled "


cd $HeaderFileBuilderPATH

Class_Compiler.exe

Write-Output "   # HeaderFileBuilder class has been compiled"


cd $Custom_System_Interface_PATH

Class_Compiler.exe

Write-Output "   # Custom_System_Interface class has been compiled "

Write-Output "   # Sub-Project has been compiled"

Write-Output ""
