
#ifndef DATA_HOLDER_H
#define DATA_HOLDER_H

class data_holder
{
public:
  data_holder();
  virtual ~data_holder();
  void receive_total_thread_number(int total_thread_number);
  void receive_tid(int thread_number,int tid);
  void receive_framenum(int thread_number,int framenum);
  int get_tid(int thread_number) const;
  int get_framenum(int thread_number) const;
private:
  int total_thread_number;
  int ** data_pointer;
};

#endif /* DATA_HOLDER_H */
