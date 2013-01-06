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

#define BOOST_FILESYSTEM_NO_DEPRECATED
#define BOOST_SYSTEM_NO_DEPRECATED
#include "function.h"
#include <iostream>
#include <yaml-cpp/yaml.h>
#include "boost/filesystem.hpp"
#include <boost/algorithm/string.hpp>

namespace bf = boost::filesystem;
using namespace std;
using namespace boost;

Function::Function() {
  m_pIn = NULL;
  m_pOut = NULL;
}


Function::~Function() {
  if(m_pIn) delete m_pIn;
  if(m_pOut) delete m_pOut;
}

int Function::has_input(unsigned long term) {
  for(int i=0; i<m_nTerms; i++)
    if(m_pIn[i] == term) return i;

    return -1;
}

void Function::load_file(string pfilename) {
  bf::path p(".");
  bf::path pa = bf::current_path();

  //  YAML::Node config = YAML::LoadFile(Option::m_fileName);
  YAML::Node config = YAML::LoadFile(pfilename);
  YAML::Node temp = config["signature"];
  m_functionName = temp["function"].as<string > ();
  m_fileName = pfilename;
  m_nBits = config["inputs"]["variables"].as<int>();
  m_nRadix = config["inputs"]["radix"].as<int>();
  string specification = config["specification"].as<string > ();
  vector<string> strs;
  boost::split(strs, specification, boost::is_any_of("\n"));

  m_pIn = new unsigned long[strs.size()];
  m_pOut = new unsigned long[strs.size()];

  m_nTerms = 0;
  for (int i = 0; i < strs.size(); i++) {
    string value = strs[i];
    if (value == "") continue;

    vector<string> in_out;
    boost::split(in_out, value, boost::is_any_of(" "));
    m_pIn[m_nTerms] = decimal(in_out[0].c_str());
    m_pOut[m_nTerms] = decimal(in_out[1].c_str());
    m_nTerms++;
  }
}

unsigned long Function::decimal(string str) {
  unsigned long result=0;

  for(int i=0; i<str.size(); i++) {
    result += str[i] - '0';
    result *= m_nRadix;
  }

  return result / m_nRadix;
}

void Function::dump() {
  cout << "\nFunction: \n";
  for(int i=0; i<m_nTerms; i++) {
    cout << m_pIn[i] << " => " << m_pOut[i] << "\n";
  }
}
