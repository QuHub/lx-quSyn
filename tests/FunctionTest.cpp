/*
 * File:   FunctionTest.cpp
 * Author: mmh
 *
 * Created on Dec 27, 2012, 9:56:37 AM
 */

#include "FunctionTest.h"
#include "common.h"
#include "function.h"


CPPUNIT_TEST_SUITE_REGISTRATION(FunctionTest);

FunctionTest::FunctionTest() {
}

FunctionTest::~FunctionTest() {
}

void FunctionTest::setUp() {
}

void FunctionTest::tearDown() {
}

void FunctionTest::testMethod() {
  Function function;
  function.load_file("./tests/fixtures/function.xqs");
  CPPUNIT_ASSERT_EQUAL(2, function.bits());
  CPPUNIT_ASSERT_EQUAL(3, function.radix());
  CPPUNIT_ASSERT_EQUAL(27, function.terms());
  unsigned long *inputs = function.inputs();
  unsigned long *outputs= function.outputs();

  CPPUNIT_ASSERT_EQUAL(0UL, inputs[0]);
  CPPUNIT_ASSERT_EQUAL(222UL, inputs[26]);
  
  CPPUNIT_ASSERT_EQUAL(1UL, outputs[0]);
  CPPUNIT_ASSERT_EQUAL(1UL, outputs[26]);
}
