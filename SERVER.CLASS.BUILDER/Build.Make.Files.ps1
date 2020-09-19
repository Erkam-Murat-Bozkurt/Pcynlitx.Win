

$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

$Inter_Thread_Data_Structure_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Inter_Thread_Data_Structure_Builder"

$Thread_Locker_Header_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Header_File_Builder"

$Thread_Locker_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Locker_Builder"

$Thread_Data_Manager_Header_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Header_Builder"

$Thread_Data_Manager_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Data_Manager_Builder"

$Thread_Manager_Header_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Header_File_Builder"

$Thread_Manager_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Thread_Manager_Builder"

$TM_Client_Header_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Header_Builder"

$TM_Client_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\TM_Client_Builder"

$Server_Header_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Header_File_Builder"

$Server_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Server_Builder"

$Main_File_Builder_PATH="D:\PCYNLITX.PROJECT.WINDOWS\SERVER.CLASS.BUILDER\Main_File_Builder"

Write-Output ""

Write-Output "  SERVER CLASS BUILDER PROJECT COMPILE PROCESS HAS BEEN STARTED"

Write-Output ""

cd $Inter_Thread_Data_Structure_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Inter_Thread_Data_Structure_Builder"


cd $Thread_Locker_Header_File_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Thread_Locker_Header_File_Builder"



cd $Thread_Locker_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Thread_Locker_Builder"



cd $Thread_Data_Manager_Header_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Thread_Data_Manager_Header_Builder"


cd $Thread_Data_Manager_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Thread_Data_Manager_Builder"



cd $Thread_Manager_Header_File_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Thread_Data_Manager_Header_Builder"




cd $Thread_Manager_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Thread_Manager_Builder"



cd $TM_Client_Header_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for TM_Client_Header_Builder"


cd $TM_Client_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for TM_Client_Builder"



cd $Server_Header_File_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Server_Header_File_Builder"



cd $Server_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Server_Builder"


cd $Main_File_Builder_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Main_File_Builder"

Write-Output ""
