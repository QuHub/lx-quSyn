/* 
 * File:   Mutex.h
 * Author: mmh
 *
 * Created on December 24, 2012, 1:21 PM
 */

#include "common.h"

#ifndef MUTEX_H
#define	MUTEX_H

class Mutex {
public:
  Mutex() {
   if (pthread_mutex_init(&m_lock, NULL) != 0) {
        cout << "\n Mutex init failed\n";
        return;
    }
	}
 ~Mutex(){
		cout << "destroying mutex\n";
		pthread_mutex_destroy(&m_lock);
	};

	void Lock() {
		pthread_mutex_lock(&m_lock);
	}

	void Release() {
		pthread_mutex_unlock(&m_lock);
	}
private:
	pthread_mutex_t m_lock;

};

#endif	/* MUTEX_H */

