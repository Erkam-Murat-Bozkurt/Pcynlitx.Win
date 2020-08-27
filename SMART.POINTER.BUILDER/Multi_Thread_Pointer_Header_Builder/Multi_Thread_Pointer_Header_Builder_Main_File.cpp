
 #include "Multi_Thread_Pointer_Header_Builder.h"
 #include "Process_Supervisor_Descriptor_File_Reader.h"

 int main(int argc, char** argv){

     Multi_Thread_Pointer_Header_Builder P_Header_Builder;

     Process_Supervisor_Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Reader.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Reader.Receive_Descriptor_File_Infomations();

     int Total_Data_Type_Number = File_Reader.Get_Shared_Data_Types()[1].Total_Data_Type_Number;

     char * Data_Type = File_Reader.Get_Shared_Data_Types()[1].Data_Type;

     int  Data_Number = File_Reader.Get_Shared_Data_Types()[1].Data_Number;

     char * Pointer_Name = File_Reader.Get_Shared_Data_Types()[1].Pointer_Name;

     char * Header_File_Name = File_Reader.Get_Shared_Data_Types()[1].Header_File_Name;

     char * Include_Directory = File_Reader.Get_Shared_Data_Types()[1].Include_Directory;

     char * Construction_Point = File_Reader.Get_Construction_Point();

     if(Total_Data_Type_Number > 0){

        std::cout << "\n Data Type        : " << Data_Type << "#";

        std::cout << "\n Data Number      : " << Data_Number << "#";

        std::cout << "\n Pointer Name     : " << Pointer_Name << "#";

        if(Header_File_Name != nullptr){

           std::cout << "\n Header file name : " << Header_File_Name << "#";
        }
        else{
                   std::cout << "\n There is no header file name..";
        }

        if(Include_Directory != nullptr){

           std::cout << "\n Include_Directory: " << Include_Directory << "#";
        }
        else{
                std::cout << "\n  There is no include directory ..";
        }
     }

     std::cout << "\n\n";

     P_Header_Builder.Receive_Data_Type(Data_Type);

     //P_Header_Builder.Receive_Entered_Class_Name(Entered_Class_Name_Pointer);

     P_Header_Builder.Receive_Construction_Point(Construction_Point);

     P_Header_Builder.Receive_Data_Type_Include_File_Name(Header_File_Name);

     //P_Header_Builder.Set_New_Class_Name_Directly(New_Class_Name_Pointer);

     //P_Header_Builder.Set_Data_Type_Include_File_Name_Receive_Condition(false);

     P_Header_Builder.Build_Header_File();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
