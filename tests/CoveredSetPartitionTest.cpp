/*
 * File:   CoveredSetPartitionTest.cpp
 * Author: mmh
 *
 * Created on Dec 26, 2012, 7:04:33 AM
 */

#include "CoveredSetPartitionTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(CoveredSetPartitionTest);

CoveredSetPartitionTest::CoveredSetPartitionTest() {
}

CoveredSetPartitionTest::~CoveredSetPartitionTest() {
}

void CoveredSetPartitionTest::setUp() {
}

void CoveredSetPartitionTest::tearDown() {
}

void CoveredSetPartitionTest::testMethod() {
  Function function;
  CoveredSetPartition::initialize(function, 3);
  CPPUNIT_ASSERT(true);
}

void CoveredSetPartitionTest::testFailedMethod() {
  CPPUNIT_ASSERT(false);
}

