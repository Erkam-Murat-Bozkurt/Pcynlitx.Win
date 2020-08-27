
#include "Data_Reader.h"

Data_Reader::Data_Reader(){

     this->File_Lenght = 0;

     this->Read_Data_Pointer = nullptr;

     this->Memory_Delete_Condition = false;

     this->reader_thread_number = 0;

     this->thread_record_increment = 0;
}

Data_Reader::~Data_Reader(){

      if(!this->Memory_Delete_Condition){

          this->Clear_Dynamic_Memory();
      }
}

void Data_Reader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         if(this->Read_Data_Pointer != nullptr){

            for(int i=0;i<this->File_Lenght;i++){

                delete [] this->Read_Data_Pointer[i].number_string;
            }

            delete [] this->Read_Data_Pointer;
         }
     }
}

void Data_Reader::SetFilePath(std::string FilePATH){

     this->FileManager.SetFilePath(FilePATH);
}

void Data_Reader::SetFilePath(char * FilePATH){

     this->FileManager.SetFilePath(FilePATH);
}

void Data_Reader::SetFilePath(const char * FilePATH){

     this->FileManager.SetFilePath(FilePATH);
}

void Data_Reader::Receive_Reader_Thread_Number(int number){

     this->reader_thread_number = number;
}

void Data_Reader::Receive_Data(){

     this->Determine_File_Length();

     this->Allocate_Memory_For_Each_Line();

     this->FileManager.FileOpen(Rf);

     for(int i=0;i<this->File_Lenght;i++){

         std::string string_line = this->FileManager.ReadLine();

         this->Set_Data(string_line,i);
     }

     this->FileManager.FileClose();
}

void Data_Reader::Determine_File_Length(){

     this->FileManager.FileOpen(Rf);

     while(!this->FileManager.Control_End_of_File()){

           std::string string_line = this->FileManager.ReadLine();

           this->File_Lenght++;
     }

     this->FileManager.FileClose();
}

void Data_Reader::Allocate_Memory_For_Each_Line(){

     this->FileManager.FileOpen(Rf);

     this->Memory_Delete_Condition = false;

     this->Read_Data_Pointer = new Read_Data [5*this->File_Lenght];

     for(int i=0;i<2*this->File_Lenght;i++){

         std::string string_line = this->FileManager.ReadLine();

         int string_size = string_line.length();

         this->Read_Data_Pointer[i].number_string = new char [5*string_size];

         this->Read_Data_Pointer[i].position = i;

         this->Read_Data_Pointer[i].read_status = false;

         this->Read_Data_Pointer[i].record_status = false;
     }

     this->FileManager.FileClose();
}

void Data_Reader::Set_Data(std::string string_line, int i){

     int string_size = string_line.length();

     int index_counter = 0;

     for(int k=0;k<string_size;k++){

         this->Read_Data_Pointer[i].number_string[index_counter] = string_line[k];

         index_counter++;
     }

     this->Read_Data_Pointer[i].number_string[index_counter] = '\0';
}

char * Data_Reader::Get_String_Data(int index){

     return this->Read_Data_Pointer[index].number_string;
}

int Data_Reader::Get_Data_Position(int index){

    return this->Read_Data_Pointer[index].position;
}

bool Data_Reader::Get_Data_Read_Status(int index){

     return this->Read_Data_Pointer[index].read_status;
}

bool Data_Reader::Get_Data_Record_Status(int index){

     return this->Read_Data_Pointer[index].record_status;
}

void Data_Reader::Set_Data_Read_Status(int index, bool status){

     this->Read_Data_Pointer[index].read_status = status;
}

void Data_Reader::Set_Thread_Data_Record_Status(int index, bool status){

     this->Read_Data_Pointer[index].record_status = status;
}

int Data_Reader::Get_Data_Size() const {

    return this->File_Lenght;
}
