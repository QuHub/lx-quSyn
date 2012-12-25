/* 
 * File:   Mutex.h
 * Author: mmh
 *
 * Created on December 24, 2012, 1:21 PM
 */

#include "common.h"

#ifndef MUTEX_H
#define	MUTEX_H
#define NO_WAIT 1

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

	int Lock(int flag=0) {
		if(flag == NO_WAIT)
      return pthread_mutex_trylock(&m_lock);
    else
			pthread_mutex_lock(&m_lock);
    return 0;
	}

	void Release() {
		pthread_mutex_unlock(&m_lock);
	}
private:
	pthread_mutex_t m_lock;

};

#endif	/* MUTEX_H */

