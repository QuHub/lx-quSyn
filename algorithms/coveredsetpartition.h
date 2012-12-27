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
	enum {
		ParitionSize	
	};
public:
	CoveredSetPartition();
	CoveredSetPartition(const CoveredSetPartition& other);
	void synthesize();
	virtual ~CoveredSetPartition();
	virtual CoveredSetPartition& operator=(const CoveredSetPartition& other);
	static void initialize(Function *pfunction, int number_of_partitions);
	int& operator[] (int key) {
		return m_parameters[key];
	}
	static void add_cli_options();
private:
  void copy_terms_in_function(unsigned long *p);
	static int m_sets;
	static int m_max_terms;
  static Function *m_function;
	static map<int,int> m_parameters;
  static Hasse m_hasse;
};

#ifdef DEFINE_STATICS
	int CoveredSetPartition::m_sets;
	int CoveredSetPartition::m_max_terms;
	map<int,int> CoveredSetPartition::m_parameters;
  Function *CoveredSetPartition::m_function;
  Hasse CoveredSetPartition::m_hasse;
#endif
#endif // COVEREDSETPARTITION_H
