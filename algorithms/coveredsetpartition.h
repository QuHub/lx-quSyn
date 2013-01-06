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

#include "../function.h"
#include "Algorithm.h"

#ifndef COVEREDSETPARTITION_H
#define COVEREDSETPARTITION_H

class CoveredSetPartition : public Algorithm
{
public:
	static void initialize(Function *pfunction, int number_of_partitions);
	static void add_cli_options();
  static void release();

  CoveredSetPartition();
	CoveredSetPartition(const CoveredSetPartition& other);
	void synthesize();
	virtual ~CoveredSetPartition();
	virtual CoveredSetPartition& operator=(const CoveredSetPartition& other);

  int num_sets() {return m_sets;}
  int num_max_terms() {return m_max_terms;}
  int num_terms() {return m_function->terms();}
  int num_bits() {return m_function->bits();}
  
  int partition_size() {return m_partition_size;}
  Function* function() {return m_function;}
  void copy_terms_in_function(unsigned long *p);

private:
	static int m_sets;
	static int m_max_terms;
	static int m_partition_size;
  static Function *m_function;
  static Hasse m_hasse;
};

#ifdef DEFINE_STATICS
	int CoveredSetPartition::m_sets;
	int CoveredSetPartition::m_max_terms;
	int CoveredSetPartition::m_partition_size;
  Function *CoveredSetPartition::m_function;
  Hasse CoveredSetPartition::m_hasse;
#endif
#endif // COVEREDSETPARTITION_H
