/*
 * File:   Thread.h
 * Author: mmh
 *
 * Created on December 24, 2012, 6:51 PM
 */

#include <pthread.h>
#ifndef THREAD_H
#define	THREAD_H

class Thread
{
   public:
      Thread();
      int Start(void * arg);
   protected:
      int Run();
      static void * EntryPoint(void*);
      virtual void Execute(void*);
      void * Arg() const {return Arg_;}
      void Arg(void* a){Arg_ = a;}
      pthread_t m_id;
      void * Arg_;

};

#endif	/* THREAD_H */

