/*
 * File:   CoveredSetPatitionTest.h
 * Author: mmh
 *
 * Created on Dec 27, 2012, 2:52:35 PM
 */

#ifndef COVEREDSETPATITIONTEST_H
#define	COVEREDSETPATITIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class CoveredSetPatitionTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(CoveredSetPatitionTest);

  CPPUNIT_TEST(test_initialize);
  CPPUNIT_TEST(test_copy_terms_in_function);
  CPPUNIT_TEST(test_copy_terms_in_incomplete_function);

  CPPUNIT_TEST_SUITE_END();

public:
  CoveredSetPatitionTest();
  virtual ~CoveredSetPatitionTest();
  void setUp();
  void tearDown();

private:
  void test_initialize();
  void test_copy_terms_in_function();
  void test_copy_terms_in_incomplete_function();
};

#endif	/* COVEREDSETPATITIONTEST_H */

