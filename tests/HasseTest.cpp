/*
 * File:   HasseTest.cpp
 * Author: mmh
 *
 * Created on Dec 27, 2012, 10:59:48 AM
 */

#include "test_helper"
#include "HasseTest.h"
#include "common.h"
#include "Hasse.h"


CPPUNIT_TEST_SUITE_REGISTRATION(HasseTest);

HasseTest::HasseTest() {
}

HasseTest::~HasseTest() {
}

void HasseTest::setUp() {
}

void HasseTest::tearDown() {
}

void HasseTest::testMethod() {
  Hasse hasse;

  hasse.initialize(3);
  assert_equal(3, hasse.bits());
  assert_equal(8, hasse.terms());
  assert_equal(4, hasse.bands());
  assert_equal(1UL, hasse.band()[0].size());
  assert_equal(3UL, hasse.band()[1].size());
  assert_equal(3UL, hasse.band()[2].size());
  assert_equal(1UL, hasse.band()[3].size());
}

void HasseTest::testBands() {
  Hasse hasse;
  hasse.initialize(3);

  vector<ulong> expected({0});
  assert_equal_vectors(expected, hasse.band()[0]);

  expected.assign({1,2,4});
  assert_equal_vectors(expected, hasse.band()[1]);

  expected.assign({3,5,6});
  assert_equal_vectors(expected, hasse.band()[2]);
  
  expected.assign({7});
  assert_equal_vectors(expected, hasse.band()[3]);
}


void HasseTest::test_get() {
  Hasse hasse;
  hasse.initialize(3);

  ulong buf[8], *p;
  p = buf;
  int n = hasse.get(p, 10);
  assert_equal(8, n);

  vector<ulong> expected({10, 11, 12, 13, 14, 15, 16, 17});
  vector<ulong> actual(p, p+8);
  assert_equal_vectors(expected, actual);
}
