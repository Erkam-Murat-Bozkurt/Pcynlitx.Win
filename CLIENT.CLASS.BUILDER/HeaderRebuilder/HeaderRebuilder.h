
#ifndef HEADERREBUILDER_H
#define HEADERREBUILDER_H

#include <ctype.h>
#include "Cpp_FileOperations.h"
#include "CharOperator.h"
#include "MemberFunctionReader.h"
#include "Descriptor_File_Reader.h"
#include "ClassRebuilder_Initializer.h"
#include "DirectoryOperations.h"

class HeaderRebuilder
{
public:
 HeaderRebuilder();
 HeaderRebuilder(const HeaderRebuilder & orig);
 virtual ~HeaderRebuilder();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Receive_ClassRebuilder_Initializer(ClassRebuilder_Initializer * Pointer);
 void Receive_MemberFunctionReader(MemberFunctionReader * Pointer);
 void Build_Header_File();
 void Read_Member_Functions();
 void Clear_Dynamic_Memory();
private:
 void Determine_Inclusion_Word();
 void Determine_Constructor_Function_Names();
 char ConvertToUpper(char character);
 void Place_String(char ** Pointer, char * Information, int String_Size);
 void Place_Information(char ** Pointer, char * Information, int * String_Size);
 Cpp_FileOperations FileManager;
 CharOperator CharacterOperations;
 MemberFunctionReader * Function_Reader_Pointer;
 Descriptor_File_Reader * Reader_Pointer;
 ClassRebuilder_Initializer * Initializer;
 DirectoryOperations DirectoryManager;
 char character;
 char * Inclusion_Word;
 bool   Memory_Delete_Condition;
};

#endif /* HEADERREBUILDER_H */
