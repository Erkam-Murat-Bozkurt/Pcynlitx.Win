
BASE_DIRECTORY=~/PCYNLITX.PROJECT/PROJECT.MANAGEMENT.TOOLS/Included_Header_File_Names_Reader
HEADER_FILES_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.HEADER.FILES
LIBRARY_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY
OBJECT_FILES_DIRECTORY=~/PCYNLITX.PROJECT.LIBRARY/PROJECT.LIBRARY/OBJECT.FILES

bash Included_Header_File_Names_Reader_Compiler.sh

printf "\n\n  #\e[1;34m Included_Header_File_Names_Reader.o has been derived .. \e[0m\n\n"

chmod 0777 $BASE_DIRECTORY/Included_Header_File_Names_Reader.o

mv $BASE_DIRECTORY/Included_Header_File_Names_Reader.o $OBJECT_FILES_DIRECTORY

cp $BASE_DIRECTORY/Included_Header_File_Names_Reader.h $HEADER_FILES_DIRECTORY

printf "\n\n  #\e[1;34m Included_Header_File_Names_Reader class has been updated .. \e[0m\n\n\n"
