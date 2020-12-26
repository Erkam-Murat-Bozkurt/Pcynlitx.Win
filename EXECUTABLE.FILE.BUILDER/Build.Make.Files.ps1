

$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

$Compiler_Descriptor_File_Constructor_PATH="D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\Compiler_Descriptor_File_Constructor"

$MT_Project_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\MT_Project_Builder"


Write-Output ""

Write-Output "  EXECUTABLE FILE BUILDER MAKE-FILE CONSTRUCTION STARTED"

Write-Output ""


cd $Compiler_Descriptor_File_Constructor_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Compiler_Descriptor_File_Constructor class"


cd $MT_Project_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MT_Project_Builder class"

Write-Output ""
