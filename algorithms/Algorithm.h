/* 
 * File:   Algorithm.h
 * Author: mmh
 *
 * Created on December 24, 2012, 6:18 PM
 */

#ifndef ALGORITHM_H
#define	ALGORITHM_H

class Algorithm {
public:
  Algorithm();
  Algorithm(const Algorithm& orig);
  virtual ~Algorithm();
protected:
	unsigned long *m_pin;
	unsigned long *m_pout;

};

#endif	/* ALGORITHM_H */

