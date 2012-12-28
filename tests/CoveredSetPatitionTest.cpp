/*
 * File:   CoveredSetPatitionTest.cpp
 * Author: mmh
 *
 * Created on Dec 27, 2012, 2:52:35 PM
 */

#include "CoveredSetPatitionTest.h"
#include "test_helper"
#include "coveredsetpartition.h"



CPPUNIT_TEST_SUITE_REGISTRATION(CoveredSetPatitionTest);

CoveredSetPatitionTest::CoveredSetPatitionTest() {
}

CoveredSetPatitionTest::~CoveredSetPatitionTest() {
}

void CoveredSetPatitionTest::setUp() {
}

void CoveredSetPatitionTest::tearDown() {
}

void CoveredSetPatitionTest::test_initialize() {
  Function function;
  function.load_file("./tests/fixtures/function-4.xqs");

  CoveredSetPartition::initialize(&function, 2);
  CoveredSetPartition csp;

  assert_equal(4, csp.num_sets());
  assert_equal(16, csp.num_max_terms());
  assert_equal(16, csp.num_terms());
  assert_equal(2, csp.partition_size());
  assert(csp.function() == &function);
}

