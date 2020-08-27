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

#include "Modification_Control_Script_Builder.h"

Modification_Control_Script_Builder::Modification_Control_Script_Builder(){

    this->Memory_Delete_Condition = false;

    this->Current_Directory = nullptr;

    this->Class_Name = nullptr;

    this->Class_Header_File_Name = nullptr;

    this->Class_Object_File_Name = nullptr;
}

Modification_Control_Script_Builder::Modification_Control_Script_Builder(const Modification_Control_Script_Builder & orig){

}

Modification_Control_Script_Builder::~Modification_Control_Script_Builder(){

    if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
    }
}

void Modification_Control_Script_Builder::Clear_Dynamic_Memory(){

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

         if(this->Current_Directory != nullptr){

            delete [] this->Current_Directory;

            this->Current_Directory = nullptr;
         }
     }
}

void Modification_Control_Script_Builder::Build_Script(char * Header_Files_Directory, char * Object_Files_Directory){

     this->Find_Class_Name();

     char Stat_Option [] = {'\"','%','y','\"',' ','\0'};

     char Slash [] = {' ','\\','\0'};

     this->FileManager.SetFilePath("Modification_Control_Script.sh");

     this->FileManager.FileOpen(RWCf);

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("Current_Directory=");

     this->FileManager.WriteToFile(this->Current_Directory);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("Target_Header_File_Directory=");

     this->FileManager.WriteToFile(Header_Files_Directory);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("Object_Files_Directory=");

     this->FileManager.WriteToFile(Object_Files_Directory);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("Base_Header_File_Path=");

     this->FileManager.WriteToFile("$Current_Directory/");

     this->FileManager.WriteToFile(this->Class_Header_File_Name);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("Target_Header_File_Path=");

     this->FileManager.WriteToFile("$Target_Header_File_Directory/");

     this->FileManager.WriteToFile(this->Class_Header_File_Name);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("Base_Object_File_Path=");

     this->FileManager.WriteToFile("$Current_Directory/");

     this->FileManager.WriteToFile(this->Class_Object_File_Name);

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("cp $Base_Header_File_Path $Target_Header_File_Path");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("Base_File_History=");

     this->FileManager.WriteToFile("$(stat --format ");

     this->FileManager.WriteToFile(Stat_Option);

     this->FileManager.WriteToFile("$Base_Header_File_Path");

     this->FileManager.WriteToFile(")\n\n");

     this->FileManager.WriteToFile("Target_File_History=");

     this->FileManager.WriteToFile("$(stat --format ");

     this->FileManager.WriteToFile(Stat_Option);

     this->FileManager.WriteToFile("$Target_Header_File_Path");

     this->FileManager.WriteToFile(")\n\n");

     this->FileManager.WriteToFile("if [ \"$Base_File_History\" != \"$Target_File_History\" ]");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("then");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("     echo \"Header will be updated ..\"");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("     cp --preserve=timestamps $Base_Header_File_Path $Target_Header_File_Directory");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("else");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("     echo \"Header file is up to date\"");

     this->FileManager.WriteToFile("\nfi");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.WriteToFile("if [ -e \"$Base_Object_File_Path\" ]");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("then");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("     mv $Base_Object_File_Path $Object_Files_Directory");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("fi");

     this->FileManager.WriteToFile("\n\n");

     this->FileManager.FileClose();
}

void Modification_Control_Script_Builder::Find_Class_Name(){

     char * Current_Directory_Path = get_current_dir_name();

     int Directory_Name_Size = strlen(Current_Directory_Path);

     this->Current_Directory =  new char [10*Directory_Name_Size];

     for(int i=0;i<Directory_Name_Size;i++){

        this->Current_Directory[i] = Current_Directory_Path[i];
     }

     this->Current_Directory[Directory_Name_Size] = '\0';

     int Start_Point = 0;

     for(int i=Directory_Name_Size;i>0;i--){

         if(this->Current_Directory[i] == '/'){

            Start_Point = i;

            break;
         }
     }

     int Name_Size = Directory_Name_Size - Start_Point;

     this->Class_Name = new char [5*Name_Size];

     int index_counter = 0;

     for(int i=Start_Point+1;i<Directory_Name_Size;i++){

         this->Class_Name[index_counter] = this->Current_Directory[i];

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

     free(Current_Directory_Path);
}
