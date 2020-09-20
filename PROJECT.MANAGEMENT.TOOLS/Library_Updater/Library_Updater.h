
#ifndef LIBRARY_UPDATER_H
#define LIBRARY_UPDATER_H

#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <cstdio>
#include <windows.h>
#include <shlwapi.h>
#include "Cpp_FileOperations.h"
#include "DirectoryOperations.h"
#include "Custom_System_Interface.h"

class Library_Updater
{
public:
 Library_Updater();
 Library_Updater(const Library_Updater & orig);
 virtual ~Library_Updater();
 void Build_Library(char * Object_Files_Directory, char * Library_Name);
 void Send_Library_New_Location(char * Object_Files_Directory, char * New_Location, char * Library_Name);
 void Clear_Dynamic_Memory();
private:
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 Cpp_FileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Custom_System_Interface System_Interface;
 char * Archive_Build_Command;
 char * Object_File_List;
 bool Memory_Delete_Condition;
};

#endif /* LIBRARY_UPDATER_H */
