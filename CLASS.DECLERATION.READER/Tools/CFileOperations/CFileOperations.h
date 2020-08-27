
#ifndef CFILEOPERATIONS_H
#define	CFILEOPERATIONS_H

#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#define R   "r"     // Opens File for only reading

#define W   "w"     // Opens File for only writing

#define RW  "r+"    // Open the file for both reading and writing.
                    // The stream is positioned at the start of the file.

#define RWC "w+"    // Open the file for both reading and writing. If the file exists,
                    // it is truncated to zero length.
                    // If the file does not exist, it is created.

#define A   "a"     // Open the file for writing in append mode.
                    // The file is created if it does not exist.
                    // The stream is positioned at the end of the file.
                    // All writes will append to the file. 

// For Copy_File function, file paths are file full paths include both directory and name Information

// For instance, directory: /home/erkam, file name: sample, file path:/home/erkam/sample

class CFileOperations {
public:
 CFileOperations();
 CFileOperations(const CFileOperations& orig);
 virtual ~CFileOperations();
 void SetFilePath(const char * FileName);
 void SetFilePath(char * FileName);
 void FileOpen(const char * mode);
 void FileClose();
 void PrintFileToConsole();
 void PrintLineToConsole();
 void Copy_File(char * New_File_Path, char * File_Path); // File Path includes file name
 void Move_File(char * New_File_Path, char * File_Path);
 void WriteToFile(const char * string);
 bool Check_End_of_File();
 void SetEndOfFile();
 void ClearEndOfFile();
 char ReadCharacter();
 int  DeleteFile(char * FileName);
 char * GetFilePath();
 char * ReadLine();
 FILE * GetFileStreamPointer();
 void   Clear_Dynamic_Memory();
private:
 void Place_String(char ** Pointer, const char * String, int String_Size);
 void Place_String(char ** Pointer, char * String, int String_Size);
 void Place_Information(char ** Pointer, const char * Information, int * index_counter);
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 void Clear_Pointer_Memory(char ** Pointer);
 bool Is_This_Long_Path(const char * Path);
 bool Is_This_Long_Path(char * Path);
 void Clear_Read_Buffer();
 int  Get_String_Size(char * String);
 FILE * stream;
 bool   isLongPath;
 bool   End_of_File_Condition;
 char * FilePath;
 char   buffer[LINE_MAX];
 char characterBuffer;
 int  FileDeleteCondition;
 int  String_Size;
 bool Memory_Delete_Condition;
};

#endif	/* CFILEOPERATIONS_H */
