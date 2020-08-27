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

#include "MethodListReader.h"

MethodListReader::MethodListReader(){

      this->Memory_Delete_Condition = true;

      this->PublicMethods = nullptr;

      this->ProtectedMethods = nullptr;

      this->PrivateMethods = nullptr;

      this->PublicMethodNumber = 0;

      this->PrivateMethodNumber = 0;

      this->ProtectedMethodNumber = 0;

      this->Default_Empty_List_Size = 10;
}

MethodListReader::MethodListReader(const MethodListReader & orig){}

MethodListReader::~MethodListReader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void MethodListReader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         int Public_Method_List_Size = 0;

         if(this->PublicMethods != nullptr){

            if(this->PublicMethodNumber == 0){

               Public_Method_List_Size = this->Default_Empty_List_Size;
            }
            else{

                  Public_Method_List_Size = this->PublicMethodNumber;
            }

            for(int i=0;i<Public_Method_List_Size;i++){

                this->Clear_Pointer_Memory(&(this->PublicMethods[i]));
            }

            delete [] this->PublicMethods;

            this->PublicMethods = nullptr;
         }

         if(this->ProtectedMethods != nullptr){

            int Protected_Method_List_Size = 0;

            if(this->ProtectedMethodNumber == 0){

               Protected_Method_List_Size = this->Default_Empty_List_Size;
            }
            else{

                  Protected_Method_List_Size = this->ProtectedMethodNumber;
            }

            for(int i=0;i<Protected_Method_List_Size;i++){

                this->Clear_Pointer_Memory(&(this->ProtectedMethods[i]));
            }

            delete [] this->ProtectedMethods;

            this->ProtectedMethods = nullptr;
         }

         if(this->PrivateMethods != nullptr){

            int Private_Method_List_Size = 0;

            if(this->PrivateMethodNumber == 0){

               Private_Method_List_Size = this->Default_Empty_List_Size;
            }
            else{

                 Private_Method_List_Size = this->PrivateMethodNumber;
            }

            for(int i=0;i<Private_Method_List_Size;i++){

                this->Clear_Pointer_Memory(&(this->PrivateMethods[i]));
            }

            delete [] this->PrivateMethods;

            this->PrivateMethods = nullptr;
         }
      }
}

void MethodListReader::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void MethodListReader::SetMethodListPath(const char * MethodList){

     this->ListFileManager.SetFilePath(MethodList);
}

void MethodListReader::SetMetaFilePath(const char * MetaDataFile){

     this->MetaFileManager.SetFilePath(MetaDataFile);
}

void MethodListReader::SetMethodListPath(char * MethodList){

     this->ListFileManager.SetFilePath(MethodList);
}

void MethodListReader::SetMetaFilePath(char * MetaDataFile){

     this->MetaFileManager.SetFilePath(MetaDataFile);
}

void MethodListReader::ReadMethodList(){

     this->Memory_Delete_Condition = false;

     this->PublicMethodNumber = 0;

     this->PrivateMethodNumber = 0;

     this->ProtectedMethodNumber = 0;

     this->ListInterpreter.SetFilePath(this->MetaFileManager.GetFilePath());

     this->ListInterpreter.ReadMetaData();

     this->PublicMethodNumber        = this->ListInterpreter.GetPublicMethodNumber();

     this->PrivateMethodNumber       = this->ListInterpreter.GetPrivateMethodNumber();

     this->ProtectedMethodNumber     = this->ListInterpreter.GetProtectedMethodNumber();

     this->PublicMethodsStartLine    = this->ListInterpreter.GetPublicRecordsStartLine();

     this->PrivateMethodsStartLine   = this->ListInterpreter.GetPrivateRecordsStartLine();

     this->ProtectedMethodsStartLine = this->ListInterpreter.GetProtectedRecordsStartLine();

     this->ReadPublicMethods();

     this->ReadPrivateMethods();

     this->ReadProtectedMethods();

     this->DetermineTotalMethodNumber();

     this->ListInterpreter.Clear_Dynamic_Memory();

     this->ListFileManager.Clear_Dynamic_Memory();

     this->MetaFileManager.Clear_Dynamic_Memory();

     this->CharacterOperations.Clear_Dynamic_Memory();
}

void MethodListReader::ReadPublicMethods(){

     if(this->PublicMethodNumber == 0){

        int List_Size = this->Default_Empty_List_Size;

        this->PublicMethods = new char * [10*List_Size];

        for(int i=0;i<List_Size;i++){

            this->PublicMethods[i] = new char [10*List_Size];

            this->Place_Null(&(this->PublicMethods[i]),List_Size);
        }
     }
     else{

        this->ListFileManager.FileOpen(R);

        this->PublicMethods = new char * [10*(this->PublicMethodNumber)];

        this->CharacterOperations.ForwardFilePointer(&this->ListFileManager,this->PublicMethodsStartLine);

        for(int i=0;i<this->PublicMethodNumber;i++){

            char * LinePointer = this->ListFileManager.ReadLine();

            if(this->isThisMethodLine(LinePointer)){

               int Memory_Need = this->Get_Memory_Need(LinePointer);

               this->PublicMethods[i] = new char [10*Memory_Need];

               this->PlaceMethodLine(&(this->PublicMethods[i]),LinePointer,Memory_Need);
            }
            else{

                 int List_Size = this->Default_Empty_List_Size;

                 this->PublicMethods[i] = new char [10*List_Size];

                 this->Place_Null(&(this->PublicMethods[i]),List_Size);
            }
        }

        this->ListFileManager.FileClose();
     }
}


void MethodListReader::ReadPrivateMethods(){

     if(this->PrivateMethodNumber == 0){

        int List_Size = this->Default_Empty_List_Size;

        this->PrivateMethods = new char * [10*List_Size];

        for(int i=0;i<List_Size;i++){

            this->PrivateMethods[i] = new char [10*List_Size];

            this->Place_Null(&(this->PrivateMethods[i]),List_Size);
        }
     }
     else{

          this->ListFileManager.FileOpen(R);

          this->PrivateMethods = new char * [10*(this->PrivateMethodNumber)];

          this->CharacterOperations.ForwardFilePointer(&this->ListFileManager,this->PrivateMethodsStartLine);

          for(int i=0;i<this->PrivateMethodNumber;i++){

              char * LinePointer = this->ListFileManager.ReadLine();

              if(this->isThisMethodLine(LinePointer)){

                 int Memory_Need = this->Get_Memory_Need(LinePointer);

                 this->PrivateMethods[i] = new char [10*Memory_Need];

                 this->PlaceMethodLine(&(this->PrivateMethods[i]),LinePointer,Memory_Need);
              }
              else{

                   int List_Size = this->Default_Empty_List_Size;

                   this->PrivateMethods[i] = new char [10*List_Size];

                   this->Place_Null(&(this->PrivateMethods[i]),List_Size);
              }
          }

          this->ListFileManager.FileClose();
     }
}


void MethodListReader::ReadProtectedMethods(){

     if(this->ProtectedMethodNumber == 0){

          int List_Size = this->Default_Empty_List_Size;

          this->ProtectedMethods = new char * [10*List_Size];

          for(int i=0;i<List_Size;i++){

             this->ProtectedMethods[i] = new char [10*List_Size];

             this->Place_Null(&(this->ProtectedMethods[i]),List_Size);
          }
     }
     else{

          this->ListFileManager.FileOpen(R);

          this->ProtectedMethods = new char * [10*(this->ProtectedMethodNumber)];

          this->CharacterOperations.ForwardFilePointer(&this->ListFileManager,this->ProtectedMethodsStartLine);

          for(int i=0;i<this->ProtectedMethodNumber;i++){

              char * LinePointer = this->ListFileManager.ReadLine();

              if(this->isThisMethodLine(LinePointer)){

                   int Memory_Need = this->Get_Memory_Need(LinePointer);

                   this->ProtectedMethods[i] = new char [10*Memory_Need];

                   this->PlaceMethodLine(&(this->ProtectedMethods[i]),LinePointer,Memory_Need);
              }
              else{

                   int List_Size = this->Default_Empty_List_Size;

                   this->ProtectedMethods[i] = new char [10*List_Size];

                   this->Place_Null(&(this->ProtectedMethods[i]),List_Size);
              }
         }

         this->ListFileManager.FileClose();
     }
}

bool MethodListReader::isThisMethodLine(char * LinePointer){

     this->isMethodLine = false;

     int braceNumber = this->CharacterOperations.DetermineCharacterRepitation(LinePointer,'(');

     if(braceNumber > 0){

        this->isMethodLine = true;
     }

     return  this->isMethodLine;
}

int MethodListReader::Get_Memory_Need(char * LinePointer){

    int ListSize = this->CharacterOperations.CharListLength(LinePointer);

    int spaceCounter = 0;

    while(LinePointer[spaceCounter] == ' '){

          spaceCounter++;
    }

    this->Memory_Need = ListSize - spaceCounter;

    return this->Memory_Need;
}

void MethodListReader::PlaceMethodLine(char ** MethodPointer,char * LinePointer, int MemoryNeed){

     int spaceCounter = 0;

     while(LinePointer[spaceCounter] == ' '){

           spaceCounter++;
     }

     for(int i=0;i<MemoryNeed;i++){

        (*MethodPointer)[i] = LinePointer[i+spaceCounter];

        if((*MethodPointer)[i] == '\n'){

            (*MethodPointer)[i] = '\0';
        }
     }

     (*MethodPointer)[MemoryNeed] = '\0';
}

void MethodListReader::Place_Null(char ** Pointer, int size){

     for(int i=0;i<size;i++){

        (*Pointer)[i] = '\0';
     }
}


void MethodListReader::DetermineTotalMethodNumber(){

     this->TotalMethodNumber = this->PublicMethodNumber + this->PrivateMethodNumber + this->ProtectedMethodNumber;
}

char ** MethodListReader::GetPublicMethods(){

        return this->PublicMethods;
}

char ** MethodListReader::GetPrivateMethods(){

        return this->PrivateMethods;
}

char ** MethodListReader::GetProtectedMethods(){

        return this->ProtectedMethods;
}

int MethodListReader::GetPublicMethodNumber(){

    return this->PublicMethodNumber;
}

int MethodListReader::GetPrivateMethodNumber(){

    return this->PrivateMethodNumber;
}

int MethodListReader::GetProtectedMethodNumber(){

    return this->ProtectedMethodNumber;
}

int MethodListReader::GetTotalMethodNumber(){

    return this->TotalMethodNumber;
}
