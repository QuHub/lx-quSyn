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
    m_Synthesizers[i].Start(NULL);
}

Conductor::Conductor(const Conductor& orig) {
}

Conductor::~Conductor() {

  delete []m_Synthesizers;
}

void Conductor::WaitForQueue() {
  Lock();
	sleep(1);
	// If you can lock all of them, then they are finished
	for(int i=0; i<m_nThreads; i++)	
		m_Synthesizers[i].Lock();

	// Now release them for future processing
	for(int i=0; i<m_nThreads; i++)	
		m_Synthesizers[i].Release();

  Release();
}

