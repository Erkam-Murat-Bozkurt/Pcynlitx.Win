

HEADERS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
OBJECTS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
LIBS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY
CURRENT_DIR= D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Empty_Process_Descriptor_File_Builder

VPATH = $(OBJECTS) $(HEADERS) $(LIBS) $(CURRENT_DIR)

Empty_Process_Descriptor_File_Builder.exe : Empty_Process_Descriptor_File_Builder_Main_File.cpp \
	Empty_Process_Descriptor_File_Builder.cpp Empty_Process_Descriptor_File_Builder.h Cpp_FileOperations.h \
	DirectoryOperations.h

	g++ -o Empty_Process_Descriptor_File_Builder.exe -std=c++14 -I$(HEADERS) -I$(CURRENT_DIR) -L$(LIBS) -L$(OBJECTS) \
	Empty_Process_Descriptor_File_Builder_Main_File.cpp Empty_Process_Descriptor_File_Builder.cpp \
	Empty_Process_Descriptor_File_Builder.h \
	-include Cpp_FileOperations.h -include DirectoryOperations.h -lmptools
