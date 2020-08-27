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

#include "MethodListInterpreter.h"

MethodListInterpreter::MethodListInterpreter(){

      this->Memory_Delete_Condition = true;

      this->public_decleration_marker = nullptr;

      this->private_decleration_marker = nullptr;

      this->protected_decleration_marker = nullptr;

      this->record_end_marker = nullptr;

      this->FilePath = nullptr;

      this->PublicMethodNumber = 0;

      this->PrivateMethodNumber = 0;

      this->ProtectedMethodNumber = 0;

      this->publicLineNumber = 0;

      this->privateLineNumber = 0;

      this->protectedLineNumber = 0;

      this->RecordEndLine = 0;

      this->isTherePublicDecleration = false;

      this->isTherePrivateDecleration = false;

      this->isThereProtectedDecleration = false;
}

MethodListInterpreter::MethodListInterpreter(const MethodListInterpreter &orig){ }

MethodListInterpreter::~MethodListInterpreter(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
}

void MethodListInterpreter::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->PublicMethodNumber    = 0;

         this->PrivateMethodNumber   = 0;

         this->ProtectedMethodNumber = 0;

         this->publicLineNumber = 0;

         this->privateLineNumber = 0;

         this->protectedLineNumber = 0;

         this->isTherePublicDecleration    = false;

         this->isTherePrivateDecleration   = false;

         this->isThereProtectedDecleration = false;

         this->Clear_String_List(&this->public_decleration_marker);

         this->Clear_String_List(&this->private_decleration_marker);

         this->Clear_String_List(&this->protected_decleration_marker);

         this->Clear_String_List(&this->record_end_marker);

         this->Clear_String_List(&this->FilePath);
     }
}

void MethodListInterpreter::SetFilePath(const char * TargetFileName){

     int String_Size = strlen(TargetFileName);

     this->FilePath = new char [10*String_Size];

     for(int i=0;i<String_Size;i++){

         this->FilePath[i] = TargetFileName[i];
     }

     this->FilePath[String_Size] = '\0';
}

void MethodListInterpreter::SetFilePath(char * TargetFileName){

     int String_Size = strlen(TargetFileName);

     this->FilePath = new char [10*String_Size];

     for(int i=0;i<String_Size;i++){

         this->FilePath[i] = TargetFileName[i];
     }

     this->FilePath[String_Size] = '\0';
}

void MethodListInterpreter::ReadMetaData(){

     this->Memory_Delete_Condition = false;

     this->StringOperations.SetFilePath(this->FilePath);

     this->SetupSetPointMarkers();

     this->DetermineMethodAcessTypes();

     if(this->isTherePublicDecleration){

         this->ReadReferenceNumbers(this->public_decleration_marker,&this->PublicMethodNumber,&this->publicLineNumber);
     }
     else{

          this->PublicMethodNumber = 0;
     }

     if(this->isTherePrivateDecleration){

         this->ReadReferenceNumbers(this->private_decleration_marker,&this->PrivateMethodNumber,&this->privateLineNumber);
     }
     else{

          this->PrivateMethodNumber = 0;
     }

     if(this->isThereProtectedDecleration){

        this->ReadReferenceNumbers(this->protected_decleration_marker,&this->ProtectedMethodNumber,&this->protectedLineNumber);
     }
     else{

          this->ProtectedMethodNumber = 0;
     }

     this->CharacterOperations.Clear_Dynamic_Memory();

     this->StringOperations.Clear_Dynamic_Memory();
}

void MethodListInterpreter::SearchDeclerationMarker(char * DeclerationMarker,bool * existance_condition){

     int Start_Point = 1;

     int Word_Line = this->StringOperations.FindNextWordLine(DeclerationMarker,Start_Point);

     if(Word_Line < this->RecordEndLine){

        *existance_condition = true;
     }
}

void MethodListInterpreter::SetupSetPointMarkers(){

     char public_decleration_word []  = {'P','U','B','L','I','C',' ','M','E','T','H','O','D','S','\0'};

     char private_decleration_word [] = {'P','R','I','V','A','T','E',' ','M','E','T','H','O','D','S','\0'};

     char protected_decleration_word [] = {'P','R','O','T','E','C','T','E','D',' ','M','E','T','H','O','D','S','\0'};

     char record_end_word [] = {'E','N','D','\0'};

     int Public_Word_Size = strlen( public_decleration_word);

     int Private_Word_Size = strlen(private_decleration_word);

     int Protected_Word_Size = strlen(protected_decleration_word);

     int End_Word_Size = strlen(record_end_word);

     this->public_decleration_marker    = new char [10*Public_Word_Size];

     this->private_decleration_marker   = new char [10*Private_Word_Size];

     this->protected_decleration_marker = new char [10*Protected_Word_Size];

     this->record_end_marker = new char [10*End_Word_Size];

     this->Place_String_List(&this->public_decleration_marker,public_decleration_word,Public_Word_Size);

     this->Place_String_List(&this->private_decleration_marker,private_decleration_word,Private_Word_Size);

     this->Place_String_List(&this->protected_decleration_marker,protected_decleration_word,Protected_Word_Size);

     this->Place_String_List(&this->record_end_marker,record_end_word,End_Word_Size);
}

void MethodListInterpreter::DetermineMethodAcessTypes(){

     int StartPoint = 1;

     this->RecordEndLine = this->StringOperations.FindNextWordLine(this->record_end_marker,StartPoint);

     this->SearchDeclerationMarker(this->public_decleration_marker,&this->isTherePublicDecleration);

     this->SearchDeclerationMarker(this->private_decleration_marker,&this->isTherePrivateDecleration);

     this->SearchDeclerationMarker(this->protected_decleration_marker,&this->isThereProtectedDecleration);
}

int MethodListInterpreter::ReadRecordedInformation(char * linePointer){

    int Start_Point = 0, index_counter = 0;

    int line_Size = strlen(linePointer);

    char * buffer = nullptr;

    if(line_Size > 0){

       char buffer[5*line_Size];

       while(linePointer[Start_Point]!=':'){

             Start_Point++;
       }

       for(int i=Start_Point+1;i<line_Size;i++){

           if(!((linePointer[i] == ' ') || (linePointer[i] == '\n'))){

                 buffer[index_counter] = linePointer[i];

                 index_counter++;
           }
       }

       buffer[index_counter] = '\0';

       this->RecordInformation = this->Translater.TranslateFromCharToInt(buffer);
    }
    else{

          char buffer[5];

          for(int i=0;i<5;i++){

             buffer[i] = '\0';
          }

          this->RecordInformation = this->Translater.TranslateFromCharToInt(buffer);
    }

    return this->RecordInformation;
}

void MethodListInterpreter::ReadReferenceNumbers(char * DeclerationMarker,int * Method_Number, int * Line_Number){

     int Start_Point = 1;

     int Decleration_Start_Point = this->StringOperations.FindNextWordLine(DeclerationMarker,Start_Point);

     this->StringOperations.ReadFileLine(Decleration_Start_Point+1);

     *Method_Number = this->ReadRecordedInformation(this->StringOperations.GetStringBuffer());

     this->StringOperations.ReadFileLine(Decleration_Start_Point+2);

     *Line_Number =  this->ReadRecordedInformation(this->StringOperations.GetStringBuffer());
}

void MethodListInterpreter::Place_String_List(char ** Pointer, char * String_List, int List_Size){

      for(int i=0;i<List_Size;i++){

          (*Pointer)[i] = String_List[i];
      }

      (*Pointer)[List_Size] = '\0';
}

void MethodListInterpreter::Place_Null_For_String_List(char ** String_List, int size){

     for(int i=0;i<size;i++){

        (*String_List)[i] = '\0';
     }
}

void MethodListInterpreter::Clear_String_List(char ** Pointer){

     if(*Pointer != nullptr){

         delete [] (*Pointer);

         *Pointer = nullptr;
     }
}

int  MethodListInterpreter::GetPublicMethodNumber(){

     return this->PublicMethodNumber;
}

int MethodListInterpreter::GetPrivateMethodNumber(){

    return this->PrivateMethodNumber;
}

int MethodListInterpreter::GetProtectedMethodNumber(){

    return this->ProtectedMethodNumber;
}

bool MethodListInterpreter::GetPublicDeclerationExistance(){

     return this->isTherePublicDecleration;
}

bool MethodListInterpreter::GetPrivateDeclerationExistance(){

     return this->isTherePrivateDecleration;
}

bool MethodListInterpreter::GetProtectedDeclerationExistance(){

     return this->isThereProtectedDecleration;
}

int MethodListInterpreter::GetPublicRecordsStartLine(){

    return this->publicLineNumber;
}

int MethodListInterpreter::GetPrivateRecordsStartLine(){

    return this->privateLineNumber;
}

int MethodListInterpreter::GetProtectedRecordsStartLine(){

    return this->protectedLineNumber;
}
