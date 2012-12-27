/* 
 * File:   option.h
 * Author: mmh
 *
 * Created on December 24, 2012, 11:18 AM
 */

#include "common.h"
#include <list>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

#ifndef OPTION_H
#define OPTION_H


class Option
{
public:
  static string m_fileName;                     
  static void init(int argc, char** argv);
	static po::options_description& Register(const char * description);
	static int Get(const char* option);
private:
	static void Parse();
	static int m_argc;
	static char** m_argv;
	static po::options_description m_options;
	static bool m_parsed;
	static po::variables_map m_vm;
	static list<po::options_description> m_desc;
};

#endif // OPTION_H
