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

namespace bf= boost::filesystem;
using namespace std;
using namespace boost;

Function::Function()
{
  bf::path p(".");
  bf::path pa = bf::current_path();
  
//  YAML::Node config = YAML::LoadFile(Option::m_fileName);
  YAML::Node config = YAML::LoadFile("3_2gtev1.xqs");
  cout << Option::m_fileName << "\n";
  YAML::Node temp = config["signature"];
  m_functionName = temp["function"].as<string>();
   m_fileName = Option::m_fileName;
   m_nBits = config["inputs"]["variables"].as<int>();
   m_nRadix = config["inputs"]["radix"].as<int>();
   string specification = config["specification"].as<string>();
   vector<string> strs;
   boost::split(strs, specification, boost::is_any_of("\n"));

   m_pIn = new int[strs.size()];
   m_pOut = new int[strs.size()]; 
 
   m_nTerms =0;
   for(int i=0; i<strs.size(); i++) {
     string value = strs[i];
     if(value == "") continue;
     
     vector<string> in_out;
     boost::split(in_out, value, boost::is_any_of(" "));
     m_pIn[m_nTerms] = atoi(in_out[0].c_str());
     m_pOut[m_nTerms] = atoi(in_out[1].c_str());
     m_nTerms++;
   }
}

Function::Function(const Function& other)
{
  m_pIn = new int[m_nTerms];
  m_pOut = new int[m_nTerms];
  memcpy(m_pIn, other.m_pIn, m_nTerms * sizeof(int));
  memcpy(m_pOut, other.m_pOut, m_nTerms * sizeof(int));
}


Function& Function::operator=(const Function& other)
{
  m_pIn = new int[m_nTerms];
  m_pOut = new int[m_nTerms];
  memcpy(m_pIn, other.m_pIn, m_nTerms * sizeof(int));
  memcpy(m_pOut, other.m_pOut, m_nTerms * sizeof(int));
  return *this;
}

Function::~Function()
{
  cout << "destroying\n";
  delete m_pIn;
  delete m_pOut;
}
