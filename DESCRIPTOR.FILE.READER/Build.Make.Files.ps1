

$HEADERS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES"

$OBJECTS_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES"

$LIBRARY_DIRECTORY="D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY"

$Descriptor_File_Data_Collector_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Data_Collector"

$Descriptor_File_Reader_Initializer_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Reader_Initializer"

$Descriptor_File_Number_Processor_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Number_Processor"

$Include_Directory_Description_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Include_Directory_Description_Reader"

$Inter_Thread_Class_Description_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Inter_Thread_Class_Description_Reader"

$Inter_Thread_Data_Type_Description_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Inter_Thread_Data_Type_Description_Reader"

$Source_File_Descriptions_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Source_File_Descriptions_Reader"

$Header_File_Descriptions_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Header_File_Descriptions_Reader"

$Library_Descriptions_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Library_Descriptions_Reader"

$Main_File_Descriptions_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Main_File_Descriptions_Reader"

$Descriptor_File_Reader_Syntax_Controller_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Reader_Syntax_Controller"

$Descriptor_File_Reader_PATH="D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Reader"


Write-Output ""

Write-Output "  DESCRIPTOR FILE READER COMPILE PROCESS STARTED"


cd $Descriptor_File_Data_Collector_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Descriptor_File_Data_Collector class"


cd $Descriptor_File_Reader_Initializer_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Descriptor_File_Reader_Initializer class"


cd $Descriptor_File_Number_Processor_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Descriptor_File_Reader_Initializer class"


cd $Include_Directory_Description_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Include_Directory_Description_Reader class"


cd $Inter_Thread_Class_Description_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Inter_Thread_Class_Description_Reader class"



cd $Inter_Thread_Data_Type_Description_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Inter_Thread_Data_Type_Description_Reader class"


cd $Source_File_Descriptions_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Source_File_Descriptions_Reader class"


cd $Header_File_Descriptions_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Header_File_Descriptions_Reader class"


cd $Library_Descriptions_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Library_Descriptions_Reader class"


cd $Main_File_Descriptions_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Main_File_Descriptions_Reader class"


cd $Descriptor_File_Reader_Syntax_Controller_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Descriptor_File_Reader_Syntax_Controller class"


cd $Descriptor_File_Reader_PATH

Make_File_Builder.exe  $HEADERS_DIRECTORY $OBJECTS_DIRECTORY $LIBRARY_DIRECTORY mptools

Write-Output "   # A make file has been derived for Descriptor_File_Reader class"

Write-Output "   # Sub-Project has been compiled"

Write-Output ""
