/*
 * File:   SynthesizerTest.cpp
 * Author: mmh
 *
 * Created on Jan 6, 2013, 8:12:38 PM
 */

#include "SynthesizerTest.h"
#include "test_helper"
#include "Synthesizer.h"


class SynthesizerMock : public Synthesizer {
  public:
    void stub(unsigned long *pcontrol, unsigned long *ptarget, int num_gates) {
    m_pcontrol = pcontrol;
    m_ptarget = ptarget;
    m_num_gates = num_gates;
    m_num_bits = 2;
  }
  unsigned long propogate(unsigned long term) {return Synthesizer::propogate(term);}
};

CPPUNIT_TEST_SUITE_REGISTRATION(SynthesizerTest);

SynthesizerTest::SynthesizerTest() {
}

SynthesizerTest::~SynthesizerTest() {
}

void SynthesizerTest::setUp() {
}

void SynthesizerTest::tearDown() {
}

void SynthesizerTest::test_propogate() {
  SynthesizerMock syn;
  unsigned long control[] = {0b1100, 0b1001, 0b0101};
  unsigned long target[] =  {0b0001, 0b0100, 0b1000};
  syn.stub(control, target, 3);
  assert_equal(0b1011UL, syn.propogate(0b1110));

  unsigned long control2[] = {0b1100101, 0b1001001, 0b1110101};
  unsigned long target2[] =  {0b0001000, 0b0000100, 0b0001000};
  syn.stub(control2, target2, 3);

  assert_equal(0b1110111UL, syn.propogate(0b1111011));
}

void SynthesizerTest::test_cost() {
}

void SynthesizerTest::test_control_lines() {

}

void SynthesizerTest::test_process() {

}
