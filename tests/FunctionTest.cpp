/*
 * File:   FunctionTest.cpp
 * Author: mmh
 *
 * Created on Dec 27, 2012, 9:56:37 AM
 */

#include "FunctionTest.h"
#include "common.h"
#include "function.h"
#include "test_helper"


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
  assert_equal(2, function.bits());
  assert_equal(3, function.radix());
  assert_equal(27, function.terms());
  unsigned long *inputs = function.inputs();
  unsigned long *outputs= function.outputs();

  assert_equal(0UL, inputs[0]);
  assert_equal(222UL, inputs[26]);
  
  assert_equal(1UL, outputs[0]);
  assert_equal(1UL, outputs[26]);
}
