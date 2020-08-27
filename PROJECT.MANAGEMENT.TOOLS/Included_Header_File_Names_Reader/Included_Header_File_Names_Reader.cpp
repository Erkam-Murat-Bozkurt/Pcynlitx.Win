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


#include "Included_Header_File_Names_Reader.h"

Included_Header_File_Names_Reader::Included_Header_File_Names_Reader(){

      this->Memory_Delete_Condition = false;

      this->Included_Header_Files = nullptr;

      this->Included_Object_Files = nullptr;

      this->Header_File_Declarations = nullptr;

      this->Included_Header_Files_Number = 0;

      this->Class_Header_File_Name = "";

      this->Header_File_Declarations_C_String = nullptr;

      this->Header_File_Names_C_String = nullptr;
}

Included_Header_File_Names_Reader::Included_Header_File_Names_Reader(const Included_Header_File_Names_Reader & orig){

}

Included_Header_File_Names_Reader::~Included_Header_File_Names_Reader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void Included_Header_File_Names_Reader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Included_Header_Files != nullptr){

            delete [] this->Included_Header_Files;

            delete [] this->Included_Object_Files;

            this->Included_Header_Files = nullptr;

            this->Included_Object_Files = nullptr;
         }

         if(this->Header_File_Declarations != nullptr){

            delete [] this->Header_File_Declarations;

            this->Header_File_Declarations = nullptr;
         }

         if(this->Header_File_Declarations_C_String != nullptr){

            for(int i=0;i<this->Included_Header_Files_Number;i++){

                if(this->Header_File_Declarations_C_String != nullptr){

                   delete [] this->Header_File_Declarations_C_String[i];

                   this->Header_File_Declarations_C_String[i] = nullptr;
                }
            }

            delete [] this->Header_File_Declarations_C_String;
         }


         if(this->Header_File_Names_C_String != nullptr){

            for(int i=0;i<this->Included_Header_Files_Number;i++){

                if(this->Header_File_Names_C_String != nullptr){

                   delete [] this->Header_File_Names_C_String[i];

                   this->Header_File_Names_C_String[i] = nullptr;
                }
            }

            delete [] this->Header_File_Names_C_String;
         }
     }
}

void Included_Header_File_Names_Reader::Determine_Included_Header_File_Names(char * Header_File_Name){

     int Header_File_Name_Size = strlen(Header_File_Name);

     for(int i=0;i<Header_File_Name_Size;i++){

         this->Class_Header_File_Name.append(1,Header_File_Name[i]);
     }

     this->Determine_Class_Name(Header_File_Name);

     this->Determine_Included_Header_Files_Number();

     this->Read_Include_File_Names();

     this->Determine_Object_File_Names();

     this->Determine_C_String_Declarations();

     this->Determine_C_String_Header_File_Names();
}


void Included_Header_File_Names_Reader::Determine_Class_Name(char * Header_File_Name){

     this->CNR.ReadClassName(Header_File_Name);

     if(this->CNR.GetClassSyntaxErrorStatus()){

        std::cout << "\n There is a syntax error in ";

        std::cout << Header_File_Name << " header file decleration..";

        std::cout << "\n\n Please check decleraiton ..";

        std::cout << "\n\n The compiling process will be interrupted ..";

        exit(0);
     }

     int Class_Name_Size = strlen(this->CNR.getClassName());

     for(int i=0;i<Class_Name_Size;i++){

         this->Class_Name.append(1,this->CNR.getClassName()[i]);
     }

     this->Class_Name.append(1,'\0');

     this->CNR.Clear_Dynamic_Memory();

     std::string Source_File_Extension = ".cpp";

     std::string Object_File_Extension = ".o";

     this->Class_Source_File_Name = this->Class_Name + Source_File_Extension;

     this->Class_Object_File_Name = this->Class_Name + Object_File_Extension;
}

void Included_Header_File_Names_Reader::Determine_Included_Header_Files_Number(){

     std::string Header_File_Name(this->Class_Header_File_Name);

     this->DataFile.open(Header_File_Name,std::ios::in);

     this->Included_Header_Files_Number = 0;

     while(!this->DataFile.eof()){

            std::getline(this->DataFile,this->String_Line);

            if(this->Include_Line_Determiner(this->String_Line)){

               this->Included_Header_Files_Number++;

               for(int i=0;i<this->String_Line.length();i++){

                   if(this->String_Line[i] == '\"'){

                      int double_quotes_number = 0;

                      for(int k = 0;k<this->String_Line.length();k++){

                          if(this->String_Line[k] == '\"'){

                              double_quotes_number++;
                          }
                      }

                      if(double_quotes_number < 2){

                         std::cout << "\n There is a syntax error in ";

                         std::cout << Header_File_Name << " header file decleration..";

                         std::cout << "\n\n Please check decleraiton ..";

                         std::cout << "\n\n The compiling process will be interrupted ..";

                         exit(0);
                      }

                      break;
                  }
               }

              for(int i=0;i<this->String_Line.length();i++){

                  if(this->String_Line[i] == '<'){

                     int less_than_character_number = 0;

                     for(int k = 0;k<this->String_Line.length();k++){

                         if(((this->String_Line[k] == '<') || (this->String_Line[k] == '>'))){

                            less_than_character_number++;
                         }
                     }

                     if(less_than_character_number < 2){

                        std::cout << "\n There is a syntax error in ";

                        std::cout << Header_File_Name << " header file decleration..";

                        std::cout << "\n\n Please check decleraiton ..";

                        std::cout << "\n\n The compiling process will be interrupted ..";

                        exit(0);
                    }

                    break;
                 }
               }
            }
       }

       this->DataFile.close();
}


void Included_Header_File_Names_Reader::Read_Include_File_Names(){

     this->Memory_Delete_Condition = false;

     this->Included_Header_Files = new std::string [5*this->Included_Header_Files_Number];

     this->Header_File_Declarations = new std::string [5*this->Included_Header_Files_Number];

     std::string Header_File_Name(this->Class_Header_File_Name);

     this->DataFile.open(Header_File_Name,std::ios::in);

     int Included_Header_Files_Index_Counter = 0;

     while(!this->DataFile.eof()){

            std::getline(this->DataFile,this->String_Line);

            if(this->Include_Line_Determiner(this->String_Line)){

                for(int i=0;i<this->String_Line.length();i++){

                    if(((this->String_Line[i] == '\"') || (this->String_Line[i] == '<'))){

                       int Next_Marker_Position = i+1;

                       if(this->String_Line[i] == '\"'){

                          while(this->String_Line[Next_Marker_Position]!= '\"'){

                                Next_Marker_Position++;
                          }
                       }
                       else{

                             while(this->String_Line[Next_Marker_Position]!= '>'){

                                   Next_Marker_Position++;
                             }
                       }

                       for(int k=i+1;k<Next_Marker_Position;k++){

                           this->Included_Header_Files[Included_Header_Files_Index_Counter].append(1,this->String_Line[k]);
                       }


                       for(int k=i;k<Next_Marker_Position+1;k++){

                           this->Header_File_Declarations[Included_Header_Files_Index_Counter].append(1,this->String_Line[k]);
                       }

                       Included_Header_Files_Index_Counter++;

                       break;
                    }
              }
          }
     }

     this->DataFile.close();
}


void Included_Header_File_Names_Reader::Determine_Object_File_Names(){

     this->Memory_Delete_Condition = false;

     this->Included_Object_Files = new std::string [5*this->Included_Header_Files_Number];

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         int Header_File_Name_Size = this->Included_Header_Files[i].length();

         for(int k=0;k<Header_File_Name_Size;k++){

             if(this->Included_Header_Files[i][k] == '.'){

                this->Included_Object_Files[i].append(1,this->Included_Header_Files[i][k]);

                break;
             }
             else{

                   this->Included_Object_Files[i].append(1,this->Included_Header_Files[i][k]);
             }
         }

         this->Included_Object_Files[i].append(1,'o');

         this->Included_Object_Files[i].append(1,'\0');
     }
}

bool Included_Header_File_Names_Reader::Include_Line_Determiner(std::string String_Line){

     this->Include_Line_Condition = false;

     char Include_Word [] = {'i','n','c','l','u','d','e','\0'};

     int Include_Word_Character_Size = strlen(Include_Word);

     for(int i=0;i<String_Line.length();i++){

         if(String_Line[i] == Include_Word[0]){

            this->Include_Line_Condition = true;

            for(int k=0;k<Include_Word_Character_Size;k++){

               if(String_Line[i+k] != Include_Word[k]){

                  this->Include_Line_Condition = false;

                  break;
               }
            }

            break;
         }
     }

     return this->Include_Line_Condition;
}

void Included_Header_File_Names_Reader::Determine_C_String_Declarations(){

     this->Header_File_Declarations_C_String = new char * [5*this->Included_Header_Files_Number];

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         std::string header_name = this->Header_File_Declarations[i];

         this->Header_File_Declarations_C_String[i] = new char [5*header_name.length()];

         int index_counter = 0;

         for(int k=0;k< header_name.length();k++){

             this->Header_File_Declarations_C_String[i][index_counter] = header_name[k];

             index_counter++;
         }

         this->Header_File_Declarations_C_String[i][index_counter] = '\0';
     }
}

void Included_Header_File_Names_Reader::Determine_C_String_Header_File_Names(){

     this->Header_File_Names_C_String = new char * [5*this->Included_Header_Files_Number];

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         std::string header_name = this->Included_Header_Files[i];

         this->Header_File_Names_C_String[i] = new char [5*header_name.length()];

         int index_counter = 0;

         for(int k=0;k< header_name.length();k++){

             this->Header_File_Names_C_String[i][index_counter] = header_name[k];

             index_counter++;
         }

         this->Header_File_Names_C_String[i][index_counter] = '\0';
     }
}

std::string Included_Header_File_Names_Reader::Get_Class_Name(){

     return this->Class_Name;
}

std::string Included_Header_File_Names_Reader::Get_Class_Source_File_Name(){

     return this->Class_Source_File_Name;
}

std::string Included_Header_File_Names_Reader::Get_Class_Object_File_Name(){

    return this->Class_Object_File_Name;
}

std::string * Included_Header_File_Names_Reader::Get_Included_Header_File_Names(){

    return this->Included_Header_Files;
}

std::string * Included_Header_File_Names_Reader::Get_Included_Object_File_Names(){

   return this->Included_Object_Files;
}

std::string * Included_Header_File_Names_Reader::Get_Header_File_Declarations(){

    return this->Header_File_Declarations;
}

char ** Included_Header_File_Names_Reader::Get_Header_File_Declarations_C_String(){

     return this->Header_File_Declarations_C_String;
}

char ** Included_Header_File_Names_Reader::Get_Header_File_Names_C_String(){

        return this->Header_File_Names_C_String;
}

int Included_Header_File_Names_Reader::Get_Included_Header_File_Number(){

    return this->Included_Header_Files_Number;
}
