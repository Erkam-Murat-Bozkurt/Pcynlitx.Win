
#ifndef CPP_FILEOPERATIONS_H
#define CPP_FILEOPERATIONS_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <windows.h>



#define Rf   'r'     // Opens File for only reading

#define Wf   'w'     // Opens File for only writing

#define RWf  'x'     // Open the file for both reading and writing.
                     // The stream is positioned at the start of the file.

#define RWCf   'b'    // Open the file for both reading and writing. If the file exists,
                      //  it is truncated to zero length.
                      // If the file does not exist, it is created.


#define Af   'a'      // Open the file for writing in append mode.
                      // The file is created if it does not exist.
                      // The stream is positioned at the end of the file.
                      // All writes will append to the file.

class Cpp_FileOperations
{
public:
 Cpp_FileOperations();
 Cpp_FileOperations(const Cpp_FileOperations & orig);
 virtual ~Cpp_FileOperations();
 void SetFilePath(std::string FilePATH);
 void SetFilePath(char * String);
 void SetFilePath(const char * String);
 void CpFile(char * path, char * target_path);
 void MoveFile_Win(char * path, char * target_path);  // Transfer file to another location in windows
 void FileOpen(char Open_Mode);
 void FileClose( );
 void WriteToFile(std::string string_list);
 void WriteToFile(const char * String);
 void WriteToFile(char * String);
 bool Control_End_of_File();
 std::string Read();
 std::string ReadLine();
 char * ReadLine_as_Cstring();
 void Determine_Base_File_Size(char * path);
 void Receive_File(char * path);
 void Record_File(char * path);
 char * Conver_Std_String_To_Char(std::string string_line);
 void Clear_Dynamic_Memory();
private:
 std::fstream DataFile;
 std::string String_Line;
 std::string string_word;
 std::string FilePath;
 bool Memory_Delete_Condition;
 char * CString;
 char ** File_Index;
 int File_line_Number;
 char Open_Mode_Determiner;
 int  FileDeleteCondition;
 bool isFilePathReceive;
 bool End_Of_File_Condition;
};

#endif /* CPP_FILEOPERATIONS_H */
