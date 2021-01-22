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
#include "Process_Descriptions_Recorder.h"

Process_Descriptions_Recorder::Process_Descriptions_Recorder(){

      this->Memory_Delete_Condition = false;
}

Process_Descriptions_Recorder::~Process_Descriptions_Recorder(){

     if(!this->Memory_Delete_Condition){

        this->Clear_Dynamic_Memory();
     }
}

void Process_Descriptions_Recorder::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Record_Tools.Clear_Dynamic_Memory();
     }
}

void Process_Descriptions_Recorder::Set_Descriptor_File_Path(char * Descriptor_File_Path){

     this->Recorder.SetFilePath(Descriptor_File_Path);

     this->Record_Tools.SetFilePath(Descriptor_File_Path);
}

int Process_Descriptions_Recorder::Record_Inter_Thread_Class_Name(char * IT_Class_Name){

     char Data_Type [] = "Inter_Thread_Class_Names";

     this->Record_Data_To_File(Data_Type,IT_Class_Name);

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Inter_Thread_Class_Instance_Name(char * IT_Class_Instance_Name){

     char Data_Type [] = "Inter_Thread_Class_Instance_Names";

     this->Record_Data_To_File(Data_Type,IT_Class_Instance_Name);

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Inter_Thread_Data_Type(char * IT_Data_Type){

     char Data_Type [] = "Inter_Thread_Data_Types";

     this->Record_Data_To_File(Data_Type,IT_Data_Type);

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Inter_Thread_Data_Type_Pointer_Name(char * IT_Data_Type_Pointer_Name){

     char Data_Type [] = "Inter_Thread_Data_Type_Pointer_Names";

     this->Record_Data_To_File(Data_Type,IT_Data_Type_Pointer_Name);

     return this->Recorder.Get_Record_Point();
}


int Process_Descriptions_Recorder::Record_Header_File_Location_Data(char * Include_Directory_Data){

     char Data_Type [] = "Header_File_Locations";

     this->Record_Data_To_File(Data_Type,Include_Directory_Data);

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Source_File_Location_Data(char * Source_File_Locations_Data){

     char Data_Type [] = "Source_File_Locations";

     this->Record_Data_To_File(Data_Type,Source_File_Locations_Data);

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Library_Locations_Data(char * Library_Locations_Data){

     char Data_Type [] = "Library_Locations";

     this->Record_Data_To_File(Data_Type,Library_Locations_Data);

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Library_Names_Data(char * Library_Names_Data){

     char Data_Type [] = "Library_Names";

     char Location_Data_Type [] = "Library_Locations";

     this->Record_Tools.Determine_Library_Name_Informations(Library_Names_Data);

     this->Record_Data_To_File(Location_Data_Type,this->Record_Tools.Get_File_Directory());

     this->Record_Data_To_File(Data_Type,this->Record_Tools.Get_File_Name());

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Thread_Function_Name(char * Function_Name_Data){

     char Data_Type [] = "Thread_Function_Names";

     this->Recorder.Read_Data_Records(Data_Type);

     int Data_Type_Record_Number = this->Recorder.Get_Data_Type_Record_Number();

     bool is_record_exist = this->Record_Tools.Is_Record_Exist(Data_Type,Function_Name_Data);

     this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

     if(((!is_record_exist) || (Data_Type_Record_Number == 0))){

         this->Recorder.Add_Data_Record(Function_Name_Data);
     }

     this->Recorder.Clear_Dynamic_Memory();

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Main_File_Name(char * Main_File_Name_Data){

     char Data_Type [] = "Main_File_Name";

     this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

     if(this->Recorder.Get_Data_Type_Record_Number() > 0){

        this->Recorder.Replace_Data_Record(Main_File_Name_Data);

        this->Recorder.Clear_Dynamic_Memory();
     }
     else{
            this->Recorder.Add_Data_Record(Main_File_Name_Data);

            this->Recorder.Clear_Dynamic_Memory();
     }

     return this->Recorder.Get_Record_Point();
}


int Process_Descriptions_Recorder::Record_Construction_Point(char * Construction_Point_Data){

     char Data_Type [] = "Construction_Point";

     this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

     if(this->Recorder.Get_Data_Type_Record_Number() > 0){

        this->Recorder.Replace_Data_Record(Construction_Point_Data);

        this->Recorder.Clear_Dynamic_Memory();
     }
     else{
            this->Recorder.Add_Data_Record(Construction_Point_Data);

            this->Recorder.Clear_Dynamic_Memory();
     }
     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Executable_File_Name(char * Executable_File_Name){

     char Data_Type [] = "Project_Executable_File_Name";

     this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

     if(this->Recorder.Get_Data_Type_Record_Number() > 0){

        this->Recorder.Replace_Data_Record(Executable_File_Name);

        this->Recorder.Clear_Dynamic_Memory();
     }
     else{
            this->Recorder.Add_Data_Record(Executable_File_Name);

            this->Recorder.Clear_Dynamic_Memory();
     }

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Thread_Number(char * Thread_Number_Data){

     char Data_Type [] = "Thread_Number";

     this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

     if(this->Recorder.Get_Data_Type_Record_Number() > 0){

        this->Recorder.Replace_Data_Record(Thread_Number_Data);

        this->Recorder.Clear_Dynamic_Memory();
     }
     else{
            this->Recorder.Add_Data_Record(Thread_Number_Data);

            this->Recorder.Clear_Dynamic_Memory();
     }

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Server_Class_Name(char * Server_Class_Name){

     char Data_Type [] = "Server_Class_Name";

     this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

     if(this->Recorder.Get_Data_Type_Record_Number() > 0){

        this->Recorder.Replace_Data_Record(Server_Class_Name);

        this->Recorder.Clear_Dynamic_Memory();
     }
     else{
            this->Recorder.Add_Data_Record(Server_Class_Name);

            this->Recorder.Clear_Dynamic_Memory();
     }

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Namespace(char * Namespace){

     char Data_Type [] = "Namespace";

     this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

     if(this->Recorder.Get_Data_Type_Record_Number() > 0){

        this->Recorder.Replace_Data_Record(Namespace);

        this->Recorder.Clear_Dynamic_Memory();
     }
     else{
            this->Recorder.Add_Data_Record(Namespace);

            this->Recorder.Clear_Dynamic_Memory();
     }

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_OpenMP_Option(char * option){

     char Data_Type [] = "OpenMP_Support";

     this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

     if(this->Recorder.Get_Data_Type_Record_Number() > 0){

        this->Recorder.Replace_Data_Record(option);

        this->Recorder.Clear_Dynamic_Memory();
     }
     else{
            this->Recorder.Add_Data_Record(option);

            this->Recorder.Clear_Dynamic_Memory();
     }

     return this->Recorder.Get_Record_Point();
}


int Process_Descriptions_Recorder::Record_Header_File_Name(char * Input_Data_File_PATH){

     char Header_File_Names_Data_Type [] = "Header_File_Names";

     char Header_File_Locations_Data_Type [] = "Header_File_Locations";

     this->Record_Tools.Determine_File_Informations(Input_Data_File_PATH);

     char * Header_File_Name = this->Record_Tools.Get_File_Name();

     bool Is_this_record_already_exist = false;

     int Location_Number = 0, Data_Number = 0;

     // Header File name record checking

     Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(Header_File_Names_Data_Type,Header_File_Name);

     if(!Is_this_record_already_exist){

        this->Recorder.Clear_Dynamic_Memory();

        this->Recorder.Determine_Data_Type_Record_Number(Header_File_Names_Data_Type);

        Data_Number = this->Recorder.Get_Data_Type_Record_Number()+1;

        char * Input_File_Location = this->Record_Tools.Get_File_Directory();

        Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(Header_File_Locations_Data_Type,Input_File_Location);

        if(!Is_this_record_already_exist){

           this->Recorder.Determine_Data_Type_Record_Number(Header_File_Locations_Data_Type);

           Location_Number = this->Recorder.Get_Data_Type_Record_Number() + 1;

           this->Record_Data_To_File(Header_File_Locations_Data_Type,Input_File_Location);
        }
        else{

           Location_Number = this->Record_Tools.Get_Directory_Number();
        }

        this->Record_Tools.Determine_Header_File_Name_Record_Data(Header_File_Name,Location_Number,Data_Number);

        this->Recorder.Collect_Information_For_Data_Recording(Header_File_Names_Data_Type);

        this->Recorder.Add_Data_Record(this->Record_Tools.Get_Header_File_Name_Record_Data());
     }
     else{

          this->Recorder.Collect_Information_For_Data_Recording(Header_File_Names_Data_Type);
     }

     this->Recorder.Clear_Dynamic_Memory();

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Source_File_Name(char * Source_File_PATH){

     char Source_File_Locations_Data_Type [] = "Source_File_Locations";

     char Source_File_Names_Data_Type [] = "Source_File_Names";

     this->Record_Tools.Determine_File_Informations(Source_File_PATH);

     char * Source_File_Name = this->Record_Tools.Get_File_Name();

     bool Is_this_record_already_exist = false;

     int Location_Number = 0, Data_Number = 0;

     // Header File name record checking

     Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(Source_File_Names_Data_Type,Source_File_Name);

     if(!Is_this_record_already_exist){

        this->Recorder.Clear_Dynamic_Memory();

        this->Recorder.Determine_Data_Type_Record_Number(Source_File_Names_Data_Type);

        Data_Number = this->Recorder.Get_Data_Type_Record_Number()+1;

        char * Input_File_Location = this->Record_Tools.Get_File_Directory();

        Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(Source_File_Locations_Data_Type,Input_File_Location);

        if(!Is_this_record_already_exist){

            this->Recorder.Determine_Data_Type_Record_Number(Source_File_Locations_Data_Type);

            Location_Number = this->Recorder.Get_Data_Type_Record_Number() + 1;

            this->Record_Data_To_File(Source_File_Locations_Data_Type,Input_File_Location);
        }
        else{

            Location_Number = this->Record_Tools.Get_Directory_Number();
        }

        this->Record_Tools.Determine_Source_File_Name_Record_Data(Source_File_Name,Location_Number,Data_Number);

        this->Recorder.Collect_Information_For_Data_Recording(Source_File_Names_Data_Type);

        this->Recorder.Add_Data_Record(this->Record_Tools.Get_Source_File_Name_Record_Data());
     }
     else{

          this->Recorder.Collect_Information_For_Data_Recording(Source_File_Names_Data_Type);
     }

     this->Recorder.Clear_Dynamic_Memory();

     return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Inter_Thread_Class_Header_File_Name(char * IT_Class_Header_File_PATH){

     char Header_File_Locations_Data_Type [] = "Header_File_Locations";

     char ITC_Header_File_Names_Data_Type [] = "Inter_Thread_Class_Header_File_Names";

     this->Record_Tools.Determine_File_Informations(IT_Class_Header_File_PATH);

     char * ITC_Header_File_Name = this->Record_Tools.Get_File_Name();

     bool Is_this_record_already_exist = false;

     int Location_Number = 0, Data_Number = 0;

     // Header File name record checking

     Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(ITC_Header_File_Names_Data_Type,ITC_Header_File_Name);

     if(!Is_this_record_already_exist){

         this->Recorder.Clear_Dynamic_Memory();

         this->Recorder.Determine_Data_Type_Record_Number(ITC_Header_File_Names_Data_Type);

         Data_Number = this->Recorder.Get_Data_Type_Record_Number()+1;

         char * Input_File_Location = this->Record_Tools.Get_File_Directory();

         Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(Header_File_Locations_Data_Type,Input_File_Location);

         if(!Is_this_record_already_exist){

             this->Recorder.Determine_Data_Type_Record_Number(Header_File_Locations_Data_Type);

             Location_Number = this->Recorder.Get_Data_Type_Record_Number() + 1;

             this->Record_Data_To_File(Header_File_Locations_Data_Type,Input_File_Location);
         }
         else{
                Location_Number = this->Record_Tools.Get_Directory_Number();
         }

         this->Record_Tools.Determine_ITC_Header_File_Name_Record_Data(ITC_Header_File_Name,Location_Number,Data_Number);

         this->Recorder.Collect_Information_For_Data_Recording(ITC_Header_File_Names_Data_Type);

         this->Recorder.Add_Data_Record(this->Record_Tools.Get_ITC_Header_File_Name_Record_Data());
    }
    else{

         this->Recorder.Collect_Information_For_Data_Recording(ITC_Header_File_Names_Data_Type);
    }

    this->Recorder.Clear_Dynamic_Memory();

    return this->Recorder.Get_Record_Point();
}

int Process_Descriptions_Recorder::Record_Inter_Thread_Data_Type_Header_File_Name(char * ITD_Header_File_PATH){

     char Header_File_Locations_Data_Type [] = "Header_File_Locations";

     char Data_Type [] = "Inter_Thread_Data_Types";

     char ITD_Header_File_Names_Data_Type [] = "Inter_Thread_Data_Type_Header_File_Names";

     this->Record_Tools.Determine_File_Informations(ITD_Header_File_PATH);

     char * ITD_Header_File_Name = this->Record_Tools.Get_File_Name();

     bool Is_this_record_already_exist = false;

     int Location_Number = 0, Data_Number = 0;

     // Header File name record checking

     Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(ITD_Header_File_Names_Data_Type,ITD_Header_File_Name);

     if(!Is_this_record_already_exist){

         this->Recorder.Clear_Dynamic_Memory();

         this->Recorder.Determine_Data_Type_Record_Number(Data_Type);

         Data_Number = this->Recorder.Get_Data_Type_Record_Number()+1;

         char * Input_File_Location = this->Record_Tools.Get_File_Directory();

         Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(Header_File_Locations_Data_Type,Input_File_Location);

         if(!Is_this_record_already_exist){

             this->Recorder.Determine_Data_Type_Record_Number(Header_File_Locations_Data_Type);

             Location_Number = this->Recorder.Get_Data_Type_Record_Number() + 1;

             this->Record_Data_To_File(Header_File_Locations_Data_Type,Input_File_Location);
         }
         else{
                Location_Number = this->Record_Tools.Get_Directory_Number();
         }

         this->Record_Tools.Determine_ITD_Header_File_Name_Record_Data(ITD_Header_File_Name,Location_Number,Data_Number);

         this->Recorder.Collect_Information_For_Data_Recording(ITD_Header_File_Names_Data_Type);

         this->Recorder.Add_Data_Record(this->Record_Tools.Get_ITD_Header_File_Name_Record_Data());
     }
     else{

           this->Recorder.Collect_Information_For_Data_Recording(ITD_Header_File_Names_Data_Type);
     }

     this->Recorder.Clear_Dynamic_Memory();

     return this->Recorder.Get_Record_Point();
}

void Process_Descriptions_Recorder::Record_Data_To_File(char * Data_Type, char * Data){

     bool Is_this_record_already_exist = this->Record_Tools.Is_Record_Exist(Data_Type,Data);

     this->Recorder.Read_Data_Records(Data_Type);

     int Data_Type_Record_Number = this->Recorder.Get_Data_Type_Record_Number();

     if(((!Is_this_record_already_exist) || (Data_Type_Record_Number == 0))){

         this->Record_Tools.Determine_Standart_Record_Data(Data,Data_Type_Record_Number);

         this->Recorder.Collect_Information_For_Data_Recording(Data_Type);

         this->Recorder.Add_Data_Record(this->Record_Tools.Get_Standart_Record_Data());
     }
     else{

          this->Recorder.Collect_Information_For_Data_Recording(Data_Type);
     }

     this->Recorder.Clear_Dynamic_Memory();
}

bool Process_Descriptions_Recorder::Compare_Strings(char * First_String, char * Second_String){

     return this->Record_Tools.Compare_Strings(First_String,Second_String);
}
