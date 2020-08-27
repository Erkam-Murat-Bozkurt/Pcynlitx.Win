
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

#include "Multi_Thread_Pointer_File_Cleaner.h"

Multi_Thread_Pointer_File_Cleaner::Multi_Thread_Pointer_File_Cleaner(){

}

Multi_Thread_Pointer_File_Cleaner::Multi_Thread_Pointer_File_Cleaner(const Multi_Thread_Pointer_File_Cleaner & orig){

}

Multi_Thread_Pointer_File_Cleaner::~Multi_Thread_Pointer_File_Cleaner(){

}

void Multi_Thread_Pointer_File_Cleaner::Remove_Source_Files(char ** Source_File_Name_Matrix){

     for(int i=0;i<3;i++){

         this->File_Manager.DeleteFile(Source_File_Name_Matrix[i]);
     }
}


void Multi_Thread_Pointer_File_Cleaner::Remove_Header_File_Extras(char ** Header_File_Matrix){

     char Gch_Word [] = {'.','g','c','h','\0'};

     int Gch_Word_Size = strlen(Gch_Word);

     for(int i=0;i<3;i++){

         int File_Name_Size = strlen(Header_File_Matrix[i]);

         int Extra_File_Name_Size = File_Name_Size + Gch_Word_Size;

         char * Extra_File_Name = new char [10*Extra_File_Name_Size];

         int index_counter = 0;

         this->Place_Information(&Extra_File_Name,Header_File_Matrix[i],&index_counter);

         this->Place_Information(&Extra_File_Name,Gch_Word,&index_counter);

         Extra_File_Name[index_counter] = '\0';

         this->File_Manager.DeleteFile(Extra_File_Name);

         delete [] Extra_File_Name;
     }
}

void Multi_Thread_Pointer_File_Cleaner::Remove_Object_Files(char ** Object_File_Name_Matrix){

     for(int i=0;i<3;i++){

         this->File_Manager.DeleteFile(Object_File_Name_Matrix[i]);
     }
}

void Multi_Thread_Pointer_File_Cleaner::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_List_Size = strlen(Information);

     for(int i=0;i<Information_List_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}
