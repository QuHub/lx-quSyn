/*
 * File:   HasseTest.h
 * Author: mmh
 *
 * Created on Dec 27, 2012, 10:59:48 AM
 */

#ifndef HASSETEST_H
#define	HASSETEST_H

#include <cppunit/extensions/HelperMacros.h>

class HasseTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(HasseTest);

  CPPUNIT_TEST(testMethod);
  CPPUNIT_TEST(testBands);
  CPPUNIT_TEST(test_get);

  CPPUNIT_TEST_SUITE_END();

public:
  HasseTest();
  virtual ~HasseTest();
  void setUp();
  void tearDown();

private:
  void testMethod();
  void testBands();
  void test_get();
};

#endif	/* HASSETEST_H */

