/*
 * File:   conductor.h
 * Author: mmh
 *
 * Created on December 24, 2012, 12:39 PM
 */
#include "Mutex.h"
#include "Synthesizer.h"

#ifndef CONDUCTOR_H
#define	CONDUCTOR_H

class Conductor {
public:
  int m_nThreads;
  Synthesizer *m_Synthesizers;

public:
	Conductor();
	Conductor(const Conductor& orig);
	virtual ~Conductor();
	void WaitForQueue();

protected:
  long m_best_cost;
  long m_best_lnnqc;

};

#endif	/* CONDUCTOR_H */

