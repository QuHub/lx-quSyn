/* 
 * File:   Synthesizer.cpp
 * Author: mmh
 * 
 * Created on December 24, 2012, 6:27 PM
 */

#include "Synthesizer.h"

Queue Synthesizer::m_queue;

Synthesizer::Synthesizer() {
	Lock();
}

Synthesizer::Synthesizer(const Synthesizer& orig) {
}

Synthesizer::~Synthesizer() {
}

void Synthesizer::Execute(void *pArg)
{
	while(true) {
		Algorithm *algo = m_queue.Pop();
		if (!algo) {
			/* Queue is empty, give Conductor#WaitForQueue the chance to
			 * find out that work is done.
			 * Re Lock() in order to check for more work in the queue
			 */
			Release();
			sleep(1);
			Lock();
			continue;
		}
	}
}