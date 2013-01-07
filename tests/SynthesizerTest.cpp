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
    void stub(ulong *pcontrol, ulong *ptarget, int num_gates, int num_bits) {
    m_pcontrol = pcontrol;
    m_ptarget = ptarget;
    m_num_gates = num_gates;
    m_num_bits = num_bits;
  }
  ulong propogate(ulong term) {return Synthesizer::propogate(term);}
  ulong cost() {return Synthesizer::cost();}
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
  ulong control[] = {0b1100, 0b1001, 0b0101};
  ulong target[] =  {0b0001, 0b0100, 0b1000};
  syn.stub(control, target, 3, 4);
  assert_equal(0b1011UL, syn.propogate(0b1110));

  ulong control2[] = {0b1100101, 0b1001001, 0b1110101};
  ulong target2[] =  {0b0001000, 0b0000100, 0b0001000};
  syn.stub(control2, target2, 3, 7);

  assert_equal(0b1110111UL, syn.propogate(0b1111011));
}

void SynthesizerTest::test_cost() {
  SynthesizerMock syn;
  ulong control[] = {0b1100, 0b1001, 0b0101};
  syn.stub(control, NULL, 3, 4);
  assert_equal(15UL, syn.cost());

  ulong control2[] = {0b11100, 0b01001, 0b10101};
  syn.stub(control2, NULL, 3, 5);
  assert_equal(31UL, syn.cost());

}

void SynthesizerTest::test_control_lines() {

}

void SynthesizerTest::test_process() {

}
