

HEADERS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
OBJECTS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
LIBS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY
CURRENT_DIR=D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Process_Descriptions_Recorder

VPATH = $(OBJECTS) $(HEADERS) $(LIBS) $(CURRENT_DIR)

Process_Descriptions_Recorder.exe : Process_Descriptions_Recorder_Main_File.cpp \
	Process_Descriptions_Recorder.cpp Process_Descriptions_Recorder.h \
  Cpp_FileOperations.h DataRecorder.h DataRecord_Tools.h

	g++ -o Process_Descriptions_Recorder.exe -std=c++14 -I$(HEADERS) \
	-I$(CURRENT_DIR) -L$(OBJECTS) -L$(LIBS) \
	Process_Descriptions_Recorder_Main_File.cpp Process_Descriptions_Recorder.cpp \
	Process_Descriptions_Recorder.h -include Cpp_FileOperations.h  \
	-include DataRecorder.h -include DataRecord_Tools.h -lmptools
