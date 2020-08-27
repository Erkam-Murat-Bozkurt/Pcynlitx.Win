
#ifndef REPORTFILEBUILDER_HEADERWRITER_H
#define REPORTFILEBUILDER_HEADERWRITER_H

#include <cstring>
#include <ctype.h>
#include "CFileOperations.h"
#include "DirectoryOperations.h"
#include "Builder_Initializer.h"

class ReportFileBuilder_HeaderWriter
{
public:
 ReportFileBuilder_HeaderWriter();
 ReportFileBuilder_HeaderWriter(const ReportFileBuilder_HeaderWriter & orig);
 virtual ~ReportFileBuilder_HeaderWriter();
 void Receive_Data_Type(const char * DataType);
 void Receive_Data_Type(char * DataType);
 void Receive_Entered_Class_Name(const char * NewClassName);
 void Receive_Entered_Class_Name(char * NewClassName);
 void Receive_Construction_Point(const char * Construction_Point);
 void Receive_Construction_Point(char * Construction_Point);
 void Receive_Namespace(char * name_space_info);
 void Build_Header_File();
private:
 void Write_Header_File();
 void Determine_Inclusion_Word();
 char ConvertToUpper(char character);
 CFileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Builder_Initializer Initializer;
 char * InclusionWord;
 char * name_space_info;
 char   character;
};

#endif /* REPORTFILEBUILDER_HEADERWRITER_H */
