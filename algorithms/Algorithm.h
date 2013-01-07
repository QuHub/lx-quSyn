/*
 * File:   Algorithm.h
 * Author: mmh
 *
 * Created on December 24, 2012, 6:18 PM
 */

#ifndef ALGORITHM_H
#define	ALGORITHM_H

#include <stdio.h>
using namespace std;

template <class T>
void REL(T* p) {
  if(p != NULL)  delete p;
}

inline ulong* ALLOC(int size) {
  return new ulong[size];
}

class Algorithm {
public:
  Algorithm() {
    m_pin = m_pout = m_pcontrol = m_ptarget = NULL;
  }
  virtual ~Algorithm() {
    REL(m_pcontrol), REL(m_ptarget);
  }
  ulong* inputs(){return m_pin;}
  ulong* outputs(){return m_pout;}
  virtual int num_terms() {throw "subclass responsibility";}
  virtual int num_bits() {throw "subclass responsibility";}
  long cost(long cost=-1) {if(cost>0) m_cost = cost; return m_cost;}
  long num_gates(long gates=-1) {if(gates>0) m_num_gates = gates; return m_num_gates;}
  ulong* target() { return (m_ptarget  = ALLOC(MAX_NUM_GATES));  }
  ulong* control() {return (m_pcontrol = ALLOC(MAX_NUM_GATES)); }

protected:
  long m_cost;
	long m_num_gates;
  ulong *m_pin;
	ulong *m_pout;
  ulong *m_ptarget;
  ulong *m_pcontrol;

};

#endif	/* ALGORITHM_H */

