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

void CoveredSetPatitionTest::test_copy_terms_in_function() {
  Function function;
  function.load_file("./tests/fixtures/function-4.xqs");

  CoveredSetPartition::initialize(&function, 2);
  CoveredSetPartition csp;

  unsigned long p[] = {0, 2, 1, 4, 5, 3, 7, 6, 8, 9, 10, 12, 11, 14, 15, 13};
  vector<unsigned long> expected(p, p+16);
  csp.copy_terms_in_function(p);

  unsigned long *pInput = csp.inputs();
  vector<unsigned long> actual(pInput, pInput + 16);
  assert_equal_vectors(expected, actual);

  unsigned long pout[] = {7, 6, 15, 0, 13, 14, 10, 5, 9, 12, 8, 4, 2, 3, 1, 11};
  expected.assign(pout, pout+16);
  unsigned long *pOutput = csp.outputs();
  actual.assign(pOutput, pOutput + 16);
  assert_equal_vectors(expected, actual);
}

void CoveredSetPatitionTest::test_copy_terms_in_incomplete_function() {
  Function function;
  function.load_file("./tests/fixtures/function-4-incomplete.xqs");

  CoveredSetPartition::initialize(&function, 2);
  CoveredSetPartition csp;

  unsigned long p[] = {0, 2, 1, 4, 5, 3, 7, 6, 8, 9, 10, 12, 11, 14, 15, 13};
  unsigned long pin[] = {0, 2, 4, 5, 3, 7, 8, 10, 12, 15};
  vector<unsigned long> expected(pin, pin+10);
  csp.copy_terms_in_function(p);

  unsigned long *pInput = csp.inputs();
  vector<unsigned long> actual(pInput, pInput + 10);
  assert_equal_vectors(expected, actual);

  unsigned long pout[] = {7, 6, 0, 13, 14, 10, 9, 8, 4, 1};
  expected.assign(pout, pout+10);
  unsigned long *pOutput = csp.outputs();
  actual.assign(pOutput, pOutput + 10);
  assert_equal_vectors(expected, actual);
}
