/* 
 * File:   Thread.cpp
 * Author: mmh
 * 
 * Created on December 24, 2012, 6:51 PM
 */

#include "common.h"
#include "Thread.h"

Thread::Thread() {}

int Thread::Start(void * arg)
{
   Arg(arg); // store user data
   int code = pthread_create(&(m_id), NULL, Thread::EntryPoint, this);
   return code;
}

int Thread::Run()
{
   Setup();
   Execute( NULL);
}

/*static */
void * Thread::EntryPoint(void * pthis)
{
   Thread * pt = (Thread*)pthis;
   pt->Run();
}

void Thread::Setup()
{
	throw "Must implement in subclass";
}

void Thread::Execute(void* arg)
{
	throw "Must implement in subclass";
}