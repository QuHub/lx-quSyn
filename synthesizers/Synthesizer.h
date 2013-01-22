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
protected:

	Mutex m_Mutex;
  static Queue m_queue;
  long m_num_gates;
  int m_num_bits;
  ulong* m_ptarget;
  ulong* m_pcontrol;

  void process(Algorithm *algo);
  void process(ulong, ulong);
  long cost();
  long lnnqc();
  long cost_of_swap_gates(int num_bits) {
    if(num_bits < 4) return 0;

    long last_stage = 2;
    long cost = 2;
    for(int k=3; k <= num_bits - 2; k++) {
      last_stage = 2 * last_stage + 2*(k-1);
      cost += last_stage;
    }

    return 2*cost;
  }
  long lnnqc_mct(int num_bits) {
    long cost_of_cv_gates = std::pow(2.0, num_bits - 1) -1;    // Equation 1
    long cost_of_cnot_gates = std::pow(2.0, num_bits - 1) -2;  // Equation 2

    long cost_of_reflection_gates = 0;
    for (int k=2; k<= num_bits - 2; k++)
      cost_of_reflection_gates += k*k - 1;
    cost_of_reflection_gates *= 2;

    long cost_of_cnots_for_cv_gate = 4*(num_bits -2);
    long cost_of_swaps = cost_of_swap_gates(num_bits);

    return (4*(num_bits - 2) + cost_of_cv_gates + cost_of_cnot_gates
            + cost_of_swap_gates(num_bits) + cost_of_reflection_gates);
  }
  long control_lines(ulong n);

  void check_buffer_size() {
    if(m_num_gates > MAX_NUM_GATES)
      throw "Buffer exceeded capacity";
  }
  ulong propogate(ulong term);
  inline long gate_cost(int i) {
    return max(1, (int)pow(2.0, 1+i) - 3);
  }

};

#endif	/* SYNTHESIZER_H */

