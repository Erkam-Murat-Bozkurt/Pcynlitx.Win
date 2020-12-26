
$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

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

Write-Output "  CLASS READER INITIALIZATION LIBRARY CONSTRUCTION STARTED "

Write-Output ""


cd $ClassSyntaxControlPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ClassSyntaxControl class"



cd $ClassNameReaderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ClassNameReader class"



cd $MethodInitializerPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MethodInitializer class"



cd $FindSetPointsPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for FindSetPoints class"



cd $MethodProcessorPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MethodProcessor class"


cd $SyntaxControllerPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for SyntaxController class"


cd $ListFileOrganizerPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ListFileOrganizer class"



cd $MethodReaderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for MethodReader class"



cd $Included_Header_File_Names_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Included_Header_File_Names_Reader class"

Write-Output ""
