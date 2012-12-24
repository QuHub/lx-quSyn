/* 
 * File:   main.cpp
 * Author: mmh
 *
 * Created on December 24, 2012, 11:11 AM
 */

#include <iostream>
#include <cstdlib>
#include "option.h"
#include "function.h"
#include "randomconductor.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
  Option::init(argc, argv);
  Function function;
  RandomConductor algo(function);
  algo.synthesize();
  return 0;
}

