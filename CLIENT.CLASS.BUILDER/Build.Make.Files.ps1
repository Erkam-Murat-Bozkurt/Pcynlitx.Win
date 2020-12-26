

$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

$ClassRebuilder_InitializerPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Initializer"

$ClassRebuilder_Data_CollectorPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Data_Collector"

$HeaderRebuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\HeaderRebuilder"

$ClassRebuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder"


Write-Output ""

Write-Output "  CLIENT.CLASS.BUILDER MAKE-FILE CONSTRUCTION STARTED"

Write-Output ""


cd $ClassRebuilder_InitializerPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ClassRebuilder_Initializer class"



cd $ClassRebuilder_Data_CollectorPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ClassRebuilder_Data_Collector class"


cd $HeaderRebuilderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for HeaderRebuilder class"


cd $ClassRebuilderPATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for ClassRebuilder class"

Write-Output ""
