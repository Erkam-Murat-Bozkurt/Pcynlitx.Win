
#include "DataRecorder.h"

int main(int argc, char ** argv){

    DataRecorder Recorder;

    Recorder.SetFilePath(argv[1]);

    char Data_Type [] = "Header_File_Locations";

    //Recorder.Collect_Information_For_Data_Recording(Data_Type);

    Recorder.Read_Data_Records(Data_Type);

    std::cout << "\n Data record number:" << Recorder.Get_Data_Type_Record_Number();

    std::cout << "\n Up record number:" << Recorder.Get_Up_Record_Number();

    for(int i=0;i<Recorder.Get_Data_Type_Record_Number();i++){

       std::cout << "\n Recorder.Get_Data_Type_Records()[" << i << "]:" << Recorder.Get_Data_Type_Records()[i] << "#";
    }

    Recorder.Clear_Dynamic_Memory();

    std::cout << "\n\n The end of the file..\n\n";

    return 0;
}
