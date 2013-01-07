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
  ulong *inputs = function.inputs();
  ulong *outputs= function.outputs();

  assert_equal(0UL, inputs[0]);
  assert_equal(26UL, inputs[26]);

  assert_equal(1UL, outputs[0]);
  assert_equal(1UL, outputs[26]);
}

void FunctionTest::test_decimal() {
  Function function;
  function.radix(2);
  assert_equal(2UL, function.decimal("10"));
  assert_equal(6UL, function.decimal("110"));
  assert_equal(14UL, function.decimal("001110"));

  function.radix(3);
  assert_equal(3UL, function.decimal("10"));
  assert_equal(15UL, function.decimal("120"));
  assert_equal(525UL, function.decimal("201110"));

}