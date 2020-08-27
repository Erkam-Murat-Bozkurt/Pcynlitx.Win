
#include "Process_Descriptions_Recorder.h"

int main(int argc, char ** argv){

    Process_Descriptions_Recorder Recorder;

    Recorder.Set_Descriptor_File_Path(argv[1]);

    char Header_File_Locations_Data_Determiner [] = "Header_File_Locations";

    char Source_File_Location_Data_Determiner [] = "Source_File_Locations";

    char Library_Locations_Data_Determiner [] = "Library_Locations";

    char Library_Names_Data_Determiner [] = "Library_Names";

    char Thread_Function_Name_Data_Determiner [] = "Thread_Function_Names";

    char Main_File_Name_Data_Determiner [] = "Main_File_Name";

    char Namespace_Data_Determiner [] = "Namespace";

    char OpenMP_Support_Determiner [] = "OpenMP_Support";

    char Construction_Point_Data_Determiner [] = "Construction_Point";

    char Executable_File_Name_Data_Determiner [] = "Project_Executable_File_Name";

    char Thread_Number_Data_Determiner [] = "Thread_Number";

    char Server_Class_Name_Data_Determiner [] = "Server_Class_Name";

    char Header_File_Name_Data_Determiner [] = "Header_File_Names";

    char Source_File_Name_Data_Determiner [] = "Source_File_Names";

    char ITC_Header_File_Name_Data_Determiner [] = "Inter_Thread_Class_Header_File_Names";

    char ITD_Heder_File_Name_Data_Determiner [] = "Inter_Thread_Data_Type_Header_File_Names";

    char ITC_Name_Data_Determiner [] = "Inter_Thread_Class_Names";

    char ITC_Instance_Name_Data_Determiner [] = "Inter_Thread_Class_Instance_Names";

    char ITD_Type_Name_Data_Determiner [] = "Inter_Thread_Data_Types";

    char ITDT_Pointer_Name_Determiner [] = "Inter_Thread_Data_Type_Pointer_Names";


    int Exit_Status = 0;

    if(Recorder.Compare_Strings(argv[2],Header_File_Locations_Data_Determiner)){

        Exit_Status = Recorder.Record_Header_File_Location_Data(argv[3]);
    }


    if(Recorder.Compare_Strings(argv[2],Source_File_Location_Data_Determiner)){

       Exit_Status = Recorder.Record_Source_File_Location_Data(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Library_Locations_Data_Determiner)){

       Exit_Status = Recorder.Record_Library_Locations_Data(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Library_Names_Data_Determiner)){

       Exit_Status = Recorder.Record_Library_Names_Data(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Thread_Function_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Thread_Function_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Main_File_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Main_File_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Executable_File_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Executable_File_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Construction_Point_Data_Determiner)){

       Exit_Status = Recorder.Record_Construction_Point(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Server_Class_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Server_Class_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Thread_Number_Data_Determiner)){

       Exit_Status = Recorder.Record_Thread_Number(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Header_File_Name_Data_Determiner)){

      Exit_Status = Recorder.Record_Header_File_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Source_File_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Source_File_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],ITC_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Inter_Thread_Class_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],ITC_Instance_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Inter_Thread_Class_Instance_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],ITD_Type_Name_Data_Determiner)){

      Exit_Status = Recorder.Record_Inter_Thread_Data_Type(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],ITDT_Pointer_Name_Determiner)){

       Exit_Status = Recorder.Record_Inter_Thread_Data_Type_Pointer_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],ITC_Header_File_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Inter_Thread_Class_Header_File_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],ITD_Heder_File_Name_Data_Determiner)){

       Exit_Status = Recorder.Record_Inter_Thread_Data_Type_Header_File_Name(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],Namespace_Data_Determiner)){

       Exit_Status = Recorder.Record_Namespace(argv[3]);
    }

    if(Recorder.Compare_Strings(argv[2],OpenMP_Support_Determiner)){

       Exit_Status = Recorder.Record_OpenMP_Option(argv[3]);
    }

    std::cout << Exit_Status;

    exit(0);
}
