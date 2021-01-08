
#ifndef REPORTFILEBUILDER_WRITER_H
#define REPORTFILEBUILDER_WRITER_H

#include <cstring>
#include "Cpp_FileOperations.h"
#include "DirectoryOperations.h"
#include "ReportFileBuilder_HeaderWriter.h"
#include "Builder_Initializer.h"

class ReportFileBuilder_Writer
{
public:
 ReportFileBuilder_Writer();
 ReportFileBuilder_Writer(const ReportFileBuilder_Writer & orig);
 virtual ~ReportFileBuilder_Writer();
 void Receive_Data_Type(const char * DataType);
 void Receive_Data_Type(char * DataType);
 void Receive_Entered_Class_Name(const char * Entered_Class_Name);
 void Receive_Entered_Class_Name(char * Entered_Class_Name);
 void Receive_Construction_Point(const char * Construction_Point);
 void Receive_Construction_Point(char * Construction_Point);
 void Receive_Namespace(char * name_space_info);
 void Write_ReportFileBuilder();
private:
 void Build_Class_Implementation_File();
 void Start_Implementation_File_Construction();
 void Build_Constructors();
 void Build_Destructor();
 void Build_SetFilePath_Member_Function();
 void Build_File_Operations_Member_Functions();
 void Build_SetReportFileName_Member_Function();
 void Build_WriteReportEnd_Member_Function();
 void Build_MemoryAllocationError_Member_Function();
 void Build_MemoryCanNotDelete_Member_Function();
 void Build_IndexOutOfBoundError_Member_Function();
 void Build_AdressSearchError_Member_Function();
 void Build_PointerAdressChangeError_Member_Function();
 void Write_Space(const char * String, size_t Line_Number);
 ReportFileBuilder_HeaderWriter Header_Writer;
 Cpp_FileOperations FileManager;
 DirectoryOperations DirectoryManager;
 Builder_Initializer Initializer;
 char * name_space_info;
};

#endif /* REPORTFILEBUILDER_WRITER_H */
