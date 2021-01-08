
HEADERS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
OBJECTS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
LIBS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY
CURRENT_DIR= D:\PCYNLITX.PROJECT.WINDOWS\KERNEL.DEVELOPMENT\Kernel

VPATH = $(OBJECTS) $(HEADERS) $(LIBS) $(CURRENT_DIR)

Kernel.exe : Kernel_Main_File.cpp Kernel.cpp Kernel.h Cpp_FileOperations.h ClassRebuilder.h \
   Inter_Thread_Data_Structure_Builder.h Multi_Thread_Pointer_Builder.h \
	 Multi_Thread_Pointer_Client_Builder.h Descriptor_File_Reader.h \
	 Server_Builder.h Multi_Thread_Pointer_File_Data_Collector.h Thread_Manager_Builder.h\
	 TM_Client_Builder.h Main_File_Builder.h Kernel_Data_Collector.h \
	 IntToCharTranslater.h

	g++ -o Kernel.exe -std=c++17 -I$(HEADERS) -I$(CURRENT_DIR) -L$(OBJECTS) -L$(LIBS) \
	Kernel_Main_File.cpp Kernel.cpp Kernel.h -include Cpp_FileOperations.h  -include ClassRebuilder.h \
	-include Inter_Thread_Data_Structure_Builder.h \
	-include Multi_Thread_Pointer_Builder.h -include Multi_Thread_Pointer_Client_Builder.h \
	-include Descriptor_File_Reader.h -include Server_Builder.h \
	-include Multi_Thread_Pointer_File_Data_Collector.h  -include Thread_Manager_Builder.h \
	-include TM_Client_Builder.h -include Main_File_Builder.h \
	-include Kernel_Data_Collector.h -include IntToCharTranslater.h \
	-lmptools -lshlwapi
