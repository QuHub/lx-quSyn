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
po::options_description Option::m_options;
po::variables_map Option::m_vm;
list<po::options_description> Option::m_desc;

void Option::init(int argc, char** argv)
{
	m_argc = argc;
	m_argv = argv;
	po::options_description desc = Register("General Options");
	desc.add_options()
		("help", "print this message")
	;

	//po::store(po::parse_command_line(m_argc, m_argv, desc), m_vm);
}

po::options_description& Option::Register(const char * description)
{
	// Declare the supported options.
	po::options_description * pdesc = new po::options_description(description);
	m_desc.push_back(*pdesc);
	return *pdesc;
}

void Option::Parse()
{
	if(m_parsed) return;
	for(int i=0; i<m_desc.size(); i++)
		m_options.add(m_desc.back());

	po::options_description desc = m_desc.front();
	po::store(po::parse_command_line(m_argc, m_argv, desc), m_vm);
	po::notify(m_vm);    
	m_parsed = true;
}

int Option::Get(const char* option)
{
	Parse();
	if(m_vm.count(option)) {
		return m_vm[option].as<int>();
	}
	
	return -1;
}
/*
char* Option::Get(po::options_description &desc, const char* option)
{
	po::variables_map vm;
	po::store(po::parse_command_line(m_argc, m_argv, desc), vm);
	po::notify(vm);    

	if(vm.count(option)) {
		return vm[option].as<char *>();
	}
	return NULL;
}
 */