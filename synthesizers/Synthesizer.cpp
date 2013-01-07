/*
 * File:   Synthesizer.cpp
 * Author: mmh
 *
 * Created on December 24, 2012, 6:27 PM
 */

#include "Synthesizer.h"
#include <string.h>


Queue Synthesizer::m_queue;
Mutex m_print;

Synthesizer::Synthesizer() {
}

Synthesizer::~Synthesizer() {
}

#define BUF_SIZE 10*1024

void Synthesizer::Execute(void *pArg)
{
  Lock();
	while(true) {
		Algorithm *algo = m_queue.Pop();
		if (!algo) {
			/* Queue is empty, give Conductor#WaitForQueue the chance to
			 * find out that work is done.
			 * Re Lock() in order to check for more work in the queue
			 */
			Release();
			sleep(0.01);
			Lock();
			continue;
  	}

    process(algo);

	}
}

void Synthesizer::process(Algorithm *algo) {
  m_ptarget = algo->target();
  m_pcontrol = algo->control();

  m_num_gates = 0;
  m_num_bits = algo->num_bits();

  ulong *pin = algo->inputs();
  ulong *pout = algo->outputs();

  for (int i=0; i < algo->num_terms(); i++)
    process(*pin++, *pout++);

  algo->cost(cost());
  algo->num_gates(m_num_gates);
}

void Synthesizer::process(ulong in_term, ulong out_term) {
  		out_term = propogate(out_term);

		// Do we still have a difference?
		// TODO: redo this thing with hash tables
		ulong diff = in_term ^ out_term;

		if (diff > 0) {
			// Flip the 0 bits first
			ulong mask = 1;
			for (int j = 0; j< m_num_bits; j++) {
				if ( (diff & mask) && !(out_term & mask)) {
					check_buffer_size();

					m_pcontrol[m_num_gates] = out_term & ~mask;		// clear in_term bit at current bit position
					m_ptarget[m_num_gates++] = mask;						  // Mark bit position for as NOT gate
					diff &= ~mask;								            // reset bit in diff, since it should be same in out_term
					out_term ^= mask;
				}
				mask <<= 1;
			}

			mask = 1;
			// Flip the 1 bits second
			for (int j = 0; j< m_num_bits; j++) {
				if ( (diff & mask) && (out_term & mask)) {
          check_buffer_size();

										m_pcontrol[m_num_gates] = out_term & ~mask;		// clear in_term bit at current bit position
					m_ptarget[m_num_gates++] = mask;						// Mark bit position for as NOT gate
					diff &= ~mask;								// reset bit in diff, since it should be same in out_term
					out_term ^= mask;
				}
				mask <<= 1;
			}
		}
}

ulong Synthesizer::propogate(ulong term) {
  ulong x;
  for (ulong i=0; i<m_num_gates; i++) {
    x = term & m_pcontrol[i];
    if (x == m_pcontrol[i])
      term ^= m_ptarget[i];
  }
  return term;
}

long Synthesizer::cost() {
  ulong * pncount = new ulong[m_num_bits];
  memset(pncount, 0, m_num_bits * sizeof(ulong));
  for (int i=0; i<m_num_gates; i++)
    pncount[control_lines(m_pcontrol[i])]++;

  long ncost=0;
  for (int i=0; i<m_num_bits; i++)
    ncost += gate_cost(i) * pncount[i];

  delete pncount;
	return ncost;
}

long Synthesizer::control_lines(ulong  n) {
  ulong count=0;

  for (int i=0; i<8; i++) {
    count += Helper::number_of_ones(n & 0xFF);
    n >>= 8;
  }
  return count;
}