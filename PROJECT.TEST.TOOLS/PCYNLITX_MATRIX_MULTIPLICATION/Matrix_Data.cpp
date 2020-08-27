
#include "Matrix_Data.h"

Matrix_Data::Matrix_Data(){

     this->Matrix_Size = 0;
}

Matrix_Data::Matrix_Data(const Matrix_Data & orig){

}

Matrix_Data::~Matrix_Data(){

}

void Matrix_Data::Receive_Matrix_Size(int size){

     this->Matrix_Size = size;
}

int  Matrix_Data::Get_Matrix_Size(){

     return this->Matrix_Size;
}

void Matrix_Data::Print_Random_Matrix(double *** pointer){

     for(int i=0;i<this->Matrix_Size;i++){

         std::cout << "\n";

         for(int k=0;k<this->Matrix_Size;k++){

             std::cout << " " << (*pointer)[i][k];
         }
     }
}
