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

void Synthesizer::Start()
{

}

void Synthesizer::Execute(void *pArg)
{
	while(true) {
		Algorithm *algo = m_queue.Pop();
		if (!algo) {
			Release();
			sleep(1);
			Lock();
			continue;
		}

	}
}