

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


Write-Output ""

Write-Output "  PROGRAMMING TOOLS SOURCE CODE DOCUMENTATION STARTED"

Write-Output ""

cd $Cpp_FileOperationsPATH

Document_Builder.exe Cpp_FileOperations.h

Document_Builder.exe Cpp_FileOperations.cpp

Write-Output "   # The documentation of Cpp_FileOperations class has been performed .."


cd $CharOperatorPATH

Document_Builder.exe CharOperator.h

Document_Builder.exe CharOperator.cpp

Write-Output "   # The documentation of CharOperator class has been performed .."


cd $DirectoryOperationsPATH

Document_Builder.exe DirectoryOperations.h

Document_Builder.exe DirectoryOperations.cpp

Write-Output "   # The documentation of DirectoryOperations class has been performed .."



cd $IntToCharTranslaterPATH

Document_Builder.exe IntToCharTranslater.h

Document_Builder.exe IntToCharTranslater.cpp

Write-Output "   # The documentation of IntToCharTranslater class has been performed .."


cd $StringOperatorPATH

Document_Builder.exe StringOperator.h

Document_Builder.exe StringOperator.cpp

Write-Output "   # The documentation of StringOperator class has been performed .."




cd $Compiler_Descriptor_File_Reader_PATH

Document_Builder.exe Compiler_Descriptor_File_Reader.h

Document_Builder.exe Compiler_Descriptor_File_Reader.cpp

Write-Output "   # The documentation of Compiler_Descriptor_File_Reader class has been performed .."


cd $CompilerPATH

Document_Builder.exe Compiler.h

Document_Builder.exe Compiler.cpp

Write-Output "   # The documentation of Compiler class has been performed .."




cd $HeaderFileBuilderPATH

Document_Builder.exe HeaderFileBuilder.h

Document_Builder.exe HeaderFileBuilder.cpp

Write-Output "   # The documentation of HeaderFileBuilder class has been performed .."



cd $Custom_System_Interface_PATH

Document_Builder.exe Custom_System_Interface.h

Document_Builder.exe Custom_System_Interface.cpp

Write-Output "   # The documentation of Custom_System_Interface class has been performed .."



cd $Document_Builder_PATH

Document_Builder.exe Document_Builder.h

Document_Builder.exe Document_Builder.cpp

Write-Output "   # The documentation of Document_Builder class has been performed .."

Write-Output ""
