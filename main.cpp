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

int test_options(int argc, char **argv) {

}

/*
 *
 */
void add_cli_options() {
//  CoveredSetPartition::add_cli_options();
}

int main(int argc, char** argv) {
  Option::init(argc, argv);
  Function function;
  function.load_file(Option::Get("input-file"));
  CoveredSetPartition::initialize(&function, atoi(Option::Get("partition-size").c_str()));
  RandomConductor algo(&function);
  algo.synthesize();
  CoveredSetPartition::release();
  return 0;
}

