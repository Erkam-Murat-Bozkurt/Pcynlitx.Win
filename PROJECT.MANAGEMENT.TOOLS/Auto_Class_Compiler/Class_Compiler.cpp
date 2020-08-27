
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

#include "Class_Compiler.h"

Class_Compiler::Class_Compiler(){

   this->Memory_Delete_Condition = false;

   this->Compiler_System_Command = nullptr;

   this->Header_File_Copy_Command = nullptr;

   this->Object_File_Move_Command = nullptr;

   this->Class_Name = nullptr;

   this->Class_Header_File_Name = nullptr;

   this->Class_Object_File_Name = nullptr;

   this->Class_Source_File_Name = nullptr;

   this->Included_Header_Files = nullptr;

   this->Included_Object_Files = nullptr;

   this->Included_Header_Files_Number = 0;
}

Class_Compiler::Class_Compiler(const Class_Compiler & orig){

}

Class_Compiler::~Class_Compiler(){

   if(!this->Memory_Delete_Condition){

       this->Clear_Dynamic_Memory();
   }
}

void Class_Compiler::Clear_Dynamic_Memory(){

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

         if(this->Class_Source_File_Name != nullptr){

            delete [] this->Class_Source_File_Name;

            this->Class_Source_File_Name = nullptr;
         }

         if(this->Class_Object_File_Name != nullptr){

            delete [] this->Class_Object_File_Name;

            this->Class_Object_File_Name = nullptr;
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

void Class_Compiler::Compile_Class(char * Header_Files_Directory, char * Object_Files_Directory, char * Library_Directory, char * Library_Name){

     this->Find_Class_Name();

     this->Determine_Included_Header_Files_Number();

     this->Read_Include_File_Names();

     this->Determine_Object_File_Names();

     this->Determine_Compiler_System_Command(Header_Files_Directory,Object_Files_Directory,Library_Name);

     system(this->Compiler_System_Command);

     this->Copy_Header_File(Header_Files_Directory);

     this->Send_Object_File(Object_Files_Directory);
}

void Class_Compiler::Find_Class_Name(){

     char * Current_Directory = get_current_dir_name();

     int Directory_Name_Size = strlen(Current_Directory);

     int Start_Point = 0;

     for(int i=Directory_Name_Size;i>0;i--){

         if(Current_Directory[i] == '/'){

            Start_Point = i;

            break;
         }
     }

     int Name_Size = Directory_Name_Size - Start_Point;

     this->Class_Name = new char [5*Name_Size];

     int index_counter = 0;

     for(int i=Start_Point+1;i<Directory_Name_Size;i++){

         this->Class_Name[index_counter] = Current_Directory[i];

         index_counter++;
     }

     this->Class_Name[index_counter] = '\0';

     int Class_Name_Size = strlen(this->Class_Name);

     this->Class_Header_File_Name = new char [5*Class_Name_Size];

     for(int i=0;i<Class_Name_Size;i++){

         this->Class_Header_File_Name[i] = this->Class_Name[i];
     }

     this->Class_Header_File_Name[Class_Name_Size] = '.';

     this->Class_Header_File_Name[Class_Name_Size+1] = 'h';

     this->Class_Header_File_Name[Class_Name_Size+2] = '\0';

     this->Class_Object_File_Name = new char [5*Class_Name_Size];

     for(int i=0;i<Class_Name_Size;i++){

         this->Class_Object_File_Name[i] = this->Class_Name[i];
     }

     this->Class_Object_File_Name[Class_Name_Size] = '.';

     this->Class_Object_File_Name[Class_Name_Size+1] = 'o';

     this->Class_Object_File_Name[Class_Name_Size+2] = '\0';

     this->Class_Source_File_Name = new char [5*Class_Name_Size];

     for(int i=0;i<Class_Name_Size;i++){

         this->Class_Source_File_Name[i] = this->Class_Name[i];
     }

     this->Class_Source_File_Name[Class_Name_Size] = '.';

     this->Class_Source_File_Name[Class_Name_Size+1] = 'c';

     this->Class_Source_File_Name[Class_Name_Size+2] = 'p';

     this->Class_Source_File_Name[Class_Name_Size+3] = 'p';

     this->Class_Source_File_Name[Class_Name_Size+4] = '\0';

     free(Current_Directory);
}

void Class_Compiler::Determine_Compiler_System_Command(char * Header_Files_Directory, char * Object_Files_Directory, char * Library_Name){

     char compiler_input_command [] = {'g','+','+',' ','-','c',' ','-','s','t','d','=','c','+','+','1','4',' ','-','g','\0'};

     char Include_Character [] = {'-','I','\0'};

     char Source_File_Directory_Character [] = {'-','L','\0'};

     char Directory_Character [] = {'/','\0'};

     char include_word [] = {'-','i','n','c','l','u','d','e','\0'};

     char Space_Character [] = {' ','\0'};

     char Linker_Character [] = {'-','l','\0'};

     char * Current_Directory = get_current_dir_name();

     int Include_Directory_Name_Size = strlen(Header_Files_Directory);

     int Object_Files_Directory_Name_Size = strlen(Object_Files_Directory);

     int Source_File_Name_Size = strlen(this->Class_Source_File_Name);

     int Header_File_Name_Size = strlen(this->Class_Header_File_Name);

     int Included_Header_Files_Name_Size = 0;

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         Included_Header_Files_Name_Size = Included_Header_Files_Name_Size + strlen(this->Included_Header_Files[i]);
     }

     int Included_Object_Files_Name_Size = 0;

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         Included_Object_Files_Name_Size = Included_Object_Files_Name_Size + strlen(this->Included_Object_Files[i]);
     }

     int compiler_input_command_size = strlen(compiler_input_command);

     int compiler_command_size = Include_Directory_Name_Size + Object_Files_Directory_Name_Size +

                                 Header_File_Name_Size + Source_File_Name_Size + compiler_input_command_size +

                                 Included_Object_Files_Name_Size + Included_Header_Files_Name_Size;

     this->Compiler_System_Command = new char [10*compiler_command_size];

     int index_counter = 0;

     this->Place_Information(&this->Compiler_System_Command,compiler_input_command,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Include_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Header_Files_Directory,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Include_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Current_Directory,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Source_File_Directory_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Object_Files_Directory,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,this->Class_Source_File_Name,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

     this->Place_Information(&this->Compiler_System_Command,this->Class_Header_File_Name,&index_counter);

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_System_Command,include_word,&index_counter);

         this->Place_Information(&this->Compiler_System_Command,Space_Character,&index_counter);

         this->Place_Information(&this->Compiler_System_Command,this->Included_Header_Files[i],&index_counter);
     }

     this->Compiler_System_Command[index_counter] = '\0';

     free(Current_Directory);
}

void Class_Compiler::Determine_Included_Header_Files_Number(){

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

void Class_Compiler::Read_Include_File_Names(){

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

void Class_Compiler::Determine_Object_File_Names(){

     this->Included_Object_Files = new char * [5*this->Included_Header_Files_Number];

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         int Header_File_Name_Size = strlen(this->Included_Header_Files[i]);

         this->Included_Object_Files[i] = new char [10*Header_File_Name_Size];

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

void Class_Compiler::Copy_Header_File(char * Header_Files_Directory){

     char Directory_Character [] = {'/','\0'};

     char Space_Character [] = {' ','\0'};

     char * Current_Directory = get_current_dir_name();

     int Directory_Name_Size = strlen(Current_Directory);

     char * Header_File_Full_Path = new char [5*Directory_Name_Size];

     char * Header_File_Copy_Path = new char [5*Directory_Name_Size];

     int index_counter = 0;

     this->Place_Information(&Header_File_Full_Path,Current_Directory,&index_counter);

     this->Place_Information(&Header_File_Full_Path,Directory_Character,&index_counter);

     this->Place_Information(&Header_File_Full_Path,this->Class_Header_File_Name,&index_counter);

     Header_File_Full_Path[index_counter] = '\0';

     index_counter = 0;

     this->Place_Information(&Header_File_Copy_Path,Header_Files_Directory,&index_counter);

     this->Place_Information(&Header_File_Copy_Path,Directory_Character,&index_counter);

     this->Place_Information(&Header_File_Copy_Path,this->Class_Header_File_Name,&index_counter);

     Header_File_Copy_Path[index_counter] = '\0';

     unlink(Header_File_Copy_Path);

     link(Header_File_Full_Path,Header_File_Copy_Path);

     free(Current_Directory);

     delete [] Header_File_Full_Path;

     delete [] Header_File_Copy_Path;
}

void Class_Compiler::Send_Object_File(char * Object_Files_Directory){

     char Directory_Character [] = {'/','\0'};

     char Space_Character [] = {' ','\0'};

     char * Current_Directory = get_current_dir_name();

     int Directory_Name_Size = strlen(Current_Directory);

     char * Object_File_Full_Path = new char [5*Directory_Name_Size];

     char * Object_File_Copy_Path = new char [5*Directory_Name_Size];

     int index_counter = 0;

     this->Place_Information(&Object_File_Full_Path,Current_Directory,&index_counter);

     this->Place_Information(&Object_File_Full_Path,Directory_Character,&index_counter);

     this->Place_Information(&Object_File_Full_Path,this->Class_Object_File_Name,&index_counter);

     Object_File_Full_Path[index_counter] = '\0';

     index_counter = 0;

     this->Place_Information(&Object_File_Copy_Path,Object_Files_Directory,&index_counter);

     this->Place_Information(&Object_File_Copy_Path,Directory_Character,&index_counter);

     this->Place_Information(&Object_File_Copy_Path,this->Class_Object_File_Name,&index_counter);

     Object_File_Copy_Path[index_counter] = '\0';

     unlink(Object_File_Copy_Path);

     this->Send_File(Object_File_Copy_Path,Object_File_Full_Path);

     int return_value = unlink(Object_File_Full_Path);

     free(Current_Directory);

     delete [] Object_File_Full_Path;

     delete [] Object_File_Copy_Path;
}

bool Class_Compiler::Include_Line_Determiner(std::string String_Line){

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

void Class_Compiler::Send_File(char * Target_Location, char * Base_Location){

     int read_fd;

     int write_fd;

     struct stat stat_buf;

     off_t offset = 0;

     /* Open the input file. */

     read_fd = open (Base_Location, O_RDONLY);

     /* Stat the input file to obtain its size. */

     fstat (read_fd, &stat_buf);
     /* Open the output file for writing, with the same permissions as the source file. */

     write_fd = open (Target_Location, O_WRONLY | O_CREAT, stat_buf.st_mode);

     /* Blast the bytes from one file to the other. */

     sendfile (write_fd, read_fd, &offset, stat_buf.st_size);

     /* Close up. */

     close (read_fd);

     close (write_fd);
}

void Class_Compiler::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int String_Size = strlen(Information);

     for(int i=0;i<String_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
 }
