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

#define N_BATCH 1
#define N_RUNS  3

RandomConductor::RandomConductor()
{

}

RandomConductor::RandomConductor(Function &function) : Conductor()
{
  m_function = function;
}

void RandomConductor::synthesize()
{
  long bestCost=numeric_limits<int>::max();

  CoveredSetPartition *pAlgo[N_BATCH];
 
  for (int j=0; j<N_RUNS; j++) {
    cout << "Run: " << j << "\n";

    for (int i=0; i<N_BATCH; i++) { 
      pAlgo[i] = new CoveredSetPartition();
      pAlgo[i]->synthesize();
    }

    for (int i=0; i<N_BATCH; i++) { 
      long qCost; // = m_pAlgo[i]->m_QuantumCost;
      if (bestCost > qCost) {
        bestCost = qCost;
 //       SaveResult(m_pAlgo[i]);
      }
      delete pAlgo[i];
    }
		WaitForQueue();
  }
 // PrintResult(0);
}

RandomConductor::~RandomConductor()
{

}

