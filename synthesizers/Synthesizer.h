/*
 * File:   Synthesizer.h
 * Author: mmh
 *
 * Created on December 24, 2012, 6:27 PM
 */

#include "Thread.h"
#include "Mutex.h"
#include "Queue.h"
#include <algorithm>

#ifndef SYNTHESIZER_H
#define	SYNTHESIZER_H

class Synthesizer : public Thread {
public:
  Synthesizer();
  virtual ~Synthesizer();
	void Execute(void*);
	inline int Lock(int flag=0) {return m_Mutex.Lock(flag);}
	inline void Release() {m_Mutex.Release();}
	static inline void Add(Algorithm*p) {m_queue.Push(p);}
private:

	Mutex m_Mutex;
  static Queue m_queue;
  long m_num_gates;
  int m_num_bits;
  unsigned long* m_ptarget;
  unsigned long* m_pcontrol;

  void process(Algorithm *algo);
  void process(unsigned long, unsigned long);
  long cost();
  long control_lines(ulong long n);

  void check_buffer_size() {
    if(m_num_gates > MAX_NUM_GATES)
      throw "Buffer exceeded capacity";
  }
  unsigned long propogate(unsigned long term);
  inline long gate_cost(int i) {
    return max(1, (int)pow(2.0, 1+i) - 3);
  }

};

#endif	/* SYNTHESIZER_H */

