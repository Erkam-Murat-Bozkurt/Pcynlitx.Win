
#ifndef CLASSREBUILDER_H
#define CLASSREBUILDER_H

#include <CharOperator.h>
#include <MemberFunctionReader.h>
#include <Cpp_FileOperations.h>
#include <DirectoryOperations.h>
#include <ClassRebuilder_Initializer.h>
#include <MetaDataTranslater.h>
#include <HeaderRebuilder.h>
#include <Descriptor_File_Reader.h>
#include <ClassRebuilder_Data_Collector.h>
#include <cstring>
#include <cstdlib>
#include <iostream>

class ClassRebuilder
{
public:
 ClassRebuilder();
 ClassRebuilder(const ClassRebuilder & orig);
 virtual ~ClassRebuilder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Receive_Class_Number(int Class_Number);
 void Receive_Data_Type_Number(int Data_Type_Number);
 void Re_Construct_Class();
 void Run_System_Commands();
 void Clear_Dynamic_Memory();
 void Print_System_Commands();
 char * Get_Object_File_Name() const;
 char * Get_New_Class_Name() const;
private:
 void Read_Informations();
 void Construct_Class_Implementation_File();
 void Write_Constructor_Function_Definition(int FunctionNumber);
 void Write_Dectructor_Function_Definition(int FunctionNumber);
 void Write_Delete_Method();
 void Write_Connection_Method();
 void Write_Disconnect_Method();
 void Write_Connection_Error_Printing_Method();
 void Write_Member_Function_Definition(int FunctionNumber);
 void Start_Implementation_File_Construction();
 bool Is_This_Method_Copy_Constructor(int ParameterNumber,char ** ParameterNames);
 void Receive_New_Class_Name();
 void Receive_Object_File_Name();
 void Write_Space(int Space_Number);
 void Place_Information(char ** Pointer, char * Information, int * counter);
 void Place_String(char ** Pointer, char * String, size_t String_Size);
 void Clear_Pointer_Memory(char ** Pointer);
 MetaDataTranslater DataTranslater;
 ClassRebuilder_Initializer Initializer;
 MemberFunctionReader FunctionReader;
 Cpp_FileOperations FileManager;
 CharOperator CharacterOperations;
 DirectoryOperations DirectoryManager;
 HeaderRebuilder HeaderFileRebuilder;
 Descriptor_File_Reader * Reader_Pointer;
 ClassRebuilder_Data_Collector Data_Collector;
 int MethodCounterForAcessProtection;
 int MethodNumberForAcessProtection;
 bool IsThisCopyConstructor;
 bool Memory_Delete_Condition;
 char * New_Class_Implementation_File_Name;
 char * Object_File_Name;
 char * New_Header_File_Name;
 char * New_Class_Name;
};

#endif /* CLASSREBUILDER_H */
