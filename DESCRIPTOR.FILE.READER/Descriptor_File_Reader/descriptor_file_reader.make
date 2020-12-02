
HEADERS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
OBJECTS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
LIBS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY
CURRENT_DIR= D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.READER\Descriptor_File_Reader

VPATH = $(OBJECTS) $(HEADERS) $(LIBS) $(CURRENT_DIR)

Descriptor_File_Reader.exe : Descriptor_File_Reader_Main_File.cpp Descriptor_File_Reader.cpp \
	Descriptor_File_Reader.h Inter_Thread_Class_Description_Reader.h Inter_Thread_Data_Type_Description_Reader.h \
	Header_File_Descriptions_Reader.h Source_File_Descriptions_Reader.h  \
	Library_Descriptions_Reader.h Main_File_Descriptions_Reader.h \
	Include_Directory_Description_Reader.h Descriptor_File_Data_Collector.h \
	Descriptor_File_Reader_Initializer.h Descriptor_File_Number_Processor.h  \
	Descriptor_File_Reader_Syntax_Controller.h Cpp_FileOperations.h

	g++ -o Descriptor_File_Reader.exe -std=c++14 -I$(HEADERS) -I$(CURRENT_DIR) \
	-L$(OBJECTS) -L$(LIBS) Descriptor_File_Reader_Main_File.cpp Descriptor_File_Reader.cpp Descriptor_File_Reader.h -include \
	Inter_Thread_Class_Description_Reader.h -include Inter_Thread_Data_Type_Description_Reader.h \
	-include Header_File_Descriptions_Reader.h -include Source_File_Descriptions_Reader.h \
	-include Library_Descriptions_Reader.h -include Main_File_Descriptions_Reader.h \
	-include Include_Directory_Description_Reader.h -include Descriptor_File_Data_Collector.h \
	-include Descriptor_File_Reader_Initializer.h -include Descriptor_File_Number_Processor.h \
	-include Descriptor_File_Reader_Syntax_Controller.h -include Cpp_FileOperations.h -lmptools
