/*

Copyright ©  2019,  Erkam Murat Bozkurt

This file is part of the research project which is carried by Erkam Murat Bozkurt.

This is a free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation
either version 3 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

*/


#include "DataBaseBuilder.h"

DataBaseBuilder::DataBaseBuilder(){

    this->Public_Method_Data_Pointer = nullptr;

    this->Private_Method_Data_Pointer = nullptr;

    this->Protected_Method_Data_Pointer = nullptr;

    this->Memory_Delete_Condition = true;

    this->Class_Name = nullptr;

    this->Construction_Point = nullptr;

    this->Default_Empty_List_Size = 5;

    this->Public_Method_Number = 0;

    this->Private_Method_Number = 0;

    this->Protected_Method_Number = 0;
};

DataBaseBuilder::DataBaseBuilder(const DataBaseBuilder & orig){}

DataBaseBuilder::~DataBaseBuilder(){

    if(!this->Memory_Delete_Condition){

       this->Clear_Dynamic_Memory();
    }
}

void DataBaseBuilder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Public_Method_Number > 0){

            for(int i=0;i<this->Public_Method_Number;i++){

               this->Clear_Method_Data(&(this->Public_Method_Data_Pointer[i]));
            }

            delete [] this->Public_Method_Data_Pointer;

            this->Public_Method_Data_Pointer = nullptr;
         }

         if(this->Private_Method_Number > 0){

            for(int i=0;i<this->Private_Method_Number;i++){

                this->Clear_Method_Data(&(this->Private_Method_Data_Pointer[i]));
            }

            delete [] this->Private_Method_Data_Pointer;

            this->Private_Method_Data_Pointer = nullptr;
         }

         if(this->Protected_Method_Number > 0){

             for(int i=0;i<this->Protected_Method_Number;i++){

                 this->Clear_Method_Data(&(this->Protected_Method_Data_Pointer[i]));
             }

             delete [] this->Protected_Method_Data_Pointer;

             this->Protected_Method_Data_Pointer = nullptr;
         }

         delete [] this->Class_Name;

         this->Class_Name = nullptr;

         this->Construction_Point = nullptr;
     }
}

void DataBaseBuilder::Clear_Method_Data(Method_Datas * Pointer){

     delete [] Pointer->Method_Name;

     delete [] Pointer->Return_Type;

     delete [] Pointer->Acess_Type;

     if(Pointer->Parameter_Types != nullptr){

        for(int i=0;i<Pointer->Parameter_Number;i++){

            delete [] Pointer->Parameter_Types[i];
        }

        delete [] Pointer->Parameter_Types;
     }

     if(Pointer->Parameter_Names != nullptr){

        for(int i=0;i<Pointer->Parameter_Number;i++){

            delete [] Pointer->Parameter_Names[i];
        }

        delete [] Pointer->Parameter_Names;
     }
}

void DataBaseBuilder::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);
     }
}

void DataBaseBuilder::Build_DataBase(MethodReader * Reader){

     this->Memory_Delete_Condition = false;

     this->Set_Currently_Working_Directory(Reader->GetDataRecordDirectory());

     this->Reader.SetMethodListPath(Reader->GetRecordFilePath());

     this->Reader.SetMetaFilePath(Reader->GetMetaDataFilePath());

     this->Reader.ReadMethodList();

     int String_Size = strlen(Reader->GetClassName());

     this->Class_Name = new char [10*String_Size];

     this->Receive_String(&this->Class_Name,Reader->GetClassName(),String_Size);

     this->Public_Method_Number    = this->Reader.GetPublicMethodNumber();

     this->Private_Method_Number   = this->Reader.GetPrivateMethodNumber();

     this->Protected_Method_Number = this->Reader.GetProtectedMethodNumber();

     if( this->Public_Method_Number > 0){

        this->Public_Method_Data_Pointer = new Method_Datas [10*this->Reader.GetPublicMethodNumber()];
     }
     else{

        this->Public_Method_Data_Pointer = nullptr;
     }

     if(this->Private_Method_Number > 0){

        this->Private_Method_Data_Pointer = new Method_Datas [10*this->Reader.GetPrivateMethodNumber()];
     }
     else{

        this->Private_Method_Data_Pointer = nullptr;
     }

     if(this->Protected_Method_Number > 0){

        this->Protected_Method_Data_Pointer = new Method_Datas [10*this->Reader.GetProtectedMethodNumber()];
     }
     else{

        this->Protected_Method_Data_Pointer = nullptr;
     }

     int counter = 0;

     char PublicAccesType []    = {'p','u','b','l','i','c','\0'};

     char PrivateAccesType []   = {'p','r','i','v','a','t','e','\0'};

     char ProtectedAcessType [] = {'p','r','o','t','e','c','t','e','d','\0'};

     for(int i=0;i<this->Reader.GetPublicMethodNumber();i++){

        this->Receive_Interpreter_Informations(this->Reader.GetPublicMethods()[i],PublicAccesType,counter);

        this->Receive_Method_Datas(&(this->Public_Method_Data_Pointer[i]));

        this->Clear_Interpreter_Memory();

        counter++;
     }

     for(int i=0;i<this->Reader.GetPrivateMethodNumber();i++){

         this->Receive_Interpreter_Informations(this->Reader.GetPrivateMethods()[i],PrivateAccesType,counter);

         this->Receive_Method_Datas(&(this->Private_Method_Data_Pointer[i]));

         this->Clear_Interpreter_Memory();

         counter++;
     }

     for(int i=0;i<this->Reader.GetProtectedMethodNumber();i++){

         this->Receive_Interpreter_Informations(this->Reader.GetProtectedMethods()[i],ProtectedAcessType,counter);

         this->Receive_Method_Datas(&(this->Protected_Method_Data_Pointer[i]));

         this->Clear_Interpreter_Memory();

         counter++;
     }

     this->Remove_MemberFunctionList(Reader);

     this->Reader.Clear_Dynamic_Memory();

     this->FileManager.Clear_Dynamic_Memory();

     this->Set_Currently_Working_Directory(Reader->GetDataRecordDirectory());

     this->DirectoryManager.Clear_Dynamic_Memory();
}

void DataBaseBuilder::Set_Currently_Working_Directory(char * path){

     int directory_swich = this->DirectoryManager.ChangeDirectory(path);

     if(directory_swich == -1){

        std::cerr << "\n An error occured on directory operations ..!";

        std::cout << "\n An error occured on directory operations ..!";

        std::cerr << "\n working directory can not be changed ..";

        std::cout << "\n working directory can not be changed ..";

        exit(EXIT_FAILURE);
     }
}

void DataBaseBuilder::Remove_MemberFunctionList(MethodReader * Reader){

     int file_remove_status = this->FileManager.DeleteFile(Reader->GetRecordFilePath());

     if(file_remove_status == -1){

        std::cerr << "\n An error occured on class header file reading ..!";

        std::cout << "\n An error occured on class header file reading ..!";

        std::cerr << "\n Member function list file can not be removed ..";

        std::cout << "\n Member function list file can not be removed ..";

        exit(EXIT_FAILURE);
     }

     file_remove_status = this->FileManager.DeleteFile(Reader->GetMetaDataFilePath());

     if(file_remove_status == -1){

        std::cerr << "\n An error occured on class header file reading ..!";

        std::cout << "\n An error occured on class header file reading ..!";

        std::cerr << "\n Member function list meta file can not be removed ..";

        std::cout << "\n Member function list meta file can not be removed ..";

        exit(EXIT_FAILURE);
     }
}

void DataBaseBuilder::Receive_Method_Datas(Method_Datas * Data_Holder){

     Data_Holder->Method_ID_Number    = this->Interpreter.getMethodIDNumber();

     Data_Holder->Syntax_Error_Status = this->Interpreter.getMethodSyntaxErrorStatus();

     Data_Holder->Parameter_Number    = this->Interpreter.getMethodParameterNumber();

     // Place Method Name information

     int Method_Name_Size = strlen(this->Interpreter.getMethodName());

     Data_Holder->Method_Name = new char [10*Method_Name_Size];

     this->Receive_String(&(Data_Holder->Method_Name),this->Interpreter.getMethodName(),Method_Name_Size);

     // Place Return type information

     int Return_Type_Size = strlen(this->Interpreter.getMethodReturnType());

     if(Return_Type_Size > 0){

        Data_Holder->Return_Type = new char [10*Return_Type_Size];

        this->Receive_String(&(Data_Holder->Return_Type),this->Interpreter.getMethodReturnType(),Return_Type_Size);
     }
     else{

          Data_Holder->Return_Type = new char [10*this->Default_Empty_List_Size];

          for(int i=0;i<this->Default_Empty_List_Size;i++){

             Data_Holder->Return_Type[i] = '\0';
          }
     }

     // Place Acess type information

     int Acess_Type_Size = strlen(this->Interpreter.getMethodAccessType());

     Data_Holder->Acess_Type = new char [10*Acess_Type_Size];

     this->Receive_String(&(Data_Holder->Acess_Type),this->Interpreter.getMethodAccessType(),Acess_Type_Size);

     int Parameter_Number = this->Interpreter.getMethodParameterNumber();

     if(Parameter_Number > 0){

        Data_Holder->Parameter_Names = new char * [10*Parameter_Number];

        Data_Holder->Parameter_Types = new char * [10*Parameter_Number];

        for(int k=0;k<Parameter_Number;k++){

            int Parameter_Name_Size = strlen(this->Interpreter.getMethodParameterNames()[k]);

            if(Parameter_Name_Size == 0){

               Data_Holder->Parameter_Names[k] = new char [10];

               for(int j=0;j<10;j++){

                   Data_Holder->Parameter_Names[k][j] = '\0';
               }
            }
            else{

                  Data_Holder->Parameter_Names[k] = new char [10*Parameter_Name_Size];

                  this->Receive_String(&(Data_Holder->Parameter_Names[k]),this->Interpreter.getMethodParameterNames()[k],Parameter_Name_Size);
            }

            int Parameter_Type_Size = strlen(this->Interpreter.getMethodParameterTypes()[k]);

            Data_Holder->Parameter_Types[k] = new char [10*Parameter_Type_Size];

            this->Receive_String(&(Data_Holder->Parameter_Types[k]),this->Interpreter.getMethodParameterTypes()[k],Parameter_Type_Size);
        }
     }
     else{

           Data_Holder->Parameter_Names = nullptr;

           Data_Holder->Parameter_Types = nullptr;
     }
}

void DataBaseBuilder::Receive_Interpreter_Informations(char * Method, char * Acess_Type, int Id_Number){

     this->Interpreter.SetClassName(this->Class_Name);

     this->Interpreter.ReceiveMethodLine(Method);

     this->Interpreter.setMethodIDNumber(Id_Number);

     this->Interpreter.setMethodAccessType(Acess_Type);

     this->Interpreter.ReadMethod();
}

void DataBaseBuilder::Clear_Interpreter_Memory(){

     this->Interpreter.Clear_Dynamic_Memory();
}

void DataBaseBuilder::Receive_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

char * DataBaseBuilder::Get_Class_Name(){

       return this->Class_Name;
}

int DataBaseBuilder::Get_Public_Method_Number(){

    return this->Public_Method_Number;
}

int DataBaseBuilder::Get_Private_Method_Number(){

    return this->Private_Method_Number;
}

int DataBaseBuilder::Get_Protected_Method_Number(){

    return this->Protected_Method_Number;
}

Method_Datas * DataBaseBuilder::Get_Public_Method_Datas(){

    return this->Public_Method_Data_Pointer;
}

Method_Datas * DataBaseBuilder::Get_Private_Method_Datas(){

    return this->Private_Method_Data_Pointer;
}

Method_Datas * DataBaseBuilder::Get_Protected_Method_Datas(){

    return this->Protected_Method_Data_Pointer;
}
