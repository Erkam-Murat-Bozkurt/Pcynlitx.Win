
HEADERS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
OBJECTS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
LIBS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY
CURRENT_DIR=D:\PCYNLITX.PROJECT.WINDOWS\EXECUTABLE.FILE.BUILDER\MT_Project_Builder

VPATH = $(OBJECTS) $(HEADERS) $(LIBS) $(CURRENT_DIR)

MT_Project_Builder.exe : MT_Project_Builder_Main_File.cpp MT_Project_Builder.cpp \
  MT_Project_Builder.h Descriptor_File_Reader.h \
	Compiler_Descriptor_File_Constructor.h Compiler.h \
	DirectoryOperations.h Cpp_FileOperations.h

	g++ -o MT_Project_Builder.exe -std=c++14 -I$(HEADERS) -I$(CURRENT_DIR) \
	-L$(OBJECTS) -L$(LIBS) -L$(CURRENT_DIR) \
	MT_Project_Builder_Main_File.cpp MT_Project_Builder.cpp MT_Project_Builder.h \
	 -include Descriptor_File_Reader.h \
	 -include Compiler_Descriptor_File_Constructor.h -include Compiler.h \
	 -include DirectoryOperations.h -include Cpp_FileOperations.h -lmptools
