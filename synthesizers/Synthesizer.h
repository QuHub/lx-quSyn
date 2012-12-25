/* 
 * File:   Synthesizer.h
 * Author: mmh
 *
 * Created on December 24, 2012, 6:27 PM
 */

#include "Thread.h"
#include "Mutex.h"
#include "Queue.h"

#ifndef SYNTHESIZER_H
#define	SYNTHESIZER_H

class Synthesizer : public Thread {
public:
  Synthesizer();
  Synthesizer(const Synthesizer& orig);
  virtual ~Synthesizer();
	void Execute(void*);
	inline int Lock(int flag=0) {return m_Mutex.Lock(flag);}
	inline void Release() {m_Mutex.Release();}
private:
	Mutex m_Mutex;
  static Queue m_queue;

};

#endif	/* SYNTHESIZER_H */

