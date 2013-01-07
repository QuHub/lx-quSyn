/*
 * File:   SynthesizerTest.h
 * Author: mmh
 *
 * Created on Jan 6, 2013, 8:12:38 PM
 */

#ifndef SYNTHESIZERTEST_H
#define	SYNTHESIZERTEST_H

#include <cppunit/extensions/HelperMacros.h>

class SynthesizerTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(SynthesizerTest);

  CPPUNIT_TEST(test_propogate);
  CPPUNIT_TEST(test_cost);
  CPPUNIT_TEST(test_control_lines);
  CPPUNIT_TEST(test_process);

  CPPUNIT_TEST_SUITE_END();

public:
  SynthesizerTest();
  virtual ~SynthesizerTest();
  void setUp();
  void tearDown();

private:
  void test_propogate();
  void test_cost();
  void test_control_lines();
  void test_process();
};   
#endif	/* SYNTHESIZERTEST_H */

