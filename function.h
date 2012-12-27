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

#include "option.h"

#ifndef FUNCTION_H
#define FUNCTION_H

class Function
{
public:
  string m_fileName;
  string m_functionName;
  int m_nBits;
  int m_nRadix;
  int m_nTerms;
  unsigned long *m_pIn;
  unsigned long *m_pOut;
  
Function();
void load_file(string pfilename);
Function(const Function& other);
virtual ~Function();
virtual Function& operator=(const Function& other);
int bits() {return m_nBits;}
int radix() {return m_nRadix;}
int terms() {return m_nTerms;}
unsigned long *inputs() {return m_pIn;}
unsigned long *outputs() {return m_pOut;}
};

#endif // FUNCTION_H
