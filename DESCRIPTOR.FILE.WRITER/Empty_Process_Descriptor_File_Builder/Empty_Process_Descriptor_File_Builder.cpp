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

#include "Empty_Process_Descriptor_File_Builder.h"

Empty_Process_Descriptor_File_Builder::Empty_Process_Descriptor_File_Builder(){

    this->Memory_Delete_Condition = false;
}

Empty_Process_Descriptor_File_Builder::Empty_Process_Descriptor_File_Builder(const Empty_Process_Descriptor_File_Builder & orig){

}

Empty_Process_Descriptor_File_Builder::~Empty_Process_Descriptor_File_Builder(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void Empty_Process_Descriptor_File_Builder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->File_Manager.Clear_Dynamic_Memory();

         this->Directory_Manager.Clear_Dynamic_Memory();
     }
}

void Empty_Process_Descriptor_File_Builder::Read_Construction_Point(char * path){

     this->Directory_Manager.ChangeDirectory(path);

     char Descriptor_File_Name [] = "Project_Descriptor_File.txt";

     this->File_Manager.SetFilePath(Descriptor_File_Name);
}

void Empty_Process_Descriptor_File_Builder::Build_Descriptor_File(){

     this->File_Manager.FileOpen(RWCf);

     this->File_Manager.WriteToFile("\n PROCESS DESCRIPTOR FILE");

     this->File_Manager.WriteToFile("\n");

     this->File_Manager.WriteToFile("\n Description [Header_File_Locations]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Source_File_Locations]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Library_Locations]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Header_File_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Source_File_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Library_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Main_File_Name]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Project_Executable_File_Name]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Inter_Thread_Class_Header_File_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Inter_Thread_Class_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Inter_Thread_Class_Instance_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Inter_Thread_Data_Types]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Inter_Thread_Data_Type_Header_File_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Inter_Thread_Data_Type_Pointer_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Construction_Point]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Server_Class_Name]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Thread_Number]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Thread_Function_Names]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [Namespace]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n Description [OpenMP_Support]");

     this->File_Manager.WriteToFile("\n {");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.FileClose();
}
