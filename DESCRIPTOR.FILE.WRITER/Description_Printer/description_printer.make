
HEADERS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.HEADER.FILES
OBJECTS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY\OBJECT.FILES
LIBS=D:\PCYNLITX.WIND.IMPL.LIBRARY\PROJECT.LIBRARY
CURRENT_DIR= D:\PCYNLITX.PROJECT.WINDOWS\DESCRIPTOR.FILE.WRITER\Description_Printer

VPATH = $(OBJECTS) $(HEADERS) $(LIBS) $(CURRENT_DIR)

Description_Printer.exe : Description_Printer_Main_File.cpp Description_Printer.cpp \
  Description_Printer.h Descriptor_File_Reader.h CharOperator.h

	g++ -o Description_Printer.exe -std=c++14 -I$(HEADERS) -I$(CURRENT_DIR) \
	-L$(OBJECTS) -L$(LIBS) Description_Printer_Main_File.cpp \
	Description_Printer.cpp Description_Printer.h -include Descriptor_File_Reader.h \
	-include CharOperator.h -lmptools
