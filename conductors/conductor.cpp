/* 
 * File:   conductor.cpp
 * Author: mmh
 * 
 * Created on December 24, 2012, 12:39 PM
 */

#include "conductor.h"
#include <unistd.h>
Conductor::Conductor() {
  m_nThreads = sysconf( _SC_NPROCESSORS_ONLN );
  m_hMutex = new Mutex[m_nThreads]; 
}

Conductor::Conductor(const Conductor& orig) {
}

Conductor::~Conductor() {
//  for(int i=0; i<m_nThreads; i++)


  delete []m_hMutex;
}

