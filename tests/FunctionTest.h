/*
 * File:   FunctionTest.h
 * Author: mmh
 *
 * Created on Dec 27, 2012, 9:56:37 AM
 */

#ifndef FUNCTIONTEST_H
#define	FUNCTIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class FunctionTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(FunctionTest);

  CPPUNIT_TEST(testMethod);

  CPPUNIT_TEST_SUITE_END();

public:
  FunctionTest();
  virtual ~FunctionTest();
  void setUp();
  void tearDown();

private:
  void testMethod();
};

#endif	/* FUNCTIONTEST_H */

