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
  ulong *m_pIn;
  ulong *m_pOut;
  int has_input(ulong term);
  void dump();

  Function();
  ulong decimal(string str);
  void load_file(string pfilename);
  virtual ~Function();
  int bits(int bits=0) {if(bits > 0) m_nBits = bits;    return m_nBits;}
  int radix(int radix=0) {if(radix>0) m_nRadix = radix; return m_nRadix;}
  int terms() {return m_nTerms;}
  ulong *inputs() {return m_pIn;}
  ulong *outputs() {return m_pOut;}
};

#endif // FUNCTION_H
