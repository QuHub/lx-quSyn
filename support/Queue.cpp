/*
 * File:   Queue.cpp
 * Author: mmh
 *
 * Created on December 24, 2012, 6:13 PM
 */

#include "../common.h"
#include "Queue.h"

Queue::Queue() {
}

Queue::Queue(const Queue& orig) {
}

Queue::~Queue() {
	Release();
}

void Queue::Push(Algorithm *qa) {
	Lock();
	m_queue.push(qa);
	Release();
}

Algorithm *Queue::Pop()
{
	m_Mutex.Lock();
	if (Empty()) {
		Release();
		return NULL;
	}
	Algorithm *qa = m_queue.front();
	m_queue.pop();
	Release();
	return qa;
}

