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

#include "Descriptor_File_Data_Collector.h"

Descriptor_File_Data_Collector::Descriptor_File_Data_Collector(){

      this->Memory_Delete_Condition = false;

      this->DescriptorFileName_Receive_Condition = false;

      this->DescriptorFileDirectory_Receive_Condition = false;

      this->DescriptorFileDirectory = nullptr;

      this->DescriptorFileName = nullptr;

      this->ConstString = new char [10];

      this->Data_Record_StartLine = 0;

      this->Data_Record_EndLine = 0;

      this->Record_Number = 0;

      this->Supervisor_Class_Name_Record_Number = 0;

      this->Include_Directory_Numbers = 0;

      this->Source_File_Location_Number = 0;

      this->Source_File_Number = 0;

      this->Library_Directory_Number = 0;

      this->Library_Names_Number = 0;

      this->Header_File_Names_Number = 0;

      this->Executable_File_Name_Record_Number = 0;

      this->Main_File_Name_Record_Number = 0;

      this->Inter_Thread_Class_Header_File_Names_Number = 0;

      this->Class_Number = 0;

      this->Class_Instance_Number = 0;

      this->Shared_Data_Types_Number = 0;

      this->Shared_Data_Types_Include_File_Names_Number = 0;

      this->Shared_Data_Type_Pointer_Names_Number = 0;

      this->Construction_Point_Record_Number = 0;

      this->Supervisor_Class_Name_Record_Number = 0;

      this->Record_Line_Number_for_Total_Thread_Number = 0;

      this->Thread_Function_Number = 0;

      this->Namespace_Record_Number = 0;

      this->OpenMP_Support_Condition_Record_Number = 0;
}

Descriptor_File_Data_Collector::Descriptor_File_Data_Collector(const Descriptor_File_Data_Collector & orig){

}

Descriptor_File_Data_Collector::~Descriptor_File_Data_Collector(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
}

void Descriptor_File_Data_Collector::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Pointer_Memory(&this->ConstString);

         if(this->DescriptorFileDirectory_Receive_Condition){

            this->Clear_Pointer_Memory(&this->DescriptorFileDirectory);

            this->DirectoryManager.Clear_Dynamic_Memory();

            if(this->DescriptorFileName_Receive_Condition){

               this->Clear_Pointer_Memory(&this->DescriptorFileName);

               this->StringOperations.Clear_Dynamic_Memory();
            }
         }
     }
}

void Descriptor_File_Data_Collector::Receive_Descriptor_File_Directory(const char * DescriptorFileDirectory){

     int String_Size = strlen(DescriptorFileDirectory);

     this->Memory_Delete_Condition = false;

     this->DescriptorFileDirectory_Receive_Condition = true;

     this->DescriptorFileDirectory = new char [10*String_Size];

     this->Place_String(&this->DescriptorFileDirectory,DescriptorFileDirectory,String_Size);
 }

void Descriptor_File_Data_Collector::Receive_Descriptor_File_Directory(char * DescriptorFileDirectory){

     int String_Size = strlen(DescriptorFileDirectory);

     this->Memory_Delete_Condition = false;

     this->DescriptorFileDirectory_Receive_Condition = true;

     this->DescriptorFileDirectory = new char [10*String_Size];

     this->Place_String(&this->DescriptorFileDirectory,DescriptorFileDirectory,String_Size);
 }

void Descriptor_File_Data_Collector::Receive_Descriptor_File_Name(const char * DescriptorFileName){

     int String_Size = strlen(DescriptorFileName);

     this->Memory_Delete_Condition = false;

     this->DescriptorFileName_Receive_Condition = true;

     this->DescriptorFileName = new char [10*String_Size];

     this->Place_String(&this->DescriptorFileName,DescriptorFileName,String_Size);

     if((this->DescriptorFileName[0] != '\0') && (this->DescriptorFileName[0] != '\n')){

         this->DescriptorFileName_Receive_Condition = true;
     }
     else{

         this->DescriptorFileName_Receive_Condition = false;
     }
 }

void Descriptor_File_Data_Collector::Receive_Descriptor_File_Name(char * DescriptorFileName){

     int String_Size = strlen(DescriptorFileName);

     this->Memory_Delete_Condition = false;

     this->DescriptorFileName_Receive_Condition = true;

     this->DescriptorFileName = new char [10*String_Size];

     this->Place_String(&this->DescriptorFileName,DescriptorFileName,String_Size);

     if((this->DescriptorFileName[0] != '\0') && (this->DescriptorFileName[0] != '\n')){

         this->DescriptorFileName_Receive_Condition = true;
     }
     else{

         this->DescriptorFileName_Receive_Condition = false;
     }
 }

 void Descriptor_File_Data_Collector::Collect_Descriptor_File_Datas(){

      if(this->DescriptorFileDirectory_Receive_Condition){

          this->DirectoryManager.ChangeDirectory(this->DescriptorFileDirectory);

          this->DirectoryManager.DetermineCurrentDirectory();

          if(this->DescriptorFileName_Receive_Condition){

             this->StringOperations.SetFilePath(this->DescriptorFileName);

             this->Determine_Record_Lines();

             this->Determine_Data_Record_Numbers();

             if(((this->Header_File_Names_Number > 0) && (this->Include_Directory_Numbers == 0))){

                 this->Print_Read_Error_Information();

                 std::cerr << "\n     There is no any include directory decleration ..";

                 std::cerr << "\n\n     Therefore, the location of some header files can not be determined ";

                 std::cerr << "\n\n     Plase check include directory and header file declerations!";

                 std::cerr << "\n\n     The process will be interrupted ..";

                 this->Print_End_of_Program();

                 exit(1);
             }

             if((this->Inter_Thread_Class_Header_File_Names_Number != this->Class_Number)){

                 this->Print_Read_Error_Information();

                 std::cerr << "\n     The number of inter-thread class names are not equal the number of inter-thread";

                 std::cerr << "\n\n     header file names. Therefore, the header files of some classes can not";

                 std::cerr << "\n\n     be determined. Plase check class names and header file declerations!";

                 std::cerr << "\n\n     The process will be interrupted ..";

                 this->Print_End_of_Program();

                 exit(1);
             }

             if(this->Supervisor_Class_Name_Record_Number > 1){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There are more than one server class name .. ";

                std::cerr << "\n\n     Plase check server class name decleration!";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Supervisor_Class_Name_Record_Number == 0){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There is no server class name .. ";

                std::cerr << "\n\n     Plase check server class name decleration!";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Thread_Function_Number == 0){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There is no thread function name decleration .. ";

                std::cerr << "\n\n     Plase check thread function name decleration!";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Namespace_Record_Number > 1){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There are more than one record namespace decleration .. ";

                std::cerr << "\n\n     Plase check namespace decleration!";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Construction_Point_Record_Number == 0){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There is no construction point decleraion .. ";

                std::cerr << "\n\n     Plase check construction point decleration!";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Class_Instance_Number != this->Class_Number){

                this->Print_Read_Error_Information();

                std::cerr << "\n     The number of class instance names are not equal";

                std::cerr << "\n\n     the number of class names.. Plase check ";

                std::cerr << "\n\n     \"Inter-Thread class instance names\" decleration!";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Shared_Data_Type_Pointer_Names_Number != this->Shared_Data_Types_Number){

                this->Print_Read_Error_Information();

                std::cerr << "\n     The number of shared data type pointer names are not equal -";

                std::cerr << "\n\n     the number of shared data types. Plase check the shared";

                std::cerr << "\n\n     data type pointer names decleration!";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Shared_Data_Types_Include_File_Names_Number > this->Shared_Data_Types_Number){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There are more shared data type header file name than";

                std::cerr << "\n\n     shared data types! Plase check data type declerations";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Record_Line_Number_for_Total_Thread_Number > 1){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There are more than one record about total thread number !";

                std::cerr << "\n\n     Plase check total thread number decleration";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Main_File_Name_Record_Number > 1){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There are more than one record about Main file name !";

                std::cerr << "\n\n     Plase check main file name decleration";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if(this->Executable_File_Name_Record_Number > 1){

                this->Print_Read_Error_Information();

                std::cerr << "\n     There are more than one record about the Executable file name !";

                std::cerr << "\n\n     Plase check Executable file name decleration";

                std::cerr << "\n\n     The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
             }

             if((this->Source_File_Location_Number != 0) && (this->Source_File_Number == 0)){

                 this->Print_Read_Error_Information();

                 std::cerr << "\n     A location for a source file readed but there is no source file name definition !";

                 std::cerr << "\n\n     Plase check source file name declerations carefully";

                 std::cerr << "\n\n     If the definition of source file location is unnecessary, place delete it ..";

                 std::cerr << "\n\n     The process will be interrupted ..";

                 this->Print_End_of_Program();

                 exit(1);
             }

             if((this->Source_File_Location_Number == 0) && (this->Source_File_Number != 0)){

                 this->Print_Read_Error_Information();

                 std::cerr << "\n     A source file readed but there is no information about the location of the file!";

                 std::cerr << "\n\n     Plase check source file name declerations carefully..";

                 std::cerr << "\n\n     The process will be interrupted ..";

                 std::cerr << "\n";

                 std::cerr << "\n\n     [ HELP ] - Source file information can not be received without any decleration";

                 std::cerr << "\n\n                about the file locations. The program does not search the location of ";

                 std::cerr << "\n\n                the file. Therefore, it needs the exact path of the file. But,";

                 std::cerr << "\n\n                the decleration block of the source file locations is empty ";

                 std::cerr << "\n";

                 this->Print_End_of_Program();

                 exit(1);
             }
          }
          else{

                this->Print_Read_Error_Information();

                std::cerr << "\n\n   Descriptor file name can not readed ..";

                std::cerr << "\n\n   The process will be interrupted ..";

                this->Print_End_of_Program();

                exit(1);
          }
      }
      else{

              this->Print_Read_Error_Information();

              std::cerr << "\n   Descriptor file directory path can not readed ..";

              std::cerr << "\n\n   The process will be interrupted ..";

              this->Print_End_of_Program();

              exit(1);
      }
 }

 void Descriptor_File_Data_Collector::Determine_Record_Lines(){

      this->Determine_Data_Record_Area("Header_File_Locations","}");

      this->Include_Directory_Record_Area[0] = this->Data_Record_StartLine;

      this->Include_Directory_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Source_File_Locations","}");

      this->Source_File_Locations_Record_Area[0] = this->Data_Record_StartLine;

      this->Source_File_Locations_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Library_Locations","}");

      this->Library_Directories_Record_Area[0] = this->Data_Record_StartLine;

      this->Library_Directories_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Header_File_Names","}");

      this->Header_File_Names_Record_Area[0] = this->Data_Record_StartLine;

      this->Header_File_Names_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Source_File_Names","}");

      this->Source_File_Names_Record_Area[0] = this->Data_Record_StartLine;

      this->Source_File_Names_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Library_Names","}");

      this->Library_Names_Record_Area[0] = this->Data_Record_StartLine;

      this->Library_Names_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Main_File_Name","}");

      this->Main_File_Name_Record_Area[0] = this->Data_Record_StartLine;

      this->Main_File_Name_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Project_Executable_File_Name","}");

      this->Executable_File_Name_Record_Area[0] = this->Data_Record_StartLine;

      this->Executable_File_Name_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Inter_Thread_Class_Header_File_Names","}");

      this->Inter_Thread_Class_Header_File_Names_Record_Area[0] = this->Data_Record_StartLine;

      this->Inter_Thread_Class_Header_File_Names_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Inter_Thread_Class_Names","}");

      this->Class_Names_Record_Area[0] = this->Data_Record_StartLine;

      this->Class_Names_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Inter_Thread_Class_Instance_Names","}");

      this->Class_Instance_Record_Area[0] = this->Data_Record_StartLine;

      this->Class_Instance_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Inter_Thread_Data_Types","}");

      this->Shared_Data_Types_Record_Area[0] = this->Data_Record_StartLine;

      this->Shared_Data_Types_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Inter_Thread_Data_Type_Header_File_Names","}");

      this->Shared_Data_Types_Include_Files_Record_Area[0] = this->Data_Record_StartLine;

      this->Shared_Data_Types_Include_Files_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Inter_Thread_Data_Type_Pointer_Names","}");

      this->Shared_Data_Type_Pointer_Names_Record_Area[0] = this->Data_Record_StartLine;

      this->Shared_Data_Type_Pointer_Names_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Construction_Point","}");

      this->Supervisor_Class_Construction_Point_Record_Area[0] = this->Data_Record_StartLine;

      this->Supervisor_Class_Construction_Point_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Server_Class_Name","}");

      this->Supervisor_Class_Name_Record_Area[0] = this->Data_Record_StartLine;

      this->Supervisor_Class_Name_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Thread_Number","}");

      this->Thread_Numbers_Record_Area[0] = this->Data_Record_StartLine;

      this->Thread_Numbers_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Thread_Function_Names","}");

      this->Thread_Names_Record_Area[0] = this->Data_Record_StartLine;

      this->Thread_Names_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("Namespace","}");

      this->Namespace_Record_Area[0] = this->Data_Record_StartLine;

      this->Namespace_Record_Area[1] = this->Data_Record_EndLine;

      this->Determine_Data_Record_Area("OpenMP_Support","}");

      this->OpenMP_Support_Record_Area[0] = this->Data_Record_StartLine;

      this->OpenMP_Support_Record_Area[1] = this->Data_Record_EndLine;
 }

 void Descriptor_File_Data_Collector::Determine_Data_Record_Area(const char * Start_Point, const char * End_Point){

      /* If a file or directory includes a name of description such as the word Namespace_Record_Area

         or  OpenMP_Support, decleration reader reads the wrong file line.

         Therefore, the following codelines are updated in order to prevent from this error */


      // Initialization of the tools that are used in checking

      char start_word [] = "Description [";

      char end_brace [] = "]";

      int start_word_size = strlen(start_word);

      int end_brace_size = strlen(end_brace);

      int Start_Point_Size = strlen(Start_Point);

      int search_string_size = start_word_size + end_brace_size + Start_Point_Size;

      char * search_string = new char [10*search_string_size];

      int index_counter = 0;

      for(int i=0;i<start_word_size;i++){

          search_string[index_counter] = start_word[i];

          index_counter++;
      }

      for(int i=0;i<Start_Point_Size;i++){

          search_string[index_counter] = Start_Point[i];

          index_counter++;
      }

      for(int i=0;i<end_brace_size;i++){

          search_string[index_counter] = end_brace[i];

          index_counter++;
      }

      search_string[index_counter] = '\0';

      this->ReadConstString(search_string);

      int Search_Start_Point = 1;

      this->Data_Record_StartLine = this->StringOperations.FindNextWordLine(this->GetConstString(),Search_Start_Point);

      if(!this->CharacterOperations.CompareString(this->StringOperations.GetStringBuffer(),search_string)){

          while(!this->CharacterOperations.CompareString(this->StringOperations.GetStringBuffer(),search_string)){

                 this->Data_Record_StartLine = this->StringOperations.FindNextWordLine(this->GetConstString(),Search_Start_Point);

                 Search_Start_Point = this->Data_Record_StartLine + 1;

                 if(this->StringOperations.Get_File_End_Condition()){

                    break;
                 }
          }
      }

      delete [] search_string;

      this->ReadConstString(End_Point);

      this->Data_Record_EndLine = this->StringOperations.FindNextWordLine(this->GetConstString(),this->Data_Record_StartLine);

      bool Start_Line_Find_Condition = false;

      for(int k=this->Data_Record_StartLine;k<=this->Data_Record_EndLine;k++){

          this->StringOperations.ReadFileLine(k);

          char * String_Line = this->StringOperations.GetStringBuffer();

          int String_Size = strlen(String_Line);

          for(int i=0;i<String_Size;i++){

              if(String_Line[i] == '{'){

                 Start_Line_Find_Condition = true;

                 this->Data_Record_StartLine = k;

                 break;
              }
          }
      }

      if(!Start_Line_Find_Condition){

          this->Print_Read_Error_Information();

          std::cerr << "\n\n      Start Brace location can not determined for";

          std::cerr << " [" << Start_Point << "]" << " definition..!";

          std::cerr << "\n\n      Place check definition, Process will be interrupted";

          std::cerr << "\n\n      Press Enter..";

          std::cerr << "\n\n";

          exit(1);
      }
 }

 void Descriptor_File_Data_Collector::ReadConstString(const char * ConstString){

      if(this->ConstString != nullptr){

         delete [] this->ConstString;

         this->ConstString = nullptr;
      }

      int String_Size = strlen(ConstString);

      this->ConstString = new char [10*String_Size];

      this->Place_String(&this->ConstString,ConstString,String_Size);
 }

 void Descriptor_File_Data_Collector::Determine_Data_Record_Numbers(){

      int Start_Point = 0, End_Point = 0;

      Start_Point = this->Include_Directory_Record_Area[0];

      End_Point   = this->Include_Directory_Record_Area[1];

      this->Include_Directory_Numbers = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Source_File_Locations_Record_Area[0];

      End_Point = this->Source_File_Locations_Record_Area[1];

      this->Source_File_Location_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Library_Directories_Record_Area[0];

      End_Point = this->Library_Directories_Record_Area[1];

      this->Library_Directory_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Source_File_Names_Record_Area[0];

      End_Point = this->Source_File_Names_Record_Area[1];

      this->Source_File_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Library_Names_Record_Area[0];

      End_Point = this->Library_Names_Record_Area[1];

      this->Library_Names_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Main_File_Name_Record_Area[0];

      End_Point = this->Main_File_Name_Record_Area[1];

      this->Main_File_Name_Record_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Executable_File_Name_Record_Area[0];

      End_Point = this->Executable_File_Name_Record_Area[1];

      this->Executable_File_Name_Record_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Header_File_Names_Record_Area[0];

      End_Point   = this->Header_File_Names_Record_Area[1];

      this->Header_File_Names_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Inter_Thread_Class_Header_File_Names_Record_Area[0];

      End_Point = this->Inter_Thread_Class_Header_File_Names_Record_Area[1];

      this->Inter_Thread_Class_Header_File_Names_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Class_Names_Record_Area[0];

      End_Point   = this->Class_Names_Record_Area[1];

      this->Class_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Class_Instance_Record_Area[0];

      End_Point   = this->Class_Instance_Record_Area[1];

      this->Class_Instance_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Shared_Data_Types_Include_Files_Record_Area[0];

      End_Point   = this->Shared_Data_Types_Include_Files_Record_Area[1];

      this->Shared_Data_Types_Include_File_Names_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Shared_Data_Types_Record_Area[0];

      End_Point   = this->Shared_Data_Types_Record_Area[1];

      this->Shared_Data_Types_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Shared_Data_Type_Pointer_Names_Record_Area[0];

      End_Point   = this->Shared_Data_Type_Pointer_Names_Record_Area[1];

      this->Shared_Data_Type_Pointer_Names_Number  = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Supervisor_Class_Construction_Point_Record_Area[0];

      End_Point   = this->Supervisor_Class_Construction_Point_Record_Area[1];

      this->Construction_Point_Record_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Supervisor_Class_Name_Record_Area[0];

      End_Point   = this->Supervisor_Class_Name_Record_Area[1];

      this->Supervisor_Class_Name_Record_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Thread_Numbers_Record_Area[0];

      End_Point = this->Thread_Numbers_Record_Area[1];

      this->Record_Line_Number_for_Total_Thread_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Thread_Names_Record_Area[0];

      End_Point   = this->Thread_Names_Record_Area[1];

      this->Thread_Function_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->Namespace_Record_Area[0];

      End_Point = this->Namespace_Record_Area[1];

      this->Namespace_Record_Number = this->Determine_Record_Number(Start_Point,End_Point);

      Start_Point = this->OpenMP_Support_Record_Area[0];

      End_Point = this->OpenMP_Support_Record_Area[1];

      this->OpenMP_Support_Condition_Record_Number = this->Determine_Record_Number(Start_Point,End_Point);
 }

 int Descriptor_File_Data_Collector::Determine_Record_Number(int Start_Point, int End_Point){

     this->Record_Number = 0;

     for(int i=Start_Point+1;i<End_Point;i++){

         this->StringOperations.ReadFileLine(i);

         int String_Size = strlen(this->StringOperations.GetStringBuffer());

         bool is_it_a_brace = false;

         for(int k=0;k<String_Size;k++){

             if(((this->StringOperations.GetStringBuffer()[k] == '{') || (this->StringOperations.GetStringBuffer()[k] == '}'))){

                 is_it_a_brace = true;

                 break;
             }
         }

         while((this->StringOperations.GetStringBuffer()[0] == '\t') || (this->StringOperations.GetStringBuffer()[0] == '\b') || (this->StringOperations.GetStringBuffer()[0] == ' ')){

               int String_Size = strlen(this->StringOperations.GetStringBuffer());

               for(int k=0;k<String_Size;k++){

                   this->StringOperations.GetStringBuffer()[k] = this->StringOperations.GetStringBuffer()[k+1];
               }
         }

         char Line_Start = this->StringOperations.GetStringBuffer()[0];

         if((Line_Start!= '\0') && (Line_Start!= '\n') && (!is_it_a_brace)){

            this->Record_Number++;
         }
     }

     return this->Record_Number;
 }

 void Descriptor_File_Data_Collector::Clear_Pointer_Memory(char ** Pointer){

      if(*Pointer != nullptr){

          delete [] (*Pointer);

          *Pointer = nullptr;
      }
 }

 void Descriptor_File_Data_Collector::Place_String(char ** Pointer, char * String, int String_Size){

      int Start_Point = 0;

      while(((String[Start_Point]== ' ') || (String[Start_Point]== '\t'))){

            Start_Point++;
      }

      int index_counter = 0;

      for(int i=Start_Point;i<String_Size;i++){

          (*Pointer)[index_counter] = String[i];

          index_counter++;
      }

      (*Pointer)[index_counter] = '\0';
 }

 void Descriptor_File_Data_Collector::Place_String(char ** Pointer, const char * String, int String_Size){

      int Start_Point = 0;

      while(((String[Start_Point]== ' ') || (String[Start_Point]== '\t'))){

              Start_Point++;
      }

      int index_counter = 0;

      for(int i=Start_Point;i<String_Size;i++){

         (*Pointer)[index_counter] = String[i];

         index_counter++;
      }

      (*Pointer)[index_counter] = '\0';
 }

 void Descriptor_File_Data_Collector::Print_Read_Error_Information(){

      std::cerr << "\n";

      std::cerr << "\n  # ERROR MESSAGE";

      std::cerr << "\n";

      std::cerr << "\n  # Error Type: Descriptor File Read Error";

      std::cerr << "\n\n  [ THE POSSIBLE REASON OF THE ERROR ]";

      std::cerr << "\n\n  {";
 }

 void Descriptor_File_Data_Collector::Print_End_of_Program(){

      std::cerr << "\n  }";

      std::cerr << "\n\n  THE END OF THE PROGRAM \n\n";
 }

 char *  Descriptor_File_Data_Collector::GetConstString() const
 {
         return this->ConstString;
 }

 char * Descriptor_File_Data_Collector::Get_DescriptorFileName() const
 {
        return this->DescriptorFileName;
 }

 char * Descriptor_File_Data_Collector::Get_DescriptorFileDirectory() const
 {
        return this->DescriptorFileDirectory;
 }
