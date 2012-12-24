/* 
 * File:   option.h
 * Author: mmh
 *
 * Created on December 24, 2012, 11:18 AM
 */

#include "common.h"

#ifndef OPTION_H
#define OPTION_H


class Option
{
public:
  static string m_fileName;                     
  static void init(int argc, char** argv);
  Option();     
  virtual ~Option();
};

#endif // OPTION_H
