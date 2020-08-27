
#ifndef BUILDER_INITIALIZER_H
#define BUILDER_INITIALIZER_H

#include <cstring>

class Builder_Initializer
{
public:
 Builder_Initializer();
 Builder_Initializer(const Builder_Initializer & orig);
 virtual ~Builder_Initializer();
 void Receive_Data_Type(const char * DataType);
 void Receive_Data_Type(char * DataType);
 void Receive_Data_Type_Include_File_Name(const char * Include_File_Name);
 void Receive_Data_Type_Include_File_Name(char * Include_File_Name);
 void Receive_Entered_Class_Name(const char * NewClassName);
 void Receive_Entered_Class_Name(char * NewClassName);
 void Receive_Generic_Class_Name(const char * ClassName);
 void Receive_Generic_Class_Name(char * ClassName);
 void Receive_Base_Directory(const char * BaseDirectory);
 void Receive_Base_Directory(char * BaseDirectory);
 void Receive_Construction_Point(const char * ConstructionPoint);
 void Receive_Construction_Point(char * ConstructionPoint);
 void Set_New_Class_Name_Directly(const char * New_Class_Name);
 void Set_New_Class_Name_Directly(char * New_Class_Name);
 void Clear_Dynamic_Memory();
 void Collect_Informations();
 char * Get_NewClassName();
 char * Get_DataType();
 char * Get_NewHeaderFileName();
 char * Get_ClassImplementationFileName();
 char * Get_Class_Constructor_Name();
 char * Get_Class_Destructor_Name();
 char * Get_DataType_IncludeFileName();
 char * Get_Base_Directory();
 char * Get_Construction_Point();
 bool   Get_Data_Type_Include_File_Name_Receive_Condition();
private:
 void Place_String(char ** Pointer, const char * String, int String_Size);
 void Place_String(char ** Pointer, char * String, int String_Size);
 void Place_Information(char ** Pointer, char * Information, int * index_counter);
 void Clear_Pointer_Memory(char ** Pointer);
 void Set_Default_New_Class_Name();
 void Set_Entered_New_Class_Name();
 void Determine_New_Header_File_Name();
 void Determine_Constructor_Function_Names();
 void Determine_Class_Implementation_File_Name();
 bool Memory_Delete_Condition;
 bool Data_Type_Include_File_Name_Receive_Condition;
 bool Entered_Class_Name_Receive_Conditon;
 bool Direct_New_Class_Name_Determination;
 char * Base_Directory;
 char * Construction_Point;
 char * Data_Type;
 char * New_Class_Name;
 char * Entered_Class_Name;
 char * New_Header_File_Name;
 char * Class_Implementation_File_Name;
 char * Constructor;
 char * Destructor;
 char * Generic_Class_Name;
 char * Data_Type_Include_File_Name;
};

#endif /* BUILDER_INITIALIZER_H */
