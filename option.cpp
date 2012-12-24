/* 
 * File:   option.cpp
 * Author: mmh
 * 
 * Created on December 24, 2012, 11:18 AM
 */

#include <unistd.h>     
#include "option.h"

string Option::m_fileName;

void Option::init(int argc, char** argv)
{
  int opt=0;
  while ((opt = getopt(argc, argv, "    ")) >= 0) {
    switch(opt) {
      case 'f':
        m_fileName = optarg;
        break;
      case 'n':
        cout << "n";
        break;
      case 'l':
        cout << "l";
        break;
    }
  }
    
}