
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

#include "Description_Printer.h"

Description_Printer::Description_Printer(){

}

Description_Printer::~Description_Printer(){

}

void Description_Printer::Receive_Descriptor_File_Directory(char * Descriptor_Directory){

     this->Description_Reader.Receive_Descriptor_File_Directory(Descriptor_Directory);

     this->Description_Reader.Receive_Descriptor_File_Name("Project_Descriptor_File");
}

void Description_Printer::Read_Descriptions(){

     this->Description_Reader.Receive_Descriptor_File_Infomations();
}

void Description_Printer::Print_Descriptions(){

     std::string Structural_Descriptions         = "\t\t[ MAIN DESCRIPTIONS ]";

     std::string Inter_Thread_Class_Descriptions = "\t\t[ INTER-THREAD CLASS DESCRIPTIONS ]";

     std::string Smart_Pointer_Descriptions      = "\t\t[ SMART POINTER DESCRIPTIONS ]";

     std::string Library_Descriptions            = "\t\t[ EXTERNAL LIBRARY DESCRIPTIONS ]";

     std::string Additional_Source_Files         = "\t\t[ SOURCE FILES ]";

     std::string Additional_Header_Files         = "\t\t[ HEADER FILES ]";

     std::string Executable_File_Name            = "\t\t[ EXECUTABLE FILE NAME ]";

     std::string Namespace                       = "\t\t[ NAMESPACE ]";

     std::string OpenMP_Support                  = "\t\t[ OPENMP SUPPORT ]";


     std::cout << "\n";

     std::cout << "\n";

     std::cout << Structural_Descriptions;

     std::cout << "\n\n";

     std::cout << "\n\t\tConstruction Point :";

     std::cout << "\n";

     std::cout << "\n\t\t" << this->Description_Reader.Get_Construction_Point();

     std::cout << "\n\n";

     std::cout << "\n\t\tHeaders Directory :";

     std::cout << "\n";

     std::cout << "\n\t\t"  <<  this->Description_Reader.Get_Constructed_Include_Directory();

     std::cout << "\n\n";

     std::cout << "\n\t\tThe number of the threads :";

     std::cout << "\n";

     std::cout << "\n\t\t"  << this->Description_Reader.Get_Thread_Number();

     std::cout << "\n\n";

     std::cout << "\n\t\tThread Function Names :";

     for(int i=0;i<this->Description_Reader.Get_Thread_Function_Number();i++){

         std::cout << "\n\n\t\t"  << this->Description_Reader.Get_Thread_Function_Names()[i];
     }

     std::cout << "\n\t\t";

     std::cout << "\n\n\t\tExecutable File Name :";

     if(this->Description_Reader.Get_Executable_File_Name() != nullptr){

        std::cout << "\n";

        std::cout << "\n\n\t\t" << this->Description_Reader.Get_Executable_File_Name();

        std::cout << "\n";
     }
     else{

          std::cout << "\n\n\t\tThe name of the executable file name was not entered yet!";
     }

     Class_Data_Type *  Inter_Thread_Classes = this->Description_Reader.Get_Class_Names();

     Shared_Memory_Data_Type  * Inter_Thread_Data_Types = this->Description_Reader.Get_Shared_Data_Types();

     if(Inter_Thread_Classes != nullptr){

        std::cout << "\n\n";

        std::cout << "\n\n";

        std::cout << Inter_Thread_Class_Descriptions;

        for(int i=0;i<Inter_Thread_Classes[0].Total_Class_Number;i++){

            std::cout << "\n\n";

            std::cout << "\n\t\t" << "Class Name : " << Inter_Thread_Classes[i].Class_Name;

            std::cout << "\n";

            std::cout << "\n\t\tHeader File Name : " << Inter_Thread_Classes[i].Header_File_Name;

            std::cout << "\n";

            std::cout << "\n\t\tClass Instance Name : " << Inter_Thread_Classes[i].Class_Instance_Name;

            std::cout << "\n";

            std::cout << "\n\t\tHeader File Location : ";

            int Directory_Size = strlen(Inter_Thread_Classes[i].Header_File_Location);

            int dir_counter = 0;

            for(int k=0;k<Directory_Size;k++){

                if( Inter_Thread_Classes[i].Header_File_Location[k] == '/'){

                    dir_counter++;
                }

                if(dir_counter >= 4){

                     std::cout << " +\n\n\t\t+ ";

                     dir_counter = 0;
                }

                std::cout << Inter_Thread_Classes[i].Header_File_Location[k];
            }
        }
     }

     if(Inter_Thread_Data_Types != nullptr){

        std::cout << "\n\n";

        std::cout << "\n\n";

        std::cout << Smart_Pointer_Descriptions;

        for(int i=0;i< Inter_Thread_Data_Types[0].Total_Data_Type_Number;i++){

            std::cout << "\n\n";

            std::cout << "\n\t\tData Type : " << Inter_Thread_Data_Types[i].Data_Type;

            if(Inter_Thread_Data_Types[i].Header_File_Name == nullptr){

               std::cout << "  -  < Basic C++ Type >";
            }

            std::cout << "\n";

            std::cout << "\n\t\tPointer Name : " << Inter_Thread_Data_Types[i].Pointer_Name;

            if(Inter_Thread_Data_Types[i].Header_File_Name != nullptr){

               std::cout << "\n";

               std::cout << "\n\t\tHeader File Name : " << Inter_Thread_Data_Types[i].Header_File_Name;

               std::cout << "\n";

               std::cout << "\n\t\tHeader File Location : ";

               int dir_counter = 0;

               int Directory_Size = strlen(Inter_Thread_Data_Types[i].Include_Directory);

               for(int k=0;k<Directory_Size;k++){

                   if( Inter_Thread_Data_Types[i].Include_Directory[k] == '/'){

                       dir_counter++;
                   }

                   if(dir_counter >= 4){

                      std::cout << " +\n\n\t\t+ ";

                      dir_counter = 0;
                   }

                   std::cout << Inter_Thread_Data_Types[i].Include_Directory[k];
               }
            }
        }
     }


     if(this->Description_Reader.Get_Library_Names() != nullptr){

        std::cout << "\n\n";

        std::cout << "\n\n";

        std::cout << Library_Descriptions;

        std::cout << "\n\n";

        std::cout << "\n\t\tLibraries :";

        for(int i=0;i<this->Description_Reader.Get_Library_Names_Number();i++){

            std::cout << "\n";

            std::cout << "\n\t\t" << this->Description_Reader.Get_Library_Names()[i];
         }
     }

     char ** Header_File_Names = this->Description_Reader.Get_Header_File_Names();

     char ** Header_File_Locations = this->Description_Reader.Get_Header_File_Paths();

     int Header_File_Numbers = this->Description_Reader.Get_Header_Files_Number();

     if(Header_File_Numbers > 0){

        std::cout << "\n\n";

        std::cout << "\n\n";

        for(int i=0;i<Header_File_Numbers;i++){

            if(!this->Is_This_Header_File_Already_Printed(Header_File_Names[i])){

                std::cout << Additional_Header_Files;

                std::cout << "\n\n";

                std::cout << "\n\t\tHeader File Paths :";

                break;
            }
        }

        for(int i=0;i<Header_File_Numbers;i++){

            if(!this->Is_This_Header_File_Already_Printed(Header_File_Names[i])){

                std::cout << "\n\n\t\t";

                int Directory_Size = strlen(Header_File_Locations[i]);

                int dir_counter = 0;

                for(int k=0;k<Directory_Size;k++){

                    if( Header_File_Locations[i][k] == '/'){

                        dir_counter++;
                    }

                    if(dir_counter >= 5){

                       std::cout << " +\n\n\t\t+ ";

                       dir_counter = 0;
                    }

                    std::cout << Header_File_Locations[i][k];
                }
           }
        }
     }

     int Source_File_Names_Number    = this->Description_Reader.Get_Source_File_Names_Number();

     int Source_File_Location_Number = this->Description_Reader.Get_Source_File_Location_Number();

     if(this->Description_Reader.Get_Source_File_Names() != nullptr){

        std::cout << "\n\n";

        std::cout << "\n\n";

        std::cout << Additional_Source_Files;

        std::cout << "\n";

        std::cout << "\n\n\t\tSource File Paths :";

        for(int i=0; i<Source_File_Names_Number; i++){

            std::cout << "\n\n\t\t";

            int Directory_Size = strlen(this->Description_Reader.Get_Source_File_Names()[i]);

            int dir_counter = 0;

            for(int k=0;k<Directory_Size;k++){

                if( this->Description_Reader.Get_Source_File_Names()[i][k] == '/'){

                    dir_counter++;
                }

                if(dir_counter >= 5){

                   std::cout << " +\n\n\t\t+ ";

                   dir_counter = 0;
                }

                std::cout << this->Description_Reader.Get_Source_File_Names()[i][k];
            }

        }
     }

     std::cout << "\n\n";

     std::cout << Namespace;

     std::cout << "\n\n\t\t Namespace of the library: " << this->Description_Reader.Get_Namespace();

     std::cout << "\n\n";

     std::cout << "\n\n";

     std::cout << OpenMP_Support;

     std::cout << "\n\n\t\t OpenMP Selection: " << this->Description_Reader.Get_OpenMP_Support_Condition();

     std::cout << "\n\n";

     std::cout << "\n\t\t[ THE END OF THE DESCRIPTIONS ]";

     std::cout << "\n\n";
}

bool Description_Printer::Is_This_Header_File_Already_Printed(char * Header_File_Name){

     this->Is_This_Already_Printed = false;

     Class_Data_Type *  Inter_Thread_Classes = this->Description_Reader.Get_Class_Names();

     Shared_Memory_Data_Type  * Inter_Thread_Data_Types = this->Description_Reader.Get_Shared_Data_Types();

     if(this->Description_Reader.Get_Class_Names() != nullptr){

        for(int i=0;i<Inter_Thread_Classes[0].Total_Class_Number;i++){

            char * ITC_Header_File_Name = Inter_Thread_Classes[i].Header_File_Name;

            bool is_header_name_equal = this->CharacterOperations.CompareString(ITC_Header_File_Name,Header_File_Name);

            if(is_header_name_equal){

               this->Is_This_Already_Printed = true;

               return this->Is_This_Already_Printed;
            }
        }
     }

     if(this->Description_Reader.Get_Shared_Data_Types() != nullptr){

        for(int i=0;i< Inter_Thread_Data_Types[0].Total_Data_Type_Number;i++){

            char * ITD_Header_File_Name = Inter_Thread_Data_Types[i].Header_File_Name;

            bool is_header_name_equal = false;

            if(Inter_Thread_Data_Types[i].Header_File_Name != nullptr){

               is_header_name_equal = this->CharacterOperations.CompareString(ITD_Header_File_Name,Header_File_Name);
            }

            if(is_header_name_equal){

               this->Is_This_Already_Printed = true;

               return this->Is_This_Already_Printed;
            }
        }
     }

     return this->Is_This_Already_Printed;
}
