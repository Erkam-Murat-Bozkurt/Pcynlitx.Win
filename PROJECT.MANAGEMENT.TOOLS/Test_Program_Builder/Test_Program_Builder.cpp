
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

#include "Test_Program_Builder.h"

Test_Program_Builder::Test_Program_Builder(){

   this->Memory_Delete_Condition = false;

   this->Compiler_System_Command = nullptr;

   this->Class_Name = nullptr;

   this->Class_Header_File_Name = nullptr;

   this->Class_Object_File_Name = nullptr;

   this->Executable_File_Name = nullptr;

   this->Main_File_Name = nullptr;

   this->Included_Header_Files = nullptr;

   this->Included_Object_Files = nullptr;

   this->Included_Header_Files_Number = 0;
}

Test_Program_Builder::Test_Program_Builder(const Test_Program_Builder & orig){

}

Test_Program_Builder::~Test_Program_Builder(){

   if(!this->Memory_Delete_Condition){

       this->Clear_Dynamic_Memory();
   }
}

void Test_Program_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Class_Name != nullptr){

            delete [] this->Class_Name;

            this->Class_Name = nullptr;
         }

         if(this->Class_Header_File_Name != nullptr){

            delete [] this->Class_Header_File_Name;

            this->Class_Header_File_Name = nullptr;
         }

         if(this->Class_Object_File_Name != nullptr){

            delete [] this->Class_Object_File_Name;

            this->Class_Object_File_Name = nullptr;
         }

         if(this->Executable_File_Name != nullptr){

            delete [] this->Executable_File_Name;

            this->Executable_File_Name = nullptr;
         }

         if(this->Main_File_Name != nullptr){

            delete [] this->Main_File_Name;

            this->Main_File_Name = nullptr;
         }

         if(this->Compiler_System_Command != nullptr){

            delete [] this->Compiler_System_Command;

            this->Compiler_System_Command = nullptr;
         }

         if(this->Included_Header_Files != nullptr){

            for(int i=0;i<this->Included_Header_Files_Number;i++){

                delete [] this->Included_Header_Files[i];

                this->Included_Header_Files[i] = nullptr;

                delete [] this->Included_Object_Files[i];

                this->Included_Object_Files[i] = nullptr;
            }

            delete [] this->Included_Header_Files;

            delete [] this->Included_Object_Files;
         }
     }
}

void Test_Program_Builder::Build_Test_Program(const char * Header_Files_Directory, const char * Object_Files_Directory, const char * Library_Directory, const char * Library_Name){

     this->Find_Class_Name();

     this->Determine_Included_Header_Files_Number();

     this->Read_Include_File_Names();

     this->Determine_Object_File_Names();

     this->Determine_Compiler_System_Command(Header_Files_Directory,Object_Files_Directory,Library_Directory,Library_Name);

     system(this->Compiler_System_Command);
}

void Test_Program_Builder::Find_Class_Name(){

     char * Current_Directory = get_current_dir_name();

     int Directory_Name_Size = strlen(Current_Directory);

     int Start_Point = 0;

     for(int i=Directory_Name_Size;i>0;i--){

         if(Current_Directory[i] == '/'){

            Start_Point = i;

            break;
         }
     }

     // Class name determination

     int Name_Size = Directory_Name_Size - Start_Point;

     this->Class_Name = new char [5*Name_Size];

     int index_counter = 0;

     for(int i=Start_Point+1;i<Directory_Name_Size;i++){

         this->Class_Name[index_counter] = Current_Directory[i];

         index_counter++;
     }

     this->Class_Name[index_counter] = '\0';

     // Header file name determination

     int Class_Name_Size = strlen(this->Class_Name);

     index_counter = 0;

     char Header_File_Add_word [] = {'.','h','\0'};

     this->Class_Header_File_Name = new char [5*Class_Name_Size];

     this->Place_Information(&this->Class_Header_File_Name,this->Class_Name,&index_counter);

     this->Place_Information(&this->Class_Header_File_Name,Header_File_Add_word,&index_counter);

     this->Class_Header_File_Name[index_counter] = '\0';

     // Source file name determination

     index_counter = 0;

     char Source_File_Add_word [] = {'.','o','\0'};

     this->Class_Object_File_Name = new char [5*Class_Name_Size];

     this->Place_Information(&this->Class_Object_File_Name,this->Class_Name,&index_counter);

     this->Place_Information(&this->Class_Object_File_Name,Source_File_Add_word ,&index_counter);

     this->Class_Object_File_Name[index_counter] = '\0';

     // Executable File Name determination

     index_counter = 0;

     char Exe_Add_word [] = {'.','e','x','e','\0'};

     this->Executable_File_Name = new char [5*Class_Name_Size];

     this->Place_Information(&this->Executable_File_Name,this->Class_Name,&index_counter);

     this->Place_Information(&this->Executable_File_Name,Exe_Add_word,&index_counter);

     this->Executable_File_Name[index_counter] = '\0';

     // Main file name determination

     index_counter = 0;

     char Main_File_Add_word [] = {'_','M','a','i','n','_','F','i','l','e','.','c','p','p','\0'};

     this->Main_File_Name = new char [5*Class_Name_Size];

     this->Place_Information(&this->Main_File_Name,this->Class_Name,&index_counter);

     this->Place_Information(&this->Main_File_Name,Main_File_Add_word,&index_counter);

     this->Main_File_Name[index_counter] = '\0';

     free(Current_Directory);
}

void Test_Program_Builder::Determine_Compiler_System_Command(const char * Header_Files_Directory, const char * Object_Files_Directory, const char * Library_Directory, const char * Library_Name){

     char compiler_input_command [] = {'g','+','+',' ','-','s','t','d','=','c','+','+','1','4',' ','-','g','\0'};

     char Include_Character [] = {'-','I','\0'};

     char Library_Character [] = {'-','L','\0'};

     char include_word [] = {'-','i','n','c','l','u','d','e','\0'};

     char Linker_Character [] = {'-','l','\0'};

     char Directory_Character [] = {'/','\0'};

     char Space_Character [] = {' ','\0'};

     char Executable_Option [] = {'-','o','\0'};

     int Header_Files_Directory_Name_Size = strlen(Header_Files_Directory);

     int Library_Directory_Name_Size = strlen(Library_Directory);

     int Object_Files_Directory_Name_Size = strlen(Object_Files_Directory);

     int Included_Header_Files_Name_Size = 0;

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         Included_Header_Files_Name_Size = Included_Header_Files_Name_Size + strlen(this->Included_Header_Files[i]);
     }

     int Included_Object_Files_Name_Size = 0;

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         Included_Object_Files_Name_Size = Included_Object_Files_Name_Size + strlen(this->Included_Object_Files[i]);
     }

     int Source_File_Name_Size = strlen(this->Class_Object_File_Name);

     int Header_File_Name_Size = strlen(this->Class_Header_File_Name);

     int Main_File_Name_Size = strlen(this->Main_File_Name);

     int Executable_File_Name_Size = strlen(this->Executable_File_Name);

     int Library_Name_Size = strlen(Library_Name);

     int compiler_input_command_size = strlen(compiler_input_command);

     int compiler_command_size = Header_Files_Directory_Name_Size + Library_Directory_Name_Size + Object_Files_Directory_Name_Size +

                                 Header_File_Name_Size + Source_File_Name_Size + compiler_input_command_size +

                                 Executable_File_Name_Size + Library_Name_Size + Main_File_Name_Size +

                                 Included_Header_Files_Name_Size + Included_Object_Files_Name_Size;

     this->Compiler_System_Command = new char [5*compiler_command_size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_System_Command,compiler_input_command,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Include_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Header_Files_Directory,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Library_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Library_Directory,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Executable_Option,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,this->Executable_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,this->Main_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,this->Class_Header_File_Name,&index_counter);

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_System_Command,include_word,&index_counter);

         this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_System_Command,this->Included_Header_Files[i],&index_counter);
     }

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Linker_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Library_Name,&index_counter);

     this->Compiler_System_Command[index_counter] = '\0';
}


void Test_Program_Builder::Determine_Included_Header_Files_Number(){

     std::string Header_File_Name(this->Class_Header_File_Name);

     this->DataFile.open(Header_File_Name,std::ios::in);

     this->Included_Header_Files_Number = 0;

     while(!this->DataFile.eof()){

            std::getline(this->DataFile,this->String_Line);

            if(this->Include_Line_Determiner(this->String_Line)){

               for(int i=0;i<this->String_Line.length();i++){

                   if(this->String_Line[i] == '\"'){

                      this->Included_Header_Files_Number++;

                      int double_quotes_numner = 0;

                      for(int k = 0;k<this->String_Line.length();k++){

                          if(this->String_Line[k] == '\"'){

                              double_quotes_numner++;
                          }
                      }

                      if(double_quotes_numner < 2){

                         std::cout << "\n There is a syntax error in ";

                         std::cout << Header_File_Name << " decleration..";

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


void Test_Program_Builder::Read_Include_File_Names(){

     this->Included_Header_Files = new char * [5*this->Included_Header_Files_Number];

     std::string Header_File_Name(this->Class_Header_File_Name);

     this->DataFile.open(Header_File_Name,std::ios::in);

     int Included_Header_Files_Index_Counter = 0;

     while(!this->DataFile.eof()){

            std::getline(this->DataFile,this->String_Line);

            if(this->Include_Line_Determiner(this->String_Line)){

                for(int i=0;i<this->String_Line.length();i++){

                    if(this->String_Line[i] == '\"'){

                       int Next_Double_Quotation_Position = i+1;

                       while(this->String_Line[Next_Double_Quotation_Position]!= '\"'){

                             Next_Double_Quotation_Position++;
                       }

                       int Header_File_Name_Size = Next_Double_Quotation_Position - i;

                       this->Included_Header_Files[Included_Header_Files_Index_Counter] = new char [5*Header_File_Name_Size];

                       int index_counter = 0;

                       for(int k=i+1;k<Next_Double_Quotation_Position;k++){

                           this->Included_Header_Files[Included_Header_Files_Index_Counter][index_counter] = this->String_Line[k];

                           index_counter++;
                       }

                       this->Included_Header_Files[Included_Header_Files_Index_Counter][index_counter] = '\0';

                       Included_Header_Files_Index_Counter++;

                       break;
                    }
              }
          }
     }

     this->DataFile.close();
}

void Test_Program_Builder::Determine_Object_File_Names(){

     this->Included_Object_Files = new char * [5*this->Included_Header_Files_Number];

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         int Header_File_Name_Size = strlen(this->Included_Header_Files[i]);

         this->Included_Object_Files[i] = new char [5*Header_File_Name_Size];

         int index_counter = 0;

         for(int k=0;k<Header_File_Name_Size;k++){

             if(this->Included_Header_Files[i][k] == '.'){

                this->Included_Object_Files[i][index_counter] = this->Included_Header_Files[i][k];

                index_counter++;

                break;
             }
             else{

                   this->Included_Object_Files[i][index_counter] = this->Included_Header_Files[i][k];

                   index_counter++;
             }
         }

         this->Included_Object_Files[i][index_counter] = 'o';

         index_counter++;

         this->Included_Object_Files[i][index_counter] = '\0';
     }
}

bool Test_Program_Builder::Include_Line_Determiner(std::string String_Line){

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


void Test_Program_Builder::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int String_Size = strlen(Information);

     for(int i=0;i<String_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
 }


 void Test_Program_Builder::Place_Information(char ** Pointer, const char * Information, int * index_counter){

      int String_Size = strlen(Information);

      for(int i=0;i<String_Size;i++){

          (*Pointer)[(*index_counter)] = Information[i];

          (*index_counter)++;
      }
  }
