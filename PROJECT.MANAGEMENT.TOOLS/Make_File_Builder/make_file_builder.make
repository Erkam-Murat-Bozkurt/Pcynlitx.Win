
ID=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
OD=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
LD=D:\PCYNLITX.WIND.IMPL.LIBRARY\PCYNLITX.PROJECT.LIBRARY\PROJECT.LIBRARY
DIR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\DirectoryOperations
CPP_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\Cpp_FileOperations
CHAR_OPS=D:\PCYNLITX.PROJECT.WINDOWS\CLASS.DECLERATION.READER\Tools\CharOperator

VPATH = $(ID) $(DIR_OPS) $(CPP_OPS) $(CHAR_OPS) $(OD) $(LD) $(DIR_OPS) $(CPP_OPS) $(CHAR_OPS)

Make_File_Builder: Make_File_Builder_Main_File.cpp Make_File_Builder.cpp \
	DirectoryOperations.cpp Cpp_FileOperations.cpp CharOperator.cpp \
	Make_File_Builder.h DirectoryOperations.h Cpp_FileOperations.h CharOperator.h

	g++ -o Make_File_Builder.exe -I$(ID) -I$(DIR_OPS) -I$(CPP_OPS) -I$(CHAR_OPS) -L$(OD) -L$(LD) \
		-L$(DIR_OPS) -L$(CPP_OPS) -L$(CHAR_OPS) \
		Make_File_Builder_Main_File.cpp Make_File_Builder.cpp \
		$(DIR_OPS)\DirectoryOperations.cpp $(CPP_OPS)\Cpp_FileOperations.cpp $(CHAR_OPS)\CharOperator.cpp \
		-include Make_File_Builder.h -include DirectoryOperations.h \
		-include Cpp_FileOperations.h -include CharOperator.h
