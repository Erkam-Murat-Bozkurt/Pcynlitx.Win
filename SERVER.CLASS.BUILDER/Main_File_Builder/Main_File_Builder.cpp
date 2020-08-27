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

#include "Main_File_Builder.h"

Main_File_Builder::Main_File_Builder(){

    this->Supervisor_Class_Header_File_Name = nullptr;

    this->New_Include_Directory_Name = nullptr;
}

Main_File_Builder::Main_File_Builder(const Main_File_Builder & orig){

}

Main_File_Builder::~Main_File_Builder(){

}

void Main_File_Builder::Receive_Descriptor_File_Object_Addres(Descriptor_File_Reader * Pointer){

     this->File_Reader = Pointer;
}

void Main_File_Builder::Receive_Newly_Constructed_Include_Directory_Name(char * Directory_Name){

     this->New_Include_Directory_Name = Directory_Name;
}

void Main_File_Builder::Build_Main_File(){

     char * Construction_Point = this->File_Reader->Get_Construction_Point();

     char * name_space = this->File_Reader->Get_Namespace();

     this->Directory_Manager.ChangeDirectory(Construction_Point);

     this->File_Manager.SetFilePath("MT_Library_Headers.h");

     this->Supervisor_Class_Header_File_Name = this->File_Reader->Get_Server_Class_Header_File_Name();

     const char * Client_Subfix = "_Client";

     const char * Client_Header_Subfix = "_Client.h";

     const char * Type_Subfix   = "_Type_Smart_Pointer";

     const char * Type_Header_Subfix = "_Type_Smart_Pointer.h";

     char * Server_Class_Name = this->File_Reader->Get_Server_Class_Name();

     Class_Data_Type  * Class_Data_Type_Holder = this->File_Reader->Get_Class_Names();

     int Total_Class_Number = this->File_Reader->Get_Class_Number();

     Shared_Memory_Data_Type * Shared_Memory_Data_Type_Holder = this->File_Reader->Get_Shared_Data_Types();

     int Total_Data_Type_Number = this->File_Reader->Get_Shared_Data_Types_Number();

     this->File_Manager.FileOpen(RWC);

     this->File_Manager.WriteToFile("\n");

     for(int i=0;i<Total_Class_Number;i++){

         this->File_Manager.WriteToFile("\n #include \"");

         char * Header_File_Name = Class_Data_Type_Holder[i].Header_File_Name;

         this->File_Manager.WriteToFile(Header_File_Name);

         this->File_Manager.WriteToFile("\"");
     }

     for(int i=0;i<Total_Data_Type_Number;i++){

         char * Header_File_Name = Shared_Memory_Data_Type_Holder[i].Header_File_Name;

         if(Header_File_Name != nullptr){

            this->File_Manager.WriteToFile("\n #include \"");

            this->File_Manager.WriteToFile(Header_File_Name);

            this->File_Manager.WriteToFile("\"");
         }
     }

     for(int i=0;i<Total_Class_Number;i++){

         this->File_Manager.WriteToFile("\n #include \"");

         char * Class_Name = Class_Data_Type_Holder[i].Class_Name;

         this->File_Manager.WriteToFile(Class_Name);

         this->File_Manager.WriteToFile(Client_Header_Subfix);

         this->File_Manager.WriteToFile("\"");
     }

     for(int i=0;i<Total_Data_Type_Number;i++){

         this->File_Manager.WriteToFile("\n #include \"");

         char * Data_Type = Shared_Memory_Data_Type_Holder[i].Data_Type;

         this->File_Manager.WriteToFile(Data_Type);

         this->File_Manager.WriteToFile(Type_Subfix);

         this->File_Manager.WriteToFile(Client_Header_Subfix);

         this->File_Manager.WriteToFile("\"");
     }

     int Header_File_Names_Number = this->File_Reader->Get_Header_Files_Number();

     for(int i=0;i<Header_File_Names_Number;i++){

         char * Header_File_Name = this->File_Reader->Get_Header_File_Names()[i];

         this->File_Manager.WriteToFile("\n #include \"");

         this->File_Manager.WriteToFile(Header_File_Name);

         this->File_Manager.WriteToFile("\"");
     }

     this->File_Manager.WriteToFile("\n #include \"itds.h\"");

     this->File_Manager.WriteToFile("\n #include \"");

     this->File_Manager.WriteToFile(this->Supervisor_Class_Header_File_Name);

     this->File_Manager.WriteToFile("\"");

     this->File_Manager.WriteToFile("\n #include \"TM_Client.h\"");

     this->File_Manager.WriteToFile("\n #include <thread>");

     this->File_Manager.WriteToFile("\n");

     for(int i=0;i<this->File_Reader->Get_Thread_Function_Number();i++){

         this->File_Manager.WriteToFile("\n");

         this->File_Manager.WriteToFile("\n void ");

         this->File_Manager.WriteToFile(this->File_Reader->Get_Thread_Function_Names()[i]);

         this->File_Manager.WriteToFile("(");

         this->File_Manager.WriteToFile(this->File_Reader->Get_Namespace());

         this->File_Manager.WriteToFile("::thds * thread_data);");
     }

     this->File_Manager.WriteToFile("\n");

     this->File_Manager.FileClose();

     this->Move_Header_File_List_To_New_Include_Directory();

     char * Main_File_Name = this->File_Reader->Get_Main_File_Name();

     this->File_Manager.SetFilePath(Main_File_Name);

     this->File_Manager.FileOpen(RWC);

     this->File_Manager.WriteToFile("\n #include \"MT_Library_Headers.h\"");

     this->File_Manager.WriteToFile("\n\n int main(int argc, char ** argv){");

     this->File_Manager.WriteToFile("\n\n");

     this->Write_Space(" int ");

     this->File_Manager.WriteToFile(name_space);

     this->File_Manager.WriteToFile("::");

     this->File_Manager.WriteToFile(Server_Class_Name);

     this->File_Manager.WriteToFile(" Server;");

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("\n\n\n");

     this->Write_Space(" int ");

     if(this->File_Reader->Get_Thread_Number() > 1){

       this->File_Manager.WriteToFile("for(int i=0;i<");

       char * Thread_Number = this->Translater.Translate(this->File_Reader->Get_Thread_Number());

       this->File_Manager.WriteToFile(Thread_Number);

       this->File_Manager.WriteToFile(";i++){");

       this->File_Manager.WriteToFile("\n\n");

       this->Write_Space(" int     ");

       this->File_Manager.WriteToFile("Server.Join(i);");

       this->File_Manager.WriteToFile("\n");

       this->Write_Space(" int ");

       this->File_Manager.WriteToFile("};");
     }
     else{

          this->File_Manager.WriteToFile("Server.Join(0);");
     }

     this->File_Manager.WriteToFile("\n\n");

     this->File_Manager.WriteToFile("     return 0;");

     this->File_Manager.WriteToFile("\n }");

     this->File_Manager.WriteToFile("\n");

     char * Thread_Function_Name = nullptr;

     int Thread_Function_Number = this->File_Reader->Get_Thread_Function_Number();

     for(int i=0;i<Thread_Function_Number;i++){

         Thread_Function_Name = this->File_Reader->Get_Thread_Function_Names()[i];

         this->File_Manager.WriteToFile("\n\n void ");

         this->File_Manager.WriteToFile(Thread_Function_Name);

         this->File_Manager.WriteToFile("(");

         this->File_Manager.WriteToFile(this->File_Reader->Get_Namespace());

         this->File_Manager.WriteToFile("::thds * thread_data){");

         this->File_Manager.WriteToFile("\n\n");

         this->Write_Space(" void ");

         this->File_Manager.WriteToFile(name_space);

         this->File_Manager.WriteToFile("::");

         this->File_Manager.WriteToFile("TM_Client Manager(thread_data,\"");

         this->File_Manager.WriteToFile(Thread_Function_Name);

         this->File_Manager.WriteToFile("\");");

         this->File_Manager.WriteToFile("\n\n");

         this->File_Manager.WriteToFile("\n\n");

         this->Write_Space(" void ");

         this->File_Manager.WriteToFile("Manager.Exit();");

         this->File_Manager.WriteToFile("\n }");
     }

     this->File_Manager.FileClose();

     this->Directory_Manager.Clear_Dynamic_Memory();

     this->File_Manager.Clear_Dynamic_Memory();
}

void Main_File_Builder::Move_Header_File_List_To_New_Include_Directory(){

     char Header_File_List_Name [] = "MT_Library_Headers.h";

     char Directory_Character [] = {'/','\0'};

     int Header_File_List_Name_Size = strlen(Header_File_List_Name);

     this->Directory_Manager.DetermineCurrentDirectory();

     char * Current_Directory = this->Directory_Manager.GetCurrentlyWorkingDirectory();

     int New_Include_Directory_Name_Size = strlen(this->New_Include_Directory_Name);

     int Current_Directory_Name_Size = strlen(Current_Directory);

     int New_Path_Size = New_Include_Directory_Name_Size + Header_File_List_Name_Size;

     int Current_Path_Size = Current_Directory_Name_Size + Header_File_List_Name_Size;

     char * Current_Path = new char [10*Current_Path_Size];

     int index_counter = 0;

     this->Place_Information(&Current_Path,Current_Directory,&index_counter);

     this->Place_Information(&Current_Path,Directory_Character,&index_counter);

     this->Place_Information(&Current_Path,Header_File_List_Name,&index_counter);

     Current_Path[index_counter] = '\0';

     index_counter = 0;

     char * New_Path = new char [10*New_Path_Size];

     this->Place_Information(&New_Path,this->New_Include_Directory_Name,&index_counter);

     this->Place_Information(&New_Path,Directory_Character,&index_counter);

     this->Place_Information(&New_Path,Header_File_List_Name,&index_counter);

     New_Path[index_counter] = '\0';

     this->File_Manager.Move_File(New_Path,Current_Path);

     delete [] New_Path;

     delete [] Current_Path;
}


void Main_File_Builder::Place_Information(char ** Pointer, char * Information, int * counter){

     int Information_Size = strlen(Information);

     for(int i=0;i<Information_Size;i++){

         (*Pointer)[(*counter)] = Information[i];

         (*counter)++;
     }
}

void Main_File_Builder::Write_Space(const char * String){

     int String_Size = strlen(String);

     for(int i=0;i<String_Size;i++){

         this->File_Manager.WriteToFile(" ");
     }
}
