
#include "DataRecord_Tools.h"

int main(int argc, char ** argv){

    DataRecord_Tools Tool;

    Tool.SetFilePath(argv[1]);

    char Header_File [] = "/home/erkam/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/Sample_Header.h";

    Tool.Determine_File_Informations(Header_File);

    std::cout << "\n File name:" << Tool.Get_File_Name() << "#";

    std::cout << "\n Directory:" << Tool.Get_File_Directory() << "#";

    char Record_Type [] = "Header_File_Locations";

    char Input_Data [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile/";

    bool Is_Exist = Tool.Is_Record_Exist(Record_Type,Input_Data);

    std::cout << "\n Is this record exits:" << Is_Exist;

    int Location_Number = 1;

    int Data_Number = 2;

    Tool.Determine_Header_File_Name_Record_Data(Tool.Get_File_Name(),Location_Number,Data_Number);

    std::cout << "\n Header file name record data:" << Tool.Get_Header_File_Name_Record_Data() << "#";

    char Source_File_Name [] = "Sample_Header.cpp";

    Tool.Determine_Source_File_Name_Record_Data(Source_File_Name,Location_Number,Data_Number);

    std::cout << "\n Source file name record data:" << Tool.Get_Source_File_Name_Record_Data() << "#";

    char ITC_Header_File [] = "CFileOperations.h";

    Tool.Determine_ITC_Header_File_Name_Record_Data(ITC_Header_File,Location_Number,Data_Number);

    std::cout << "\n ITC Header file name record:" << Tool.Get_ITC_Header_File_Name_Record_Data();

    char ITD_Header_File [] = "IntToCharTranslater.h";

    Tool.Determine_ITD_Header_File_Name_Record_Data(ITD_Header_File,Location_Number,Data_Number);

    std::cout << "\n ITD Header File Name Record:" << Tool.Get_ITD_Header_File_Name_Record_Data();

    char First_String [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile";

    char Second_String [] = "/home/erkam/META.PROGRAMMING.PROJECT/SEMI.AUTONOM.THREAD.MANAGEMENT/TestDirectory/TestHeaderFile";

    std::cout << "\n Is these strings equal :" << Tool.Compare_Strings(First_String,Second_String);

    //Tool.Clear_Dynamic_Memory();

    std::cout << "\n\n The end of the program .. \n\n";

    return 0;
}
