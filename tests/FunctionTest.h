/*
 * File:   FunctionTest.h
 * Author: mmh
 *
 * Created on Dec 26, 2012, 8:20:11 AM
 */

#ifndef FUNCTIONTEST_H
#define	FUNCTIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class FunctionTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(FunctionTest);

  CPPUNIT_TEST(testWillLoadFile);
  CPPUNIT_TEST(testFailedMethod);

  CPPUNIT_TEST_SUITE_END();

public:
  FunctionTest();
  virtual ~FunctionTest();
  void setUp();
  void tearDown();

private:
  void testWillLoadFile();
  void testFailedMethod();
};

#endif	/* FUNCTIONTEST_H */

