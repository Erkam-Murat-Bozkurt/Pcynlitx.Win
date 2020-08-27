
#include "Data_Reader.h"

Data_Reader::Data_Reader(){

     this->File_Lenght = 0;

     this->data_list_pointer = nullptr;

     this->Memory_Delete_Condition = true;

     this->Data_Record_Condition = false;

     this->Line_index = 0;

     this->Record_List_Length = 0;

     this->data_records = nullptr;

     this->acess_order_violation = false;

     this->acess_order_list_increment = 0;

     this->acess_order_data_list  = nullptr;

     this->total_thread_number = 0;

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

         for(int i=0;i<this->File_Lenght;i++){

             delete [] this->data_list_pointer[i]->number_string;

             delete this->data_list_pointer[i];
         }

         delete [] this->data_list_pointer;

         if(this->data_records != nullptr){

             delete [] this->data_records;
         }

         if(this->acess_order_data_list != nullptr){

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

void Data_Reader::Receive_Total_Thread_Number(int number){

     this->total_thread_number = number;
}

void Data_Reader::Receive_Data(){

     this->Determine_File_Length();

     this->Allocate_Memory_For_Each_Line();

     this->FileManager.FileOpen(Rf);

     for(int i=0;i<this->File_Lenght;i++){

         std::string string_line = this->FileManager.ReadLine();

         this->Set_Data(string_line,&this->data_list_pointer[i]->number_string);
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

     this->data_list_pointer = new data_list * [5*this->File_Lenght];


     for(int i=0;i<4*this->File_Lenght;i++){

         std::string string_line = this->FileManager.ReadLine();

         int string_size = string_line.length();

         this->data_list_pointer[i] = new data_list;

         this->data_list_pointer[i]->number_string = new char [5*string_size];

         this->data_list_pointer[i]->position = i;

         this->data_list_pointer[i]->read_status = false;

         this->data_list_pointer[i]->record_status = false;
     }

     this->FileManager.FileClose();

     this->data_records = new record_list [5*this->File_Lenght];

     for(int i=0;i<2*this->File_Lenght;i++){

         this->data_records[i].record_number = 0;

         this->data_records[i].thread_number = 0;

         this->data_records[i].reputation = 0;
     }

     this->Initialize_Acess_Order_Holders();
}

void Data_Reader::Set_Data(std::string string_line, char ** pointer){

     int string_size = string_line.length();

     int index_counter = 0;

     for(int i=0;i<string_size;i++){

         (*pointer)[index_counter] = string_line[i];

         index_counter++;
     }

     (*pointer)[index_counter] = '\n';
}


int Data_Reader::Get_Line_Index() const {

    return this->Line_index;
}

void Data_Reader::Print_Data(){

     for(int i=0;i<this->File_Lenght;i++){

         int string_size = strlen(this->data_list_pointer[i]->number_string);

         for(int k=0;k<string_size;k++){

             std::cout << this->data_list_pointer[i]->number_string[k];
         }
     }
}


void Data_Reader::Increase_Line_Index(){

     this->Line_index++;
}

void Data_Reader::Set_Line_Index(int index){

     this->Line_index = index;
}

char * Data_Reader::Get_Data_List_Member_String(int index){

        return this->data_list_pointer[index]->number_string;
}

int Data_Reader::Get_Data_List_Member_Position(int index){

    return this->data_list_pointer[index]->position;
}

bool Data_Reader::Get_Data_List_Member_Read_Status(int index){

     return this->data_list_pointer[index]->read_status;
}

bool Data_Reader::Get_Data_List_Member_Record_Status(int index){

     return this->data_list_pointer[index]->record_status;
}

void Data_Reader::Set_Data_List_Member_Read_Status(int index, bool status){

     this->data_list_pointer[index]->read_status = status;
}

void Data_Reader::Set_Data_List_Member_Record_Status(int index, bool status){

     this->data_list_pointer[index]->record_status = status;
}

int Data_Reader::Get_Data_length() const {

    return this->File_Lenght;
}

void Data_Reader::Set_Record_Data(int index, int thread_number, int reputation){

     this->data_records[index].reputation = reputation;

     this->data_records[index].thread_number = thread_number;

     this->data_records[index].record_number++;

     this->Set_Data_List_Member_Record_Status(index,true);

     this->Increase_Record_List_Length();
}

void Data_Reader::Clear_Record_Data(int index){

     this->data_records[index].reputation = 0;

     this->data_records[index].thread_number = 0;

     this->data_records[index].record_number = 0;

     this->Set_Data_List_Member_Record_Status(index,false);
}

void Data_Reader::Increase_Record_List_Length(){

     this->Record_List_Length++;
}

void Data_Reader::Set_Record_List_Length(int length){

     this->Record_List_Length = length;
}

int Data_Reader::Get_Record_List_Length() {

    return this->Record_List_Length;
}

int  Data_Reader::Get_Reputation(int index) const {

     return this->data_records[index].reputation;
}

int  Data_Reader::Get_Thread_Number(int index) const {

     return this->data_records[index].thread_number;
}

int  Data_Reader::Get_Record_Number(int index) const {

     return this->data_records[index].record_number;
}

void Data_Reader::Initialize_Acess_Order_Holders(){

     this->acess_order_data_list  = new acess_order_data [this->File_Lenght+100];

     for(int i=0;i<this->File_Lenght;i++){

         this->acess_order_data_list[i].acess_data_holder = new int [this->total_thread_number+20];

         this->acess_order_data_list[i].empty_status = new bool [this->total_thread_number+20];

         for(int k=0;k<this->total_thread_number;k++){

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

     if(this->thread_record_increment >= this->total_thread_number){

        this->acess_order_list_increment++;

        this->thread_record_increment = 0;
     }
}

void Data_Reader::Print_Acess_Order()
{
     this->FileManager.SetFilePath("The_Acess_Orders");

     this->FileManager.FileOpen(RWCf);

     for(int i=0;i<this->File_Lenght;i++){

        this->FileManager.WriteToFile("\n ");

        for(int k=0;k<this->total_thread_number;k++){

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

// The member function that check access order of the first group..

bool Data_Reader::Check_Acess_Order_Violation()
{
     this->acess_order_violation = false;

     for(int i=0;i<this->File_Lenght;i++){

         int remaining_operation = this->File_Lenght - i;

         for(int k=0;k<this->total_thread_number;k++){

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
