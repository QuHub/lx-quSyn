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


#include <limits>
#include "coveredsetpartition.h"
#include "randomconductor.h"

#define N_BATCH 64
#define N_RUNS  16000

#include <iostream>
#include <fstream>

using namespace std;
RandomConductor::RandomConductor()
{

}

RandomConductor::RandomConductor(Function *function) : Conductor()
{
  m_function = function;
}

void RandomConductor::synthesize()
{
  m_best_lnnqc = numeric_limits<long>::max();
  m_best_cost = numeric_limits<long>::max();

  CoveredSetPartition *pAlgo[N_BATCH];
  long j;
  m_timer.start();
  
  for (j=0; j<N_RUNS; j++) {
    cout << "Run: " << j << "\r" <<  std::flush;

    for (int i=0; i<N_BATCH; i++) {
      pAlgo[i] = new CoveredSetPartition();
      pAlgo[i]->synthesize();
      //pAlgo[i]->inspect();

    }

   WaitForQueue();

    for (long i=0; i<N_BATCH; i++) {
      save_best_cost(pAlgo[i]);
      
      delete pAlgo[i];
    }
  }

  cout << "Waiting for queue\n";
	WaitForQueue();
  
  print_results();
}

void RandomConductor::print_results()
{
  ofstream results("result.txt",  ios_base::app);
  results << m_function->m_nBits << ", ";
  results << m_function->m_functionName << ", ";
  results << m_best_cost << ", ";
  results << m_best_lnnqc << ",";
  results << m_timer.elapsed_time() << ",";
  results << Option::Get("partition-size", 0) << ",";
  results << std::endl;
  results.close();
}

void RandomConductor::save_best_cost(Algorithm *algo) 
{
  bool changed = false;
  if (m_best_cost > algo->cost()) 
    m_best_cost = algo->cost(), changed = true;
  
  if (m_best_lnnqc > algo->lnnqc()) 
    m_best_lnnqc = algo->lnnqc(), changed = true;

  if (changed) {
    cout << "QCost: " << m_best_cost << " LNNQC: " << m_best_lnnqc << std::endl;
    ofstream circuit(m_function->m_functionName + ".circuit", ios_base::out);
    for(int i=0; i < algo->num_gates(); i++) {
      circuit << algo->control()[i] << "," << algo->target()[i] << endl;
    }
  }
  
}
RandomConductor::~RandomConductor()
{

}

