/* 
 * File:   Queue.h
 * Author: mmh
 *
 * Created on December 24, 2012, 6:13 PM
 */

#include <queue>
#include "Algorithm.h"
#include "Mutex.h"

using namespace std;
#ifndef QUEUE_H
#define	QUEUE_H

class Queue {
public:
  Queue();
  Queue(const Queue& orig);
  virtual ~Queue();
	void Push(Algorithm *qa);
	Algorithm *Pop();
	bool Empty(){return m_queue.size() <= 0;}
private:
	Mutex m_Mutex;
	queue<Algorithm*> m_queue;
	inline void Lock() {m_Mutex.Lock();}
	inline void Release() {m_Mutex.Release();}
};

#endif	/* QUEUE_H */

