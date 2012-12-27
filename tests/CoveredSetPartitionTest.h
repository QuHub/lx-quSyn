/*
 * File:   CoveredSetPartitionTest.h
 * Author: mmh
 *
 * Created on Dec 26, 2012, 7:04:33 AM
 */

#ifndef COVEREDSETPARTITIONTEST_H
#define	COVEREDSETPARTITIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class CoveredSetPartitionTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(CoveredSetPartitionTest);

  CPPUNIT_TEST(testMethod);
  CPPUNIT_TEST(testFailedMethod);

  CPPUNIT_TEST_SUITE_END();

public:
  CoveredSetPartitionTest();
  virtual ~CoveredSetPartitionTest();
  void setUp();
  void tearDown();

private:
  void testMethod();
  void testFailedMethod();
};

#endif	/* COVEREDSETPARTITIONTEST_H */

