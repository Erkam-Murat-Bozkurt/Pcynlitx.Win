
 #include "Descriptor_File_Reader.h"
 #include "Multi_Thread_Pointer_Builder.h"


 int main(int argc, char** argv){

     Multi_Thread_Pointer_Builder P_Builder;

     Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

     File_Reader.Receive_Descriptor_File_Infomations();

     P_Builder.Receive_Descriptor_File_Reader(&File_Reader);

     char Include_Directory [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile";

     int Data_Type_Number = 2;

     P_Builder.Receive_Data_Type_Number(Data_Type_Number);

     P_Builder.Receive_Newly_Constructed_Include_Directory(Include_Directory);

     P_Builder.Build_Pointer();

     std::cout << "\n\n Header file paths in new include directory:";

     for(int i=0;i<3;i++){

         std::cout << "\n\n" << P_Builder.Get_Header_File_Paths_In_New_Include_Directory()[i] << "#";
     }

     std::cout << "\n\n Header File Name List :" << P_Builder.Get_Header_File_Name_List() << "#";

     std::cout << "\n\n Object_File_List:" << P_Builder.Get_Object_File_List();

     std::cout << "\n\n New_Class_Name:" << P_Builder.Get_New_Class_Name();

     P_Builder.Run_System_Commands();

     File_Reader.Clear_Dynamic_Memory();

     P_Builder.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
