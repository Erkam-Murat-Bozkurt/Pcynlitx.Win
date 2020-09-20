
ID=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
OD=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
LD=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY
DIR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations
CPP_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations
CHAR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator
CSYS_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Custom_System_Interface

VPATH = $(ID) $(DIR_OPS) $(CPP_OPS) $(CHAR_OPS) $(CSYS_OPS) $(OD) $(LD) $(DIR_OPS) $(CPP_OPS) $(CHAR_OPS)

Library_Updater: Library_Updater_Main_File.cpp Library_Updater.cpp \
	DirectoryOperations.cpp Cpp_FileOperations.cpp CharOperator.cpp \
	Library_Updater.h DirectoryOperations.h Cpp_FileOperations.h CharOperator.h

	g++ -std=c++14 -o Library_Updater.exe -I$(ID) -L$(OD) -L$(LD) \
		Library_Updater_Main_File.cpp Library_Updater.cpp \
		$(DIR_OPS)\DirectoryOperations.cpp $(CPP_OPS)\Cpp_FileOperations.cpp \
		$(CHAR_OPS)\CharOperator.cpp $(CSYS_OPS)\Custom_System_Interface.cpp \
		-include Library_Updater.h -include DirectoryOperations.h \
		-include Cpp_FileOperations.h -include CharOperator.h -include Custom_System_Interface.h -lshlwapi
