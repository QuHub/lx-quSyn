/*
    Copyright 2012 <copyright holder> <email>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "../common.h"
#include "Synthesizer.h"
#include "coveredsetpartition.h"

void dump(unsigned long *p, int length)
{
  cout << "\nbegin memory dump: ******* at: " << p << "\n";
  for(int i=0; i<length; i++) 
    cout << p[i] << " ";

  cout << "end memory dump: ******* at: " << p << "\n";
}

CoveredSetPartition::CoveredSetPartition()
{
	m_pin = new unsigned long[m_function->m_nTerms];
	m_pout = new unsigned long[m_function->m_nTerms];
	
	// Build input vector with m_sets of bands and each band has a Hasse structure
	//
	unsigned long *buf = new unsigned long[m_max_terms];
	unsigned long *p= buf;
	for (int i=0; i<m_sets; i++) {
    p += m_hasse.get(p, i<<(m_function->m_nBits - CoveredSetPartition::partition_size()));											
	}

  //copy_terms_in_function(buf);
  delete buf;
}

void CoveredSetPartition::copy_terms_in_function(unsigned long *p)
{
  unsigned long *mapping = new unsigned long[m_max_terms];
  for(int i=0; i<m_max_terms; i++) 
    mapping[p[i]] = i;

  for (int i=0; i<m_function->m_nTerms; i++) {
    m_pin[i] = mapping[m_function->m_pIn[i]];
    m_pout[i] = m_function->m_pOut[i];
  }
  
  delete mapping;
}
void CoveredSetPartition::synthesize()
{
	Synthesizer::Add(this);
}


void CoveredSetPartition::initialize(Function *pfunction, int partition_size)
{
  m_function = pfunction;
	m_partition_size = partition_size;
	m_sets = pow(2, m_partition_size);
  m_max_terms = pow(2, pfunction->m_nBits);
  m_hasse.initialize(pfunction->m_nBits - m_partition_size);
}

CoveredSetPartition::CoveredSetPartition(const CoveredSetPartition& other)
{

}

CoveredSetPartition::~CoveredSetPartition()
{
	delete m_pin;
	delete m_pout;
}

void CoveredSetPartition::add_cli_options()
{
	po::options_description desc = Option::Register("Covered Set Partition");
	desc.add_options()
		("partition_size", po::value<int>(), "Set partition size")
	;
}

CoveredSetPartition& CoveredSetPartition::operator=(const CoveredSetPartition& other)
{
	return *this;
}

