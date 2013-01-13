#pragma warning(disable:4996)
#pragma once

#include <vector>
using namespace std;

class Hasse {
public:

  void initialize(int bits) {
    m_bits = bits;
    m_terms = pow(2, bits);
    m_bands = bits + 1;
    m_pbands = new vector<ulong>[m_bands]; // Delete only once at the end of the or on TotalReset();

    // Allocate space for each bands
    for (int i = 0; i < m_terms; i++) {
      m_pbands[Helper::number_of_ones(i)].push_back(i);
    }
  }

  static void seed() {
    long seed = Rand::for_random_shuffle(100000);
    srand(seed);
   }

  int get(ulong *p, int bias) {
    int n = 0;
    for (int i = 0; i < m_bands; i++) {
      random_shuffle(m_pbands[i].begin(), m_pbands[i].end());
      for (int j = 0; j < m_pbands[i].size(); j++)
        *p++ = m_pbands[i][j] + bias;

      n += m_pbands[i].size();
    }
    return n;
  }

  void release() {
    delete []m_pbands;
  }

  int bits() {
    return m_bits;
  }

  int terms() {
    return m_terms;
  }

  int bands() {
    return m_bands;
  }

  vector<ulong>*band() {
    return m_pbands;
  }

private:
  int m_bits;
  int m_terms;
  int m_bands;
  vector<ulong> *m_pbands;
};

