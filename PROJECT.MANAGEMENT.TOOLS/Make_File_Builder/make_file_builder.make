
DIR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations
CPP_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations
CHAR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator

VPATH = $(DIR_OPS) $(CPP_OPS) $(CHAR_OPS)

Make_File_Builder: Make_File_Builder_Main_File.cpp Make_File_Builder.cpp \
	DirectoryOperations.cpp Cpp_FileOperations.cpp CharOperator.cpp \
	Make_File_Builder.h DirectoryOperations.h Cpp_FileOperations.h CharOperator.h

	g++ -o Make_File_Builder.exe -I$(DIR_OPS) -I$(CPP_OPS) -I$(CHAR_OPS) \
		-L$(DIR_OPS) -L$(CPP_OPS) -L$(CHAR_OPS) \
		Make_File_Builder_Main_File.cpp Make_File_Builder.cpp \
		$(DIR_OPS)\DirectoryOperations.cpp $(CPP_OPS)\Cpp_FileOperations.cpp $(CHAR_OPS)\CharOperator.cpp \
		-include Make_File_Builder.h -include $(DIR_OPS)\DirectoryOperations.h \
		-include $(CPP_OPS)\Cpp_FileOperations.h -include $(CHAR_OPS)\CharOperator.h
