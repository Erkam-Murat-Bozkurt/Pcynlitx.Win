
#ifndef MEMBERFUNCTIONREADER_H
#define MEMBERFUNCTIONREADER_H

#include <MethodReader.h>
#include <DataBaseBuilder.h>


class MemberFunctionReader
{
public:
 MemberFunctionReader();
 MemberFunctionReader(const MemberFunctionReader & orig);
 virtual ~MemberFunctionReader();
 void Receive_Include_Directory_PATH(char * IncludeDirectory);
 void Receive_Construction_Point(char * BaseDirectory);
 void Receive_Header_File_Path(char * HeaderFileName);
 void Read_Member_Functions();
 void Clear_Dynamic_Memory();
 int  Get_Public_Method_Number();
 int  Get_Private_Method_Number();
 int  Get_Protected_Method_Number();
 Method_Datas * GetPublicMethods();
 Method_Datas * GetPrivateMethods();
 Method_Datas * GetProtectedMethods();
 char * Get_Class_Name();
private:
 MethodReader Reader;
 DataBaseBuilder Builder;
 bool Memory_Delete_Condition;
};

#endif /* MEMBERFUNCTIONREADER_H */
