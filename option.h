/*
 * File:   option.h
 * Author: mmh
 *
 * Created on December 24, 2012, 11:18 AM
 */

#include "common.h"
#include <list>
#include "argvparser.h"

using namespace CommandLineProcessing;

#ifndef OPTION_H
#define OPTION_H


class Option
{
public:
  static string m_fileName;
  static void init(int argc, char** argv);
	static string Get(const char* option, const char* _default="");
  static int Get(const char* option, int _default=0);

private:
	static void Parse();
	static int m_argc;
	static char** m_argv;
	static bool m_parsed;
  static ArgvParser m_parser;
};

#endif // OPTION_H
