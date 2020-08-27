

#ifndef DATABASEBUILDER_H
#define DATABASEBUILDER_H

#include <cstring>
#include "DirectoryOperations.h"
#include "CFileOperations.h"
#include "MethodInterpreter.h"
#include "MethodListReader.h"
#include "MethodReader.h"

struct Method_Datas
{
  int     Method_ID_Number;
  bool    Syntax_Error_Status;
  int     Parameter_Number;
  char *  Method_Name;
  char *  Return_Type;
  char *  Acess_Type;
  char ** Parameter_Names;
  char ** Parameter_Types;
};

class DataBaseBuilder
{
public:
  DataBaseBuilder();
  DataBaseBuilder(const DataBaseBuilder & orig);
  virtual ~DataBaseBuilder();
  void Build_DataBase(MethodReader * Reader);
  void Remove_MemberFunctionList(MethodReader * Reader);
  void Clear_Dynamic_Memory();
  int  Get_Public_Method_Number();
  int  Get_Private_Method_Number();
  int  Get_Protected_Method_Number();
  char * Get_Class_Name();
  Method_Datas * Get_Public_Method_Datas();
  Method_Datas * Get_Private_Method_Datas();
  Method_Datas * Get_Protected_Method_Datas();
private:
  void Receive_String(char ** Pointer, char * Method_Name, int String_Size);
  void Set_Currently_Working_Directory(char * path);
  void Clear_Method_Data(Method_Datas * Pointer);
  void Clear_Pointer_Memory(char ** Pointer);
  void Receive_Interpreter_Informations(char * Method, char * Acess_Type, int Id_Number);
  void Receive_Method_Datas(Method_Datas * Data_Pointer);
  void Clear_Interpreter_Memory();
  MethodListReader Reader;
  MethodInterpreter Interpreter;
  CFileOperations FileManager;
  DirectoryOperations DirectoryManager;
  Method_Datas * Public_Method_Data_Pointer;
  Method_Datas * Private_Method_Data_Pointer;
  Method_Datas * Protected_Method_Data_Pointer;
  char * Class_Name;
  char * Construction_Point;
  bool Memory_Delete_Condition;
  int Public_Method_Number;
  int Private_Method_Number;
  int Protected_Method_Number;
  int Default_Empty_List_Size;
};

#endif /* DATABASEBUILDER_H */
