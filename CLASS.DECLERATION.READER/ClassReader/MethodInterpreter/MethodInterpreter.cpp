/*

Copyright ©  2021,  Erkam Murat Bozkurt

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


#include "MethodInterpreter.h"

MethodInterpreter::MethodInterpreter(){

      this->SyntaxErrorCondition = false;

      this->Memory_Delete_Condition = true;

      this->ClassName = nullptr;

      this->MethodAccessType = nullptr;

      this->ReturnType = nullptr;

      this->MethodName = nullptr;

      this->ParameterTypes = nullptr;

      this->ParameterNames = nullptr;

      this->Default_Empty_List_Size = 10;
}

MethodInterpreter::MethodInterpreter(const MethodInterpreter & orig){ }

MethodInterpreter::~MethodInterpreter(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
}

void MethodInterpreter::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_String_List(&this->ClassName);

         this->Clear_String_List(&this->MethodAccessType);

         this->Clear_String_List(&this->ReturnType);

         this->Clear_String_List(&this->MethodName);

         int List_Size = 0;

         if((this->MethodParameterNumber == 0) || (this->getMethodSyntaxErrorStatus())){

             List_Size = this->Default_Empty_List_Size;
         }
         else{

             List_Size = this->MethodParameterNumber;
         }

         if(this->ParameterTypes != nullptr){

            for(int i=0;i<List_Size;i++){

                this->Clear_String_List(&(this->ParameterTypes[i]));

                this->Clear_String_List(&(this->ParameterNames[i]));
             }

             delete [] this->ParameterTypes;

             this->ParameterTypes = nullptr;
         }

         if(this->ParameterNames != nullptr){

            for(int i=0;i<List_Size;i++){

                this->Clear_String_List(&(this->ParameterNames[i]));
            }

            delete [] this->ParameterNames;

            this->ParameterNames = nullptr;
         }
      }
}

void MethodInterpreter::ReceiveMethodLine(char * MethodLine){

     this->SyntaxErrorCondition = false;

     this->Memory_Delete_Condition = false;

     this->MethodLineReceiver.ReceiveMethodLine(MethodLine);

     this->MethodReturnTypeReader.SetSyntaxErrorStatus(this->MethodLineReceiver.getMethodSyntaxErrorStatus());

     this->MethodNameReader.SetSyntaxErrorStatus(this->MethodLineReceiver.getMethodSyntaxErrorStatus());

     this->MethodParameterReader.SetSyntaxErrorStatus(this->MethodLineReceiver.getMethodSyntaxErrorStatus());

     this->setMethodSyntaxErrorStatus(this->MethodLineReceiver.getMethodSyntaxErrorStatus());

     this->MethodReturnTypeReader.SetClassConstructorStatus(this->MethodLineReceiver.getClassConstructorStatus());

     this->MethodReturnTypeReader.SetClassDestructorStatus(this->MethodLineReceiver.getClassDestructorStatus());

     this->MethodNameReader.SetClassConstructorStatus(this->MethodLineReceiver.getClassConstructorStatus());

     this->MethodNameReader.SetClassDestructorStatus(this->MethodLineReceiver.getClassDestructorStatus());

     this->MethodParameterReader.SetMethodParameterNumber(this->MethodLineReceiver.getMethodParameterNumber());

     this->MethodReturnTypeReader.SetMethodLine(MethodLine);

     this->MethodNameReader.SetMethodLine(MethodLine);

     this->MethodParameterReader.SetMethodParenthes(this->MethodLineReceiver.getMethodParenthes());

     this->SetMethodParameterNumber(this->MethodLineReceiver.getMethodParameterNumber());
}

void MethodInterpreter::ReadMethod(){

     this->MethodNameReader.DetermineMethodName();

     this->MethodReturnTypeReader.Receive_Method_Name(this->MethodNameReader.GetMethodName());

     this->MethodReturnTypeReader.DetermineMethodReturnType();

     this->SetMethodReturnType(this->MethodReturnTypeReader.GetMethodReturnType());

     this->SetMethodName(this->MethodNameReader.GetMethodName());

     this->MethodParameterReader.Read_Parameter_Informations();

     this->SetParameterTypes(this->MethodParameterReader.GetMethodParameterTypes());

     this->SetParameterNames(this->MethodParameterReader.GetMethodParameterNames());

     this->MethodLineReceiver.Clear_Dynamic_Memory();

     this->MethodReturnTypeReader.Clear_Dynamic_Memory();

     this->MethodNameReader.Clear_Dynamic_Memory();

     this->MethodParameterReader.Clear_Dynamic_Memory();
}

void MethodInterpreter::setMethodAccessType(char * Acess_Type){

     int List_Size = strlen(Acess_Type);

     this->MethodAccessType = new char [10*List_Size];

     this->Place_String_List(&this->MethodAccessType,Acess_Type,List_Size);
}

void MethodInterpreter::SetClassName(char * ClassName){

     int List_Size = strlen(ClassName);

     this->ClassName = new char [10*List_Size];

     this->Place_String_List(&this->ClassName,ClassName,List_Size);

     this->MethodLineReceiver.SetClassName(ClassName);
}

void MethodInterpreter::SetMethodReturnType(char * Return_Type){

     if((Return_Type[0] == '\0') || this->getMethodSyntaxErrorStatus()){

          this->ReturnType = new char [10];

          this->Place_Null(&this->ReturnType,5);
     }
     else{
            int List_Size = strlen(Return_Type);

            this->ReturnType = new char [10*List_Size];

            this->Place_String_List(&this->ReturnType,Return_Type,List_Size);
     }
}

void MethodInterpreter::SetMethodName(char * Method_Name){

     if(!this->getMethodSyntaxErrorStatus()){

        int List_Size = strlen(Method_Name);

        this->MethodName = new char [10*List_Size];

        this->Place_String_List(&this->MethodName,Method_Name,List_Size);
    }
    else{

         this->MethodName = new char [10];

         this->Place_Null(&this->MethodName,5);
    }
}

void MethodInterpreter::SetParameterTypes(char ** ParameterTypes){

     if((this->MethodParameterNumber == 0) || (this->getMethodSyntaxErrorStatus())){

         int List_Size = this->Default_Empty_List_Size;

         this->ParameterTypes = new char * [10*List_Size];

         for(int i=0;i<List_Size;i++){

             this->ParameterTypes[i] = new char [10*List_Size];

             this->Place_Null(&(this->ParameterTypes[i]),List_Size);
         }
     }
     else{

         this->ParameterTypes = new char * [10*this->MethodParameterNumber];

         for(int i=0;i<this->MethodParameterNumber;i++){

              int List_Size = strlen(ParameterTypes[i]);

              this->ParameterTypes[i] = new char [10*List_Size];

              this->Place_String_List(&this->ParameterTypes[i],ParameterTypes[i],List_Size);
         }
     }
}

void MethodInterpreter::SetParameterNames(char ** ParameterNames){

     if((this->MethodParameterNumber == 0) || (this->getMethodSyntaxErrorStatus())){

        int List_Size = this->Default_Empty_List_Size;

        this->ParameterNames = new char * [10*List_Size];

        for(int i=0;i<List_Size;i++){

            this->ParameterNames[i] = new char [10*List_Size];

            this->Place_Null(&(this->ParameterNames[i]),List_Size);
        }
     }
     else{

        this->ParameterNames = new char * [10*this->MethodParameterNumber];

        for(int i=0;i<this->MethodParameterNumber;i++){

            int List_Size = strlen(ParameterNames[i]);

            if(List_Size == 0){

                 this->ParameterNames[i] = new char [10];

                 for(int k = 0;k<10;k++){

                     this->ParameterNames[i][k] = '\0';
                 }
            }
            else{

                   this->ParameterNames[i] = new char [10*List_Size];

                   this->Place_String_List(&this->ParameterNames[i],ParameterNames[i],List_Size);
            }
        }
     }
}

void MethodInterpreter::Place_String_List(char ** Pointer, char * String, int List_Size){

     for(int i=0;i<List_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[List_Size] = '\0';
}

void MethodInterpreter::Place_Null(char ** Pointer, int size){

     for(int i=0;i<size;i++){

        (*Pointer)[i] = '\0';
     }
}

void MethodInterpreter::Clear_String_List(char ** Pointer){

     if( *Pointer != nullptr){

          delete [] (*Pointer);

          *Pointer = nullptr;
     }
}


void MethodInterpreter::setMethodIDNumber(int IDNumber){

     this->MethodIDNumber = IDNumber;
}

int MethodInterpreter::getMethodIDNumber(){

    return this->MethodIDNumber;
}

int MethodInterpreter::getMethodParameterNumber(){

    return this->MethodParameterNumber;
}

char * MethodInterpreter::getMethodName(){

    return this->MethodName;
}

char * MethodInterpreter::getMethodAccessType(){

    return this->MethodAccessType;
}

char * MethodInterpreter::getMethodReturnType(){

    return this->ReturnType;
}

char ** MethodInterpreter::getMethodParameterTypes(){

    return this->ParameterTypes;
}

char ** MethodInterpreter::getMethodParameterNames(){

    return this->ParameterNames;
}

bool MethodInterpreter::getMethodSyntaxErrorStatus(){

     return this->SyntaxErrorCondition;
}

void MethodInterpreter::setMethodSyntaxErrorStatus(bool condition){

     this->SyntaxErrorCondition = condition ;
}

void MethodInterpreter::SetMethodParameterNumber(int Number){

     this->MethodParameterNumber = Number;
}

char * MethodInterpreter::GetClassName(){

     return this->ClassName;
}
