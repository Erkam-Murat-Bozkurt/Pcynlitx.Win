
BASE_DIRECTORY=~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS/Included_Header_File_Names_Reader
HEADER_FILES_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
LIBRARY_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY

g++ -std=c++14 -I$BASE_DIRECTORY -I$HEADER_FILES_DIRECTORY -L$LIBRARY_DIRECTORY \
    -o Included_Header_File_Names_Reader Included_Header_File_Names_Reader_Main_File.cpp \
     Included_Header_File_Names_Reader.cpp \
    -include Included_Header_File_Names_Reader.h -include ClassNameReader.h -lmptools
