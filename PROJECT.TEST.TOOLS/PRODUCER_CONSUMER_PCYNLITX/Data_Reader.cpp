
#include "Data_Reader.h"

Data_Reader::Data_Reader(){

     this->File_Lenght = 0;

     this->Read_Data_Pointer = nullptr;

     this->Memory_Delete_Condition = false;

     this->acess_order_violation = false;

     this->acess_order_list_increment = 0;

     this->acess_order_data_list  = nullptr;

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

         if(this->acess_order_data_list != nullptr){

            for(int i=0;i<this->File_Lenght;i++){

                delete [] this->acess_order_data_list[i].acess_data_holder;

                delete [] this->acess_order_data_list[i].empty_status;
            }

            delete [] this->acess_order_data_list;
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

     this->Initialize_Acess_Order_Holders();

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

     this->Read_Data_Pointer = new Read_Data [3*this->File_Lenght];

     for(int i=0;i<2*this->File_Lenght;i++){

         std::string string_line = this->FileManager.ReadLine();

         int string_size = string_line.length();

         this->Read_Data_Pointer[i].number_string = new char [2*string_size];

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


void Data_Reader::Initialize_Acess_Order_Holders(){

     this->acess_order_data_list  = new readers_acess_order_data [2*this->File_Lenght];

     for(int i=0;i<this->File_Lenght;i++){

         this->acess_order_data_list[i].acess_data_holder = new int [2*this->reader_thread_number];

         this->acess_order_data_list[i].empty_status = new bool [2*this->reader_thread_number];

         for(int k=0;k<this->reader_thread_number;k++){

            this->acess_order_data_list[i].acess_data_holder[k] = -1;

            this->acess_order_data_list[i].empty_status[k] = true;
         }
     }
}

void Data_Reader::Set_Acess_Order(int thread_number)
{
     int Record_Index = this->thread_record_increment; // Record index for thread numbers

     int Data_List_Index = this->acess_order_list_increment; // Record index for data structures

     if(this->acess_order_data_list[Data_List_Index].empty_status[Record_Index]){

        this->acess_order_data_list[Data_List_Index].acess_data_holder[Record_Index] = thread_number;

        this->acess_order_data_list[Data_List_Index].empty_status[Record_Index] = false;
     }

     this->thread_record_increment++;

     if(this->thread_record_increment >= this->reader_thread_number){

        this->acess_order_list_increment++;

        this->thread_record_increment = 0;
     }
}

void Data_Reader::Print_Acess_Order()
{
     this->FileManager.SetFilePath("Readers_Acess_Orders");

     this->FileManager.FileOpen(RWCf);

     for(int i=0;i<this->File_Lenght;i++){

        this->FileManager.WriteToFile("\n ");

        for(int k=0;k<this->reader_thread_number;k++){

           if(!(this->acess_order_data_list[i].empty_status[k])){

               int order = this->acess_order_data_list[i].acess_data_holder[k];

               char * value = this->Translater.Translate(order);

               this->FileManager.WriteToFile("\n ");

               this->FileManager.WriteToFile(value);

               this->FileManager.WriteToFile(" ");
           }
        }
     }

    this->FileManager.FileClose( );
}


bool Data_Reader::Check_Readers_Acess_Order_Violation()
{
     this->acess_order_violation = false;

     for(int i=0;i<this->File_Lenght;i++){

         int remaining_operation = this->File_Lenght - i;

         for(int k=0;k<this->reader_thread_number;k++){

             if(k>remaining_operation){

                  break;
             }

             if(!(this->acess_order_data_list[i].empty_status[k])){

                  int order = this->acess_order_data_list[i].acess_data_holder[k];

                  if(order != k){

                     this->acess_order_violation = true;

                     return this->acess_order_violation;
                  }
             }
         }
     }

     return this->acess_order_violation;
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
