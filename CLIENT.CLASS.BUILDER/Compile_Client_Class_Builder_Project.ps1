

$ClassRebuilder_InitializerPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Initializer"

$ClassRebuilder_Data_CollectorPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder_Data_Collector"

$HeaderRebuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\HeaderRebuilder"

$ClassRebuilderPATH="D:\PCYNLITX.PROJECT.WINDOWS\CLIENT.CLASS.BUILDER\ClassRebuilder"


Write-Output ""

Write-Output " CLIENT.CLASS.BUILDER COMPILE PROCESS HAS BEEN STARTED"

Write-Output ""

cd $ClassRebuilder_InitializerPATH

Class_Compiler.exe


Write-Output "   # ClassRebuilder_Initializer class has been compiled"


cd $ClassRebuilder_Data_CollectorPATH

Class_Compiler.exe

Write-Output "   # ClassRebuilder_Data_Collector class has been compiled"


cd $HeaderRebuilderPATH

Class_Compiler.exe

Write-Output "   # HeaderRebuilder class has been compiled"


cd $ClassRebuilderPATH

Class_Compiler.exe

Write-Output "   # ClassRebuilder class has been compiled"

Write-Output "   # Sub-Project has been compiled"

Write-Output ""
