
 #include "HeaderRebuilder.h"
 #include <ClassRebuilder_Initializer.h>
 #include <MemberFunctionReader.h>
 #include <DescriptorFileReader.h>
 #include <Process_Supervisor_Descriptor_File_Reader.h>

 void Place_Information(char ** Pointer, const char * Information, int String_Size){

      for(int i=0;i<String_Size;i++){

          (*Pointer)[i] = Information[i];
      }

      (*Pointer)[String_Size] = '\0';
 }


 int main(int argc, char** argv){

     const char * Base_Directory = "/home/erkam/IntelligentObject/TestDirectory";

     int String_Size = strlen(Base_Directory);

     char * Directory = new char [5*String_Size];

     Place_Information(&Directory ,Base_Directory,String_Size);

     Process_Supervisor_Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("/home/erkam/IntelligentObject/TestDirectory");

     File_Reader.Receive_Descriptor_File_Name("Supervisor_Constructor_Descriptor_File");

     File_Reader.Receive_Descriptor_File_Infomations();

     int Total_Include_Directory_Number = File_Reader.Get_Include_Directory()[0].Total_Include_Directory_Number;

     ClassRebuilder_Initializer Initializer;

     Initializer.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

     Initializer.Receive_Supervisor_Newly_Constructed_Include_Directory(Directory);

     int Class_Number = 1;

     int Data_Type_Number = 1;

     bool Class_Data_Type_Receive_Condition = true;

     bool Shared_Data_Type_Receive_Condition = false;

     if(Class_Data_Type_Receive_Condition){

        Initializer.Receive_Class_Number(Class_Number);
     }

     if(Shared_Data_Type_Receive_Condition){

        Initializer.Receive_Data_Type_Number(Data_Type_Number);
     }

     Initializer.Determine_Informations();

     MemberFunctionReader Header_Reader;

     char * Header_File_Location = Initializer.Get_Base_Class_Header_File_Location();

     char * Header_File_Name = Initializer.Get_Base_Class_Header_File_Name();

     Header_Reader.Receive_Include_Directory_PATH(Header_File_Location);

     Header_Reader.Receive_Header_File_Name(Header_File_Name);

     Header_Reader.Receive_Base_Directory(Directory);

     Header_Reader.Read_Member_Functions();

     HeaderRebuilder Rebuilder;

     Rebuilder.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

     Rebuilder.Receive_ClassRebuilder_Initializer(&Initializer);

     Rebuilder.Receive_MemberFunctionReader(&Header_Reader);

     Rebuilder.Build_Header_File();

     Rebuilder.Clear_Dynamic_Memory();

     File_Reader.Clear_Dynamic_Memory();

     Initializer.Clear_Dynamic_Memory();

     delete [] Directory;

     std::cout << "\n\n The end of the program ..\n\n";

    return 0;
 };
