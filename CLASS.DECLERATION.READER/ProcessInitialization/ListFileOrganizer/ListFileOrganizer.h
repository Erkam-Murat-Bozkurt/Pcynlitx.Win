
#ifndef LISTFILEORGANIZER_H
#define LISTFILEORGANIZER_H

#include <cstring>
#include <cstdlib>
#include "ClassNameReader.h"
#include "DirectoryOperations.h"

class ListFileOrganizer
{
public:
 ListFileOrganizer();
 ListFileOrganizer(const ListFileOrganizer & orig);
 virtual ~ListFileOrganizer();
 void ReceiveIncludeDirectoryPATH(char * IncludeDirectoryPATH);
 void ReceiveDataBaseConstructionPoint(char * ConstructionPoint);
 void Set_Target_Header_File_Path(char * TargetHeaderFile);
 void CollectInformations();
 void Clear_Dynamic_Memory();
 char * GetIncludeDirectoryPATH();
 char * GetRecordFilePath();
 char * GetMetaDataFilePath();
 char * GetHeaderFilePath();
 char * GetDataBaseConstructionPoint();
private:
 void Place_String(char ** Pointer, char * String, int String_Size);
 void Place_String(char ** Pointer, const  char * String, int String_Size);
 void Clear_Pointer_Memory(char ** Pointer);
 void DetermineRecordFilePath();
 void DetermineClassName();
 void DetermineTargetHeaderFilePath();
 ClassNameReader ClassNameDeterminer;
 DirectoryOperations DirectoryManager;
 bool IncludeDirectorySetCondition;
 bool BaseDirectorySetCondition;
 bool DataBaseConstructionPointSetCondition;
 char * DataBaseConstructionPoint;
 char * IncludeDirectoryPATH;
 char * HeaderFilePath;
 char * Record_File_Path;
 char * Meta_File_Path;
 bool   Memory_Delete_Condition;
};

#endif /* LISTFILEORGANIZER_H */
