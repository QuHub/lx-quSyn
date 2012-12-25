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
  m_Synthesizers = new Synthesizer[m_nThreads];

  for(int i=0; i<m_nThreads; i++)
    m_Synthesizers[i].Start();
}

Conductor::Conductor(const Conductor& orig) {
}

Conductor::~Conductor() {

  delete []m_Synthesizers;
}

void Conductor::WaitForQueue() {
  Lock();
  bool fDone = false;
  while(!fDone) {
    sleep(1);
    for(int i=0; i<m_nThreads; i++)	
      m_Synthesizers->Lock();
  }
  Release();
}

