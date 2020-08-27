
#include "Loop_Interval.h"

Loop_Interval::Loop_Interval()
{
   this->loop_interval = 0;
};

Loop_Interval::~Loop_Interval()
{

};

void Loop_Interval::set_loop_interval(int interval)
{
    this->loop_interval = interval;
}

int Loop_Interval::get_loop_interval()
{
      return this->loop_interval;
}
