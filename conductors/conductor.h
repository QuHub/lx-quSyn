/* 
 * File:   conductor.h
 * Author: mmh
 *
 * Created on December 24, 2012, 12:39 PM
 */
#include "Mutex.h"

#ifndef CONDUCTOR_H
#define	CONDUCTOR_H

class Conductor {
public:
  int m_nThreads;
  Mutex *m_hMutex;
    
public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();
private:

};

#endif	/* CONDUCTOR_H */

