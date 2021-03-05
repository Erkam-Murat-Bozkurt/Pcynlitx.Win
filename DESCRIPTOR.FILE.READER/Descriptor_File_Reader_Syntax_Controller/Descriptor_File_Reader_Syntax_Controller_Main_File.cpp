
#include "Descriptor_File_Reader.h"
#include "Descriptor_File_Reader_Syntax_Controller.h"

int main(int argc, char** argv){

    Descriptor_File_Reader File_Reader;

    File_Reader.Receive_Descriptor_File_Directory(argv[1]);

    File_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");

    File_Reader.Receive_Descriptor_File_Infomations();

    Descriptor_File_Reader_Syntax_Controler Syntax_Controler;

    if(File_Reader.Get_Class_Number() > 0){

        Syntax_Controler.Determine_Class_Data_Type_Receive_Condition(true);

        Syntax_Controler.Receive_Inter_Thread_Class_Data(File_Reader.Get_Class_Names());
    }
    else{

        Syntax_Controler.Determine_Class_Data_Type_Receive_Condition(false);
    }

    if(File_Reader.Get_Shared_Data_Types_Number() > 0){

        Syntax_Controler.Determine_Shared_Data_Type_Receive_Condition(true);

        Syntax_Controler.Receive_Inter_Thread_Data_Type_Data(File_Reader.Get_Shared_Data_Types());
    }
    else{

         Syntax_Controler.Determine_Shared_Data_Type_Receive_Condition(false);
    }

    Syntax_Controler.Receive_Construction_Point(File_Reader.Get_Construction_Point());

    Syntax_Controler.Control_Process_Syntax();

    Syntax_Controler.Clear_Dynamic_Memory();

    return 0;
}
