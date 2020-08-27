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

#include "MetaDataTranslater.h"

MetaDataTranslater::MetaDataTranslater(){

    this->CodeLine = nullptr;

    this->InClassFunctionCall = nullptr;

    this->Object_Name = nullptr;

    this->Class_Name = nullptr;

    this->FunctionCall = nullptr;

    this->Namespace = nullptr;

    this->Memory_Delete_Condition = true;
};

MetaDataTranslater::MetaDataTranslater(const MetaDataTranslater & orig){

};

MetaDataTranslater::~MetaDataTranslater(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void MetaDataTranslater::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->CodeLine);

         this->Clear_Pointer_Memory(&this->InClassFunctionCall);

         this->Clear_Pointer_Memory(&this->Class_Name);

         this->Clear_Pointer_Memory(&this->Object_Name);

         this->Clear_Pointer_Memory(&this->FunctionCall);
     }
}

void MetaDataTranslater::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void MetaDataTranslater::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void MetaDataTranslater::ReceiveObjectName(char * ObjectName){

     this->Clear_Pointer_Memory(&this->Object_Name);

     int Name_Size = strlen(ObjectName);

     this->Object_Name = new char [10*Name_Size];

     this->Place_String(&this->Object_Name,ObjectName,Name_Size);
}

void MetaDataTranslater::ReceiveClassName(char * ClassName){

     this->Clear_Pointer_Memory(&this->Class_Name);

     int Name_Size = strlen(ClassName);

     this->Class_Name = new char [10*Name_Size];

     this->Place_String(&this->Class_Name,ClassName,Name_Size);
}

void MetaDataTranslater::ReceiveMethodInformations(Method_Datas * Method_Data_Pointer){

     this->Data_Pointer = Method_Data_Pointer;
}

void MetaDataTranslater::Receive_Namespace(char * Pointer){

     this->Namespace = Pointer;
}

void MetaDataTranslater::Collect_Informations(){

     this->DetermineFunctionImplementationCodeLine();

     this->DetermineInClassFunctionCallLine();

     this->DetermineFunctionCallLine();
}

void MetaDataTranslater::DetermineFunctionImplementationCodeLine(){

     this->Memory_Delete_Condition = false;

     this->Clear_Pointer_Memory(&this->CodeLine);

     int namespace_size = strlen(this->Namespace);

     int ClassNameSize  = strlen(this->Class_Name);

     int MethodNameSize = strlen(this->Data_Pointer->Method_Name);

     int ReturnTypeNameSize = strlen(this->Data_Pointer->Return_Type);

     int ParameterTypesNameSize = 0;

     int ParameterNames_NameSize = 0;

     if(this->Data_Pointer->Parameter_Number > 0){

        for(int i=0;i<this->Data_Pointer->Parameter_Number;i++){

            ParameterTypesNameSize = ParameterTypesNameSize + strlen(this->Data_Pointer->Parameter_Types[i]);
        }

        for(int i=0;i<this->Data_Pointer->Parameter_Number;i++){

            ParameterNames_NameSize = ParameterNames_NameSize + strlen(this->Data_Pointer->Parameter_Names[i]);
        }
     }

     int CodeLineSize = ClassNameSize + ParameterNames_NameSize +

                        ParameterTypesNameSize + ReturnTypeNameSize + MethodNameSize + namespace_size;

     this->CodeLine = new char [10*CodeLineSize];

     int index_counter = 0;

     this->CodeLine[index_counter] = ' ';

     index_counter++;

     if(ReturnTypeNameSize !=0){

        for(int i=0;i<ReturnTypeNameSize;i++){

           this->CodeLine[index_counter] = this->Data_Pointer->Return_Type[i];

           index_counter++;
        }

        this->CodeLine[index_counter] = ' ';

        index_counter++;
     }

     for(int i=0;i<namespace_size;i++){

         this->CodeLine[index_counter] = this->Namespace[i];

         index_counter++;
     }

     this->CodeLine[index_counter] = ':';

     index_counter++;

     this->CodeLine[index_counter] = ':';

     index_counter++;

     for(int i=0;i<ClassNameSize;i++){

         this->CodeLine[index_counter] = this->Class_Name[i];

         index_counter++;
     }

     this->CodeLine[index_counter] = ':';

     index_counter++;

     this->CodeLine[index_counter] = ':';

     index_counter++;

     for(int i=0;i<MethodNameSize;i++){

         this->CodeLine[index_counter] = this->Data_Pointer->Method_Name[i];

         index_counter++;
     }

     this->CodeLine[index_counter] = '(';

     index_counter++;

     if(this->Data_Pointer->Parameter_Number > 0){

        for(int i=0;i<this->Data_Pointer->Parameter_Number;i++){

             int TypeNameSize = strlen(this->Data_Pointer->Parameter_Types[i]);

             for(int j=0;j<TypeNameSize;j++){

               this->CodeLine[index_counter] = this->Data_Pointer->Parameter_Types[i][j];

               index_counter++;
             }

             this->CodeLine[index_counter] = ' ';

             index_counter++;

             int ParameterName_NameSize = strlen(this->Data_Pointer->Parameter_Names[i]);

             if(ParameterName_NameSize == 0){

                char parameter_name [] = {'a','r','g','\0'};

                ParameterName_NameSize = strlen(parameter_name);

                for(int j=0;j<ParameterName_NameSize;j++){

                    this->CodeLine[index_counter] = parameter_name[j];

                    index_counter++;
                }
             }
             else{

                    for(int j=0;j<ParameterName_NameSize;j++){

                        this->CodeLine[index_counter] = this->Data_Pointer->Parameter_Names[i][j];

                        index_counter++;
                    }
             }

             if(i< this->Data_Pointer->Parameter_Number -1){

                 this->CodeLine[index_counter] = ',';

                 index_counter++;

                 this->CodeLine[index_counter] = ' ';

                 index_counter++;
             }
        }
     }

     this->CodeLine[index_counter] = ')';

     index_counter++;

     this->CodeLine[index_counter] = '\0';
}

void MetaDataTranslater::DetermineInClassFunctionCallLine(){

     this->Clear_Pointer_Memory(&this->InClassFunctionCall);

     this->Memory_Delete_Condition = false;

     int ObjectNameSize = strlen(this->Object_Name);

     int MethodNameSize = strlen(this->Data_Pointer->Method_Name);

     this->ReturnTypeNameSize = strlen(this->Data_Pointer->Return_Type);

     int ParameterNames_NameSize = 0;

     if(this->Data_Pointer->Parameter_Number > 0){

        for(int i=0;i<this->Data_Pointer->Parameter_Number;i++){

            ParameterNames_NameSize = ParameterNames_NameSize + strlen(this->Data_Pointer->Parameter_Names[i]);
        }
     }

     int FunctionCallNameSize = ObjectNameSize + MethodNameSize + ParameterNames_NameSize + this->ReturnTypeNameSize;

     this->InClassFunctionCall = new char [10*FunctionCallNameSize];

     int index_counter = 0;

     for(int i=0;i<ObjectNameSize;i++){

         this->InClassFunctionCall[index_counter] = this->Object_Name[i];

         index_counter++;
     }

     this->InClassFunctionCall[index_counter] = '-';

     index_counter++;

     this->InClassFunctionCall[index_counter] = '>';

     index_counter++;

     for(int i=0;i<MethodNameSize;i++){

         this->InClassFunctionCall[index_counter] = this->Data_Pointer->Method_Name[i];

         index_counter++;
     }

     this->InClassFunctionCall[index_counter] = '(';

     index_counter++;

     if(this->Data_Pointer->Parameter_Number > 0){

         for(int i=0;i<this->Data_Pointer->Parameter_Number;i++){

             int ParameterName_NameSize = strlen(this->Data_Pointer->Parameter_Names[i]);

             if(ParameterName_NameSize == 0){

                char parameter_name [] = {'a','r','g','\0'};

                ParameterName_NameSize = strlen(parameter_name);

                for(int j=0;j<ParameterName_NameSize;j++){

                    this->InClassFunctionCall[index_counter] = parameter_name[j];

                    index_counter++;
                }
             }
             else{
                    for(int j=0;j<ParameterName_NameSize;j++){

                        this->InClassFunctionCall[index_counter] = this->Data_Pointer->Parameter_Names[i][j];

                        index_counter++;
                    }
             }

             if(i<this->Data_Pointer->Parameter_Number-1){

                 this->InClassFunctionCall[index_counter] = ',';

                 index_counter++;
             }
         }
       }

       this->InClassFunctionCall[index_counter] = ')';

       index_counter++;

       this->InClassFunctionCall[index_counter] = ';';

       index_counter++;

       this->InClassFunctionCall[index_counter] = '\0';
}

void MetaDataTranslater::DetermineFunctionCallLine(){

     this->Clear_Pointer_Memory(&this->FunctionCall);

     this->Memory_Delete_Condition = false;

     int MethodNameSize = strlen(this->Data_Pointer->Method_Name);

     int ParameterNames_NameSize = 0;

     if(this->Data_Pointer->Parameter_Number > 0){

        for(int i=0;i<this->Data_Pointer->Parameter_Number;i++){

            ParameterNames_NameSize = ParameterNames_NameSize + strlen(this->Data_Pointer->Parameter_Names[i]);
        }
     }

     int FunctionCallNameSize = MethodNameSize + ParameterNames_NameSize;

     this->FunctionCall = new char [10*FunctionCallNameSize];

     int index_counter = 0;

     for(int i=0;i<MethodNameSize;i++){

         this->FunctionCall[index_counter] = this->Data_Pointer->Method_Name[i];

         index_counter++;
     }

     this->FunctionCall[index_counter] = '(';

     index_counter++;

     if(this->Data_Pointer->Parameter_Number > 0){

        for(int i=0;i<this->Data_Pointer->Parameter_Number;i++){

            int ParameterName_NameSize = strlen(this->Data_Pointer->Parameter_Names[i]);

            if(ParameterName_NameSize == 0){

               char parameter_name [] = {'a','r','g','\0'};

               ParameterName_NameSize = strlen(parameter_name);

               for(int j=0;j<ParameterName_NameSize;j++){

                   this->FunctionCall[index_counter] = parameter_name[j];

                   index_counter++;
               }
            }
            else{

                  for(int j=0;j<ParameterName_NameSize;j++){

                      this->FunctionCall[index_counter] = this->Data_Pointer->Parameter_Names[i][j];

                      index_counter++;
                  }
            }

            if(i<this->Data_Pointer->Parameter_Number-1){

               this->FunctionCall[index_counter] = ',';

               index_counter++;
            }
       }
    }

    this->FunctionCall[index_counter] = ')';

    index_counter++;

    this->FunctionCall[index_counter] = ';';

    index_counter++;

    this->FunctionCall[index_counter] = '\0';
}

char * MetaDataTranslater::GetFunctionImplementationCodeLine(){

       return this->CodeLine;
}

char * MetaDataTranslater::GetInClassFunctionCallLine(){

       return this->InClassFunctionCall;
}

char * MetaDataTranslater::Get_Function_Call_Line(){

       return this->FunctionCall;
}

int MetaDataTranslater::GetReturnTypeNameSize(){

    return this->ReturnTypeNameSize;
}
