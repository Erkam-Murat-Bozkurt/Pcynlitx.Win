
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

#include "Make_File_Builder.h"

Make_File_Builder::Make_File_Builder(){

   this->Memory_Delete_Condition = false;

   this->Gui_Status = false;

   this->Compiler_System_Command = nullptr;

   this->Header_File_Copy_Command = nullptr;

   this->Object_File_Move_Command = nullptr;

   this->Class_Name = nullptr;

   this->Class_Header_File_Name = nullptr;

   this->Class_Object_File_Name = nullptr;

   this->Class_Source_File_Name = nullptr;

   this->Included_Header_Files = nullptr;

   this->Included_Object_Files = nullptr;

   this->Dependency_Code_Line = nullptr;

   this->Included_Header_Files_Number = 0;
}

Make_File_Builder::Make_File_Builder(const Make_File_Builder & orig){

}

Make_File_Builder::~Make_File_Builder(){

   if(!this->Memory_Delete_Condition){

       this->Clear_Dynamic_Memory();
   }
}

void Make_File_Builder::Clear_Dynamic_Memory(){

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

         if(this->Dependency_Code_Line != nullptr){

            delete [] this->Dependency_Code_Line;

            this->Dependency_Code_Line = nullptr;
         }
     }
}

void Make_File_Builder::Make_For_GUI(bool GUI_Status){

     this->Gui_Status = GUI_Status;
}

void Make_File_Builder::Build_MakeFile(char * Header_Files_Directory, char * Object_Files_Directory, char * Library_Directory, char * Library_Name){

     this->Find_Class_Name();

     this->Determine_Included_Header_Files_Number();

     this->Read_Include_File_Names();

     this->Determine_Object_File_Names();

     this->Determine_Compiler_System_Command(Header_Files_Directory,Object_Files_Directory,Library_Name);

     this->Determine_Dependency_Code_Line();

     this->FileManager.SetFilePath("auto_make_file.make");

     this->FileManager.FileOpen(RWCf);

     this->FileManager.WriteToFile("\n");

     char PathSpecifier [] = {'v','p','a','t','h',' ','%','\0'};

     char header_add [] = ".h ";

     char object_add [] = ".o ";

     this->FileManager.WriteToFile(PathSpecifier);

     this->FileManager.WriteToFile(header_add);

     this->FileManager.WriteToFile(Header_Files_Directory);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(PathSpecifier);

     this->FileManager.WriteToFile(object_add);

     this->FileManager.WriteToFile(Object_Files_Directory);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n");

     if(this->Gui_Status){

        this->FileManager.WriteToFile("Libraries=`wx-config --cxxflags --libs`");

        this->FileManager.WriteToFile(" `wx-config --libs std stc` `wx-config --libs core,base,aui`");
     }

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile(this->Dependency_Code_Line);

     this->FileManager.WriteToFile("\n\t");

     std::string compiler_command;

     int compiler_command_size = strlen(this->Compiler_System_Command);

     int index_counter = 0;

     bool new_line_condition = false;

     bool space_detect_condition = false;

     for(int i=0;i<compiler_command_size;i++){

         compiler_command.append(1,this->Compiler_System_Command[i]);

         index_counter++;

         if(index_counter >= 60){

            new_line_condition = true;
         }

         if(new_line_condition){

            if(this->Compiler_System_Command[i] == ' '){

               space_detect_condition = true;
            }
         }

         if(new_line_condition && space_detect_condition){

            compiler_command.append(1,'\\');

            compiler_command.append(1,'\n');

            compiler_command.append(1,'\t');

            index_counter = 0;

            new_line_condition = false;

            space_detect_condition = false;
         }
     }

     this->FileManager.WriteToFile(compiler_command);

     this->FileManager.WriteToFile(" $(Libraries)");

     this->FileManager.WriteToFile("\n");

     this->FileManager.FileClose();
}

void Make_File_Builder::Find_Class_Name(){

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

void Make_File_Builder::Determine_Compiler_System_Command(char * Header_Files_Directory, char * Object_Files_Directory, char * Library_Name){

     char compiler_input_command [] = {'g','+','+',' ','-','c',' ','-','s','t','d','=','c','+','+','1','4','\0'};

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

void Make_File_Builder::Determine_Included_Header_Files_Number(){

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

void Make_File_Builder::Read_Include_File_Names(){

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

void Make_File_Builder::Determine_Object_File_Names(){

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

bool Make_File_Builder::Include_Line_Determiner(std::string String_Line){

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

void Make_File_Builder::Determine_Dependency_Code_Line(){

     char double_quotes [] = " : ";

     char space [] = " ";

     int Object_File_Name_Size = strlen(this->Class_Object_File_Name);

     int Header_File_Name_Size = strlen(this->Class_Header_File_Name);

     int Source_File_Name_Size = strlen(this->Class_Source_File_Name);

     int Included_Header_Files_Name_Size = 0;

     for(int i=0;i<this->Included_Header_Files_Number;i++){

        Included_Header_Files_Name_Size = Included_Header_Files_Name_Size + strlen(this->Included_Header_Files[i]);
     }

     int Code_Line_Size = Object_File_Name_Size + Source_File_Name_Size +

                          Header_File_Name_Size + Included_Header_Files_Name_Size;

     this->Dependency_Code_Line =  new char [10*Code_Line_Size];

     int index_counter = 0;

     this->Place_Information(&this->Dependency_Code_Line,this->Class_Object_File_Name,&index_counter);

     this->Place_Information(&this->Dependency_Code_Line,double_quotes,&index_counter);

     this->Place_Information(&this->Dependency_Code_Line,this->Class_Source_File_Name,&index_counter);

     this->Place_Information(&this->Dependency_Code_Line,space,&index_counter);

     this->Place_Information(&this->Dependency_Code_Line,this->Class_Header_File_Name,&index_counter);

     int  sizer = 0;

     char slash [] = "\\";

     char new_line [] = "\n";

     char tab [] = "\t";

     for(int i=0;i<this->Included_Header_Files_Number;i++){

         this->Place_Information(&this->Dependency_Code_Line,space,&index_counter);

         this->Place_Information(&this->Dependency_Code_Line,this->Included_Header_Files[i],&index_counter);

         sizer++;

         if(((sizer >= 3) && (i!=(this->Included_Header_Files_Number -1)))){

            this->Place_Information(&this->Dependency_Code_Line,slash,&index_counter);

            this->Place_Information(&this->Dependency_Code_Line,new_line,&index_counter);

            this->Place_Information(&this->Dependency_Code_Line,tab,&index_counter);

            sizer = 0;
         }
     }

     this->Dependency_Code_Line[index_counter] = '\0';
}

void Make_File_Builder::Place_Information(char ** Pointer, char * Information, int * index_counter){

     int String_Size = strlen(Information);

     for(int i=0;i<String_Size;i++){

         (*Pointer)[(*index_counter)] = Information[i];

         (*index_counter)++;
     }
 }
