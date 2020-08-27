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

#include "MethodReader.h"

MethodReader::MethodReader(){

     this->Default_Null_List_Size = 5;

     this->PublicMethods    = nullptr;

     this->PrivateMethods   = nullptr;

     this->ProtectedMethods = nullptr;

     this->PublicMethodNumber = 0;

     this->PrivateMethodNumber = 0;

     this->ProtectedMethodNumber = 0;

     this->Memory_Delete_Condition = true;
}

MethodReader::MethodReader(const MethodReader & orig){ }

MethodReader::~MethodReader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void MethodReader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->PublicMethodNumber > 0){

            for(int i=0;i<this->PublicMethodNumber;i++){

                this->Clear_Pointer_Memory(&(this->PublicMethods[i]));
            }

            delete [] this->PublicMethods;

            this->PublicMethods = nullptr;
         }

         if(this->PrivateMethodNumber > 0){

            for(int i=0;i<this->PrivateMethodNumber;i++){

                this->Clear_Pointer_Memory(&(this->PrivateMethods[i]));
            }

            delete [] this->PrivateMethods;

            this->PrivateMethods = nullptr;
         }


         if(this->ProtectedMethodNumber > 0){

            for(int i=0;i<this->ProtectedMethodNumber;i++){

                this->Clear_Pointer_Memory(&(this->ProtectedMethods[i]));
            }

            delete [] this->ProtectedMethods;

            this->ProtectedMethods = nullptr;
         }
      }

      this->FileOrganizer.Clear_Dynamic_Memory();

      this->ClassNameDeterminer.Clear_Dynamic_Memory();
}

void MethodReader::Clear_Pointer_Memory(char ** Pointer){

     if(*Pointer != nullptr){

        delete [] (*Pointer);

        *Pointer = nullptr;
     }
}

void MethodReader::ReceiveIncludeDirectoryPATH(char * IncludeDirectoryPATH){

     this->FileOrganizer.ReceiveIncludeDirectoryPATH(IncludeDirectoryPATH);
}

void MethodReader::ReceiveDataBaseConstructionPoint(char * ConstructionPoint){

     this->FileOrganizer.ReceiveDataBaseConstructionPoint(ConstructionPoint);
}

void MethodReader::Receive_Header_File_Path(char * Target_Header_File_Path){

     this->FileOrganizer.Set_Target_Header_File_Path(Target_Header_File_Path);
}

void MethodReader::ReadFunctionDeclerations(){

     this->CurrentLineNumber = 0;

     this->ListLineNumber = 0;

     this->PublicMethodNumber = 0;

     this->PrivateMethodNumber = 0;

     this->ProtectedMethodNumber = 0;

     this->Memory_Delete_Condition = false;

     this->FileOrganizer.CollectInformations();

     this->DirectoryManager.ChangeDirectory(this->FileOrganizer.GetIncludeDirectoryPATH());

     this->FileManager.SetFilePath(this->FileOrganizer.GetHeaderFilePath());

     this->ClassNameDeterminer.ReadClassName(this->FileOrganizer.GetHeaderFilePath());

     if(this->ClassNameDeterminer.GetClassSyntaxErrorStatus()){

         std::cerr << "\n\n";

         std::cerr << "\n  # ERROR MESSAGE";

         std::cerr << "\n";

         std::cerr << "\n  # Message Type: Class Header File Read Error";

         std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

         std::cerr << "\n\n  {";

         std::cerr << "\n     There is a syntax error in class declarations";

         std::cerr << "\n\n     Class name can not be determined!";

         std::cerr << "\n\n     Please check class declarations..";

         std::cerr << "\n\n     The process has been interrupted.";

         std::cerr << "\n  }";

         std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";

         exit(EXIT_FAILURE);
     }

     this->SetPointExplorer.DetermineSetPoints(this->FileOrganizer.GetHeaderFilePath());

     this->ExtractClassMethods();

     this->ConstructMethodList();

     this->SetPointExplorer.Clear_Dynamic_Memory();

     this->DirectoryManager.Clear_Dynamic_Memory();

     this->CharacterOperations.Clear_Dynamic_Memory();

     this->FileManager.Clear_Dynamic_Memory();
}

void MethodReader::ConstructMethodList(){

     this->DirectoryManager.ChangeDirectory(this->FileOrganizer.GetDataBaseConstructionPoint());

     this->FileManager.SetFilePath(this->FileOrganizer.GetRecordFilePath());

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n ");

     this->ListLineNumber++;

     this->FileManager.WriteToFile(this->ClassNameDeterminer.getClassName());

     const char * MetaFileHeader = " Class Member Functions Signatures:\0";

     this->FileManager.WriteToFile(MetaFileHeader);

     if(this->PublicMethodNumber>0){

        this->FileManager.WriteToFile("\n\n");

        this->FileManager.WriteToFile(" public:");

        this->ListLineNumber = this->ListLineNumber + 4;

        this->PublicMethodsStartPoint = this->ListLineNumber;

        for(int i=0;i<this->PublicMethodNumber;i++){

            this->FileManager.WriteToFile("\n  ");

            this->FileManager.WriteToFile(this->PublicMethods[i]);

            this->ListLineNumber++;
        }
     }

     if(this->PrivateMethodNumber>0){

        this->FileManager.WriteToFile("\n\n");

        this->FileManager.WriteToFile(" private:");

        this->ListLineNumber = this->ListLineNumber + 2;

        this->PrivateMethodsStartPoint = this->ListLineNumber;

        for(int i=0;i<this->PrivateMethodNumber;i++){

            this->FileManager.WriteToFile("\n  ");

            this->FileManager.WriteToFile(this->PrivateMethods[i]);

            this->CurrentLineNumber++;
        }
     }

     if(this->ProtectedMethodNumber>0){

        this->FileManager.WriteToFile("\n\n");

        this->FileManager.WriteToFile(" protected:");

        this->ListLineNumber = this->ListLineNumber + 2;

        this->ProtectedMethodsStartPoint = this->ListLineNumber;

        for(int i=0;i<this->ProtectedMethodNumber;i++){

            this->FileManager.WriteToFile("\n  ");

            this->FileManager.WriteToFile(this->ProtectedMethods[i]);

            this->ListLineNumber++;
        }
     }

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile(" END");

     this->FileManager.FileClose();

     this->RecordListMetaData();
}

void MethodReader::ExtractClassMethods(){

    if(!this->SetPointExplorer.getAcessTypesError()){

        this->DeterminePublicMethods();

        this->DeterminePrivateMethods();

        this->DetermineProtectedMethods();
     }
     else{

            std::cerr << "\n\n";

            std::cerr << "\n  # ERROR MESSAGE";

            std::cerr << "\n";

            std::cerr << "\n  # Message Type: Class Header File Read Error";

            std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

            std::cerr << "\n\n  {";

            std::cerr << "\n     There is a syntax error in \"" << this->ClassNameDeterminer.getClassName() << "\" class -";

            std::cerr << "\n\n     decleration. The acess types of some functions can not be determined!";

            std::cerr << "\n\n     Please check the function declerations..";

            std::cerr << "\n\n     The process has been interrupted.";

            std::cerr << "\n  }";

            std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";

            exit(EXIT_FAILURE);
     }
}

void MethodReader::DeterminePublicMethods(){

     this->PublicMethodNumber = 0;

     if(this->SetPointExplorer.isTherePublicMethod()){

        this->FileManager.FileOpen(R);

        this->CurrentLineNumber = this->SetPointExplorer.getPublicLineNumber()+1;

        this->CharacterOperations.ForwardFilePointer(&this->FileManager,this->CurrentLineNumber);

        int PublicArea = this->SetPointExplorer.getPublicDeclerationArea();

        this->PublicMethods = new char * [10*PublicArea];

        for(int i=0;i<PublicArea;i++){

            char * MethodLine = this->FileManager.ReadLine();

            bool is_This_A_Method_Line = this->IsMethodLine(MethodLine);

            if(is_This_A_Method_Line){

               this->SyntaxOperations = new SyntaxController;

               this->SyntaxOperations->ReceiveClassContructorName(this->ClassNameDeterminer.getClassName());

               this->SyntaxOperations->ReceiveMethod(MethodLine);

               this->SyntaxOperations->CheckMethodSyntax();

               if(this->SyntaxOperations->getSyntaxErrorCondition()){

                  std::cerr << "\n";

                  std::cerr << "\n  # Message Type: Class Header File Read Error";

                  std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

                  std::cerr << "\n\n  {";

                  std::cerr << "\n     There is a syntax error in \"" << this->ClassNameDeterminer.getClassName() << "\" class -";

                  std::cerr << "\n\n     public member function declerations. Please check class decleration.";

                  std::cerr << "\n\n     The process has been interrupted.";

                  std::cerr << "\n  }";

                  std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";

                  exit(EXIT_FAILURE);
               }

               int String_Size = strlen(this->SyntaxOperations->getMethodLine());

               this->PublicMethods[this->PublicMethodNumber] = new char [10*String_Size];

               this->ReceiveMethodLine(&(this->PublicMethods[this->PublicMethodNumber]),this->SyntaxOperations->getMethodLine());

               this->PublicMethodNumber++;

               delete this->SyntaxOperations;
            }
        }

        this->FileManager.FileClose();
     }
}

void MethodReader::DeterminePrivateMethods(){

     this->PrivateMethodNumber = 0;

     if(this->SetPointExplorer.isTherePrivateMethod()){

        this->FileManager.FileOpen(R);

        this->CurrentLineNumber = this->SetPointExplorer.getPrivateLineNumber()+1;

        this->CharacterOperations.ForwardFilePointer(&this->FileManager,this->CurrentLineNumber);

        int PrivateArea = this->SetPointExplorer.getPrivateDeclerationArea();

        this->PrivateMethods = new char * [10*PrivateArea];

        for(int i=0;i<PrivateArea;i++){

            char * MethodLine = this->FileManager.ReadLine();

            bool is_This_A_Method_Line = this->IsMethodLine(MethodLine);

            if(is_This_A_Method_Line){

               this->SyntaxOperations = new SyntaxController;

               this->SyntaxOperations->ReceiveClassContructorName(this->ClassNameDeterminer.getClassName());

               this->SyntaxOperations->ReceiveMethod(MethodLine);

               this->SyntaxOperations->CheckMethodSyntax();

               if(this->SyntaxOperations->getSyntaxErrorCondition()){

                  std::cerr << "\n\n";

                  std::cerr << "\n  # ERROR MESSAGE";

                  std::cerr << "\n";

                  std::cerr << "\n  # Message Type: Class Header File Read Error";

                  std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

                  std::cerr << "\n\n  {";

                  std::cerr << "\n     There is a syntax error in \"" << this->ClassNameDeterminer.getClassName() << "\" class -";

                  std::cerr << "\n\n     private member function declarations.";

                  std::cerr << "\n\n     Please check class decleration.";

                  std::cerr << "\n\n     The process has been interrupted.";

                  std::cerr << "\n  }";

                  std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";

                  exit(EXIT_FAILURE);
               }

               int String_Size = strlen(this->SyntaxOperations->getMethodLine());

               this->PrivateMethods[this->PrivateMethodNumber] = new char [10*String_Size];

               this->ReceiveMethodLine(&this->PrivateMethods[this->PrivateMethodNumber],this->SyntaxOperations->getMethodLine());

               this->PrivateMethodNumber++;

               delete this->SyntaxOperations;
           }
        }

        this->FileManager.FileClose();
     }
}

void MethodReader::DetermineProtectedMethods(){

     this->ProtectedMethodNumber = 0;

     if(this->SetPointExplorer.isThereProtectedMethod()){

        this->FileManager.FileOpen(R);

        this->CurrentLineNumber = this->SetPointExplorer.getProtectedLineNumber()+1;

        this->CharacterOperations.ForwardFilePointer(&this->FileManager,this->CurrentLineNumber);

        int ProtectedArea = this->SetPointExplorer.getProtectedDeclerationArea();

        this->ProtectedMethods = new char * [10*ProtectedArea];

        for(int i=0;i<ProtectedArea;i++){

            char * MethodLine = this->FileManager.ReadLine();

            bool is_This_A_Method_Line = this->IsMethodLine(MethodLine);

            if(is_This_A_Method_Line){

               this->SyntaxOperations = new SyntaxController;

               this->SyntaxOperations->ReceiveClassContructorName(this->ClassNameDeterminer.getClassName());

               this->SyntaxOperations->ReceiveMethod(MethodLine);

               this->SyntaxOperations->CheckMethodSyntax();

               if(this->SyntaxOperations->getSyntaxErrorCondition()){

                  std::cerr << "\n\n";

                  std::cerr << "\n  # ERROR MESSAGE";

                  std::cerr << "\n";

                  std::cerr << "\n  # Message Type: Class Header File Read Error";

                  std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

                  std::cerr << "\n\n  {";

                  std::cerr << "\n     There is a syntax error in \"" << this->ClassNameDeterminer.getClassName() << "\" class -";

                  std::cerr << "\n\n     protected methods declarations.";

                  std::cerr << "\n\n     Please check class decleration.";

                  std::cerr << "\n\n     The process has been interrupted.";

                  std::cerr << "\n  }";

                  std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";

                  exit(EXIT_FAILURE);
               }

               int String_Size = strlen(this->SyntaxOperations->getMethodLine());

               this->ProtectedMethods[this->ProtectedMethodNumber] = new char [10*String_Size];

               this->ReceiveMethodLine(&this->ProtectedMethods[this->ProtectedMethodNumber],this->SyntaxOperations->getMethodLine());

               this->ProtectedMethodNumber++;

               delete this->SyntaxOperations;
            }
        }

        this->FileManager.FileClose();
     }
}

void MethodReader::ReceiveMethodLine(char ** MethodPointer,char * MethodLine){

     int MethodLineSize = strlen(MethodLine);

     int index_counter = 0;

     for(int i=0;i<MethodLineSize;i++){

         if(MethodLine[i] != '\n'){

            (*MethodPointer)[index_counter] = MethodLine[i];

            index_counter++;
         }
     }

     (*MethodPointer)[index_counter] = '\0';
}

bool MethodReader::IsMethodLine(char * ListLine){

     bool isThereFirstBrace = this->CharacterOperations.CharacterCheck(ListLine,'(');

     bool isThereLastBrace  = this->CharacterOperations.CharacterCheck(ListLine,')');

     if(isThereFirstBrace || isThereLastBrace){

         this->isMethodLine = true;
     }
     else{

         this->isMethodLine = false;
     }

     return this->isMethodLine;
}

void MethodReader::RecordListMetaData(){

     this->FileManager.SetFilePath(this->FileOrganizer.GetMetaDataFilePath());

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n METHOD LIST META DATAS");

     this->FileManager.WriteToFile("\n");

     if(this->SetPointExplorer.isTherePublicMethod()){

         this->FileManager.WriteToFile("\n PUBLIC METHODS");

         this->FileManager.WriteToFile("\n Public Method Number         :");

         this->FileManager.WriteToFile(this->TypeConverter.Translate(this->PublicMethodNumber));

         this->FileManager.WriteToFile("\n Public Methods Star Line     :");

         this->FileManager.WriteToFile(this->TypeConverter.Translate(this->PublicMethodsStartPoint));

         this->FileManager.WriteToFile("\n");
     }

     if(this->SetPointExplorer.isTherePrivateMethod()){

         this->FileManager.WriteToFile("\n PRIVATE METHODS");

         this->FileManager.WriteToFile("\n Private Method Number        :");

         this->FileManager.WriteToFile(this->TypeConverter.Translate(this->PrivateMethodNumber));

         this->FileManager.WriteToFile("\n Private Methods Start Line   :");

         this->FileManager.WriteToFile(this->TypeConverter.Translate(this->PrivateMethodsStartPoint));

         this->FileManager.WriteToFile("\n");
     }

     if(this->SetPointExplorer.isThereProtectedMethod()){

        this->FileManager.WriteToFile("\n PROTECTED METHODS");

        this->FileManager.WriteToFile("\n Protected Method Number      :");

        this->FileManager.WriteToFile(this->TypeConverter.Translate(this->ProtectedMethodNumber));

        this->FileManager.WriteToFile("\n Protected Methods Start Line :");

        this->FileManager.WriteToFile(this->TypeConverter.Translate(this->ProtectedMethodsStartPoint));

        this->FileManager.WriteToFile("\n");
     }

     this->FileManager.WriteToFile("\n END");

     this->FileManager.FileClose();
}

void MethodReader::Place_String(char ** Pointer, const char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void MethodReader::Place_String(char ** Pointer, char * String, int String_Size){

     for(int i=0;i<String_Size;i++){

         (*Pointer)[i] = String[i];
     }

     (*Pointer)[String_Size] = '\0';
}

void MethodReader::Place_Null(char ** Pointer, int List_Size){

     for(int i=0;i<List_Size;i++){

         (*Pointer)[i] = '\0';
     }
}

char * MethodReader::GetHeaderFilePath(){

       return this->FileOrganizer.GetHeaderFilePath();
}

char * MethodReader::GetRecordFilePath(){

       return this->FileOrganizer.GetRecordFilePath();
}

char * MethodReader::GetMetaDataFilePath(){

       return this->FileOrganizer.GetMetaDataFilePath();
}

char * MethodReader::GetIncludeDirectoryPATH(){

       return this->FileOrganizer.GetIncludeDirectoryPATH();
}

char * MethodReader::GetClassName(){

       return this->ClassNameDeterminer.getClassName();
}

char * MethodReader::GetDataRecordDirectory(){

       return this->FileOrganizer.GetDataBaseConstructionPoint();
}

int MethodReader::GetPublicMethodNumber(){

    return this->PublicMethodNumber;
}

int MethodReader::GetPrivateMethodNumber(){

    return this->PrivateMethodNumber;
}

int MethodReader::GetProtectedMethodNumber(){

    return this->ProtectedMethodNumber;
}

char ** MethodReader::GetPublicMethods(){

        return this->PublicMethods;
}

char ** MethodReader::GetPrivateMethods(){

        return this->PrivateMethods;
}

char ** MethodReader::GetProtectedMethods(){

        return this->ProtectedMethods;
}
