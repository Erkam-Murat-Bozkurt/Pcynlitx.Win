

DIR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations
CSI_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Custom_System_Interface
CHAR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator
CPP_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations

VPATH = $(DIR_OPS) $(CPP_OPS) $(CHAR_OPS) $(CSI_OPS) $(CPP_OPS)

Class_Compiler: Class_Compiler_Main_File.cpp Class_Compiler.cpp \
	DirectoryOperations.cpp Custom_System_Interface.cpp CharOperator.cpp Cpp_FileOperations.cpp \
	Class_Compiler.h DirectoryOperations.h Custom_System_Interface.h CharOperator.h Cpp_FileOperations.h

	g++ -o Class_Compiler.exe -I$(DIR_OPS) -I$(CSI_OPS) -I$(CHAR_OPS) -I$(CPP_OPS) \
	  -L$(DIR_OPS) -L$(CSI_OPS) -L$(CHAR_OPS) -L$(CPP_OPS) \
		Class_Compiler_Main_File.cpp Class_Compiler.cpp \
		$(DIR_OPS)\DirectoryOperations.cpp $(CSI_OPS)\Custom_System_Interface.cpp \
		$(CHAR_OPS)\CharOperator.cpp $(CPP_OPS)\Cpp_FileOperations.cpp \
		-include Class_Compiler.h -include $(DIR_OPS)\DirectoryOperations.h \
		-include $(CSI_OPS)\Custom_System_Interface.h -include $(CHAR_OPS)\CharOperator.h \
		-include $(CPP_OPS)\Cpp_FileOperations.h
