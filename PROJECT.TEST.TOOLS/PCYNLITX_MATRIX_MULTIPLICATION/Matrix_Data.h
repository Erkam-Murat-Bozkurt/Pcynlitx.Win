
#ifndef MATRIX_DATA_H
#define MATRIX_DATA_H

class Matrix_Data
{
public:
  Matrix_Data();
  Matrix_Data(const Matrix_Data & orig);
  virtual ~Matrix_Data();
  void Receive_Matrix_Size(int matrix_size);
  void Print_Random_Matrix(double *** pointer);
  int  Get_Matrix_Size();
private:
  int Matrix_Size;
};

#endif /* MATRIX_DATA_H */
