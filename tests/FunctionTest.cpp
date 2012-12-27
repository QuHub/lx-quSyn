/*
 * File:   FunctionTest.cpp
 * Author: mmh
 *
 * Created on Dec 26, 2012, 8:20:11 AM
 */

#include "FunctionTest.h"

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

void FunctionTest::testWillLoadFile() {
  Function function;
  function.load_file("fixtures/function.xqs");
  CPPUNIT_ASSERT(function.bits() == 3);
}

void FunctionTest::testFailedMethod() {
  CPPUNIT_ASSERT(false);
}
