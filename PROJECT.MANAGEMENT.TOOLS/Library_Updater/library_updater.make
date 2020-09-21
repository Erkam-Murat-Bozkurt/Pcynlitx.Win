
DIR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations
CPP_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations
CHAR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator
CSYS_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Custom_System_Interface

VPATH = $(DIR_OPS) $(CPP_OPS) $(CHAR_OPS) $(CSYS_OPS)

Library_Updater: Library_Updater_Main_File.cpp Library_Updater.cpp \
	DirectoryOperations.cpp Cpp_FileOperations.cpp CharOperator.cpp Custom_System_Interface.cpp \
	Library_Updater.h DirectoryOperations.h Cpp_FileOperations.h CharOperator.h Custom_System_Interface.h

	g++ -std=c++14 -o Library_Updater.exe -I$(DIR_OPS) -I$(CPP_OPS) -I$(CHAR_OPS) -I$(CSYS_OPS) \
		-L$(DIR_OPS) -L$(CPP_OPS) -L$(CHAR_OPS) -L$(CSYS_OPS) \
		Library_Updater_Main_File.cpp Library_Updater.cpp \
		$(DIR_OPS)\DirectoryOperations.cpp $(CPP_OPS)\Cpp_FileOperations.cpp \
		$(CHAR_OPS)\CharOperator.cpp $(CSYS_OPS)\Custom_System_Interface.cpp \
		-include Library_Updater.h -include $(DIR_OPS)\DirectoryOperations.h \
		-include $(CHAR_OPS)\CharOperator.h -include $(CPP_OPS)\Cpp_FileOperations.h \
		-include $(CSYS_OPS)\Custom_System_Interface.h -lshlwapi
