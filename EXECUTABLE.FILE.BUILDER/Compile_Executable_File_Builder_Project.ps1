
$Compiler_Descriptor_File_Constructor_PATH="D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\Compiler_Descriptor_File_Constructor"

$MT_Project_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\MT_Project_Builder"


Write-Output ""

Write-Output "  EXECUTABLE FILE BULDER COMPILE PROCESS HAS BEEN STARTED"

Write-Output ""

cd $Compiler_Descriptor_File_Constructor_PATH

Class_Compiler.exe

Write-Output "   # Compiler_Descriptor_File_Constructor class has been compiled"


cd $MT_Project_Builder_PATH

Class_Compiler.exe

Write-Output "   #  MT_Project_Builder class has been compiled"

Write-Output "   #  Sub-Project has been compiled"

Write-Output ""
