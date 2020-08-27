
#ifndef LOOP_INTERVAL_H
#define LOOP_INTERVAL_H

class Loop_Interval
{
public:
  Loop_Interval();
  virtual ~Loop_Interval();
  void set_loop_interval(int interval);
  int get_loop_interval();
  int loop_interval;
};

#endif /* LOOP_INTERVALS_H */
