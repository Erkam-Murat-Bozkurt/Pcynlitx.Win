
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

Write-Output ""

Write-Output " CLASS READER INITIALIZATION LIBRARY CONTRUCTION STARTED "

Write-Output ""


cd $ClassSyntaxControlPATH

Class_Compiler.exe

Write-Output "   # ClassSyntaxControl class has been updated"

Write-Output ""


cd $ClassNameReaderPATH

Class_Compiler.exe

Write-Output "   # ClassNameReader class has been updated"

Write-Output ""



cd $MethodInitializerPATH

Class_Compiler.exe

Write-Output "   # MethodInitializer class has been updated"

Write-Output ""



cd $FindSetPointsPATH

Class_Compiler.exe

Write-Output "   # FindSetPoints class has been updated"

Write-Output ""


cd $MethodProcessorPATH

Class_Compiler.exe

Write-Output "   # MethodProcessor class has been updated"

Write-Output ""


cd $SyntaxControllerPATH

Class_Compiler.exe

Write-Output "   # SyntaxController class has been updated"

Write-Output ""



cd $ListFileOrganizerPATH

Class_Compiler.exe

Write-Output "   # ListFileOrganizer class has been updated"

Write-Output ""


cd $MethodReaderPATH

Class_Compiler.exe

Write-Output "   # MethodReader class has been updated"

Write-Output ""



cd $Included_Header_File_Names_Reader_PATH

Class_Compiler.exe

Write-Output "   # Included_Header_File_Names_Reader class has been updated"

Write-Output ""



Write-Output "   # Sub-Project has been compiled"

Write-Output ""
