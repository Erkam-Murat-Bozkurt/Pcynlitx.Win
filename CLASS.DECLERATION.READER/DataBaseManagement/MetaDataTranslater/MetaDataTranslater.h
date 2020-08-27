
#ifndef METADATATRANSLATER_H
#define METADATATRANSLATER_H

#include <cstring>
#include "MemberFunctionReader.h"

class MetaDataTranslater
{
public:
 MetaDataTranslater();
 MetaDataTranslater(const MetaDataTranslater & orig);
 virtual ~MetaDataTranslater();
 void Receive_Namespace(char * Pointer);
 void ReceiveMethodInformations(Method_Datas * Method_Data_Pointer);
 void ReceiveObjectName(char * ObjectName);
 void ReceiveClassName(char * ClassName);
 void Collect_Informations();
 void Clear_Dynamic_Memory();
 int    GetReturnTypeNameSize();
 char * GetFunctionImplementationCodeLine();
 char * GetInClassFunctionCallLine();
 char * Get_Function_Call_Line();
private:
 void DetermineFunctionImplementationCodeLine();
 void DetermineInClassFunctionCallLine();
 void DetermineFunctionCallLine();
 void Clear_Pointer_Memory(char ** Pointer);
 void Place_String(char ** Pointer, char * String, int String_Size);
 Method_Datas * Data_Pointer;
 char * Namespace;
 char * Class_Name;
 char * Object_Name;
 char * CodeLine;
 char * InClassFunctionCall;
 char * FunctionCall;
 int ReturnTypeNameSize;
 bool Memory_Delete_Condition;
};

#endif /* METADATATRANSLATER_H */
