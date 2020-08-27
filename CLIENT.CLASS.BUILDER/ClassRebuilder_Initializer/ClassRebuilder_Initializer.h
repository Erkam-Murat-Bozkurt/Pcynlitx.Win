
#ifndef CLASSREBUILDER_INITIALIZER_H
#define CLASSREBUILDER_INITIALIZER_H

#include <iostream>
#include <cstring>
#include <string>
#include "CharOperator.h"
#include "Descriptor_File_Reader.h"
#include "Included_Header_File_Names_Reader.h"


class ClassRebuilder_Initializer
{
public:
 ClassRebuilder_Initializer();
 ClassRebuilder_Initializer(const ClassRebuilder_Initializer & orig);
 virtual ~ClassRebuilder_Initializer();
 void Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer);
 void Receive_Class_Number(int Class_Number);
 void Receive_Data_Type_Number(int Data_Type_Number);
 bool Is_This_Method_Base_Class_Constructor(char * MethodName);
 bool Is_This_Method_Base_Class_Destructor(char * MethodName);
 void Determine_Informations();
 void Clear_Dynamic_Memory();
 int  Get_Index_Number_For_Descriptor_File_Reader() const;
 int  Get_Included_Header_Files_Number();
 std::string * Get_Header_File_Declarations();
 char * Get_Object_Name() const;
 char * Get_New_Header_File_Name() const;
 char * Get_New_Class_Name() const;
 char * Get_New_Class_Implementation_File_Name() const;
 char * Get_New_Class_Constructor_Name() const;
 char * Get_New_Class_Destructor_Name() const;
 char * Get_Base_Class_Destructor_Name() const;
 char * Get_Base_Class_Header_File_Name() const;
 char * Get_Base_Class_Header_File_Path() const;
 char * Get_Base_Class_Name() const;
 char * Get_Base_Class_Header_File_Location() const;
 char * Get_Base_Class_Instance_Name() const;
 char ** Get_Header_File_Declarations_C_String();
 char ** Get_Header_File_Names_C_String();
private:
 void Clear_Pointer_Memory(char ** Pointer);
 void Place_String(char ** Pointer, char * Information, int String_Size);
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 void Determine_Included_Header_Files();
 void Determine_New_Class_Implementation_File_Name();
 void Determine_New_Class_Destructor_Name();
 void Determine_Base_Class_Destructor_Name();
 void Determine_New_Class_Name();
 void Determine_New_Header_File_Name();
 void Determine_Object_Name();
 void Determine_Index_Number_of_Class();
 void Determine_Base_Class_Informations();
 Included_Header_File_Names_Reader Header_Files_Name_Reader;
 Descriptor_File_Reader * Reader_Pointer;
 CharOperator CharacterOperations;
 int    Class_Number;
 int    Data_Type_Number;
 int    Index_Number;
 char * Base_Class_Header_File_Name;
 char * Base_Class_Header_File_Path;
 char * Base_Class_Name;
 char * Base_Class_Instance_Name;
 char * Base_Class_Header_File_Location;
 char * New_Class_Name;
 char * New_Header_File_Name;
 char * Class_Implementation_File_Name;
 char * New_Destructor_Name;
 char * Base_Class_Destructor_Name;
 char * Object_Name;
 char * Newly_Constructed_Include_Directory;
 bool   Is_This_Base_Class_Constructor;
 bool   Is_This_Base_Class_Destructor;
 bool   Class_Data_Type_Receive_Condition;
 bool   Shared_Data_Type_Receive_Condition;
 bool   Memory_Delete_Condition;
};

#endif /* CLASSREBUILDER_INITIALIZER_H */
