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
  // Declare the supported options.
  po::options_description desc("Allowed options");
  desc.add_options()
          ("help", "produce help message")
          ("compression", po::value<int>(), "set compression level")
          ;

  po::options_description xesc("Not Allowed options");
  xesc.add_options()
          ("depression", po::value<int>(), "set compression level")
          ;
  po::options_description cmdline_options;
  cmdline_options.add(desc).add(xesc);

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, cmdline_options), vm);
  po::notify(vm);

  if (vm.count("help")) {
    cout << desc << "\n";
  }

  cout << vm.count("help");

  if (vm.count("help")) {
    cout << xesc << "\n";
  }

  if (vm.count("compression")) {
    cout << "Compression level was set to "
            << vm["compression"].as<int>() << ".\n";
  } else {
    cout << "Compression level was not set.\n";
  }

}

/*
 *
 */
void add_cli_options() {
  CoveredSetPartition::add_cli_options();
}

int main(int argc, char** argv) {
  Option::init(argc, argv);
  Function function;
  function.load_file("./tests/fixtures/function-4.xqs");
  CoveredSetPartition::initialize(&function, 0);
  RandomConductor algo(&function);
  algo.synthesize();
  return 0;
}

