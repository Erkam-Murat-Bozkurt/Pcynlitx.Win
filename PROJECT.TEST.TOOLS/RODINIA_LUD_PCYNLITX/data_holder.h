
#ifndef DATA_HOLDER_H
#define DATA_HOLDER_H

class data_holder
{
public:
  data_holder();
  virtual ~data_holder();
  void receive_total_thread_number(int number);
  int get_chunks_per_inter();
  int get_chunks_in_inter_row();
  int get_offset();
  float * get_Matrix(int threadNumber);
  float * get_duplicated_matrix();
  int  get_Matrix_Size();
  void set_Matrix_Size(int size);
  void set_chunks_per_inter(int arg);
  void set_chunks_in_inter_row(int arg);
  void set_offset(int arg);
  void set_Thread_Matrix(int Thread_Number,float * m);
  void set_duplicated_matrix(float * m);
private:
  int size;
  int chunks_per_inter;
  int chunks_in_inter_row;
  int offset;
  int matrix_size;
  float ** matrix_list;
  float * duplicated_matrix;
};






#endif /* DATA_HOLDER_H */
