/*
 * File:   option.cpp
 * Author: mmh
 *
 * Created on December 24, 2012, 11:18 AM
 */

#include <unistd.h>
#include "option.h"
string Option::m_fileName;
bool Option::m_parsed=false;
int Option::m_argc;
char** Option::m_argv;
ArgvParser Option::m_parser;

void Option::init(int argc, char** argv)
{
    //define error codes
  m_parser.addErrorCode(0, "Success");
  m_parser.addErrorCode(1, "Error");
  m_parser.setHelpOption("help", "h", "help descr.");
  m_parser.defineOption("partition-size", "Set the partition size", ArgvParser::OptionRequiresValue);
  m_parser.defineOption("input-file", "Input filename", ArgvParser::OptionRequiresValue | ArgvParser::OptionRequired);

  ArgvParser::ParserResults results = m_parser.parse(argc, argv);
   if (results != ArgvParser::NoParserError)  {
    cout << m_parser.parseErrorDescription(results);
    exit(1);
  }

  cout << "Filename: " << Get("input-file") << std::endl;
  cout << "PatitionSize: " << Get("partition-size") <<std::endl;
  cout << std::endl;
}

string Option::Get(const char* option)
{
  if(m_parser.foundOption(option))
    return m_parser.optionValue(option);
	return NULL;
}