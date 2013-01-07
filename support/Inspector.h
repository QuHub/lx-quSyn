/*
 * File:   Inspector.h
 * Author: mmh
 *
 * Created on January 7, 2013, 7:45 AM
 */

#ifndef INSPECTOR_H
#define	INSPECTOR_H

#include <stdio.h>

using namespace std;

template <class T>
void dump(string message, T* p, long size) {
  cout << message;
  for(int i=0; i<size; i++)
    cout << p[i] << " ";

  cout << "\n";
}

#endif	/* INSPECTOR_H */

