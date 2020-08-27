
 #include "ClassRebuilder_Initializer.h"
 #include "Process_Supervisor_Descriptor_File_Reader.h"
 #include <iostream>

 int main(int argc, char** argv){

     char Newly_Constructed_Directory [ ] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/Thread_Server_Include_Directory";

     // ********************************************************************

     Process_Supervisor_Descriptor_File_Reader File_Reader;

     File_Reader.Receive_Descriptor_File_Directory("/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory");

     File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

     File_Reader.Receive_Descriptor_File_Infomations();

     // ********************************************************************

     ClassRebuilder_Initializer Initializer;

     Initializer.Receive_Process_Supervisor_Descriptor_File_Reader(&File_Reader);

     int Class_Number = 1;

     int Data_Type_Number = 2;

     bool Class_Data_Type_Receive_Condition = false;

     bool Shared_Data_Type_Receive_Condition = true;

     if(Class_Data_Type_Receive_Condition){

        Initializer.Receive_Class_Number(Class_Number);
     }

     if(Shared_Data_Type_Receive_Condition){

        Initializer.Receive_Data_Type_Number(Data_Type_Number);
     }

     Initializer.Determine_Informations();


     std::cout << "\n New Constructor Name:" << Initializer.Get_New_Class_Constructor_Name();

     std::cout << "\n New Destructor Name:"  << Initializer.Get_New_Class_Destructor_Name();

     std::cout << "\n Base Class Destructor Name:" << Initializer.Get_Base_Class_Destructor_Name();

     std::cout << "\n New Class Name:" << Initializer.Get_New_Class_Name();

     std::cout << "\n New Header File Name:" << Initializer.Get_New_Header_File_Name();

     std::cout << "\n New Class Implementation File Name:" << Initializer.Get_New_Class_Implementation_File_Name();

     int Index_Number = Initializer.Get_Index_Number_For_Descriptor_File_Reader();

     std::cout << "\n Index_Number:" << Index_Number;

     char * Base_Class_Constructor_Name = nullptr;

     if(Class_Data_Type_Receive_Condition){

        Class_Data_Type * Class_Data_Holder = File_Reader.Get_Class_Names();

        Base_Class_Constructor_Name = Class_Data_Holder[Index_Number].Class_Name;
     }

     if(Shared_Data_Type_Receive_Condition){

        Shared_Memory_Data_Type * Data_Holder = File_Reader.Get_Shared_Data_Types();

        Base_Class_Constructor_Name = Data_Holder[Index_Number].Data_Type;
     }

     std::cout << "\n Base class constructor name:" << Initializer.Get_Base_Class_Name();

     std::cout << "\n Base class destructor name:" << Initializer.Get_Base_Class_Destructor_Name();

     std::cout << "\n Is this Base class Constructor:" << Initializer.Is_This_Method_Base_Class_Constructor(Base_Class_Constructor_Name);

      std::cout << "\n Is this Base class Constructor:" << Initializer.Is_This_Method_Base_Class_Constructor(Initializer.Get_Base_Class_Name());

     std::cout << "\n Is this Base Class Destructor:" << Initializer.Is_This_Method_Base_Class_Destructor(Initializer.Get_Base_Class_Destructor_Name());

     std::cout << "\n Object Name:" << Initializer.Get_Object_Name();


     if(Initializer.Get_Base_Class_Header_File_Name() != nullptr){

        std::cout << "\n Base Class Header File Name:" << Initializer.Get_Base_Class_Header_File_Name();
     }

     if(Initializer.Get_Base_Class_Header_File_Path() != nullptr){

        std::cout << "\n Base_Class_Header_File_Path:" << Initializer.Get_Base_Class_Header_File_Path();
     }

     if(Initializer.Get_Base_Class_Header_File_Location() != nullptr){

        std::cout << "\n Base_Class_Header_File_Location:" << Initializer.Get_Base_Class_Header_File_Location();
     }

     if(Initializer.Get_Base_Class_Name() != nullptr){

        std::cout << "\n Base_Class_Name:" <<  Initializer.Get_Base_Class_Name();
     }

     if(Initializer.Get_Base_Class_Instance_Name() != nullptr){

        std::cout << "\n Base_Class_Instance_Name:" << Initializer.Get_Base_Class_Instance_Name();
     }

     Initializer.Clear_Dynamic_Memory();

     File_Reader.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
