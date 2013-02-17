/* 
 * File:   StopWatch.h
 * Author: mmh
 *
 * Created on February 16, 2013, 3:06 PM
 */

#ifndef STOPWATCH_H
#define	STOPWATCH_H


#include <boost/timer/timer.hpp>
using boost::timer::cpu_timer;
using boost::timer::cpu_times;

class StopWatch {
public:
  StopWatch() {
    timer.start();
  };

  
  void start() {
    timer.start();
  }
  
  ulong elapsed_time() {
    return (ulong)timer.elapsed().wall / 1.0e9;
  }

private:
  cpu_timer timer;

};

#endif	/* STOPWATCH_H */

